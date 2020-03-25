#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* next;
	node(int d){
	data=d;
	next=NULL;
	}
};
node *insertAthead(node*&head,int data){
	node*n=new node(data);
	n->next=head;
	head=n;
}
void print(node*head){
	while(head!=NULL){
	cout<<head->data<<" ";
	head=head->next;
	}
}
node * reverse(node*head){
	node*n;
	node*c=head;
	node*p=NULL;
	while(c!=NULL){
	n=c->next;
	c->next=p;
	p=c;
	c=n;
	}
	head=p;
}
node * recursive(node*head){
	if(head==NULL||head->next==NULL)
	return head;
	node*smallnode =recursive(head->next);
	node*c=head;
	c->next->next=c;
	c->next=NULL;
	return smallnode;
}
node* midpoint(node*head){
	if(head==NULL||head->next==NULL){
	return head;
	}
	node*slow=head;
	node*fast=head->next;
	while(fast!=NULL&&fast->next!=NULL){
	fast=fast->next->next;
	slow=slow->next;
	}
	return slow;
}
node*buildlist(node*&head){
	int d;
	cin>>d;
	while(d--)
	{
	int data;
	cin>>data;
	insertAthead(head,data);
	}
}
int length(node*head){
	int result=0;
	while(head!=NULL){
		result++;
		head=head->next;
	}
	return result;
}
istream &operator >>(istream &is,node*&head){
	buildlist(head);
	return is;
}
ostream &operator<<(ostream &os,node*head){
	print(head);
	return os;
} 
int main(){
	node*head=NULL;
	cin>>head;
	cout<<length(head);
	cout<<head;
} 