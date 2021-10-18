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

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> M){
	int m(M.size()), n{0}; 
	if(m > 0) n=M.at(0).size();
	std::vector<std::vector<double>> ogledalo(3*m, std::vector<double> (3*n));
	for(int i{0}; i<m; i++){
		if(M.at(i).size() != n) throw std::domain_error("Matrica nije korektna");
		for(int j{0}; j<n; j++){
			ogledalo.at(i+m).at(j+n)=M.at(i).at(j);
			ogledalo.at(i).at(j)=M.at(m-1-i).at(n-1-j);
			ogledalo.at(i+2*m).at(j+2*n)=M.at(m-1-i).at(n-1-j);
			ogledalo.at(i+2*m).at(j)=M.at(m-1-i).at(n-1-j);
			ogledalo.at(i).at(j+2*n)=M.at(m-1-i).at(n-1-j);
			ogledalo.at(i).at(j+n)=M.at(m-1-i).at(j);
			ogledalo.at(i+2*m).at(j+n)=M.at(m-1-i).at(j);
			ogledalo.at(i+m).at(j)=M.at(i).at(n-1-j);
			ogledalo.at(i+m).at(j+2*n)=M.at(i).at(n-1-j);
		}
	}
	return ogledalo;
}

int main ()
{
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m<0 || n<0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout << "Unesite elemente matrice: ";
	std::vector<std::vector<double>> Matrica(m, std::vector<double> (n));

	for(int i{0}; i<m; i++){
	   for(int j{0}; j<n; j++){
	   	double x;
	   	std::cin >> x;
	   	if(!std::cin){
	   		std::cout << "Element nije korektan!";
	   		return 0;
	   	}
	   	Matrica.at(i).at(j) = x;
	   }
	}
	try{
		std::cout << std::endl << "Rezultantna matrica: ";
      	for(std::vector<double> i:OgledaloMatrica(Matrica)){
	    	std::cout << std::endl;
	    	for(int j:i) std::cout << std::setw(4) << j;
    	}
	}
	catch(std::domain_error izuzetak){
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}