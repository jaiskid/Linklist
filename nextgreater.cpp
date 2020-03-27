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
vector<int> nextLargerNodes(ListNode* head) {
	vector<int> result;
	vector<pair<int, int>> stk;
	for (auto node = head; node; node = node->next) {
		while (!stk.empty() && stk.back().second < node->val) {
			result[stk.back().first] = node->val;
			stk.pop_back();
		}
		stk.emplace_back(result.size(), node->val);
		result.emplace_back(0);
	}
	return result;
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
	vector<int> res;
	res = nextLargerNodes(n1);
	for (int i = 0; i < res.size(); i++)
		cout << res[i];
	//print(n1);
}