char * intToRoman(int num){
    char *romans[4][10] = {{"", "I","II","III","IV","V","VI","VII","VIII","IX"},
                        {"", "X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                        {"", "C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
                        {"", "M","MM","MMM"}};
    char *ret = malloc(16 * sizeof(char));
    ret[0] = '\0';
    char digits[5];
    sprintf(digits, "%d", num);
    int place = strlen(digits)-1;
    for (int i = 0; i < strlen(digits); ++i) {
        strcat(ret, romans[place--][digits[i]-'0']);
    }
    return ret;
}


// Worked
char * intToRoman(int num){
    char *romans[4][10] = {{"", "I","II","III","IV","V","VI","VII","VIII","IX"},
                        {"", "X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                        {"", "C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
                        {"", "M","MM","MMM"}};
    char *ret = malloc(16 * sizeof(char));
    ret[0] = '\0';            
    char *digits[5];
    int place = 0;
    while (num) {
        int i = num % 10;
        digits[place] = romans[place][i];
        num /= 10;
        place += 1;
    }
    
    while (place) {
        strcat(ret, digits[--place]);
    }
    return ret;
}

// reversed way didn't work since don't want to reverse digits as well ex. IV => VI
void reverse(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len/2; ++i) {
        char tmp = s[i];
        s[i] = s[len+~i];
        s[len+~i] = tmp;
    }
}
