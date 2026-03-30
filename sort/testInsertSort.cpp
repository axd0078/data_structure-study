#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "insertSort.h"

using namespace std;

bool isSortedIntWithSentinel(const vector<int>& nums) {
    for (size_t i = 2; i < nums.size(); ++i) {
        if (nums[i] < nums[i - 1]) {
            return false;
        }
    }
    return true;
}

bool isSortedDouble(const vector<double>& nums) {
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] + 1e-9 < nums[i - 1]) {
            return false;
        }
    }
    return true;
}

void printIntWithSentinel(const vector<int>& nums) {
    for (size_t i = 1; i < nums.size(); ++i) {
        cout << nums[i] << (i + 1 == nums.size() ? '\n' : ' ');
    }
}

void printDoubleArray(const vector<double>& nums) {
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << (i + 1 == nums.size() ? '\n' : ' ');
    }
}

void testInsertSortInt() {
    vector<int> nums = {0, 49, 38, 65, 97, 76, 13, 27, 49};
    insertSort(nums.data(), static_cast<int>(nums.size()) - 1);
    cout << "[insertSort int] " << (isSortedIntWithSentinel(nums) ? "PASS" : "FAIL") << '\n';
    printIntWithSentinel(nums);
}

void testBInsertSortInt() {
    vector<int> nums = {0, 49, 38, 65, 97, 76, 13, 27, 49};
    BInsertSort(nums.data(), static_cast<int>(nums.size()) - 1);
    cout << "[BInsertSort int] " << (isSortedIntWithSentinel(nums) ? "PASS" : "FAIL") << '\n';
    printIntWithSentinel(nums);
}

void testShellSortInt() {
    vector<int> nums = {0, 49, 38, 65, 97, 76, 13, 27, 49};
    shellSort(nums.data(), static_cast<int>(nums.size()) - 1);
    cout << "[shellSort int] " << (isSortedIntWithSentinel(nums) ? "PASS" : "FAIL") << '\n';
    printIntWithSentinel(nums);
}

void testInsertSortDouble() {
    vector<double> nums = {4.5, 2.2, 2.2, 8.1, 3.6, 0.5};
    insertSort(nums.data(), static_cast<int>(nums.size()));
    cout << "[insertSort double] " << (isSortedDouble(nums) ? "PASS" : "FAIL") << '\n';
    printDoubleArray(nums);
}

void testBInsertSortDouble() {
    vector<double> nums = {4.5, 2.2, 2.2, 8.1, 3.6, 0.5};
    BInsertSort(nums.data(), static_cast<int>(nums.size()));
    cout << "[BInsertSort double] " << (isSortedDouble(nums) ? "PASS" : "FAIL") << '\n';
    printDoubleArray(nums);
}

void testShellSortDouble() {
    vector<double> nums = {4.5, 2.2, 2.2, 8.1, 3.6, 0.5};
    shellSort(nums.data(), static_cast<int>(nums.size()));
    cout << "[shellSort double] " << (isSortedDouble(nums) ? "PASS" : "FAIL") << '\n';
    printDoubleArray(nums);
}

int main() {
    testInsertSortInt();
    testBInsertSortInt();
    testShellSortInt();
    testInsertSortDouble();
    testBInsertSortDouble();
    testShellSortDouble();
    return 0;
}
