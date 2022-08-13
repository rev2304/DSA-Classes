#include<iostream>

#include "Stack.hpp"
#include "Stack.cpp"

int main(){

    Stack<int> s;

    s.push(12);
    s.push(21);
    s.push(35);

    std::cout << "Size of stack:" << s.size() << "\n";

    while (!s.isEmpty())
    {
        std::cout << s.pop() << " ";
    }std::cout << "\n";
    

    return 0;
}