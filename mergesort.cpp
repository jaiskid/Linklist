#include<bits/stdc++.h>
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
node *insertAthead(node*&head,int data){
	node *n=new node(data);
	n->next=head;
	head=n;

}
node*buildlist(node*&head){
	int d;
	cin>>d;
	while(d--){
	int data;
	cin>>data;
	insertAthead(head,data);
	}
}
void print(node*head){
	while(head!=NULL){
	cout<<head->data<<" ";
	head=head->next;
	}
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
node *recursive(node* head){
	if(head!=NULL||head->next==NULL)
	{
	return head;
	}
	
	node *smallnode =recursive(head->next);
	node*c=head;
	c->next->next=c;
	c->next=NULL;
	return smallnode;
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
node*merge(node*a,node*b){
	if(a==NULL){
		return b;
	}
	else if(b==NULL){
		return a;
	}
	node* c;
	if(a->data<b->data){
		c=a;
		c->next=merge(a->next,b);
	}
	else{
		c=b;
		c->next=merge(a,b->next);
	}
	return c;
}
node* mergesort(node* head){
	//base Case
	if(head==NULL||head->next==NULL){
		return head;
	}
	//rec Case
	//Mid point 
	node* mid = midpoint(head);
	node*a=head;
	node*b=mid->next;
	mid->next=NULL;
	//2.Recursively sort
	a=mergesort(a);
	b=mergesort(b);
	//Merge a and b
	node* c=merge(a,b);
	return c;
}
istream &operator>>(istream &is ,node *&head){
	buildlist(head);
	return is;
}
ostream &operator<<(ostream&os ,node*head)
{
	print(head);
	return os;
}
int main(){
	node*head=NULL;
	cin>>head;
	head=mergesort(head);
	cout<<head;
	

}