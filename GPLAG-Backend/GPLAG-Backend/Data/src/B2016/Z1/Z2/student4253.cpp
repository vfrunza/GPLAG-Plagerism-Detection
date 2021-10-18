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

Matrica Dopuni(Matrica ogledalo, Matrica mat, int no, int nm){
	
	for(int j(0); j<int(mat.at(nm).size()); j++){
		ogledalo.at(no).push_back(mat[nm][j]);
	}
	
	return ogledalo;
}

void IspisiMatricu(Matrica mat){
	std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
	for(auto red: mat){
		for(auto x: red) std::cout<<std::setw(4)<<x;
		std::cout<<std::endl;
	}
}

Matrica OgledaloMatrica (Matrica mat){
	
	if(int(mat.size())==0) return mat;
	
	int n(int(mat.at(0).size())), vel(int(mat.size()));
	for(int i(1); i<vel; i++){
		if(int(mat.at(i).size())!=n) throw std::domain_error ("Matrica nije korektna");
	}
	
	Matrica h(vel);
	for(int i(0); i<vel; i++){
		for(int j(n-1) ; j>=0; j--){
			h.at(i).push_back(mat.at(i).at(j));
		}
	}
	
	Matrica v(vel);
	for(int i(vel-1), j(0); i>=0; i--, j++){
		for(int k(0); k<int(mat.at(i).size()); k++) v.at(j).push_back(mat.at(i).at(k));
	}
	
	Matrica hv(vel);
	for(int i(int(h.size())-1), j(0); i>=0; i--, j++){
		for(int k(0); k<int(h.at(i).size()); k++) hv.at(j).push_back(h.at(i).at(k));
	}

	
	Matrica ogledalo(3*vel);
	for(int i(0); i<3*vel; i++){
		if(i<vel){
			ogledalo=Dopuni(ogledalo, hv, i, i);
			ogledalo=Dopuni(ogledalo, v, i, i);
			ogledalo=Dopuni(ogledalo, hv, i, i);
		}
		if(i<2*vel && i>=vel){
			ogledalo=Dopuni(ogledalo, h, i, i-vel);
			ogledalo=Dopuni(ogledalo, mat, i, i-vel);
			ogledalo=Dopuni(ogledalo, h, i, i-vel);
		}
		if(i>=2*vel){
			ogledalo=Dopuni(ogledalo, hv, i, i-2*vel);
			ogledalo=Dopuni(ogledalo, v, i, i-2*vel);
			ogledalo=Dopuni(ogledalo, hv, i, i-2*vel);
		}
	}
	
	return ogledalo;
	
}

int main ()
{	try{
		int m, n;
		std::cout<<"Unesite dimenzije matrice (m n): ";
		std::cin>>m>>n;
		if(m<0 || n<0) throw "Dimenzije matrice moraju biti nenegativne!";
	
		Matrica mat(m,std::vector<double> (n));
		std::cout<<"Unesite elemente matrice: ";
	
		for(int i(0); i<m; i++){
			for(int j(0); j<n; j++){
			
				std::cin>>mat.at(i).at(j);
			}
		}
	
		try{
			Matrica ogledalo(OgledaloMatrica(mat));
		
			IspisiMatricu(ogledalo);
		
		}
		catch(std::domain_error izuzetak){
			std::cout<<izuzetak.what()<<std::endl;
		}
	}
	catch (const char poruka[]){
		std::cout<<poruka;
	}
	
	return 0;
}