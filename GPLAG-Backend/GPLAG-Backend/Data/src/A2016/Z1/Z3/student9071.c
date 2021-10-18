#include <stdio.h>

int main() {
printf("Unesite vozila: ");
	int c=0,b=0,s=0,v=0,p=0,max=0,nr=0;
	float bj=0;
	char U;

	/*Beskonacna petlja*/
while(1){
	

		
		U = getchar();
		
		/*Test koji je karakter*/
			if ((U =='c')||(U =='C')){
			c++;
		}	else if ((U =='b')||(U =='B')){
			b++;
		}	else if ((U =='s')||(U =='S')){
			s++;
		}	else if ((U =='v')||(U =='V')){
			v++;
		}	else if ((U =='p')||(U =='P')){
			p++;
		}	else if ((U =='k')||(U =='K')){
			break; /*Bijeg iz petlje*/
		}   else {
			printf("Neispravan unos\n");
		}

}
nr=c+b+s+v+p;

/*Trazenje maksimalne vrijednosti, eventualno vise njih*/

max=c;

if (b>max){
	max=b;
} 
if(s>max){
	max=s;
} 
if (v>max){
	max=v;
} 
if (p>max){
	max=p;
}
if (nr!=0){
bj=((float)max/nr)*100;
	
} else {
bj=0;
}
printf("Ukupno evidentirano %d vozila.",nr);
printf("\nNajpopularnija boja je ");

if (max==c){
	printf("crna (%.2f%%).",bj);
}
else if (max==b){
	printf("bijela (%.2f%%).",bj);
}
else if (max==s){
	printf("siva (%.2f%%).",bj);
}
else if (max==v){
	printf("crvena (%.2f%%).",bj);
}
else if (max==p){
	printf("plava (%.2f%%).",bj);
}





	return 0;
}
