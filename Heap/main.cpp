#include<iostream>
#include<vector>

#include "heap.hpp"

int main(){

    std::vector<int> a{20,5,10,30,50};

    Heap h1(a);

    h1.display();

    h1.insert(12);

    return 0;

}