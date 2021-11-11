#include <stdio.h>
#define BROJ_NIZ1 100
#define BROJ_NIZ2 1000
int main() {
    int i,j,n,br1=0,k,nizA[BROJ_NIZ1]={0},nizB[BROJ_NIZ2]={0},a,br=0,brojac=1,nizC[BROJ_NIZ2]={0};
    printf("Unesite velicinu niza: ");
    scanf("%d",&n);
    printf("Unesite clanove niza: ");
    for(i=0;i<n;i++){
        scanf("%d",&nizA[i]);
    } 
    j=0;
    for(i=n-1;i>=0;i--){
        if(nizA[i]==0) { nizB[j]=0; j++;}
        while (nizA[i]!=0){
            a=nizA[i]%10;
            nizA[i]/=10;
            nizB[j]=a;
            j++;
        }
    }
    br=j;
    k=0;
    for(i=br-1;i>0;i--){
        nizC[k]=nizB[i];
        while(nizB[i]==nizB[i-1]){
            brojac++;
                i--;
                if(i==0) break;
        }
        k++;
        nizC[k]=brojac;
        k++;
        brojac=1;
        
     if(i==1 && nizB[i]!=nizB[i-1]){
            nizC[k]=nizB[i-1];
            k++;
            nizC[k]=brojac;
            k++;
        }
    }
    br1=k;
    printf("Finalni niz glasi:\n");
    for(i=0;i<br1;i++){
        printf("%d ",nizC[i]);
    }
    
    
    
    
	return 0;
}
