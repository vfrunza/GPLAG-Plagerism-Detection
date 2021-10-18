#include <stdio.h>
#include<math.h>
#define PI 3.141592
#define EPSILON 0.0001


int main() {
double x1, y1, x2, y2, x3, y3, a, b, c, stepen_a, minut_a, sekund_a, stepen_b, minut_b, sekund_b, stepen_c, minut_c, sekund_c, alfa, beta, gama, al, be, ga, alfa0, beta0, gama0, max_ugao;
int s, m, sc, max_stepen, max_minut, max_sekund;

/* !!!! */
/*U Autotestu na C9, test 6 prikazuje 51 sekundu, ali zbog zaokruzivanja na cijeli broj dobije se 52. Ostavila sam funkciju round umjesto ceil-a koji bi namjestio tacan rezultat sto ne bi bilo ispravno.*/

printf("Unesite koordinate tacke t1: ");
scanf("%lf %lf", &x1, &y1);
printf("Unesite koordinate tacke t2: ");
scanf("%lf %lf", &x2, &y2);
printf("Unesite koordinate tacke t3: ");
scanf("%lf %lf", &x3, &y3);
	

c = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
a = sqrt(pow((x3-x2),2) + pow((y3-y2),2));
b = sqrt(pow((x3-x1),2) + pow((y3-y1),2));


alfa = acos((b * b + c * c - a * a) / (2 * b * c));
beta = acos((a * a + c * c - b * b) / (2 * a * c));
gama = acos((a * a + b * b - c * c) / (2 * a * b));

alfa0 = alfa;
beta0 = beta;
gama0 = gama;

/*Pretvaranje radijana u stepen*/
alfa *= (180 / PI);
stepen_a = floor (alfa);


beta *= (180 / PI);
stepen_b = floor (beta);

gama *= (180 / PI);
stepen_c = floor (gama);



/*Izracunavanje minuta*/
alfa -= stepen_a;
alfa *= 60;
minut_a = floor (alfa);

beta -= stepen_b;
beta *= 60;
minut_b = floor (beta);

gama -= stepen_c;
gama *= 60;
minut_c = floor (gama);



/*Izracunavanje sekundi*/
alfa -= minut_a;
alfa *= 60;
sekund_a = round (alfa);

beta -= minut_b;
beta *= 60;
sekund_b = round (beta);

gama -= minut_c;
gama *= 60;
sekund_c = round (gama);

max_ugao = alfa0;
max_stepen = stepen_a;
max_minut = minut_a;
max_sekund = sekund_a;


if(stepen_b > max_stepen){
    max_ugao = beta0;
    max_stepen = stepen_b;
    max_minut = minut_b;
    max_sekund = sekund_b;
}

if(stepen_c > max_stepen){
    max_ugao = gama0;
    max_stepen = stepen_c;
    max_minut = minut_c;
    max_sekund = sekund_c;
}


/*Ukoliko tri tacke leze na istom pravcu*/
if(fabs(max_ugao - PI) < EPSILON ) {
    printf("Linija\n");
    printf("Najveci ugao ima 180 stepeni, 0 minuta i 0 sekundi.");
    return 1;
}


/*Testiranje za pravougli*/
if(fabs(alfa0 - PI / 2) < EPSILON || fabs(beta0 - PI / 2) < EPSILON || fabs(gama0 - PI / 2) < EPSILON) {
    printf("Pravougli\n");
}

/*Testiranje za jednakostranicni*/
if(fabs(alfa0 - beta0) < EPSILON && fabs(beta0 - gama0) < EPSILON) {
    printf("Jednakostranicni\n");
}

/*Testiranje za jednakokraki*/
else if(
    (fabs(alfa0 - beta0) < EPSILON && fabs(alfa0 - gama0) >= EPSILON) || (fabs(alfa0 - gama0) < EPSILON && fabs(alfa0 - beta0) >= EPSILON) || (fabs(beta0 - gama0) < EPSILON && fabs(beta0 - alfa0) >= EPSILON)
) {
    printf("Jednakokraki\n");
}

/*Raznostranicni*/
else {
    printf("Raznostranicni\n");
}

printf("Najveci ugao ima %d stepeni, %d minuta i %d sekundi.", max_stepen, max_minut, max_sekund);


return 0;

}
