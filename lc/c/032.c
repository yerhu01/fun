bool isPalindrome(char * s){
    int l = 0, r = strlen(s)-1;
    while (l <= r) {
        if (!isalnum(s[l]))
            l++;
        else if (!isalnum(s[r]))
            r--;
        else if (tolower(s[l]) != tolower(s[r]))
            return false;
        else {
            l++; r--;
        }
    }
    return true;
}
