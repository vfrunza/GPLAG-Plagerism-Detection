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
void IspitajMatricu(std::vector<std::vector<double> > m){
	for(int i=0; i<m.size(); i++)
		if(m[i].size() != m[0].size()) throw std::domain_error("Matrica nije korektna");
}
std::vector<std::vector<double>> HM (std::vector<std::vector<double>> m) {
		std::vector<std::vector<double>> mh;
		for(int i=0;i<m.size();i++) {
		mh.push_back(std::vector<double>());
			for(int j=m[i].size()-1;j>=0;j--) {
		   mh[i].push_back(m[i][j]);
			} 
		}
	return mh;
}
std::vector<std::vector<double>> VM (std::vector<std::vector<double>> m) {
	std::vector<std::vector<double>> vm;
	int k=0;
	for(int i=m.size()-1;i>=0;i--) {
	vm.push_back(std::vector<double>());
		for(int j=0;j<m[i].size();j++)	{
			vm[k].push_back(m[i][j]);
		}
		k++;
	} 
	return vm; 
}
std::vector<std::vector<double>> HVM (std::vector<std::vector<double>> m){
	std::vector<std::vector<double>> hvm;
	int k=0;
	for(int i=m.size()-1;i>=0;i--) {
		hvm.push_back(std::vector<double>());
		for(int j=m[i].size()-1;j>=0;j--){
			hvm[k].push_back(m[i][j]);
		}
		k++;
	}
	return hvm; 
}
std::vector<std::vector<double>> OgledaloMatrica (std::vector<std::vector<double> > m) {
	IspitajMatricu(m);
	auto vm=VM(m);
	auto hvm=HVM(m);
	std::vector<std::vector<double> > pomocna_matrica;
	for(int k=0; k<m.size(); k++){
		pomocna_matrica.push_back(std::vector<double>());
		for(int j=0; j<hvm[k].size(); j++){
			pomocna_matrica[k].push_back(hvm[k][j]);
		}
		for(int j=0; j<vm[k].size(); j++){
			pomocna_matrica[k].push_back(vm[k][j]);
		}
		for(int j=0; j<hvm[k].size(); j++){
			pomocna_matrica[k].push_back(hvm[k][j]);
		}
	}
	auto konmat=pomocna_matrica;
	for(int i=pomocna_matrica.size()-1; i>=0; i--){
		konmat.push_back(pomocna_matrica[i]);
	}
	for(int i=0; i<pomocna_matrica.size(); i++){
		konmat.push_back(pomocna_matrica[i]);
	}
 return konmat;
}
int main() {
	try{
		int m,n;
		std::cout<<"Unesite dimenzije matrice (m n): ";
		std::cin>>m>>n;
		if(m < 0 || n < 0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
		std::cout<<"Unesite elemente matrice: "<<std::endl;
		std::vector<std::vector<double>> v3 (m) ;
		for(int i=0;i<v3.size();i++) {
			for(int j=0;j<n;j++) {
				double temp;
				std::cin>> temp;
				v3[i].push_back(temp);
			}
		} 
		std::cout<<"Rezultantna matrica: "<<std::endl;
		auto rez=OgledaloMatrica(v3);
		for(int i=0; i<rez.size(); i++){
			for(int j=0; j<rez[i].size(); j++){
				std::cout<<std::setw(4)<<rez[i][j];
			}
			std::cout<<std::endl;
		}
	}
	catch(std::domain_error greska){
		std::cout<<greska.what();
	}
	return 0;
}