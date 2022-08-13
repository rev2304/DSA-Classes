#include<iostream>

#include "Stack.hpp"

template<class T>
void Stack<T>::push(T element){
    Node<T> *tmp = new Node<T>(element);
    tmp->next = head; len++;
    head = tmp;
}  

template<class T>
T Stack<T>::pop(){

    if(head == nullptr){
        std::cout << "Stack is empty\n";
    }

    else{

        Node<T> *tmp = head;
        head = head->next;
        T elm = tmp->data;
        len--;
        delete tmp;
        return elm;
    }

}    

template<class T>
T Stack<T>::top(){

    if(head == nullptr)
        std::cout << "Stack is empty\n";

    else
        return head->data;

}    