/*Binary Search Tree in c++*/
//if 2 is from 1 then 1 is parent for 2
//a node having no parent is root
//the children which does not have link after is leaf
//the tree in which there is maximum two links is known as binary tree
//every node is connected with other with an edge
//the  nodes between  root and leaf is known as intermediate nodes
//a binary search tree is such a binary tree in which the left data is always less than the right data
//height of the tree is max(all the root paths)

#include<iostream>
using namespace std;
//class Node
class Node{
	//make public
	public:
	int data;
	Node* left,* right;
	Node(int value){
		data=value;
		left=NULL;
		right=NULL;
	}
};
//class Tree
class BiST{
	//make public
	public:
	Node* root;
	BiST(){
		root=NULL;
	}
	//insert1 function that will do the recursion
	void insert1(int value,Node* &current){
		if(current==NULL){
			current=new Node(value);
			if(root==NULL){root=current;}
			return;		
		}
		else if(current->data>=value){
			//cout<<"left,";
			insert1(value,current->left);
		}
		else if(current->data<value){
			//cout<<"right,";
			insert1(value,current->right);
		}
		else{}
	}
	//insert function that inserts the data
	//it will insert the greater number in right side and smaller number in left side
	void insert(int value){
			insert1(value,root);
			//cout<<"NULL"<<endl;
	}
	//recursion display
	void display1(Node* current){
		//stoping condition
		if(current==NULL){return;}
		else{
			//first go to the left leaf
			display1(current->left);
			//print the data
			cout<<current->data<<"->";
			//then go to the right
			display1(current->right);
		}
	}
	//display function
	void display(){
		 display1(root);
		cout<<"NULL"<<endl;	
	}
	//search function that searches the value in the node
	Node* search(Node* current,int value){
		//if it does not get any value or it gets
		if(current==NULL || current->data==value) return current;
		else if(current->data>value) return search(current->left,value);
		else return search(current->right,value);
	}
};
//main
int main(){
	BiST b;
	for(int i=1;i<10;i++){
		b.insert(i);
	}
	//b.display();
	//b.insert(0);
	b.display();
	return 0;
}
