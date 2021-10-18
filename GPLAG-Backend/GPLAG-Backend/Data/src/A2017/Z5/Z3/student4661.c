#include <stdio.h>

char *f1(char *s)
{
    s++;
    *s++;
    *(s++);
    *++s;
    return s;
}
char *f2(char *s)
{
    --s;
    --*s;
    *--s;
    return s;
}
int main()
{
    char string [] = "Ispisi su interesantni.";
    printf("%s", f2(f1(string)));
    return 0;
}

