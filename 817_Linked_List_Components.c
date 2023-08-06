// You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.
// 
// Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.
// 
// [exp1]
// Input: head = [0,1,2,3], nums = [0,1,3]
// Output: 2
// Explanation: 0 and 1 are connected, so [0, 1] and [3] are the two connected components.
// 
// [exp2]
// Input: head = [0,1,2,3,4], nums = [0,3,1,4]
// Output: 2
// Explanation: 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.

int numComponents(struct ListNode* head, int* nums, int numsSize){
    int num_of_set = 0;
    for(int i = 0; i < numsSize; i++){
        struct ListNode *current = head;
        while(current != NULL){
            if(current->val == nums[i]){
               current->val = -1;
            }
            current = current->next;
        }
    }
    
    bool wasInComponent = false; 
    while(head != NULL){
        if(head->val == -1){
            if(!wasInComponent){
                num_of_set++;
                wasInComponent = true;
            }
        } else {
            wasInComponent = false;
        }
        head = head->next;
    }

    return num_of_set;
}
