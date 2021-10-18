#include <stdio.h>

int main() {
//	printf("Zadaća 1, Zadatak 4");
    int i, j, r, k, p, x, y, sk, m, n, r1, k1;
    do{ printf("Unesite broj redova: ");
        scanf("%d", &r);} while(r<=0 || r>10);
    do{ printf("Unesite broj kolona: ");
        scanf("%d", &k);}  while(k<=0 || k>10);
    do{ printf("Unesite sirinu jedne kolone: ");
        scanf("%d", &sk);} while(sk<=0 || sk>10);
    
    r1=(r*2)+1;
    k1=k+1+(sk*k);
    
//    for(i=1; i<=k; i++){
    	for(j=1; j<=r1; j++){
    	//	p=1; //?????????
    		x=0; y=0;
    		for(p=1; p<=k; p++){
    			if(j%2==0){
    			    if(y==0){ printf("|"); y=1;}
    				for(n=1; n<=sk; n++){ printf(" ");}
    				printf("|");
    //				if(x==0){ printf("+"); x=1;}
    //				for(m=1; m<=sk; m++) printf("-");
    //				printf("+");
    			}
    			else{
    			    if(x==0){ printf("+"); x=1;}
    				for(m=1; m<=sk; m++) printf("-");
    				printf("+");
    			}
    		}
    		printf("\n");
    	}
    //	printf("\n");
 //   }
    
	return 0;
}
