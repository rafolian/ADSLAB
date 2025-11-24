#include <iostream>
using namespace std;

// Queue

struct Node {
  
  string data;
  Node*next;
  
};

class Queue {
  
private :
  Node* front;   // pointer Head
  Node* rear ;   //pointer tail
  
public :
  Queue() {
    
    front = nullptr;
    rear = nullptr;
    
  }
  
  //Enquue process (adding element)
  void Enqueue (string value){
    
    Node* newNode = new Node;
    
    newNode ->data = value;
    newNode ->next = nullptr;
    
    if(rear == nullptr){
      // Queue empty
      front = rear = newNode;
      
    }
    else {
      
    // add new elemnt 
    rear-> next = newNode;
    rear = newNode;
    
    }
    
  }
  
  // Dequeue ( remove lelement from the front)
  
  void Dequeue(){
    
    //chehck for underflow 
    if (front == nullptr){
      cout << "Queue Is Empty"<< endl;
      return ;
      
    }
    cout <<"[ " << front ->data <<" ] " << " Removed From Queue "<< endl;
    
    Node* temp = front;
    
    front = front->next;
    
    // chehk if the queue is empty after Dequeue process
    if (front == nullptr){
      rear = nullptr;
    }
    
    // delete the element on the front
    delete temp;
    
    cout << endl;
  }
  
  // Peek element in the front and rear
  void Peek(){
    
    if (front == nullptr){
      cout << "Queue Is Empty"<< endl;
      return ;
      
    }
    
    cout << "Front element: " << front->data << endl;
    cout << "Rear element: " << rear->data << endl;
    cout << endl;
  }
  
  void Display(){
    
    if (front == nullptr){
      cout << "Queue Is Empty"<< endl;
      return ;
      
    }
    
    Node * current = front;
    cout << "Queue :"<<endl;
    
    while (current != nullptr){
      cout << current-> data << endl;
      current = current-> next;
    }
    cout << endl;
    
    
  }
  
  // Size of Queue
  void Count(){
    
    if (front == nullptr){
      cout << "Queue size is Null "<< endl;
      return ;
      
    }
    Node * current = front;
    int count = 0 ;
    
    while (current != nullptr){
      count++;
      current = current-> next;
    }
    cout << "Size of The Queue: "<< count<< endl;
    
  }
  
};

int main (){
  
  Queue q;
  
  q.Enqueue("test1");
  q.Enqueue("test2");
  q.Enqueue("test3");
  q.Enqueue("test4");
  q.Enqueue("test5");

  q.Count();
  q.Display();
  q.Peek();

  q.Dequeue();
  q.Display();
  q.Count();
  

  return 0;
}