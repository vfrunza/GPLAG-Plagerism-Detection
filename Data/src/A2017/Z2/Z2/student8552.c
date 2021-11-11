#include <stdio.h>

int main() {
	int nizA[100],vel,i,nizB[1000],brojac[101]={0},j;
	do{
	printf("Unesite velicinu niza: ");
	scanf("%d", &vel);
	if(vel>100) printf("Dozvoljeno je maksimalno 100 elemenata!\n");
	}while(vel>100);


	printf("Unesite clanove niza: ");
	do{
	for(i=0;i<vel;i++){
	scanf("%d",&nizA[i]);
	if(nizA[i]<=0){
    printf("Clan nije prirodan broj!\n");
    i--;
	}
	}
    }while(nizA[i]>0);

    for(i=0;i<vel;i++){
    	nizB[i]=nizA[i];
    }
    for(i=0;i<vel;i++){
    printf("%d",nizB[i]);}
    
   for(i=0;i<vel;i++){
       for(j=i+1;j<vel;j++){
       	if(nizB[i]==nizB[j])
       	brojac[nizB[i]]++;
       }	
    }
    printf("\nFinalni niz glasi:\n");
    for(i=0;i<vel;i++){
    	printf("%d %d ",nizB[i],brojac[nizB[i]]);
    }
	
	return 0;
}
