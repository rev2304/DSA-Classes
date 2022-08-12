#include<iostream>

#include "linkedList.hpp"

template<class T>
void LinkedList<T>::display(){

    Node<T> *current = head;

    while (current->next != nullptr)
    {
        std::cout << current->value << "->";
        current = current->next;
    }
    std::cout << current->value << "\n";

}

template<class T>
void LinkedList<T>::insertAtBeg(T element){

    Node<T> *node = new Node<T>(element);

    if(head == nullptr){
        head = node;
        tail = node;
        this->length++;
        return;
    }
        

    node->next = head;
    head = node;
    this->length++;

}

template<class T>
void LinkedList<T>::insertAtEnd(T element){

    Node<T> *node = new Node<T>(element);

    if(head == nullptr){
        head = node;
        tail = node;
        this->length++;
        return;
    }
        

    tail->next = node;
    tail = node;
    this->length++;

}

template<class T>
void LinkedList<T>::insertAtPos(T element,int position){


    if(position < 0 || position > length){
        std::cout << "Index out of bound" << "\n";
        return;
    }

    if(position == 0)
        insertAtBeg(element);

    else if(position == length)
        insertAtEnd(element);

    else{
        Node<T> *node = new Node<T>(element);

        int i = 0;
        Node<T> *current = head;

        while(i < position - 1){
            current = current->next;
            i++;
        }

        node->next = current->next;
        current->next = node;
        this->length++;

    }

}

int main(){

    LinkedList<int> ll1;

    ll1.insertAtBeg(12);
    ll1.insertAtBeg(35);
    ll1.insertAtBeg(5);
    ll1.insertAtEnd(10);
    ll1.insertAtPos(50,2);

    ll1.display();
    std::cout << ll1.len() << "\n";

    return 0;
}