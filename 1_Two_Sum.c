/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* ans = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int tempSum = nums[i];
        ans[0] = i;

        for (int j = 0; j < numsSize; j++) {
            if (target >= 0 && tempSum > target){
                break;
            } else if(target < 0 && tempSum < target) {
                break;
            }
            
            if (i != j) {
                tempSum += nums[j];
                if (tempSum != target) {
                    tempSum = tempSum - nums[j];
                } else {
                    ans[1] = j;
                    *returnSize = 2;
                    return ans;
                }
            }
        }
    }

    free(ans);
    *returnSize = 0;
    return NULL; 
}
