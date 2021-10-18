#include <stdio.h>

void ubaci( int*a,int velicina){
   int *q,*p,i=0,d,b;
   q=a;
   while(q<2*velicina+a-1){
       d=1;
       p=q+velicina-1-i;
    while(p>=q){
        *(p+1)=*p;
    p--;
    }
   if(*q<0) b=-*q;
   else b=*q;
   while(b>=10){
       b/=10;
       d*=10;
   }
    if(*q<0) b=-*q;
   else b=*q;
  *(q+1)=0;
  while(d>=1){
       *(q+1)=*(q+1)+(b/d);
       b=b-(b/d)*d;
       d/=10;
   }
   i++;
   q+=2;
   }
   
    
   }
  
int fibonaci(int x)
{ int a=1,b=1,c;
while(b<=x){
    if(b==x) return x;
    c=b;
    b+=a;
    a=c;
}
return 0;
}

int izbaci(int *p,int velicina)
{ int *a,*b;
a=p;
while(a<p+velicina){
    if (fibonaci(*a)){
        b=a;
        while(b<(p+velicina-1)){
            *b=*(b+1);
            b++;
        }
        a--;
        velicina--;
    }
    a++;
}
return velicina;}
  
int main() {
    int a[50000],i,j;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0;i<10;i++)
    { scanf("%d",&a[i]);
    }
    ubaci(a,i);
    i*=2;
    i=izbaci(a,i);
    printf("Modificirani niz glasi: ");
    for(j=0;j<i;j++){
       if (j!=i-1) printf("%d, ",a[j]);
       if(j==i-1) printf("%d.",a[j]);
    }
    
	return 0;
}
