#ifndef DLL_HPP
#define DLL_HPP

struct NodeDll
{
    int value;
    NodeDll* next;
    NodeDll* prev;
};

class doublyLinkedList
{
private:
    NodeDll* head;
    NodeDll* tail;
    int size;

public:
    doublyLinkedList() { head = tail = nullptr; size = 0; }
    int getSize() { return size; }
    NodeDll* getHead() { return head; }

    void insertBack(int value)
    {
        NodeDll* newNode = new NodeDll{value, nullptr, tail};
        if (!head) head = newNode;
        if (tail) tail->next = newNode;
        tail = newNode;
        size++;
    }

    void eraseGivenNode(NodeDll* node)
    {
        if (!node) return;
        if (node->prev) node->prev->next = node->next;
        else head = node->next;
        if (node->next) node->next->prev = node->prev;
        else tail = node->prev;
        delete node;
        size--;
    }
};

#endif