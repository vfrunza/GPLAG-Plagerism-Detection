/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int m, int n) {
	return Matrica(m, std::vector<double>(n));
}
Matrica UnesiMatricu(int m, int n) {
	auto mat(KreirajMatricu(m,n));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
		std::cin>>mat.at(i).at(j);
		}
	}
	return mat;
}

void IspisiMatricu(Matrica mat) {
	for(auto red:mat) {
		for(auto x:red) std::cout<<std::setw(6)<<x;
		std::cout<<std::endl;
	}
}

Matrica NajvecaPlaninaMatrice(Matrica v) {
	Matrica planina(0);
	if(v.size()==0 || v.at(0).size()==0) {
		return planina;
	}
		for(int i=0; i<v.size(); i++) {
			if(v.at(0).size()!=v.at(i).size()) throw std::domain_error("Matrica nije korektna");
		}
		
		
	double suma(0);
	std::vector<double>red;
	int pozi, pozj;
	if(v.size()==1 || v.size()==2) {
		double max(0);
		max=v.at(0).at(0);
		for(int i=0; i<v.size(); i++) {
			if(v.at(0).at(i)>max) max=v.at(0).at(i);
		}
		red.push_back(max);
		planina.push_back(red);
	}
	
	
	for(int i=1; i<v.size(); i++) {
		for(int j=1; j<v.at(i).size(); j++ ) {
			suma=v.at(i).at(j-1)+v.at(i).at(j+1)+v.at(i+1).at(j)+v.at(i-1).at(j)+v.at(i-1).at(j-1)+v.at(i-1).at(j+1)+v.at(i+1).at(j-1)+v.at(i+1).at(j+1);
			if(v.at(i).at(j)>suma) {
				pozi=i;
				pozj=j;
				if (i-2>0 && j-2>0 && i+2<v.size() && j+2<v.size()){
                        double sumk=v.at(i-2).at(j-2)+v.at(i-2).at(j-1)+v.at(i-2).at(j)+v.at(i-2).at(j+1)+v.at(i-2).at(j+2)+v.at(i-1).at(j-2)+v.at(i-1).at(j-1)+v.at(i-1).at(j)+v.at(i-1).at(j+1)+v.at(i-1).at(j+2)+v.at(i).at(j-2)+v.at(i).at(j-1)+v.at(i).at(j)+v.at(i).at(j+1)+v.at(i).at(j+2)+v.at(i+1).at(j-2)+v.at(i+1).at(j-1)+v.at(i+1).at(j)+v.at(i+1).at(j+1)+v.at(i+1).at(j+2)+v.at(i+2).at(j-2)+v.at(i+2).at(j-1)+v.at(i+2).at(j)+v.at(i+2).at(j+1)+v.at(i+2).at(j+2);
                        if (suma<sumk){
						for	(i=pozi-1; i<=pozi+1; i++) {
							for(j=pozj-1; j<=pozj+1; j++) {
								red.push_back(v.at(i).at(j));
							}
							planina.push_back(red);
						}
			}
			
		}
	}
		
	}
}
return planina;
}

int main ()
{
	try {
	int n, m;
	
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if(n<0 || m<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice: ";
	auto mat(UnesiMatricu(m, n));
	auto nova(NajvecaPlaninaMatrice(mat));
	std::cout<<std::endl<<"Najveca planina unesene matrice je:"<<std::endl;
	IspisiMatricu(nova);
	}
	catch(std::domain_error IZUZETAK){
        std::cout<<IZUZETAK.what()<<std::endl;
    }
    return 0;
}