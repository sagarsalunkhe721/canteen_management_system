#include<iostream>
using namespace std;

class Node{
	int data;
	Node *next;

	public:
	
	Node(){ }
	Node(int data){
		this->data=data;
		next=NULL;
	}
	
	void setNext(Node *next){
		this->next = next;
	}
	
	Node* getNext(){
		return this->next;
	}

	void setData(int data){
		this->data=data;
	}

	int getData(){
		return this->data;
	}

};

class stackUsingLinklist{
	int data;
	int top,index;
	Node *Top; 

	public:
	stackUsingLinklist(){ 
		data = 0;
		Top = NULL;
	}

	bool isEmpty(){
		if(Top==NULL)
			return 1;
		return 0;	
	}


	void push(int data){
		Node *newNode = new Node(data);
		if( Top == NULL){
			Top=newNode;	
		}else{
			newNode->setNext(Top);
			Top=newNode;
		}
		
	}

	Node *pop(){
		if(isEmpty()){
			cout<<"Stack Is Empty.."<<endl;
		}
		else{
			Node *temp = Top;
			temp = temp->getNext();
			Top = temp;
			temp = NULL;
			delete(temp);
		}
	}	
	void print(){
		Node *traversal = Top;
			while(traversal!=NULL){
			cout<<traversal->getData();
			if( traversal->getNext()!=NULL ){
				cout<<"->";
			}
			traversal=traversal->getNext();
		}
		cout<<endl;
	}
};

void list(){
	cout<<"---> Stack Operations <---"<<endl;
	cout<<"i. Push"<<endl;
	cout<<"d. Pop"<<endl;
	cout<<"p. Print"<<endl;
	cout<<"q. Quit"<<endl;
	cout<<"Enter Your Choice: "<<endl;
}

int main(){
	stackUsingLinklist s;
	int data;
	char choice;

	while(1){
		cin>>choice;
		if( choice == 'l' )
			list();
		else if( choice == 'i' ){
			cin>>data;
			cout<<"---> Pushed One Element On Top Of Stack <---"<<endl;
			s.push(data);
		}else if( choice == 'd' ){
			cout<<"---> Popped Top Element Of Stack <---"<<endl;
			s.pop();
		}else if( choice == 'p' ){
			cout<<"Current Stack Is :"<<endl;
			s.print();
		}else if( choice == 'q' ){
			break;
		}
	}	
	
	
	return 0;
}
