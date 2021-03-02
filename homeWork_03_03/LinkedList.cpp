#include <iostream>

using namespace std;
struct Node {
    int value;
    Node *next = nullptr;
};

struct linkedList {

    Node *pHead = nullptr;

    void add(int item) {
        Node *node = new Node;
        node->value = item;
        if (pHead == nullptr) {
            pHead = node;
            return;
        }
        Node *temp = pHead;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = node;
    }

    int get(int id) {
        int count = 0;
        int value;
        Node *temp = pHead;
        while (count != id) {
            count++;
            temp = temp->next;
            value = temp->value;
        }

        return value;
    }

    int size() {
        Node *temp = pHead;
        int count = 1;
        while (temp->next != nullptr) {
            temp = temp->next;
            count++;
        }
        delete temp;
        return count;
    }

    void printAll() {
        Node *temp = pHead;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
    }


};

int main() {
    linkedList *plist = new linkedList;
    plist->add(10);
    plist->add(20);
    plist->add(30);
    plist->add(40);
    plist->printAll();
    cout << " " << endl;
    cout << "Cheek method get(1): " << plist->get(1) << endl;
    cout << "Cheek method size: " << plist->size() << endl;
    return 0;
}
