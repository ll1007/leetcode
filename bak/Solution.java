import java.util.Stack;

public class Solution {
	
	Stack<Integer> stack1 = new Stack<Integer>();
	Stack<Integer> stack2 = new Stack<Integer>();

//	测试用例:
//	["PSH3","MIN","PSH4","MIN","PSH2","MIN","PSH3","MIN","POP",
//		"MIN","POP","MIN","POP","MIN","PSH0","MIN"]
//
//	对应输出应该为:
//
//	3,3,2,2,2,3,3,0
	
	public final static void main(String argv[]){
		Solution S = new Solution();
		
		S.push(3);
	}
    
    public void push(int node) {
        stack1.push(node);
        if(!stack2.empty() && node <= stack2.peek())
        	stack2.push(node);
    }
    
    public void pop() {
    	if(stack1.empty()) return;
        int ret = stack1.pop();
        if(ret == stack2.peek())
        	stack2.pop();
    }
    
    public int top() {
        return stack1.peek();
    }
    
    public int min() {
        return stack2.peek();
    }
}
	
//    public String intToRoman(int num) {
//    	
//    	String[] roman = new String[5];
//    	roman[0] = "";
//    	roman[1] = "I";		// 1
//    	roman[2] = "II";	// 2
//    	roman[3] = "III";	// 3
//    	roman[4] = "IV";	// 4
//        
//    	String res = "";
//    	
//    	int numberOfM = num / 1000;	
//    	num -= numberOfM * 1000;
//    	
//    	for(int i = 0; i < numberOfM; i++){
//    		res = res.concat("M");
//    	}
//    	
//    	int numberOfD = num / 500;
//    	num -= numberOfD * 500;
//    	
//    	for(int i = 0; i < numberOfD; i++){
//    		res = res.concat("D");
//    	}
//    	
//    	int numberOfC = num / 100;
//    	num -= numberOfC * 100;
//    	
//    	for(int i = 0; i < numberOfC; i++){
//    		res = res.concat("C");
//    	}
//    	
//    	int numberOfL = num / 50;
//    	num -= numberOfL * 50;
//    	
//    	for(int i = 0; i < numberOfL; i++){
//    		res = res.concat("L");
//    	}
//    	
//    	int numberOfX = num / 10;
//    	num -= numberOfX * 10;
//    	
//    	for(int i = 0; i < numberOfX; i++){
//    		res = res.concat("X");
//    	}
//    	
//    	int numberOfV = num / 5;
//    	num -= numberOfV * 5;
//    	
//    	for(int i = 0; i < numberOfV; i++){
//    		res = res.concat("V");
//    	}
//    	
//    	res = res.concat(roman[num]);
//    	
//    	return res;
//    }

