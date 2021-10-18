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
typedef std::vector<int> IntVektor;

IntVektor IzdvojiGadne(IntVektor vektor, bool n) {
	IntVektor v;
	for (int x: vektor) {			//rangovskom for-petljom prolazimo kroz vektor poslat kao parametar f-je
		IntVektor cifre(3,0);		//deklaracija vektora u kojem cemo cuvati cifre broja u ter. zapisu (moguće cifre 0,1,2); sve elemente inic. na 0 
		int a(x), b(0);		//deklariramo pom varijablu a (inicijalziramo je aps vrijednoscu clana vektora zbog neg brojeva-ne radi abs za int_min)
		do {					
			b=a%3;			// konverzija broja a u ternarni brojni sistem dijeljenjem sa 3; ostatak pri dijeljenju je cifra broja a u tern. br. sistemu
			cifre[std::abs(b)]++;	//biljezimo pojavljivanje cifre b u vektoru cifre inkrementiranjem b-tog clana vektora (abs(b) zbog neg brojeva)
			a/=3;			//u a stavljamo rezultat dijeljenja a sa 3 i vrtimo petlju dok a ne postane 0
		} while (a!=0);
		if(n) {										//provjera za opake brojeve, ako je n=true
			bool prekid(false), jednak(false);		//deklaracija 2 logicke varijable koje ce nam dati inf da li je doslo do breaka u for-petljama
			for(int i(0); i<3; i++) {
				if(cifre[i]!=0 && cifre[i]%2!=0) {prekid=true; break;}    //provjera da li neka cifra ima neparan broj pojavljivanja, ukoliko ima odmah
			}														 //prekidamo petlju jer taj broj nije opak! log. var. prekid postavljamo na true 
			if(!prekid) {			//ukoliko nije doslo do prekida u gornjoj petlji to znaci da je taj broj opak
				for(int i(0); i<v.size(); i++)
					if(x==v[i]) {jednak=true; break;}     //provjera da li se taj broj vec nalazi u vektoru
				if(!jednak) v.push_back(x);					//ako ne ubacujemo ga u vektor
			}
		} else {									//provjera za odvratne brojeve, ako je n=false
			bool prekid(false), jednak(false);
			for(int i(0); i<3; i++) {									  //provjera da li neka cifra ima paran broj ponavljanja, ukoliko ima prekidamo
				if(cifre[i]!=0 && cifre[i]%2==0) {prekid=true; break;}	  //petlju jer broj nije odvratan! log. var. prekid postavljamo na true
			}							//posebnu provjeru smo izvrsili kada neke cifre nema u broju, da ne bi uslov djeljivosti sa 2 stalno bio tacan
			if(!prekid) {				//ukoliko nije doslo do prekida broj je odvratan
				for(int i(0); i<v.size(); i++)
					if(x==v[i]) {jednak=true; break;}		//provjera da li se broj vec nalazi u vektoru
				if(!jednak) v.push_back(x);					// ako ne ubacujemo ga u vektor
			}
		}
	}
	return v;
}
int main ()
{
	IntVektor a;
	int unos;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;) {
		std::cin>>unos;
		if(unos==0) break;
		a.push_back(unos);
	} 
	IntVektor b(IzdvojiGadne(a,true)), c(IzdvojiGadne(a,false));
	std::cout<<"Opaki: ";
	for(int x: b) std::cout<<x<<" ";
	std::cout<<std::endl<<"Odvratni: ";
	for(int x: c) std::cout<<x<<" ";
	return 0;
}