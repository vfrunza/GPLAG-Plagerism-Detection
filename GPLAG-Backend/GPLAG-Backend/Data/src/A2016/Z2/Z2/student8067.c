#include <stdio.h>
#define PI 3.1415926
#include <stdlib.h>
#include <math.h>

int main() {
    int i,n,j;
    double S,M,SEK;
    double a[500];
    double UGAO;
 
    printf("Unesite broj uglova: ");
    scanf("%d", &n);
 
    
    for(i=0;i<n;i++) {
        
        scanf("%lf",&a[i]);
    }
    
    
    for(i=0;i<n;i++) {
       UGAO=fabs((a[i]*180)/PI);
       M=(UGAO-(int)UGAO)*60;
       SEK=round((M-(int)M)*60);
        if(SEK==60) { SEK==0,M++; }
        
        if(SEK>30)  {
            for(j=i;j<n-1;j++) {
                a[j]=a[j+1];
                }
                n--;
                i--;
        }
        }
        printf("Uglovi su:\n");
        for(i=0;i<n;i++) {
            UGAO=(a[i]*180)/PI;
            M=fabs((UGAO-(int)UGAO)*60);
            SEK=round((M-(int)M)*60);
            
            S=(int)UGAO;
            M=(int)M;
            SEK=round(SEK);
            
            if(S>=0) {
                if(SEK==60) {SEK=0;M++;}
                if(M==60) {M=0;S++;}
                
            }
            if(S<0) {
                if(SEK==60) { SEK=0;M++;}
                if(M==60) {M=0;S--;}
                
            }
            printf("%.f stepeni %.f minuta %.f sekundi\n",S,M,SEK);
        }
        

    

	
	
    
	return 0;
}
