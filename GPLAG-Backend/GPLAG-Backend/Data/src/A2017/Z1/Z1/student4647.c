#include <stdio.h>

int main() {
	char tarik,bojan,mirza,novi_unos;
	double suma,suma_1,suma_2,suma_3,h,p,c;
	char H='H',P='P',C='C';
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&novi_unos);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novi_unos);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&novi_unos);
	
	if(tarik==H && bojan==H && mirza==H) {
	suma_1=3*3.30;
	suma_2=3*3.00;
	suma_3=3*5.00;
	
	if((suma_1<suma_2) && (suma_1<suma_3)){
	suma=suma_1;
	printf("Najjeftiniji je Restoran ""Kod konja i konjusara""(%.2f KM).",suma);
	return 0;
	}
	
	if((suma_2<suma_1) && (suma_2<suma_3)){
	suma=suma_2;
	printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).\n",suma);
	suma_1=3*((90./100)*3.30);
	if((suma_1<suma_2) && (suma_1<suma_3))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	
	if((suma_3<suma_1) && (suma_3<suma_2)){
	suma=suma_3;
	printf("Najjeftiniji je Bistro " "Lorelei" " (%.2f KM).\n",suma);
	suma_1=3*((90./100)*3.30);
	if((suma_1<suma_3) && (suma_3<suma_2))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	
	}
	else if(tarik==P && bojan==P && mirza==P){
	suma_1=3*6.80;
	suma_2=3*8.00;
	suma_3=3*5.30;
	
	 if((suma_1<suma_2) && (suma_1<suma_3)){
	suma=suma_1;
	printf("Najjeftiniji je Restoran ""Kod konja i konjusara""(%.2f KM).",suma);
	return 0;
	}
	
	if((suma_2<suma_1) && (suma_2<suma_3)){
	suma=suma_2;
	printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).\n",suma);
	suma_1=3*((90./100)*6.80);
	if((suma_1<suma_2) && (suma_1<suma_3))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	
	if((suma_3<suma_1) && (suma_3<suma_2)){
	suma=suma_3;
	printf("Najjeftiniji je Bistro " "Lorelei" " (%.2f KM).\n",suma);
	suma_1=3*((90./100)*6.80);
	if((suma_1<suma_3) && (suma_3<suma_2))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	
	}
	
  else if(tarik==C && bojan==C && mirza==C){
	suma_1=3*5.00;
	suma_2=3*3.90;
	suma_3=3*6.00;
	
	if((suma_1<suma_2) && (suma_1<suma_3)){
	suma=suma_1;
	printf("Najjeftiniji je Restoran ""Kod konja i konjusara""(%.2f KM).",suma);
	return 0;
	}
	
	if((suma_2<suma_1) && (suma_2<suma_3)){
	suma=suma_2;
	printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).\n",suma);
	suma_1=3*((90./100)*5.00);
	if((suma_1<suma_2) && (suma_1<suma_3))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	
	if((suma_3<suma_1) && (suma_3<suma_2)){
	suma=suma_3;
	printf("Najjeftiniji je Bistro ""Lorelei"" (%.2f KM).\n",suma);
	suma_1=3*((90. /100)*5.00);
	if((suma_1<suma_3) && (suma_1<suma_2))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	
	}

	else if((tarik==H && bojan==P && mirza==C) || (tarik==H && bojan==C && mirza==P)||(tarik==P && bojan==H && mirza==C)||(tarik==P && bojan==C && mirza==H)||(tarik==C && bojan==H && mirza==P)||(tarik==C && bojan==P && mirza==H)){
	suma_1=6.80+3.30+5.00;
	suma_2=8.00+3.00+3.90;
	suma_3=5.30+5.00+6.00;
	
	if((suma_1<suma_2) && (suma_1<suma_3)){
	suma=suma_1;
	printf("Najjeftiniji je Restoran ""Kod konja i konjusara""(%.2f KM).",suma);
	return 0;
	}
	
	if((suma_2<suma_1) && (suma_2<suma_3)){
	suma=suma_2;
	printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).\n",suma);
    h=((90./100)*6.80 + 3.30+5.00);
    p=((90./100)*3.30+6.80+5.00);
    c=((90./100)*5.00+6.80+3.30);
    if(h<p && h<c)
    suma_1=h;
    if(p<h && p<c)
    suma_1=p;
    if(c<h && c<p)
    suma_1=c;
	if((suma_1<suma_2) && (suma_1<suma_3))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	
	if((suma_3<suma_1) && (suma_3<suma_2)){
	suma=suma_3;
	printf("Najjeftiniji je Bistro ""Lorelei"" (%.2f KM).",suma);
	h=((90./100)*6.80 + 3.30+5.00);
    p=((90./100)*3.30+6.80+5.00);
    c=((90./100)*5.00+6.80+3.30);
    if(h<p && h<c)
    suma_1=h;
    if(p<h && p<c)
    suma_1=p;
    if(c<h && c<p)
    suma_1=c;
	if((suma_1<suma_3) && (suma_1<suma_2))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	
	}
	
  else if((tarik==H && bojan==H && mirza==P)||(tarik==H && bojan==P && mirza==H) ||(tarik==P && bojan==H &&mirza==H)){
	suma_1=(2*3.30)+6.80;
	suma_2=(2*3.00)+8.00;
	suma_3=(2*5.00)+5.30;
	
		if((suma_1<suma_2) && (suma_1<suma_3)){
	suma=suma_1;
	printf("Najjeftiniji je Restoran ""Kod konja i konjusara""(%.2f KM).",suma);
	return 0;
	}
	
	if((suma_2<suma_1) && (suma_2<suma_3)){
	suma=suma_2;
	printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).\n",suma);
    h=(2*(90./100)*3.30 + 6.80);
    p=((90./100)*6.80+2*3.30);
    if(h<p)
    suma_1=h;
    if(p<h)
    suma_1=p;
	if((suma_1<suma_2) && (suma_1<suma_3))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	
	if((suma_3<suma_1) && (suma_3<suma_2)){
	suma=suma_3;
	printf("Najjeftiniji je Bistro ""Lorelei"" (%.2f KM).\n",suma);
	h=(2*(90./100)*3.30 + 6.80);
    p=((90./100)*6.80+2*3.30);
    if(h<p)
    suma_1=h;
    if(p<h)
    suma_1=p;
	if((suma_1<suma_2) && (suma_1<suma_3))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	}
	
	else if(tarik==H && bojan==P && mirza==C){
	suma_1=6.80+3.30+5.00;
	suma_2=8.00+3.00+3.90;
	suma_3=5.30+5.00+6.00;
	
			if((suma_1<suma_2) && (suma_1<suma_3)){
	suma=suma_1;
	printf("Najjeftiniji je Restoran ""Kod konja i konjusara""(%.2f KM).",suma);
	return 0;
	}
	
	if((suma_2<suma_1) && (suma_2<suma_3)){
	suma=suma_2;
	printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).",suma);
    h=((10/100)*6.80+3.30+5.00);
    p=((10/100)*3.30+6.80+5.00);
    c=((10/100)*5.00+3.30+6.80);
    if(h<p && h<c)
    suma_1=h;
    if(p<h && p<c)
    suma_1=p;
    if(c<p && c<h)
    suma_1=c;
	if((suma_1<suma_2) && (suma_1<suma_3))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	
	if((suma_3<suma_1) && (suma_3<suma_2)){
	suma=suma_3;
	printf("Najjeftiniji je Bistro ""Lorelei"" ( %.2f KM).",suma);
	h=((10/100)*6.80+3.30+5.00);
    p=((10/100)*3.30+6.80+5.00);
    c=((10/100)*5.00+3.30+6.80);
    if(h<p && h<c)
    suma_1=h;
    if(p<h && p<c)
    suma_1=p;
    if(c<p && c<h)
    suma_1=c;
	if((suma_1<suma_2) && (suma_1<suma_3))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	}
	else if((tarik==H && bojan==H && mirza==C)||(tarik==H && bojan==H)||(tarik==C && bojan==H && mirza==H)){
	suma_1=(2*3.30)+5.00;
	suma_2=(2*3.00)+3.90;
	suma_3=(2*5.00)+6.00;
	
	if((suma_1<suma_2) && (suma_1<suma_3)){
	suma=suma_1;
	printf("Najjeftiniji je Restoran ""Kod konja i konjusara""(%.2f KM).",suma);
	return 0;
	}
	
	if((suma_2<suma_1) && (suma_2<suma_3)){
	suma=suma_2;
	printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).\n",suma);
    h=(2*(90./100)*3.30+5.00);
    c=((90./100)*5.00+2*3.30);
    if(h<c)
    suma_1=h;
    if(c<p)
    suma_1=c;
	if((suma_1<suma_2) && (suma_1<suma_3))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	
	if((suma_3<suma_1) && (suma_3<suma_2)){
	suma=suma_3;
	printf("Najjeftiniji je Bistro ""Lorelei"" (%.2f KM).\n",suma);
	 h=(2*(90./100)*3.30+5.00);
    c=((90./100)*5.00+2*3.30);
    if(h<c)
    suma_1=h;
    if(c<p)
    suma_1=c;
	if((suma_1<suma_2) && (suma_1<suma_3))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	}
else if((tarik==H && bojan==P && mirza==P)||(tarik==P && bojan==H && mirza==P)||(tarik==P && bojan==P && mirza==H)){
	suma_1=(2*6.80)+3.30;
	suma_2=(2*8.00)+3.00;
	suma_3=(2*5.30)+5.00;
	
	if((suma_1<suma_2) && (suma_1<suma_3)){
	suma=suma_1;
	printf("Najjeftiniji je Restoran ""Kod konja i konjusara""(%.2f KM).",suma);
	return 0;
	}
	
	if((suma_2<suma_1) && (suma_2<suma_3)){
	suma=suma_2;
	printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).\n",suma);
    h=(2*(90./100)*6.80+3.30);
    p=((90./100)*3.30+2*6.80);
    if(h<p)
    suma_1=h;
    if(p<c)
    suma_1=p;
	if((suma_1<suma_2) && (suma_1<suma_3))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	
	if((suma_3<suma_1) && (suma_3<suma_2)){
	suma=suma_3;
	printf("Najjeftiniji je Bistro ""Lorelei"" (%.2f KM).\n",suma);
	 h=(2*(90./100)*6.80+3.30);
    p=((90./100)*3.30+2*6.80);
    if(h<p)
    suma_1=h;
    if(p<c)
    suma_1=p;
	if((suma_1<suma_2) && (suma_1<suma_3))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	}
	
	else if((tarik==C && bojan==P && mirza==P) || (tarik==P && bojan==C && mirza==P)||(tarik==P && bojan==P && mirza==C)){
	suma_1=(2*6.80)+5.00;
	suma_2=(2*8.00)+3.90;
	suma_3=(2*5.30)+6.00;
		if((suma_1<suma_2) && (suma_1<suma_3)){
	suma=suma_1;
	printf("Najjeftiniji je Restoran ""Kod konja i konjusara""(%.2f KM).",suma);
	return 0;
	}
	
	if((suma_2<suma_1) && (suma_2<suma_3)){
	suma=suma_2;
	printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).\n",suma);
    c=(2*(90./100)*6.80+5.00);
    p=((90./100)*5.00+2*6.80);
    if(c<p)
    suma_1=c;
    if(p<c)
    suma_1=p;
	if((suma_1<suma_2) && (suma_1<suma_3))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	
	if((suma_3<suma_1) && (suma_3<suma_2)){
	suma=suma_3;
	printf("Najjeftiniji je Bistro ""Lorelei"" (%.2f KM).\n",suma);
	 c=(2*(90./100)*6.80+5.00);
    p=((90./100)*5.00+2*6.80);
    if(c<p)
    suma_1=c;
    if(p<c)
    suma_1=p;
	if((suma_1<suma_2) && (suma_1<suma_3))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",suma_1);
	return 0;
	}
	}
else if ((tarik==C && bojan==P && mirza==C) || (tarik==P && bojan==C && mirza==C)||(tarik==P && bojan==P && mirza==C)){
	suma_1=5.00+5.00+6.80;
	suma_2=2*3.90+8.00;
	suma_3=2*6.00+5.30;
	
	if((suma_1<suma_2) && (suma_1<suma_3)){
	suma=suma_1;
	printf("Najjeftiniji je Restoran ""Kod konja i konjusara""(%.2f KM).",suma);
	return 0;
	}
	
	if((suma_2<suma_1) && (suma_2<suma_3)){
	suma=suma_2;
	printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).\n",suma);
    c=(2*(90./100)*5.00+6.80);
    p=((90./100)*6.80+2*5.00);
    if(c<p)
    suma_1=c;
    if(p<c)
    suma_1=p;
	if((suma_1<suma_2) && (suma_1<suma_3))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	
	if((suma_3<suma_1) && (suma_3<suma_2)){
	suma=suma_3;
	printf("Najjeftiniji je Bistro ""Lorelei"" (%.2f KM).\n",suma);
	 c=(2*(90./100)*5.00+6.80);
    p=((90./100)*6.80+2*5.00);
    if(c<p)
    suma_1=c;
    if(p<c)
    suma_1=p;
	if((suma_1<suma_2) && (suma_1<suma_3))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	}
	
else if ((tarik==C && bojan==C && mirza==H) || (tarik==H && bojan==C && mirza==C)||(tarik==C && bojan==H && mirza==C)) {
	suma_1=(2*5.00)+3.30;
	suma_2=(2*3.90)+3.00;
	suma_3=(2*6.00)+5.00;
	
	if((suma_1<suma_2) && (suma_1<suma_3)){
	suma=suma_1;
	printf("Najjeftiniji je Restoran ""Kod konja i konjusara""(%.2f KM).",suma);
	return 0;
	}
	
	if((suma_2<suma_1) && (suma_2<suma_3)){
	suma=suma_2;
	printf("Najjeftiniji je Fast-food ""Trovac"" (%.2f KM).\n",suma);
    c=(2*(90./100)*5.00+3.30);
    h=((90./100)*3.30+2*5.00);
    if(c<h)
    suma_1=c;
    if(h<c)
    suma_1=h;
	if((suma_1<suma_2) && (suma_1<suma_3))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	
	if((suma_3<suma_1) && (suma_3<suma_2)){
	suma=suma_3;
	printf("Najjeftiniji je Bistro ""Lorelei"" (%.2f KM).\n",suma);
	 c=(2*(90./100)*5.00+3.30);
    h=((90./100)*3.30+2*5.00);
    if(c<h)
    suma_1=c;
    if(h<c)
    suma_1=h;
	if((suma_1<suma_2) && (suma_1<suma_3))
	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",suma_1);
	return 0;
	}
	}
	
	return 0;
}
