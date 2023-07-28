// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
  
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int totalSize = nums1Size + nums2Size;
    int mergeArr[totalSize];
    int a = 0, b = 0;
    float med = 0.0;

    for(int i = 0; i < totalSize; i++){
        if(a < nums1Size && (b >= nums2Size || nums1[a] < nums2[b])){
            mergeArr[i] = nums1[a];
            a++;
        }else{
            mergeArr[i] = nums2[b];
            b++;
        }
    }

    if(totalSize % 2 == 0){
        med = (mergeArr[(totalSize / 2) - 1] + mergeArr[totalSize / 2]) / 2.0;
    }else{
        med = mergeArr[totalSize / 2];
    }

    return med;
}
