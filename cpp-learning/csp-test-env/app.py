from __future__ import annotations

import threading
import tkinter as tk
from tkinter import messagebox, ttk

from csp_test_env.catalog import (
    ContestMeta,
    ProblemMeta,
    fixed_submission_path,
    fixed_submission_relative_path,
    load_catalog,
)
from csp_test_env.judge import judge_submission


class CspJudgeApp(tk.Tk):
    def __init__(self) -> None:
        super().__init__()
        self.title("CSP 本地测试环境")
        self.geometry("900x620")
        self.minsize(760, 520)

        self.contests = load_catalog()
        self.current_problems: tuple[ProblemMeta, ...] = tuple()

        self.contest_var = tk.StringVar()
        self.problem_var = tk.StringVar()
        self.source_path_var = tk.StringVar()
        self.timeout_var = tk.StringVar(value="2.0")

        self._build_ui()
        self._load_initial_values()

    def _build_ui(self) -> None:
        self.columnconfigure(0, weight=1)
        self.rowconfigure(6, weight=1)

        ttk.Label(self, text="认证").grid(row=0, column=0, sticky="w", padx=14, pady=(14, 4))
        self.contest_combo = ttk.Combobox(self, textvariable=self.contest_var, state="readonly")
        self.contest_combo.grid(row=1, column=0, sticky="ew", padx=14)
        self.contest_combo.bind("<<ComboboxSelected>>", self._on_contest_selected)

        ttk.Label(self, text="题目").grid(row=2, column=0, sticky="w", padx=14, pady=(12, 4))
        self.problem_combo = ttk.Combobox(self, textvariable=self.problem_var, state="readonly")
        self.problem_combo.grid(row=3, column=0, sticky="ew", padx=14)
        self.problem_combo.bind("<<ComboboxSelected>>", self._on_problem_selected)

        source_frame = ttk.Frame(self)
        source_frame.grid(row=4, column=0, sticky="ew", padx=14, pady=(14, 4))
        source_frame.columnconfigure(1, weight=1)
        ttk.Label(source_frame, text="固定源码路径").grid(row=0, column=0, sticky="w")
        ttk.Entry(source_frame, textvariable=self.source_path_var, state="readonly").grid(
            row=0, column=1, sticky="ew", padx=(8, 0)
        )

        action_frame = ttk.Frame(self)
        action_frame.grid(row=5, column=0, sticky="ew", padx=14, pady=(10, 14))
        action_frame.columnconfigure(3, weight=1)
        ttk.Label(action_frame, text="超时(秒)").grid(row=0, column=0, sticky="e")
        ttk.Entry(action_frame, textvariable=self.timeout_var, width=8).grid(row=0, column=1, sticky="w", padx=(6, 12))
        self.run_button = ttk.Button(action_frame, text="运行测试", command=self._start_judge)
        self.run_button.grid(row=0, column=2, sticky="w")

        result_frame = ttk.Frame(self)
        result_frame.grid(row=6, column=0, sticky="nsew", padx=14, pady=(0, 14))
        result_frame.rowconfigure(1, weight=1)
        result_frame.columnconfigure(0, weight=1)

        ttk.Label(result_frame, text="得分信息").grid(row=0, column=0, sticky="w", pady=(0, 4))
        self.result_text = tk.Text(result_frame, wrap="word", height=18, state="disabled")
        self.result_text.grid(row=1, column=0, sticky="nsew")
        scrollbar = ttk.Scrollbar(result_frame, orient="vertical", command=self.result_text.yview)
        scrollbar.grid(row=1, column=1, sticky="ns")
        self.result_text.configure(yscrollcommand=scrollbar.set)

    def _load_initial_values(self) -> None:
        self.contest_combo["values"] = [self._contest_label(contest) for contest in self.contests]
        if self.contests:
            self.contest_combo.current(0)
            self._set_problems(self.contests[0])

    def _contest_label(self, contest: ContestMeta) -> str:
        return f"第{contest.contest_id:02d}次认证 {contest.contest_month}"

    def _problem_label(self, problem: ProblemMeta) -> str:
        return f"第{problem.position}题 {problem.title}  ({problem.key})"

    def _on_contest_selected(self, _event: tk.Event) -> None:
        index = self.contest_combo.current()
        if 0 <= index < len(self.contests):
            self._set_problems(self.contests[index])

    def _on_problem_selected(self, _event: tk.Event) -> None:
        self._refresh_source_path()

    def _set_problems(self, contest: ContestMeta) -> None:
        self.current_problems = contest.problems
        self.problem_combo["values"] = [self._problem_label(problem) for problem in self.current_problems]
        if self.current_problems:
            self.problem_combo.current(0)
        self._refresh_source_path()

    def _selected_problem(self) -> ProblemMeta | None:
        index = self.problem_combo.current()
        if 0 <= index < len(self.current_problems):
            return self.current_problems[index]
        return None

    def _refresh_source_path(self) -> None:
        problem = self._selected_problem()
        if problem is None:
            self.source_path_var.set("")
            return
        self.source_path_var.set(str(fixed_submission_relative_path(problem.contest_id, problem.position)))

    def _set_result(self, text: str) -> None:
        self.result_text.configure(state="normal")
        self.result_text.delete("1.0", tk.END)
        self.result_text.insert("1.0", text)
        self.result_text.configure(state="disabled")

    def _start_judge(self) -> None:
        problem = self._selected_problem()
        if problem is None:
            messagebox.showerror("错误", "请选择题目")
            return
        try:
            timeout_seconds = float(self.timeout_var.get())
            if timeout_seconds <= 0:
                raise ValueError
        except ValueError:
            messagebox.showerror("错误", "超时阈值必须是正数")
            return

        source_path = fixed_submission_path(problem.contest_id, problem.position)
        self.source_path_var.set(str(fixed_submission_relative_path(problem.contest_id, problem.position)))
        self.run_button.configure(state="disabled")
        self._set_result("正在编译并运行测试...")

        def work() -> None:
            report = judge_submission(problem.key, source_path, timeout_seconds)
            self.after(0, lambda: self._finish_judge(report.to_display_text()))

        threading.Thread(target=work, daemon=True).start()

    def _finish_judge(self, result_text: str) -> None:
        self._set_result(result_text)
        self.run_button.configure(state="normal")


def main() -> None:
    app = CspJudgeApp()
    app.mainloop()


if __name__ == "__main__":
    main()
