#include <stdio.h>
#define BR_ELEMENATA 500
#define PI 3.1415926

int main()
{
    
double niz[500];

 int n,i,j;
 int sekunde=0,minute=0,stepeni=0;
 double ukupno_sekundi=0;
 
 do{
    printf("Unesite broj uglova: ");
    scanf("%d", &n);
    if(n<=0 || n>500)
    printf("Pogresan unos\n");
 } while(n<=0 || n>500);
    
    for(i=0; i<n; i++){
        scanf("%lf", &niz[i]); 
    }
    

    
     for(i=0; i<n; i++) {
         ukupno_sekundi= ((niz[i]*360*60*60)/ (2*PI));
        
         ukupno_sekundi= (int)(ukupno_sekundi+0.5);
         stepeni = (int) ukupno_sekundi/3600;
        minute = (int)(ukupno_sekundi - stepeni*3600)/60;
        sekunde = (int)(ukupno_sekundi-stepeni*3600-minute*60);
   
         if (sekunde>=60) {
             sekunde=sekunde-60;}
             
             
             
         if(sekunde>30){
         for(j=i; j<n-1; j++){
             niz[j]=niz[j+1];
         }
         n--;
         i--;}
     
    }
    
 
    printf("Uglovi su:\n");
    for(i=0; i<n; i++){
         ukupno_sekundi= ((niz[i]*360*60*60)/ (2*PI));
        ukupno_sekundi= (int)(ukupno_sekundi+0.5);
        stepeni = (int) ukupno_sekundi/3600;
        minute = (int)(ukupno_sekundi - stepeni*3600)/60;
        sekunde = (int)(ukupno_sekundi-stepeni*3600-minute*60);
         
         if (sekunde>=60) {
             minute++;
             sekunde=sekunde-60;}
             
            if (minute>=60) {
             stepeni++;
             minute=minute-60;}  
             
        printf("%d stepeni %d minuta %d sekundi\n",stepeni, minute, sekunde);
    }
    
    
    
    return 0;
}
/*#include <stdio.h>
#define BR_ELEMENATA 500
#define PI 3.1415926

int main()
{
    
float niz[500];

 int n,i,j;
 int sekunde=0,minute=0,stepeni=0;
 float ukupno_sekundi=0;
 
 do{
    printf("Unesite broj uglova: ");
    scanf("%d", &n);
    if(n<=0 || n>500)
    printf("Pogresan unos\n");
 } while(n<=0 || n>500);
    
    for(i=0; i<n; i++){
        scanf("%f", &niz[i]); 
    }
    

    
     for(i=0; i<n; i++) {
         ukupno_sekundi= ((niz[i]*360*60*60)/ (2*PI));
     ukupno_sekundi= (int)(ukupno_sekundi+0.5);
         sekunde= (int)ukupno_sekundi % 60;
         
         if (sekunde>=60) {
             sekunde=sekunde-60;}
             
             
             
             
         if(sekunde>30){
         for(j=i; j<n-1; j++){
             niz[j]=niz[j+1];
         }
         n--;
         i--;}
     
    }
    
 
    printf("Uglovi su: ");
    for(i=0; i<n; i++){
       ukupno_sekundi= (niz[i]*360*60*60/ (2*PI));
       ukupno_sekundi= (int)(ukupno_sekundi+0.5);
       
     if (sekunde>=60) {
minute++;
             sekunde=sekunde-60;}
             
       
       if(minute>=60) {
             stepeni++;
             minute=minute-60;}
             
         sekunde=(int)ukupno_sekundi % 60;
         minute= ( (int) ukupno_sekundi/60)% 60;
         stepeni= (int) ukupno_sekundi/3600;
        printf("%d stepeni %d minuta %d sekundi\n",stepeni, minute, sekunde);
    }
    
    
    
    return 0;
}




*/

/*#include <stdio.h>
#define VISINA 100
#define SIRINA 100
int main() {
	
	int M, N, i, j;
	int mat[VISINA][SIRINA];
	int pomocna=0, teplicova_i=0, teplicova_j=0, teplicova=0, cirkularna=0;
	int niz1[100],niz2[100];
	int f,k;
	
	do{
		
	printf("Unesite M i N: ");
	scanf("%d %d", &M, &N);
	if(M<=0 || M>100 || N<=0 || N>100)
	printf("Pogresan unos!\n");
	}
   while(M<=0 || M>100 || N<=0 || N>100); 
	
	printf("Unesite elemente matrice: ");
   
   
    for(i=0; i<M; i++){
    	for(j=0; j<N; j++){
    		scanf("%d", &mat[i][j]);
    	}
    	}
    
    	teplicova_i=1;
    for(i=0; i<M-1; i++){
        if(teplicova_i==0)
        break;
    	j=0;
        pomocna=mat[i][j];
    	while( ++i<M && ++j<N){
    	if(mat[i][j] != pomocna){
    	teplicova_i=0;
    	break;}
    	}
    }
    
    	teplicova_j=1;
    for(j=0; j<N-1; j++){
        if(teplicova_j==0)
        break;
    	i=0;
        pomocna=mat[i][j];
    	while( ++i<M && ++j<N){
    	if(mat[i][j] != pomocna){
    	teplicova_j=0;
    	break;}
    	}
    }
    
    
    	if(teplicova_i==1 && teplicova_j==1){
    		teplicova=1;
    	}
    	
    if(teplicova==1)
    printf("Matrica je Teplicova");
    
    
    
    	cirkularna=1;
    	
    	
    	   
    	for(i=0; i<M-1; i++){
    	    if (cirkularna==0) break;
        	for(j=0; j<N; j++){
        	niz1[j] = mat[i][j];
        	}
    	    for(k=i+1; k<i+2; k++){
        	for(j=0; j<N; j++){
        	niz2[j] = mat[k][j];
        	}
         	}
         	
         
         		if(niz1[N-1] != niz2[0]){
    			cirkularna=0;
    			break;
    			}
    		
         	for(f=0; f<N-1; f++){
         	    if(niz1[f] != niz2[f+1]){
    			cirkularna=0;
    			break;
    			}
         	}
    	};
    	
    	if(cirkularna==1)
    	printf("Matrica je cirkularna");
    	
    	
  if(teplicova !=1  && cirkularna != 1)
  printf("Matrica nije ni cirkularna ni Teplicova");



	return 0;
}



NOVI KOJI RADI, SAMO DVA TESTA NE PROLAZE

#include <stdio.h>
#define VISINA 100
#define SIRINA 100
int main() {
	
	int M, N, i, j;
	int mat[VISINA][SIRINA];
	int pomocna=0, teplicova_i=0, teplicova_j=0, teplicova=0, cirkularna=0;
	int niz1[100],niz2[100];
	int f,k;
	
	do{
		
	printf("Unesite M i N: ");
	scanf("%d %d", &M, &N);
	if(M<=0 || M>100 || N<=0 || N>100)
	printf("Pogresan unos!\n");
	}
   while(M<=0 || M>100 || N<=0 || N>100); 
	
	printf("Unesite elemente matrice: ");
   
   
    for(i=0; i<M; i++){
    	for(j=0; j<N; j++){
    		scanf("%d", &mat[i][j]);
    	}
    	}
    
    
    	cirkularna=1;
    	
    	for(i=0; i<M-1; i++){
    	    if (cirkularna==0) break;
        	for(j=0; j<N; j++){
        	niz1[j] = mat[i][j];
        	}
    	    for(k=i+1; k<i+2; k++){
        	for(j=0; j<N; j++){
        	niz2[j] = mat[k][j];
        	}
         	}
         	
         
         		if(niz1[N-1] != niz2[0]){
    			cirkularna=0;
    			break;
    			}
    	
         	for(f=0; f<N-1; f++){
         	    if(niz1[f] != niz2[f+1]){
    			cirkularna=0;
    			break;
    			}
         	}
    	};
    	
    	if(cirkularna==1){
    	printf("Matrica je cirkularna");
    	return 0;}
    	
    	
    	teplicova_i=1;
    for(i=0; i<M; i++){
        if(teplicova_i==0) break;
    	j=0;
        pomocna=mat[i][j];
    	while( ++i<M+1 && ++j<N+1){
    	if(mat[i][j] != pomocna){
    	teplicova_i=0;
    	break;}
    	}
    }
    
    	teplicova_j=1;
    for(j=0; j<N; j++){
        if(teplicova_j==0) break;
    	i=0;
        pomocna=mat[i][j];
    	while( ++i<M+1 && ++j<N+1){
    	if(mat[i][j] != pomocna){
    	teplicova_j=0;
    	break;}
    	}
    }
    
    
    	if(teplicova_i==1 && teplicova_j==1){
    		teplicova=1;
    	}
    	
    if(teplicova==1)
    printf("Matrica je Teplicova");
   
    
    
    	
  if(teplicova !=1  && cirkularna != 1)
  printf("Matrica nije ni cirkularna ni Teplicova");



	return 0;
}
*/