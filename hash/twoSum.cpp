#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for(int i=0; i< nums.size(); i++){
        auto iter = map.find(target - nums[i]);
        if(iter !=map.end()){
            return {iter->second, i};
        }
        map.insert(pair<int, int>(nums[i], i));
    }
    return {};
}

void printVector(vector<int>& nums){
    cout << " prepare print vector"<<endl;
    for(vector<int>::iterator it= nums.begin(); it< nums.end(); it++){
        cout<< *it << endl;
    }
}

int main(){
    int a[4] = {2, 7, 11, 15};
    vector<int> nums(a, a+4);
    int target = 9;
    vector<int> c = twoSum(nums, target);
    vector<int> b;
    b.push_back(0);
    b.push_back(10);
    b.push_back(20);
    b.push_back(30);
    cout<< *b.begin()<<endl;
    cout<< *(b.end()-1)<<endl;
    b.erase(b.begin()+1);
    printVector(b);
    vector<int> d(b.begin(), b.end());
    printVector(d); 
    return 0;
}