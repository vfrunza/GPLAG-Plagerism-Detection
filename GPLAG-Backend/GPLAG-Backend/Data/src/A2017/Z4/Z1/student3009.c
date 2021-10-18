#include<stdio.h>
#include<math.h>
void unesi(char niz[], int velicina) {
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

char* ubaci_broj (char*tekst,int broj){
	int num=broj;
	int broj_cifri=0,pom=fabs(broj);
	char*vrati=tekst;
do{
	broj_cifri++;
	pom/=10;
} while(pom>0);



while (*tekst!='\0'){
	if (*tekst==' '){
		char*kraj=tekst;
		while(*kraj!='\0') kraj++;
		while (kraj>tekst) {
			*(kraj+broj_cifri)=*kraj;
			kraj--;
		}
			
		int temp=fabs(broj);
		while(temp>0)
		{
			int ubaci=temp%10;
			temp/=10;
			*(tekst+broj_cifri)=(ubaci+'0');
			tekst--;
		}
	
	
		tekst+=broj_cifri;
	}
	tekst++;
}
int m=fabs(broj);
int zadnja_cifra=m%10;
char* ponovo_tekst=vrati;
while(*ponovo_tekst!='\0'){
	if (*ponovo_tekst==zadnja_cifra+'0'){
		char *kraj2=ponovo_tekst;
		while(*kraj2!='\0') kraj2++;
		while (kraj2>ponovo_tekst) {
			*(kraj2+1)=*kraj2;
			kraj2--;
		}
		*(ponovo_tekst+1)=' ';
	
	
	}ponovo_tekst++;
}
char* ponovo_tekst2=vrati;
	int pom2=fabs(num),j;
for (j=1;j<broj_cifri;j++){
	pom2/=10;
}
int ispitaj=pom2;
if (num<0){
while(*ponovo_tekst2!='\0'){
	if (*ponovo_tekst2==ispitaj+'0'){
		char *kraj3=ponovo_tekst2-1;
		while(*kraj3!='\0') kraj3++;
		while (kraj3>ponovo_tekst2) {
			*(kraj3+1)=*kraj3;
			kraj3--;
		}
		*(ponovo_tekst2+1)=*ponovo_tekst2;
		*ponovo_tekst2='-';
ponovo_tekst2++;
		
	
	}ponovo_tekst2++;
}
}


return vrati;	
}



int main(){
	int m,br=0,j;
	scanf("%d",&m);
	int s=fabs(m);
	int l=fabs(m);
	while(s>0){
			printf("%d",s%10);
		br++;
		s/=10;
	
	}
	printf("%d ",br);
	printf("%d",m%10);
for (j=1;j<5;j++){
l/=10;
}	
printf("\n%d",l);
return 0;
}

