#include <stdio.h>
#include <math.h>

float zaokruzi1(float* niz, int br){
    int i=0;
    for(; i<br; i++)
	niz[i]=round(niz[i]*10)/10;
	return 0;
	}

float preslozi(float* niz, int br, int k){
    int i, a, suma=0, j, p=0; float temp;
    a=zaokruzi1(niz, br);
    for(i=0; i<br; i++){
        suma=0;
        a=fabs(niz[i]*10);
        do{suma+=a%10;
           a=(a-a%10)/10;}while(a!=0);
    if(suma>=k){ if(i!=p){
                 temp=niz[p];
                 niz[p]=niz[i];
                 for(j=i; j>p+1; j--)
                 niz[j]=niz[j-1];
                 niz[p+1]=temp; p++;}
                 if(i==p)
                 p++;} 
    }
    return 0;
}	

int main(){
    float niz[100]={0}; int i, br, k;
    scanf("%d", &br);
    scanf("%d", &k);
    for(i=0; i<br; i++)
    scanf("%f", &niz[i]);
    i=preslozi(niz, br, k);
    return 0;
    
    
    
}