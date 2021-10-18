#include <stdio.h>
#define v 500
#define PI 3.1415926
int main() {
	double niza[v]={0}; 
	int negativno=0; 
	int n,i,sekund,minut,stepen,k,j,min[v],sek[v],st[v]; 
	do {
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	}while(n>500 || n<0);
	
	for(i=0; i<n; i++){
		scanf("%lf", &niza[i]);
	}
	
	for(k=0; k<n; k++){
		negativno=0;
		if(niza[k]<0){
			niza[k]=-niza[k]; negativno++; }
		stepen=niza[k]*180/PI;
		minut=((niza[k]*180/PI)-stepen)*60;
		sekund=((niza[k]*180/PI-stepen)*60-minut)*60+0.5; 
		
		if(sekund>59){
			sekund-=60;	minut++; }
		if(minut>=60){
			stepen++; minut-=60; }
			
		if(sekund>=31) {           
			for(j=k; j<n-1; j++)
			niza[j]=niza[j+1];
			k--; n--;  continue;                                                            
		}
		
	    if(negativno!=1) {
	     	st[k]=stepen;	min[k]=minut; sek[k]=sekund;
        }
	    else { 
		    st[k]=-stepen; min[k]=minut; sek[k]=sekund;
	    }
	} 

	printf("Uglovi su:\n");                 
	for(k=0; k<n; k++){
		printf("%d stepeni %d minuta %d sekundi\n", st[k],min[k],sek[k]);
	} 
	return 0;
}
