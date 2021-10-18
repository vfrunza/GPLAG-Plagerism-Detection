#include<stdio.h>
int main(){
	int n,i=0,c,b=0,x,a=0,z=0,j,m=0;
	int niz[100];
	int niza[100];
	int nizc[100];
	int nizx[100]={0};
	int nizb[100]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
    printf("Unesite clanove niza: ");
 for(i=0;i<n;i++){
		scanf("%d",&niz[i]);
	}
	for(i=0;i<n;i++){
		if (i==0)z=0;
		else z=b;
		nizx[i]=niz[i];
		do{
			nizx[i]=nizx[i]/10;
			b++;
		}while(nizx[i]!=0);
		x=b-1;
		do{
		niza[x]=niz[i]%10;
		niz[i]=niz[i]/10;
		x--;
		
		}	while(x>=z);
		
	}
	printf("Finalni niz glasi:\n");
	for(i=0;i<b;i++){
		printf("%d ",niza[i]);
		a=1;
		if(i==b-1);
		else
		{
			while(niza[i]==niza[i+1]){
				a++;
				i++;
				if (i+1>=b)break;
			}
		}
		if (i==b-1)printf("%d",a);
		else printf("%d ",a);
		

	}

	


	return 0;
}

/* Dat je neki niz prirodnih brojeva (uključujući nulu), na primjer:
	233, 38, 17777, 7737, 152
Ovaj niz možemo posmatrati kao neprekinuti niz cifara, npr:
	23338177777737152
Potrebno je u drugi niz upisati: cifru i koliko puta uzastopno se ta cifra nalazi u ovom 
neprekinutom nizu. Dakle, za primjer iznad drugi niz bi trebao glasiti:
	2 1 3 3 8 1 1 1 7 6 3 1 7 1 1 1 5 1 2 1
(cifra 2 se pojavljuje 1 put uzastopno, cifra 3 se pojavljuje 3 puta uzastopno itd.)

Potrebno je napisati program koji radi na sljedeći način: najprije se unosi veličina polaznog 
niza (max. 100 elemenata), a zatim i njegovi članovi (osigurati da se ponavlja unos ako 
korisnik proba unijeti neispravnu veličinu ili član koji nije prirodan broj ili nula). 
Zatim se na ekranu ispisuju članovi drugog niza razdvojeni znakom razmaka.

Primjer ulaza i izlaza:
Unesite velicinu niza: 5
Unesite clanove niza: 233 38 17777 7737 152
Finalni niz glasi:
	2 1 3 3 8 1 1 1 7 6 3 1 7 1 1 1 5 1 2 1

 */