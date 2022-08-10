#ifndef _HEAP_HPP_
#define _HEAP_HPP_

#include<vector>

class Heap
{
private:
    /* data */
    std::vector<int> a;

    /*methods*/
    void heapify(int i);  //maintain max heap property
    void buildHeap();     //bulid heap from initially passed array


public:
    /*constructors*/

    Heap(){}
    Heap(std::vector<int> &a){
        this->a = a;
        buildHeap();
    }

    /*methods*/


    int size(){return a.size();}    
    int top(){return a[0];}     //returns element having maximum value
    void insert(int element);  
    void pop();
    void display();
    
};


#endif