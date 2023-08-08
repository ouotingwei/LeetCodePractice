// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
// 
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

int reverse(int x){
    int rev_num = 0;

    while(x != 0){
        int temp = x%10;
        x = x/10;
        if (rev_num > INT_MAX / 10 || (rev_num == INT_MAX / 10 && temp > 7)) return 0;
        if (rev_num < INT_MIN / 10 || (rev_num == INT_MIN / 10 && temp < -8)) return 0;
        rev_num = rev_num*10 + temp;
    }

    return rev_num;
}
