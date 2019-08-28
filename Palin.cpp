#include<iostream>
#include<vector>
using namespace std;
struct Node {
	int data;
	Node*next;
};
void push(Node*head,int data)
{
	Node*temp=new Node();
	temp->data=data;
	temp->next=head;
    head=temp;
}
void reverse(Node*head)
{
	Node*result=nullptr;
	Node*current=head;

	
	while (current!=nullptr)
	{
		
		Node*next=current->next;
		current->next=result;
		result=current;
		current=next;
	}
	head=result;
}
bool compare(Node*a,Node*b)
{
	if (a==nullptr&&b==nullptr)
		return true;
return a&&b&&(a->data==b->data)&&compare(a->next,b->next);
}
Node* findMiddle(Node*head,bool odd)
{
	Node*prev=nullptr;
	Node*slow=head,*fast=head;
	while(fast&&fast->next)
	{
		prev=slow;
		slow=slow->next;
		fast=fast->next->next;
	}
	if (fast)
		odd=true;
	prev->next=nullptr;
	return slow;
}
bool checkPalindrome(Node*head)
{
	if (head==nullptr)
		return true;
	bool odd=false;
	Node*mid=findMiddle(head,odd);
	if (odd)
		mid=mid->next;
	reverse(mid);
	return compare(head,mid);
}
int main()
{
	vector<int>keys={1,2,3,2,1};
    Node*head=nullptr;
	for(int i=keys.size()-1;i>=0;i--)
		push(head,keys[i]);
	if(checkPalindrome(head))
		cout<<"Linked list is Palindrome";
	else
		cout<<"Linked list is not Palindrome";
	return 0;
}
