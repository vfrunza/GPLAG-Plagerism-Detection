#include <stdio.h>

/*int pomocna(int broj){
	int naopak=0;
	while (broj!=0) {
		naopak*=10;
		naopak+=broj%10;
		broj/=10;
	}
	return naopak;
}
*/

char* ubaci_broj(char *s, int broj)
{
	char *p=s;
	int d=0;
	int n = 0;
	//char * pt = NULL;
	char *kt = NULL;
	char *pi = NULL;
	
	if(broj<0) {
		d++; //DA IZBROJIMO MINUS 
		n=-1*broj;
	} else n=broj;

	while (n!=0) {
		n/=10;
		d++;
	}
//	d++;

	while (*p != '\0') {
		if(*p!='\0' && ((*p>='A' && *p<='Z') || (*p>='a' && *p<='z'))) {
		//	pt=p;
			while((*p>='A' && *p<='Z') || (*p>='a' && *p<='z'))
				p++;
			if(*p==' ' || *p=='\0') {
				kt=p;
				char *pom=kt;
				while (*pom!='\0')  pom++;
				int ima_slova = 0;
				char *pomocni = kt;
				while(*kt != '\0'){
					if(((*kt>='A' && *kt<='Z') || (*kt>='a' && *kt<='z'))) ima_slova = 1;
					kt++;
				} // da ubacije samo iza rijeci ako imamo samo neki znak il broj ne treba
				// npr ako imamo @ nesto 
				// 		 	imamo 4 nesto iza @ i 4 ne treba dodavati broj neko samo iza svake rijeci 
				// DA LI SAM NA ZADNJOJ RIJECI 
				
				kt = pomocni;
				if(ima_slova == 1){
				pi=kt+d;
				int x = 1;
				if(*(kt+1) == ' ') x = 0; //sto ces dodavat ramak ako vec ima 
				while (pom>kt) { //ODGURUJEMO NA KRAJ tj pravimo mjesto za ubacivanje
					*(pom+d+x)=*pom; // da ostavimo razmak jer obrnuto prepisujem
					// jer ne moram dodavati jedan razmak 
					pom--;
				}
				
				n=broj;
				if(*p != '\0') // samo ako smo na kraju a u suprotnom uvijek treba dodati razmak poslije ubacivanja
			     *(pi+1) = ' ';
				if(n<0) n*=-1;
				while (n!=0) {
					if(*pi != '\0' && pi>=s)  //OVO se nece nikad desiti i vrijedi i bez ovog 
					//PI JE POK NA KRAJU MJESTA GDJE TREBA UBACITI I IDEMO PI--
					*pi = n%10+'0'; //  iz inta pretvaram u char 
					pi--;
					n/=10;
				}
				if(broj<0) *pi='-';
				}
			}
		}
		if(*p == '\0') break;
		p++;

	}
	return s;
}


int main()
{

	char s[500]= " ovo je      je     ";
	ubaci_broj(s, 32);
	printf("%s",s);
	return 0;

}
