#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <array>
// #include <fstream>

using std::vector;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target){
        int size = nums.size();
        vector<int> ans;
        for ( int i = 0; i < size - 1; ++i){
            for (int j = i + 1; j < size; ++j){
                if ( (nums[i] + nums[j]) == target){                   
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
	}
};

void print_vector(vector<int>& ins){
	for(auto it = ins.begin(); it != ins.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;	
}


int main(){

	std::array<int, 4> arr = {2, 7, 11, 13};

	vector<int> ins(arr.begin(), arr.end());

	print_vector(ins);
	Solution s;
	vector<int> ans = s.twoSum(ins, 9);
	print_vector(ans);

	return 0;
}