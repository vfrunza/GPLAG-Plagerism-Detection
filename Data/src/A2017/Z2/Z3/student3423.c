#include <stdio.h>

int main() {
int c='E',d='C',e='D';
c=c-e;
e=c-d;
d=d+e+'E';
c=c-d;
printf ("c=%d,d=%d,e=%d", c,d,e);
return 0;
}