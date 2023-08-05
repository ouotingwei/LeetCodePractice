// Given a string s, return the longest palindromic substring in s.
//   
// Example 1:
// 
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// 
// Example 2:
// 
// Input: s = "cbbd"
// Output: "bb"

int* expand(char *s, int left, int right){
    int *match = (int*) malloc(3 * sizeof(int));
    match[0] = left;
    match[1] = right;
    match[2] = 0;
    while(left >= 0 && right < strlen(s) && s[left] == s[right]){
        match[0] = left;
        match[1] = right;
        match[2] = right-left+1;
        left--;  
        right++;
    }

    return match;
}

char* longestPalindrome(char *s){
    int len_s = strlen(s);
    int longist = 0;
    int ans[3] = {0};

    if(len_s < 2){
        return s;
    }

    for(int i = 0; i < len_s; i++){
        int* odd_match = expand(s, i, i);
        if(odd_match[2] > longist){
            longist = odd_match[2];
            for(int j = 0; j < 3; j++){
                ans[j] = odd_match[j];
            }
        }
        free(odd_match); 

        int* even_match = expand(s, i, i+1);
        if(even_match[2] > longist){
            longist = even_match[2];
            for(int j = 0; j < 3; j++){
                ans[j] = even_match[j];
            }
        }
        free(even_match); 
    }

    char *longest_substring = (char*) malloc((longist + 1) * sizeof(char));
    strncpy(longest_substring, s + ans[0], longist);    // strncpy(pointer, pointer, int)
    longest_substring[longist] = '\0';

    return longest_substring;
}
