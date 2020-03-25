#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node* next;
	node(int d) {
		data = d;
		next = NULL;
	}
};
void print(node*head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}
void insertAthead(node*&head, int data) {
	if (head == NULL) {
		head = new node(data);
		return;
	}
	node *n = new node(data);
	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = n;

}
node * evenodd(node*head) {
	node*oddhead = NULL;
	node*evenhead = NULL;
	while (head != NULL) {
		if (((head->data) & 1) == 1) {
			insertAthead(oddhead, head->data);
		}
		else
			insertAthead(evenhead, head->data);
		head = head->next;
	}
	if (oddhead == NULL)
		oddhead = evenhead;
	else {
		node*temp = oddhead;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = evenhead;
	}
	return oddhead;
}
int main() {
	node*head = NULL;
	int n;
	cin >> n;
	int data;
	while (n--) {
		cin >> data;
		insertAthead(head, data);
	}
	node *a = NULL;
	a = evenodd(head);
	print(a);
	return 0;

}