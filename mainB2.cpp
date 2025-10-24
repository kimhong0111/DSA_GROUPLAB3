#include "utils/sll.hpp"
#include <vector>

using namespace std::chrono;

void dynamicArray(int size) {
    vector<int> stack;
    stack.reserve(100);
    auto start = high_resolution_clock::now();

    for (int i=0;i<size;i++) {
        if (i%5==4&&!stack.empty()) {
            stack.pop_back();
        } else {
            stack.push_back(i);
        }
    }

    auto end =high_resolution_clock::now();
    cout << "Time taken: " << duration_cast<nanoseconds>(end-start).count() << " nanosecond(s)";
}

int main() {
    singlyLinkedList list1;

    sll_observe(&list1, &singlyLinkedList::undoHistory, "Time Taken", 999);

    dynamicArray(10000);
}