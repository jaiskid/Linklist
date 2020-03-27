#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};
ListNode* rotateNode(ListNode* head, int k) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	int n = 1;
	auto curr = head;
	for (; curr->next; curr = curr->next) {
		++n;
	}
	curr->next = head;
	auto tail = curr;
	k = n - k % n;
	curr = head;
	for (int i = 0; i < k; curr = curr->next, i++) {
		tail = curr;
	}
	tail->next = NULL;
	return curr;
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
	int k;
	cin >> k;

	n1 = rotateNode(n1, k);
	print(n1);
}