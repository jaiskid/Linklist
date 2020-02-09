#include<bits/stdc++.h>
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
node * insertAthead(node*&head,int d)
{
	node *n =new node(d);
	n->next=head;
	head=n;
}
node *buildlist(node*&head){
	int d;
	cin>>d;
	while(d--){
	int data;
	cin>>data;
	insertAthead(head,data);
	}	
}
void print(node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}
node* reverse(node*&head){
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
node *recursivere(node*head){
	if(head->next==NULL||head==NULL){
		return head;
	}
	node*smallhead=recursivere(head->next);
	node*c=head;
	c->next->next=c;
	c->next=NULL;
	return smallhead;
}
int midpoint(node*head){
	if(head->next==NULL||head==NULL){
	return head->data;
	}
	
	node*slow=head;
	node*fast=head->next;
	while(fast!=NULL&&fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow->data;
}
node* merge(node*a,node*b){
	if(a==NULL){
		return b;
	}
	else if(b==NULL){
		return a;
	}
	node *c;
	if(a->data<b->data){
		c=a;
		c->next=merge(a->next,b);
	}else{
		c=b;
		c->next=merge(a,b->next);
	}
	return c;
}
istream & operator >> (istream & is ,node*&head){
	buildlist(head);
	return is;
}
ostream &operator << (ostream & os ,node *head){
	print(head);
	return os;
}
int main(){
	node*head=NULL;
	node*head1=NULL;
	cin>>head>>head1;
	head=merge(head,head1);
	cout<<head;
	
	
}