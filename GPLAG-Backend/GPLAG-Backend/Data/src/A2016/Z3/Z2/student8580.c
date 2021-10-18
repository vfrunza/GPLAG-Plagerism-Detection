#include <stdio.h>
#include <math.h>
 int izbaci(int *niz,int vel){
     int s=1,prethodni=1,drugi_prethodni=1,f,j,i,max;
    max=niz[0];
    for(i=0;i<vel;i++)
    if(niz[i]>max)
    max=niz[i];
   do{
    f=0;
        s=prethodni+drugi_prethodni;
        for(i=0;i<vel;i++){
        if(niz[i]==s){
        f=1;break;}
        else if(niz[i]==1){
        f=1;break;}
        }
        
           
                if(f){
        for(j=i;j<vel-1;j++){
        niz[j]=niz[j+1];}
        vel--;
        
        continue;
        }
        drugi_prethodni=prethodni;
        prethodni=s;}
        while(s<=max);
        return vel;
    
}

void ubaci(int* niz,int vel){
     int i,j=10,c,x,n,s,k,temp;
     int suma=0;
    k=1;
	 for(i=vel;i<2*vel;i++)
        niz[i]=0;
        for(i=vel;i<2*vel;i++){
        for(s=i;s>k;s--){
        temp=niz[s-1];
        niz[s-1]=niz[s];
        niz[s]=temp;}k+=2;}
   n=vel;
    for(i=0;i<2*n;i+=2){
        x=niz[i];
        suma=0;
        do{
            c=fabs(x%j);
            x=x/j;
            suma=suma+c;
        }while(x!=0);
        niz[i+1]=suma;vel++;
    }
}

int main() {
    int niz[20];
    int i,vel,n;
    vel=10;
    printf("Unesite niz od 10 brojeva: ");
    for (i=0; i<vel; i++) {
        scanf("%d",&niz[i]);
    }
    ubaci(niz,vel);
    vel=2*vel;
    n=izbaci(niz,vel);
    printf("Modificirani niz glasi: ");
    for(i=0;i<n;i++)
    if(i<n-1)
    printf("%d, ",niz[i]);
    else
    printf("%d.",niz[n-1]);
    
    
    
    
    

	return 0;
}