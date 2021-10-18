#include <stdio.h>

int main() {
int i=0,j=0,k=0,l=0,m=0,u=0;
float p;
char a='a';
printf("Unesite vozila: ");
do{
scanf("%c",&a);
    if(a=='c' || a=='C')
    i++;
    else if(a=='b' || a=='B')
    j++;
    else if(a=='s' || a=='S')
    k++;
    else if(a=='v' || a=='V')
    l++;
    else if(a=='p' || a=='P')
    m++;
    else if (a=='k' || a=='K')
    break;
    else printf("Neispravan unos\n");
} while (1);

u=i+j+k+l+m;
printf("Ukupno evidentirano %d vozila.\n",u);

if (i>=j && i>=k && i>=l && i>=m){
p=(i*100)/(float)u;
if (u==0)
p=0.;
printf("Najpopularnija boja je crna (%.2f%%).",p);
return 0;
}

if (j>=i && j>=k && j>=l && j>=m){
p=(j*100)/(float)u;
printf("Najpopularnija boja je bijela (%.2f%%).",p);
return 0;
}

if (k>=i && k>=j && k>=l && k>=m){
p=(k*100)/(float)u;
printf("Najpopularnija boja je siva (%.2f%%).",p);
return 0;
}

if (l>=i && l>=j && l>=k && l>=m){
p=(l*100)/(float)u;
printf("Najpopularnija boja je crvena (%.2f%%).",p);
return 0;
}

if (m>=i && m>=j && m>=k && m>=l){
p=(m*100)/(float)u;
printf("Najpopularnija boja je plava (%.2f%%).",p);
return 0;
}

	return 0;
}
