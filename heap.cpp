/*Binary heap*/
//the parent should be smaller or greater than all the children but not both
//for min parent<{l,r} and for max parent>{l,r}
//the next generation of node will come after filling the current generation
//
#include<iostream>
using namespace std;
//class Heap
class Heap{
	public:
	//pointer to array elements
	int *hArr;
	//maximum no of elements
	int mSize;
	//current size of array
	int cSize;
	//constructor
	Heap(int mSize){
		//create a new array
		hArr=new int(mSize); 
		this->mSize=mSize;
		cSize=-1;
	}		
	//getting parent
	int parent(int i){return (i-1)/2;}
	//getting left child
	int leftchild(int i){return 2*i+1;}
	//getting right child
	int rightchild(int i){return 2*i+2;}
	//swap function that swaps the values
	void swap(int &a,int &b){
		int t=a;
		a=b;
		b=t;
	}	
	//insertions
	void insert(int value){
		cSize++;
		//if it is the first element
		if(cSize==0){hArr[cSize]=value;}
		else if(cSize==mSize) cout<<"There is no space to store."<<endl;
		else{
			//first insert at last
			hArr[cSize]=value;
			//find the value which is just smaller than this
			//compare for prop 2
			prop_2_compare(cSize);
		}
	}
		//prop_2_compare function that compares with the parent and swaps if needed
		void prop_2_compare(int i){
			//stoping condition
			//cout<<i<<"-,"<<endl;
			if(i==0) return;
			//it does in the way like if the parent is bigger than this child then it swaps
			else if(hArr[(i-1)/2]>hArr[i]) {
				swap(hArr[(i-1)/2],hArr[i]);
				//do recursion
				prop_2_compare((i-1)/2);
			}
			else return;
		}
		//MinHeapify function that swap with the child having minimum value
		void MinHeapify(int i){
			//stoping condition
			if(i>cSize) return;
			else if(hArr[i]<hArr[2*i+1] and hArr[i]<hArr[2*i+2]) return;
			else if(2*i+1>cSize) return;
			else if(2*i+2>cSize and 2*i+1<=cSize) swap(hArr[i],hArr[2*i+1]); 
			//compare with the children and replace accordingly
			else if(hArr[2*i+1]>hArr[2*i+2]) {
				swap(hArr[2*i+2],hArr[i]);
				MinHeapify(2*i+2);
			}
			else {
				swap(hArr[2*i+1],hArr[i]);
				MinHeapify(2*i+1);
			}
		}
		//getMin function that returns the value of the minimum
		int getMin(){
			return hArr[0];
		}
		//extract_min function that deletes the minimum function 
		int extract_min(){
			if(cSize==-1) cout<<"There is no element."<<endl;
			else if(cSize==0){
				int a=hArr[0];
				return a;
			}
			else{
				//store the minimum
				int a=hArr[0];
				//swap the values
				swap(hArr[0],hArr[cSize]);
				cSize--;
				MinHeapify(0);
				return a;
			}
		}
	//display function that displays the values
	void display(){
		for(int i=0;i<=cSize;i++){
			cout<<"("<<i<<","<<hArr[i]<<")"<<endl;
		}
		cout<<"NULL"<<endl;
	}
	//deletAt function that deletes the value at that position
	int deletAt(int a){
		if(a>cSize) cout<<"This position is not avialable"<<endl;
		else{
			int b=hArr[a];
			//if it is the the last element
			if(a==cSize) cSize--;
			else{}		
		}
	}
};
//define main
int main(){
	Heap h(15);
	for(int i=10;i>4;i--){
		h.insert(i);	
	}
	h.display();
	return 0;
}
