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

Matrica KreirajMatricu(int broj_redova, int broj_kolona)
{
	return Matrica(broj_redova, std::vector<double> (broj_kolona));
}

Matrica HM(Matrica M)
{
	Matrica hm(KreirajMatricu(M.size(), M[0].size()));
	for(int i=0; i<hm.size(); i++) {
		for(int j=0; j<hm[0].size(); j++) {
			for(int k=M[0].size()-1-j; k>=0; k--) {
				hm[i][k]=M[i][j];
			}
		}

		
	}
	return hm;
}
Matrica VM(Matrica M)
{
	Matrica vm(KreirajMatricu(M.size(), M[0].size()));
	for(int i=0; i<M.size(); i++) {
		vm[i]=M[M.size()-1-i];
	}
	
	return vm;
}
Matrica HVM(Matrica M){
	return VM(HM(M));
}

Matrica OgledaloMatrica(Matrica M)
{
	if(M.size()==0){
		return KreirajMatricu(0,0);
	}
	for(int i=1; i<M.size(); i++) {
		if(M[i].size()!=M[0].size()) {
			throw std::domain_error("Matrica nije korektna");
		}
	}

	Matrica hvm(HVM(M));
	Matrica hm(HM(M));
	Matrica vm(VM(M));
	
	Matrica OM(KreirajMatricu(3*M.size(), 3*M[0].size()));
	for(int i=0; i<M.size(); i++) {
		for(int j=0; j<M[0].size(); j++) {
			OM[i][j]=hvm[i][j];
		}
	}
	for(int i=0; i<vm.size(); i++) {
		for(int j=0; j<vm[0].size(); j++) {
			OM[i+M.size()][j+M[0].size()]=M[i][j];
		}
	}
	for(int i=0; i<vm.size(); i++) {
		for(int j=0; j<vm[0].size(); j++) {
			OM[i][j+M[0].size()]=vm[i][j];
		}
	}
	for(int i=0; i<vm.size(); i++) {
		for(int j=0; j<vm[0].size(); j++) {
			OM[i][j+2*M[0].size()]=hvm[i][j];
		}
	}
	for(int i=0; i<vm.size(); i++) {
		for(int j=0; j<vm[0].size(); j++) {
			OM[i+M.size()][j+2*M[0].size()]=hm[i][j];
		}
	}
	for(int i=0; i<vm.size(); i++) {
		for(int j=0; j<vm[0].size(); j++) {
			OM[i+2*M.size()][j+2*M[0].size()]=hvm[i][j];
		}
	}
	for(int i=0; i<vm.size(); i++) {
		for(int j=0; j<vm[0].size(); j++) {
			OM[i+2*M.size()][j+M[0].size()]=vm[i][j];
		}
	}
	for(int i=0; i<vm.size(); i++) {
		for(int j=0; j<vm[0].size(); j++) {
			OM[i+2*M.size()][j]=hvm[i][j];
		}
	}
	for(int i=0; i<vm.size(); i++) {
		for(int j=0; j<vm[0].size(); j++) {
			OM[i+M.size()][j]=hm[i][j];
		}
	}


	return OM;

}

int main ()
{
	int m, n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	std::cout<<"Unesite elemente matrice: ";
	try {
		Matrica M(KreirajMatricu(m,n));
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				std::cin>>M[i][j];
			}
		}
		std::cout<<std::endl;
		std::cout<<"Rezultantna matrica: "<<std::endl;
		
		Matrica OM(OgledaloMatrica(M));
		for(int i=0; i<OM.size(); i++) {
			for(int j=0; j<OM[0].size(); j++) {
				std::cout<<std::setw(4)<<OM[i][j];
			}
			std::cout<<std::endl;
		}
	} catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}