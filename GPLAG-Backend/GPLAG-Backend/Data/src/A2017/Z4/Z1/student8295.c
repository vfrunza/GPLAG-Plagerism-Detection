#include <stdio.h>
#include <string.h>

char * ubaci_broj ( char *s,int broj)
{
int duzina = strlen(broj)-1;
while (*s != '\0') {
if (*s ==!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) {
char* kraj = s;
while (*kraj != '\0') kraj++;
while (kraj > s) {
*(kraj+duzina) = *kraj;
kraj--;
}
int tmp;
char* p = broj;
while (*p != '\0') *s++ = *p++;



s++;
}
}
return broj;
}