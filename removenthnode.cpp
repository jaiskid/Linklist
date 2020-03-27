#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};
ListNode* removeNthFromEnd(ListNode *head, int n) {
	ListNode dummy{0};
	dummy.next = head;
	auto slow = &dummy;
	auto fast = &dummy;
	//fast n step ahead
	while (n > 0) {
		fast = fast->next;
		n--;
	}
	while (fast->next != NULL) {
		slow = slow->next;
		fast = fast->next;
	}
	auto node_to_delete = slow->next;
	slow->next = slow->next->next;
	delete node_to_delete;
	return dummy.next;
}
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
	cout << endl;
	int n;
	cin >> n;
	n1 = removeNthFromEnd(n1, n);
	cout << endl;
	print(n1);
}