#include <stdio.h>

int prebroji_cifre(int broj)
{
	int brojac=0;
	while(broj!=0) {
		broj=broj/10;
		brojac++;
	}
	return brojac;
}
char* ubaci_broj (char* s, int broj)
{
	char* pozicija;
	char* poc=s;
	char* kraj;
	int desilo_se=0;
	int desilo_se1=0;
	
	if(broj<0) {
		broj=-broj;
		desilo_se=1;

	}
    while(*s==' ') s++;

	while(*s!='\0') {
		
		if(*s==' ') {
			int temp=broj;
			pozicija=s;
			kraj=pozicija;
            desilo_se1=0;

			while(*kraj!='\0') {
				if((*kraj>='A' && *kraj<='Z') || (*kraj>='a' && *kraj<='z'))
				desilo_se1=1;
				kraj++;

			}
			if(desilo_se1){
			if(*(pozicija+1)!=' ') {
				while(kraj>pozicija) {


					*(kraj+prebroji_cifre(broj)+1)= *kraj;
					kraj--;

				}
				kraj=kraj+prebroji_cifre(broj)+1;
				*kraj--=' ';
			} 
			else {

				while(kraj>pozicija) {


					*(kraj+prebroji_cifre(broj))= *kraj;
					kraj--;

				}
				kraj=kraj+prebroji_cifre(broj);
			}


			while(kraj>pozicija) {
				*kraj=temp%10 + '0';
				kraj--;
				temp=temp/10;
			}
			if(desilo_se) {
				while(*kraj!='\0')
					kraj++;
				while(kraj>pozicija) {
					*(kraj+1)=*kraj;
					kraj--;

				}
				*(kraj+1)='-';
			}




			while(*s==' ') s++;
			while(*s!='\0' && *s!=' ') s++;
			while(*s==' ') s++;
		}

}



		s++;
	}

	return poc;
}

int main()
{
	char string[50]="ovo je neki primjer";
	printf("%s",ubaci_broj(string,-123));

	return 0;
}






