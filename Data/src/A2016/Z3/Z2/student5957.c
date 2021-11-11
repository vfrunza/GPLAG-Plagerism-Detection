#include <stdio.h>
int saberi_cifre(int a){
	int zbir=0,b=0;
	do{
		b=a%10;
		a=a/10;
		zbir=zbir+b;
	}while(a!=0);
	if(zbir<0)
	zbir=-zbir;
	return zbir;
}
void ubaci(int niz[],int i){
	i=i*2;
	int j=0,i2=0,niz_ubaci[20]={0},pomocni[20]={0};
	for(j=0;j<i;j++)
	pomocni[j]=niz[j];
	for(j=0;j<i;j++)
	niz[j]=0;
	for(j=0;j<i;j++){
	if(j%2==0 || j==0){
		niz_ubaci[j]=pomocni[i2];
		i2++;
	}
	else
	niz_ubaci[j]=saberi_cifre(pomocni[i2-1]);
	niz[j]=niz_ubaci[j];
	}
}
int izbaci(int niz[],int i){
	int prvi=1,drugi=1,pomocni=0,j=0,k=0,br=0;
	br=i;
	for(j=0;j<br;j++){
		do{
			pomocni=drugi;
			drugi=prvi+drugi;
			prvi=pomocni;
		}while(drugi<niz[j]);
		if(niz[j]==drugi || niz[j]==prvi) {
			for (k=j; k<br-1; k++) {
				niz[k]=niz[k+1];
			}
			br--;            
			j--;
		}
    prvi=1;
    drugi=1;
    pomocni=0;
	}
	return br;
}

int main() {
	int niz[20]={0},i,brojac=0,vel=0;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
	scanf("%d",&niz[i]);
	brojac++;
	}
	if(brojac>10)
	brojac=10;
	ubaci(&niz[0],brojac);
	vel=izbaci(&niz[0],2*brojac);
	printf("Modificirani niz glasi: ");
	for(i=0;i<vel;i++){
		if(i<vel-1)
	    printf("%d, ",niz[i]);
        else if(i==vel-1)
	    printf("%d.",niz[i]);
	}
	return 0;
}
