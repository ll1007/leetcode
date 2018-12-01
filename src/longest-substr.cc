#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {

public:
	bool book[256];
	void reset_book(){
		for(int i = 0; i < 256; ++i){
			book[i] = false;
		}
	}
	int lengthOfLongestSubstring(string s){
		const char *str = s.c_str();
		int size = s.size();
		int global_max = 0;
		int current_max = 0;
		if (size == 1){
			return 1;
		}
		for (int i = 0; i < size - 1; ++i){
			reset_book();
			book[str[i]] = true;
			current_max = 1;
			for(int j = i + 1; j < size && !book[str[j]]; ++j){
				book[str[j]] = true;
				++current_max;
			}
			if (current_max > global_max){
				global_max = current_max;
			}
		}
		return global_max;
	}

	// solution 2
	int lengthOfLongestSubstring2(string s){
		set<int> set1;
		const char *str = s.c_str();
		int size = s.size();
		int ans = 0, i = 0, j = 0;
		while(i < size && j < size){
			if(set1.find(str[j]) == set1.end()){
				set1.insert(str[j]);
				j++;
				ans = (j-i) > ans ? (j-i) : ans;
			} else {
				set1.erase(str[i]);
				i++;
			}
		}
		return ans;
	}

};

int main(){
	Solution s;

	cout << s.lengthOfLongestSubstring2("abcabcbb") << endl;
	cout << s.lengthOfLongestSubstring2("bbbbb") << endl;
	cout << s.lengthOfLongestSubstring2("pwwkew") << endl;
	cout << s.lengthOfLongestSubstring2(" ") << endl;
	cout << s.lengthOfLongestSubstring2("") << endl;

	return 0;
}