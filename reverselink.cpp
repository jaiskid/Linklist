#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
	int data;
	node* next;
	node(int d){
	data=d;
	next=NULL;
	}
};
node* insertAthead(node *&head,int data)
{
	node *n =new node(data);
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
istream & operator >> (istream&is,node*&head){
	buildlist(head);
	return is;
}
ostream & operator<< (ostream&os ,node*&head){
	print(head);
	return os;
}
node *reverse(node*&head){
	node*c=head;
	node*p=NULL;
	node*n;
	while(c!=NULL){
	//save the next node
	n=c->next;
	//Make the current node to the previous
	c->next=p;
	p=c;
	c=n;
	}
	return head=p;
}
int main(){
	node*head=NULL;
	cin>>head;
	cout<<head;
	reverse(head);
	cout<<endl;
	cout<<head;
}