OSTALE STVARI IZ TUTORIJALA

fja za drugi najveci element u nizu brojeva:

int drugi (int niz[], int velicina)
{
 int najveci = 0;
 int i = 0, flag = 0, indeks;
 /*Trazenje najveceg elementa*/
 for (i = 0; i < velicina; i++)
 {
 if (niz[i] >= najveci)
najveci = niz[i];
 }
 int drugi = 0;
 /*Trazenje drugog najveceg elementa, ako ima vise istih vracamo drugi najveci sa lijeve strane.*/
 for (i = velicina - 1; i >= 0; i--)
 {
 if (niz[i] >= drugi && niz[i] != najveci)
 {
drugi = niz[i];
indeks = i;
flag = 1; /*Ako je vrijednost varijable 'drugi' makar jednom promijenjena, znaci da nisu svi
elementi niza isti*/
 }
 }
 /*Provjera da li su svi elementi isti*/
 if (najveci == 0 || flag == 0)
indeks = -1;
 return indeks;
}






zaokruzivanje brojeva na jednu decimalu

void zaokruzi(float* pok, int velicina)
{
 int i;
 float temp;
 /*Zaokruzivanje brojeva na jednu decimalu*/
 for(i=0; i<velicina; i++)
 {
*(pok+i) = *(pok+i) + 0.05;
temp=(int)(*(pok+i)*10);
 *(pok+i)=temp/10.;
 }
}






fja za prebrojavanje samoglasnika

int samoglasnici (char* string)
{
 int i=0;
 while(*string!='\0')
 {
 if(*string=='a' || *string=='e'
|| *string=='i' || *string=='o'
|| *string=='u' || *string=='A'
|| *string=='B' || *string=='C'
|| *string=='D' || *string=='E')
i++;
string++;
 }
 return i;
}





fja za prebrojavanje odredjenog znaka

int prebrojavanje(char* string, char znak)
{
 int broj = 0;
 while(*string != '\0')
 {
 if(*string == znak)
broj++;
string++;
 }
 return broj;
}





fja za promjenu malih slova u velika

char* velika(char* string)
{
 char* prvi=string;
 while(*string != '\0')
 {
 if(*string>='a' && *string<='z')
 *string = (*string) - 32;
string++;
 }
 return prvi;
}




ROT13 FJA

void rot13(char *string)
{
 while(*string!='\0')
 {
 /*Ako se slovo nalazi izmedju A i M, sifruj ga za 13 slova unaprijed*/
 if((*string>='A' && *string<='M') || (*string>='a' && *string<='m'))
 *string+=13;
 /*Ako se slovo nalazi izmedju M i Z, sifruj ga za 13 slova unazad*/
 else if ((*string>='N' && *string<='Z') || (*string>='n' && *string<='z'))
 *string-=13;
string++;
 }
}









