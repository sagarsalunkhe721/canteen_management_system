#include<iostream>
using namespace std;

class Node{
	int data;
	Node *next;

	public:
	Node(){}
	Node( int data ){
		this->data=data;
		this->next=NULL;
	}
		
	int getData(){
		return this->data;
	}

	void setData( int data ){
		this->data=data;
	}

	Node *getNext(){
		return next;
	}

	void setNext( Node * next ){
		this->next=next;
	}

	void print(){
		cout<<this->data;
	}

};

class cLinklist{
	Node *head;
	
	public:

	cLinklist(){
		head=NULL;
	}	

	void insertEnd( int data ){
		Node *newNode=new Node( data );
		if(head == NULL){
			head=newNode;
			newNode->setNext(head);
		}else{
			Node *temp=head;
			while(temp->getNext()!=head){
				temp=temp->getNext();
			}
			temp->setNext( newNode );
			newNode->setNext( head );
		}
	}

	void insertBegin( int data ){
		Node *newNode=new Node( data );
		if( head==NULL ){
			head=newNode;
			newNode->setNext(head);
		}else{
			Node *temp=head;
			while(temp->getNext()!=head){
				temp=temp->getNext();
			}
			temp->setNext(newNode);
			newNode->setNext( head );
			head=newNode;
		}
	}

	void insertBefore( int before, int data  ){
		Node *newNode=new Node( data );
		if( head->getData() == before ){
			insertBegin( data );
		}else{
			Node *temp=head;
			while(temp->getNext()!=NULL){
				if( temp->getNext()->getData() == before ){
					break;
				}
				temp=temp->getNext();
			}
			newNode->setNext(temp->getNext());
			temp->setNext(newNode);
		}
	}

	void insertAfter( int after, int data ){
		Node *temp=head;
		while(temp->getNext()!=head){
			if( temp->getData()==after ){
				break;
			}
			temp=temp->getNext();
		}
		if( temp->getNext() == head && temp->getData() == after){
			Node *newNode = new Node( data );
			temp->setNext(newNode);
			newNode->setNext(head);
		}else{
			Node *newNode=new Node( data );
			newNode->setNext(temp->getNext());
			temp->setNext(newNode);
		}
		
	}

	void deleteEnd(){
		Node *temp=head;
		Node *prev = NULL;
		if(temp->getNext() == head){
			head = NULL;
			temp = NULL;
			delete( temp );
		}else{
			while(temp->getNext()!=head){
				prev = temp;
				temp=temp->getNext();
			}
			prev->setNext(head);
			temp = NULL;
			delete( temp );
		}
		
	}

	void deleteBegin(){
		if( head->getNext() == head ){
			head = NULL;
			delete(head);
		}else{
			Node *temp=head;
			Node *prev = head;
			while(temp->getNext()!=head){
				temp=temp->getNext();
			}
			head = head->getNext();
			temp->setNext(head);
			prev=NULL;
			delete(prev);
		}	
	}

	void deleteAfter( int after ){
		Node *temp=head;
		Node *prev = NULL;
		while( temp->getNext()!=head ){
			prev = temp;
			if( temp->getData() == after ){
				break;
			}
			temp=temp->getNext();
		}
		temp=temp->getNext();
		if(temp == head ){
			cout<<"Can't Delete This Node... :("<<endl;
		}else{
			if(temp->getNext() == head ){
				prev->setNext(head);
				temp=NULL;
				delete(temp);
			}else{
				prev->setNext(temp->getNext());
				temp=NULL;
				delete(temp);
			}
		}
		
	}

	void deleteBefore( int before ){
		Node *temp=head;
		Node *prev=NULL;

		while( temp->getNext()!=head ){
			if( temp->getNext()->getData() == before ){
				break;
			}
			prev = temp;
			temp=temp->getNext();
		}
		if( temp->getNext() == head ){
			cout<<"Can't Delete This Node... :("<<endl;
		}else{
			if(prev == NULL && temp->getNext()->getData() == before){
				head=temp->getNext();
				temp->getNext()->setNext(head);
				temp = NULL;
				delete(temp);
			}else{

				prev->setNext(temp->getNext());
				temp=NULL;
				delete( temp );
			}
		}
	}

	void print(){
		Node *temp=head;
		if(head!=NULL){
			do{
				temp->print();
				if(temp->getNext()!=head){
					cout<<" ->";
				}
				temp=temp->getNext();
			}while(temp != head);
			cout<<endl;
		}
	}
};

void list(){
	cout<<"i. Insert At End "<<endl;
	cout<<"b. Insert At Begin "<<endl;
	cout<<"a. Insert Before ( Before, Data ) "<<endl;
	cout<<"s. Insert After ( After, Data ) "<<endl;
	cout<<"d. Delete Last Node Of Linklist "<<endl;
	cout<<"f. Delete First Node Of Linklist "<<endl;
	cout<<"g. Delete Node After Some Node Of Linklist ( After ) "<<endl;
	cout<<"h. Delete Node Before Some Node Of Linklist ( Before ) "<<endl;
	cout<<"p. Print The Linklist "<<endl;
	cout<<"l. List The Menu "<<endl;
	cout<<"Enter The Choice: "<<endl;
}

int main(){

	cLinklist cll;
	char choice;
	int data,pos;
	cout<<"Press 'l' For List Of Operations "<<endl;
	
	while(1){
		cin>>choice;
		if( choice == 'l' ){
			list();
		}else if( choice == 'i' ){
			cin>>data;
			cll.insertEnd( data );
		}else if( choice == 'b' ){
			cin>>data;
			cll.insertBegin( data );
		}else if( choice == 'a'){
			cin>>pos;
			cin>>data;
			cll.insertBefore( pos, data );
		}else if( choice == 's' ){
			cin>>pos;
			cin>>data;
			cll.insertAfter( pos, data );
		}else if( choice == 'd' ){
			cll.deleteEnd();
		}else if( choice == 'f' ){
			cll.deleteBegin();
		}else if( choice == 'g' ){
			cin>>pos;
			cll.deleteAfter( pos );
		}else if( choice == 'h' ){
			cin>>pos;
			cll.deleteBefore( pos );
		}else if( choice == 'p' ){
			cll.print();
		}else if( choice == 'q' ){
			break;
		}
	}


	return 0;
}
