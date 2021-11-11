#include <stdio.h>
#define pizza P
#define cevap C
#define hamburger H

int main(){
	
	char t,b,m,nr,P,C,H;
	float Pr,Pff,Pb,Hr,Hff,Hb,Cr,Cff,Cb,ruk,ffuk,buk;
	nr='\n';
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &t);
	scanf("%c", &nr);
	
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &b);
	scanf("%c", &nr);
	
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &m);
	scanf("%c", &nr);
	
	Pr=6.80;
	Pff=8.00;
	Pb=5.30;
	Hr=3.30;
	Hff=3.00;
	Hb=5.00;
	Cr=5.00;
	Cff=3.90;
	Cb=6.00;
	
	
	if(t==P && b==P && m==P){ 
		ruk=3*Pr;
		ffuk=3*Pff;
		buk=3*Pb;
		
		if(ruk<ffuk && ruk<buk){
			printf("Najjeftiniji je Restoran ""Kod konja i konjusara"" (%.2f KM).",ruk);
		}else if(ffuk<ruk && ffuk<buk){
			printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).",ffuk);
		}else if(buk<ffuk && buk<ruk){
			printf("Najjeftiniji je Bistro ""Lorelei"" (%.2f KM).",buk);
		}
		
	}
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}