/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> Pretvori_u_ternatne_cifre (int broj) {		//funkcija pretvara broj u ternatni, i uvecava brojac ternarnih cifara
	std::vector<int>brojac_cifara(3);						//tj biljezi koliko se puta koja cifra ponavlja, i vraca vektor brojaca
	int broj1=fabs(broj);
	do {
		brojac_cifara[broj1%3]++;
		broj1/=3;
	} while (broj1!=0);
	return brojac_cifara; 
}

bool Da_li_je_opaki (int broj) {								//funkcija prolazi kroz brojac ternarnih cifara, i ispituje  da li
	std::vector<int> preb_cifre=Pretvori_u_ternatne_cifre(broj);// se sve cifre ponavljaju paran broj puta, tj da li je broj opak
	for (int i=0; i<preb_cifre.size(); i++) 
		if (preb_cifre[i]%2!=0) return false;
	return true;
}

bool Da_li_je_odvratni (int broj) {								// funkcija ispituje da li se sve cifre pojavljuju neparan broj puta,
	std::vector<int> preb_cifre=Pretvori_u_ternatne_cifre(broj);// prolazeci kroz vektor ternarnih brojeva, tj da li je odvratan
	for (int i=0; i<preb_cifre.size(); i++) 
		if(preb_cifre[i]!=0 && preb_cifre[i]%2==0) return false;
	return true;
}

std::vector<int> IzdvojiGadne (std::vector<int> vektor_dekadnih, bool log_vrijednost) {	//pravi vektor gadnih brojeva, opakih ili odvratnih
	std::vector<int> novi_vektor,ponovljeni;											// u zavisnosti od log_vrijednosti (t/f)
	if (log_vrijednost) {
		for (int broj: vektor_dekadnih) {				//petlja prolazi kroz zadani vektor
			int pom=0;
			for (int i=0; i<ponovljeni.size(); i++) 	//ispituje da li je broj ponovljen
				if (ponovljeni[i]==broj) pom=1;
			if (pom==0 && Da_li_je_opaki(broj)) {		//ako nije ponovljen i ako je opak, smjesta se u vektor opakih,
				novi_vektor.push_back(broj);			// i u vektor ponovljenih, zbog daljeg poredjenja
				ponovljeni.push_back(broj);
			}
		}
	}
	else {
		for (int broj: vektor_dekadnih) {				//isti fazon, samo za odvratne brojeve 
			int pom=0;
			for (int i=0; i<ponovljeni.size(); i++)
				if (ponovljeni[i]==broj) pom=1;
			if (pom==0 && Da_li_je_odvratni(broj)) {
				novi_vektor.push_back(broj);
				ponovljeni.push_back(broj);
			}
		}
	}
	return novi_vektor;
}

void Ispisi_vektor (std::vector<int> v){
	for (int i=0; i<v.size(); i++)
		std::cout<<v[i]<<" ";
}

int main () 
{	
	std::vector<int> vektor_brojeva;
	int broj;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do {
		std::cin>>broj;
		if (broj!=0) vektor_brojeva.push_back(broj);
	} while (broj!=0);
	std::cout<<"Opaki: ";
	Ispisi_vektor(IzdvojiGadne(vektor_brojeva,true));
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	Ispisi_vektor(IzdvojiGadne(vektor_brojeva,false));
	return 0;
}