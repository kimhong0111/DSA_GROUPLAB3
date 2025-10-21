#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int value;
    Node *next;
};

class singlyLinkedList
{
private:
    Node *head, *tail, *current;
    int size;

public:
    singlyLinkedList()
    {
        head = nullptr;
        size = 0;
    }

    int getSize() { return size; }

    int getTail() { return tail->value; }

    int getHead() { return head->value; }

    void _travers()
    {
        current = head;
        while (current->next)
            current = current->next;
    }

    void _traverseTill(int pos)
    {
        current = head;
        for (int i = 0; i < pos - 1; i++)
        {
            current = current->next;
        }
    }

    void insertFront(int value)
    {
        Node *newNode = new Node{value, nullptr};
        newNode->next = head;
        head = newNode;
        if (size == 0)
            tail = newNode;
        size++;
    }

    void insertBack(int value)
    {
        if (size == 0)
        {
            insertFront(value);
            return;
        }

        Node *newNode = new Node{value, nullptr};
        tail->next = newNode;
        size++;
        tail = newNode;
    }

    void insertAt(int pos, int value)
    {
        if (pos == 0)
        {
            insertFront(value);

            return;
        }

        if (pos >= size)
        {
            insertBack(value);
            return;
        }

        Node *newNode = new Node{value, nullptr};
        Node *temp;
        _traverseTill(pos);
        temp = current->next;
        current->next = newNode;
        newNode->next = temp;
        size++;
    }

    void insertMiddle(int value)
    {
        _traverseTill(size / 2);
        Node *newNode = new Node{value, nullptr};
        Node *temp;
        temp = current->next;
        current->next = newNode;
        newNode->next = temp;
        size++;
    }

    void deleteFront()
    {
        if (head == nullptr)
        {
            cout << "the list is empty!" << endl;
            return;
        }

        Node *temp;
        temp = head;
        head = head->next;
        delete temp;
        size--;
        if (head == nullptr)
            tail = nullptr;
    }

    void deleteEnd()
    {
        if (head == 0)
        {
            cout << "The list is empty" << endl;
            return;
        }

        Node *temp;
        temp = tail;
        _traverseTill(size);
        tail = current;
        delete temp;
    }

    void deleteMiddle()
    {
        if (head == nullptr)
        {
            cout << "the list is empty" << endl;
            return;
        }

        if (size == 1)
        {
            deleteFront();
            return;
        }

        Node *temp;
        _traverseTill(size / 2);
        temp = current->next;
        current->next = temp->next;
        if (temp == tail)
            tail = current;
        delete temp;
        size--;
    }

    void print()
    {
        current = head;
        while (current->next)
        {
            cout << current->value << "->";
            current = current->next;
        }

        cout << current->value << endl;
    }

    void swapTwoNodes(int posFirstNode, int posSecNode)
    {
        if (head == nullptr || size < 2)
        {
            cout << "The list is empty or has only one node!" << endl;
            return;
        }

        if (posFirstNode < 0 || posSecNode < 0 || posFirstNode >= size || posSecNode >= size)
        {
            cout << "Invalid positions!" << endl;
            return;
        }

        if (posFirstNode == posSecNode)
        {
            cout << "Positions are the same, nothing to swap." << endl;
            return;
        }

        // Ensure posFirstNode < posSecNode
        if (posFirstNode > posSecNode)
            swap(posFirstNode, posSecNode);

        Node *prev1 = nullptr;
        Node *node1 = head;
        if (posFirstNode > 0)
        {
            _traverseTill(posFirstNode);
            prev1 = current;
            node1 = prev1->next;
        }

        Node *prev2 = nullptr;
        Node *node2 = head;
        if (posSecNode > 0)
        {
            _traverseTill(posSecNode);
            prev2 = current;
            node2 = prev2->next;
        }

        // If one of them is the head
        if (prev1 != nullptr)
            prev1->next = node2;
        else
            head = node2;

        if (prev2 != nullptr)
            prev2->next = node1;
        else
            head = node1;

        // Swap next pointers
        Node *temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;

        // Update tail if needed
        if (node1->next == nullptr)
            tail = node1;
        else if (node2->next == nullptr)
            tail = node2;
    }

};