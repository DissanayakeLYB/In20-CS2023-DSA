#include <iostream>

// Stack implementation using linked list
struct Node {
    int data;
    Node* next;
};

Node* top = nullptr; // initially stack is empty

//push adds an element to the top of the stack
void Push(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->next = top;
    top = temp;
}

//pop removes an element on the top of the stack
void Pop() {
    if (top == nullptr) {
        std::cout << "Error: Stack underflow\n";
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

int main() {

    //calling the push function adds elements to the top of the stack
    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);

    //calling the pop function removes the top element of the stack
    Pop();
    Pop();
    Pop();
    Pop();


    return 0;
}
