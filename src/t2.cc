#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
		int c = 0;
		ListNode* out = new ListNode(0);
		ListNode* pOut = out;
		ListNode* nextToLast = NULL;
		while(l1 != NULL || l2 != NULL){
			int a, b;
			// load val
			if (l1 != NULL){
				a = l1->val;
			} else {
				a  = 0;
			}
			if (l2 != NULL){
				b = l2->val;
			} else {
				b  = 0;
			}
			
			pOut->val = (a + b + c) % 10;
			c = (a + b + c) / 10;

			// update pointers
			if(l1) l1 = l1->next;
			if(l2) l2 = l2->next;
			pOut->next = new ListNode(c);
			nextToLast = pOut;
			pOut = pOut->next;
		}

		if(c == 0){
			delete nextToLast->next;
			nextToLast->next = NULL;
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
	// case 1
	// ListNode *l1 = new ListNode(2);
	// ListNode *p1 = l1;
	// p1->next = new ListNode(4);
	// p1 = p1->next;
	// p1->next = new ListNode(3);

	// ListNode *l2 = new ListNode(5);
	// p1 = l2;
	// p1->next = new ListNode(6);
	// p1 = p1->next;
	// p1->next = new ListNode(4);

	// case 2
	ListNode *l1 = new ListNode(0);
	ListNode *l2 = new ListNode(1);
	l2->next = new ListNode(8);

	print_list_node(l1);
	print_list_node(l2);
	print_list_node(s.addTwoNumbers(l1, l2));
	return 0;
}