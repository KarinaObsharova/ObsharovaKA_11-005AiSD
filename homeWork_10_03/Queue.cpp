#include <iostream>

using namespace std;
struct Node {
    int value;
    Node *next = nullptr;
    Node *prev = nullptr;
};

struct Queue {
    Node *pHead = nullptr;

    void Enqueue(int item) {
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
        node->prev = tempHead;
        tempHead->next = node;
        tempHead = node;

    }
    void Dequeue(){
        pHead = pHead->next;
    }
    void printAll() {
        Node *pTempHead = pHead;
        while (pHead != nullptr) {
            cout << pHead->value << " ";
            pHead = pHead->next;
        }
        pHead = pTempHead;
    }

};
int main() {
    Queue *pQueue = new Queue;
    pQueue->Enqueue(10);
    pQueue->Enqueue(20);
    pQueue->Enqueue(30);
    pQueue->Enqueue(40);
    pQueue->printAll();
    pQueue->Dequeue();
    cout << " " << endl;
    pQueue->printAll();




    return 0;
}
