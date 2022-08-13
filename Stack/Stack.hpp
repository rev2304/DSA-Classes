#ifndef _STACK_HPP
#define _STACK_HPP

template<class T>
class Node{

    public:
        T data;
        Node *next;

    Node(){

    }   
    Node(int el){
        this->data = el;
        this->next = nullptr;
    } 

};

template<class T>
class Stack{

    private:
        Node<T> *head;
        int len;

    public:
        Stack(){
            head = nullptr;
            len = 0;
        }

        int size(){
            return this->len;
        }

        bool isEmpty(){
            return !head;
        }

        void push(T element); 
        T pop();
        T top();    

};

#endif