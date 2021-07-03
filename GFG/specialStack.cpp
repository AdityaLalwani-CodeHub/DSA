/*
Special Stack

Design a data-structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. Your task is to complete all the functions, using stack data-Structure.


Example 1:

Input:
Stack: 18 19 29 15 16
Output: 15
Explanation:
The minimum element of the stack is 15.
 


Your Task:
Since this is a function problem, you don't need to take inputs. You just have to complete 5 functions, push() which takes the stack and an integer x as input and pushes it into the stack; pop() which takes the stack as input and pops out the topmost element from the stack; isEmpty() which takes the stack as input and returns true/false depending upon whether the stack is empty or not; isFull() which takes the stack and the size of the stack as input and returns true/false depending upon whether the stack is full or not (depending upon the
given size); getMin() which takes the stack as input and returns the minimum element of the stack. 
Note: The output of the code will be the value returned by getMin() function.


Expected Time Complexity: O(N) for getMin, O(1) for remaining all 4 functions.
Expected Auxiliary Space: O(1) for all the 5 functions.
*/

// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends

int top = -1;

void push(stack<int>& s, int a){
	// Your code goes here
	if(top == -1)
	{
	    s.push(a);
	    top = 0;
	    return;
	}
	int t = s.top();
	if(a <= t)
	    s.push(a);
	else
	{
	    s.pop();
	    s.push(a);
	    s.push(t);
	}
	top++;
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	return (top+1) == n;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	return top == -1;
}

int pop(stack<int>& s){
	// Your code goes here
	if(top == -1)
	{
	    return -1;
	}
	int t = s.top();
	s.pop();
	top--;
	return t;
}

int getMin(stack<int>& s){
	// Your code goes here
	return s.top();
}