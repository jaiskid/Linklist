#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node*next;
	node(int d){
	data=d;
	next=NULL;
	}
};
node* insertAthead(node*&head,int d){
	node*n =new node(d);
	n->next=head;
	head=n;

}
node* buildlist(node*&head){
	int d;
	cin>>d;
	while(d--)
	{
	int data;
	cin>>data;
	insertAthead(head,data);
	}
}
void print(node*head)
{
	while(head!=NULL){
	cout<<head->data<<" ";
	head=head->next;
	}
}
istream &operator >>(istream &is,node*&head){
	buildlist(head);
	return is;
}
ostream &operator <<(ostream&os,node*&head){
	print(head);
	return os;
}
node* reverse(node*&head){
	node*c=head;
	node*p=NULL;
	node*n;
	while(c!=NULL){
	n=c->next;
	c->next=p;
	p=c;
	c=n;
	}
	return head=p;
}
node* recursivere(node*&head){
	if(head->next==NULL||head==NULL){
	return head;
	}
	node* smallnode =recursivere(head->next);
	node*c=head;
	c->next->next=c;
	c->next=NULL;
	return smallnode;
}
int midpoint(node*head){
	if(head->next==NULL||head==NULL){
	return head->data;
	}
	node *slow=head;
	node *fast=head->next;
	while(fast!=NULL&&fast->next!=NULL){
	fast=fast->next->next;
	slow=slow->next;
	}
	return slow->data;
}
int main(){ 
	cin>>head;
	cout<<head;
	head=recursivere(head);
	cout<<head;

	head=reverse(head);
	cout<<head;
	cout<<midpoint(head);
}