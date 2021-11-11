#include <stdio.h>

int main() {
	
	int unos[100]={0},tmp,i=0,j,temp[1000]={0},brojac=0,izlaz[1000]={0},u=0;
	
	printf("Unesite velicinu niza: ");
	scanf("%d",&j);
	printf("Unesite clanove niza: ");

	while(i<j) 
	scanf("%d", &unos[i++]);
	i=j;

	while(--i>=0){
		if(unos[i]==0)
		{
			temp[brojac]=0;
			brojac++;}
		while (unos[i]) {
			temp[brojac]=unos[i]%10;
			unos[i]=unos[i]/10;
			brojac++;
		}
	}
	i=-1;
	while(++i<brojac/2){
		tmp=temp[i];
		temp[i]=temp[brojac-i-1];
		temp[brojac-i-1]=tmp;
	}
	i=0;
	j=0;
	while(i<brojac){
		izlaz[u]=temp[i];
		do{
		j++;
		i++;
		}
		while(temp[i-1]==temp[i] && i<brojac);
		u++;
		izlaz[u]=j;
		j=0;
		u++;
	}
	i=0;
	printf("Finalni niz glasi:\n");
	while(i<u)printf("%d ",izlaz[i++]);
	return 0;
}
