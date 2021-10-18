/*B 2016/2017, Zadaća 1, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica UnesiMatricu(int br_redova, int br_kolona) {
	Matrica mat; 
	if(br_redova==0) return mat;
	mat.resize(br_redova);
	for(int i(0);i<br_redova;i++)
		mat.at(i).resize(br_kolona);

	for(int i(0);i<br_redova;i++) {
		for(int j(0);j<br_kolona;j++) {
			std::cin>>mat.at(i).at(j);
		}
	}
	return mat;
}

void IspisiMatricu(Matrica m) {
	for(int i(0);i<m.size();i++) {
		for(int j(0);j<m.at(0).size();j++) {
			std::cout<<std::setw(4)<<m.at(i).at(j);
		}
		std::cout<<std::endl;
	}
}

Matrica OgledaloMatrica (Matrica m)
{
	
	Matrica ogledalo;
	if(m.size()==0) return ogledalo;
	ogledalo.resize(3*m.size());
	for(int i(0);i<ogledalo.size();i++) 
		ogledalo.at(i).resize(3*m.at(0).size());
		
	Matrica hv(m.size(), std::vector<double>(m.at(0).size()));
	Matrica h(m.size(), std::vector<double>(m.at(0).size()));
	Matrica v(m.size(), std::vector<double>(m.at(0).size()));

	int x(m.size()), y(m.at(0).size());
	
	for(int i(0);i<x;i++) {
		for(int j(0);j<x;j++) {
			if(m.at(i).size()!=m.at(j).size()) 
				throw std::domain_error("Matrica nije korektna.");
		}
	}

	for(int i(0); i<x; i++) {
		for(int j(0); j<y; j++) {
			v.at(i).at(j)=m.at(x-1-i).at(j);
			h.at(i).at(j)=m.at(i).at(y-1-j);
		}
	}

	for(int i(0); i<x; i++) {
		for(int j(0); j<y; j++) {
			hv.at(i).at(j)=h.at(x-1-i).at(j);
		}
	}

	for(int i(0); i<3*x; i++) {
		for(int j(0); j<3*y; j++) {

			if(j<y) {
				if(i<x) ogledalo.at(i).at(j)=hv.at(i).at(j);
				else if(i>=x && i<2*x) ogledalo.at(i).at(j)=h.at(i-x).at(j);
				else ogledalo.at(i).at(j)=hv.at(i-2*x).at(j);
			}

			else if(j>=y && j<2*y) {
				if(i<x) ogledalo.at(i).at(j)=v.at(i).at(j-y);
				else if(i>=x && i<2*x) ogledalo.at(i).at(j)=m.at(i-x).at(j-y);
				else ogledalo.at(i).at(j)=v.at(i-2*x).at(j-y);

			} else {
				if(i<x) ogledalo.at(i).at(j)=hv.at(i).at(j-2*y);
				else if(i>=x && i<2*x) ogledalo.at(i).at(j)=h.at(i-x).at(j-2*y);
				else ogledalo.at(i).at(j)=hv.at(i-2*x).at(j-2*y);
			}
		}
	}
	return ogledalo;
}

int main ()
{
	int m, n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
    Matrica mat, rez;
	std::cout<<"Unesite elemente matrice: ";
	try {
		 mat=UnesiMatricu(m,n);
		 rez=OgledaloMatrica(mat); 
	}
	catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
	
	std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
	IspisiMatricu(rez);

	return 0;
}