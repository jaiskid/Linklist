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
void buildlist(ListNode*&head) {
	int n;
	cin >> n;
	while (n--) {
		int data;
		cin >> data;
		intail(head, data);
	}
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	ListNode *curA = headA, *curB = headB;
	ListNode *begin = NULL, *tailA = NULL, *tailB = NULL;
	while (curA && curB) {
		if (curA == curB) {
			begin = curA;
			break;
		}

		if (curA->next) {
			curA = curA->next;
		} else if (!tailA) {
			tailA = curA;
			curA = headB;
		} else {
			break;
		}

		if (curB->next) {
			curB = curB->next;
		} else if (!tailB) {
			tailB = curB;
			curB = headA;
		} else {
			break;
		}
	}

	return begin;
}
void print(ListNode*n) {
	while (n != NULL) {
		cout << n->val << " ";
		n = n->next;
	}
}
int main() {
	ListNode*n1 = NULL;
	ListNode*n2 = NULL;
	buildlist(n1);
	buildlist(n2);
	ListNode*n3 = NULL;
	n3 = getIntersectionNode(n1, n2);
	cout << n3->val;
}