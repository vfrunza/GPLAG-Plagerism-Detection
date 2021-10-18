#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void zaokruzi1(float *n, int a){
	int i;
	float r;
	for(i=0;i<a;i++){
		r=n[i];
		if(r>0){
		r = ((int)(n[i]*10.0 + .5));
		n[i]=(float)r/10;
		}
		if(r<0){
		r = ((int)(n[i]*10.0 - .5));
		n[i]=(float)r/10;	
		}
	}
}
void preslozi(float *n,int a, int b){
	zaokruzi1(n,a);
	int x;
	int i,j;
	int suma=0;
	float tmp;
	int br=0;
	int pocetak=a;
	for(i=0;i<a;i++){
		x=abs(n[i]*10);
		suma=0;
	while(x!=0){
		int r;
		r=x%10;
		suma+=r;
		x/=10;
	}
	if(suma<b){
		br++;
		tmp=n[i];
		for(j=i;j<a-1;j++){
			n[j]=n[j+1];
		}
		n[a-1]=tmp;
		i--;
		a--;
	}
	}
	int y,k;
	y=pocetak-br;
	k=pocetak-1;
	while (y < k) {
      tmp = n[y];
      n[y] = n[k];
      n[k] = tmp;
      y++;         
      k--;          
   }
}
int main() {
	  int i;
float niz[] = { -1.0, -0.1, -0.19999, -4.449999, -4.45001 };
preslozi(niz, 5, 8);
printf("Niz glasi: ");
for (i=0; i<5; i++)
    printf("%g ", niz[i]);
}
