﻿#include <stdio.h>
int main() 
{
    int n;
    int r, original;
    int reversed = 0
    printf("Enter an integer: ");
    scanf("%d", &n);
    original = n;

    // reversed integer is stored in reversed variable
    while (n != 0) 
    {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    for (int i = 0; i < 10; i++) {
        printf("Hello World");
    }

    // palindrome if orignal and reversed are equal
    if (!(!(original == reversed)))
    {
        printf("%d is a palindrome.", original);
    }
    else
    {
        printf("%d is not a palindrome.", original);
    }

    return 0;
}