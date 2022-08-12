#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_


#include<iostream>

template<class T>
class Node{

    public:
        T value = 0;
        Node<T> *next = nullptr;

        Node(){}
        Node(T val){this->value = val;}
        Node(T value,Node next){
            this->value = value;
            this->next = &next;
        }

};

template<class T>
class LinkedList{

    private:
        int length;

    public:
        Node<T> *head;
        Node<T> *tail;

        LinkedList(){
            length = 0;
            head = nullptr;
            tail = nullptr;
        }

        int len(){return length;}   //returns length
        void display();     //prints entire list;

        //insertion operations
        void insertAtBeg(T element);    
        void insertAtEnd(T element);
        void insertAtPos(T element,int position);

        int search(T element);  //searching an element

        //deletion operations
        void deleteFromBeg();
        void deleteFromEnd();
        void deleteAValue(T val);

};



#endif