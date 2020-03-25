#include<bits/stdc++.h>
using namespace std;
struct Listnode {
	int val;
	Listnode *next;
	Listnode(int x) {
		val = x;
		next = NULL;
	}
};
Listnode* insertAthead(Listnode*&head, int data) {
	Listnode *n = new Listnode(data);
	n->next = head;
	head = n;
	return head;
}

void print(Listnode*n) {
	while (n != NULL) {
		cout << n->val << " ";
		n = n->next;
	}
}
void intail(Listnode*&head, int data) {
	if (head == NULL) {
		head = new Listnode(data);
		return;
	}
	Listnode*tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}

	tail->next = new Listnode(data);
	return;
}
void buildlist(Listnode*&head) {
	int n;
	cin >> n;
	while (n--) {
		int data;
		cin >> data;
		intail(head, data);
	}
}
Listnode* addtwoNumber(Listnode *l1, Listnode *l2) {
	Listnode dummy{0};
	auto curr = &dummy;
	auto carry = 0;
	while (l1 || l2 || carry) {
		auto a = l1 ? l1->val : 0;
		auto b = l2 ? l2->val : 0;
		auto val = carry + a + b;
		curr->next = new Listnode(val % 10);
		carry = val / 10;
		l1 = l1 ? l1->next : NULL;
		l2 = l2 ? l2->next : NULL;
		curr = curr->next;
	}
	return dummy.next;
}
int main() {
	Listnode*n1 = NULL;
	Listnode*n2 = NULL;
	buildlist(n1);
	buildlist(n2);
	print(n1);
	cout << endl;
	print(n2);
	Listnode *n3 = NULL;
	n3 = addtwoNumber(n1, n2);
	cout<<endl;
	print(n3);
}