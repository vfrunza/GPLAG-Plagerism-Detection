#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define velicina 500

int main() {
	
	int i, brojUGLOVA, j;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &brojUGLOVA);
	
	double niz[velicina], varSTEPENI=0, varMINUTA=0, varSEKUNDI=0, storeMINUTE=0, storeSEKUNDE=0;
	
	for(i=0;i<brojUGLOVA;i++){
		scanf("%lf", &niz[i]);
	}
	
	printf("Uglovi su:\n");
	
	for(i=0;i<brojUGLOVA;i++){
		varSTEPENI=niz[i]*(180/PI);
		storeMINUTE=(varSTEPENI-(int)varSTEPENI);
		varSTEPENI=varSTEPENI-storeMINUTE;
		varMINUTA=storeMINUTE*60;
		storeSEKUNDE=(varMINUTA-(int)varMINUTA);
		varMINUTA=varMINUTA-storeSEKUNDE;
		varSEKUNDI=storeSEKUNDE*60;
		if(varSEKUNDI>=59.5){
			varMINUTA++;
			varSEKUNDI=0;
		}
		if(varSEKUNDI<=-59.5){
			varMINUTA--;
			varSEKUNDI=0;
		}
		if(varMINUTA>=59.5){
			varSTEPENI++;
			varMINUTA=0;
		}
		if(varMINUTA<=-59.5){
			varSTEPENI--;
			varMINUTA=0;
		}
		//printf("%.3f ,%.3f, %.3f\n", varSTEPENI, varMINUTA, varSEKUNDI);
		if(varSEKUNDI>30 || varSEKUNDI<-30){
			for(j=i;j<brojUGLOVA;j++){
				niz[j]=niz[j+1];
				
			}
			i--;
			brojUGLOVA--;
			continue;
		}
		if(varMINUTA<0){
			varMINUTA=-varMINUTA;
		}
		if(varSEKUNDI<0){
			varSEKUNDI=-varSEKUNDI;
		}
			//printf("%d, %d, %d", (int)varSTEPENI, (int)varMINUTA);
			printf("%.f stepeni %.f minuta %.f sekundi\n",varSTEPENI, varMINUTA,varSEKUNDI);
	}
	
	return 0;
}
