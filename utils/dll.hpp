#include <iostream>
#include <string>

using namespace std;

struct NodeDll
{
    int value;
    NodeDll *next;
    NodeDll *prev;
};

class doublyLinkedList
{
private:
    NodeDll *head, *tail, *current;
    int size;

public:
    doublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
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
        NodeDll *newNode = new NodeDll{value, nullptr, nullptr};
        
        if (size == 0)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void insertBack(int value)
    {
        if (size == 0)
        {
            insertFront(value);
            return;
        }

        NodeDll *newNode = new NodeDll{value, nullptr, tail};
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    void insertAt(int pos, int value)
    {
        if (pos <= 0)
        {
            insertFront(value);
            return;
        }

        if (pos >= size)
        {
            insertBack(value);
            return;
        }

        NodeDll *newNode = new NodeDll{value, nullptr, nullptr};
        _traverseTill(pos);
        
        newNode->next = current->next;
        newNode->prev = current;
        
        if (current->next != nullptr)
            current->next->prev = newNode;
        
        current->next = newNode;
        size++;
    }

    void insertMiddle(int value)
    {
        if (size == 0)
        {
            insertFront(value);
            return;
        }

        _traverseTill(size / 2);
        NodeDll *newNode = new NodeDll{value, nullptr, nullptr};
        
        newNode->next = current->next;
        newNode->prev = current;
        
        if (current->next != nullptr)
            current->next->prev = newNode;
        else
            tail = newNode;
        
        current->next = newNode;
        size++;
    }

    void deleteFront()
    {
        if (head == nullptr)
        {
            cout << "the list is empty!" << endl;
            return;
        }

        NodeDll *temp = head;
        head = head->next;
        
        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;
        
        delete temp;
        size--;
    }

    void deleteEnd()
    {
        if (head == nullptr)
        {
            cout << "The list is empty" << endl;
            return;
        }

        if (size == 1)
        {
            deleteFront();
            return;
        }

        NodeDll *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        size--;
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

        _traverseTill(size / 2);
        NodeDll *temp = current->next;
        
        current->next = temp->next;
        
        if (temp->next != nullptr)
            temp->next->prev = current;
        else
            tail = current;
        
        delete temp;
        size--;
    }

    void print()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        current = head;
        while (current->next)
        {
            cout << current->value << "->";
            current = current->next;
        }
        cout << current->value << endl;
    }

    void printReverse()
    {
        if (tail == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        current = tail;
        while (current->prev)
        {
            cout << current->value << "->";
            current = current->prev;
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

        // Find node1
        NodeDll *node1 = head;
        for (int i = 0; i < posFirstNode; i++)
            node1 = node1->next;

        // Find node2
        NodeDll *node2 = head;
        for (int i = 0; i < posSecNode; i++)
            node2 = node2->next;

        // Save previous and next pointers
        NodeDll *prev1 = node1->prev;
        NodeDll *next1 = node1->next;
        NodeDll *prev2 = node2->prev;
        NodeDll *next2 = node2->next;

        // Handle adjacent nodes
        if (node1->next == node2)
        {
            // node1 and node2 are adjacent
            node1->next = next2;
            node1->prev = node2;
            node2->next = node1;
            node2->prev = prev1;

            if (prev1 != nullptr)
                prev1->next = node2;
            else
                head = node2;

            if (next2 != nullptr)
                next2->prev = node1;
            else
                tail = node1;
        }
        else
        {
            // Non-adjacent nodes
            node1->next = next2;
            node1->prev = prev2;
            node2->next = next1;
            node2->prev = prev1;

            if (prev1 != nullptr)
                prev1->next = node2;
            else
                head = node2;

            if (next1 != nullptr)
                next1->prev = node2;
            else
                tail = node2;

            if (prev2 != nullptr)
                prev2->next = node1;
            else
                head = node1;

            if (next2 != nullptr)
                next2->prev = node1;
            else
                tail = node1;
        }
    }
};