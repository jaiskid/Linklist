#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
TreeNode* sortedListToBST(ListNode* head) {
	auto curr = head;
	int n = 0;
	while (curr) {
		curr = curr->next;
		++n;
	}
	return Buildbst(&head, 0, n);
}
TreeNode* Buildbst(ListNode**head, int s, int e) {
	if (s == e) {
		return NULL;
	}
	int m = s + ((e - s) / 2);
	auto left = Buildbst(head, s, m);
	auto curr = new TreeNode((*head)->val);
	*head = (*head)->next;
	curr->left = left;
	curr->right = Buildbst(head, m + 1, e);
	return curr;
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