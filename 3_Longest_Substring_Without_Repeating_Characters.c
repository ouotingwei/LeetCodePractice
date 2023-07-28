// 3. Longest Substring Without Repeating Characters
//     Given a string s, find the length of the longest 
//     substring without repeating characters.

//     Input: s = "abcabcbb"
//     Output: 3
//     Explanation: The answer is "abc", with the length of 3.

//     Input: s = "bbbbb"
//     Output: 1
//     Explanation: The answer is "b", with the length of 1.

//     Input: s = "pwwkew"
//     Output: 3
//     Explanation: The answer is "wke", with the length of 3.
//     Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


int lengthOfLongestSubstring(char* s){
    int length = strlen(s);
    int longest_substr = 0;

    for(int i = 0; i < length; i++){
        int char_index[256] = {0};

        int current_substr_len = 0;
        for(int j = i; j < length; j++){
            char current_char = s[j];
            if(char_index[current_char] == 0){
                char_index[current_char] = 1;
                current_substr_len++;
            }else {
                break;
            }
        }

        if(current_substr_len > longest_substr){
            longest_substr = current_substr_len;
        }
    }

    return longest_substr;
}
