#include <stdio.h>
#include <math.h>
#include<stdlib.h>


int izbaci_cifre(int *niz1,int vel1,int *niz2, int vel2){
	int i,j,x,y,counter,cifre,cifra,New;
	for(x=0;x<vel2;x++){
		for(y=0;y<vel2;y++){
			if(niz2[x]<0||niz2[x]>9)return 0;
			if(niz2[x]==niz2[y] && y!=x)return 0;
		}
	}
	for(i=0;i<vel1;i++){
		counter=0;
		cifre=fabs(niz1[i]);
		/*PREBROJAVA BROJ CIFRI U BROJU*/
		do{
			cifre=cifre/10;
			counter++;
		}while(cifre!=0);
	counter--;
	cifra=fabs(niz1[i]);	
	New=0;
	do{
		cifre=cifra;
		cifre=cifre/pow(10,counter);
		for(j=0;j<vel2;j++)if(cifre==niz2[j]){
			break;
		}
		if(j==vel2){
			New=New*10+cifre;
		}
		cifra=cifra-pow(10,counter)*cifre;
		counter--;
	}while(counter>=0);
	if(niz1[i]<0)niz1[i]=-1*New;
	else niz1[i]=New;
	}
	return 1;
}
	
int main() {
	return 0;
}
