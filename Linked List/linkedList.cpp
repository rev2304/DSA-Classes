#include<iostream>

#include "linkedList.hpp"

//displays the entire list
//T(n) = O(n)
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

//Inserts in begining
//T(n) = O(1) because of head pointer
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

//Inserts in end
//T(n) = O(1) because of tail pointer
template<class T>
void LinkedList<T>::insertAtEnd(T element){

    Node<T> *node = new Node<T>(element);   //allocate memory for a new element

    if(head == nullptr){    //check if the list is empty
        head = node;
        tail = node;
        this->length++;
        return;
    }
        

    tail->next = node;
    tail = node;
    this->length++;

}

//insert an element at given position
//A case of insertion in middle
//T(n) = O(n)
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

//search an element: Uses Linear search, Traverses every node one by one
//T(n) = o(n)
template<class T>
int LinkedList<T>::search(T element){

    int i = 0;
    Node<T> *current = head;

    while (current->next != nullptr)
    {
        if(current->value == element)
            return i;
        i++;
        current = current->next;
    }
    
    return -1;

}

//Delete the element at beginning
//T(n) = O(1)
template<class T>
void LinkedList<T>::deleteFromBeg(){

    //if list is empty, deletion is not possible
    if(head == nullptr){
        std::cout << "List is Empty" << "\n";
        return;
    }
        
    Node<T> *temp = head;   //save the current head node pointer, so it can be deleted
    head = head->next;      //make the next node as new head
    delete temp;            //delete old head
    this->length--;         //decrease the length

}

//Delete the element at End
//T(n) = O(1)
template<class T>
void LinkedList<T>::deleteFromEnd(){

    //if list is empty, deletion is not possible
    if(head == nullptr){
        std::cout << "List is Empty" << "\n";
        return;
    }
        
    Node<T> *temp = tail;   
    Node<T> *current = head;
    Node<T> *prev = head;   //we have to keep track of previous node

    //traverse until last node is found
    while (current->next != nullptr)
    {
        prev = current;
        current = current->next;
    }
    
    //set previous node of last node as tail and make it point to null
    prev->next = nullptr;
    tail = prev;
    this->length--;
    delete current; //free the memory allocated to the pointer

}

int main(){

    LinkedList<int> ll1;

    ll1.insertAtBeg(12);
    ll1.insertAtBeg(35);
    ll1.insertAtBeg(5);
    ll1.insertAtEnd(10);
    ll1.insertAtPos(50,2);

    ll1.display();
    std::cout << "Length of the list:" << ll1.len() << "\n";
    std::cout << "Element found at:" << ll1.search(35) << "\n";

    ll1.deleteFromBeg();
    ll1.deleteFromEnd();
    ll1.display();
    std::cout << "Length of the list:" << ll1.len() << "\n";

    return 0;
}