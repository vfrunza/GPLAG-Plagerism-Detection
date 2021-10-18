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
typedef std::vector<std::vector<double>> matrica;

	matrica OgledaloMatrica(matrica M){
		if(M.size()==0) return M;
			bool isti(true);
			for(int i=0; i<M.size(); i++){
				if(i<M.size()-1){
					if(M[0].size() != M[i+1].size()){
					isti = false;
					break;
					}
				}
			}
		if(!isti) throw std::domain_error("Matrica nije korektna");
		matrica hM;
		hM.resize(M.size());
		matrica vM;
		vM.resize(M.size());
		matrica hvM;
		hvM.resize(M.size());
		
		
		for(int i=0; i<hM.size(); i++){
			hM[i].resize(M[0].size());
			vM[i].resize(M[0].size());
			hvM[i].resize(M[0].size());
		}
		int k(0);
		for(int i=0; i<hM.size(); i++){
			int l(M[0].size()-1);
			for(int j=0; j<hM[0].size(); j++){
				hM[i][j] = M[k][l];
				l--;
			}
			k++;
		}
		
		 k = vM.size()-1;
		for(int i=0; i<vM.size(); i++){
			int l(0);
			for(int j=0; j<vM[0].size(); j++){
				vM[i][j] = M[k][l];
				l++;
			}
			k--;
		}
		
		k = hvM.size()-1;
		for(int i=0; i<hvM.size(); i++){
			int l(M[0].size()-1);
			for(int j=0; j<hvM[0].size(); j++){
				hvM[i][j] = M[k][l];
				l--;
			}
			k--;
		}
		matrica ogledalo(3*M.size(),std::vector<double>(3*M[0].size()));
		int m(M.size());
		int n(M[0].size());
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				ogledalo[i][j] = hvM[i][j];
				ogledalo[i][j+n] = vM[i][j];
				ogledalo[i][j+2*n] = hvM[i][j];
				ogledalo[i+m][j] = hM[i][j];
				ogledalo[i+m][j+n] = M[i][j];
				ogledalo[i+m][j+2*n] = hM[i][j];
				ogledalo[i+2*m][j] = hvM[i][j];
				ogledalo[i+2*m][j+n] = vM[i][j];
				ogledalo[i+2*m][j+2*n] = hvM[i][j];
			}
			
		}
		return ogledalo;
	}

int main (){
	try{
		int m,n;
		std::cout<< "Unesite dimenzije matrice (m n): ";
		std::cin>>m>>n;
		if(m<0 or n<0){
			std::cout<< "Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
	
		matrica matra(m, std::vector<double>(n));
		std::cout<< "Unesite elemente matrice: ";
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				std::cin>>matra[i][j];
			}
		}
		 	auto p = OgledaloMatrica(matra);
		 	std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
		 	for(int i=0; i<p.size(); i++) {
		 	 for(int j=0; j<p[0].size(); j++)
				 std::cout << std::setw(4) << p[i][j];
				 std::cout << std::endl;
			 }
	}
							
	catch(std::domain_error izuzetak){
		std::cout << izuzetak.what();
	}

	return 0;
}