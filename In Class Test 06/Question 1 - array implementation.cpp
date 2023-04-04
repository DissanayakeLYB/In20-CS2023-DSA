#include <iostream>

#define arr_size 100
//size of the array

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

int main() {
    //push adds elements to the top of the stack
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

    //pop removes the top element of the stack
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();

    return 0;
}
