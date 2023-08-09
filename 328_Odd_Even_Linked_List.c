// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
// 
// The first node is considered odd, and the second node is even, and so on.
// 
// Note that the relative order inside both the even and odd groups should remain as it was in the input.
// 
// You must solve the problem in O(1) extra space complexity and O(n) time complexity.
// 
// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* create_node(int num){
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = num;
    newnode->next = NULL;
    return newnode;
}

void insert_tail(struct ListNode** n, int num){
    struct ListNode* newnode = create_node(num);
    if (*n == NULL) {
        *n = newnode;
        return;
    }

    struct ListNode* temp = *n;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
}

struct ListNode* oddEvenList(struct ListNode* head){
    struct ListNode* odd = NULL;
    struct ListNode* even = NULL;
    int cnt = 0;
    while(head != NULL){
        if(cnt %2 == 1){
            insert_tail(&odd, head->val);
        }else{
            insert_tail(&even, head->val);
        }

        head = head->next;
        cnt++;
    }

    if (even == NULL) {
        return odd;
    }

    struct ListNode* temp = even;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = odd;
    return even;
}
