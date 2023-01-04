#include <stdio.h>

enum week {
    Mon, Tue, Wed, Thur, Fri, Sat, Sun
};

struct person {
    char name[10];
};

//TODO anonymoua enum

int main()
{
    enum week day = Sun;
    struct person p[] = { [Mon] = {'A'}, [Tue] = {'B'}, [Sun] = {'G'} }; // not null terminated?
    printf("%s\n", p[1].name);
    printf("%s\n", p[day].name);
    return 0;
}
