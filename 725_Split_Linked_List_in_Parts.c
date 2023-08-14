/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize){
    int len = 0;
    struct ListNode *current = head;
    while(current != NULL){
        len++;
        current = current->next;
    }

    int base_size = len / k;
    int extra = len % k;
    struct ListNode** result = (struct ListNode**)malloc(k * sizeof(struct ListNode*));
    *returnSize = k;

    current = head;
    for(int i = 0; i < k; i++){
        struct ListNode *Part_H = current;
        struct ListNode *prev = NULL;
        int partSize = base_size + (i < extra ? 1:0);
        for(int j = 0; j < partSize; j++){
            prev = current;
            current = current ? current->next : NULL;
        }

        if(prev){
            prev->next = NULL;
        }
        
        result[i] = Part_H;
    }

    return result;
}
