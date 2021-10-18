/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int br_kolona, int br_redova){
	return Matrica(br_kolona,std::vector<double> (br_redova));
}


Matrica UnesiMatricu(int br_redova, int br_kolona){
	auto m(KreirajMatricu(br_redova,br_kolona));
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[i].size();j++){
			std::cin>>m[i][j];
		}
}
	return m;
}
int BrojRedova(Matrica m){
	return m.size();
}
int BrojKolona(Matrica m){
	return m[0].size();
}


Matrica v(Matrica m){
	Matrica ver;
	for ( int i=m.size()-1;i>=0;i--)
	ver.push_back(m[i]);
	return ver;
}
Matrica h(Matrica m){
	Matrica hor;
	for(int j=0;j<m.size();j++){
			std::vector<double> pom;
for(int i=m[j].size()-1;i>=0;i--)
pom.push_back(m[j][i]);
hor.push_back(pom);

	}

	return hor;
}
Matrica hv(Matrica m){
	Matrica komb;
	komb=(h(v(m)));
	return komb;
	
}

Matrica OgledaloMatrica(Matrica mat) {
	int zadnja_vel=-1;
	for( auto x: mat){
		if(zadnja_vel==-1)
		zadnja_vel=x.size();
	
		if(zadnja_vel!=x.size())
		throw std::domain_error("Matrica nije korektna!");
		zadnja_vel=x.size();
	}
	
	std::vector<std::vector<double>> rez;
	std::vector<std::vector<double>> h_ = h(mat);
	std::vector<std::vector<double>> v_ = v(mat);
	std::vector<std::vector<double>> hv_ = hv(mat);
	
	
	
	int l(0);
	std::vector<double> prazan;
	for(int i(0); i<hv_.size(); i++) {
		rez.push_back(prazan);
		for(int j(0); j<hv_[i].size(); j++) {
			rez[l].push_back(hv_[i][j]);
		}
		l++;
	}
	l= 0;
	for(int i(0); i<v_.size(); i++) {
		rez.push_back(prazan);
		for(int j=0; j<v_[i].size(); j++) {
			rez[l].push_back(v_[i][j]);
		}
		l++;

	}
	l=0;
	for(int i(0); i<hv_.size(); i++) {
		for(int j=0; j<hv_[i].size(); j++) {
			rez[l].push_back(hv_[i][j]);
		}
		l++;
	}
int k=l;	
	
	// ------------------------------------------------------------
	

	for(int i(0); i<h_.size(); i++) {
		rez.push_back(prazan);
		for(int j(0); j<h_[i].size(); j++) {
			rez[l].push_back(h_[i][j]);
		}
		l++;
	}
	l=k;
	
		for(int i(0); i<mat.size(); i++) {
			rez.push_back(prazan);
		for(int j=0; j<mat[i].size(); j++) {
			rez[l].push_back(mat[i][j]);
		}
l++;
}
	l=k;
	for(int i(0); i<h_.size(); i++) {
		rez.push_back(prazan);
		for(int j=0; j<h_[i].size(); j++) {
			rez[l].push_back(h_[i][j]);
		}
		l++;
	}
	
	// ------------------------------------------------------------
	
k=l;
	for(int i(0); i<hv_.size(); i++) {
		for(int j(0); j<hv_[i].size(); j++) 
			rez[l].push_back(hv_[i][j]);
		
		l++;

	}
l=k;
for(int i(0); i<v_.size(); i++) {
		rez.push_back(prazan);
		for(int j=0; j<v_[i].size(); j++) {
			rez[l].push_back(v_[i][j]);
		}
		l++;
		
	}
l=k;
for(int i(0); i<hv_.size(); i++) {
		rez.push_back(prazan);
		for(int j=0; j<hv_[i].size(); j++) {
			rez[l].push_back(hv_[i][j]);
		}
		l++;
		
	}
	
	return rez;
}
int main ()
{
int m;
int n;
std::cout<<"Unesite dimenzije matrice (m n): ";
std::cin>>m>>n;
if( m<0 || n<0) {
std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;
std::cin.ignore(1000,'\n');}
auto o(UnesiMatricu(m,n));
std::cout<<std::endl;

Matrica b=OgledaloMatrica(o);

std::cout<<"Rezultantna matrica: "<<std::endl;


for(auto x: OgledaloMatrica(o)) {
		for(auto y: x) 
			std::cout<<std::setw(4)<< y <<"";
		
		std::cout << std::endl;
	}
	return 0;
}