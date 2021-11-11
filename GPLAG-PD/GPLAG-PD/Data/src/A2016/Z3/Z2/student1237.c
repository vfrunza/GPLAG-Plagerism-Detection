#include <stdio.h>
#include <math.h>

int fibonaci(int niz,int vel){
int sljedeci;
int prvi=0,drugi=1;
int c=0;
for(c=0;c<100;c++){
if(c<=0) sljedeci=c;
else {
	sljedeci=prvi+drugi;
	prvi=drugi;
	drugi=sljedeci;
}
}
return sljedeci;
}

int izbaci(int niz[],int vel){
	int i,j;
for(i=0;i<10;i++){
	if(niz[i]==fibonaci(niz[i],10)){

			for(j=i;j<vel;j++){
				niz[j]=niz[j+1];
		
			}
			i--;
			vel--;
			continue;
		
}}
return vel;
}
int main() {
int niz[10],i;
printf("Unesite niz: ");
for(i=0;i<10;i++){
	scanf("%d",&niz[i]);
}



printf("%d",izbaci(niz[10],10));


	return 0;
}
