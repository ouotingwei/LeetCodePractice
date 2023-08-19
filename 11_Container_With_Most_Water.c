int maxArea(int* height, int heightSize) {
    int max_con = 0;
    int left = 0;
    int right = heightSize - 1;

    while (left < right) {
        int min_height = height[left] < height[right] ? height[left] : height[right];
        int temp_con = min_height * (right - left);

        if (temp_con > max_con) {
            max_con = temp_con;
        }

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_con;
}
