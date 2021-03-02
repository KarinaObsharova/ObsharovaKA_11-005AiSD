#include <iostream>

using namespace std;
struct Node {
    int value;
    Node *next = nullptr;
};

struct Stack {
    Node *pHead = nullptr;

    void Push(int value) {
        Node *node = new Node;
        node->value = value;
        node->next = pHead;
        pHead = node;
    }

    int Pop() {
        Node * temp = pHead;
        int value = temp->value;
        pHead = temp->next;
        delete temp;
        return value;
    }

    int Peek() {
        return pHead->value;

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
    Stack *pStack = new Stack;
    pStack->Push(10);
    pStack->Push(20);
    pStack->Push(30);
    pStack->Push(40);
    pStack->printAll();
    cout << " " << endl;
    cout << "Cheek method pop: " << pStack->Pop() << endl;
    cout << "Cheek method peek: " << pStack->Peek() << endl;


    return 0;
}
