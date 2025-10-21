#include <iostream>
#include <string>
using namespace std;

struct NodeCsll
{
    int value;
    NodeCsll *next;
};

class circullarSinglyLinkedList {
private:
    NodeCsll *head, *tail, *current;
    int size;

public:
    circullarSinglyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int getSize() { return size; }

    int getHead() { return head ? head->value : -1; }

    int getTail() { return tail ? tail->value : -1; }

    // Traverse till position-1
    void _traverseTill(int pos) {
        current = head;
        for (int i = 0; i < pos - 1; i++)
            current = current->next;
    }

    void insertFront(int value) {
        NodeCsll *newNode = new NodeCsll{value, nullptr};
        if (size == 0) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
        size++;
    }

    void insertBack(int value) {
        NodeCsll *newNode = new NodeCsll{value, nullptr};
        if (size == 0) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        size++;
    }

    void insertAt(int pos, int value) {
        if (pos <= 0) {
            insertFront(value);
            return;
        }
        if (pos >= size) {
            insertBack(value);
            return;
        }

        _traverseTill(pos);
        NodeCsll *newNode = new NodeCsll{value, current->next};
        current->next = newNode;
        size++;
    }

    void deleteFront() {
        if (size == 0) {
            cout << "List is empty!\n";
            return;
        }

        NodeCsll *temp = head;
        if (size == 1) {
            head = tail = nullptr;
        } else {
            head = head->next;
            tail->next = head;
        }
        delete temp;
        size--;
    }

    void deleteEnd() {
        if (size == 0) {
            cout << "List is empty!\n";
            return;
        }

        if (size == 1) {
            deleteFront();
            return;
        }

        _traverseTill(size - 1); // current at node before tail
        NodeCsll *temp = tail;
        tail = current;
        tail->next = head;
        delete temp;
        size--;
    }

    void deleteMiddle() {
        if (size == 0) {
            cout << "List is empty!\n";
            return;
        }

        if (size == 1) {
            deleteFront();
            return;
        }

        int mid = size / 2;
        _traverseTill(mid);
        NodeCsll *temp = current->next;
        current->next = temp->next;
        if (temp == tail)
            tail = current;
        delete temp;
        size--;
    }

    void print() {
        if (size == 0) {
            cout << "List is empty!\n";
            return;
        }

        current = head;
        do {
            cout << current->value << " -> ";
            current = current->next;
        } while (current != head);
        cout << "(back to head)\n";
    }

    void swapTwoNodes(int posFirstNode, int posSecNode){
        if (size < 2)
        {
            cout << "The list is empty or has only one node!\n";
            return;
        }

        if (posFirstNode < 0 || posSecNode < 0 || posFirstNode >= size || posSecNode >= size)
        {
            cout << "Invalid positions!\n";
            return;
        }

        if (posFirstNode == posSecNode)
        {
            cout << "Positions are the same. Nothing to swap.\n";
            return;
        }

        // Ensure posFirstNode < posSecNode
        if (posFirstNode > posSecNode)
            swap(posFirstNode, posSecNode);

        NodeCsll *prev1 = nullptr, *prev2 = nullptr;
        NodeCsll *node1 = head, *node2 = head;

        // Find node1 and its previous
        if (posFirstNode != 0)
        {
            _traverseTill(posFirstNode);
            prev1 = current;
            node1 = prev1->next;
        }

        // Find node2 and its previous
        _traverseTill(posSecNode);
        prev2 = current;
        node2 = prev2->next;

        // Handle if one node is head
        if (prev1 != nullptr)
            prev1->next = node2;
        else
            head = node2;

        if (prev2 != nullptr)
            prev2->next = node1;
        else
            head = node1;

        // Swap next pointers
        NodeCsll *temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;

        // Fix tail if necessary
        if (node1 == tail)
            tail = node2;
        else if (node2 == tail)
            tail = node1;

        // Restore circular link
        tail->next = head;
    }

};  