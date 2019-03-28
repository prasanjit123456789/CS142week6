/*Binary search tree*/
#include<iostream>
using namespace std;
//Node class
class Node{
public:
	int data;
	Node* left,*right,*parent;
	//constructor
	Node(int value){
		data=value;
		left=NULL;
		right=NULL;
		parent=NULL;
	}
};
//BiST class
class BiST{
public:
	Node* root;
	BiST(){
		root=NULL;
	}
	//insert function 
	void insert(int value){
		//if it is the first element
		if(root==NULL)	root=new Node(value);
		else	//inserthelper function
			inserthelper(root,value);
	}
	//inserthlper function
	void inserthelper(Node* current,int value){
		if(current->data>=value){
			if(current->left==NULL) {
			current->left=new Node(value);
			current->left->parent=current;
			}
			else inserthelper(current->left,value);
		}
		else{
			if(current->right==NULL){
			 current->right=new Node(value);
			current->right->parent=current;
			}
			else inserthelper(current->right,value);
		}
	}
	//search function that searchs the value
	Node* search(int value){
		return searchhelper(root,value);
	}
	//searchhelper function
	Node* searchhelper(Node* current,int value){
		//stoping condition
		if(current==NULL || current->data==value) return current;
		else{
			//if current->data>=value
			if(current->data>=value) return searchhelper(current->left,value);
			else return searchhelper(current->right,value);		
		}
	}
	//display function that displays the vlaues
	void display(){
		//displayhelper function
		displayhelper(root);
		cout<<"NULL"<<endl;
	}
	//displayhelper functio
	void displayhelper(Node* current){
		//stoping condition
		if(current==NULL) return;
		else{
			displayhelper(current->left);
			cout<<current->data<<"->";
			displayhelper(current->right);
		}
	}
	//print2d function that prints in a fancy way
	void print2d(){
		print2dhelper(root,0);
	}
	//print2dhelper function
	void print2dhelper(Node* current,int space){
		//stoping condition
		if(current==NULL) return;
		else{
			print2dhelper(current->right,space+1);
			for(int i=0;i<space;i++){
				cout<<"  ";
			}
			cout<<current->data<<endl;
			print2dhelper(current->left,space+1);
		}
	}
      	// void replace_At_Parent(Node * A, Node *B) - Replaces A with B at the parent of A. This replacement makes the B the respective child (left/right child depending if A was left or right child of its parent)
	void replace_At_Parent(Node* A,Node* B){
		//if B is the left child of A
		if(A->parent->left==A){ A->parent->left=B; B->parent=A->parent;}
		//if B is the right child of A
		else {A->parent->right=B; B->parent=A->parent;}
	}
	//void deleteNode(int value) - Deletes the node with "value"
	void deleteNode(int value){
		//find the address of the Node
		Node* temp=search(value);
		//if it is NULL
		if(temp==NULL) cout<<"There is no node having this value"<<endl;
		else{
			//if it has no child
			if(temp->right==NULL && temp->left==NULL){
				//if it is the root
				//delete temp;temp=NULL;
				if(temp==root) {delete root;root=NULL;}
				else{			
			        	if(temp->parent->left==temp) {delete temp->parent->left;temp->parent->left=NULL;}
					else {delete temp->parent->right;temp->parent->right=NULL;}
				}
			}
			//only left child is present
			else if(temp->right==NULL && temp->left!=NULL){
				//if it is the root
				if(temp==root) root=root->left;
				//replace at parent
				else replace_At_Parent(temp,temp->left);
				delete temp;temp=NULL;
			}
			//if only right child is present
			else if(temp->right!=NULL && temp->left==NULL){
				//if it is the root
				if(temp==root) root=root->right;
				//replace at parent
				else replace_At_Parent(temp,temp->right);
				delete temp; temp=NULL;
			}
			//if two children are present
			else{
				//first find the the min element in the right sub branch
				Node* current=find_min(temp->right);//cout<<endl<<current->data<<endl;
				int a=current->data;
				//replace at parent
				deleteNode(a);
				//replace_At_Parent(current,current->right);
				
				temp->data=a;
			}
		}	
	}
	//find_min function that finds the minimum element in the given sub branch
	Node* find_min(Node* current){
		if(current==NULL || current->left==NULL) return current;
		//otherwise go to the left
		else return find_min(current->left);
	}
	//height function finds the  height of  the binary search tree
	int height(Node* current){
		//stoping condition
		if(current==NULL) return 0;
		//for recursion
		else{
			int a=1+height(current->left);
			int b=1+height(current->right);
			if(a>b) return a;
			else return b;
		}
	}
	//countItems function that counts the number of nodes in the binary search tree
	int countItems(Node* current){
		//stoping condition
		if(current==NULL) return 0;
		else{
			int a=0,b=0;
			a=1+countItems(current->left);
			b=countItems(current->right);
		            return a+b;	
		}
	} 
	//rangeSearch function that prints and counts all the numbers between two given numbers 
	int rangeSearch(int k1,int k2){
		int a,b,c;
		//arrange the values in a order
		if(k1>k2){a=k1;b=k2;}
		else{a=k2;b=k1;}
		c=rangeSearchHelper(b,a,root);
		cout<<"NULL"<<endl;
		return c;
	}
	int rangeSearchHelper(int k1,int k2,Node* current){
		//stoping condition
		if(current==NULL) return 0;
		else if(current->data<k1 || current->data>k2) return 0;
		//recurring condition
		else{
			int a=0,b=0;
			//first go to the smallest value in the range
			a=1+rangeSearchHelper(k1,k2,current->left);
			cout<<current->data<<"->";
			b=rangeSearchHelper(k1,k2,current->right);
			return a+b;	
		}
	}
};
//main function
int main(){
    
    BiST bst1;
    bst1.insert(4);
    bst1.insert(-5);
    bst1.insert(2);
    bst1.insert(3);
    bst1.insert(1);
    bst1.insert(-1);
    bst1.insert(0);
    bst1.insert(6);
    bst1.insert(5);
    bst1.insert(7);
    bst1.insert(8);
    bst1.display();
    if(bst1.search(3) != NULL){
        cout << endl << bst1.search(3)->data << endl;
    }
    bst1.print2d();
    cout<<endl<<"Height="<<bst1.height(bst1.root)<<endl;
    cout<<"No of items="<<bst1.countItems(bst1.root)<<endl;
    cout<<"The number of items between -5 and 6="<<bst1.rangeSearch(-5,6)<<endl;
    bst1.deleteNode(6);
    bst1.print2d();
    cout << "Deleting 2" << endl;
    bst1.deleteNode(2);
    bst1.print2d();
    bst1.deleteNode(4);
    bst1.print2d();
    bst1.deleteNode(7);
    bst1.print2d();
    cout<<"HI 7 IS DELETED"<<endl;
    bst1.deleteNode(8);
    bst1.print2d();
    cout<<endl<<"No of items="<<bst1.countItems(bst1.root)<<endl;
    cout<<"Height="<<bst1.height(bst1.root)<<endl;
    cout<<"The number of items between -5 and 6="<<bst1.rangeSearch(-5,6)<<endl;
    bst1.deleteNode(3);
    bst1.print2d();
   bst1.deleteNode(1);
    bst1.print2d();
    bst1.deleteNode(1);
    bst1.print2d();
    return 0;
}
