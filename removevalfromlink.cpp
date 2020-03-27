#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};
ListNode* removeElement(ListNode*head, int val) {
	for (auto *indirect = &head ; *indirect != NULL;) {
		if ((*indirect)->val == val) {
			*indirect = (*indirect)->next;
			continue;
		}
		indirect = &(*indirect)->next;
	}
	return head;
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
	int v;
	cin >> v;
	n1 = removeElement(n1, v);
	print(n1);
}