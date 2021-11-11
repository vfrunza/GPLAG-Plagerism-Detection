#include <stdio.h>

int main() {
    int niz1[100],niz2[500],niz3[200];
    int n,i=0,j;
    int velNiza2=0,tmp,k,counter;
    printf("Unesite velicinu niza: ");
    do{
    scanf("%d",&n);
    }while(n>100 || n<=0);
    printf("Unesite clanove niza: ");
    for(i=0;i<n;i++){
        scanf("%d",&niz1[i]);
        if(niz1[i]<0)i--;
    }
    for(i=0;i<n;i++){
        tmp=niz1[i];
        counter=0;
        if(tmp==0){counter=1;tmp=0;}
        else while(tmp!=0){
            counter++;
            tmp/=10;
        }    
        velNiza2+=counter;
        tmp=niz1[i];
        for(j=velNiza2-1;j>=velNiza2-counter;j--){
                niz2[j]=tmp%10;
                tmp/=10;    
        }
    }    
    k=0;
    for(i=0;i<velNiza2;i++){
        counter=1;
        for(j=i+1;j<velNiza2;j++){
            if(niz2[i]==niz2[j])counter++; 
            else break;
        }
        niz3[k]=niz2[i];
        k++;
        niz3[k]=counter;
        k++;
        i=j-1;
    }
    printf("Finalni niz glasi: \n");
    for(i=0;i<k;i++)printf("%d ",niz3[i]);
	return 0;
}