#include <iostream>
#include <string>

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

};

int main(){
	Solution s;

	cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
	cout << s.lengthOfLongestSubstring("bbbbb") << endl;
	cout << s.lengthOfLongestSubstring("pwwkew") << endl;
	cout << s.lengthOfLongestSubstring(" ") << endl;
	cout << s.lengthOfLongestSubstring("") << endl;

	return 0;
}