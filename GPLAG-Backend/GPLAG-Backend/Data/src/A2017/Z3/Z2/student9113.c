#include <stdio.h>
#include <math.h>
void zaokruzi1(float *niz,int br){
	float  *p=niz;
	while (p<niz+br){
		if(*p>=0){
			*p*=10;
			*p=(int)(*p+0.5);
			*p++/=10;
	}
	else {
		*p*=10;
		*p=(int)(*p-0.5);
		*p++/=10;
		
	}
}
}
void preslozi(float *niz,int br,int k){
 float *p=niz;
 float *q=niz;
 float *s=niz;
 float *m=niz;
 int temp=0,a=0,suma=0;
 zaokruzi1(niz,br);
 while(p<niz+br){
  *p*=10;
  p++;
 }
 p=niz;
 
 while(p<niz+br){
 if(*p<0) a=*p*(-1);
 else a=*p;
  while(a!=0){
   suma+=a%10;
   a=a/10;
  }
  if(suma>=k){
   s=p;
   temp=*p;
   while(s>q){
    *s=*(s-1);
   s--;
    }
    *m=temp;
    m++;
    q=m;
   }
  suma=0;
  p++;
 }
 p=niz;
 while(p<niz+br){
  *p /=10;
  p++;
 }
 
}
int main(){
 int i;
    float niz[5] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
    preslozi(niz, 5, 14);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);
 return 0;
}