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
ListNode* mergesortlink(ListNode* l1, ListNode*l2) {
	if (l1 == NULL) {
		return l2;
	}
	else if (l2 == NULL)
	{
		return l1;
	}
	ListNode*c;
	if (l1->val < l2->val) {
		c = l1;
		c->next = mergesortlink(l1->next, l2);
	}
	else {
		c = l2;
		c->next = mergesortlink(l1, l2->next);
	}
	return c;
}
ListNode* mergesort(ListNode*head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	ListNode*fast = head;
	ListNode*slow = head;
	while (fast->next and fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	fast = slow;
	slow = slow->next;
	fast->next = NULL;
	return mergesortlink(mergesort(head), mergesort(slow));
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
	n1 = mergesort(n1);
	print(n1);
}