void removeSubstring(char *str, const char *substr) {
    while (str && (str = strstr(str, substr))) {
        size_t len = strlen(substr);
        memmove(str, str + len, strlen(str + len) + 1); 
    }
}

int romanToInt(char * s){
    int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *syms[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int num = 0;

    for(int i = 0; i < 13; i++){
        char *substr = syms[i];
        while (strstr(s, substr) == s) {
            s += strlen(substr);
            num += val[i];
        }
    }

    return num;
}
