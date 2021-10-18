/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>

typedef std::vector<std::vector<double>> DoubleMatrica;
typedef std::vector<double> DoubleVektor;

int BrojRastucih (DoubleVektor niz) {  //pomocna funkcija koja broji koliko ima rastucih podnizova u datom vektoru, radi kreiranja grbave matrice
	if(niz.size()<=1) return 0;			//ukoliko je vektor prazan ili ima samo 1 clan, vraća se 0  
	int i(0), j(0);				//brojac i sluzi za kretanje kroz vektor, a j broji rasutce podnizove u vektoru
	for(;;) {
		bool parametar(false), prekid(false);  //logicke varijable koje nam govore da li se uslo u while petlju i da li je doslo do prekida petlje
		while(niz[i]<=niz[i+1]) {  //while petlja koja radi ako je clan vektora <= sljedecem clanu
			parametar=true;      //znak da je detektovan rastuci podniz
			i++;				//uvećava se brojac dok se ne dođe do kraja trenutnog podniza ili kraja vektora
			if(i==niz.size()-1) {prekid=true; break;} //kad se dođe do kraja vektora prekid petlje
		}
		if(parametar) j++;   //ulazak u petlju je znak da ima odgovarajuci podniz pa se brojac inkrementira
		i++;			//inkrementiramo brojac 
		if(i==niz.size()-1 || prekid) return j;  // ukoliko je u while petlji doslo do prekida ili ukoliko se nakon prethodnog inkrementiranja doslo
	}											 //do kraja vektora salje se rezultat funkcije
}
int BrojOpadajucih (DoubleVektor niz) { //pomocna funkcija koja broji koliko ima opadajucih podnizova u datom vektoru, sto će nam olaksati kreiranje
	if(niz.size()<=1) return 0;			//grbave matrice u trazenoj funkciji
	int i(0), j(0);				//strukturu funkcije je slicna kao funkcije BrojRastucih
	for(;;) {
		bool m(false), prekid(false);  //jedina razlika je u uslovu while petlje, jer je promjenjen znak jednakosti
		while(niz[i]>=niz[i+1]) {
			m=true;
			i++;
			if(i==niz.size()-1) {prekid=true; break;}
		}
		if(m) j++;
		i++;
		if(i==niz.size()-1 || prekid) return j;
	}
}
DoubleMatrica RastuciPodnizovi (DoubleVektor niz) {
	DoubleMatrica matrica(BrojRastucih(niz));  //kreiramo matricu sa onoliko redova kolika je povratna vrijednost funkcije BrojRastucih
	int j(0);							//brojac za indeksiranje vektora
	for (int i(0); i<matrica.size(); i++) {    //kroz vektore matrice prolazimo for petljom
		bool n(false);		//logicka varijabla koja potvrđuje ulazak u petlju
		while(niz[j]<=niz[j+1]) {    //ukoliko je j-ti clan <= od sljedeceg clana ulazimo u petlju
			matrica[i].push_back(niz[j]);  //ubacujemo j-ti clan u matricu
			n=true;				//log. vrijednost parametra mijenjamo u tacno
			j++;				
			if(j==niz.size()-1) break;  //ukoliko dođemo do kraja vektora prekidamo petlju kako ne bi pristupali van vektora
		}
		if(n) matrica[i].push_back(niz[j]); //ukoliko je n tacno to znaci da se barem jednom uslo u petlju i moramo uraditi jos jedan push_back radi unosa i posljednjeg clana podniza
		else i--; //ukoliko uslov while petlje nije ni jednom ispunjen dekrementiramo i kako bi ostali u istom redu matrice
		j++;
	}
	return matrica;
}

DoubleMatrica OpadajuciPodnizovi (DoubleVektor niz) {  //funkcija ima gotovo identicnu strukturu kao i funkcija RastuciPodnizovi
	DoubleMatrica matrica(BrojOpadajucih(niz));
	int j(0);
	for(int i(0); i<matrica.size(); i++) {
		bool m(false);
		while(niz[j]>=niz[j+1]) {					//jedina razlika u promjeni znaka jednakosti u uslovu while petlje
			matrica[i].push_back(niz[j]);
			m=true;
			j++;
			if(j==niz.size()-1) break;
		}
		if(m) matrica[i].push_back(niz[j]);
		else i--;
		j++;
	}
	return matrica;
}
int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	DoubleVektor niz(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0); i<n; i++) 
		std::cin>>niz[i];
	DoubleMatrica rastuci_podnizovi(RastuciPodnizovi(niz)), opadajuci_podnizovi(OpadajuciPodnizovi(niz));
	std::cout<<"Maksimalni rastuci podnizovi:\n";
	for (auto niz : rastuci_podnizovi) {
		for (auto x : niz)
			std::cout<<x<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi:\n";
	for(auto niz : opadajuci_podnizovi) {
		for (auto x : niz)
			std::cout<<x<<" ";
		std::cout<<std::endl;
	}
	return 0;
}