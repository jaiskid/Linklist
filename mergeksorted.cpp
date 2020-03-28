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
ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.empty()) {
		return NULL;
	}
	int left = 0, right = lists.size() - 1;
	while (right > 0) {
		if (left >= right) {
			left = 0;
		}
		else {
			lists[left] = mergeTwolists(lists[left], lists[right]);
			++left;
			--right;
		}
	}
	return lists[0];
}
ListNode *mergeTwolists(ListNode* l1, ListNode* l2) {
	if (l1 == NULL)
		return l2;
	else if (l2 == NULL) {
		return l1;
	}
	ListNode *c;
	if (l1->val < l2->val) {
		c = l1;
		c->next = mergeTwolists(l1->next, l2);
	}
	else {
		c = l2;
		c->next = mergeTwolists(l1, l2->next);
	}
	return c;
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
	print(n1);
}