#include <stdio.h>

int main() {
char novi_red, t, b, m;
float restoran_p, restoran_h, restoran_c, fastfood_p, fastfood_h, fastfood_c, bistro_p, bistro_h, bistro_c, nr_p, nr_h, nr_c, restoran_suma, fastfood_suma, bistro_suma, min_cijena, popust_p, popust_h, popust_c, min_popust; 
 


do{
printf("Unesite jelo za Tarika: ");
scanf("%c", &t);
scanf("%c", &novi_red);
printf("Unesite jelo za Bojana: ");
scanf("%c", &b);
scanf("%c", &novi_red);
printf("Unesite jelo za Mirzu: ");
scanf("%c", &m);
scanf("%c", &novi_red);
} while((t!='P' && t!='H' && t!='C') || (b!='P' && b!='H' && b!='C') || (m!='P' && m!='H' && m!='C'));


/*Restoran "Kod konja i konjusara"*/

restoran_p = 6.80;
restoran_h = 3.30;
restoran_c = 5.00;

/*Fast-food "Trovac"*/

fastfood_p = 8.00;
fastfood_h = 3.00;
fastfood_c = 3.90;

/*Bistro "Lorelei"*/

bistro_p = 5.30;
bistro_h = 5.00;
bistro_c = 6.00;


/*Broj narudzbi*/
nr_p = 0;
nr_h = 0;
nr_c = 0;



/*Sta jede Tarik*/
if(t == 'P') { 
    nr_p++;
} else if (t == 'H') {
    nr_h++;
} else if (t == 'C') {
    nr_c++;
}


/*Sta jede Bojan*/
if(b == 'P') {
    nr_p++;
} else if (b == 'H') { 
    nr_h++;
} else if (b == 'C') {
    nr_c++;
}


/*Sta jede Mirza*/
if(m == 'P') {
    nr_p++;
} else if (m == 'H') {
    nr_h++;
} else if (m == 'C') {
    nr_c++;
}



/*Suma za svako mjesto*/
restoran_suma = nr_p * restoran_p + nr_h * restoran_h + nr_c * restoran_c;
fastfood_suma = nr_p * fastfood_p + nr_h * fastfood_h + nr_c * fastfood_c;
bistro_suma = nr_p * bistro_p + nr_h * bistro_h + nr_c * bistro_c;



/*Pretpostavimo da je restoran najjeftiniji*/
min_cijena = restoran_suma;



if(fastfood_suma < min_cijena) {
    min_cijena = fastfood_suma;
}


if(bistro_suma < min_cijena){
    min_cijena = bistro_suma;
}


/*Ispis najjeftinijeg mjesta*/
if(min_cijena == restoran_suma) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", min_cijena );
if(min_cijena == bistro_suma) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", min_cijena);
if(min_cijena == fastfood_suma) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", min_cijena );




/*Provjera popusta kod restorana u slucaju da nije najjeftiniji*/
if(min_cijena != restoran_suma) {
    
    /*Popust na pizzu*/
    popust_p = nr_p * (restoran_p - restoran_p * 0.1) + nr_h * restoran_h + nr_c * restoran_c;
    
    /*Popust na hamburger*/
    popust_h = nr_p * restoran_p + nr_h * (restoran_h - restoran_h * 0.1) + nr_c * restoran_c;
    
    /*Popust na cevape*/
    popust_c = nr_p * restoran_p + nr_h * restoran_h + nr_c * (restoran_c - restoran_c * 0.1);
    
    
    
    min_popust = min_cijena;
   
    
    /*Provjera da li je sa popustom jeftinije od do sada najjeftinije sume*/
    if(popust_p < min_popust) {
        min_popust = popust_p;
    }
    if(popust_h < min_popust) {
        min_popust = popust_h;
    }
    if(popust_c < min_popust){
        min_popust = popust_c;
    }
    
    
    /*Ispis cijene sa popustom*/
    if(min_popust < min_cijena) {
        printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", min_popust);
    }
    
}



return 0;
}