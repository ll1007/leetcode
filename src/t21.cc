#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int v) : val(v), next(NULL){}
};

void print_list_node(ListNode *l){
	while(l->next != NULL){
		std::cout << l->val << " -> ";
		l = l->next;
	}
	std::cout << l->val << std::endl;
}

class Solution {
public:
	void add_rest(ListNode *out, ListNode* in){
		if (in == NULL) return;
		out = in;
	}
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if (l1 == NULL && l2 == NULL) return NULL;	
    	ListNode *head;
    	if (l1 != NULL) head = new ListNode(l1->val);
    	else if (l2 != NULL) head = new ListNode(l2->val);
    	ListNode *ptr = head;
    	bool begin = true;
        while(l1 != NULL && l2 != NULL){
        	int a = l1->val; 
        	int b = l2->val;
        	if ( a < b ){
        		if (begin){
        			begin = false;
        			ptr->val = a;
        		} else {
        			ptr->next = new ListNode(a);
        			ptr = ptr->next;
        		}
        		ptr->next = new ListNode(b);
        	} else {
        		if (begin){
        			begin = false;
        			ptr->val = b;
        		} else {
        			ptr->next = new ListNode(b);
        			ptr = ptr->next;
        		}
        		ptr->next = new ListNode(a);
        	}
        	ptr = ptr->next;
        	l1 = l1->next;
        	l2 = l2->next;
        }
        add_rest(ptr, l1);
        add_rest(ptr, l2);
        return head;
    }
};

int main(){
	Solution s;

	// ListNode *l1 = new ListNode(1);
	ListNode *ptr;
	// ptr->next = new ListNode(2);
	// ptr = ptr->next;
	// ptr->next = new ListNode(4);
	
	// ListNode *l2 = new ListNode(1);
	// ptr = l2;
	// ptr->next = new ListNode(3);
	// ptr = ptr->next;
	// ptr->next = new ListNode(4);

	ListNode *l1 = new ListNode(5);
	ListNode *l2 = new ListNode(1);
	ptr = l2;
	ptr->next = new ListNode(3);
	ptr = ptr->next;
	ptr->next = new ListNode(4);

	// print_list_node(l1);
	// print_list_node(l2);
	print_list_node(s.mergeTwoLists(l1, l2));

	return 0;
}