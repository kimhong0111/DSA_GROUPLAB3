#include <iostream>
#include <chrono>
#include "utils/sll.hpp"
#include "utils/dll.hpp"

using namespace std;
using namespace chrono;

int main()
{
    const int n = 10000;
    const int trials = 5;

    double dllTime = 0, sllKnownTime = 0, sllUnknownTime = 0;

    for (int t = 0; t < trials; t++)
    {
        // --- DLL test ---
        doublyLinkedList dll;
        for (int i = 0; i < n; i++) dll.insertBack(i);

        NodeDll* dnode = dll.getHead();
        for (int i = 0; i < n/2; i++) dnode = dnode->next;

        auto t0 = high_resolution_clock::now();
        dll.eraseGivenNode(dnode);
        auto t1 = high_resolution_clock::now();
        dllTime += duration<double, nano>(t1 - t0).count();

        // --- SLL with known predecessor ---
        singlyLinkedList sll1;
        for (int i = 0; i < n; i++) sll1.insertBack(i);

        NodeSll* cur = sll1.getHead();
        NodeSll* prev = nullptr;
        for (int i = 0; i < n/2; i++)
        {
            prev = cur;
            cur = cur->next;
        }

        auto t2 = high_resolution_clock::now();
        sll1.eraseGivenNodeWithPrev(prev, cur);
        auto t3 = high_resolution_clock::now();
        sllKnownTime += duration<double, nano>(t3 - t2).count();

        // --- SLL without predecessor ---
        singlyLinkedList sll2;
        for (int i = 0; i < n; i++) sll2.insertBack(i);

        cur = sll2.getHead();
        for (int i = 0; i < n/2; i++) cur = cur->next;

        auto t4 = high_resolution_clock::now();
        sll2.eraseGivenNodeNoPrev(cur);
        auto t5 = high_resolution_clock::now();
        sllUnknownTime += duration<double, nano>(t5 - t4).count();
    }

    cout << "Average times over " << trials << " trials (nanoseconds):\n";
    cout << "DLL erase middle node: " << dllTime/trials << " ns\n";
    cout << "SLL erase known predecessor: " << sllKnownTime/trials << " ns\n";
    cout << "SLL erase unknown predecessor: " << sllUnknownTime/trials << " ns\n";

    return 0;
}