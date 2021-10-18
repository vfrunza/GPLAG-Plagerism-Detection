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
#include <stdexcept>

enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

template<typename D_kontenjer>
D_kontenjer Transponovana3DMatrica(D_kontenjer kont1){
	D_kontenjer pomocni;
	pomocni.resize(kont1.size());
	for (int i(0);i<pomocni.size();i++){
		pomocni.at(i).resize(kont1.at(i).size());
			for (int j(0);j<pomocni.at(i).size();j++){
				pomocni.at(i).at(j).resize(kont1.at(i).at(j).size());
			}
	}
	for (int i(0);i<kont1.size();i++){
			for (int j(0);j<kont1.at(i).size();j++){
				for(int k(0);k<kont1.at(i).at(j).size();k++){
					pomocni.at(i).at(k).at(j)=kont1.at(i).at(j).at(k);
					
			}
		}
	}
	return pomocni;
}
template<typename D_kontenjer>
D_kontenjer aaaa (D_kontenjer kont1){
	D_kontenjer pomocni;
	pomocni.resize(kont1.size());
	for (int i(0);i<pomocni.size();i++){
		pomocni.at(i).resize(kont1.at(i).size());
			for (int j(0);j<pomocni.at(i).size();j++){
				pomocni.at(i).at(j).resize(kont1.at(i).at(j).size());
			}
		}
	for (int i(0);i<kont1.size();i++){
			for (int j(0);j<kont1.at(i).size();j++){
				for(int k(0);k<kont1.at(i).at(j).size();k++){
					pomocni.at(j).at(i).at(k)=kont1.at(i).at(j).at(k);
				}
			}
		}
		return pomocni;
}
template<typename D_kontenjer>
D_kontenjer ObrniRedove (D_kontenjer kont1){
	D_kontenjer pomocni;
	pomocni.resize(kont1.size());
	for (int i(0);i<pomocni.size();i++){
		pomocni.at(i).resize(kont1.at(i).size());
			for (int j(0);j<pomocni.at(i).size();j++){
				pomocni.at(i).at(j).resize(kont1.at(i).at(j).size());
			}
		}
	for (int i(0);i<kont1.size();i++){
			for (int j(0);j<kont1.at(i).size();j++){
				for(int k(0);k<kont1.at(i).at(j).size();k++){
					pomocni.at(i).at(kont1.size()-j-1).at(k)=kont1.at(i).at(j).at(k);
				}
			}
		}
		return pomocni;
}
template <typename D_kontenjer>
D_kontenjer PjescaniSat(D_kontenjer kont, SmjerKretanja smjer){
	if (kont.size()==0 || kont.size()==1) return kont;
	if (kont.size() != kont.at(0).size() || kont.size() != kont.at(0).at(0).size()) throw std::domain_error ("3D matrica nema oblik kocke");
	D_kontenjer pomocni_kont;
	pomocni_kont.resize(kont.size());
	if (kont.size()%2==0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	for (int i(0);i<pomocni_kont.size();i++){
		pomocni_kont.at(i).resize(kont.at(i).size());
			for (int j(0);j<pomocni_kont.at(i).size();j++){
				pomocni_kont.at(i).at(j).resize(kont.at(i).at(j).size());
			}
		}
		if (smjer==SmjerKretanja::LijevoDesno || smjer==SmjerKretanja::DesnoLijevo){
			kont=Transponovana3DMatrica (kont);
		}
		if (smjer==SmjerKretanja::NaprijedNazad || smjer==SmjerKretanja::NazadNaprijed){
			kont=aaaa(kont);
		}
		for (int i(0);i<kont.size();i++){
			for (int j(0);j<kont.at(i).size();j++){
				for(int k(0);k<kont.at(i).at(j).size();k++){
					if ((k>=j && k<=int(kont.at(i).at(j).size()/2)) || (k<=j && k>=int(kont.at(i).at(j).size()/2))
					|| (k+j<=kont.at(i).at(j).size()-1 && k>=int(kont.at(i).at(j).size()/2)) 
					|| (k+j>=kont.at(i).at(j).size()-1 && k<=int(kont.at(i).at(j).size()/2)) ) pomocni_kont.at(i).at(j).at(k)=kont.at(i).at(j).at(k);
					else pomocni_kont.at(i).at(j).at(k)= 5903;
				}
			}
		}
		if (smjer==SmjerKretanja::DoljeGore || smjer==SmjerKretanja::DesnoLijevo || smjer==SmjerKretanja::NazadNaprijed){
			pomocni_kont=ObrniRedove(pomocni_kont);
		}
	return pomocni_kont;
}

int main ()
{
	std::vector<std::deque<std::deque<int>>> ko,o;
	int a(0),x,n;
	std::cout << "Unesite dimenziju (x/y/z): ";
	for(;;){
		std::cin >> a;
		if (a>=0) break;
		else if (a<0) std::cout << "Dimenzija nije ispravna, unesite opet: ";
	}
	std::cout << "Unesite elemente kontejnera: ";
	ko.resize(a);
	for (int i(0);i<a;i++){
		ko.at(i).resize(a);
		for (int j(0);j<a;j++){
			ko.at(i).at(j).resize(a);
		}
	}
	for (int i(0);i<a;i++){
		for (int j(0);j<a;j++){
			for(int k(0);k<a;k++){
				std::cin >> x;
				ko.at(i).at(j).at(k)=x;
			}
		}
	}
	std::cout << "Unesite smjer kretanja [0 - 5]: ";
	for(;;){
		std::cin >> n;
		if (n>=0 && n<=5) break;
		else std::cout << "Smjer nije ispravan, unesite opet: ";
	}
	try{
		if (n==0) o=PjescaniSat(ko,SmjerKretanja::NaprijedNazad);
		else if (n==1) o=PjescaniSat(ko,SmjerKretanja::NazadNaprijed);
		else if (n==2) o=PjescaniSat(ko,SmjerKretanja::GoreDolje);
		else if (n==3) o=PjescaniSat(ko,SmjerKretanja::DoljeGore);
		else if (n==4) o=PjescaniSat(ko,SmjerKretanja::LijevoDesno);
		else if (n==5) o=PjescaniSat(ko,SmjerKretanja::DesnoLijevo);
		std::cout << std::endl << "Pjescani sat unesene matrice je:" << std::endl;
		for (int i(0);i<o.size();i++){
			for (int j(0);j<o.at(i).size();j++){
				for(int k(0);k<o.at(i).at(j).size();k++){
					if (o.at(i).at(j).at(k)==5903) std::cout << std::setw(4) << " ";
					else std::cout << " " <<std::setw(3)  << o.at(i).at(j).at(k);
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	}
	catch (std::length_error err){
		std::cout << std::endl <<"Izuzetak: " << err.what() << std::endl;
	}
	catch (std::domain_error err){
		std::cout << std::endl <<"Izuzetak: " << err.what() << std::endl;
	}
	return 0;
}