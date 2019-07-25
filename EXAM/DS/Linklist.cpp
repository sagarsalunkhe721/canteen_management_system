#include<iostream>
using namespace std;

class Node{
        int data;
        Node *next;

        public:
                Node(){}
                Node(int data){
                        this->data=data;
                        next=NULL;
                }

                int getData(){
                        return this->data;
                }

                void setData(int data){
                        this->data=data;
                }

                Node * getNext(){
                        return this->next;
                }

                void setNext(Node *next){
                        this->next=next;
                }

                void print(){
                        cout<<this->data<<" ";
                }
};

class Linklist{
        Node *head;
        public:
                Linklist(){
                        head=NULL;
                }
		
		//----------------------------------------------------------------
		
                void insertAtEnd(int data){
                        Node *newNode=new Node(data);
                        if(head==NULL){
                                head=newNode;
                        }else{
                                Node *temp=head;
                                while(temp->getNext()!=NULL){
                                        temp=temp->getNext();
                                }
                                temp->setNext(newNode);
                        }
                }

			//----------------------------------------------------------------
				
                void insertAtBegin(int data){
                        Node *newNode=new Node(data);
                        if(head==NULL){
                                head=newNode;
                        }else{
                                newNode->setNext(head);
                                head=newNode;
                        }
                }

				//----------------------------------------------------------------
				
                void insertBeforeNode(int before,int data){
                        Node *newNode=new Node(data);
                        if(head==NULL){
                                head=newNode;
                        }else{
                                Node *temp=head;
                                while(temp->getNext()!=NULL){
                                        if(temp->getNext()->getData()==before){
                                                break;
                                        }
                                        temp=temp->getNext();
                                }
                                newNode->setNext(temp->getNext());
                                temp->setNext(newNode);
                        }
                }

				//----------------------------------------------------------------
				
                void insertAfterNode(int after,int data){
                        Node *newNode=new Node(data);
                        if(head==NULL){
                                head=newNode;
                        }else{
                                Node *temp=head;
                                while(temp->getNext()!=NULL){
                                        if(temp->getData()==after){
                                                break;
                                        }
                                        temp=temp->getNext();
                                }
                                newNode->setNext(temp->getNext());
                                temp->setNext(newNode);
                        }
                }

				//----------------------------------------------------------------
				
                void deleteAtEnd(){
                        Node *temp=head;
                        if(temp->getNext()==NULL){
                                delete(temp);
                                head=NULL;
                        }else{
                                Node *prev;
                                while(temp->getNext()!=NULL){
                                        prev=temp;
                                        temp=temp->getNext();
                                }
                                delete(temp);
                                prev->setNext(NULL);
                        }
                }

				//----------------------------------------------------------------
				
                void deleteAtBegin(){
                        Node *temp=head;
                        if(temp->getNext()==NULL){
                                delete(temp);
                                head=NULL;
                        }else{
                                head=temp->getNext();
                                temp=NULL;
                                delete(temp);
                        }
                }

				//----------------------------------------------------------------
				
                void deleteBeforeNode(int place){
                        Node *temp=head;
                        Node *prev;
                        while(temp!=NULL){
                                if(temp->getNext()!=NULL){
                                        if(temp->getNext()->getData()==place){
                                                break;
                                        }
                                        prev=temp;
                                        temp=temp->getNext();
                                }
                        }
                        if(prev!=NULL && temp!=NULL){
                                prev->setNext(temp->getNext());
                        }
                        temp=NULL;
                        delete(temp);

                }
				
				//----------------------------------------------------------------
				
                void deleteAfterNode(int place){
                        Node *temp=head;
                        Node *prev;
                        if(temp->getNext()==NULL && prev==NULL){
                                delete(temp);
                                head=NULL;
                                return;
                        }else{
                                while(temp!=NULL){
                                        prev=temp;
                                        if(temp->getData()==place){
                                                prev=temp;
                                                temp=temp->getNext();
                                                prev->setNext(temp->getNext());
                                                break;
                                        }
                                        temp=temp->getNext();
                                }
                                delete(temp);
                        }
                }

			//----------------------------------------------------------------

                void print(){
                        Node *temp=head;
                        while(temp!=NULL){
                                temp->print();
                                temp=temp->getNext();
                        }
                        cout<<endl;
                }

};

//----------------------------------------------------------------

void list(){
        cout<<"1. Insert At End: "<<endl;
        cout<<"2. Insert At Begin: "<<endl;
        cout<<"3. Insert Before Some Node: "<<endl;
        cout<<"4. Insert After Some Node: "<<endl;
        cout<<"5. Delete At End: "<<endl;
        cout<<"6. Delete At Begin: "<<endl;
        cout<<"7. Delete Before Node: "<<endl;
        cout<<"8. Delete After Node: "<<endl;
        cout<<"p. Print:"<<endl;
        cout<<"q. Quit: "<<endl;
}

//----------------------------------------------------------------

int main(){
        Linklist l1;
        char cmd;
        int data;
        int place;

        while(1){
                cin>>cmd;
                if(cmd== '1'){
                        cin>>data;
                        l1.insertAtEnd(data);
                }else if(cmd== '2'){
                        cin>>data;
                        l1.insertAtBegin(data);
                }else if(cmd== '3'){
                        cin>>place;
                        cin>>data;
                        l1.insertBeforeNode(place,data);
                }else if(cmd== '4'){
                        cin>>place;
                        cin>>data;
                        l1.insertAfterNode(place,data);
                }else if(cmd=='5'){
                        l1.deleteAtEnd();
                }else if(cmd=='6'){
                        l1.deleteAtBegin();
                }else if(cmd=='7'){
                        cin>>place;
                        l1.deleteBeforeNode(place);
                }else if(cmd=='8'){
                        cin>>place;
                        l1.deleteAfterNode(place);
                }else if(cmd=='p'){
                        l1.print();
                }else if(cmd=='q'){
                        break;
                }else if(cmd=='l'){
                        list();
                }
        }
return 0;
}
