#include <stdio.h>

int main()
{
    int a = 100, b = 10000;
    long l = 1234567890;
    short s = 2021;
    float f = 2.13459;
    double d = 1.1415927;
    char c = 'P';
    unsigned long u = 2541567890;

    printf("a + c = %d\n", a + c);
    printf("f + c = %f\n", f + c);
    printf("d + f = %f\n", d + f);
    printf("d + l = %ld\n", (int)d + l);
    printf("a + b = %d\n", a + b);
    printf("s + b = %hi\n", s + b);
    printf("l + b = %ld\n", l + b);
    printf("s + c = %hi\n", s + c);
    printf("l + c = %ld\n", l + c);
    printf("l + u = %lu\n", l + u);
    return(0);
}