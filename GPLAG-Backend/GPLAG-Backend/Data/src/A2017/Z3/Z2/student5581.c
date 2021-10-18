#include <stdio.h>
double zaokruzi1 (double niz[], int n){
    for (int i=0; i<n; i++){
        niz[i]=int(niz[i]*10+0.5)/10.;
    }
    return niz[i];
} int suma_cifara (int br){
    int suma=0;
    do{
        int n=br%10;
        br=br/10;
        suma+=n;
    }while (br!=0);
    return suma;
}
void preslozi (double niz[],int k, int n){
    int red=0;
    for (int i=0; i<n; i++){
        if (suma_cifara(niz[i]*10)==k && i!=0){
            for (int j=(i-1); j>=red; j--){
                int temp=niz[]
            }
        }
    }
        
}
    
    
}
int main() {
	
	return 0;
}
