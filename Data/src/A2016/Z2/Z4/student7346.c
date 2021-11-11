#include <stdio.h>
int main() {
	int a,b,j,i;
	int pretpostavkaT=1;
	int pretpostavkaM=1;
	double mmm[100][100]={{0}};
	int razlika;
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &a,&b);
		if(a<=0 || b<=0 || a>100 || b>100)
		   printf("Pogresan unos!\n");
	} while(a<1 || b>100 || b<=0 || a>100);
	 razlika=a-b;
	 if(razlika<=-1) 
	     razlika=-razlika;
	printf("Unesite elemente matrice: ");
	for(i=0; i<a; i++){
		for(j=0; j<b; j++)
			scanf("%lf ", &mmm[i][j]);
	}
	for(i=0; i<a-1; i++){
		for(j=0; j<b-1; j++){
			if(mmm[i][j]!=mmm[i+1][j+1]) 
                pretpostavkaT=0; 
		}
                
			if((mmm[i][b-1]!=mmm[i+1][0]) || (mmm[0][razlika]!=mmm[a-1][b-1]))
                pretpostavkaM=0;  
            
    }

  if(pretpostavkaM!=0) printf("Matrica je cirkularna");
  else if(pretpostavkaT==1) printf("Matrica je Teplicova");
  else if(pretpostavkaT!=1 && pretpostavkaM==0) printf("Matrica nije ni cirkularna ni Teplicova");
  
  
  return 0;
}
