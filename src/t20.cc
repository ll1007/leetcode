#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
	bool isMatch(char a, char b){
		if (a == '{' && b == '}') return true;
		if (a == '[' && b == ']') return true;
		if (a == '(' && b == ')') return true;
		return false;
	}
    bool isValid(string s) {
        stack<char> st;
        const char *str = s.c_str();
        int size = s.size();
        for (int i = 0; i < size; ++i){
        	if (!st.empty() && isMatch(st.top(), str[i])){
        		st.pop();
        		continue;
        	}
        	st.push(str[i]);     	
        }
        return st.empty();
    }
};

int main(){
	Solution s;
	cout << s.isValid("()") << endl;
	cout << s.isValid("()[]{}") << endl;
	cout << s.isValid("([)") << endl;

	return 0;
}