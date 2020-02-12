#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* next =NULL;
	node(int d){
	data=d;
	next=NULL;
	}
};
node* insertAthead(node*&head,int data){
	node *n = new node(data);
	n->next=head;
	head=n;
}
node * buildlist(node*&head){
	int d;
	cin>>d;
	while(d--){
	int data;
	cin>>data;
	insertAthead(head,data);
	}
}
void print( node*head){
	while(head!=NULL){
	cout<<head->data<<" ";
	head=head->next;
	}
}
node* midpoint(node*head){
	if(head==NULL||head->next==NULL){
		return head;
	}
	node*small=head;
	node*fast=head->next;
	while(fast!=NULL&&fast->next!=NULL){
		fast=fast->next->next;
		small=small->next;
	}
	return small;
}
node *reverse(node*&head){
	node*c=head;
	node*n;
	node*p=NULL;
	while(c!=NULL){
		n=c->next;
		c->next=p;
		p=c;
		c=n;

	}
	return head=p;
}
node * recursive(node *&head){
	if(head==NULL||head->next==NULL){
		return head;
	}
	node* smallnode=recursive(head->next);
	node*c=head;
	c->next->next=c;
	c->next=NULL;
	return smallnode;

}
void insertAtTail(Node *&head, int data) {
		if(head == NULL) {
			insertATHead(head, data);
			return;
		}
		Node *temp = head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		Node *new_node = new Node(data);
		temp->next = new_node;
		return;
	}
istream &operator >> (istream&is ,node*&head){
	buildlist(head);
	return is;

}
ostream & operator << (ostream &os ,node*head)
{
	print(head);
	return os;
}
int main(){
node*head=NULL;
	cin>>head;
	cout<<head;
	head=midpoint(head);
	head=reverse(head);
	head=recursive(head);
	cout<<head;
}
