#include <stdio.h>
int dva_od_tri(int nizA[], int a, int nizB[], int b, int nizC[], int c){
    int i, j, i1, br, brA=0, brB=0,brojac=0;
    
    for(i=0; i<a; i++){
        br=0;
        brA=0;
        brB=0;
        if(i>0){
            for(i1=i; i1>0; i1--){
                if(nizA[i]==nizA[i1-1]) br++;
            }
        }
        
        if(br==0){
            for(j=0; j<b; j++){
                if(nizA[i]==nizB[j]) brA++;
            }
            for(j=0; j<c; j++){
                if(nizA[i]==nizC[j]) brB++;
            }
            if((brA!=0 && brB==0)||(brA==0 && brB!=0)) brojac++;
        }
    }
    
    for(i=0; i<b; i++){
        brA=0;
        br=0;
        if(i>0){
            for(i1=i; i1>0; i1--){
                if(nizB[i]==nizB[i1-1]) br++;
            }
        }
        if(br==0){
        for(j=0; j<a; j++){
           if(nizA[j]==nizB[i]) brA++;
        }
    if(brA==0){
        for(j=0; j<c; j++){
            if(nizB[i]==nizC[j]) brojac++;
        }
    }
    }
    }
    
    return brojac;
}
int main() {
	int nizA[100], nizB[100], nizC[100], a, b, c, br,i;
	printf("Unesite velicinu niza A: ");
	scanf("%d",&a);
	printf("Unesite clanove niza A: ");
	for(i=0; i<a; i++){
	    scanf("%d",&nizA[i]);
	}
	printf("Unesite velicinu niza B: ");
	scanf("%d",&b);
	printf("Unesite clanove niza B: ");
	for(i=0; i<b; i++){
	    scanf("%d",&nizB[i]);
	}
	printf("Unesite velicinu niza C: ");
	scanf("%d",&c);
	printf("Unesite clanove niza C: ");
	for(i=0; i<c; i++){
	    scanf("%d",&nizC[i]);
	}
	br=dva_od_tri(nizA,a,nizB,b,nizC,c);
	printf("%d",br);
	return 0;
}