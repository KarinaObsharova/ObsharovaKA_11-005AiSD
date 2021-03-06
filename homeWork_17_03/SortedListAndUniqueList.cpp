#include <iostream>

using namespace std;
struct Node {
    int value;
    Node *next = nullptr;
    Node *previous = nullptr;
};

struct SortedList {
    Node *pHead = nullptr;


    void add(int item) {
        int count = 0;
        Node *node = new Node;
        node->value = item;
        if (pHead == nullptr) {
            pHead = node;
            return;
        }
        Node *tempHead = pHead;
        while (tempHead->next != nullptr) {
            if (node->value > tempHead->value) {
                tempHead = tempHead->next;
                count++;
            } else break;
        }
        if (node->value <= tempHead->value) {
            if (count == 0) {
                node->next = pHead;
                pHead = node;
            } else {
                tempHead->previous->next = node;
                node->previous = tempHead->previous;
                tempHead->previous = node;
                node->next = tempHead;
            }
        } else {
            tempHead->next = node;
            node->previous = tempHead;
            count = 0;
        }
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


    void remove(int id) {
        Node *tempHead = pHead;
        int count = 0;
        while (tempHead != nullptr && id != count) {
            count++;
            tempHead = tempHead->next;
        }
        if (id == 0) {
            pHead->next->previous = nullptr;
            pHead = pHead->next;
        } else if (id == size() - 1) {
            tempHead->previous->next = nullptr;
            tempHead = tempHead->previous;

        } else {
            tempHead->previous->next = tempHead->next;
            tempHead->next->previous = tempHead->previous;
        }
    }


    void UniqueAdd(int item) {
        int count = 0;
        Node *node2 = new Node;
        node2->value = item;
        if (pHead == nullptr) {
            pHead = node2;
            return;
        }
        Node *tempHead = pHead;

        while (tempHead->next != nullptr) {
            if (node2->value > tempHead->value) {
                tempHead = tempHead->next;
                count++;
            } else break;
        }
        if (node2->value < tempHead->value) {
            if (count == 0) {
                node2->next = pHead;
                pHead = node2;
            } else {
                tempHead->previous->next = node2;
                node2->previous = tempHead->previous;
                tempHead->previous = node2;
                node2->next = tempHead;
            }
        } else if (node2->value != tempHead->value) {
            tempHead->next = node2;
            node2->previous = tempHead;
            count = 0;
        }

    }
};

SortedList *Union(SortedList *a, SortedList *b) {
    SortedList *unionList = new SortedList;
    Node *temp = a->pHead;
    Node *temp2 = b->pHead;
    while (temp != nullptr && temp2 != nullptr) {
        if (temp->value < temp2->value) {
            unionList->add(temp->value);
            temp = temp->next;
        } else if (temp->value == temp2->value) {
            unionList->add(temp2->value);
            temp2 = temp2->next;
            temp = temp->next;
        } else {
            unionList->add(temp2->value);
            temp2 = temp2->next;
        }

    }
    return unionList;
}

SortedList *Intersect(SortedList *a, SortedList *b) {
    SortedList *intersectList = new SortedList;
    Node *temp = a->pHead;
    Node *temp2 = b->pHead;
    while (temp != nullptr && temp2 != nullptr) {
        if (temp->value == temp2->value) {
            intersectList->add(temp->value);
            temp2 = temp2->next;

        } else if (temp->value < temp2->value)
            temp = temp->next;
        else temp2 = temp2->next;

    }
    return intersectList;

}

SortedList *Difference(SortedList *a, SortedList *b) {
    SortedList *differenceList = new SortedList;
    Node *temp = a->pHead;
    Node *temp2 = b->pHead;
    while (temp != nullptr && temp2 != nullptr) {
        if (temp->value == temp2->value) {
            temp = temp->next;

        } else if (temp->value > temp2->value)
            temp2 = temp2->next;
        else {
            differenceList->add(temp->value);
            temp = temp->next;
        }
    }
    return differenceList;
}

void printAll(SortedList *a) {
    Node *tempHead = a->pHead;
    while (tempHead != nullptr) {
        cout << tempHead->value << " ";
        tempHead = tempHead->next;
    }
}


int main() {
    SortedList *plist = new SortedList;
    cout << "Add elements in Sortedlist:   5, 10, 100, 21, 30, 31 " << endl;
    cout << "Sortedlist: ";

    plist->add(5);
    plist->add(10);
    plist->add(100);
    plist->add(21);
    plist->add(30);
    plist->add(31);
    printAll(plist);
    cout << " " << endl;
    cout << " " << endl;


    SortedList *pUniqueList = new SortedList;
    cout << "Add elements in UniqueList:  10, 65, 20, 20, 65, 16 " << endl;
    cout << "UniqueList: ";

    pUniqueList->UniqueAdd(10);
    pUniqueList->UniqueAdd(65);
    pUniqueList->UniqueAdd(20);
    pUniqueList->UniqueAdd(20);
    pUniqueList->UniqueAdd(65);
    pUniqueList->UniqueAdd(16);
    pUniqueList->UniqueAdd(15);
    printAll(pUniqueList);
    cout << " " << endl;
    cout << " " << endl;

    SortedList *pUniqueList2 = new SortedList;
    cout << "Add elements in UniqueList:  20, 26, 65, 20, 45, 30, 16 " << endl;
    cout << "UniqueList: ";

    pUniqueList2->UniqueAdd(20);
    pUniqueList2->UniqueAdd(26);
    pUniqueList2->UniqueAdd(65);
    pUniqueList2->UniqueAdd(20);
    pUniqueList2->UniqueAdd(45);
    pUniqueList2->UniqueAdd(30);
    pUniqueList2->UniqueAdd(16);
    printAll(pUniqueList2);

    cout << " " << endl;
    cout << " " << endl;

    cout << "list1: ";
    printAll(pUniqueList);
    cout << " " << endl;

    cout << "list2: ";
    printAll(pUniqueList2);
    cout << " " << endl;

    cout << "Union: " << endl;
    printAll(Union(pUniqueList, pUniqueList2));
    cout << " " << endl;

    cout << "Intersect: " << endl;
    printAll(Intersect(pUniqueList, pUniqueList2));
    cout << " " << endl;

    cout << "Difference: " << endl;
    printAll(Difference(pUniqueList, pUniqueList2));

    return 0;
}

