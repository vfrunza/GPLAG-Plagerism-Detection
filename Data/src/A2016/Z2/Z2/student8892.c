#include <stdio.h>
#define PI 3.1415926
int main() {
    
    double niz[500], s, u;
    int i, stepen, minute, sekunde, n, j;
    
    
    
    printf ("Unesite broj uglova: ");
    scanf ("%d", &n);
    
      for (i=0; i<n; i++){
        scanf ("%lf", &niz[i]);
      }
    printf ("Uglovi su: \n");
    
    for (i=0; i<n; i++){
       
         u= 180. / PI * niz[i];
        if (u>0){
        s= u* 3600;
        s = (int) (s + 0.5);
        stepen=minute=sekunde=0;
        stepen = s / 3600;
        minute = (s - stepen * 3600) / 60;
        sekunde = s-(stepen *3600 + minute *60);
        if (sekunde >=60){
            sekunde -=60;
            minute ++;
            
        }
        if (minute >=60){
            minute-= 60;
            stepen++;
        }
        if (sekunde > 30){
            for (j =i; j<n- 1; j++){
                niz[j] = niz [j+ 1];
            }
                n--;
                i--;
        }
            
    }
    else {
        s= u * -3600.;
         s = (int) (s + 0.5);
        stepen=minute=sekunde=0;
        stepen = s/3600;
        minute = (s - stepen * 3600) / 60;
        sekunde = s - (stepen *3600 + minute *60);
        if (sekunde <= -60){
            sekunde +=60;
            minute --;
            
        }
        if (minute<=-60){
            minute+=60;
            stepen++;
            
        }
        if (sekunde > 30){
            for (j =i; j<n- 1; j++){
                niz[j] = niz [j+ 1];
            }
                n--;
                i--;
        }
    }
    }
    for (i=0; i<n; i++){
          int  minus=0;
        u= 180./PI * niz [i];
        if (u>0){
            s= u*3600.;
        }
        else {minus=1;
        s= u * -3600.;
        
        }
        s = (int) (s + 0.5);
  
        stepen = s / 3600;
        minute = (s- stepen *3600) /60;
        sekunde = s - (stepen*3600 + minute*60);
    
        if( sekunde >= 60){
        sekunde -=60;
        minute++;
        }
        if (minute >= 60){
        minute -=60;
        stepen++;
        }
    if (minus==1){
        if (stepen==0){
            printf ("%d stepeni %d minuta %d sekundi\n", stepen, minute, sekunde);
        }
       else  printf ("-%d stepeni %d minuta %d sekundi\n", stepen, minute, sekunde);
    }
    else {
        printf ("%d stepeni %d minuta %d sekundi\n", stepen, minute, sekunde);
        
    }
    }
    return 0;
    }
    
    
  



    
    
    
    
    
    