#include <stdio.h>
/*char* ubaci_broj (char* s, int br) {
	int naopak=0,duzina=0,brojac=0,temp;
	char *pok=s;
	while (br!=0)
	{
		naopak*=10;
		naopak+=br%10;
		brojac++;
		br/=10;
	}
	temp=naopak;
	duzina=brojac;
	while (*s!='\0') {
		if (*s==' '){
			s++;
			char *kraj=s;
			while (*kraj!='\0') kraj++;
			while (kraj>s) {
				*(kraj+duzina)=*kraj;
				kraj--;
			}
			temp=naopak;
			while (temp!=0) {
				*pok=(char) (temp%10+48);
				temp/=10;
				s++;
				return pok;
			}
			s++;
		}
	}
	return pok;
*/
int fun(int br) {
	int naopak;
	while (br!=0)
	{
		naopak*=10;
		naopak+=br%10;
		br/=10;
	}
	return naopak;
}
char* ubaci_broj (char* s, int br) {
	int i=0,naopak;
	int temp;
	char *pok=s;
	naopak=fun(br);
	temp=naopak;
	while (s[i]!='\0')
	{
		if (s[i]==' ')
		{
			naopak=temp;
			while (naopak!=0)
			{
				s[i]=(char) (naopak%10+48);
				naopak/=10;
				i++;
			}
			s[i++]=' ';
		}
	   i++;
	}
	s[i]='\0';
	return pok;
}
int main() {
	return 0;
}
