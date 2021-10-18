#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica horizontalnaMatrica(Matrica m) {
	Matrica hm(m.size(), std::vector<double> (m[0].size()));
	int d=m.size();
	int s=m[0].size();
	
	for(int i=0; i<d; i++) {
		for(int j=0; j<s; j++) {
			hm[i][j]=m[i][s-1-j];
			}
	}
	return hm;
}

Matrica vertikalnaMatrica(Matrica m) {
	Matrica vm(m.size(), std::vector<double> (m[0].size()));
	int d=m.size()-1;
	int s=m[0].size();
	for(int i=d; i>=0; i--) {
		for(int j=0; j<s; j++) {
			vm[d-i][j]=m[i][j];
		}
	}
	return vm;
}

Matrica kombinovanoOgledalo(Matrica m) {
	Matrica hvm(m.size(), std::vector<double> (m[0].size()));
	int d=m.size()-1;
	int s=m[0].size()-1;
	for(int i=d; i>=0; i--) {
		for(int j=s; j>=0; j--) {
			hvm[d-i][s-j]=m[i][j];
		}
	}
	return hvm;
}

Matrica OgledaloMatrica(Matrica mat) {
	
	if(mat.size()==0 || mat[0].size()==0) {
		Matrica ogledalo(mat.size()*3, std::vector<double> (0));
		return ogledalo;
	}
	
	
	for(int i=0; i<mat.size(); i++) 
		if(mat[i].size()!=mat[0].size()) throw std::domain_error("Matrica nije korektna");
	
	Matrica hm = horizontalnaMatrica(mat);
	Matrica vm = vertikalnaMatrica(mat);
	Matrica hvm = kombinovanoOgledalo(mat);
		
	int red=mat.size();
	int kolona=mat[0].size();
		
	Matrica ogledalo(red*3, std::vector<double> (kolona*3));
	
	for(int i=0; i<3*red; i++) {
		for(int j=0; j<3*kolona; j++) {
			if(i<red && j<kolona) ogledalo[i][j]=hvm[i][j]; //hvm
			else if(i<red && j>=2*kolona) ogledalo[i][j]=hvm[i][j-2*kolona]; //hvm
			else if(i>=2*red && j<kolona) ogledalo[i][j]=hvm[i-2*red][j]; //hvm
			else if(i>=2*red && j>=2*kolona) ogledalo[i][j]=hvm[i-2*red][j-2*kolona];	//hvm
			
			
			else if(i>=red && j<kolona) ogledalo[i][j]=hm[i-red][j]; //hm
			else if(i>=red && j>=2*kolona) ogledalo[i][j]=hm[i-red][j-2*kolona]; //hm
			
			else if(i<red && j>=kolona) ogledalo[i][j]=vm[i][j-kolona]; //vm
			else if(i>=2*red && j>=kolona) ogledalo[i][j]=vm[i-2*red][j-kolona]; //vm
				
			else ogledalo[i][j]=mat[i-red][j-kolona]; //M
			
		}
	}
	
	return ogledalo;
}
int main ()
{
	std::cout << "Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin >> m >> n;
	
	if(m<0 || n<0)  {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	while(!std::cin || std::cin.peek()!='\n') {
		std::cout << "Unesite dimenzije matrice (m n): " << std::endl;
		std::cin.clear();
		std::cin.ignore(1000000, '\n');
		std::cin >> m >> n;
	}
	/*try {
		Matrica mat(m, std::vector<double> (n));
		if(m==0 || n==0) Matrica ogledalo(mat);
	}
	catch(...) {}
*/

	Matrica mat(m, std::vector<double> (n));
	

		std::cout << "Unesite elemente matrice: " << std::endl;

		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				std::cin >> mat[i][j];
			}
		}
	
	try {
		Matrica ogledalo(OgledaloMatrica(mat));
		
		std::cout << "Rezultantna matrica: " << std::endl;
		for(int i=0; i<ogledalo.size(); i++) {
			for(int j=0; j<ogledalo[0].size(); j++) {
				std::cout << std::setw(4) << ogledalo[i][j];
			}
			std::cout << std::endl;
		}
	}
	catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
} 
