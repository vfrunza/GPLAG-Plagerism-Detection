#include <stdio.h>

int provjeri (const char *s)
{
	int i,j,k=0,brojac=0,br_vracanja=0,br=0,duzina=0,m=0,T=0,br1=0,br2=0,d=0,pon=0,n=0;
	char tag[1000],niz[1000]="\0";
	/*trazenje broja char-ova datog stringa u oznaci "d"*/
	while(s[k]!='\0') {
		d++;
		k++;
	}
	/*vraćanje indeksa "k" */
	for(i=0; i<d; i++)
		k--;
	/*brojanje znakova "<" i ">" */
	while(s[k]!='\0') {
		if(s[k]=='<') br1++;
		if(s[k]=='>') br2++;
		k++;
	}
	/*jedan od uslova*/
	if(br1!=br2) return 0;
	br1=0;
	br2=0;
	/*vraćanje indeksa "k"*/
	for(i=0; i<d; i++)
		k--;
		/*početak "glavnog" dijela programa*/
	while(s[k]!='\0') {
		/*traženje "zatvaranja" tag-a*/
		/*duzina-duzina rijeci i/ili brojeva unutar </...>*/
		while(k<d) {
			if(s[k]=='<' && s[k+1]=='/') {
				k+=2;
				for(j=0; j<d; j++) {
					if(s[k]=='>' && s[k-1]=='/') return 0;
					if(s[k]=='>') break;
					if(s[k]==' ' && duzina==0) return 0;
					if(s[k]<' ' || (s[k]>' ' && s[k]<'0') || (s[k]>'9' && s[k]<'A') || (s[k]>'Z' && s[k]<'a') || s[k]>'z') return 0;
					tag[j]=s[k];
					duzina++;
					k++;
				}
			}
			if(duzina>0) break;
			k++;
		}
		/*Da li je preostalo otvorenih tagova? (blok ispod)*/
		for(i=0; i<m; i++) {
			br1=0;
			br2=0;
			if(s[i]!='<') T=0;
			if(s[i]=='<') {
				i++;
				while(s[i]!='>' && i<m) {
					if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) br1++;
					if(s[i]<'0' || (s[i]>'9' && s[i]<'A') || (s[i]>'Z' && s[i]<'a') || s[i]>'z') break;
					if(s[i]==' ' && br1>0) {
						while(s[i]!='>' && i<m) {
							br2++;
							i++;
						}
						i--;
					} else if(s[i]==' ' && br1==0) break;
					i++;
				}
				if(s[i]!='>' && i!=m) T=0;
				if(i==m && s[i]!='>') T=0;
				if(s[i]=='>' && br1==0) T=0;
				if((s[i]=='>' && br1>0 && br2==0) || (s[i]=='>' && br2>1)) T=1;
			}
			if(T==1) break;
		}
		/*ako je indeks posmatranog stringa dosao do kraja, a ostalo je (ili nije) otvorenih tagova*/
		if(k==d && T==1) return 0;
		if(k==d && T==0) return 1;
		/*izbacivanje nepotrebnih razmaka*/
		for(i=0; i<duzina; i++) {
			if(tag[i]==' ') {
				tag[i]=tag[i+1];
				i--;
				duzina--;
			}
		}
		br1=0;
		br2=0;
		j=0;
		/*dio koda koji provjerava koliko puta je neki tag zatvoren na isti nacin (sa istim char-ovima)*/
		for(i=0; i<n; i++) {
			while(j<duzina && niz[i]!=' ') {
				if(niz[i]==tag[j]) br1++;
				i++;
				j++;
			}
			if(j==duzina && niz[i]!=' ') {
				while(niz[i]!=' ')
					i++;
			}
			j=0;
			if(br1==duzina) pon++;
			br1=0;
		}
		/*dodavanje u niz char-ove kojima se zatvara tag (kojeg trenutno posmatramo) - sluzi za prethodni dio koda*/
		for(i=0; i<duzina; i++) {
			niz[n]=tag[i];
			n++;
		}
		niz[n]=' ';
		n++;
		if(pon%2!=0) brojac++; /*brojac-broji neodgovarajuca otvaranja tagova; ukoliko postoji istih otvaranja/zatvaranja, potrebno je preskociti vec koristeno otvaranje pri trazenju odgovarajuceg*/
		/*trazenje odgovarajuce otvaranje taga uz prethodno nadjeno zatvaranje*/
		for(i=0; i<d; i++) {
			if(s[k]=='<') {
				for(j=0; j<duzina; j++) {
					if(tag[j]>='A' && tag[j]<='Z') {
						if((s[k+j+1]==tag[j]) || (s[k+j+1]==(tag[j]+32))) br++;
					} else if(tag[j]>='a' && tag[j]<='z') {
						if((s[k+j+1]==tag[j]) || (s[k+j+1]==(tag[j]-32))) br++;
					} else {
						if(s[k+j+1]==tag[j]) br++;
					}
				}
				if(br!=j) brojac++; /*povecati broj neodgovarajucih otvaranja se odgovarajuci char-ovi ne poklapaju*/
				else if(br==j && pon>0) {
					pon--;
					br=0;
					k--;
					continue; /*preskakanje identicnog otvaranja taga, ali ipak neodgovarajuceg*/
				} else if(br==j && brojac%2!=0) break; /*pronađen odgovarajuce otvaranje*/
				else if(br==j && brojac%2==0) return 0; 
			}
			k--;
			br=0;
		}
		if(i==d) return 0; /*ako je program dosao do zadnjeg indeksa, prekida se*/
		brojac=0;
		br_vracanja=i;
		m=k-1;
		duzina=0;
		pon=0;
		/*vracanje indeksa "k" na vrijednost (+1) koja je bila pri pronalasku zatvaranja tag-a*/
		for(i=0; i<br_vracanja+1; i++)
			k++;
	}
	/*ukoliko je sve uredu, ispisuje 1*/
	return 1;
}
int main()
{
	return 0;
}