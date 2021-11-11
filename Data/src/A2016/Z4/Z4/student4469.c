#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
void unesi(char niz[], int velicina){
    
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';

}


char* obuhvat(char *koordinate,float x1, float y1, float x2, float y2){
int i,brojacdecimala=0,brojacdotacke=0,brojcifara=0,negativan=0,niz[10],prvapripada=0;
float prvax=0,prvay=0,drugax=0,drugay=0,trecax=0,trecay=0,cetvrtax=0,cetvrtay=0;
char* vratikoord;
vratikoord=koordinate;
while(*koordinate!='\0'){



for(i=0;i<3;i++) {    //provjera ispravnosti za prva tri uredjena para je ista, za cetvrti par je drugacija jer nakon njega se ne pise zarez
 



if(*koordinate!='(') {
return koordinate=NULL;          //ako na pocetku stringa nije '(' string nije dobro formatiran i vracamo null pokazivac;

}
koordinate++;
if(*koordinate!='-' || *koordinate<48 || *koordinate>57){            //ako nakon zagrade nije - ili neki cijeli broj, vracamo null pokazivac;

return koordinate=NULL;

}

while(*koordinate!='\0') {
if ( (*koordinate=='-' && (*(koordinate+1)>=48 && *(koordinate+1)<=57) )    || (*koordinate>=48 && *koordinate<=57) )        {
while(*koordinate!=',') {
koordinate++;                                     //ako pokazuje na broj ili na minus, pa je nakon minusa broj, pomjeramo sve do zareza tj. do kraja prve koordinate
if(*koordinate=='\0') {                          //ako je u medjuvremenu kraj stringa, vracamo null pokazivac
 return koordinate=NULL;   
}
}
}
}

koordinate++;                          //pomjeramo pokazivac na sljedecu koordinatu, jer je tamo ostao na zarezu

while(*koordinate!='\0') {
if ( (*koordinate=='-' && (*(koordinate+1)>=48 && *(koordinate+1)<=57) )    || (*koordinate>=48 && *koordinate<=57) )        {
while(*koordinate!=')') {
koordinate++;                                //ako pokazuje na broj ili na minus, pa je nakon minusa broj, pomjeramo sve do zagrade, tj. kraja druge koordinate
                                             //ako je u medjuvremenu kraj stringa, vracamo null pokazivac
if(*koordinate=='\0') {

return koordinate=NULL;
}
}
}
}


koordinate++;                              //pomjeramo pokazivac poslije zagrade i provjeravamo da li je tu napisan zarez

if(*koordinate!=',') {
return koordinate=NULL;
}









koordinate++;
}

if(*koordinate!='(') {
return koordinate=NULL;

}
koordinate++;
if(*koordinate!='-' || *koordinate<48 || *koordinate>57){

return koordinate=NULL;

}

while(*koordinate!='\0') {
if ( (*koordinate=='-' && (*(koordinate+1)>=48 && *(koordinate+1)<=57) )    || (*koordinate>=48 && *koordinate<=57) )        {
while(*koordinate!=',') {
koordinate++;
if(*koordinate=='\0') {
 return koordinate=NULL;   
}
}
}
}

koordinate++;

while(*koordinate!='\0') {
if ( (*koordinate=='-' && (*(koordinate+1)>=48 && *(koordinate+1)<=57) )    || (*koordinate>=48 && *koordinate<=57) )        {
while(*koordinate!=')') {
koordinate++;

if(*koordinate=='\0') {             

return koordinate=NULL;
}
}
}
}


koordinate++;


if(*koordinate!='\0') {                       //na kraju cetvrtog uredjenog para ne treba biti zarez nego kraj stringa
    return koordinate=NULL;
}

}



return vratikoord;

}

int main() {
    char koordinate [100];
    float x1,x2,y1,y2;
    scanf("%f %f %f %f",&x1,&x2,&y1,&y2);
    unesi(koordinate,100);
    obuhvat(koordinate,x1,y1,x2,y2);
	return 0;
}
