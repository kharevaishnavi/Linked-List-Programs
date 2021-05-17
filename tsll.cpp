/*Single linked list using templates
  Vaishnavi Khare-19545*/

#include <iostream>

using namespace std;

template<typename T>
class node
{
public:
    T data;
    node<T> *next;
    node()
    {
        data=0;
        next=NULL;
    }
};

template<typename T>
class linked_list
{
private:
    node <T>*head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_Head(T n)                                      //Add at head
    {
        node<T> *tmp= new node<T>;
        tmp->data=n;

        if(head==NULL)
        {
            head=tmp;
            tail=tmp;
        }
        else
        {
            tmp->next=head;
            head=tmp;
        }
        
    }
    void add_Tail(T n)                                      //Add at tail
    {
        node<T> *tmp = new node<T>;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void display()                                       //Traverse and Display
    {
        node<T> *tmp;
        tmp = head;
        if(head==NULL)
        {
            cout<<"**Linked list is empty**"<<endl;
        }
        else
        {
            cout<<"List values are- ";
            while (tmp != NULL)
            {
                cout << tmp->data <<"->";
                tmp = tmp->next;
            }
        cout<<endl;
        }
       
    }
    bool boolSearch(T element)                           //Search the element
    {       
        node<T> *ptr=head;
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
    void deleteHead()                                 //Delete from head
    {            
	    if(head==NULL)
        { 
	        return;
        }
        else
        {
	        node<T> *ptr=head;	
	        head=head->next;
	        delete ptr;
        }
    }
    void deleteTail()                                 //Delete from tail
    {
        if(tail==NULL)
        {
            return;
        }
        else
        {
           node<T> *temp=head;
           while(temp->next!=tail)
           {
               temp=temp->next;
           }
           delete tail;
           tail=temp;
           tail->next=NULL;
        }
        
    }
    int count()                                       //Count total number of elements
    {                   
        int count=0;
        node<T> *ptr= head;
        while(ptr!=NULL)
        {
            ++count;
	        ptr=ptr->next;
        }
        return count;
    }	
    float average()                                      //Average of elements
    {            
	    int sum=0,count=0;
	    float average=0.0;
	    node<T> *ptr= head;
        while(ptr!=NULL)
	    {
	        sum=sum+ptr->data;	 
            ++count;
	        ptr=ptr->next;
	    }
	    average=sum/count;
        return average;
    }

    void reverse()                                       //Reverse the linked list
    {
       node<T> *curr;
       node<T> *prev;
       node<T> *nextnode;
       prev = NULL;
       curr=head;
       nextnode=head;
       curr=nextnode=head;
       while(nextnode!=NULL)
       {
           nextnode=nextnode->next;
           curr->next=prev;
           prev=curr;
           curr=nextnode;
       }
       head=prev;

    }

    void insertSort(T element)                            //Insert an element by sorting
    {
        node<T> *n=new node<T>;
        n->data=element;
        n->next=NULL;
        node<T> *p=head;
        node<T> *q=NULL;
        if (head==NULL)
        {
            head=n;
            tail=n;
        }
        else
        {
            while((p!=NULL) && (p->data<element))
            {
                q=p;
                p=p->next;
            }
            if (p==head)
            {
                n->next=head;
                head=n;
            }
            else
            {
                if(p==NULL)
                {
                    q->next=n;
                    tail=n;
                }
                else
                {
                    n->next=q->next;
                    q->next=n;
                }
               
            }
            
        }
        
    }

    void deleteAfterPos(int pos)                        //Delete after a position
    {
        int index=0;
        node<T> *p=head;
        node<T> *q=NULL;
        while(p!=NULL)
        {
            ++index;
            if(index==(pos+1))
            break;
            q=p;
            p=p->next;
        }
        if (p->next==NULL)
        {
            delete p;
            tail=q;
            tail->next=NULL;
        }
        else
        {
            q->next=p->next;
            delete p;
            return;
        }

         
    }

     void deleteBeforePos(int pos)                        //Delete before a position
    {
        int index=0;
        node<T> *p=head;

        node<T> *q=NULL;
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
            delete p;
        }
        else
        {
            q->next=p->next;
            delete p;
            return;

        }
    }

    void insertAfterPos(int pos,T value)                    //Insert after a specific position
    {
        node<T> *temp=head;
        int index=0;
        while(temp!=NULL)
        {
            index=index+1 ;
            if(index==pos)
            break;
            temp=temp->next;
        }
        node<T> *n= new node<T>;
        n->data=value;
        n->next=temp->next;
        temp->next=n;
        if(n->next==NULL)
        {
            tail=n;
        }

    }


     void insertBeforePos(int pos,T value)                    //Insert before a specific position
    {
        node<T> *temp=head;
        int index=0;
        node<T> *n= new node<T>;
        n->data=value;
        if(pos==1)
        {
            n->next=head;
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
        temp->next=n;
        }
        
        
    }
      
    int temp(T data1)
    {
        int option;
        int pos;

   do
   {
       cout<<endl;
       cout<<" SINGLY LINKED LIST"<<endl;
       cout<<endl<<"Enter option or 0 to exit"<<endl;
       cout<<"1. Add element at the start of the node(prepend)"<<endl;
       cout<<"2. Add element at the end of the node(append)"<<endl;
       cout<<"3. Seach if the data is present (TRUE/FALSE)"<<endl;
       cout<<"4. Delete from head"<<endl;
       cout<<"5. Delete from tail"<<endl;
       cout<<"6. Count the elements in the list."<<endl;
       cout<<"7. Average of the elements in list"<<endl;
       cout<<"8. Insert a node after a position"<<endl;
       cout<<"9. Insert a node before a position"<<endl;
       cout<<"10.Reverse the list"<<endl;
       cout<<"11.Insert an element by sorting"<<endl;
       cout<<"12.Delete after a position"<<endl;
       cout<<"13.Delete before a postion"<<endl;
       cout<<"14. Display the list"<<endl;
       cout<<endl<<"Enter your choice-";
       cin>>option;
       cout<<endl;
       switch(option)
       {
 
           case 1:	 
           cout<<"Enter the element of the node to be added first- ";
           cin>>data1;
           add_Head(data1);
           cout<<"**Added at head**"<<endl;
           break;
 
           case 2:	 
           cout<<"Enter the element of the node to be added at the end- ";
           cin>>data1;
           add_Tail(data1);
           cout<<"**Added at tail**"<<endl;
           break;
 
           case 3:
           {cout<<"Enter the element you wish to find is present or not- ";
           cin>>data1;
           int val=boolSearch(data1);
           if(val==1)
           {
              cout<<"**True**"<<endl;
           }
           else
           {
              cout<<"**False**"<<endl;
           }
           }	 
           break;
 
           case 4:
           deleteHead();
           cout<<"**Deleted**"<<endl;
           break;

           case 5:
           deleteTail();
           cout<<"**Deleted**"<<endl;
           break;
 
           case 6:
           cout<<"Total elements : "<<count()<<endl;
           break;
 
           case 7:
           cout<<"**Average of the elements in list is "<<average()<<"**"<<endl;
           break;

           case 8:
           cout<<"Enter the position after which you wish to add element-";
           cin>>pos;
           cout<<endl<<"Enter the element-";
           cin>>data1;
           insertAfterPos(pos,data1);
           cout<<endl<<"**Done**"<<endl;
           break;
          
           case 9:
           cout<<"Enter the position before which you wish to add element-";
           cin>>pos;
           cout<<endl<<"Enter the element-";
           cin>>data1;
           insertBeforePos(pos,data1);
           cout<<endl<<"**Done**"<<endl;
           break;
 
           case 10:
           reverse();
           cout<<"**Reversed**"<<endl;
           break;

           case 11:
           cout<<"Enter the element-";
           cin>>data1;
           insertSort(data1);
           cout<<endl<<"**Inserted**"<<endl;
           break;

           case 12:
           cout<<"Enter the position-";
           cin>>pos;
           deleteAfterPos(pos);
           cout<<endl<<"**Deleted**"<<endl;
           break;

           case 13:
           cout<<"Enter the position-";
           cin>>pos;
           deleteBeforePos(pos);
           cout<<endl<<"**Deleted**"<<endl;
           break;

           case 14: 
           display();
           break;
 
           default: break;
        }
    }while(option!=0);
 return 0;
    }

};

int main()
{
    int type;
    cout<<"Enter your choice- 1 for Integers and 2 for character"<<endl;
    cin>>type;
    if(type==1)
    {
        int data1;  
        linked_list<int> a;
        a.temp(data1);
    }
    else if(type==2)
    {
        char data1;
        linked_list<char> a;
        a.temp(data1);
    }
    else
    {
        cout<<"Wrong input"<<endl;
    }
    return 0;
}
