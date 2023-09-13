/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* current1 = list1;
    struct ListNode* current2 = list2;
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* mergeList = &dummy;

    struct ListNode* mer = mergeList;


    while(current1 != NULL || current2 != NULL){
        if(current1 == NULL){
            mergeList->next = current2;
            if (current2) current2 = current2->next; 
        }else if(current2 == NULL){
            mergeList->next = current1;
            if(current1) current1 = current1->next;
        }else if(current1->val <= current2->val){
            mergeList->next = current1;
            if(current1) current1 = current1->next;
        }else{
            mergeList->next = current2;
            if (current2) current2 = current2->next; 
        }

        mergeList = mergeList->next;
    }

    return mer->next;
}
