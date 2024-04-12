#include<iostream>
using namespace std;

// Class definition for Stack
class Stack{
    public:
    int* arr; // Pointer to array to store stack elements
    int size; // Maximum size of the stack
    int top; // Index of the top element in the stack

    // Constructor to initialize the stack with a given size
    Stack(int size){
        arr = new int[size]; // Dynamically allocate memory for the stack
        this->size = size; // Assign the size
        this->top = -1; // Initialize top to -1 indicating an empty stack
    }

    // Function to push an element onto the stack
    void push(int data){
        if(top == size-1){ // Check for stack overflow
            cout << "Stack Overflow" << endl;
            return;
        }
        else{
            top++; // Increment top to point to the next empty position
            arr[top] = data; // Store the new element at the top of the stack
        }
    }

    // Function to pop an element from the stack
    void pop(){
        if(top == -1){ // Check for stack underflow
            cout << "Stack is UnderFlow" << endl;
            return;
        }
        else{
            top--; // Decrement top to remove the top element
        }
    }
    
    // Function to get the top element of the stack
    int getTop(){
        if(top == -1){ // Check if the stack is empty
            cout << "Stack is Empty" << endl;
            return -1; // Return -1 to indicate an empty stack
        }
        else{
            return arr[top]; // Return the top element
        }
    }
    
    // Function to check if the stack is empty
    bool isEmpty(){
        if(top == -1){ // Check if top is -1 indicating an empty stack
            return true; // Return true if the stack is empty
        }
        else{
            return false; // Return false if the stack is not empty
        }
    }
    
    // Function to get the current size of the stack
    int getSize(){
        return top+1; // Return the number of elements in the stack
    }

    // Function to print the stack elements
    void print(){
        cout << "Top: " << top << endl; // Print the index of the top element
        cout << "Top element: " << getTop() << endl; // Print the top element
        cout << "Stack: " ;
        for(int i = 0; i <getSize(); i++){ // Loop through each element in the stack
            cout << arr[i] <<" "; // Print the current element
        }
        cout << endl << endl;
    }

};

// Main function
int main() {
    Stack s1(8); // Create a stack of size 8
    s1.push(10); // Push elements onto the stack
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    s1.push(70);
    s1.push(80);
    // s1.push(90);
    // s1.push(100);
    s1.print(); // Print the stack

   return 0; // Return 0 to indicate successful completion
}
