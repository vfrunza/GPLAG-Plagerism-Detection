#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.1415926
int main() {
	double niz[500],ugao;
	int i,n,j,stepen,minuta,sekunda,ukugaosek,nizstepen[500],nizminuta[500],nizsekunda[500];
	
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	
	for (i=0; i<n; i++){
		scanf("%lf", &niz[i]);
		ugao=niz[i]*(180/pi)*3600;
		if (ugao>=0)
		ukugaosek=(int)(ugao+0.5);
		if(ugao<0) ukugaosek=(int)(ugao-0.5);
		stepen=ukugaosek/3600;
		minuta=(ukugaosek-stepen*3600)/60;
		sekunda=ukugaosek-stepen*3600-minuta*60;
	
		
		if (sekunda<0) {sekunda=abs(sekunda);} 
		if (minuta<0) minuta=abs(minuta);
		if (sekunda>=60){minuta++; sekunda=sekunda-60;}
		if (minuta>=60){stepen++; minuta=minuta-60;}

	
			nizstepen[i]=stepen;
		nizminuta[i]=minuta;
		nizsekunda[i]=sekunda;
		
		if(sekunda>30){ for (j=i; j<n-1; j++){
			niz[j]=niz[j+1];
			nizsekunda[j]=nizsekunda[j+1];
			nizminuta[j]=nizminuta[j+1];
			nizstepen[j]=nizstepen[j+1];
		}
			n--;
			i--;
		}
	
	}

	
	printf("Uglovi su:\n");
	 for (i=0;i<n; i++){
	 	printf("%d stepeni %d minuta %d sekundi\n", nizstepen[i], nizminuta[i], nizsekunda[i]);
	 }
		return 0;
	}
	

