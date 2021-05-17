/* Circular double linked list using templates
   Vaishnavi Khare-19545*/
#include<iostream>
using namespace std;

template<typename T>
class NodeCDLL
{
    public:
    NodeCDLL<T> *next;
    NodeCDLL<T> *prev;
    T info;
    NodeCDLL()
    {
        info=0;
        next=NULL;
        prev=NULL;
    }

    NodeCDLL(T element)
    {
        info=element;
        next=this;
        prev=this;
    }
};
template<typename T>
class CDLL
{
    NodeCDLL<T> *tail;
    
    public:
    CDLL()
    {
        tail=NULL;
    }    

    void insert_Head(T element)                                 //insert at head
    {
        NodeCDLL<T> *n=new NodeCDLL<T>(element);
        if(tail==NULL)
        {
            tail=n;
            tail->next=n;
            tail->prev=n;
        }
        else
        {
            tail->next->prev=n;
            n->next=tail->next;
            n->prev=tail;
            tail->next=n;
        }
    }

    void insert_Tail(T element)                              //insert at tail
    {
        NodeCDLL<T> *n=new NodeCDLL<T>(element);
        if(tail==NULL)
        {
            tail=n;
            tail->next=n;
            tail->prev=n;
        }
        else
        {
            NodeCDLL<T> *temp=tail->next;
            tail->next=n;
            n->prev=tail;
            tail=n;
            tail->next=temp;
            temp->prev=tail;
        }
    }

    bool Search(T element)                                //search the element
    {
        NodeCDLL<T> *temp;
        temp=tail->next;
        do
        {
           if(temp->info==element)
           {
               return true;
               break;
           }
           temp=temp->next;
        } while (temp!=tail->next);
        return false;
    }

    void  del_Head()                                        //delete from head
    {
        if(tail==NULL)
        return;
        else if(tail==tail->next)
        delete(tail);
        else
        {
            NodeCDLL<T> *temp;
            temp=tail->next;
            tail->next=temp->next;
            tail->next->prev=tail;
            delete(temp);
        }
    } 

    void del_Tail()                                          //delete from tail
    {
        if(tail==NULL)
        return;
        else if(tail==tail->next)
        delete(tail);
        else
        {
             NodeCDLL<T> *temp;
             temp=tail->next;
             tail->prev->next=temp;
             temp->prev=tail->prev;
             tail=temp->prev;
             delete temp;
        }
    }

    int count()                                                //Count the number of elements
    {
        NodeCDLL<T> *temp;
        temp=tail->next;
        int count=0;
        do
        {
            ++count;
            temp=temp->next;
        }while(temp!=tail->next);
        return count;
    }

    void deleteAfterPos(int pos)                            //Delete after a postion
    {
        NodeCDLL<T> *p=tail->next;
        NodeCDLL<T> *q=NULL;
        int index=0;
        do
        {
            ++index;
            if(index==(pos+1))
            break;
            q=p;
            p=p->next;
        } while (p!=tail->next);
        if(p==tail)
        {
            NodeCDLL<T> *temp;
            temp=tail->next;
            tail->prev->next=temp;
            temp->prev=tail->prev;
            tail=temp->prev;
            delete temp;
           // delete p;
        }
        else
        {
            q->next=p->next;
			q->next->prev=q;
			delete p;
        }
        return;
    }

     void deleteBeforePos(int pos)                            //Delete before a postion
    {
        NodeCDLL<T> *p=tail->next;
        NodeCDLL<T> *q=NULL;
        int index=0;
        do
        {
            ++index;
            if(index==(pos-1))
            break;
            q=p;
            p=p->next;
        } while (p!=tail->next);
        if(p==tail->next)
        {
            NodeCDLL<T> *temp;
            temp=tail->next;
            tail->next=temp->next;
            tail->next->prev=tail;
            delete(temp);
        }
        else
        {
            q->next=p->next;
			q->next->prev=q;
			delete p;
        }
        return;
    }
        

    void Traverse()                                        //Traverse and display
    {
        NodeCDLL<T> *temp;
        if(tail==NULL)
        {
            cout<<"Circular linked list is empty"<<endl;
        }
        else
        {
            temp=tail->next;
            cout<<"Circular double linked list-";
            do
            {
                cout<<temp->info<<" -> ";
                temp=temp->next;
            }while(temp!=tail->next);
            if(temp==tail->next)
            {
                cout<<"(head node)";
            }
        }
        cout<<endl;
    }
    void menu(T data)
    {
    int option;
    int pos;
    do
    {
        cout<<endl<<"Circular Double Linked List Operations"<<endl;
        cout<<endl<<"Select any one-"<<endl;
        cout<<"1.Insert element at head"<<endl;
        cout<<"2.Insert element at tail"<<endl;
        cout<<"3.Search the element"<<endl;
        cout<<"4.Delete from head"<<endl;
        cout<<"5.Delete from tail"<<endl;
        cout<<"6.Count the elemnts"<<endl;
        cout<<"7.Delete after a postion"<<endl;
        cout<<"8.Delete before a postion"<<endl;
        cout<<"9.Display"<<endl;
        cout<<"10.Exit"<<endl;
        cout<<"Your choice- "; 
        cin>>option;
        switch(option)
        {
            case 1: cout<<"Enter the element- ";
                    cin>>data;
                    insert_Head(data);
                    cout<<endl<<"**Done**"<<endl;
                    break;

            case 2: cout<<"Enter the element- ";
                    cin>>data;
                    insert_Tail(data);
                    cout<<endl<<"**Done**"<<endl;
                    break; 

            case 3: {cout<<"Enter the element to be searched-";
                    cin>>data; 
                    int val=Search(data);
                    if (val==1)
                    cout<<endl<<"**Found**"<<endl;
                    else
                    cout<<endl<<"**Not found**"<<endl;
                    break;}

            case 4: del_Head();
                    cout<<endl<<"**Deleted**"<<endl;
                    break;

            case 5: del_Tail();
                    cout<<endl<<"**Deleted**"<<endl;
                    break;

            case 6: cout<<endl<<"**Total number of elements - "<<count()<<"**"<<endl;   
                    break;

            case 7: cout<<"Enter the position-" ;
                    cin>>pos;
                    deleteAfterPos(pos);
                    cout<<endl<<"**Deleted**"<<endl;  
                    break;   
           
           case 8: cout<<"Enter the position-" ;
                    cin>>pos;
                    deleteBeforePos(pos);
                    cout<<endl<<"**Deleted**"<<endl;  
                    break;   
           
            case 9: Traverse();
                    break;

                    

            default: break;               
        }


    }while(option!=10);
  return ;

}};

int main()
{
 int type;
    cout<<"Enter your choice-"<<endl; 
    cout<<"1. Integers"<<endl;
    cout<<"2. Character"<<endl;
    cout<<"Your choice-"<<endl;
    cin>>type;
    if(type==1)
    {
        int data1;  
        CDLL<int> a;
        a.menu(data1);
    }
    else if(type==2)
    {
        char data1;
        CDLL<char> a;
        a.menu(data1);
    }
    else
    {
        cout<<"Wrong input"<<endl;
    }
    return 0;
}
