#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        vector<int> v;
        while ( x > 0){
        	v.push_back(x % 10);
        	x /= 10;
        }
        int n = v.size();
        for(int i = 0; i <= (n >> 1); ++i){
        	if (v[i] != v[n-i-1]){
        		return false;
        	}
        } 
        return true;
    }

    bool isPalindrome2(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        int reverse = 0;
        while ( x > 0){
        	reverse = reverse * 10 + (x % 10);
        	int t = x;
        	x /= 10;
        	if (reverse == t || reverse == x) {
        		return true;
        	} else if (reverse > t) {
        		return false;
        	}
        }
        return false;
    }
};


int main(){
	Solution s;
	cout << s.isPalindrome2(121) << endl;
	cout << s.isPalindrome2(-121) << endl;
	cout << s.isPalindrome2(10) << endl;
	
	return 0;
}