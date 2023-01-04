int getSum(int a, int b){
    int mask = 0xFFF, max_int = 0x7FF;
    int carry;
    while (b) {
        // can't have <<1 before mask, would be shifting neg #
        carry = ((a & b) & mask) << 1; 
        a = (a ^ b) & mask;
        b = carry;
    }
    return (a <= max_int) ? a : ~(a ^ mask);
}

int getSum(int a, int b) {
    return getDifference(a, -b);
}

int getDifference(int a, int b) {
    int mask = 0xFFF, max_int = 0x7FF;
    int borrow;
    while (b) {
        borrow = ((~a & b) & mask) << 1;
        a = (a ^ b) & mask;
        b = borrow;
    }
    return (a <= max_int) ? a : ~(a ^ mask);
}


// Alternatives
int getSum(int a, int b){
    int carry;
    while (b) {
        carry = (unsigned)(a & b) << 1;
        a = a ^ b; //sum without carry
        b = carry;
    }
    return a;
}

int getDifference(int a, int b) {
    int borrow;
    while (b) {
        borrow = (unsigned)(~a & b) << 1;
        a = a ^ b;
        b = borrow;
    }
    return a;
}
