#include <stdio.h>
#define KP 6.80
#define KH 3.30
#define KC 5.00
#define FP 8.00
#define FH 3.00
#define FC 3.90
#define BP 5.30
#define BH 5.00
#define BC 6.00
int main() {
	char tarik,mirza,bojan,novi_red,novi_red1;
/*ovo su one cijene koliko ce raja potrositi u nekom od njih*/
	float cijena_restorana=0.0, cijena_bistro=0.0, cijena_fastfood=0.0;
	float najjeftinije;
	float cijena_restoranaN;
	do{
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);}
	while(tarik!='H' && tarik!='P' && tarik!='C');
	scanf("%c",&novi_red);
	do{
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);}
	while(bojan!='H' && bojan!='P' && bojan!='C');
	scanf("%c",&novi_red1);
	do{
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);}
	while(mirza!='P' && mirza!='H' && mirza!='C');
	/*sta ce tarik jesti da vidimo mogucnosti */
	
	if (tarik=='P'){
/*tarik hoce pizzu, ima 3 opcije da vidimo...*/
			cijena_restorana=cijena_restorana+KP;
			cijena_fastfood=cijena_fastfood+FP;
			cijena_bistro=cijena_bistro+BP;
			}
/*tarik hoce hamburger, ima 3 opcije..*/			
	if(tarik=='H'){
			cijena_restorana=cijena_restorana+KH;
			cijena_fastfood=cijena_fastfood+FH;
			cijena_bistro=cijena_bistro+BH;
			}
/*tarik hoce cevape, ima 3 opcije..*/			
			if(tarik=='C'){
			cijena_restorana=cijena_restorana+KC;
			cijena_fastfood=cijena_fastfood+FC;
			cijena_bistro=cijena_bistro+BC;
			}
/*kao sto smo vidjeli mogucnosti za tarika tako cemo i za bojana i mirzu*/	
	
	 if(bojan=='P'){
		cijena_restorana=cijena_restorana+KP;
		cijena_fastfood=cijena_fastfood+FP;
		cijena_bistro=cijena_bistro+BP;
		}
		
		if(bojan =='H'){
		cijena_restorana=cijena_restorana+KH;
		cijena_fastfood=cijena_fastfood+FH;
		cijena_bistro=cijena_bistro+BH;
		}
		
		if(bojan=='C'){
		cijena_restorana=cijena_restorana+KC;
		cijena_fastfood=cijena_fastfood+FC;
		cijena_bistro=cijena_bistro+BC;
	}
	
	if(mirza=='P'){
		cijena_restorana=cijena_restorana+KP;
		cijena_fastfood=cijena_fastfood+FP;
		cijena_bistro=cijena_bistro+BP;
		}
		
	if(mirza=='H'){
		cijena_restorana=cijena_restorana+KH;
		cijena_fastfood=cijena_fastfood+FH;
		cijena_bistro=cijena_bistro+BH;
		}
		
	if(mirza=='C'){
		cijena_restorana=cijena_restorana+KC;
		cijena_fastfood=cijena_fastfood+FC;
		cijena_bistro=cijena_bistro+BC;
			}
	/*gdje je najjeftinije da vidimo*/
	
	if(cijena_restorana<cijena_bistro && cijena_restorana<cijena_fastfood) najjeftinije=cijena_restorana;
	else if (cijena_fastfood<cijena_restorana && cijena_fastfood<cijena_bistro) najjeftinije=cijena_fastfood;
	else if (cijena_bistro<cijena_restorana && cijena_bistro<cijena_fastfood) najjeftinije=cijena_bistro;
	
	/*koji je od 3 navedena najjeftinije ispisujemo*/
	if(najjeftinije==cijena_restorana){
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",cijena_restorana);
	return 0;
	}
	else { if(najjeftinije==cijena_bistro){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",cijena_bistro);
	}
	else if (najjeftinije==cijena_fastfood) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",cijena_fastfood);
	}
	
	/*ako restoran nije najjeftiniji, trebamo provjeriti bi li bio jeftiniji sa popustom*/
	/*pa hajmo vidjet sta mogu kupiti u restoranu svaki od njih*/
	if(bojan=='P' || tarik=='P' || mirza=='P'){
		 if(tarik=='P') cijena_restoranaN=cijena_restorana*0.9;
		else if(bojan=='P') cijena_restoranaN=cijena_restorana*0.9;
		else if(mirza=='P') cijena_restoranaN=cijena_restorana*0.9;
	}
	if(tarik=='H' || bojan=='H' || mirza=='H'){
		 if(tarik=='H') cijena_restoranaN=cijena_restorana*0.9;
		else if(bojan=='H') cijena_restoranaN=cijena_restorana*0.9;
		else if(mirza=='H') cijena_restoranaN=cijena_restorana*0.9;
	}
	if(tarik=='C' || bojan=='C' || mirza=='C'){
		 if(tarik=='C') cijena_restoranaN=cijena_restorana*0.9;
		else if(bojan=='C') cijena_restoranaN=cijena_restorana*0.9;
		else if(mirza=='C') cijena_restoranaN=cijena_restorana*0.9;
	}
	if(tarik=='P' && bojan=='H' && mirza=='C') {
		if(tarik=='P') cijena_restoranaN=cijena_restorana-KP*0.1;
		if(bojan=='H') cijena_restoranaN=cijena_restorana-KH*0.1;
		if(mirza=='C') cijena_restoranaN=cijena_restorana-KC*0.1;
	}
	if(tarik=='H' && bojan=='P' && mirza=='C'){
		if(tarik=='H') cijena_restoranaN=cijena_restorana-KH*0.1;
		if(bojan=='P') cijena_restoranaN=cijena_restorana-KP*0.1;
		if(mirza=='C') cijena_restoranaN=cijena_restorana-KC*0.1;
	}
	if(tarik=='C' && bojan=='H' && mirza=='P'){
		if(tarik=='C') cijena_restoranaN=cijena_restorana-KC*0.1;
		if(bojan=='H') cijena_restoranaN=cijena_restorana-KH*0.1;
		if(mirza=='P') cijena_restoranaN=cijena_restorana-KP*0.1;
		}
	if(tarik=='P' && bojan=='C' && mirza=='H'){
		if(tarik=='P') cijena_restoranaN=cijena_restorana-KP*0.1;
		if(bojan=='C') cijena_restoranaN=cijena_restorana-KC*0.1;
		if(mirza=='H') cijena_restoranaN=cijena_restorana-KH*0.1;
	}
	if(tarik=='H' && bojan=='C' && mirza=='P'){
		if(tarik=='H') cijena_restoranaN=cijena_restorana-KH*0.1;
		if(bojan=='C') cijena_restoranaN=cijena_restorana-KC*0.1;
		if(mirza=='P') cijena_restoranaN=cijena_restorana-KP*0.1;
	}
	if(tarik=='C' && bojan=='P' && mirza=='H'){
		if(tarik=='C') cijena_restoranaN=cijena_restorana-KC*0.1;
		if(bojan=='P') cijena_restoranaN=cijena_restorana-KP*0.1;
		if(mirza=='H') cijena_restoranaN=cijena_restorana-KH*0.1;
		
	}
	if(tarik=='C' && bojan=='C' && mirza=='P'){
		if(tarik=='C') cijena_restoranaN=cijena_restorana-KC*0.2;
		if(bojan=='C') cijena_restoranaN=cijena_restorana-KC*0.2;
		if(mirza=='P') cijena_restoranaN=cijena_restorana-KP*0.1;
	}
	if(tarik=='C' && bojan=='C' && mirza=='H'){
		if(tarik=='C') cijena_restoranaN=cijena_restorana-KC*0.2;
		if(bojan=='C') cijena_restoranaN=cijena_restorana-KC*0.2;
		if(mirza=='H') cijena_restoranaN=cijena_restorana-KH*0.1;
	}
	if(tarik=='H' && bojan=='H' && mirza=='C'){
		if(tarik=='H') cijena_restoranaN=cijena_restorana-KH*0.2;
		if(bojan=='H') cijena_restoranaN=cijena_restorana-KH*0.2;
		if(mirza=='C') cijena_restoranaN=cijena_restorana-KC*0.1;
	}
	if(tarik=='H' && bojan=='H' && mirza=='P'){
		if(tarik=='H') cijena_restoranaN=cijena_restorana-KH*0.2;
		if(bojan=='H') cijena_restoranaN=cijena_restorana-KH*0.2;
		if(mirza=='P') cijena_restoranaN=cijena_restorana-KP*0.1;
	}
	if(tarik=='P' && bojan=='P' && mirza=='C'){
		if(tarik=='P') cijena_restoranaN=cijena_restorana-KP*0.2;
		if(bojan=='P') cijena_restoranaN=cijena_restorana-KP*0.2;
		if(mirza=='C') cijena_restoranaN=cijena_restorana-KC*0.1;
	}
	if(tarik=='P' && bojan=='P' && mirza=='H'){
		if(tarik=='P') cijena_restoranaN=cijena_restorana-KP*0.2;
		if(bojan=='P') cijena_restoranaN=cijena_restorana-KP*0.2;
		if(mirza=='H') cijena_restoranaN=cijena_restorana-KH*0.1;
	}
	if(tarik=='C' && bojan=='P' && mirza=='C'){
		if(tarik=='C') cijena_restoranaN=cijena_restorana-KC*0.2;
		if(bojan=='P') cijena_restoranaN=cijena_restorana-KP*0.1;
		if(mirza=='C') cijena_restoranaN=cijena_restorana-KC*0.2;
	}
	if(tarik=='C' && bojan=='H' && mirza=='C'){
		if(tarik=='C') cijena_restoranaN=cijena_restorana-KC*0.2;
		if(bojan=='H') cijena_restoranaN=cijena_restorana-KH*0.1;
		if(mirza=='C') cijena_restoranaN=cijena_restorana-KC*0.2;
	}
	if(tarik=='H' && bojan=='C' && mirza=='H'){
		if(tarik=='H') cijena_restoranaN=cijena_restorana-KH*0.2;
		if(bojan=='C') cijena_restoranaN=cijena_restorana-KC*0.1;
		if(mirza=='H') cijena_restoranaN=cijena_restorana-KH*0.2;
	}
	if(tarik=='H' && bojan=='P' && mirza=='H'){
		if(tarik=='H') cijena_restoranaN=cijena_restorana-KH*0.2;
		if(bojan=='P') cijena_restoranaN=cijena_restorana-KP*0.1;
		if(mirza=='H') cijena_restoranaN=cijena_restorana-KH*0.2;
	}
	if(tarik=='P' && bojan=='C' && mirza=='P'){
		if(tarik=='P') cijena_restoranaN=cijena_restorana-KP*0.2;
		if(bojan=='C') cijena_restoranaN=cijena_restorana-KC*0.1;
		if(mirza=='P') cijena_restoranaN=cijena_restorana-KP*0.2;
	}
	if(tarik=='P' && bojan=='H' && mirza=='P'){
		if(tarik=='P') cijena_restoranaN=cijena_restorana-KP*0.2;
		if(bojan=='H') cijena_restoranaN=cijena_restorana-KH*0.1;
		if(mirza=='P') cijena_restoranaN=cijena_restorana-KP*0.2;
	}
	if(tarik=='P' && bojan=='C' && mirza=='C'){
		if(tarik=='P') cijena_restoranaN=cijena_restorana-KP*0.1;
		if(bojan=='C') cijena_restoranaN=cijena_restorana-KC*0.2;
		if(mirza=='C') cijena_restoranaN=cijena_restorana-KC*0.2;
	}
	if(tarik=='P' && bojan=='H' && mirza=='H'){
		if(tarik=='P') cijena_restoranaN=cijena_restorana-KP*0.1;
		if(bojan=='H') cijena_restoranaN=cijena_restorana-KH*0.2;
		if(mirza=='H') cijena_restoranaN=cijena_restorana-KH*0.2;
	}
	if(tarik=='H' && bojan=='P' && mirza=='P'){
		if(tarik=='H') cijena_restoranaN=cijena_restorana-KH*0.1;
		if(bojan=='P') cijena_restoranaN=cijena_restorana-KP*0.2;
		if(mirza=='P') cijena_restoranaN=cijena_restorana-KP*0.2;
	}
	if(tarik=='H' && bojan=='C' && mirza=='C'){
		if(tarik=='H') cijena_restoranaN=cijena_restorana-KH*0.1;
		if(bojan=='C') cijena_restoranaN=cijena_restorana-KC*0.2;
		if(mirza=='C') cijena_restoranaN=cijena_restorana-KC*0.2;
		
	}
	if(tarik=='C' && bojan=='P' && mirza=='P'){
		if(tarik=='C') cijena_restoranaN=cijena_restorana-KC*0.1;
		if(bojan=='P') cijena_restoranaN=cijena_restorana-KP*0.2;
		if(mirza=='P') cijena_restoranaN=cijena_restorana-KP*0.2;
	}
	if(tarik=='C' && bojan=='H' && mirza=='H'){
		if(tarik=='C') cijena_restoranaN=cijena_restorana-KC*0.1;
		if(bojan=='H') cijena_restoranaN=cijena_restorana-KH*0.2;
		if(mirza=='H') cijena_restoranaN=cijena_restorana-KH*0.2;
	}
	}
	
	 if(cijena_restoranaN<najjeftinije){
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena_restoranaN);
	}
	
	return 0;
	
}
