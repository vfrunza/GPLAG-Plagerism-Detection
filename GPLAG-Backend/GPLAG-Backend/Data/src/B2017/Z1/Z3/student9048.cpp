/*                                                 NAPOMENA !!!

                 SREDI SVE RUBNE SLUCAJEVE KOJI TI MOGU PASTI NA PAMET I SREDI IZUZETKE
*/


//Zahvaljujuci nedovoljnom obracanju paznje, citav 3. zadatak sam uradio u folderu namijenjenom drugom zadataku
//Zbog toga se čini kao da je funkcija MaksimalniPodnizovi... odradjena tako brzo, vjerujte, nije, ni priblizno tome, duze nego sto mozete zamisliti
//Druge funkcije kao sto su UnesiVektor, IspisiVektor ili njihovi ekvivalenti deku, prethodno su odradjeni na tutorijalima
// i samo su prema potrebama zadatka doradjene


#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
//Zamjenske kljucne rijeci koje cemo u daljnem kodu koristiti kao zamjenu za tip vektor, kao i konstrukciju deka vektora
typedef std::vector<int> Vektor;
typedef std::deque<std::vector<int>> DekVek;
//Deklaracija novog 'tipa' tipa enum, cije promjenljive mogu poprimiti samo vrijednosti Rastuci i Opadajuci
enum Smjer {Rastuci, Opadajuci};

//Provjeravamo da li je proslijedjeni broj neki (nama nebitno koji) stepen broja dva
//Istu funkciju smo mogli uraditi na prost nacin da provjerimo da li su prvo proslijedjeni 1 || 0, nakon cega bi vratili true kao rezultat
//a za sve druge bismo kreirali for-petlju te trazili cjelobrojni broj ciji korijen daje rezultat 2
//ocigledan nedostatak ove petlje jeste cinjenica da ne znamo max moguci stepen broja 2 koji nam moze biti proslijedjen
//naravno, mogli smo napraviti beskonacnu for petlju tipa for(;;) i uraditi break onog trenutka kada rezultat bude = 2
//Medjutim, efikasniji nacin jeste koristenje Bitwise AND operatora
//Logika: binarni zapis je takav da je svaki stepen broja zapisan kao '1', te slijed nula ciji broj odgovara stepenu broja u decimalnom zapisu
// (Zamislite sipku ili tome slicno, koja na sebi ima pokretne tockice sa jedinicama i nulama, na svakom novom punom krugu okrecemo prethodne i jedan novi tockic)
//Npr. decimalni   |   binarni  
//         2       |   10
//         4       |   100
//         8       |   1000
//         16      |   10000
//itd. Sada kada oduzmemo 1 od binarnog zapisa, kao rezultat dobit ćemo vodeću nulu i beskonacan slijed jedinica
// Primjenjivanjem logickog operatora AND (^) kao rezultat dobit cemo slijed nula ukoliko je broj zaista stepen broja 2 (tautologija T ⊥)
//Implementacija funkcije mogla je izgledati i nesto drugacije, da idemo putem return IZRAZ
// medjutim ovo bi vracalo '0' ukoliko je izraz tacan, sto je malo konfuzno, tako da je ovakva implementacija funkcij nesto citljivija
bool JeLiStepenDvojke(int broj)
{
	if((broj > 0) && (broj & (broj - 1)) == 0) return true;
	return false;
}

//Logika funkcije MaksimalniPodnizovi... je vrlo jednostavna, naravno sada kada se do nje konacno doslo
//U zavisnosti od vrijednosti promjenljive var, provjeravat cemo rastuce/opadajuce nizove
DekVek MaksimalniPodnizoviStepenaDvojke(Vektor v, Smjer var)
{
	DekVek dv;
	Vektor v1;
	if(var == Rastuci) {
		for(int i(0); i < v.size()-1; i++) {
			//Varijabla pomocu koje cemo se 'setati' ispred broja koji provjeravamo
			int sljedeci = i + 1;
			//Svi uvjeti koji garantiraju da je element vektora max podniz nekog niza moraju ispuniti uvjet da su stepeni broja 2
			//Takodjer, da bi podniz bio rastuci, svaki sljedbenik mora biti veci od prethodnika
			//Ukoliko su sva 3 uvjeta zadovoljena, element se unosi u vektor
			if(JeLiStepenDvojke(v.at(i)) && JeLiStepenDvojke(v.at(sljedeci)) && v.at(sljedeci) >= v.at(i)) {
				v1.push_back(v.at(i));
				//Kreiramo beskonacnu petlju cije izvrsenje prekidamo onog trenutka kada dodjemo do kraja vektora,
				//kada dodjemo do broja koji nije stepen dvojke, ili kao posljednje ukoliko sljedbenik nije veci od prethodnika
				for(;;) {
					if(!(sljedeci != v.size() && JeLiStepenDvojke(v.at(sljedeci)) && v.at(sljedeci) >= v.at(sljedeci - 1))) break;
					//Svi brojevi koji se nadju u slijedu prije izvrsavanja break komande bit ce upisani u nas pomocni vektor
					v1.push_back(v.at(sljedeci));
					sljedeci++;
				}
				//Provjeru gore definisanih uvjeta vracamo na mjesto iza gdje je 'sljedeci' stao
				//moze se desiti da vrijednost na koju sljedeci 'pokazuje' pripada podnizu, ali ukoliko bi provjeravali od te pozicije, ona ne bi usla u vektor
				//takodjer, ocigledniji razlog zasto bas 'i' dodjeljujemo vrijednost 'sljedeceg' jeste cinjenica da sve one vrijednosti izmedju uopce nije potrebno, te cak i ne smijemo provjeravati
				i = sljedeci -1;
				//Nakon sto smo zavrsili 'punjenje' pomocnog vektora v1, vrijeme je da ga jednostavno ubacimo u dek dv
				dv.push_back(v1);
				//S obzirom da je v1 pomocni niz koji ce biti vise puta upotrijebljen, potrebno ga je isprazniti kako ne bi doslo do
				//gomilanja elemenata i na poslijetku netacnog rezultata
				v1.clear();
			}
		}
		return dv;
		//Logika za Opadajuce je posve identicna, samo sto se sada radi o negaciji slucaja kada je prethodnik veci od sljedbenika
	} else {
		for(int i(0); i < v.size()-1; i++) {
			int sljedeci = i + 1;
			if(JeLiStepenDvojke(v.at(i)) && JeLiStepenDvojke(v.at(sljedeci)) && v.at(sljedeci) <= v.at(i)) {
				v1.push_back(v.at(i));
				for(;;) {
					if(!(sljedeci != v.size() && JeLiStepenDvojke(v.at(sljedeci)) && v.at(sljedeci) <= v.at(sljedeci - 1))) break;
					v1.push_back(v.at(sljedeci));
					sljedeci++;
				}
				i = sljedeci -1;
				dv.push_back(v1);
				v1.clear();
			}
		}
		return dv;
	}

}

//Funkcija za unos vektora
Vektor UnesiVektor(int vel)
{
	int i(0);
	//Pomocni vektor koji cemo naposlijetku vratiti iz funkcije
	Vektor unosVektor;
	int broj;
	do{
		//Unos brojeva kao pojedinacnih cjelobrojnih vrijednosti koje ce naknadno biti ubacene u vektor
		std::cin >> broj;
		//Ubacivanje upravo spomenutih cjelob. vrijednosti
		unosVektor.push_back(broj);
		//Povecavamo brojac za +1 pri svakoj iteraciji petlje
		i++;
		//Petlja se izvrsava sve dok se brojna vrijednost brojaca ne izjednaci sa brojnom vrijednoscu velicine vektora
	}while(i < vel);
	//Vracamo sada 'napunjeni' pomocni vektor
	return unosVektor;
}

//Funkcija za ispisivanje deka vektora
//S obzirom da ce funkcija samo ispisivati brojeve na izlazni uredjaj (u ovom slucaju ekran/monitor), ona dakle nece nista vracati
//te je upravo zbog toga tipa void
void IspisiDekVektora(DekVek DV1)
{
	//Dvostrukom rangovskom petljom ispisujemo vrijednosti
	for(auto x : DV1){
		for(auto m : x){
			std::cout << m << " ";
		}
		//Novi red na kraju svakog vektora u cilju ljepseg (a i tacnijeg) ispisa
		std::cout << std::endl;
	}
}

int main ()
{
	//Deklarisanje vitalnih varijabli
	int Br_el(0);
	int logicka(0);
	Smjer pobrojana;
	//Ispis poruka i unosi podataka neophodnih za rad programa
	std::cout << "Unesite broj elemenata vektora: ";
	do{
	std::cin >>Br_el;
	  if(Br_el < 0) std::cout << "Neispravan unos! Unesite ponovo: ";
	}while(Br_el < 0);
	std::cout << "Unesite elemente vektora: ";
	//Unos vektora pomocu iznad opisane funkcije
	Vektor v1(UnesiVektor(Br_el));
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	//Osiguravamo da je unos za nacin rada [RASTUCI/OPADAJUCI] ogranicen na vrijednosti 1 i 2
	do{
		std::cin >> logicka;
		if(logicka < 1 || logicka > 2) std::cout << "Neispravan unos! Unesite ponovo: ";
	}while(logicka < 1 || logicka > 2);
	//Ako je korisnik unio 1, pronaci cemo i ispisati rastuce, u suprostnom trazimo i ispisujemo opadajuce
	if(logicka == 1) pobrojana = Rastuci;
	else pobrojana = Opadajuci;
	if(logicka == 1) std::cout << "Maksimalni rastuci podnizovi: "<< std::endl;
	else std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	//U konacnici ispisujemo rezultirajuci dek vektora
	IspisiDekVektora(MaksimalniPodnizoviStepenaDvojke(v1, pobrojana));
	return 0;
}haefdiuewfe