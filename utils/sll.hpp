#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using clk = chrono::high_resolution_clock;

struct NodeSll
{
    int value;
    NodeSll *next;
};

class singlyLinkedList
{
private:
    NodeSll *head, *tail, *current;
    int size;

public:
    singlyLinkedList()
    {
        head = nullptr;
        size = 0;
    }
    ~singlyLinkedList(){
        clear();
    }

    void clear(){
        while(!empty()){
            deleteFront();
        }
    }

    bool empty(){
        return size==0;
    }

    int getSize() { return size; }

    int getTail() { return tail->value; }

    int getHead() { return head->value; }

    void _travers()
    {
        current = head;
        while (current->next) {
            current = current->next;
            if (current==nullptr) current = head;
        }
    }

    void _traverseTill(int pos)
    {
        current = head;
        for (int i = 0; i < pos - 1; i++)
        {
            current = current->next;
            if (current==nullptr) current = head;
        }
    }

    void insertFront(int value)
    {
        NodeSll *newNode = new NodeSll{value, nullptr};
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

        NodeSll *newNode = new NodeSll{value, nullptr};
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

        NodeSll *newNode = new NodeSll{value, nullptr};
        NodeSll *temp;
        _traverseTill(pos);
        temp = current->next;
        current->next = newNode;
        newNode->next = temp;
        size++;
    }

    void insertMiddle(int value)
    {
        _traverseTill(size / 2);
        NodeSll *newNode = new NodeSll{value, nullptr};
        NodeSll *temp;
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

        NodeSll *temp;
        temp = head;
        head = head->next;
        delete temp;
        size--;
        if (head == nullptr)
            tail = nullptr;
    }

    void deleteEnd()
    {
        if (size==0)
        {
            cout << "The list is empty" << endl;
            return;
        }
        current=head;
        NodeSll *temp;
        temp = tail;
        while(current->next->next!=nullptr){
            current=current->next;
        }
        delete temp;
        tail = current;
        tail->next=nullptr;
        --size;
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

        NodeSll *temp;
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

        NodeSll *prev1 = nullptr;
        NodeSll *node1 = head;
        if (posFirstNode > 0)
        {
            _traverseTill(posFirstNode);
            prev1 = current;
            node1 = prev1->next;
        }

        NodeSll *prev2 = nullptr;
        NodeSll *node2 = head;
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
        NodeSll *temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;

        // Update tail if needed
        if (node1->next == nullptr)
            tail = node1;
        else if (node2->next == nullptr)
            tail = node2;
    }

    void rotateRight(int k) {
        if (size == 0 || k % size == 0) return;

        k = k % size;
        int splitPoint = size - k - 1;

        NodeSll *newTail = head;
        for (int i = 0; i < splitPoint; i++)
            newTail = newTail->next;

        NodeSll *newHead = newTail->next;
        tail->next = head;
        newTail->next = nullptr; 
        head = newHead;
        tail = newTail;
    }
    void insert_front_onlyhead(int value){
        NodeSll* n=new NodeSll{value,nullptr};
        n->next=head;    
        head=n;
        size++;
    }

    // void insertBack(int value){
    //     NodeSll* newNode = new NodeSll{value, nullptr};
    //     if (!head)
    //     {
    //         head = tail = newNode;
    //     }
    //     else
    //     {
    //         tail->next = newNode;
    //         tail = newNode;
    //     }
    //     size++;
    // }

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


    void remove_front_onlyhead(){
        NodeSll* temp=head;
        head=head->next;
        delete temp;
        size--;
    }

    void remove_end_onlyhead(){
        current=head;
        while(current->next->next!=nullptr){
            current=current->next;
        }
        delete current->next;
        tail=current;
        tail->next=nullptr;
        size--;



    }
    void insert_end_onlyhead(int value){
        NodeSll* n=new NodeSll{value,nullptr};
        _travers();
          current->next=n;
          size++;


    }

    

};

void sll_observe(singlyLinkedList* obj, void(singlyLinkedList::*method)(int value), string msg, int value){
    auto t0 = clk::now();

    (obj->*method)(value); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" << endl;
}