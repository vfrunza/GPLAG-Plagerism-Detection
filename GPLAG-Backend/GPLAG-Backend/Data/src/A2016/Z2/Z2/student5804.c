#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	float nizuglova[500], ostatakzamin, ostatakzasek, ostatakzapovecaj;
	int n, i, j, nizstepena[500], nizminuta[500], nizsekundi[500], nizminusa[500];
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%f", &nizuglova[i]);
		if(nizuglova[i]<0){nizuglova[i]*=(-1); nizminusa[i]=1;} else nizminusa[i]=0;
	}
	for(i=0;i<n;i++){
		nizstepena[i]=nizuglova[i]*(180/PI);
		ostatakzamin=(nizuglova[i]*(180/PI))-nizstepena[i];
		nizminuta[i]=ostatakzamin*60;
		ostatakzasek=(ostatakzamin*60)-nizminuta[i];
		nizsekundi[i]=ostatakzasek*60;
		ostatakzapovecaj=(ostatakzasek*60)-nizsekundi[i];
		if((ostatakzapovecaj*100)>=51) nizsekundi[i]+=1;
		if(nizsekundi[i]==60){nizsekundi[i]=0; nizminuta[i]+=1;}
		if(nizminuta[i]==60){nizminuta[i]=0; nizstepena[i]+=1;}
	}
	for(i=0;i<n;i++){
		if(fabs(nizsekundi[i])>30) { for(j=i;j<n-1;j++) {nizuglova[j]=nizuglova[j+1]; nizsekundi[j]=nizsekundi[j+1]; nizminuta[j]=nizminuta[j+1]; nizstepena[j]=nizstepena[j+1];nizminusa[j]=nizminusa[j+1];}
		i--;
		n--;}
	}
	for(i=0; i<n;i++){
		if(nizminusa[i]==1){ nizuglova[i]*=(-1); nizstepena[i]*=(-1);}
	}
	printf("Uglovi su: \n");
	for(i=0; i<n;i++){
	printf("%d stepeni %d minuta %d sekundi\n", nizstepena[i], nizminuta[i], nizsekundi[i]);}
	return 0;
}
