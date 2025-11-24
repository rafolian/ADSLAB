// NAME: AMIRAH NAILOFAR BINTI MUHAMAD HAFIDZ
// ID: 24007510
// EMAIL: amirah_24007510@utp.edu.my
// COURSE: BACHELOR OF COMPUTER SCIENCE

// #include <iostream>
// using namespace std;

// // Singly Linked List ;

// struct Node{
//   string data;
//   Node* ptr;
//   Node* previousptr;
// };

// int main(){
  
//   Node node1, node2, node3, node4;

  
//   node1.data = "test1";
//   node1.ptr = &node2;
  
//   node2.data = "test2";
//   node2.ptr = &node3;
  
//   node3.data = "test3";
//   node3.ptr = &node4;
  
//   node4.data = "test4";
//   node4.ptr = NULL;

//   cout << "Output:" << endl;
//   Node* current = &node1;
//   while ( current != nullptr){
    
//     cout << current -> data<< " "<<"\n";
//     current = current -> ptr;
    
//   }
  
//   cout << endl;
  
//   return 0;
  
 
  
// }

// Changed the above code into stack using basic operations like push(), pop(), and peek()
// Answer: 

#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* ptr; // pointer to next node
};

// Stack implementation using linked list
class Stack {
private:
    Node* top; // points to the top of the stack

public:
    // Constructor
    Stack() {
        top = nullptr;
    }

    // Push operation
    void push(string value) {
        Node* newNode = new Node(); // create new node
        newNode->data = value;
        newNode->ptr = top; // new node points to the previous top
        top = newNode;      // move top to new node
        cout << value << " pushed into stack\n";
    }

    // Pop operation
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow! Nothing to pop.\n";
            return;
        }
        cout << top->data << " popped from stack\n";
        Node* temp = top;
        top = top->ptr;
        delete temp;
    }

    // Peek operation
    void peek() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top element: " << top->data << endl;
    }

    // Display all elements
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements (top to bottom):\n";
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->ptr;
        }
    }
};

// Main function
int main() {
    Stack s;

    s.push("test1");
    s.push("test2");
    s.push("test3");
    s.push("test4");

    cout << endl;
    s.display();

    cout << endl;
    s.peek();

    cout << endl;
    s.pop();
    s.peek();

    cout << endl;
    s.display();

    return 0;
}