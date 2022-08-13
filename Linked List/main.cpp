#include<iostream>
#include "linkedList.hpp"
#include "linkedList.cpp"

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
    ll1.deleteAValue(50);
    ll1.display();
    std::cout << "Length of the list:" << ll1.len() << "\n";

    return 0;
}