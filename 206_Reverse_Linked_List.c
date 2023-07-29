// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* pre = NULL;
    struct ListNode* currentNode = head;

    while(currentNode != NULL){
        struct ListNode* next = currentNode->next;
        currentNode->next = pre;
        pre = currentNode;
        currentNode = next;
    }

    return pre;
}
