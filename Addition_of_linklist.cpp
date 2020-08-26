#include<iostream>
using namespace std;

class node
{ public:
int data;
node *next;	
node*prev;
};

class sll
{ public:
node*head,*newhead,*head3;
sll()
{
	head=NULL;
	newhead=NULL;
	head3=NULL;
}
void insert();
void insert_new();
void addition();
void display();	
};
void sll::insert()
{
	int data;
	cout<<"Enter the data:";
	cin>>data;
	node*temp=new node;
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	if(head==NULL)
	{   
		head=temp;
		
	}
	else
	{
		node*copyhead=head;
		while(copyhead->next!=NULL)
		{
			
			copyhead=copyhead->next;
		}
	    copyhead->next=temp;
		temp->prev=copyhead;
	}	
}
void sll::insert_new()
{
    int data;
	cout<<"Enter the data:";
	cin>>data;
	node*temp=new node;
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	if(newhead==NULL)
	{
		newhead=temp;
	}
	else
	{
		node*copyhead=newhead;
		while(copyhead->next!=NULL)
		{
			
			copyhead=copyhead->next;
		}
	    copyhead->next=temp;
		temp->prev=copyhead;
	}	
}
void sll::addition()
{
	node*temp=new node;
	temp->next=NULL;
	temp->prev=NULL;
	node*p=head;
	node*q=newhead;
	int count1=1,count2=1;
    while(p->next!=NULL)
    {
    	count1++;
    	p=p->next;
	}
	while(q->next!=NULL)
	{
		count2++;
		q=q->next;
	}
	int b=0;
	while(count1>0 || count2>0)
	{
		node*temp=new node;
     	temp->next=NULL;
	    temp->prev=NULL;
	    if(count1>0 && count2>0)
	    {  
	    	temp->data=p->data+q->data+b;
		}
		else if(count1>0 && count2==0)
		{ 
			temp->data=p->data+b;
			
		}
		else if(count1==0 && count2>0)
		{   
			temp->data=q->data+b;
		}
		node*temp1=new node;
     	temp1->next=NULL;
	    temp1->prev=NULL;
	    temp1->data=temp->data;
		
		if(temp->data>=10)
		{
			if(head3==NULL)
			{
				head3=temp1;
				temp1->data=temp1->data%10;
				b=temp->data/10;
		    }
		    else
		    {
		    	node*c=head3;
		    	while(c->next!=NULL)
		    	{
		    		c=c->next;
				}
				c->next=temp1;
				temp1->prev=c;
				temp1->data=temp1->data%10;
				b=temp->data/10;
			}
		}
		else
		{
			if(head3==NULL)
		{
			head3=temp1;
			b=0;
			
		}
		else
		{
			node *a=head3;
			while(a->next!=NULL)
			{
				a=a->next;
			}
			a->next=temp1;
			temp1->prev=a;
			b=0;
		}
		}
	
		count1--;
		count2--;
		
		if(p!=NULL)
		p=p->prev;
		if(q!=NULL)
		{ 
			q=q->prev;
		
		}
		
	}
	
}
void sll::display()
{   
	node*copyhead=head3;
	while(copyhead->next!=NULL)
	{
		
		copyhead=copyhead->next;
	}
	while(copyhead!=NULL)
	{
		cout<<copyhead->data;
		copyhead=copyhead->prev;
	}
	
		
}
int main()
{
	sll s;
	for(int i=0;i<4;i++)
	{
		s.insert();
		
	}
	for(int i=0;i<3;i++)
	{
		s.insert_new();
	}
    s.addition();
	s.display();
}
