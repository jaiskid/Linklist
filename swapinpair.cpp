#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};
void intail(ListNode*&head, int data) {
	if (head == NULL) {
		head = new ListNode(data);
		return;
	}
	ListNode*tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}

	tail->next = new ListNode(data);
	return;
}
ListNode* swapPairs(ListNode *head){
	ListNode dummy{0};
	dummy.next=head;
	auto curr=&dummy;
	while(curr->next and curr->next->next){
		auto next_one=curr->next;
		auto next_two=next_one->next;
		auto next_three=next_two->next;
		curr->next=next_two;
		next_two->next=next_one;
		next_one->next=next_three;
		curr=next_one;
	}
	return dummy.next;
}
void buildlist(ListNode*&head) {
	int n;
	cin >> n;
	while (n--) {
		int data;
		cin >> data;
		intail(head, data);
	}
}
void print(ListNode*n) {
	while (n != NULL) {
		cout << n->val << " ";
		n = n->next;
	}
}
int main() {
	ListNode*n1 = NULL;
	buildlist(n1);
	print(n1);
	n1=swapPairs(n1);
	cout << endl;
	print(n1);
}