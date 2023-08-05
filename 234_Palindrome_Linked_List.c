// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
// 
// Input: head = [1,2,2,1]
// Output: true
//
// Input: head = [1,2]
// Output: false

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
bool isPalindrome(struct ListNode* head){
    if (head == NULL || head->next == NULL) return true;

    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    //  len = odd
    if (fast != NULL) {
        slow = slow->next;
    }

    struct ListNode* back_half = reverseList(slow);
    struct ListNode* front_half = head;
    while(back_half != NULL){
        if(front_half->val != back_half->val) return false;
        front_half = front_half->next;
        back_half = back_half->next;
    }

    return true;
}
