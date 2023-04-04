#include <iostream>
#include <chrono>

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

//returns whether the stack is empty or not
bool isEmpty() {
    return top == nullptr;
}

//returns whether the stack is full or not
bool isFull() {
    // Linked list implementation of a stack cannot be full
    return false;
}

//returns the top element of the stack
int StackTop() {
    if (top == nullptr) {
        std::cout << "Error: Stack is empty\n";
        return -1;
    }
    else{
        return top->data;
    }
}

//prints the stack
void Display() {
    if (top == nullptr) {
        std::cout << "Stack is empty\n";
        return;
    }
    else{
        std::cout << "Stack: ";
    }
    Node* temp = top;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

int main() {
    // Start measuring execution time
    auto start = std::chrono::high_resolution_clock::now();

    // operations to implement for the stack
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
    Display();
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    Display();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    Display(); 

    // End measuring execution time and print the duration
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " seconds\n";

    return 0;
}
