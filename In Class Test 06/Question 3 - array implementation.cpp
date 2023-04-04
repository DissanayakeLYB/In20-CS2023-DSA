#include <iostream>
#include <chrono>

#define arr_size 100

int stack[arr_size]; //capacity of the stack
int top = -1; //initially stack is empty

//push adds an element to the top of the stack
void Push(int value) {
    if (top >= arr_size - 1) {
        std::cout << "Error: Stack overflow\n";
        return;
    }
    stack[++top] = value;
}

//pop removes an element on the top of the stack
void Pop() {
    if (top == -1) {
        std::cout << "Error: Stack underflow\n";
        return;
    }
    --top;
}

//returns whether the stack is empty or not
bool isEmpty() {
    return top == -1;
}

//returns whether the stack is full or not
bool isFull() {
    return top >= arr_size - 1;
}

//returns the top element of the stack
int StackTop() {
    if (top == -1) {
        std::cout << "Error: Stack is empty\n";
        return -1;
    }
    else{
        return stack[top];
    }
}

//prints the stack
void Display() {
    if (top == -1) {
        std::cout << "Stack is empty\n";
        return;
    }
    else{
        std::cout << "Stack: ";
    }
    for (int i = 0; i <= top; ++i) {
        std::cout << stack[i] << " ";
    }
    std::cout << "\n";
}

int main() {
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

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}
