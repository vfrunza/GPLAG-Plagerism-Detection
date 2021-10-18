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

typedef std::vector<std::vector<double>> Matrica;

Matrica OgledaloMatrica(Matrica m) {
	int grbava(0);
for(int i(0); i<m.size();i++) {
	if(m[0].size()!=m[i].size()) grbava=1;
}
if(grbava==1) throw std::domain_error("Matrica nije korektna");

	if(m.size()==0) return m; 
	Matrica hm(m.size(),std::vector<double>(m[0].size())), vm(m.size(),std::vector<double>(m[0].size())),
	hvm(m.size(),std::vector<double>(m[0].size()));
	int s(m.size()-1);
	for(int i(0);i<m.size();i++) {
		int k(m[0].size()-1);
		
		for(int j(0); j<m[0].size();j++) {
			hm[i][j]=m[i][k];
			vm[i][j]=m[s][j];
			k--;
		}
		s--;
	}
	
	for(int i(0); i<m.size();i++) {
		int k=m[0].size()-1;
		for(int j(0); j<m[0].size(); j++) {
			hvm[i][j]=vm[i][k];
			k--;
		}
	}
	
	Matrica nova(3*m.size());
	int i(0);
	for(int j(0); j<m.size();j++)
		{
			for(int k(0); k<m[0].size();k++) nova[i].push_back(hvm[j][k]);

			for(int k(0); k<m[0].size();k++) nova[i].push_back(vm[j][k]);
			
			for(int k(0); k<m[0].size();k++) nova[i].push_back(hvm[j][k]);
			
			i++;
		}
		
			for(int s(0); s<m.size();s++)
		{
			for(int k(0); k<m[0].size();k++) nova[i].push_back(hm[s][k]);
			
			for(int k(0); k<m[0].size();k++) nova[i].push_back(m[s][k]);
			
			for(int k(0); k<m[0].size();k++) nova[i].push_back(hm[s][k]);
			
			i++;
		}
		
			for(int h(0); h<m.size();h++)
		{
			for(int k(0); k<m[0].size();k++) nova[i].push_back(hvm[h][k]);
			
			for(int k(0); k<m[0].size();k++) nova[i].push_back(vm[h][k]);
			
			for(int k(0); k<m[0].size();k++) nova[i].push_back(hvm[h][k]);
			
			i++;
		}

	
	return nova;
}

int main ()
{
	
	Matrica nova;
	int m,n;
	try {
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica mat(m,std::vector<double>(n));
		std::cout<<"Unesite elemente matrice: ";
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
		
			std::cin>>mat[i][j];
		}
	}
	std::cout<<std::endl;
	std::cout<<"Rezultantna matrica: "<<std::endl;
	nova=OgledaloMatrica(mat);
	for(int i(0); i<nova.size();i++) {
		for(int j(0); j<nova[0].size(); j++) {
			std::cout<<std::right<<std::setw(4)<<nova[i][j];
		}
		std::cout<<std::endl;
	}
	}
	catch(std::domain_error greska){
		std::cout<< greska.what() << std::endl;
		
	}
	return 0;
}