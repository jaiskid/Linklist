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
ListNode* deleteDuplicate(ListNode* head) {
	ListNode dummy{0};
	auto prev = &dummy;
	while (head) {
		if (head->next and head->next->val == head->val)
		{
			auto val = head->val;
			while (head and head ->val == val) {
				head = head->next;
			}
			prev->next = head;
		}
		else {
			prev->next = head;
			prev = head;
			head = head->next;
		}
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
	cout << endl;
	n1 = deleteDuplicate(n1);
	print(n1);
}