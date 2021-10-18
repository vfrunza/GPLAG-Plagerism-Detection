#include<stdio.h>
#include<stdlib.h>
void ubaci(int niz[], int vel){
	int i,niz_1[10],niz_2[10],cifra,temp;
	for(i=0;i<vel;i++){
		niz_1[i]=niz[i];
		niz_2[i]=niz[i];
	}
	for(i=0;i<vel;i++){
		temp=0;
		while(niz_1[i]!=0){
			cifra=abs(niz_1[i]%10);
			temp+=cifra;
			niz_1[i]/=10;
		}
			niz[2*i+1]=temp;
			niz[2*i]=niz_2[i];
	}
}

int izbaci(int niz[], int vel){
	int i,j,f_niz[46],k,temp;
	f_niz[0]=1;
	f_niz[1]=1;
	for(i=2;i<46;i++){
		f_niz[i]=f_niz[i-1]+f_niz[i-2];
	}
	for(i=0;i<vel;i++){
		temp=0;
		for(j=1;j<46;j++){
			if(niz[i]==f_niz[j]){
				for(k=i;k<vel-1;k++){
					niz[k]=niz[k+1];
				}
				vel--;
				temp=1;
			}
		}
		if(temp)
			i--;
	}
	return vel;
}

int main() {
	int niz[100]={0},i,pomocna=0;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d",&niz[i]);
	}
	ubaci(niz,i);
	pomocna=izbaci(niz,2*i);
	printf("Modificirani niz glasi: ");
	for(i=0;i<pomocna-1;i++)
		printf("%d, ",niz[i]);
	printf("%d.",niz[i]);
	return 0;
}