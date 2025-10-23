#include "utils/cdll.hpp"
#include "utils/sll.hpp"
#include "utils/csll.hpp"
#include "utils/dll.hpp"
#include <chrono>

using namespace std;
using clk = chrono::high_resolution_clock;

int main() {
    circullarSinglyLinkedList list;

    for(int i = 100; i > 0; i--) list.insertFront(i);

        list.print();

    auto t0 = clk::now();

    list.rotateRight(list.getSize()-1);

    auto t1 = clk::now();

    list.print();

    cout<<"the head of the list is : "<< list.getHead()<< endl;
    cout<<"the tail of the list is : "<<list.getTail()<<endl;
    cout<<"the size of the list is : "<<list.getSize()<< endl;
    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<duration.count() <<" nanosecond(s)" << endl;
    return 0;
}