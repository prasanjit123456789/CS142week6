/*Binary search tree*/
#include<iostream>
using namespace std;
//class node
class Node{
	public:
	int data;
	Node* right,*left;
	//define constructor
	Node(int value){
		data=value;
		right=NULL;
		left=NULL;
	}
};
//lBiST class
class BiST{
	//make public
	public:
	Node* root;
	BiST(){
		root=NULL;
	}
	//insert function that inserts the datas in the tree
	void insert(int value){
		//call by another function that inserts by the recursion and high values in the right and small values in the left
		inserthelper(root,value);
	}
	//the recursion function 
	void inserthelper(Node* &current,int value){
		if(current==NULL){
			current=new Node(value);
		}
		else if(value<=current->data) inserthelper(current->left,value);
		else inserthelper(current->right,value);
	}
	//search function that return the address of the node having given value
	Node* search(Node* current,int value){
		if(current==NULL || current->data==value) return current;
		else if(value<=current->data) search(current->left,value);
		else search(current->right,value);
	}
	//display function that prints the tree
	void display(){
		//another display function that prints the out put by recursion
		displayhelper(root);
		cout<<"NULL"<<endl;
	}
	void displayhelper(Node* current){
		//stoping condititon
		if(current==NULL) return;
		else{
			displayhelper(current->left);
			cout<<current->data<<"->";
			displayhelper(current->right);
		}
	}
	//height function that return the height of the tree
	int height(){
		int c=0;
		//height calls a function that return the height of the tree
		heighthelper(root,0,c);
		return c; 
	}
	int heighthelper(Node* current,int i,int &p){
		//stoping condition
		if (current==NULL) {
			if (p<i) p=i;
			return i;
		}
		else{
			heighthelper(current->left,i+1,p);
			heighthelper(current->right,i+1,p);
		}
	}
	//fancydisplay function that displays the output in a proper tree look
	void fancydisplay(){
		//fancy display function calls another function that displays the output
		fancydisplayhelper(root,0);
	}
	void fancydisplayhelper(Node* current,int space){
		//stoping condition
		if(current==NULL) return;
		else{
			fancydisplayhelper(current->right,space+1);
			for(int i=0;i<space;i++){
				cout<<"    ";
			}
			cout<<current->data<<endl;
			fancydisplayhelper(current->left,space+1);
		}
	}
	
};
//main function
int main(){
	//define object
	BiST b;
	for(int i=1;i<11;i++){
		b.insert(i);
	}
	for(int i=5;i<16;i++){
		b.insert(i);
	}
	for(int i=0;i>-20;i--){
		b.insert(i);
	}
	b.insert(1);
	b.display();
	cout<<b.height()<<endl;
	b.fancydisplay();
	return 0;
}
