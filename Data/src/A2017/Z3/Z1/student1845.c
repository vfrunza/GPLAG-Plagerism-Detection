#include <stdio.h>
#include <math.h>
int dva_od_tri(int* niz1, int vel1, int* niz2, int vel2, int* niz3, int vel3){
    int i,j,k,br=0, pom1[100000], pom2[100000], pom3[100000];
    int br1=vel1,br2=vel2,br3=vel3, brojaci[100000];
    for(i=0; i<br1; i++) {
        pom1[i]=niz1[i];
    }
    for(j=0; j<br2; j++) {
        pom2[j]=niz2[j];
    }
    for(k=0; k<br3; k++) {
        pom3[k]=niz3[k];
    }
    for(i=0; i<br1-1; i++) {
        for(j=i+1; j<br1; j++) {
            if(pom1[i]==pom1[j]){
                for(k=j; k<br1-1; k++) {
                    pom1[k]=pom1[k+1];
                }
                    br1--;
                    j--;
            }
        }
    }
    for(i=0; i<br2-1; i++) {
        for(j=i+1; j<br2; j++) {
            if(pom2[i]==pom2[j]){
                for(k=j; k<br2-1; k++) {
                    pom2[k]=pom2[k+1];
                }
                 br2--;
                    j--;
            }
        }
    }
    for(i=0; i<br3-1; i++) {
        for(j=i+1; j<br3; j++) {
            if(pom3[i]==pom3[j]){
                for(k=j; k<br3-1; k++) {
                    pom3[k]=pom3[k+1];
                }
                 br3--; 
                    j--;
            }
        }
    }
    for(i=0; i<1000; i++) {
        brojaci[i]=0;
    }
    for(i=0; i<br1; i++) {
        brojaci[pom1[i]]++;
        
    }
    for(j=0; j<br2; j++) {
        brojaci[pom2[j]]++;
    }
    for(k=0; k<br3; k++) {
        brojaci[pom3[k]]++;
    }
    for(i=0; i<1000; i++) {
        if(brojaci[i]==2)
        br++;
    }
    return br;
}
int main (){
   
    return 0;
}