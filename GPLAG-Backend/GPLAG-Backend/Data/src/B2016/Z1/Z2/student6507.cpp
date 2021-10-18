/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<double> Vektor;
typedef std::vector<Vektor> Matrica; 

int BrojKolona(Matrica m){
	return m[0].size();
}

int BrojRedova(Matrica m){
	return m.size();
}

void IspisiMatricu(Matrica m){
	std::cout<<std::endl<<"Rezultantna matrica:"<<std::endl;
	for(Vektor x : m){
		for(double y : x){
			std::cout<<std::setw(4)<<y;
		}
		std::cout<<std::endl;
	}
}
bool JeLiGrbava(Matrica m){
	for(Vektor x : m){
		if(x.size() != m[0].size()) return false;
	}
	return true;
}

Matrica HorizontalnoOgledalo(Matrica m){
	for(int i=0; i<BrojRedova(m); i++){
		for(int j=0; j<BrojKolona(m)/2; j++){
		  double pomocna;
		  pomocna=std::move(m[i][j]); m[i][j]=std::move(m[i][BrojKolona(m)-1-j]); m[i][BrojKolona(m)-1-j]=std::move(pomocna);
		}
	}
	return m;
}

Matrica VertikalnoOgledalo(Matrica m){
	for(int i=0; i<BrojRedova(m)/2; i++){
		Vektor pomocna;
		pomocna=std::move(m[i]); m[i]=std::move(m[BrojRedova(m)-1-i]); m[BrojRedova(m)-1-i]=std::move(pomocna);
	}
	return m;
}

Matrica KombinovanoOgledalo(Matrica m){
	return HorizontalnoOgledalo(VertikalnoOgledalo(m));
}

bool DaLiJePrazna(Matrica m){
	for(Vektor x : m)
		if(!x.size()==0) return false;
	
	return true;
}

Matrica OgledaloMatrica(Matrica m){
	if(!JeLiGrbava(m)) throw std::domain_error ("Matrica nije korektna");
	if(m.size()!= 0 && DaLiJePrazna(m)) return Matrica (3*m.size(), Vektor (0));
	if(m.size()==0 && DaLiJePrazna(m)) return Matrica (0, Vektor(0));
	Matrica m1(3*m.size(), Vektor (3*m[0].size()));
	Matrica hv(KombinovanoOgledalo(m)), h(HorizontalnoOgledalo(m)), v(VertikalnoOgledalo(m));
	for(int i=0; i<m.size(); i++)
		for(int j=0; j<m[0].size(); j++)
			m1[i][j]=hv[i][j];
	
	for(int i=0; i<m.size(); i++)
		for(int j=m[0].size(); j<2*m[0].size(); j++)
			m1[i][j]=v[i][j-m[0].size()];

	for(int i=0; i<m.size(); i++)
		for(int j=2*m[0].size(); j<3*m[0].size(); j++)
			m1[i][j]=hv[i][j-2*m[0].size()];
	
	for(int i=m.size(); i<2*m.size(); i++)
		for(int j=0; j<m[0].size(); j++)
			m1[i][j]=h[i-m.size()][j];
	
	for(int i=m.size(); i<2*m.size(); i++)
		for(int j=m[0].size(); j<2*m[0].size(); j++)
			m1[i][j]=m[i-m.size()][j-m[0].size()];
	for(int i=m.size(); i<2*m.size(); i++)
		for(int j=2*m[0].size(); j<3*m[0].size(); j++)
			m1[i][j]=h[i-m.size()][j-2*m[0].size()];	
	for(int i=2*m.size(); i<3*m.size(); i++)
		for(int j=0; j<m[0].size(); j++)
			m1[i][j]=hv[i-2*m.size()][j];
	for(int i=2*m.size(); i<3*m.size(); i++)
		for(int j=m[0].size(); j<2*m[0].size(); j++)
			m1[i][j]=v[i-2*m.size()][j-m[0].size()];
			
	for(int i=2*m.size(); i<3*m.size(); i++)
		for(int j=2*m[0].size(); j<3*m[0].size(); j++)
			m1[i][j]=hv[i-2*m.size()][j-2*m[0].size()];
	
	return m1;
	
}

int main ()
{
	try{
	std::cout<<"Unesite dimenzije matrice (m n): " ;
	int a, b;
	std::cin>>a>>b;
	if(a<0 || b<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice: ";
	Matrica m(a, Vektor (b));
	for(int i=0; i<a; i++)
		for(int j=0; j<b; j++)
			std::cin>>m[i][j];
	IspisiMatricu(OgledaloMatrica(m));
	} catch(std::domain_error izuzetak){
		std::cout<<"IZUZETAK: "<<izuzetak.what()<<std::endl;
	}
	return 0;
}