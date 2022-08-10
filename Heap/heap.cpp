#include<iostream>
#include<vector>

#include "heap.hpp"

void swap(int &a,int &b){

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

}

void Heap::heapify(int i){
    
    int largest = i;
    int left = (2*i+1);
    int right = (2*i+2);
    int n = a.size()-1;

    if(left<=n && a[largest] < a[left])
        largest = left;    
    if(right<=n && a[largest] < a[right])
        largest = right;

    if(largest != i){
        swap(a[largest],a[i]);
        heapify(largest);
    }

}

void Heap::buildHeap(){
    int n = a.size()-1;
    for (int i = n/2; i >= 0; i--)
        heapify(i);

}

void Heap::insert(int element){

    a.push_back(element);
    int n = a.size()-1;

    while (n > 0)
    {
       int parent = (n-1)/2;
       if(a[parent] < a[n]){
            swap(a[parent],a[n]);
            n = parent;
       }
       else
            return;
    }

}

void Heap::pop(){

    int n = a.size()-1;
    a[0] = a[n];
    a.pop_back();
    n = a.size()-1;
    int i = 0;

    while (i <= n)
    {
        int left = (2*i+1);
        int right = (2*i+2);

        int larger = (left > right) ? left : right;

        if (a[i] < a[larger])
        {
            swap(a[i],a[larger]);
            i = larger;
        }
        
        else
            return;

    }

}

void Heap::display(){
    for (int i = 0; i < this->size(); i++)
        std::cout << a[i] << " ";
    std::cout << "\n";
}