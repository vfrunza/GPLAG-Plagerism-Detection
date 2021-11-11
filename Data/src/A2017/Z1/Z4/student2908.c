#include <stdio.h>

int main() {
	int red,kolona,sirina,i,j;
    do{
	printf("Unesite broj redova: ");
	scanf("%d",&red);
	}while(red<=0 || red>10);
	do{
	printf("Unesite broj kolona: ");
	scanf("%d",&kolona);
	}while(kolona<=0 || kolona>10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sirina);
	}while(sirina<=0 || sirina>10);

	for(i=0;i<(2*red+1);i++){             //broj redova ukupno jer npr. za red=1 treba nam 3 reda, za red=2 treba nam 5 redova itd--
		for(j=0;j<(kolona*sirina+kolona+1);j++){   //kolona*sirina oznacava koliko ima - , a kolona+1 nam oznacava sve pluseve pa sve kad se sabere dobije se ukupan broj kolona.
			if(i%2==0 && j%(sirina+1)==0)           //za sve parne i i za sve j djeljive sa sirina+1 jer se na tim mjestima nalaze plusebi 
                printf("+");
            if(i%2!=0 && j%(sirina+1)==0)           // -||- za 
                printf("|");                        
             if(i%2!=0 && j%(sirina+1)!=0)          // -||- za razmake     
                printf(" ");
             if(i%2==0 && j%(sirina+1)!=0)         //za sve parne i i za j koje nije djeljive sa sirina+1 jer se na tim mjestima nalaze -
            printf("-");
		}
		printf("\n");
	}
	return 0;
}
