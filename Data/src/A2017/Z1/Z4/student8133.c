#include <stdio.h>

int main() {
int i, j, k;
int brojRedova, brojKolona, sirinaKolone;
do {
printf("Unesite broj redova: ");
scanf("%d", &brojRedova);
}
while(brojRedova<=0 || brojRedova>10);
do {
printf("Unesite broj kolona: ");
scanf("%d", &brojKolona);
}
while(brojKolona<=0 || brojKolona>10);
do {
printf("Unesite sirinu jedne kolone: ");
scanf("%d", &sirinaKolone);
}
while(sirinaKolone<=0 || sirinaKolone>10);

for (i=0; i<brojRedova; i++)
{
    if(i==0)
{
    for(j=0; j<brojKolona; j++)
{
    if(j==0)
printf("+");
for(k=0; k<sirinaKolone; k++)
{
    printf("-");
}
printf("+");
}
printf("\n");
}
for(j=0; j<brojKolona; j++) {
  if(j==0) 
  printf("|");
for(k=0; k<sirinaKolone; k++)
{
    printf(" ");
}
printf("|");
}
printf("\n");

for(j=0; j<brojKolona; j++)
{
    if(j==0)
    printf("+");
for(k=0; k<sirinaKolone; k++)
{
    printf("-");
}
printf("+");
}
printf("\n");
}
return 0;
}
