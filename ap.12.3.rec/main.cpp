#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void printList(Node* head) {
    if (!head) {
        std::cout << std::endl;
        return;
    }
    std::cout << head->data << " ";
    printList(head->next);
}

void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

int countElementsWithValue(Node* head, int value) {
    if (!head) {
        return 0; 
    }
    if (head->data == value) {
        return 1 + countElementsWithValue(head->next, value); 
    }
    return countElementsWithValue(head->next, value);
}

int main() {
    Node* head = nullptr;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 1);
    insert(head, 4);
    insert(head, 5);
    insert(head, 1);

    std::cout << "List: ";
    printList(head);

    int valueToFind = 1;
    int count = countElementsWithValue(head, valueToFind);
    std::cout << "Number of elements with value " << valueToFind << ": " << count << std::endl;

    return 0;
}
