#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

void printLinkedList(SinglyLinkedListNode* head) {
    while (head != NULL){
        cout<< head->data << ' ';
        head = head->next;
    }
}


// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertSortedLinkedList(SinglyLinkedListNode* head, int x) {
    if (!head) {
        SinglyLinkedListNode* newnode = new SinglyLinkedListNode(x);
        return newnode;
    }
    SinglyLinkedListNode* temp = head;
    SinglyLinkedListNode* prev = head;
    while (temp -> data < x) {
        if (temp -> next) {
            prev = temp;
            temp = temp -> next;
        }
        else
            break;
    }
    if (temp -> next || !(temp -> next) && temp -> data > x) {
        temp = prev;
    }

    if (head == temp && head -> data > x) {
        SinglyLinkedListNode* newnode = new SinglyLinkedListNode(x);
        newnode -> next = head;
        return newnode;
    }

    SinglyLinkedListNode* newnode = new SinglyLinkedListNode(x);
    if (temp -> next) {
        newnode -> next = temp -> next;
        temp -> next = newnode;
    } else {
        temp -> next = newnode;
    }
    return head;
}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;
    int x;

    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }
    cin >> x;
    llist->head = insertSortedLinkedList(llist->head, x);
    printLinkedList(llist->head);

    return 0;
}
