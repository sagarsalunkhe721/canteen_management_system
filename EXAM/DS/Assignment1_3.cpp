#include<iostream>
using namespace std;

class Node
{

        int data;
        Node *next;
        public:
                Node()
                {

                }

                Node(int data)
                {
                        this->data=data;
                        this->next=NULL;
                }

                void setData(int data)
                {
                        this->data=data;
                }

                int getData()
                {
                        return this->data;
                }

                void setNext(Node *next)
                {
                        this->next=next;
                }

                Node * getNext()
                {
                        return this->next;
                }
};

class Linklist
{
        Node *head;

        public:
                        Linklist()
                        {
                                head=NULL;
                        }

        void addLast(int data)
        {
                Node*newNode=new Node(data);
                Node *temp=head;

                if(head==NULL)
                {
                        head=newNode;
                }
                else
                {
                        while(temp->getNext()!=NULL)
                        {
                                temp=temp->getNext();
                        }
                        temp->setNext(newNode);
                }
        }

        void Checker(int size)
        {
                int index1,index2, arr[size],arr1[size],count;

                Node *temp=head;
                while(temp!=NULL)
                {
                        for(index1=0;index1<size;index1++)
                        {
                                arr[index1]=temp->getData();
                                temp=temp->getNext();           
                        }
                }

                index1=index1-1;
                for(index2=0;index2<size;index2++,index1--)
                {
                        arr1[index2]=arr[index1];
                }

                for(index1=0;index1<size;index1++)
                {
                        if(arr[index1]==arr1[index1])
                        {
                                count++;
                        }
                }


                if(count==size)
                {
                        cout<<"String Is Palindrome"<<endl;
                }
                else
                {
                        cout<<"String Is Not Palindrome"<<endl;
                }


        }
};

int main()
{
int noOfTestCases,index1,index2,size,element;
cout<<"Enter Number Of Test Cases:\n";
cin>>noOfTestCases;

Linklist l1[noOfTestCases];


        for(index1=0 ; index1<noOfTestCases ; index1++)         //to iterate all operations till user entered number
        {
                cout<<index1+1<<" TestCase: "<<endl;
                cout<<"Enter Size Of Linked List: "<<endl;
                cin>>size;

                for(index2=0; index2<size ;index2++)            //index2 for adding elements to linked list till size
                {
                        cout<<index2+1<<" Element: ";
                        cin>>element;
                        l1[index1].addLast(element);
                }

                l1[index1].Checker(size);
        }

return 0;
} 