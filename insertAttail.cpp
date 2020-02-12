#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	int data;
	node *next;
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
void print(node*head){
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
	insertAthead(head,data);
	}
}
istream &operator >> (istream& is,node*&head){
	buildlist(head);
	return is;
}
ostream &operator << (ostream& os,node*&head){
	print(head);

	return os;
}
int main(){
	node *head=NULL;
	cin>>head;
	cout<<head;
}