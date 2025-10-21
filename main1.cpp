#include <iostream>
#include "utils/csll.hpp"
#include "utils/sll.hpp"

using namespace std;

int main() {
    // circullarSinglyLinkedList list1;
    singlyLinkedList list2;
    for (int i=0;i<1000;i++) {
        // list1.insertFront(i);
        list2.insertFront(i);
    }

    // csll_observe(&list1, &circullarSinglyLinkedList::_traverseTill, "Time taken", 999);
    sll_observe(&list2, &singlyLinkedList::_traverseTill, "Time Taken", 999);
}