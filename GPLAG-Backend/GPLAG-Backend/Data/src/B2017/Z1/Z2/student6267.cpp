/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/

//6 6 0 0 0 15 12 6 1 25 1 5 2 9 1 1 20 15 10 5 3 2 19 130 14 8 90 6 20 12 17 2 12 3 5 1 8 4
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;
typedef std::vector<double> Vektor;

Matrica KreirajIUnesiMatricu(int visina, int sirina){
	Matrica pom(visina, Vektor (sirina));
	std::cout<<"Unesite elemente matrice: "<<std::endl;
	for(int i(0);i<visina;i++){
		for(int j(0);j<sirina;j++){
			std::cin>>pom.at(i).at(j);
		}
	}
	return pom;
}
bool DaLiJePlanina(Matrica m, int format){
	double suma(0);
	double tren_sum(0);
	
	for(int k(0);k<=format/2;k++){
		tren_sum=0;
		for(int i(0);i<format;i++){
			for(int j(0);j<format;j++){
				if(i==k || j==k || i==format-1-k || j==format-1-k){
					tren_sum+=m.at(i).at(j);
					
				}
			}
		
		}
		if(k==0) suma=tren_sum;
		else{
			if(tren_sum<suma)  return false;
			else suma=tren_sum;
		}
	}
	return true;
}

Matrica NajvecaPlaninaMatrice(Matrica m){
	int visina(m.size());
	int sirina(m.at(0).size());
	for(int i(1);i<sirina;i++){
		if(m.at(i).size()!=sirina) throw std::domain_error("Matrica nije korektna");
	}
	int format(visina);
	if(sirina<format) format=sirina;
	Matrica pom(format, Vektor (format));
	for(int t(format);t>=1;t--){
		if(t%2==1){
			Matrica pov(t, Vektor (t));
		
			for(int i(0);i<=m.size()-t;i++){
				for(int j(0);j<=m.at(0).size()-t;j++){
				
					int p(0);
					int q(0);
					for(int k(i);k<i+t;k++){
						q=0;
						for(int l(j);l<j+t;l++){
							pov.at(p).at(q)=m.at(k).at(l);
							q++;
						}
						p++;
					}
				if(DaLiJePlanina(pov,t)) return pov;
				}
			}
		}
	}
	return pom;
}


int main ()
{
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	int m,n;
	try{
	std::cin>>m>>n;
	if(m<0 || n<0) throw std::range_error("Dimenzije matrice moraju biti nenegativne!");
	Matrica mat(KreirajIUnesiMatricu(m,n));
	try{
		Matrica Vrh(NajvecaPlaninaMatrice(mat));
		std::cout<<"Najveca planina unesene matrice je: "<<std::endl;
		for(int i(0);i<Vrh.size();i++){
			for(int j(0);j<Vrh.size();j++){
				std::cout<<std::setw(6)<<Vrh.at(i).at(j);
			}
			std::cout<<""<<std::endl;
		}
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	}
	catch(std::range_error  greska){
		std::cout<<greska.what();
	}
	
	return 0;
}