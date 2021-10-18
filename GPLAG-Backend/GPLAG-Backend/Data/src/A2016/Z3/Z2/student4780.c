#include <stdio.h>
#include <stdlib.h>



void ubaci(int  *niz, int vel){
	int i=0,c=0;
	 int x=0,y=0;
	 int t[10];
	
	for(i=0; i<vel; i++){
		t[i]=niz[i];
	}
	for(i=vel-1;i>=0;i--){
		niz[2*i]=t[i];
	}
	for(i=0;i<vel;i++){
		y=niz[2*i];
	if(y<0) 
	y=y*(-1);
	
	while(y!=0){
		c=y%10;
		x+=c;
		y/=10;
	}
	niz[2*i+1]=x;
	x=0;
	}
}

 int izbaci( int *niz, int n){
	 int i=0,j=0,x=0,a=1,b=1,c=0;
 for(i=0;i<n;i++){
	a=1;
	b=1;
	for(j=1;j<10000;j++){
		
		if(j==1)
		c=1;
		else {
			c=a+b;
			a=b;
			b=c;
		}
		if(niz[i]==c){
				for(x=i;x<n-1;x++)
				niz[x]=niz[x+1];
				n--;
				i--;
				break;
			}
		}}
	return n;
}
int main() {
 int niz[20]={0};
 int i=0,d=10;
printf("Unesite niz od 10 brojeva: ");
 for(i=0;i<d;i++)
scanf("%d", &niz[i]);
ubaci(niz,10);
d=izbaci(niz,20);
if(d==0)
printf("Prazan niz.");
else {
printf("Modificirani niz glasi: ");
for(i=0;i<d;i++){
	if(i==(d-1))
	printf("%d.", niz[i]);
else
printf("%d, ", niz[i]);}}
return 0;
}
