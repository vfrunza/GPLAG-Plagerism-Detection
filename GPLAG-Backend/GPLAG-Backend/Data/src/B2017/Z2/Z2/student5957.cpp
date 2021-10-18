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
#include <iomanip>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <stdexcept>
using std::cout;
using std::cin;
using std::vector;
using std::deque;
typedef vector<deque<deque<int>>> KONT;
enum class SmjerKretanja{NaprijedNazad,NazadNaprijed,GoreDolje,DoljeGore,LijevoDesno,DesnoLijevo};

void UnesiMat(deque<deque<int>> &mat,int dim){
	for(int i(0);i<dim;i++){
		deque<int> dek;
		for(int j(0);j<dim;j++){
			int x(0);
			cin>>x;
			dek.push_back(x);
		}
		mat.push_back(dek);
	}
}

template<typename Neki3DTip>
	void DaLiJeKocka(Neki3DTip &Kont){
		for(int i(0);i<Kont.size();i++){
			if(Kont.at(0).size()!=Kont.at(i).size()) throw std::domain_error("3D matrica nema oblik kocke");
		}
		for(int i(0);i<Kont.size();i++){
			for(int j(0);j<Kont.at(i).size();j++){
					if(Kont.at(i).size()!=Kont.at(i).at(j).size()) throw std::domain_error("3D matrica nema oblik kocke");
			}
		}
	}
	
template<typename Neki1DTip>
	void Red(Neki1DTip &v, Neki1DTip &pom_red, int n){
		std::copy(v.begin()+n,v.begin()+v.size()-n,std::back_inserter(pom_red));
	}
	
template<typename Neki2DTip>
	Neki2DTip Matrica(Neki2DTip &Mat){
		Neki2DTip pom_mat(Mat.size());
		for(int i(0);i<Mat.size();i++){
			if(i==(Mat.size()-1)/2) Red(Mat.at(i),pom_mat.at(i),i);
			else if(i<(Mat.size()-1)/2) Red(Mat.at(i),pom_mat.at(i),i);
			else Red(Mat.at(i),pom_mat.at(i),Mat.size()-i-1);
		}
		return pom_mat;
	}
	
template<typename Neki3DTip>
	void IzbaciEl(Neki3DTip &Kont){
		Neki3DTip pom(Kont.size());
		for(int i(0);i<Kont.size();i++){
			pom.at(i)=Matrica(Kont.at(i));
		}
		Kont=pom;
	}
	
template<typename Neki3DTip>
	void ZaokreniGD(Neki3DTip &Kont){
		for(int i(0);i<Kont.size();i++){
			for(int j(0);j<Kont.size()/2;j++){
				std::swap_ranges(Kont.at(i).at(j).begin(),Kont.at(i).at(j).end(),Kont.at(i).at(Kont.size()-j-1).begin());
			}
		}
	}

template<typename Neki3DTip>
	void ZaokreniDL(Neki3DTip &Kont){
		Neki3DTip PomocniKont(Kont);
		for(int i(0);i<Kont.size();i++){
			for(int j(0);j<Kont.size();j++){
				for(int k(0);k<Kont.size();k++){
					PomocniKont.at(i).at(j).at(k)=Kont.at(i).at(k).at(Kont.size()-j-1);
				}
			}
		}
		Kont=PomocniKont;
	}
	
template<typename Neki3DTip>
	void ZaokreniNN(Neki3DTip &Kont){
		Neki3DTip PomocniKont(Kont);
		for(int j(0);j<Kont.size();j++){
			for(int i(0);i<Kont.size();i++){
					std::copy(Kont.at(i).at(j).begin(),Kont.at(i).at(j).end(),PomocniKont.at(j).at(i).begin());
			}
		}
		Kont=PomocniKont;
	}

template<typename Neki3DTip>
	Neki3DTip PjescaniSat(Neki3DTip Kont,enum SmjerKretanja smjer){
		if(Kont.size()==0) return Neki3DTip();
		if(Kont.size()==1) return Kont;
		DaLiJeKocka(Kont);
		if(Kont.at(0).size()%2==0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
		if(smjer==SmjerKretanja(3)){ ZaokreniGD(Kont); }
		else if(smjer==SmjerKretanja(5)){ ZaokreniDL(Kont); }
		else if(smjer==SmjerKretanja(4)){ ZaokreniDL(Kont); ZaokreniGD(Kont); }
		else if(smjer==SmjerKretanja(0)){ ZaokreniNN(Kont); }
		else if(smjer==SmjerKretanja(1)){ ZaokreniNN(Kont); ZaokreniGD(Kont); }
		IzbaciEl(Kont);
		return Kont;
	}

int main ()
{
	int dim(0);
	cout<<"Unesite dimenziju (x/y/z): ";
	cin>>dim;
	while(dim<0){
		cout<<"Dimenzija nije ispravna, unesite opet: ";
		cin>>dim;
	}
	cout<<"Unesite elemente kontejnera: ";
	KONT Kont(dim);
	for(int i(0);i<dim;i++){
		UnesiMat(Kont.at(i),dim);
	}
	int smjer(0);
	cout<<"Unesite smjer kretanja [0 - 5]: ";
	cin>>smjer;
	while(!(smjer>=0 && smjer<=5)){
		cout<<"Smjer nije ispravan, unesite opet: ";
		cin>>smjer;
	}
	try{
		Kont=PjescaniSat(Kont,SmjerKretanja(smjer));
		cout<<std::endl<<"Pjescani sat unesene matrice je:"<<std::endl;
		for(int i(0);i<Kont.size();i++){
			for(int j(0);j<Kont.at(i).size();j++){
				if(j<Kont.size()/2+1) cout<<std::string((j)*4,' ');
				else cout<<std::string((Kont.size()-j-1)*4,' ');
				for(int k(0);k<Kont.at(i).at(j).size();k++){
					if(k==0) cout<<std::right<<std::setw(4)<<Kont.at(i).at(j).at(k);
					else cout<<std::right<<std::setw(4)<<Kont.at(i).at(j).at(k);
				}
				cout<<std::endl;
			}
			cout<<std::endl;
		}
	}
	catch(std::domain_error izuzetak){
		cout<<std::endl<<"Izuzetak: "<<izuzetak.what();
	}
	catch(std::length_error izuzetak){
		cout<<std::endl<<"Izuzetak: "<<izuzetak.what();
	}
	
	return 0;
}