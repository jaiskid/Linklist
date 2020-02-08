#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node * next;
	node(int d){
	data=d;
	next=NULL;
	}
};
node* insertAtHead(node *&head,int d){
	node *n=new node(d);
	n->next=head;
	head=n;
}
void print(node *head){
	while(head!=NULL){
	cout<<head->data<<" ";
	head=head->next;
	}
}
node* buildlist(node*&head){
	int d;
	cin>>d;
	while(d--){
	int data;
	cin>>data;
	insertAtHead(head,data);
	
	}
	return head;
}
istream & operator>>(istream &is ,node *&head){
	buildlist(head);
	return is;
}
ostream &operator<<(ostream &os,node *head){
	print(head);
	return os;
}

int main(){
	node*head=NULL;
	cin>>head;
	cout<<head;
}