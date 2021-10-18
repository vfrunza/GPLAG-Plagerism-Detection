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
#include <iomanip>
#include <type_traits>

enum class SmjerKretanja
{
    NaprijedNazad,NazadNaprijed,GoreDolje,DoljeGore,LijevoDesno,DesnoLijevo
};

template <typename tipkont>
auto PjescaniSat ( tipkont kont,SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont)>::type 
{
	int n=kont.size();
	tipkont nova;
	
	if (smjer==SmjerKretanja::GoreDolje ) {
		for(int i=0;i<n;i++){
			std::deque<std::deque<int>> mat;
		for(int j=0; j<n; j++) {
			std::deque<int> d;
			for(int k=0; k<n; k++) {
				int diagA=j;
				int diagB=n-j-1;
				if(diagA<=diagB){
					if(k>=diagA&&k<=diagB){
						d.push_back(kont[i][j][k]);
					}
					else continue;
				}
				else{
					if(k>=diagB&&k<=diagA){
						d.push_back(kont[i][j][k]);
					}
					else continue;
				}
			}
			mat.push_back(d);
		}
		nova.push_back(mat);
	}
	}
	//else if()
	return nova;
}
int main ()
{
	std::cout<<"Unesite dimenziju (x/y/z): ";
	int n;
	std::cin>>n;
	
	std::vector<std::deque<std::deque<int>>> kont;
	std::vector<std::deque<std::deque<int>>> nova;
	//std::deque<int> d;
	//std::deque<std::deque<int>> mat;
	std::cout<<"Unesite elemente kontejnera: ";
	for(int i=0; i<n; i++) {
		std::deque<std::deque<int>> mat;
		for(int j=0; j<n; j++) {
			std::deque<int> d;
			for(int k=0; k<n; k++) {
				int x;
				std::cin>>x;
				d.push_back(x);
			}
			mat.push_back(d);
		}
		kont.push_back(mat);
	}
	
	int smjer;
	std::cout<<"Unesite smjer kretanja [0 - 5]: ";
	std::cin>>smjer;
	if(smjer==0) nova=PjescaniSat(kont,SmjerKretanja::NaprijedNazad);
	else if(smjer==1) nova=PjescaniSat(kont, SmjerKretanja::NazadNaprijed);
	else if(smjer==2) nova=PjescaniSat(kont,SmjerKretanja::GoreDolje);
	else if(smjer==3) nova=PjescaniSat(kont,SmjerKretanja::DoljeGore);
	else if(smjer==4) nova=PjescaniSat(kont,SmjerKretanja::LijevoDesno);
	else if(smjer==5) nova=PjescaniSat(kont,SmjerKretanja::DesnoLijevo);
	for(int i=0; i<n; i++) {
		//std::deque<std::deque<int>> mat;
		for(int j=0; j<nova[0].size(); j++) {
			//std::deque<int> d;
			for(int k=0; k<nova[i][j].size(); k++) {
				std::cout<<std::setw(4)<<nova[i][j][k];
			}
			std::cout<<std::endl;
		}
		std::cout<<std::endl;
	}
	
	
	/*std::vector<std::deque<int>> mat{{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25},{26,27,28,29,30},{31,32,33,34,35}};
	std::vector<std::deque<int>> nova;
	nova=PjescaniSat(mat,GoreDolje);
	ispis(nova);*/
	return 0;
}