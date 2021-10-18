#include <stdio.h>

int main() {
	double parc1, parc2 , prisustvo, zadaca, zavrsni,o1,o2,o3;
	printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
	scanf("%lf", &parc1);
	if(parc1<0 || parc1>20) {printf("Neispravan broj bodova"); return;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &parc2);
	if(parc2<0 || parc2>20) {printf("Neispravan broj bodova"); return;}
	printf("Prisustvo: ");
	scanf("%lf" , &prisustvo);
	if(prisustvo<0 || prisustvo>10) {printf("Neispravan broj bodova"); return;}
	printf("Zadace: ");
	scanf("%lf", &zadaca);
	if(zadaca<0 || zadaca>10) {printf("Neispravan broj bodova"); return;}
	printf("Zavrsni ispit: ");
	scanf("%lf" , &zavrsni);
	if(zavrsni<0 || zavrsni>40) {printf("Neispravan broj bodova"); return;}
	

	
	double parcc1, parcc2 , prisustvoo, zadacaa, zavrsnii;
	printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
	scanf("%lf", &parcc1);
	if(parcc1<0 || parcc1>20) {printf("Neispravan broj bodova"); return;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &parcc2);
	if(parcc2<0 || parcc2>20) {printf("Neispravan broj bodova"); return;}
	printf("Prisustvo: ");
	scanf("%lf" , &prisustvoo);
	if(prisustvoo<0 || prisustvoo>10) {printf("Neispravan broj bodova"); return;}
	printf("Zadace: ");
	scanf("%lf", &zadacaa);
	if(zadacaa<0 || zadacaa>10) {printf("Neispravan broj bodova"); return;}
	printf("Zavrsni ispit: ");
	scanf("%lf" , &zavrsnii);
	if(zavrsnii<0 || zavrsnii>40) {printf("Neispravan broj bodova"); return;}

	double parccc1, parccc2 , prisustvooo, zadacaaa, zavrsniii;
	printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
	scanf("%lf", &parccc1);
	if(parccc1<0 || parccc1>20) {printf("Neispravan broj bodova"); return;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &parccc2);
	if(parccc2<0 || parccc2>20) {printf("Neispravan broj bodova"); return;}
	printf("Prisustvo: ");
	scanf("%lf" , &prisustvooo);
	if(prisustvooo<0 || prisustvooo>10) {printf("Neispravan broj bodova"); return;}
	printf("Zadace: ");
	scanf("%lf", &zadacaaa);
	if(zadacaaa<0 || zadacaaa>10) {printf("Neispravan broj bodova"); return;}
	printf("Zavrsni ispit: ");
	scanf("%lf" , &zavrsniii);
	if(zavrsniii<0 || zavrsniii>40) {printf("Neispravan broj bodova"); return;}
	

	
	if(parc1>=0 && parc2>=0 && prisustvo>=0 && zadaca>=0 && zavrsni>=0 && parc1<=20 && parc2<=20 && zadaca<=10 && prisustvo<=10 &&zavrsni<=40) 
	{
	if((parc1+parc2+prisustvo+zadaca+zavrsni)<55) {o1=5;}
	else if((parc1+parc2+prisustvo+zadaca+zavrsni)>=55 && (parc1+parc2+prisustvo+zadaca+zavrsni)<65) { o1=6;}
	else if((parc1+parc2+prisustvo+zadaca+zavrsni)>=65 && (parc1+parc2+prisustvo+zadaca+zavrsni)<75) { o1=7;}
	else if((parc1+parc2+prisustvo+zadaca+zavrsni)>=75 && (parc1+parc2+prisustvo+zadaca+zavrsni)<85) {o1=8;}
	else if((parc1+parc2+prisustvo+zadaca+zavrsni)>=85 && (parc1+parc2+prisustvo+zadaca+zavrsni)<92) {o1=9;}
	else if((parc1+parc2+prisustvo+zadaca+zavrsni)>=92 && (parc1+parc2+prisustvo+zadaca+zavrsni)<=100) {o1=10;}
	}
	

	
		if(parcc1>=0 && parcc2>=0 && prisustvoo>=0 && zadacaa>=0 && zavrsnii>=0 && parcc1<=20 && parcc2<=20 && zadacaa<=10 && prisustvoo<=10 &&zavrsnii<=40) 
	{
	if((parcc1+parcc2+prisustvoo+zadacaa+zavrsnii)<55) {o2=5; }
	else if((parcc1+parcc2+prisustvoo+zadacaa+zavrsnii)>=55 && (parcc1+parcc2+prisustvoo+zadacaa+zavrsnii)<65) {o2=6;}
	else if((parcc1+parcc2+prisustvoo+zadacaa+zavrsnii)>=65 && (parcc1+parcc2+prisustvoo+zadacaa+zavrsnii)<75) {o2=7;}
	else if((parcc1+parcc2+prisustvoo+zadacaa+zavrsnii)>=75 && (parcc1+parcc2+prisustvoo+zadacaa+zavrsnii)<85) {o2=8;}
	else if((parcc1+parcc2+prisustvoo+zadacaa+zavrsnii)>=85 && (parcc1+parcc2+prisustvoo+zadacaa+zavrsnii)<92) {o2=9;}
	else if((parcc1+parcc2+prisustvoo+zadacaa+zavrsnii)>=92 && (parcc1+parcc2+prisustvoo+zadacaa+zavrsnii)<=100) {o2=10;}
}


	
		if(parccc1>=0 && parccc2>=0 && prisustvooo>=0 && zadacaaa>=0 && zavrsniii>=0 && parccc1<=20 && parccc2<=20 && zadacaaa<=10 && prisustvooo<=10 &&zavrsniii<=40) 
	{
	if((parccc1+parccc2+prisustvooo+zadacaaa+zavrsniii)<55) {o3=5; }
	else if((parccc1+parccc2+prisustvooo+zadacaaa+zavrsniii)>=55 && (parccc1+parccc2+prisustvooo+zadacaaa+zavrsniii)<65) {o3=6;}
	else if((parccc1+parccc2+prisustvooo+zadacaaa+zavrsniii)>=65 && (parccc1+parccc2+prisustvooo+zadacaaa+zavrsniii)<75) {o3=7;}
	else if((parccc1+parccc2+prisustvooo+zadacaaa+zavrsniii)>=75 && (parccc1+parccc2+prisustvooo+zadacaaa+zavrsniii)<85) {o3=8;}
	else if((parccc1+parccc2+prisustvooo+zadacaaa+zavrsniii)>=85 && (parccc1+parccc2+prisustvooo+zadacaaa+zavrsniii)<92) {o3=9;}
	else if((parccc1+parccc2+prisustvooo+zadacaaa+zavrsniii)>=92 && (parccc1+parccc2+prisustvooo+zadacaaa+zavrsniii)<=100) {o3=10;}
	}
	
	
	
	if(parc1>=0 && parc2>=0 && prisustvo>=0 && zadaca>=0 && zavrsni>=0 && parc1<=20 && parc2<=20 && zadaca<=10 && prisustvo<=10 && zavrsni<=40 && parcc1>=0 && parcc2>=0 && prisustvoo>=0 && zadacaa>=0 && zavrsnii>=0 && parcc1<=20 && parcc2<=20 && zadacaa<=10 && prisustvoo<=10 &&zavrsnii<=40 && parccc1>=0 && parccc2>=0 && prisustvooo>=0 && zadacaaa>=0 && zavrsniii>=0 && parccc1<=20 && parccc2<=20 && zadacaaa<=10 && prisustvooo<=10 &&zavrsniii<=40)
{	
	if( (parc1+parc2+prisustvo+zadaca+zavrsni)>=55 && (parcc1+parcc2+prisustvoo+zadacaa+zavrsnii)>=55 && (parccc1+parccc2+prisustvooo+zadacaaa+zavrsniii)>=55) 
	{ printf("Sva tri studenta su polozila."); 
	if(o1==o2 && o2==o3) { printf("\nSva tri studenta imaju istu ocjenu."); }
	else if(o1!=o2 && o2!=o3 && o1!=o3) {printf("\nSvaki student ima razlicitu ocjenu."); }
	else if((o1==o2 && o1!=o3) || (o1==o3 && o1!=o2) || (o2==o3 && o2!=o3)) {printf("\nDva od tri studenta imaju istu ocjenu."); } 
	}
	else if( (parc1+parc2+prisustvo+zadaca+zavrsni)<55 && (parcc1+parcc2+prisustvoo+zadacaa+zavrsnii)<55 && (parccc1+parccc2+prisustvooo+zadacaaa+zavrsniii)<55) 
	{ printf("Nijedan student nije polozio.");}
	else if( (parc1+parc2+prisustvo+zadaca+zavrsni)>=55 && (parcc1+parcc2+prisustvoo+zadacaa+zavrsnii)>=55 && (parccc1+parccc2+prisustvooo+zadacaaa+zavrsniii)<55)
	{ printf("Dva studenta su polozila."); }
	else if( (parc1+parc2+prisustvo+zadaca+zavrsni)>=55 && (parcc1+parcc2+prisustvoo+zadacaa+zavrsnii)<55 && (parccc1+parccc2+prisustvooo+zadacaaa+zavrsniii)>=55) 
	{ printf("Dva studenta su polozila."); }
	else if( (parc1+parc2+prisustvo+zadaca+zavrsni)<55 && (parcc1+parcc2+prisustvoo+zadacaa+zavrsnii)>=55 && (parccc1+parccc2+prisustvooo+zadacaaa+zavrsniii)>=55) 
	{printf("Dva studenta su polozila."); }
	else if( (parc1+parc2+prisustvo+zadaca+zavrsni)>=55 && (parcc1+parcc2+prisustvoo+zadacaa+zavrsnii)<55 && (parccc1+parccc2+prisustvooo+zadacaaa+zavrsniii)<55) 
	{printf("Jedan student je polozio."); }
	else if( (parc1+parc2+prisustvo+zadaca+zavrsni)<55 && (parcc1+parcc2+prisustvoo+zadacaa+zavrsnii)<55 && (parccc1+parccc2+prisustvooo+zadacaaa+zavrsniii)>=55) 
	{printf("Jedan student je polozio."); }
	else if( (parc1+parc2+prisustvo+zadaca+zavrsni)<55 && (parcc1+parcc2+prisustvoo+zadacaa+zavrsnii)>=55 && (parccc1+parccc2+prisustvooo+zadacaaa+zavrsniii)<55) 
	{printf("Jedan student je polozio."); }

}
	


	

	return 0;

}

