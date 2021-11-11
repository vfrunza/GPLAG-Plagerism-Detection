#include <stdio.h>
#define epsilon 0.0000001
int sumacifara(float a){
	int x=a*10;
	int suma=0;
	if(x<0)x*=-1;
	while(x!=0){
		suma+=x%10;
		x/=10;
	}
	return suma;
}
void zaokruzi1(float *niz,int vel){
	int i=0;
	int a,sgn;
	for(i=0;i<vel;i++){
		if(niz[i]<0)sgn=-1;
		else sgn=1;
		a=(sgn*niz[i]*10+0.5)*sgn;
		niz[i]=(float)a/10;
	}
}
void preslozi(float *niz,int vel,int k){
	int i;
	int j;
	float back;
	zaokruzi1(niz,vel);
	for(i=0;i<vel;i++){
		if(sumacifara(niz[i])>=k){
			j=i;
			back=niz[i];
			while(j-1>=0){
				if(sumacifara(niz[j-1])<k){
					niz[j]=niz[j-1];
				}else{
					niz[j]=back;
					break;
				}
				j--;
				if(j==0)niz[j]=back;
			}
		}
	}
}
int main() {
int i;
    float niz[] = { 13.1, 15.79999, 15.5, 9.222, 78.1 };
    preslozi(niz, 5, 14);
    printf("Niz glasi: ");
    for (i=0; i<5; i++)
        printf("%g ", niz[i]);
 
}
