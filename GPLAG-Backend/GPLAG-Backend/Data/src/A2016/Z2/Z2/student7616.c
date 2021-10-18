#include <stdio.h>
#include <math.h>
#define PI 3.1415926

                                                                    
int main(){
    int n, i, j, stepen,minuta,sekunda,cs;
    double niz[500], sms;
        
        printf("Unesite broj uglova: ");
            scanf("%d",&n);
                for(i = 0; i < n; i++)  scanf("%lf",&niz[i]);
                
        for(i = 0; i < n; i++){     
                cs = 0;
                    if(niz[i] < 0) {    niz[i] = -niz[i];  cs = 1;  };
                        
                        sms  = ( niz[i] * 180 / PI ) * 3600; 
                        sms = (int) ( sms + 0.5 );          
                        stepen = sms / 3600;           
                        minuta = ( sms - stepen * 3600 ) / 60;
                        sekunda = sms - stepen * 3600 - minuta * 60 ;
      
        
        if (fabs(sekunda) >= 60 ) {
            if(sekunda < 0)     minuta--;        else        minuta++; 
            sekunda =  0; 
        }
        
        if ( fabs(minuta) >= 60 ) {
            if( minuta < 0 )    stepen--;     else        stepen++; 
                minuta = 0; 
        }
            if(cs) niz[i] = -niz[i];
        
                if(fabs(sekunda)  > 30){
                    for(j = i; j < n-1; j++) niz[j] = niz[j + 1];
                    n--;
                    i--;
                }
        }
        
        printf("Uglovi su:\n");
        
        for(i = 0; i < n; i++){
                cs = 0;
                    if(niz[i] < 0) {    niz[i] = -niz[i]  ; cs = 1; };
                    
                         sms  = ( niz[i] * 180 / PI ) * 3600; 
                         sms = (int) ( sms + 0.5 );          
                         stepen = sms / 3600;           
                         minuta = ( sms - stepen * 3600 ) / 60;
                         sekunda = sms - stepen * 3600 - minuta * 60 ;
                    
            if(cs) { niz[i] = -niz[i];  stepen = -stepen; }
                    
                        printf("%d stepeni %d minuta %d sekundi\n",stepen,minuta,sekunda);
        }
        
        return 0;
}

