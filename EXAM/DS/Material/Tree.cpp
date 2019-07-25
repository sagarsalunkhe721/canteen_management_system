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

//--------------------------------------------------------------------------------------------------
//---------------------------->  Search Perticular Node  <------------------------------------------

	Node *searchNode(Node *node, int data){
		Node *temp=node;
		while( temp!=NULL && temp->getData()!=data){
			if(data > temp->getData()){
				temp=temp->getRight();
			}else{
				temp=temp->getLeft();
			}
		}
		return temp;
	}

//--------------------------------------------------------------------------------------------------
//---------------------------->  Search Perticular Parent  <----------------------------------------

	Node *findParent(Node *node, int data){
		Node *temp=node;
		Node *parent = NULL;
		while( temp != NULL & temp->getData() != data ){
			parent=temp;
			if(data > temp->getData())
				temp=temp->getRight();
			else
				temp=temp->getLeft();
		}
		return parent;
	}

//--------------------------------------------------------------------------------------------------
//---------------------------->  Delete A Node Having Zero Child  <---------------------------------

	Node *deleteZeroChild(Node *childRoot, Node *nodeToBeDeleted){
		if( childRoot==nodeToBeDeleted ){
			childRoot=NULL;
		}else{
			Node *parent=findParent( childRoot, nodeToBeDeleted->getData() );
			
			if( nodeToBeDeleted->getData() > parent->getData() ){
				parent->setRight( NULL );
			}
			else{
				parent->setLeft( NULL );
			}
			nodeToBeDeleted = NULL;
			delete(nodeToBeDeleted);
		}
			return childRoot;
		
	}

//--------------------------------------------------------------------------------------------------
//---------------------------->  Delete A Node Having One Child  <----------------------------------

	Node *deleteOneChild(Node *root, Node *nodeToBeDeleted){
		Node *subchild;

		if(nodeToBeDeleted->getLeft()!=NULL)
			subchild=nodeToBeDeleted->getLeft();
		else
			subchild=nodeToBeDeleted->getRight();

		
		if(root==nodeToBeDeleted){
			root=NULL;
			root=subchild;
		}else{
			Node *parent = findParent( root, nodeToBeDeleted->getData() );
			if( nodeToBeDeleted->getData() > parent->getData() ){
				parent->setRight(subchild);
			}else{
				parent->setLeft(subchild);
			}
		}
		return root;
	}	

//--------------------------------------------------------------------------------------------------
//------------------->  Get Rightmost Element Of Left Child  <-------------------------------------

	Node *getRightmostOfLeft(Node *root){
		while(root->getRight()!=NULL){
			root=root->getRight();
		}
		return root;
	}

//--------------------------------------------------------------------------------------------------
//-------------------------->   Delete A Node Having Two Child  <-----------------------------------

	Node * deleteTwoChild(Node *root, Node *nodeToBeDeleted ){
		Node *rightmostOfLeftNode = getRightmostOfLeft( nodeToBeDeleted->getLeft() );
		int data = nodeToBeDeleted->getData();
		nodeToBeDeleted->setData( rightmostOfLeftNode->getData() );
	//	cout<<"New Value Of NodeToBeDeleted Is: "<<nodeToBeDeleted->getData()<<endl;
		rightmostOfLeftNode->setData( data );
	//	cout<<"New Value Of rightMostOfLeftNode Is: "<<rightmostOfLeftNode->getData()<<endl;

		if(rightmostOfLeftNode->getLeft()!= NULL || rightmostOfLeftNode->getRight()!= NULL ){
			nodeToBeDeleted->setLeft( deleteOneChild( nodeToBeDeleted->getLeft(), rightmostOfLeftNode) );
		}else{
			nodeToBeDeleted->setLeft( deleteZeroChild( nodeToBeDeleted->getLeft(), rightmostOfLeftNode ) );
		}
		return root;
	}

//--------------------------------------------------------------------------------------------------
//------------------------------>  Global Delete Function  <----------------------------------------

	void deleteNode(int data){
		Node *Root=root;
		Node *nodeToBeDeleted = searchNode(Root,data);
		if(nodeToBeDeleted != NULL){
			
			if(nodeToBeDeleted->getLeft() == NULL && nodeToBeDeleted->getRight()==NULL)
				root = deleteZeroChild( root, nodeToBeDeleted );
			else if( nodeToBeDeleted->getLeft()!=NULL && nodeToBeDeleted->getRight()==NULL )
				root = deleteOneChild( root, nodeToBeDeleted );
			else if( nodeToBeDeleted->getLeft()==NULL && nodeToBeDeleted->getRight()!=NULL )
				root = deleteOneChild( root, nodeToBeDeleted );
			else{
				
				root=deleteTwoChild( root, nodeToBeDeleted );
			}
		}
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
	cout<<"o. Delete Leaf Nodes ( Node With Zero Child ) "<<endl;
	cout<<"p. Delete Parent Node ( Node With One Child ) "<<endl;
	cout<<"k. Delete Parent Node ( Node With Two Child ) "<<endl;
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
		}else if( choice == 'o' ){
			cin>>data;
			bst.deleteNode(data);
		}else if( choice == 'p' ){
			cin>>data;
			bst.deleteNode(data);
		}else if( choice == 'k' ){
			cin>>data;
			bst.deleteNode(data);
		}else if(choice == 'q'){
			break;
		}

	}
	return 0;
}
