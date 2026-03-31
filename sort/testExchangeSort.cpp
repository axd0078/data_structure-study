#include <iostream>
#include <vector>

#include "exchangeSort.h"

using namespace std;

bool isSorted(const vector<int>& nums) {
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] < nums[i - 1]) {
            return false;
        }
    }
    return true;
}

void printArray(const vector<int>& nums) {
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << (i + 1 == nums.size() ? '\n' : ' ');
    }
}

void testBubbleSort() {
    vector<int> nums = {49, 38, 65, 97, 76, 13, 27, 49};
    bubbleSort(nums.data(), static_cast<int>(nums.size()));
    cout << "[bubbleSort] " << (isSorted(nums) ? "PASS" : "FAIL") << '\n';
    printArray(nums);
}

void testQuickSortBasic() {
    vector<int> nums = {49, 38, 65, 97, 76, 13, 27, 49};
    quickSort(nums.data(), static_cast<int>(nums.size()));
    cout << "[quickSort basic] " << (isSorted(nums) ? "PASS" : "FAIL") << '\n';
    printArray(nums);
}

void testQuickSortDuplicates() {
    vector<int> nums = {5, 5, 5, 3, 3, 8, 1, 1, 2};
    quickSort(nums.data(), static_cast<int>(nums.size()));
    cout << "[quickSort duplicates] " << (isSorted(nums) ? "PASS" : "FAIL") << '\n';
    printArray(nums);
}

void testQuickSortSortedInput() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    quickSort(nums.data(), static_cast<int>(nums.size()));
    cout << "[quickSort sorted] " << (isSorted(nums) ? "PASS" : "FAIL") << '\n';
    printArray(nums);
}

int main() {
    testBubbleSort();
    testQuickSortBasic();
    testQuickSortDuplicates();
    testQuickSortSortedInput();
    return 0;
}
