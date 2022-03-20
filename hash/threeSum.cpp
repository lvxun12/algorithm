#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        // hash
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出 a+b+c = 0
        // a = nums[i], b=nums[j], c= -(a+b)
        for(int i=0; i< nums.size(); i++){
            // 排序之后如果第一个元素已经大于0, 那么不可能凑成三元数组
            if(nums[i] > 0){
                break;
            }
            // 三元组元素a去重
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }

            unordered_set<int> set;
            for(int j=i+1; j<nums.size(); j++){
                if(j>i+2 
                &&  nums[j] == nums[j-1]
                &&  nums[j-1] == nums[j-2]){
                    // 三元数组b去重
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if(set.find(c) != set.end()){
                    result.push_back({nums[i], nums[j], c});
                    set.erase(c);
                }else{
                    set.insert(nums[j]);
                }
            }

        }
        return result;
    }

int main(){
    int a[6] = {-1, 0,1,2,-1,-4};
    vector<int> nums(a, a+6);
    threeSum(nums);
    return 0;
}