#include <stdio.h> 

/*c=99 C=67 s=115 S=83 b=98 B=66 v=118 V=86 p=112 P=80 k=107 K=75*/

int main() {
	char z;
	int bc=0, bb=0, bs=0, bv=0, bp=0, ue=0;
	float pc=0, pb=0, ps=0, pv=0, pp=0;
	

	printf("Unesite vozila: ");
    while(1==1){
    	scanf("%c",&z);
    	if(z=='k' || z=='K'){break;}
    	else if(z=='c' || z=='C'){bc++;}
    	else if(z=='b' || z=='B'){bb++;}
    	else if(z=='s' || z=='S'){bs++;}
    	else if(z=='v' || z=='V'){bv++;}
    	else if(z=='p' || z=='P'){bp++;}
    	else {printf("Neispravan unos\n");}
    	}
    
		ue=bc+bb+bs+bv+bp;
		printf("Ukupno evidentirano %d vozila.\n", ue);
		
		pc=(bc*100.)/ue;
		pb=(bb*100.)/ue;
		ps=(bs*100.)/ue;
		pv=(bv*100.)/ue;
		pp=(bp*100.)/ue;
		
		if(ue==0){printf("Najpopularnija boja je crna (0.00%).");}
		else if(bc>=bb && bc>=bs && bc>=bv && bc>=bp ){printf("Najpopularnija boja je crna (%.2f%).", pc);}
		else if(bb>=bc && bb>=bs && bb>=bv && bb>=bp ){printf("Najpopularnija boja je bijela (%.2f%).", pb);}
		else if(bs>=bc && bs>=bb && bs>=bv && bs>=bp ){printf("Najpopularnija boja je siva (%.2f%).", ps);}
		else if(bv>=bc && bv>=bs && bv>=bb && bv>=bp ){printf("Najpopularnija boja je crvena (%.2f%).", pv );}
		else if(bp>=bc && bp>=bs && bp>=bv && bp>=bb ){printf("Najpopularnija boja je plava (%.2f%).", pp);}

		
		
		
		

	return 0;
}
