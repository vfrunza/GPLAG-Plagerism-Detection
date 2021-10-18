#include <stdio.h>

int main() {
int d='F',e='D',f='E';
d=d-f;
f=d-e;
e=e+f-'F';
d=d+e;
printf ("d=%d,e=%d,f=%d", d,e,f);
return 0;
}