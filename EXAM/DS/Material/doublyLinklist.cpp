#include<iostream>
using namespace std;

class Node{
	int data;
	Node *next;
	Node *prev;

	public:
	
	Node(){}

	Node(int data){
		this->data=data;
		next=NULL;
		prev=NULL;
	}

	int getData(){
		return this->data;
	}
	
	void setData( int data ){
		this->data=data;
	}

	Node * getNext(){
		return this->next;
	}

	Node * getPrev(){
		return this->prev;
	}

	void setNext( Node *node ){
		next=node;
	}

	void setPrev( Node *node ){
		prev=node;
	}

	void print(){
		cout<<this->data;
	}
};

class DoublyLinkList{
	Node *head;
	public:
	DoublyLinkList(){
		head=NULL;
	}

	void InsertAtEnd(int data){
		Node *newNode=new Node(data);
		if( head == NULL ){
			head=newNode;
		}else{
			Node *temp = head;
			while( temp->getNext() != NULL ){
				temp=temp->getNext();
			}
			newNode->setPrev( temp );
			temp->setNext( newNode );
		}
	}

	void InsertAtBegin( int data ){
		Node *newNode = new Node(data);
		if( head == NULL ){
			head = newNode;
		}else{
			head->setPrev(newNode);
			newNode->setNext(head);
			head=newNode;
		}
	}

	void InsertAfter( int data , int After ){
		Node *newNode = new Node( data );
		if( head == NULL ){
			cout<<"There Is No Node "<<After<<" Present In The LinkList "<<endl;
		}else{
			Node *temp=head;
			while(temp->getNext()!=NULL){
				if(temp->getData() == After){
					break;
				}
				temp=temp->getNext();
			}
			newNode->setNext(temp->getNext());
			temp->getNext()->setPrev(newNode);

			temp->setNext(newNode);
			newNode->setPrev(temp);
		}
	}

	void insertBefore( int data, int before ){
		Node *newNode = new Node(data);

		if( head == NULL ){
			cout<<"There Is No Node "<<before<<" Present In The LinkList "<<endl;
		}else{
			Node *temp = head;
			while( temp->getNext() != NULL ){
				if( temp->getNext()->getData() == before ){
					break;
				}
				temp=temp->getNext();
			}
			temp->getNext()->setPrev(newNode);
			newNode->setNext(temp->getNext());

			temp->setNext(newNode);
			newNode->setPrev(temp);
		}
	}

	void deleteEnd(){
		Node *temp=head;
		if(head->getNext()==NULL){
			head=NULL;
			delete(head);
		}else{
			while( temp->getNext()!=NULL ){
				temp = temp->getNext();
			}
			temp->getPrev()->setNext(NULL);
			temp=NULL;
			delete(temp);
		}
	}

	void deleteBegin(){
			Node *temp = head;
			if(head->getNext() == NULL){
				head = NULL;
				delete(head);
			}else{
				head=temp->getNext();
				temp->getNext()->setPrev(NULL);
				temp=NULL;
				delete(temp);
			}
	}

	void deleteAfter( int After ){
		if( head->getNext() == NULL ){
			cout<<"There Is No Node After "<<After<<", Its Head!"<<endl;
		}else{
			Node *temp=head;
			while(temp->getNext()!=NULL){
				if( temp->getData() == After )
					break;
				temp=temp->getNext();
			}
			temp = temp->getNext();
			
			if(temp->getNext()!=NULL){
				temp->getPrev()->setNext(temp->getNext());
				temp->getNext()->setPrev(temp->getPrev());
				temp=NULL;
				delete(temp);
			}else{
				temp->getPrev()->setNext(NULL);
				temp=NULL;
				delete(temp);
			}
		}
	}

	void deleteBefore( int before ){
		Node *temp=head;
		if( head->getNext() == NULL ){
			cout<<"There Is No Node After "<<before<<", Its Head!"<<endl;
		}else{
			while(temp->getNext()!=NULL){
				if( temp->getNext()->getData() == before )
					break;
				temp=temp->getNext();
			}
			if(temp->getPrev() == NULL){
				head=temp->getNext();
				temp=NULL;
				delete( temp );
			}else{
				temp->getPrev()->setNext(temp->getNext());
				temp->getNext()->setPrev(temp->getPrev());
				temp=NULL;
				delete(temp);
			}
		}
	}

	void print(){
		Node *temp = head;
		while(temp!=NULL){
			temp->print();
			if(temp->getNext()!=NULL)
				cout<<"->";
			temp = temp->getNext();
		}
		cout<<endl;
	}	
};

void list(){
	cout<<"i. Insert Into Doubly Linklist At Last"<<endl;
	cout<<"b. Insert Into Doubly Linklist At Begin"<<endl;
	cout<<"a. Insert Into Doubly Linklist After Some Element ( data, after )"<<endl;
	cout<<"s. Insert Into Doubly Linklist Before Some Element ( data, after )"<<endl;
	cout<<"d. Delete Last Node Of Linklist"<<endl;
	cout<<"f. Delete Start Node Of Linklist"<<endl;
	cout<<"g. Delete Node After A Node In Linklist ( After )"<<endl;
	cout<<"h. Delete Node Before A Node In Linklist ( Before )"<<endl;
	cout<<"p. Print The Link List "<<endl;
	cout<<"q. Quit"<<endl;
	cout<<"Enter The Choice"<<endl;
}

int main(){
	DoublyLinkList dl;
	char choice;
	int data;
	int pos;
	
	while(1){
		cin>>choice;
		if( choice == 'l' ){
			list();
		}else if( choice == 'i' ){
			cin>>data;
			dl.InsertAtEnd(data);
		}else if( choice == 'b' ){
			cin>>data;
			dl.InsertAtBegin(data);
		}else if( choice == 'p' ){
			dl.print();
		}else if( choice == 'a' ){
			cin>>data;
			cin>>pos;
			dl.InsertAfter( data, pos );
		}else if( choice == 's' ){
			cin>>data;
			cin>>pos;
			dl.insertBefore( data, pos );
		}else if( choice == 'd' ){
			dl.deleteEnd();
		}else if( choice == 'f' ){
			dl.deleteBegin();
		}else if( choice == 'g' ){
			cin>>pos;
			dl.deleteAfter( pos );
		}else if( choice == 'h' ){
			cin>>pos;
			dl.deleteBefore( pos );
		}else if( choice == 'q' ){
			break;
		}
	}

return 0;
}
