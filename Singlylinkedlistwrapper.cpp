#include<iostream>
#include<stdlib.h>
using namespace std;

namespace TadeebDS
{
class SinglyLinkedList
{
private:
class Node
{
private:
Node *next;
int num;
Node(int num)
{
this->num=num;
this->next=NULL;
}
friend class SinglyLinkedList;
};
Node *top, *bottom;
int size;

public:

SinglyLinkedList()
{
this->top = NULL;
this->bottom = NULL;
this->size=0;
}

SinglyLinkedList(const SinglyLinkedList &other)
{
this->top = NULL;
this->bottom = NULL;
this->size=0;
Node *t;
t=other.top;
for(int x=0; x<other.size; x++)
{
this->add(t->num);
t=t->next;
}
}

SinglyLinkedList(SinglyLinkedList &&other)
{
this->top=other.top;
this->bottom=other.bottom;
this->size= other.size;

other.top=NULL;
other.bottom=NULL;
other.size=0;
}

~SinglyLinkedList()
{
cout<<"Object is about to die !!! "<<endl;
this->clearAll();
}

void add(int num)
{
Node *t;
t=new Node(num);
if(this->top==NULL && this->bottom == NULL) 
{
this->top=t;
this->bottom=t;
}
else
{
bottom->next=t;
bottom=t;
}
this->size++;
}

void insertAtTop(int num)
{
this->insertAt(0,num);

/*
Node *t;
t=new Node(num);
t->next=this->top;
this->top=t;
this->size++;
*/
}

void insertAt(int pos, int num)
{
if(pos<0) pos=0;
if(pos>this->size) 
{
this->add(num);
return;
}

if(pos==0)
{
Node *t;
t=new Node(num);
t->next=this->top;
this->top=t;
this->size++;
return;
}

Node *p1, *p2;
int x;
x=0;
p1=this->top;
while(x<pos && p1!=NULL)
{
p2=p1;
p1=p1->next;
x++;
}
Node *t;
t= new Node(num);
t->next = p1;
p2->next=t;
this->size++;
}

int get(int index)
{
int x;
Node *t;
t=this->top;
for(x=0; x<index ;x++,t=t->next);
return t->num; 
}

int getSize()
{
return this->size;
}


void removeAt(int index)
{
Node *p1, *p2;

if(index<0 || index>this->size) return;

if(this->top==NULL)
{
cout<<"No nodes in the list"<<endl;
return;
}

if(this->size == 1)
{
delete this->top;
this->top=NULL;
this->bottom=NULL;
this->size=0;
return;
}

p1=this->top;


int x;
x=0;
while(x<index)
{
p2=p1;
p1=p1->next;
x++;
}
if(p1==this->top)
{
this->top = this->top->next;
delete p1;
this->size--;
return;
}
if(p1==this->bottom)
{
p2->next=NULL;
delete p1;
this->size--;
this->bottom=p2;
return;
}
p2->next=p1->next;
delete p1;
this->size--;
}

void clearAll()
{
/*
for(int x=0;x<this->size;x++)
{
removeAt(x);
}
*/
Node *t;
t=this->top;
if(t==NULL) cout<<"Already Empty"<<endl;
while(this->top!=NULL)
{
t=this->top;
this->top=this->top->next;
delete t;
this->size--;
}
this->bottom = NULL;
}

};
};


using namespace TadeebDS;
int main()
{
int ch, num, pos;
SinglyLinkedList list1;
//SinglyLinkedList list2(list1);  //Don't create object here because constructor runs only once in their lifecycle.

while(1)
{
cout<<"_________________________________"<<endl;
cout<<"1. Add at end"<<endl;
cout<<"2. Insert at top"<<endl;
cout<<"3. Add at Position"<<endl;
cout<<"4. Remove a node"<<endl;
cout<<"5. Print all Nodes"<<endl;
cout<<"6. Clear all Nodes"<<endl;
cout<<"7. Exit"<<endl<<endl;

cout<<"Enter your choice: ";
cin>>ch;

cout<<endl;
if(ch==1)
{
cout<<"Enter the number to add: ";
cin>>num;
list1.add(num);
}
else if(ch==2)
{
cout<<"Enter the number to insert(at top): ";
cin>>num;
list1.insertAtTop(num);
}
else if(ch==3)
{
cout<<"Enter the number: ";
cin>>num;
cout<<"Enter the position to enter: ";
cin>>pos;
list1.insertAt(pos,num);
}
else if(ch==4)
{
cout<<"Enter the Place of Node to remove: ";
cin>>num;
list1.removeAt(num);
}
else if(ch==5)
{
 int x, ask;
 cout<<"Which list you wanna see 1 or 2 or 3: ";
 cin>>ask;

 if(ask==1)
 {
 if(list1.getSize() == 0) cout<<"No Nodes in the List 1"<<endl;
 for(x=0; x<list1.getSize(); x++)
 {
 cout<<list1.get(x)<<endl;
 }
 }
 else if(ask==2)
 {
 SinglyLinkedList list2(list1);
 if(list2.getSize() == 0) cout<<"No Nodes in the List 2"<<endl;
 for(x=0; x<list2.getSize(); x++)
 {
 cout<<list2.get(x)<<endl;
 }
 }
 else if(ask==3)
 {
 SinglyLinkedList list3(std::move(list1));
 if(list3.getSize() == 0) cout<<"No Nodes in the List 3"<<endl;
 for(x=0; x<list3.getSize(); x++)
 {
 cout<<list3.get(x)<<endl;
 }

 }
 else cout<<"Invalid list selection"<<endl;
}
else if(ch==6)
{
list1.clearAll();
}
else if(ch==7)
{
cout<<"Program Exiting … "<<endl;
break;
}
else 
{
cout<<"Invalid Choice"<<endl;
}

}
return 0;
}
