#include <stdio.h>
int izbaci(int *niz,int vel){
	int fniz[100],i,j,k;
	fniz[0]=1;
	fniz[1]=1;
	for(i=2;i<100;i++){
		fniz[i]=fniz[i-2]+fniz[i-1];
	}
	for(i=0;i<vel;i++){
		for(j=0;j<100;j++){
			if(niz[i]==fniz[j]){
				for(k=i;k<vel-1;k++){
					niz[k]=niz[k+1];
				}
				vel--;				
				i--;
				break;
			}
		}
	}
	return vel;
}
void ubaci(int *niz,int vel){
	int i,s=0,c,niz1[10],a;
	for(i=0;i<10;i++){
		niz1[i]=niz[i];
	}
	for(i=0;i<vel;i++){
		if(i%2!=0) niz[i]=0;
	}
	for(i=0;i<vel/2;i++){
		niz[2*i]=niz1[i];
	}
	for(i=0;i<vel;i+=2){
		a=niz[i];
		if(a<0) a*=-1;
		while(a!=0){
			c=a%10;
			s+=c;
			a/=10;
		}
		niz[i+1]=s;
		s=0;
	}
}
int main() {
	int niz[20],i,vel=20;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d",&niz[i]);
	}
	
	ubaci(niz,vel);
	vel=izbaci(niz,vel);
	printf("Modificirani niz glasi: ");
	for(i=0;i<vel;i++){
		printf("%d",niz[i]);
		if(i<vel-1) printf(", ");
	}
	printf(".");
	return 0;
}
