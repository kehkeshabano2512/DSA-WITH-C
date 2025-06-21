// deletion in Linked List.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL; // Initialize head to NULL

// Function to insert a node at the end
void insertAtEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node at the beginning
void deleteAtBeginning() {
    if (head == NULL) {
        cout << "The list is empty, deletion not possible.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "Node deleted from the beginning.\n";
}

// Function to delete a node at the end
void deleteAtEnd() {
    if (head == NULL) {
        cout << "The list is empty, deletion not possible.\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Node deleted from the end.\n";
        return;
    }
    
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    delete temp->next;
    temp->next = NULL;
    cout << "Node deleted from the end.\n";
}

// Function to delete a node after a given node
void deleteAfterNode(int afterVal) {
    Node* temp = head;
    while (temp != NULL && temp->data != afterVal) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        cout << "Node not found or no node after the given value.\n";
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
    cout << "Node deleted after " << afterVal << ".\n";
}

// Function to traverse and display the linked list
void traverse() {
    if (head == NULL) {
        cout << "The list is empty.\n";
        return;
    }
    
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, val, afterVal;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at end\n";
        cout << "2. Delete at beginning\n";
        cout << "3. Delete at end\n";
        cout << "4. Delete after a given node\n";
        cout << "5. Traverse the list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at end: ";
                cin >> val;
                insertAtEnd(val);
                break;
            case 2:
                deleteAtBeginning();
                break;
            case 3:
                deleteAtEnd();
                break;
            case 4:
                cout << "Enter the value after which you want to delete: ";
                cin >> afterVal;
                deleteAfterNode(afterVal);
                break;
            case 5:
                traverse();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

