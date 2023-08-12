// Given an integer x, return true if x is a palindrome, and false otherwise.

bool isPalindrome(int x){
    if(x < 0){
        return false;
    }

    int rev_x = 0;
    int x_cp = x;
    int digit = 0;
    while(x_cp >= 1){
        if (rev_x > (INT_MAX - (x_cp % 10)) / 10) {
            return false;
        }
        
        rev_x = rev_x * 10 + (x_cp%10);
        x_cp = x_cp / 10;
        digit++;
    }

    if(digit == 1){
        return true;
    }

    for(int i = digit-1; i > 0; i--){
        if(rev_x / pow(10, i) != x/pow(10, i)){
            return false;
        }

        rev_x = rev_x % (int)pow(10, i);
        x = x % (int)pow(10, i);
    }

    return true;
}
