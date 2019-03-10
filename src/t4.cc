#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int find_position(vector<int>& nums, int val){
		int l, h;
		int size = nums.size();
		while(l < h) {
			int p = (h + l) / 2;
			if (nums[p] == val) return p;
			else if (nums[p] < val) h = p;
			else if (nums[p] > val) l = p;
		}
		return l;
	}


    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int half_n = n >> 1;

        int low = (upper_bound(nums1.begin(), nums1.end(), nums2[half_n]) - nums1.begin());
        cout << low << endl;
    }
};

void print_vector(vector<int>& v){
	for(auto it = v.begin(); it != v.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

int main(){
	Solution s;

	vector<int> v1;
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	vector<int> v2;
	v2.push_back(3);

	cout << "v1: ";
	print_vector(v1);
	cout << "v2: ";
	print_vector(v2);
	s.findMedianSortedArrays(v1, v2);
}