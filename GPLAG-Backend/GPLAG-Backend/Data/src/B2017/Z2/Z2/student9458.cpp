/*B 2017/2018, Zadaća 2, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iomanip>
enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
template <typename Kont>
auto PjescaniSat(Kont kont, SmjerKretanja smjeric)-> typename std::remove_reference<decltype(kont)>::type {
	typename std::remove_reference<decltype(kont)>::type matrica;
	if(kont.size()==0) return matrica;
    if(kont.size()%2==0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	int x=kont.size();
	if(smjeric==SmjerKretanja::GoreDolje ||smjeric ==SmjerKretanja::DoljeGore) {
		for(int i=0; i<kont.size(); i++) {
			typename std::remove_reference<decltype(kont[0])>::type pomocna;
			for(int j=0; j<kont[i].size(); j++) {
				typename std::remove_reference<decltype(kont[0][0])>::type dek;
				for(int k=0; k<(kont[i][j]).size(); k++) {
					if(j==k || j+k==x-1 ) dek.push_back(kont[i][j][k]);
					else if(j<k && j+k<x-1 && j<x/2) dek.push_back(kont[i][j][k]);
					else if(j>k && j+k>x-1 && j>x/2) dek.push_back(kont[i][j][k]);

				}
				pomocna.push_back(dek);

			}

			matrica.push_back(pomocna);
		}
	}
	if(smjeric==SmjerKretanja::DesnoLijevo ||smjeric ==SmjerKretanja::LijevoDesno) {

		for(int i=0; i<kont.size(); i++) {
			typename std::remove_reference<decltype(kont[0])>::type pomocna;

			int l=kont.size()-1;
			typename std::remove_reference<decltype(kont[0])>::type okrenuta;
			for(int p=0; p<kont.size(); p++) {

				int k=0;
				typename std::remove_reference<decltype(kont[0][0])>::type vp;
				for(int f=kont.size()-1; f>=0; f--) {
					vp.push_back(kont[i][k][l]);
					k++;
				}
				l--;
				okrenuta.push_back(vp);
			}
			for(int j=0; j<kont[i].size(); j++) {
				typename std::remove_reference<decltype(kont[0][0])>::type dek;

				for(int k=0; k<kont.size(); k++) {
					if(j==k || j+k==x-1 ) dek.push_back(okrenuta[j][k]);
					else if(j<k && j+k<x-1 && j<x/2) dek.push_back(okrenuta[j][k]);
					else if(j>k && j+k>x-1 && j>x/2) dek.push_back(okrenuta[j][k]);

				}
				pomocna.push_back(dek);

			}

			matrica.push_back(pomocna);
		}
	}
	if(smjeric==SmjerKretanja::NaprijedNazad || smjeric==SmjerKretanja::NazadNaprijed) {

		int k=0;
		for(int i=0; i<kont.size(); i++) {
			typename std::remove_reference<decltype(kont[0])>::type pomocna;
			typename std::remove_reference<decltype(kont[0])>::type nova;

			for(int p=0; p<kont.size(); p++) {


				typename std::remove_reference<decltype(kont[0][0])>::type vp;
				for(int f=0; f<kont.size(); f++) {
					vp.push_back(kont[p][k][f]);

				}
				nova.push_back(vp);
			}
			for(int j=0; j<kont[i].size(); j++) {
				typename std::remove_reference<decltype(kont[0][0])>::type dek;

				for(int k=0; k<kont.size(); k++) {
					if(j==k || j+k==x-1 ) dek.push_back(nova[j][k]);
					else if(j<k && j+k<x-1 && j<x/2) dek.push_back(nova[j][k]);
					else if(j>k && j+k>x-1 && j>x/2) dek.push_back(nova[j][k]);

				}
				pomocna.push_back(dek);

			}

			matrica.push_back(pomocna);
			k++;
		}
	}

	return matrica;


}


int main ()
{
		try{
			int x;
				std::cout <<"Unesite dimenziju (x/y/z): ";
			do{

	
	std::cin>>x;
	if(x<=0) std::cout <<"Dimenzija nije ispravna, unesite opet: ";
	
			}while(x<0);
			
	std::vector<std::deque<std::deque<int>>> kontejner;
	std::cout <<"Unesite elemente kontejnera: ";
	for(int i=0; i<x; i++) {
		std::deque<std::deque<int>> mat ;
		for(int j=0; j<x; j++) {
			std::deque<int> ubaci;
			for (int k=0; k<x; k++) {
				int broj;
				std::cin>>broj;
				ubaci.push_back(broj);
			}
			mat.push_back(ubaci);

		}
		kontejner.push_back(mat);
	}
	std::cout <<"Unesite smjer kretanja [0 - 5]: ";
		int s;
	do{
		std::cin>>s;
		if(s<0 || s>5) std::cout<<"Smjer nije ispravan, unesite opet: ";
		}while(s<0 || s>5);
	



	std::vector<std::deque<std::deque<int>>>konacan;
	std::cout <<std::endl;

	

	if(s==0) {
		konacan=PjescaniSat(kontejner,SmjerKretanja::NaprijedNazad);
		std::cout<<"Pjescani sat unesene matrice je:"<<std::endl<<std::endl;

		for(int i=0; i<konacan.size(); i++) {
			for(int j=0; j<konacan[0].size(); j++) {
				if(j==0 || j==konacan.size()-1) {
					for(int k=0; k<konacan[0][0].size(); k++) {
						std::cout <<std::setw(4)<<konacan[i][j][k];
					}
				} else if(j<=konacan.size()/2){
					int brojPomicanja=(konacan[i][0].size()-konacan[i][j].size())/2;
					for(int k=0; k<konacan[0][0].size(); k++) {
						if(k<brojPomicanja || k>=int(konacan[0][0].size())-brojPomicanja ) std::cout <<std::setw(4)<<" ";
						else std::cout <<std::setw(4)<<konacan[i][j][k-brojPomicanja];


					}
				} else if(j>konacan.size()/2){
					int brojPomicanja=(konacan[i][0].size()-konacan[i][j].size())/2;
					for(int k=0; k<konacan[0][0].size(); k++) {
						if(k<brojPomicanja || k>=int(konacan[0][0].size())-brojPomicanja ) std::cout <<std::setw(4)<<" ";
						else std::cout <<std::setw(4)<<konacan[i][j][k-brojPomicanja];


					}
				}




				std::cout <<std::endl;
			}
			std::cout<<std::endl;
		}
	}

	if(s==1) {
		konacan=PjescaniSat(kontejner,SmjerKretanja::NazadNaprijed);
		std::cout<<"Pjescani sat unesene matrice je:"<<std::endl<<std::endl;

		for(int i=0; i<konacan.size(); i++) {
			for(int j=konacan[0].size()-1; j>=0; j--) {
				if(j==0 || j==konacan.size()-1) {
					for(int k=0; k<konacan[0][0].size(); k++) {
						std::cout <<std::setw(4)<<konacan[i][j][k];
					}
				} else if(j<=konacan.size()/2){
					int brojPomicanja=(konacan[i][0].size()-konacan[i][j].size())/2;
					for(int k=0; k<konacan[0][0].size(); k++) {
						if(k<brojPomicanja || k>=int(konacan[0][0].size())-brojPomicanja ) std::cout <<std::setw(4)<<" ";
						else std::cout <<std::setw(4)<<konacan[i][j][k-brojPomicanja];


					}
				} else if(j>konacan.size()/2){
					int brojPomicanja=(konacan[i][0].size()-konacan[i][j].size())/2;
					for(int k=0; k<konacan[0][0].size(); k++) {
						if(k<brojPomicanja || k>=int(konacan[0][0].size())-brojPomicanja ) std::cout <<std::setw(4)<<" ";
						else std::cout <<std::setw(4)<<konacan[i][j][k-brojPomicanja];


					}
				}




				std::cout <<std::endl;
			}
			std::cout<<std::endl;
		}
	}

	if(s==2) {
		konacan=PjescaniSat(kontejner,SmjerKretanja::GoreDolje);
		std::cout<<"Pjescani sat unesene matrice je:"<<std::endl<<std::endl;

		for(int i=0; i<konacan.size(); i++) {
			for(int j=0; j<konacan[0].size(); j++) {
				if(j==0 || j==konacan.size()-1) {
					for(int k=0; k<konacan[0][0].size(); k++) {
						std::cout <<std::setw(4)<<konacan[i][j][k];
					}
				} else if(j<=konacan.size()/2){
					int brojPomicanja=(konacan[i][0].size()-konacan[i][j].size())/2;
					for(int k=0; k<konacan[0][0].size(); k++) {
						if(k<brojPomicanja || k>=int(konacan[0][0].size())-brojPomicanja ) std::cout <<std::setw(4)<<" ";
						else std::cout <<std::setw(4)<<konacan[i][j][k-brojPomicanja];


					}
				} else if(j>konacan.size()/2){
					int brojPomicanja=(konacan[i][0].size()-konacan[i][j].size())/2;
					for(int k=0; k<konacan[0][0].size(); k++) {
						if(k<brojPomicanja || k>=int(konacan[0][0].size())-brojPomicanja ) std::cout <<std::setw(4)<<" ";
						else std::cout <<std::setw(4)<<konacan[i][j][k-brojPomicanja];


					}
				}




				std::cout <<std::endl;
			}
			std::cout<<std::endl;
		}
	}


	if(s==3) {
	konacan=PjescaniSat(kontejner,SmjerKretanja::DoljeGore);
		std::cout<<"Pjescani sat unesene matrice je:"<<std::endl<<std::endl;

		for(int i=0; i<konacan.size(); i++) {
			for(int j=konacan[0].size()-1; j>=0; j--) {
				if(j==0 || j==konacan.size()-1) {
					for(int k=0; k<konacan[0][0].size(); k++) {
						std::cout <<std::setw(4)<<konacan[i][j][k];
					}
				} else if(j<=konacan.size()/2){
					int brojPomicanja=(konacan[i][0].size()-konacan[i][j].size())/2;
					for(int k=0; k<konacan[0][0].size(); k++) {
						if(k<brojPomicanja || k>=int(konacan[0][0].size())-brojPomicanja ) std::cout <<std::setw(4)<<" ";
						else std::cout <<std::setw(4)<<konacan[i][j][k-brojPomicanja];


					}
				} else if(j>konacan.size()/2){
					int brojPomicanja=(konacan[i][0].size()-konacan[i][j].size())/2;
					for(int k=0; k<konacan[0][0].size(); k++) {
						if(k<brojPomicanja || k>=int(konacan[0][0].size())-brojPomicanja ) std::cout <<std::setw(4)<<" ";
						else std::cout <<std::setw(4)<<konacan[i][j][k-brojPomicanja];


					}
				}




				std::cout <<std::endl;
			}
			std::cout<<std::endl;
		}
	}

	if(s==4) {
		konacan=PjescaniSat(kontejner,SmjerKretanja::LijevoDesno);
		std::cout<<"Pjescani sat unesene matrice je:"<<std::endl<<std::endl;

		for(int i=0; i<konacan.size(); i++) {
			for(int j=konacan[0].size()-1; j>=0; j--) {
				if(j==0 || j==konacan.size()-1) {
					for(int k=0; k<konacan[0][0].size(); k++) {
						std::cout <<std::setw(4)<<konacan[i][j][k];
					}
				} else if(j<=konacan.size()/2){
					int brojPomicanja=(konacan[i][0].size()-konacan[i][j].size())/2;
					for(int k=0; k<konacan[0][0].size(); k++) {
						if(k<brojPomicanja || k>=int(konacan[0][0].size())-brojPomicanja ) std::cout <<std::setw(4)<<" ";
						else std::cout <<std::setw(4)<<konacan[i][j][k-brojPomicanja];


					}
				} else if(j>konacan.size()/2){
					int brojPomicanja=(konacan[i][0].size()-konacan[i][j].size())/2;
					for(int k=0; k<konacan[0][0].size(); k++) {
						if(k<brojPomicanja || k>=int(konacan[0][0].size())-brojPomicanja ) std::cout <<std::setw(4)<<" ";
						else std::cout <<std::setw(4)<<konacan[i][j][k-brojPomicanja];


					}
				}




				std::cout <<std::endl;
			}
			std::cout<<std::endl;
		}
	}

	if(s==5) {
		konacan=PjescaniSat(kontejner,SmjerKretanja::DesnoLijevo);
		std::cout<<"Pjescani sat unesene matrice je:"<<std::endl<<std::endl;

		for(int i=0; i<konacan.size(); i++) {
			for(int j=0; j<konacan[0].size(); j++) {
				if(j==0 || j==konacan.size()-1) {
					for(int k=0; k<konacan[0][0].size(); k++) {
						std::cout <<std::setw(4)<<konacan[i][j][k];
					}
				} else if(j<=konacan.size()/2){
					int brojPomicanja=(konacan[i][0].size()-konacan[i][j].size())/2;
					for(int k=0; k<konacan[0][0].size(); k++) {
						if(k<brojPomicanja || k>=int(konacan[0][0].size())-brojPomicanja ) std::cout <<std::setw(4)<<" ";
						else std::cout <<std::setw(4)<<konacan[i][j][k-brojPomicanja];


					}
				} else if(j>konacan.size()/2){
					int brojPomicanja=(konacan[i][0].size()-konacan[i][j].size())/2;
					for(int k=0; k<konacan[0][0].size(); k++) {
						if(k<brojPomicanja || k>=int(konacan[0][0].size())-brojPomicanja ) std::cout <<std::setw(4)<<" ";
						else std::cout <<std::setw(4)<<konacan[i][j][k-brojPomicanja];


					}
				}




				std::cout <<std::endl;
			}
			std::cout<<std::endl;
		}
	}
		}
	catch(std::length_error izuzetak){
		std::cout <<"Izuzetak: "<<izuzetak.what();
	}
	return 0;
}