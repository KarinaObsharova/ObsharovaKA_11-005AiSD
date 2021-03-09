#include <iostream>

using namespace std;
struct Node {
    int value;
    Node *next = nullptr;
    Node *previous = nullptr;
};

struct LinkedListNode {
    Node *pHead = nullptr;


    void add(int item) {
        Node *node = new Node;
        node->value = item;
        if (pHead == nullptr) {
            pHead = node;
            return;
        }
        Node *tempHead = pHead;
        while (tempHead->next != nullptr) {
            tempHead = tempHead->next;
        }
        tempHead->next = node;
        node->previous = tempHead;

    }

    int get(int id) {
        int count = 0;
        int value;
        Node *tempHead = pHead;
        while (count != id) {
            count++;
            tempHead = tempHead->next;
            value = tempHead->value;
        }
        return value;
    }

    int size() {
        Node *tempHead = pHead;
        int count = 1;
        while (tempHead->next != nullptr) {
            tempHead = tempHead->next;
            count++;
        }
        return count;
    }

    void printAll() {
        Node *tempHead = pHead;
        while (tempHead != nullptr) {
            cout << tempHead->value << " ";
            tempHead = tempHead->next;
        }
    }

    void insertAt(int item, int id) {
        Node *tempHead = pHead;
        Node *newHead = new Node;
        newHead->value = item;
        int count = 0;
        while (tempHead != nullptr && id != count) {
            count++;
            tempHead = tempHead->next;
        }
        if(id == 0){
            newHead->next = pHead;
            pHead = newHead;
        } else if (id == size()) {
          add(item);
        } else {
            tempHead->previous->next = newHead;
            newHead->previous = tempHead->previous;
            tempHead->previous = newHead;
            newHead->next = tempHead;
        }




    }
    void removeAt(int id){
        Node *tempHead = pHead;
        int count = 0;
        while (tempHead != nullptr && id != count) {
            count++;
            tempHead = tempHead->next;
        }
        if(id == 0){
            pHead->next->previous = nullptr;
            pHead = pHead->next;
        } else if(id == size() -1){
            tempHead->previous->next = nullptr;
            tempHead = tempHead->previous;

        }else {
            tempHead->previous->next = tempHead->next;
            tempHead->next->previous = tempHead->previous;
        }
    }

};

int main() {
    LinkedListNode *plist = new LinkedListNode;
    plist->add(10);
    plist->add(20);
    plist->add(30);
    plist->add(40);
    plist->printAll();
    cout << " " << endl;
    cout << "Add elements: " << endl;
    plist->insertAt(100, 4);
    plist->printAll();
    cout << " " << endl;
    cout << "Remove elements: " << endl;
    plist->removeAt( 4);
    plist->printAll();
    cout << " " << endl;
    cout << "Cheek method get(1): " << plist->get(1) << endl;
    cout << "Cheek method size: " << plist->size() << endl;
    return 0;
}
