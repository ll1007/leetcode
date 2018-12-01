#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
	const int MAX_INT = 0x7fffffff;
    int reverse(int x) {
        bool neg = false;
        if (x < 0){
        	neg = true;
        	x = -x;
        }
        queue<int> q;
        while( x > 0) {
        	q.push(x%10);
        	x /= 10;
        }
        long long res = 0;
        bool beg = true;
        while(!q.empty()){
        	int t = q.front(); q.pop();
        	if (beg){
        		beg = false;
        		if ( t == 0) continue;
        	}
    		res = res * 10 + t;
        }
        if (res > static_cast<long long>(MAX_INT)){
        	res = 0;
        }
        if (neg) res = -res;
        return res;
    }
};

int main(){
	Solution s;
	// cout << s.reverse(123) << endl;
	// cout << s.reverse(-123)<< endl;
	// cout << s.reverse(120) << endl;
	cout << s.reverse(1534236469) << endl;
	cout << s.reverse(1463847412) << endl;
	
	return 0;
}