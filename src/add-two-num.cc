#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
		int a = l1->val;
		int b = l2->val;
		int c = 0;
		ListNode* out = new ListNode(0);
		out->val = (a + b + c) % 10;
		c = (a + b + c) / 10;
		ListNode* pOut = out;
		while(l1 != NULL && l2 != NULL){
			a = l1->val;
			b = l2->val;
			pOut = new ListNode(c);
			pOut->val = (a + b + c) % 10;
			c = (a + b + c) / 10;
			l1 = l1->next;
			l2 = l2->next;
			pOut = pOut->next;
		}
		while (l1 != NULL){
			int a = l1->val;
			pOut = new ListNode(c);
			pOut->val = (a + c) % 10;
			c = (a + c) / 10;
			l1 = l1->next;
			pOut = pOut->next;
		}
		while (l2 != NULL){
			int a = l2->val;
			pOut = new ListNode(c);
			pOut->val = (a + c) % 10;
			c = (a + c) / 10;
			l2 = l2->next;
			pOut = pOut->next;
		}
		if ( c != 0){
			pOut = new ListNode(c);
		}
		return out;
	}
};

void print_list_node(ListNode *l){
	while(l->next != NULL){
		std::cout << l->val << " -> ";
		l = l->next;
	}
	std::cout << l->val << std::endl;
}

int main(){
	Solution s;
	ListNode *l1 = new ListNode(2);
	ListNode *p1 = l1;
	p1->next = new ListNode(4);
	p1 = p1->next;
	p1->next = new ListNode(3);

	ListNode *l2 = new ListNode(5);
	p1 = l2;
	p1->next = new ListNode(6);
	p1 = p1->next;
	p1->next = new ListNode(4);

	print_list_node(l1);
	print_list_node(l2);
	print_list_node(s.addTwoNumbers(l1, l2));
	return 0;
}