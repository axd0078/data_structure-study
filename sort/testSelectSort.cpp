#include <iostream>
#include <vector>

#include "selectSort.h"

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

void testSelectSort() {
    vector<int> nums = {49, 38, 65, 97, 76, 13, 27, 49};
    selectSort(nums.data(), static_cast<int>(nums.size()));
    cout << "[selectSort] " << (isSorted(nums) ? "PASS" : "FAIL") << '\n';
    printArray(nums);
}

void testHeapSortBasic() {
    vector<int> nums = {49, 38, 65, 97, 76, 13, 27, 49};
    heapSort(nums.data(), static_cast<int>(nums.size()));
    cout << "[heapSort basic] " << (isSorted(nums) ? "PASS" : "FAIL") << '\n';
    printArray(nums);
}

void testHeapSortDuplicates() {
    vector<int> nums = {5, 5, 5, 3, 3, 8, 1, 1, 2};
    heapSort(nums.data(), static_cast<int>(nums.size()));
    cout << "[heapSort duplicates] " << (isSorted(nums) ? "PASS" : "FAIL") << '\n';
    printArray(nums);
}

void testHeapSortEdgeCases() {
    vector<int> one = {7};
    heapSort(one.data(), static_cast<int>(one.size()));
    cout << "[heapSort single] " << (isSorted(one) ? "PASS" : "FAIL") << '\n';
    printArray(one);

    vector<int> sorted = {1, 2, 3, 4, 5, 6};
    heapSort(sorted.data(), static_cast<int>(sorted.size()));
    cout << "[heapSort sorted] " << (isSorted(sorted) ? "PASS" : "FAIL") << '\n';
    printArray(sorted);
}

int main() {
    testSelectSort();
    testHeapSortBasic();
    testHeapSortDuplicates();
    testHeapSortEdgeCases();
    return 0;
}
