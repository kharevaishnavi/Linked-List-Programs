/*Double linked list using templates
 Vaishnavi Khare-19545*/

#include<iostream>

using namespace std;

template<typename T>
class Node
{
public:
  T data;
  Node<T> *prev;
  Node<T> *next;
  Node()
  {
     data=0;
     prev=NULL;
     next=NULL;
  }
  Node(T d)
  {
     data=d;
     prev=NULL;
     next=NULL;
   }
};

template<typename T>
class DoubleLinkedList
{
public:	
  Node<T> *head;
  Node<T> *tail;
  DoubleLinkedList()
  {
	 head=NULL;
     tail=NULL;
  }
  void insertHead(T element)                                //insert element at head
  {
     Node<T> *temp=new Node<T>(element);
     if(head==NULL)
     {
         head=temp;
         tail=temp;   
     }
     else
     {
         head->prev=temp;
         temp->next=head;
         head=temp;
     }
  }
  
  void insertTail(T element)                                //insert element at tail
  {
     Node<T> *temp=new Node<T>(element);
     if(head==NULL)
     {
         head=temp;
         tail=temp;   
     }
     else
     {
         tail->next=temp;
		 temp->prev=tail;
		 tail=temp;
     }
  }
  
  int del_Head()                                            //Delete head
  {
	 if(head==NULL)
	 {
		 return 0;
	 }
	 else if(head==tail)
	 {
		 delete (head);
		 head=NULL;
		 tail=NULL;
		 return 1;
	 }
	 else
	 {
		 Node<T> *temp=head;
		 head=head->next;
		 head->prev=NULL;
		 delete (temp);
		 return 1;
	 }
  }
  
  int del_Tail()                                            //Delete tail
  {
	  if(head==NULL)
	 {
		 return 0;
	 }
	 else if(head==tail)
	 {
		 delete (head);
		 head=NULL;
		 tail=NULL;
		 return 1;
	 }
	 else
	 {
		 Node<T> *temp=tail;
		 tail=tail->prev;
		 delete(temp);
		 tail->next=NULL;
		 return 1;
	 }
  }
  
  bool boolSearch(T element)                            //Seach the element
  {        
     Node<T> *ptr=head;
     int f=false;
     while(ptr!=NULL)
	 {
         if(ptr->data==element)
		 {
	         f=true;	
             return f;
             break;	
	     }
	 ptr=ptr->next;
     }
   
   return f;
  }

  void insertAfterPos(int pos,T element)                   //Insert after a position
  {
	  Node<T> *n=new Node<T>(element); 
	  Node<T> *temp=head;
	  int index=0;
	  while(temp!=NULL)
	  {
		  ++index;
		  if(index==pos)
		  break;
		  temp=temp->next;
	  }
	  if(temp->next==NULL)
	  {
		  temp->next=n;
		  n->prev=temp;
		  n->next=NULL;
		  tail=n;
	  }
	  else
	  {
		  n->next=temp->next;
		  (temp->next)->prev=n;
		  temp->next=n;
		  n->prev=temp;
	  }
	  return;

  }

  void insertBeforePos(int pos,T element)                    //Insert before a specific position
    {
        Node<T> *temp=head;
        int index=0;
        Node<T> *n=new Node<T>(element); 
        if(pos==1)
        {
            n->next=temp;
			temp->prev=n;
            head=n;
        }
        else
        {
            while(temp!=NULL)
            {
                index=index+1 ;
                if(index==pos-1)
                break;
                temp=temp->next;
            }
        
        n->next=temp->next;
		(temp->next)->prev=n;
		temp->next=n;
		n->prev=temp;
        }
		return;
    }

	void deleteAfterPos(int pos)                             //Delete after a specific postion
	{
		Node<T> *p=head;
		Node<T> *q=NULL;
		int index=0;
		while(p!=NULL)
		{
			++index;
			if(index==(pos+1))
			break;
			q=p;
			p=p->next;
		}
		if(p->next==NULL)
		{
			tail=tail->prev;
			delete p;
			tail->next=NULL;
		}
		else
		{
			q->next=p->next;
			q->next->prev=q;
			delete p;
		}
		return;
	}

	void deleteBeforePos(int pos)                             //Delete before a specific postion
	{
		Node<T> *p=head;
		Node<T> *q=NULL;
		int index=0;
		while(p!=NULL)
		{
			++index;
			if(index==(pos-1))
			break;
			q=p;
			p=p->next;
		}
		if(p==head)
		{
			head=head->next;
			head->prev=NULL;
			delete p;
		}
		else
		{
			q->next=p->next;
			q->next->prev=q;
			delete p;
		}
		return;
	}
  
  void traverseForward()                                        //Traverse forward
  {
     if(head==NULL)
	 {
         cout<<endl<<"No nodes in double linked list"<<endl;
	 }
     else 
	 {
         cout<<"Forward Traversal : ";
         Node<T> *temp=head;
         while(temp!=NULL)
		 {
             cout<<"("<<temp->data<<")-->";		
             temp=temp->next;
		 }
	 }
	 cout<<endl;
  }  
  
  void traverseBackward()                                        //Traverse backward
  {
     cout<<"Backward Traversal : ";
     Node<T> *temp=tail;
     while(temp!=NULL)
	 {
         cout<<"("<<temp->data<<")-->";		
         temp=temp->prev;
	 }
	 cout<<endl;
  }  
  
int menu(T data1)
{
 int pos;
 int choice;
 do
 {
	 cout<<endl;
	 cout<<"DOUBLE LINKED LIST"<<endl;
	 cout<<endl;
	 cout<<"Enter option :"<<endl;
	 cout<<endl;
	 cout<<"1.Insert at head"<<endl;
	 cout<<"2.Insert at tail"<<endl;
	 cout<<"3.Traverse forward"<<endl;
	 cout<<"4.Traverse backward"<<endl;
	 cout<<"5.Delete from head"<<endl;
	 cout<<"6.Delete from tail"<<endl;
	 cout<<"7.Search the element"<<endl;
	 cout<<"8.Insert element after a position"<<endl;
	 cout<<"9.Insert element before a position"<<endl;
	 cout<<"10.Delete after a postion"<<endl;
	 cout<<"11.Delete before a position"<<endl;
	 cout<<"12.Exit"<<endl;
	 cout<<"Choice-";
	 cin>>choice;
	 
	 switch(choice)
	 {
		 case 1: cout<<endl<<"Enter the element to be inserted at head-";
		         cin>>data1;
				 insertHead(data1);
				 cout<<endl<<"Inserted."<<endl;
				 break;
				 
	     case 2: cout<<endl<<"Enter the element to be inserted at tail-";
		         cin>>data1;
				 insertTail(data1);
				 cout<<endl<<"Inserted."<<endl;
				 break;			 
		 
		 case 3: traverseForward();
                 break;

         case 4: traverseBackward();
                 break;

         case 5: del_Head();
		         cout<<"Deleted."<<endl;
				 break;
		
		 case 6: del_Tail();
		         cout<<"Deleted"<<endl;
				 break;
				 
		 case 7:{
			     cout<<"Enter the element to be searched-"<<endl;	
                 cin>>data1;		
                 int val=boolSearch(data1);
				 if (val==1)
				 {
					cout<<endl<<"Found"<<endl;
				 }
				 else
				 {
					cout<<endl<<"Not found"<<endl;
				 }
		         }
				 break;

		case 8:cout<<"Enter the position-";
		       cin>>pos;
			   cout<<"Enter the element-";
			   cin>>data1;
			   insertAfterPos(pos,data1);
			   cout<<endl<<"Inserted"<<endl;
			   break;	 

		case 9:cout<<"Enter the position-";
		       cin>>pos;
			   cout<<"Enter the element-";
			   cin>>data1;
			   insertBeforePos(pos,data1);
			   cout<<endl<<"Inserted"<<endl;
			   break;

		case 10:cout<<"Enter the position-";
		        cin>>pos;
				deleteAfterPos(pos);
				cout<<endl<<"Deleted"<<endl;
				break;	 

		case 11:cout<<"Enter the position-";
		        cin>>pos;
				deleteBeforePos(pos);
				cout<<endl<<"Deleted"<<endl;
				break;	 		  	 	   				
                				
         default: break;	
	 }
 }while(choice!=12);	 
 return 0;
}
};

int main()
{
	int ch;
	cout<<"Enter your choice-"<<endl;
	cout<<"1.Interger"<<endl;
	cout<<"2.Characters"<<endl;
	cout<<"Your choice-";
	cin>>ch;
	if(ch==1)
	{
		int data1;
		DoubleLinkedList<int> a;
		a.menu(data1);
	}
	else if(ch==2)
	{
		char data1;
		DoubleLinkedList<char> a;
		a.menu(data1);
	}
	else
	{
		cout<<"Wrong input";
	}
	return 0;
}