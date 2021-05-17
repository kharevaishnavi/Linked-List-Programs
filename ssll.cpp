/*Sorted Single linked list
  Vaishnavi Khare-19545*/

#include<iostream>

using namespace std;

template<typename T>
class NodeSSLL
{
    public:
    T data;
    NodeSSLL<T> *next;

    NodeSSLL()
    {
        data=0;
        next=NULL;
    }

    NodeSSLL(T element)
    {
        data=element;
        next=NULL;
    }
};
 
 template<typename T>
 class SortedSLL
 {
     NodeSSLL<T> *head;
     NodeSSLL<T> *tail;

     public:
     SortedSLL()
     {
         head=NULL;
         tail=NULL;
     }
    
    void insertSort(T element)                            //Insert an element by sorting
    {
        NodeSSLL<T> *n=new NodeSSLL<T>(element);
        NodeSSLL<T> *p=head;
        NodeSSLL<T> *q=NULL;
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
    int delete_element(T element)                         //Delete an element
    {
        NodeSSLL<T> *p=head;
        NodeSSLL<T> *q=NULL;
        while((p!=NULL) && (p->data<element))
        {
            q=p;
            p=p->next;
        }
        if(p->data!=element)
        {
           return -1;
        }
        else
        {
        if(p==head)
        {
            head=head->next;
            delete p;
        }
        else
        {
            if(p==tail)
            {
                delete p;
                tail=q;
                tail->next=NULL;
            }
            else
            {
                q->next=p->next;
                delete p;
            }
        }
         return 0;
        }
    }
      bool search(T element)                             //Search an element
    {
        NodeSSLL<T> *p=head;
        while((p!=NULL) && (p->data<element))
        {
            p=p->next;
        }
        if(p->data==element)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void display()                                       //Traverse and Display
    {
        NodeSSLL<T> *tmp;
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
            if(tmp==NULL)
            {
                cout<<"NULL";
            }
        cout<<endl;
        }
       
    }
    void menu(T element)                                   //menu
    {
        int option;
        do
        {
        cout<<endl<<"Sorted Single Linked List"<<endl;
        cout<<endl<<"Enter your choice:"<<endl;
        cout<<"1.Insert in sorted list"<<endl;
        cout<<"2.Delete an element"<<endl;
        cout<<"3.Search the element"<<endl;
        cout<<"4.Display"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Your choice-";
        cin>>option;
        switch(option)
        {
            case 1: cout<<"Enter the element-";
                    cin>>element;
                    insertSort(element);
                    cout<<endl<<"**Inserted**"<<endl;
                    break;

            case 2: {cout<<"Enter the element to be deleted-";
                    cin>>element;
                    int val=delete_element(element);
                    if (val==-1)
                    cout<<endl<<"**No such element in the list**"<<endl;
                    else
                    cout<<endl<<"**Deleted**"<<endl;
                    break;}

            case 3: {cout<<"Enter the element to be searched-";
                    cin>>element; 
                    int val=search(element);
                    if (val==1)
                    cout<<endl<<"**Found**"<<endl;
                    else
                    cout<<endl<<"**Not Found**"<<endl;
                    break;}      

            case 4: display();
                    break;

            default: break;                
        }
        }while(option!=5);
        return;
    }
 };

 int main()
 {
    int type;
    cout<<endl<<"Enter your choice-"<<endl; 
    cout<<endl<<"1. Integers"<<endl;
    cout<<"2. Character"<<endl;
    cout<<"Your choice-"<<endl;
    cin>>type;
    if(type==1)
    {
        int data1;  
        SortedSLL<int> a;
        a.menu(data1);
    }
    else if(type==2)
    {
        char data1;
        SortedSLL<char> a;
        a.menu(data1);
    }
    else
    {
        cout<<"Wrong input"<<endl;
    }
    return 0;
}

 