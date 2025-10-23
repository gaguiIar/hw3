#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    if (head == nullptr) {
        smaller = larger = nullptr;
        return;
    }
    Node* current_node = head;
    Node* everything_else = head->next;
    current_node->next = nullptr;
    llpivot(everything_else, smaller, larger, pivot);

    if(current_node->val <= pivot) {
        current_node-> next = smaller;
        smaller = current_node;
    }
    else {
        current_node-> next = larger;
        larger = current_node;
    }
    head=nullptr;
}