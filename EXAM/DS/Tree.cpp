#include<iostream>
using namespace std;

template <typename T>
//--------------------------------------------------------------------------------------------------
//-------------------------------------->  Stack  <-------------------------------------------------
class Stack{
	int top;
	T data;
	int size;
	T *arr;

	public:
	Stack(){}

	Stack(int size){
		this->data=NULL;
		this->top=0;
		this->size=size;
		this->arr=new T[size];
	}

	bool isFull(){
		if(top==size)
			return 1;
		return 0;
	}

	bool isEmpty(){
		if(top==0)
			return 1;
		return 0;
	}

	void push(T data){
		if(isFull()){
			cout<<"Stack Is Full..."<<endl;
		}else{
			arr[top]=data;
			top++;	
		}
	}

	T pop(){
		T data;
		if(isEmpty()){
			cout<<"Stack Is Empty..."<<endl;
		}else{
			top--;
			data=arr[top];
			return data;
		}
	}

};

//--------------------------------------------------------------------------------------------------
//-------------------------------------->  Queue  <-------------------------------------------------

template <typename T>
class Queue{
	T data;
	int front;
	int rear;
	int size;
	T *arr;

	public:

		Queue(){}

		Queue(int size){
			this->data = NULL;
			this->front=0;
			this->rear=0;
			this->size=size;
			this->arr = new T[size];
		}

		bool isEmpty(){
			if(front==rear)
				return 1;
			return 0;
		}

		bool isFull(){
			if( rear==size )
				return 1;
			return 0;
		}

		void enqueue(T data){
			if(isFull()){
				cout<<"Queue Is Full..."<<endl;
			}else{
				arr[rear]=data;
				rear++;
			}
		}
		
		T dequeue(){
			T data;
			if(isEmpty()){
				cout<<"Queue Is Empty..."<<endl;
			}else{
				data=arr[front];
				front++;
				return data;
			}
		}
};

//--------------------------------------------------------------------------------------------------
//-------------------------------------->  Tree  <--------------------------------------------------

class Node{
	int data;
	Node *left;
	Node *right;

	public:

	Node(){}

	Node(int data){
		this->data=data;
		this->left=NULL;
		this->right=NULL;	
	}

	void setData(int data){
		this->data=data;
	}

	int getData(){
		return this->data;
	}

	void setRight(Node * right){
		this->right=right;
	}

	Node *getRight(){
		return this->right;
	}

	void setLeft(Node * left){
		this->left=left;
	}

	Node * getLeft(){
		return this->left;
	}

	void print(){
		cout<<this->data<<" ";
	}

};


class BST{
	Node *root;
	public:
	BST(){
		root=NULL;
	}

	void insert(int data){
		Node *newNode=new Node(data);
	
		if(root==NULL){
			root=newNode;
		}
		else{
			Node *temp=root;
			Node *prev=NULL;
			while(temp!=NULL){
				prev=temp;
				if(data>temp->getData()){
					temp=temp->getRight();
				}
				else{
					temp=temp->getLeft();
				}
			}
			if(data>prev->getData()){
				prev->setRight(newNode);
			}else{
				prev->setLeft(newNode);
			}			
		}
	}

	void inorder(Node *root){
		if(root!=NULL){
			inorder(root->getLeft());
			root->print();
			inorder(root->getRight());
		}
		
	}

	void inorder(){
		inorder(root);
		cout<<endl;
	}

	void preorder(Node *root){
		if(root!=NULL){
			root->print();
			preorder(root->getLeft());
			preorder(root->getRight());
		}
	}

	void preorder(){
		preorder(root);
		cout<<endl;
	}

	void postorder(Node *root){
		if(root!=NULL){
			postorder(root->getLeft());
			postorder(root->getRight());
			root->print();
		}
	}

	void postorder(){
		postorder(root);
		cout<<endl;
	}

	void DepthFirstSearch(){
		Stack <Node *> s(100);
		Node *temp;
		s.push(root);
		while(!s.isEmpty()){
			temp=s.pop();
			temp->print();

			if(temp->getRight()!=NULL){
				s.push(temp->getRight());
			}
			
			if(temp->getLeft()!=NULL){
				s.push(temp->getLeft());
			}
		}
		cout<<endl;

	}

	void BreadthFirstSearch(){
		Queue <Node *> q(100);
		Node *temp;
		q.enqueue(root);

		while(!q.isEmpty()){
			temp=q.dequeue();
			temp->print();

			if(temp->getLeft()!=NULL){
				q.enqueue(temp->getLeft());
			}
			if(temp->getRight()!=NULL){
				q.enqueue(temp->getRight());
			}
		}
		cout<<endl;
	}

};

//--------------------------------------------------------------------------------------------------
//------------------------------>  Global List Function  <------------------------------------------

void list(){
	cout<<"i. Insert to Tree "<<endl;
	cout<<"w. Print Inorder Trasversal "<<endl;
	cout<<"d. Print Preorder Trasversal "<<endl;
	cout<<"s. Print Postorder Trasversal "<<endl;
	cout<<"t. Print Depth First Trasversal "<<endl;
	cout<<"g. Print Breadth First Trasversal "<<endl;
	cout<<"q. Quit \n"<<endl;
	cout<<"Enter your Choice: "<<endl;
}

int main(){
	BST bst;
	char choice;
	int data;
	while(1){
		cin>>choice;
		if(choice == 'l'){
		 	list();
		}else if( choice == 'i' ){
			cout<<"Enter The Data"<<endl;
			cin>>data;
			bst.insert(data);
		}else if( choice == 'w' ){
			cout<<"Printing Inorder"<<endl;
			bst.inorder();
		}else if( choice == 'd' ){
			cout<<"Printing Preorder"<<endl;
			bst.preorder();
		}else if( choice == 's' ){
			cout<<"Printing Postorder"<<endl;
			bst.postorder();
		}else if( choice == 't' ){
			cout<<"Printing Depth First Search"<<endl;
			bst.DepthFirstSearch();
		}else if( choice == 'g' ){
			cout<<"Breadth First Traversal "<<endl;
			bst.BreadthFirstSearch();
		}else if(choice == 'q'){
			break;
		}

	}
	return 0;
}
