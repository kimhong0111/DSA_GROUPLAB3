#ifndef SLL_HPP
#define SLL_HPP

struct NodeSll
{
    int value;
    NodeSll* next;
};

class singlyLinkedList
{
private:
    NodeSll* head;
    NodeSll* tail;
    NodeSll* current;
    int size;

public:
    singlyLinkedList() { head = nullptr; tail = nullptr; size = 0; }
    int getSize() { return size; }
    NodeSll* getHead() { return head; }

    void insertBack(int value)
    {
        NodeSll* newNode = new NodeSll{value, nullptr};
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void eraseGivenNodeWithPrev(NodeSll* prev, NodeSll* node)
    {
        if (!node) return;
        if (!prev) head = node->next;
        else prev->next = node->next;
        if (node == tail) tail = prev;
        delete node;
        size--;
    }

    void eraseGivenNodeNoPrev(NodeSll* node)
    {
        if (!node || !head) return;
        if (node == head) { head = head->next; delete node; size--; return; }
        NodeSll* cur = head;
        while (cur && cur->next != node) cur = cur->next;
        if (cur)
        {
            cur->next = node->next;
            if (node == tail) tail = cur;
            delete node;
            size--;
        }
    }
};

#endif