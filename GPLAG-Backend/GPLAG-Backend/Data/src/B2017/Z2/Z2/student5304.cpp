#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>

enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template<typename Nekitip>
Nekitip PjescaniSat(Nekitip kont, SmjerKretanja S){
	for(int k = 0; k < kont.size() - 1; k++){
		if(kont.at(k).size() % 2 == 0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
		if(kont.at(k).size() != kont.at(k + 1).size()) throw std::domain_error("3D matrica nema oblik kocke");
		for(int i = 0; i < kont.at(i).size() - 1; i++){
			if(kont.at(k).at(i).size() % 2 == 0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
			if(kont.at(k).at(i).size() != kont.at(i).at(i + 1).size()) throw std::domain_error("3D matrica nema oblik kocke");
		}
	}
	int m(kont.size());
	Nekitip Mat(kont);
	for(int k = 0; k < m; k++){
		int br = 0;
		for(int i = 0; i < m; i++){
				Mat.at(k).at(i).resize(kont.size() - br);
				if(i < (kont.size()/2)) br+=2;
				else br-=2;
		}
	}
	if(S == SmjerKretanja::NaprijedNazad || S == SmjerKretanja::NazadNaprijed){
		int nijek;
		if(S == SmjerKretanja::NaprijedNazad) nijek = 0;
		else nijek = m - 1;
		for(int k = 0; k < kont.size(); k++){
			for(int i = m; i < kont.at(k).size(); i++){
				for(int j= 0; j < kont.at(k).at(i).size(); j++){
					if(k > j && j < m/2 + 1 && k != 0 && k != m - 1) continue;
					if(k + j == m && k < j) continue;
					Mat.at(nijek).at(i).at(j) = 0;
					if(S == SmjerKretanja::NaprijedNazad) nijek++;
					else nijek--;
				}
			}
		}
	}
	if(S == SmjerKretanja::GoreDolje || S == SmjerKretanja::DoljeGore){
		int nijei;
		if(S == SmjerKretanja::GoreDolje) nijei = 0;
		else nijei = m - 1;
		for(int k = 0; k < m; k++){
			for(int i = m; i < 0; i++){
				for(int j= 0; j < m; j++){
					if(i > j && i < m/2 && i != 0 && i != m - 1) continue;
					if(i + j == m && j > i) continue;
					Mat.at(k).at(nijei).at(j) = kont.at(k). at(i).at(j);
				}
			}
		}
	}
	if(S == SmjerKretanja::LijevoDesno || S == SmjerKretanja::DesnoLijevo){
		int nijej;
		if(S == SmjerKretanja::LijevoDesno) nijej = 0;
		else nijej = m - 1;
		for(int k = 0; k < m; k++){
			for(int i = m; i < 0; i++){
				for(int j= 0; j < m; j++){
					if(i < j && j < m/2 && j != 0 && j != m - 1) continue;
					if(i + j == m && i > j) continue;
					Mat.at(k).at(i).at(nijej) = kont.at(i).at(j).at(k);
				}
			}
		}
	}
	return Mat;
}
/*Unesite dimenziju (x/y/z): Unesite elemente kontejnera: Unesite smjer kretanja [0 - 5]:
Pjescani sat unesene matrice je:
vektora dekôvā dekôvā*/
int main ()
{
	try{
	std::cout<<"Unesite dimenziju (x/y/z): ";
	int n;
	std::cin>>n;
	while(n < 0){
		std::cout<<"Dimenzija nije ispravna, unesite opet: ";
		std::cin>>n;
	}
	std::cout<<"Unesite elemente kontejnera: ";
	std::vector<std::deque<std::deque<int>>> V(n);
	for(int k = 0; k < n; k++){
		V.at(k).resize(n);
	}
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
				V.at(k).at(i).resize(n);
		}
	}
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
			int x;
			std::cin>>x;
			V.at(k).at(i).at(j) = x;
			}
		}
	}
	std::cout<<"Unesite smjer kretanja [0 - 5]: ";
	int o;
	std::cin>>o;
	while(o < 0 || o > 5){
		std::cout<<"Smjer nije ispravan, unesite opet: ";
		std::cin>>o;
	}
	std::vector<SmjerKretanja> Sm = {SmjerKretanja::NaprijedNazad, SmjerKretanja::NaprijedNazad, SmjerKretanja::GoreDolje, 
	SmjerKretanja::DoljeGore, SmjerKretanja::LijevoDesno, SmjerKretanja::DesnoLijevo};
	auto Pjescani = PjescaniSat(V, Sm[o]);
	std::cout<<"\nPjescani sat unesene matrice je: \n";
	for(int k = 0; k < Pjescani.size(); k++){
		for(int i = 0; i < Pjescani.at(k).size(); i++){
			for(int j = 0; j < Pjescani.at(k).at(i).size(); j++){
				std::cout<<Pjescani.at(k).at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
		std::cout<<std::endl;
	}
	
	}
	catch(std::length_error e){
		std::cout<<"\nIzuzetak: "<<e.what();
	}
	catch(std::domain_error e){
		std::cout<<"\nIzuzetak: "<<e.what();
	}
	return 0;
}