#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        int size = strs.size();
        if (size == 0) return ret;
        string start = strs[0];
        for(int i = 0; i < start.size(); ++i){
            for(int j = 1; j < size; ++j){
                if (start[i] != strs[j][i]){
                    return ret;
                }
            }
            ret = start.substr(0, i + 1);
        }
        return ret;
    }
};

int main(){
    Solution s;
    vector<string> v1;
    v1.push_back("flower");
    v1.push_back("flow");
    v1.push_back("flight");

    vector<string> v2;
    v2.push_back("dog");
    v2.push_back("racecar");
    v2.push_back("cat");


    cout << s.longestCommonPrefix(v1) << endl;
    cout << s.longestCommonPrefix(v2) << endl;

    return 0;
}