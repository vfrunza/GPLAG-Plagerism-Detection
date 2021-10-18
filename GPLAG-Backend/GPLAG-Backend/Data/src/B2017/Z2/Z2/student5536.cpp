#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <iomanip>
#include <stdexcept>

enum class SmjerKretanja {NaprijedNazad,NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

template <typename Tip>   // Izvrce matrice tako da zandnji red postaje prvi itd...
Tip Izvrni (Tip ogledalo)
{
	Tip pomoc(ogledalo);
	int stranica(ogledalo.size());
	for (int j=0; j<stranica/2; j++) {
		pomoc.at(0)=ogledalo.at(j);
		ogledalo.at(j)=ogledalo.at(stranica-j-1);
		ogledalo.at(stranica-j-1)=pomoc.at(0);
	}
	return ogledalo;
}

template <typename Tip>
bool DaLiJeKocka (Tip Kocka){
	int broj_kocki(Kocka.size());
	for (int i = 0; i<Kocka.size(); i++){
	if (broj_kocki!=Kocka.at(i).size()) return false;
	for (int j = 0; j<Kocka.at(i).size(); j++)
	if (broj_kocki!=Kocka.at(i).at(j).size()) return false;
	}
	return true;
}

template <typename Tip>
Tip PjescaniSat (Tip Kocka, enum SmjerKretanja smjer)
{
	try{
	if (!DaLiJeKocka(Kocka)) throw std::domain_error("3D matrica nema oblik kocke");
	if (Kocka.size()%2==0 && Kocka.size()>0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	int duzina(Kocka.size());
	Tip vrati(duzina);
	for (int i = 0; i<Kocka.size(); i++) {
		// GoreDolje i DoljeGore
		if (smjer==SmjerKretanja::GoreDolje || smjer==SmjerKretanja::DoljeGore) {
			vrati.at(i).resize(duzina);  // Podesavam red matrice na 5
			for (int j = 0; j<duzina; j++)
				for (int k = 0; k<duzina; k++)
					if (!((j>k && k<Kocka.at(i).at(j).size()-j-1) || (j>=Kocka.at(i).at(j).size()-k && k>j))) // Uslov da bude pjesacni sat
						vrati.at(i).at(j).push_back(Kocka.at(i).at(j).at(k));  // Stavljam element u matricu

			if (smjer==SmjerKretanja::GoreDolje) continue;   // Ako je GoreDolje ostavi kako jeste, u slucaju da nije samo obrni i njega vrati
			vrati.at(i)=Izvrni(vrati.at(i));
		}
		//DesnoLijevo i LijevoDesno// Vrijede iste stvari kao i za prethodni dio koda od GoreDolje i DoljeGore
		else if (smjer==SmjerKretanja::DesnoLijevo || smjer==SmjerKretanja::LijevoDesno) {
			vrati.at(i).resize(duzina);
			for (int j = 0; j<duzina; j++)
				for (int k = 0; k<duzina; k++)
					if (!((k>j && j<Kocka.at(i).at(j).size()-k-1) || (k>=Kocka.at(i).at(j).size()-j && j>k)))
						vrati.at(i).at(k).push_back(Kocka.at(i).at(j).at(k));
			if (smjer==SmjerKretanja::LijevoDesno) continue;
			vrati.at(i)=Izvrni(vrati.at(i));
		}
		//NaprijedNazad i NazadNaprijed
		else if (smjer==SmjerKretanja::NaprijedNazad || smjer==SmjerKretanja::NazadNaprijed) {
			vrati.at(i).resize(duzina);
			int s(0);  // Sa varijablom s prolazim kroz matrice 3D vektora
			for (int j = 0; j<duzina; j++) {
				for (int k = 0; k<duzina; k++) {
					if (!((j>k && k<duzina-j-1) || (j>=duzina-k && k>j)))  // Isti uslovi kao i za GoreDolje
						vrati.at(i).at(j).push_back(Kocka.at(s).at(i).at(k));    // Sa s-om hodam kroz matrice
				}
				s++;
			}
			if (smjer==SmjerKretanja::NaprijedNazad) continue;
			vrati.at(i)=Izvrni(vrati.at(i));
		}
	}
	return vrati;
	}
	catch (...){
		throw;
	}
}

int main ()
{
	try {
		int x;
		std::cout<<"Unesite dimenziju (x/y/z): ";
		for(;;) {
			std::cin>>x;
			if (x<0)
				std::cout<<"Dimenzija nije ispravna, unesite opet: ";   // Unosenje dimnezije
			else break;
		}
		std::cout<<"Unesite elemente kontejnera: ";
		std::vector<std::deque<std::deque<int>>> kocka;  
		int broj;
		for (int i = 0; i<x; i++) {
			kocka.push_back(std::deque<std::deque<int>>(x));
			for (int j = 0; j<x; j++)
				for (int k = 0; k<x; k++) {
					std::cin>>broj;
					kocka.at(i).at(j).push_back(broj);
				}
		}
		std::cout<<"Unesite smjer kretanja [0 - 5]: ";
		int smjer;
		do {
			std::cin>>smjer;
			if (smjer==0) {
				kocka=PjescaniSat(kocka,SmjerKretanja::NaprijedNazad);
				break;
			} else if (smjer==1) {
				kocka=PjescaniSat(kocka,SmjerKretanja::NazadNaprijed);
				break;
			} else if (smjer==2) {
				kocka=PjescaniSat(kocka,SmjerKretanja::GoreDolje);
				break;
			} else if (smjer==3) {
				kocka=PjescaniSat(kocka,SmjerKretanja::DoljeGore);
				break;
			} else if (smjer==4) {
				kocka=PjescaniSat(kocka,SmjerKretanja::LijevoDesno);
				break;
			} else if (smjer==5) {
				kocka=PjescaniSat(kocka,SmjerKretanja::DesnoLijevo);
				break;
			}
			std::cout<<"Smjer nije ispravan, unesite opet: ";
		} while (smjer<0 || smjer>5);

		std::cout<<"\nPjescani sat unesene matrice je: "<<std::endl<<std::endl;;
		for (int i=0; i<kocka.size(); i++) {
			for (int j=0; j<kocka.at(i).size(); j++) {
				if (j<=kocka.size()/2){
						for (int r=0; r<j; r++)
						std::cout<<std::right<<std::setw(4)<<"";
					}
					else {
						for (int r=0; r<(kocka.size()-j-1); r++)
						std::cout<<std::right<<std::setw(4)<<"";
					}
				for (int k = 0; k<kocka.at(i).at(j).size(); k++) {
					std::cout<<std::right<<std::setw(4)<<kocka.at(i).at(j).at(k)<<"";
				}
				std::cout<<std::endl;
			}
			std::cout<<std::endl;
		}
	} catch (std::length_error izuzetak) {
		std::cout<<"\nIzuzetak: "<<izuzetak.what();
	}
	catch (std::domain_error izuzetak) {
		std::cout<<"\nIzuzetak: "<<izuzetak.what();
	}
	catch (...){
		std::cout<<"\nIzuzetak ";
	}
	return 0;
}