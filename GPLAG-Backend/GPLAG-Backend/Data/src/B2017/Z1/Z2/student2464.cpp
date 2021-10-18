#include <stdexcept>
#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int m, int n)
{
	return Matrica(m, std::vector<double>(n));
}

Matrica UnesiMatricu (int m, int n)
{
	Matrica mm(KreirajMatricu(m, n));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			std::cin >> mm.at(i).at(j);
		}
	}
	return mm;
}

Matrica NajvecaPlaninaMatrice(Matrica m)
{
	std::vector<double> pomocni_v;
	Matrica pomocna_matrica;
	
	if(m.size()==0 || m.at(0).size()==0) return pomocna_matrica;

	for(int i=0; i<int(m.size()-1); i++) {
		for(int j=i; j<m.size(); j++) {
			if (m[i].size()!=m[j].size()) throw std::domain_error("Matrica nije korektna");
		}
	}
    


	if(m.size()<=3 || m.at(0).size()<=3 ) {
		double maxi=m.at(0).at(0);
		for(int i=0; i<m.size(); i++) {
			for(int j=0; j<m.at(0).size(); j++) {
				if (m.at(i).at(j)>maxi) maxi=m.at(i).at(j);
			}
		}
		
		pomocni_v.push_back(maxi);
		pomocna_matrica.push_back(pomocni_v);
		
	}
	return pomocna_matrica;
}


int main ()
{
	try {
		int m, n;
		std::cout<<"Unesite dimenzije matrice (m i n):";
		std::cin>>m>>n;
		if(m<0 || n<0) {
			std::cout<<" Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		std::cout<<" Unesite elemente matrice: ";
		Matrica M(UnesiMatricu(m,n));

		std::cout<<std::endl<<"Najveca planina unesene matrice je:"<<std::endl;
		Matrica Nova(NajvecaPlaninaMatrice(M));
		for(int i=0; i<Nova.size(); i++) {
			for(int j=0; j<Nova.at(0).size(); j++) {
				std::cout<<std::right<<std::setw(6)<<Nova.at(i).at(j);
			}
			std::cout<<std::endl;
		}
	}

	catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}

	return 0;
}