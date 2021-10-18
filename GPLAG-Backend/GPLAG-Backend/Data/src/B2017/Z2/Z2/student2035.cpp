#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <deque>
#include <type_traits>
enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

void UvecajILIUmanjiPoI(int &brojac, SmjerKretanja smjer) {
	if(smjer==SmjerKretanja::GoreDolje)
	brojac++;
	if(smjer==SmjerKretanja::DoljeGore) brojac--;
}

bool UslovUZavisnostiOdSmjeraPoI(int brojac, int granica, SmjerKretanja smjer) {
	if(smjer==SmjerKretanja::GoreDolje) {
		if(brojac<granica) return true;
		return false;
	} 
	if(smjer==SmjerKretanja::DoljeGore) {
		if(brojac>=granica) return true;
		return false;
	}
}

void IspisiRazmake(int koliko) {
	for(int i=0; i<koliko; i++)
	std::cout << " ";
}
template <typename kont2>
kont2 Transponiraj(kont2 &CudnovataMatricaIspravnogFormata) {
	typename std::remove_reference<decltype(CudnovataMatricaIspravnogFormata.at(0))>::type prazna_poloha; 
	typename std::remove_reference<decltype(CudnovataMatricaIspravnogFormata.at(0).at(0))>::type prazan_red;
	kont2 kontejner2; 
	for(int k=0; k<CudnovataMatricaIspravnogFormata.size(); k++) {
		kontejner2.push_back(prazna_poloha);
	for(int i=0; i<CudnovataMatricaIspravnogFormata.size(); i++) {
		kontejner2.at(k).push_back(prazan_red); 
	for(int j=0; j<CudnovataMatricaIspravnogFormata.size(); j++) {
		kontejner2.at(k).at(i).push_back(CudnovataMatricaIspravnogFormata.at(k).at(j).at(i)); //ja mislim da jeste ovako transponovana
	}}
	}
	
	return kontejner2;
}

template <typename kont3>
kont3 TransponirajDrugacije(kont3 &CudnovataMatricaIspravnogFormata) {
	kont3 kontejner3;
	typename std::remove_reference<decltype(CudnovataMatricaIspravnogFormata.at(0))>::type prazna_ploha; 
	typename std::remove_reference<decltype(CudnovataMatricaIspravnogFormata.at(0).at(0))>::type prazan_red;
	for(int k=0; k<CudnovataMatricaIspravnogFormata.size(); k++) {
		kontejner3.push_back(prazna_ploha);
	for(int i=0; i<CudnovataMatricaIspravnogFormata.size(); i++) {
		kontejner3.at(k).push_back(CudnovataMatricaIspravnogFormata.at(i).at(k)); //valjda  
		 }}
	 
	 return kontejner3;
}

template <typename kont>
kont PjescaniSat(kont CudnovataMatrica, SmjerKretanja smjer) {
	if(CudnovataMatrica.size()==0) return CudnovataMatrica;  //napravi ti funkciju lijepo za ovu provjeru sta ako je matrica grbava moras se osigurati u zivotu
	int za_provjeru_plohe(CudnovataMatrica.size());
	for(int k=0; k<CudnovataMatrica.size(); k++) {
		if (CudnovataMatrica.at(k).size()!=za_provjeru_plohe) throw std::domain_error("3D matrica nema oblik kocke");
	for(int i=0; i<CudnovataMatrica.at(k).size(); i++) {
		if (CudnovataMatrica.at(k).at(i).size()!=za_provjeru_plohe) throw std::domain_error("3D matrica nema oblik kocke");
 		}}
	
	
	//if(CudnovataMatrica.at(0).size()!=CudnovataMatrica.size()) throw std::domain_error("3D matrica nema oblik kocke"); 
	//if(CudnovataMatrica.at(0).size()!=CudnovataMatrica.at(0).at(0).size()) throw std::domain_error("3D matrica nema oblik kocke"); 
	if(CudnovataMatrica.size()%2==0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	kont sat;
	typename std::remove_reference<decltype(CudnovataMatrica.at(0))>::type prazna_ploha;
	typename std::remove_reference<decltype(CudnovataMatrica.at(0).at(0))>::type prazan_red;
	int broj_ploha(CudnovataMatrica.size());
	int broj_redova(CudnovataMatrica.at(0).size()); 
	int broj_kolona(CudnovataMatrica.at(0).at(0).size());
	int pocetak_i(0), kraj_i(0); 
	int mojamatrica(-1);
	if(smjer==SmjerKretanja::DesnoLijevo) {	CudnovataMatrica=Transponiraj(CudnovataMatrica); smjer=SmjerKretanja::DoljeGore; }	//proveri
	if(smjer==SmjerKretanja::LijevoDesno) {	CudnovataMatrica=Transponiraj(CudnovataMatrica); smjer=SmjerKretanja::GoreDolje; } //ditto
	if(smjer==SmjerKretanja::NaprijedNazad) {	CudnovataMatrica=TransponirajDrugacije(CudnovataMatrica); smjer=SmjerKretanja::GoreDolje;	} //ditto
	if(smjer==SmjerKretanja::NazadNaprijed) { CudnovataMatrica=TransponirajDrugacije(CudnovataMatrica); smjer=SmjerKretanja::DoljeGore;  }	//ditto 	
	if(smjer==SmjerKretanja::GoreDolje) {pocetak_i=0; kraj_i=broj_redova; }
	if(smjer==SmjerKretanja::DoljeGore) {pocetak_i=broj_redova-1; kraj_i=0;}
	
	
	for(int k=0; k<broj_ploha ;k++) {
		sat.push_back(prazna_ploha);
		mojamatrica=-1;
	for(int i=pocetak_i; UslovUZavisnostiOdSmjeraPoI(i,kraj_i,smjer) ;UvecajILIUmanjiPoI(i, smjer)) {
		mojamatrica++;// std::cout << " " << mojamatrica << " ";
		sat.at(k).push_back(prazan_red);
		if(i<=broj_redova/2) {
			for(int j=0+i; j<broj_kolona-i; j++) {
			sat.at(k).at(mojamatrica).push_back(CudnovataMatrica.at(k).at(i).at(j)); 
				}
			}
		else { 
			for(int j=broj_redova-i-1; j<=i; j++)	//OVDJE SI DODALA -1 SAMO DA ZNAS
			sat.at(k).at(mojamatrica).push_back(CudnovataMatrica.at(k).at(i).at(j));
			}	
		}}  
		
		return sat;
	
}
int main ()
{
	
	std::cout << "Unesite dimenziju (x/y/z): "; 
try {	int x; //vidi hoce li testirati lose poslane neintove i tako to
	std::cin >> x;
	while(x<0) {
		std::cout << "Dimenzija nije ispravna, unesite opet: "; 
		std::cin >> x;
	}
	std::cout << "Unesite elemente kontejnera: "; 
	std::deque<std::deque<std::deque<int>>> nesto;
	std::deque<std::deque<int>> prazan_dek_dekova;
	std::deque<int> prazan_dek;
	int unijeto; // vidi hoce li ovdje unositi neke boelsti
	for(int i=0; i<x; i++) {
		nesto.push_back(prazan_dek_dekova);
	for(int j=0; j<x; j++) {
		nesto.at(i).push_back(prazan_dek);
	for(int k=0; k<x; k++) {
	std::cin >> unijeto;
	nesto.at(i).at(j).push_back(unijeto); } } }
	
	std::cout << "Unesite smjer kretanja [0 - 5]: "; 
	int n; //vidi hoce li testirati lose poslane ove
	std::cin >> n; 
	while(n<0 || n>5) {
	std::cout << "Smjer nije ispravan, unesite opet: ";
	std::cin >> n; }
	auto sat(PjescaniSat(nesto, static_cast<SmjerKretanja>(n)));
	std::cout << std::endl <<"Pjescani sat unesene matrice je: " << std::endl << std::endl;
	for(int k=0; k<x; k++) {
	for(int i=0; i<x; i++) {
	for(int j=0; j<sat.at(k).at(i).size(); j++) { //POPRAVI TI OVAJ ISPIS OBE MI ZNAMO DA OVO NE RADI ZA DIM>3
		if(i<=x/2 && j==0) {
		IspisiRazmake(i*4);
		std::cout << std::setw(4) << sat.at(k).at(i).at(j); }
		
		else if(j==0) {
			IspisiRazmake(4*(x-i-1));
			std::cout << std::setw(4) << sat.at(k).at(i).at(j);}
			else std::cout << std::setw(4) << sat.at(k).at(i).at(j);
		
	}
		std::cout << std::endl;
	}
		std::cout << std::endl; 
	}
	 
	return 0; }
	
	catch(std::domain_error e) {
		std::cout << std::endl << "Izuzetak: " << e.what();
	}
	
	catch(std::length_error a) {
		std::cout << std::endl << "Izuzetak: " << a.what(); 
	} }
