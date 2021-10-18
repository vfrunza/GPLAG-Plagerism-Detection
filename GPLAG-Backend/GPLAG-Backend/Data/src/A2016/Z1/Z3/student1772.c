#include <stdio.h>

int main() {
	char znak;
	int bb=0,cb=0,sb=0,vb=0,pb=0,max=0,ub=0;
	float avg;
	printf("Unesite vozila: ");
	znak=getchar();
	while(znak !='k' && znak !='K'){
		if(znak =='b' || znak =='B'){
			ub++;
			bb++;
		}
		else if(znak =='c' || znak =='C'){
			ub++;
			cb++;
		}
		else if(znak =='s' || znak == 'S'){
			ub++;
			sb++;
		}
		else if(znak =='v' || znak =='V'){
			ub++;
			vb++;
		}
		else if(znak =='p' || znak =='P'){
			ub++;
			pb++;
		}
		else printf("Neispravan unos\n");
			znak=getchar();
	}
	if(bb>max){
		max=bb;
	}
	if(cb>max){
		max=cb;
	}
	if(sb>max){
		max=sb;
	}
	if(vb>max){
		max=vb;
	}
	if(pb>max){
		max=pb;
	}
	avg=(float)max/(float)ub*100;
	printf("Ukupno evidentirano %d vozila.\n",ub);
	if(max==0){
		printf("Najpopularnija boja je crna (0.00%).");
	}
	else if(max==bb){
		printf("Najpopularnija boja je bijela (%.2f%%).",avg);
	}
	else if(max==cb){
		printf("Najpopularnija boja je crna (%.2f%%).",avg);
	}
	else if(max==sb){
		printf("Najpopularnija boja je siva (%.2f%%).",avg);
	}
	else if(max==vb){
		printf("Najpopularnija boja je crvena (%.2f%%).",avg);
	}
	else if(max==pb){
		printf("Najpopularnija boja je plava (%.2f%%).",avg);
	}
	return 0;
}
