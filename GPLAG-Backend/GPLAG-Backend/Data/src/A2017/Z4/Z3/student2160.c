#include <stdio.h>
void najduzi_bp(char *s1, char *s2){
    int i=0;
    int duzina=0;
while(*s1 != '\0'){
    
	if((*s1 >='a' && *s1<= 'z') || (*s1 >= 'A' && *s1 <= 'Z')){    /*upisi slova u histogram*/
     char *pok1= s1;
     char *pok2=s1; 
     int histogram [150] = {0};    
     	while((*pok1 >='a' && *pok1<= 'z') || (*pok1 >= 'A' && *pok1 <= 'Z')) 
      if(histogram[(int)*pok1]==1) break;
             else
             {
                 histogram[(int)*pok1]++; 
                 duzina++;
             }
	pok1++;
      }
      duzina=pok1-pok2;
   }

while(*s2!= ' \0'){
       int histogram [150] = {0};
    for(i=0; i<150; i++){
if(duzina>duzina-1)
s2 = histogram[i];
    }
  }
}
/*int histogram [150] = {0};

while(*s1!= '\0'){
	if((*s1<= 'a' && *s1>='z') || (*s1<='A' && *s1<='Z')) br++;
	histogram[(int)*s1]++;
   }
}
*/
int main() {
	printf("Zadaća 4, Zadatak 3");
	return 0;
}
#include <stdio.h>
#include <ctype.h>	//zbog funkcije tolower cija upotreba u linijama 13 i 14 omogucava da zanemarim razliku izmedju velikih i malih slova

void najduzi_bp(char *p1, char *p2)
{
	int broj=0; //broj slova trenutnog podstringa
	while(*p1!='\0') {
		if((*p1>='a' && *p1<='z') || (*p1>='A' && *p1<='Z')) {
			char *pom=p1;
			char *poc=p1;//poc cuva pocetak stringa
			int histogram[200]= {0};
			while((*pom>='a' && *pom<='z') || (*pom>='A' && *pom<='Z')) {
				if(histogram[(int)tolower(*pom)]==1) break; //prije nego sto stavim slovo u histogram provjeravam da li se to slovo vec nalazi u histogramu
				else histogram[(int)tolower(*pom)]++;	//ako slovo nije u histogramu trenutno, smijem ga staviti
				pom++;
			}
			if((pom-p1)>broj) { //oduzimanjem ova dva pokazivaca dobijam duzinu podstringa i ako je ta duzina veca od prethodne ubacujem podstring u poslati prazni string
				broj=pom-p1;
				char *novi=p2;
				while(poc<pom && *poc!='\0') { //prvi dio uslova omedjuje podstring koji treba prepisat
					*novi++=*poc++;
				}
				*novi='\0';	//rucno postavljam kraj prosljedenog drugog stringa na '\0'
			}

		}
		p1++;
	}
}




int main()
{
	char string[]="ovo je neki primjer";
	char prazni[100]= {'a'};
	najduzi_bp(string, prazni);
	printf("%s", prazni);
	return 0;
}

#include <stdio.h>

int dva_od_tri(int prvi_niz[], int vel_od_prvog,int drugi_niz[], int vel_od_drugog, int treci_niz[], int vel_od_treceg)
{
	int broj=0,i,histogram_1[100]= {0},histogram_2[100]= {0},histogram_3[100]= {0}; //kreirali smo 3 pomocna niza (po jedan za svaki niz) i svaki od njih postavili na 0 
	for(i=0; i<vel_od_prvog; i++) {
		histogram_1[prvi_niz[i]]++;			//ako je clan niza jednak nekom datom broju, povecavamo odgovarajuci brojac za 1 
	}
	for(i=0; i<vel_od_drugog; i++) {
		
		histogram_2[drugi_niz[i]]++;		//ovaj nacin rjesavanja zadatka je moguc samo u slucaju kada su clanovi niza pozitivni cijeli brojevi(zbog indeksa)
	}
	for(i=0; i<vel_od_treceg; i++) {
		histogram_3[treci_niz[i]]++;
	}
											//uslov zadatka(linija 18)
	for(i=0; i<100; i++) {
		if((histogram_1[i]>=1 && histogram_2[i]>=1 && histogram_3[i]==0) || (histogram_1[i]>=1 && histogram_3[i]>=1 && histogram_2[i]==0) || (histogram_2[i]>=1 && histogram_3[i]>=1 &&  histogram_1[i]==0))
			broj++;

	}

	return broj;
}



int main()
{
	int niz1[]={1,2,3,4};
	int niz2[]={1,2,4,6,7};
	int niz3[]={1,3,4,8,9,10};
	dva_od_tri(niz1,4,niz2,5,niz3,6);
	
	return 0;
}
#include <stdio.h>

int izbaci_cifre(int *p1, int vel_1, int *p2, int vel_2)
{
	int histogram[10]= {0};		//da bismo prebrojali koliko puta se javlja svaka cifra iz niza cifara
	int *pom1=p1;
	int *pom2=p2;
	int broj,zadnji,k,postoji, negativan,i,j;
	for(i=0; i<vel_2; i++) {
		if(*pom2<0 || *pom2>9) return 0; //ako se u nizu nalzi vrijednost manja od 0 ili veca od 9 niz cifara nije ispravan
		histogram[*pom2]++;
		pom2++;
	}
	for(i=0; i<10; i++) {
		if(histogram[i]>1) return 0; //ako se neki od clanova ponavlja, niz cifara nije ispravan
	}
	for(i=0; i<vel_1; i++) {
		pom2=p2;					//vracamo pokazivac pom2 na pocetak niza cifri(p2 "cuva" pocetak)
		broj=*pom1;					// u varijablu broj smjestamo sadrzaj onog na sta pokazuje pokazivac pom1
		negativan=0;
		if(broj<0) {				//provjeramo da li je clan prvog niza negativan i ako jeste logicku promjenljivu negativan postavljamo na 1
			broj*=-1;
			negativan=1;
		}
		k=1;
		*pom1=0;
		do {
			pom2=p2;
			zadnji=broj%10;			//u varijablu zadnji smjestamo trenutno zadnju cifru broja
			postoji=0;
			for(j=0; j<vel_2; j++)		//krecemo se nizom cifara
				if(*pom2++==zadnji) postoji=1;  //provjeramo da li je odgovarajuca cifra iz niza cifara jednaka varijabli zadnji i ako jeste logicka promjenljiva postoji postaje 1
			if(postoji==0) {			//ako cifru iz odgovarajuceg clana prvog niza ne treba izbaciti
				*pom1+=k*zadnji;
				k*=10;
			}
			broj/=10;

		} while(broj!=0);

		if(negativan==1)
			*pom1*=-1;
		pom1++;
	}
	return 1;
}



int main()	
{
	int niz[4]= {1234, 3476, 3270, 66};
	int cifre[3]= {7,6,3};
	int i;
	izbaci_cifre(niz,4,cifre,3);
	for(i=0; i<4; i++)
		printf("%d ", niz[i]);
	return 0;
}
#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina)
{
	int max=0, indeks_i=0, indeks_j=0,i,j,k,l,clan=0,trenutno;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			trenutno=0; //broj pojavljivanja trenutnog clana
			for(k=0; k<visina; k++) {
				for(l=0; l<sirina; l++) {
					if(matrica[k][l]==matrica[i][j]) trenutno++;
					if(trenutno>max || (trenutno==max && matrica[i][j]<matrica[indeks_i][indeks_j])) { //drugi dio uslova: ako se vise clanova ponavlja jednak(najveci) broj puta, vraca se najmanji od tih clanova
						max=trenutno;
						indeks_i=i;	//cuvamo indekse clana sa maksimalnim brojem pojavljivanja
						indeks_j=j;
						clan=matrica[i][j];
					}
				}
			}
		}

	}
	return clan;
}





int izbaci_kolone(int mat[100][100], int visina, int sirina, int n)
{
	int i,j,k,l,postoji,kolone=sirina; //broj kolona koje ostanu nakon izbacivanja svakako ne moze biti veci od sirine zadate matrice
	for(j=0; j<sirina; j++) {
		for(i=0; i<visina; i++) {
			postoji=0;
			if(mat[i][j]==n) postoji=1;
			if(postoji) {		//"izbacujemo" sve kolone u kojima se javlja clan n uz ocuvanje redoslijeda
				for(k=j; k<sirina-1; k++) {
					for(l=0; l<visina; l++) {
						mat[l][k]=mat[l][k+1];
					}
				}
				sirina--;
				kolone--;
				j--;		//ponovo posmatrajmo kolonu koja je dosla na mjesto izbacene jer mozda i nju treba izbaciti
			}
		}
	}


	return kolone;
}

int main()
{
	int vis,sir,mat[100][100]= {0},i,j,rez=0,br=0,kolone=0;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d", &sir, &vis);
	for(i=0; i<vis; i++) {
		printf("Unesite elemente %d. reda: ", i+1);
		for(j=0; j<sir; j++) {

			scanf("%d", &mat[i][j]);
		}

	}
	while(1) { //posto ne znamo koliko ce se puta ova petlja izvrsiti pa smo  koristili beskonacnu
		rez=max(mat,vis,sir);
		kolone=izbaci_kolone(mat,vis,sir,rez);
		sir=kolone; //nakon poziva funkcije izbaci_kolone mijenja se i sirina matrice pa je i u main funkciji moramo promijeniti
		br++;
		if(kolone==0) {
			printf("\nNakon %d. prolaza matrica je prazna!", br);
			break;
		} else {
			printf("\nNakon %d. prolaza matrica glasi:\n", br);
			for(i=0; i<vis; i++) {
				for(j=0; j<kolone; j++) {
					printf("%5d", mat[i][j]);
				}
				printf("\n");
			}
		}
	}

	return 0;
}
#include <stdio.h>

int main() {
	int i,j,visina,isti=1,sirina,a[100][100], b[100][100], c[100][100], bra[10000]={0},brb[10000]={0},brc[10000]={0};
	
	
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &visina, &sirina);

	}while(visina>100 || visina<0 || sirina<0 || sirina>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			scanf("%d", &a[i][j]);
			if(a[i][j]<0) a[i][j]*=-1;
		}
	}
	
	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			scanf("%d", &b[i][j]);
			if(b[i][j]<0) b[i][j]*=-1;
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			scanf("%d", &c[i][j]);
			if(c[i][j]<0) c[i][j]*=-1;
		}
	}
	
	if(visina==1 && sirina==1){
		if(a[0][0]!=b[0][0] || a[0][0]!=c[0][0]) printf("NE\n");
		else printf("DA");
	}
	else{
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			
				bra[a[i][j]]++;
				brb[b[i][j]]++;
				brc[c[i][j]]++;
		}
		
	}
	
	for(i=0;i<10000;i++){
		if(bra[i]!=brb[i] || bra[i]!=brc[i]){
			isti=0;
			break;
		}
	}
	if(isti) printf("DA\n");
	else printf("NE\n");
	
	
	}
	return 0;
}
