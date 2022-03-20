#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // 存放结果
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            // 发现nums2的元素 在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }

int main(){
    int a[3] = {4, 9, 5};
    vector<int> nums1(a, a+3);
    int b[5] = {9, 4, 9, 8, 4};
    vector<int> nums2(b, b+5);
    vector<int> c = intersection(nums1, nums2);
    cout << c[1] <<endl;
    return 0;
}