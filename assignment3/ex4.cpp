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
    
};




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
void insert_node(SinglyLinkedList* ll, int node_data) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

    if (!ll->head) {
        ll->head = node;
    } else {
        ll->tail->next = node;
        }

    ll->tail = node;
}

void printLinkedList(SinglyLinkedList* ll) {
    SinglyLinkedListNode* head = ll -> head;
    while (head != NULL){
        cout<< head->data << ' ';
        head = head->next;
    }
}

void reverseLinkedList(SinglyLinkedList *ll) {
    int v[100000] = {};
    int c = 0;
    SinglyLinkedListNode* node = ll -> head;
    while (node) {
        v[c] = node -> data;
        node = node -> next;
        c++;
    }
    node = ll -> head;
    for (int i = c - 1; i >= 0; i--) {
        node -> data = v[i];
        node = node -> next;
    }
}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }
    
    
    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
