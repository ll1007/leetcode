#include <iostream>

class Solution {
public:
	enum Level {
		I = 1, 
		V = 5, 
		X = 10, 
		L = 50, 
		C = 100, 
		D = 500, 
		M = 1000
	};

	int update_result(int& last, int level){
		int ret = level;
		if (last != 0 && last < level){
			ret = level - last;
			last = 0;
		} else if (last > level) {	
			ret = last;
			last = level;
		}
		return ret;
	}

    int romanToInt(string s) {
        int level = M;
        const char *str = s.c_str();
        int size = s.size();
        int res = 0;
        int last = 0;
        for (int i = 0; i < size; ++i){
        	switch(str[i]){
        		case 'I':
        			last = Level.I;
        			break;
        		case 'V':
        		case 'X':
        		case 'L':
        		case 'C':
        		case 'D':
        			res += update_result(last, Level.D);
        		case 'M':
        			res += update_result(last, Level.M);
        			break;
        		default:
        	}
        }
    }
};

int main(){
	return 0;
}