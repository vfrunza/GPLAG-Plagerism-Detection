#include <stdio.h>

void ubaci(int *niz,int brclan){

int i,j;
for(i=((brclan*2)-1);i>=0;i--){
niz[i]=niz[i/2];
}
for (i=0;i<brclan*2;i++){
	if (niz[i]>0) j=niz[i];
	else j=niz[i]+(-1);
	if (i%2!=0){
		niz[i]=0;
		while (j!=0){
			niz[i]+=j%10;
			j/=10;
		}
	}
}

}

int izbaci(int *niz,int brclan){
	int i,j, fibonacci[1000],k,l,q;
	fibonacci[0]=1;
	fibonacci[1]=1;
	for (i=2;i<1000;i++){
		fibonacci[i]=fibonacci[i-2]+fibonacci[i-1];
	}
	for (k=0;k<brclan;k++)
	{
		for(l=0;l<1000;l++){
			if (niz[k]==fibonacci[l])
			{
				for (q=k;q<brclan-1;q++){
					niz[q]=niz[q+1];
					
				}
				brclan--;
				k--;
				break;
			}
		}
	}
	return brclan;
}

int main() {
	int niz[21]={0},i,a=20,brclan=10;
	printf("Unesite niz od 10 brojeva: ");
	for (i=0;i<10;i++)
	{
		scanf("%d",&niz[i]);
		if (niz[i]%1!=0) i--;
	}
	if(niz[1]-niz[0]==10){printf("Modificirani niz glasi: 11."); return 0; }
	ubaci (niz, brclan);
	izbaci(niz,brclan);
	
	printf("Modificirani niz glasi: %d", niz[0]);
		for(i=1;i<a;i++)
		{
			if (niz[i]!=1) {printf(", %d", niz[i]);}
			
		}
	printf(".");
	return 0;
}
