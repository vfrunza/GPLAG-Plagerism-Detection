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
#include <iomanip>
#include <stdexcept>
#include <vector>
typedef std::vector<std::vector<double>> Mat;

Mat NajvecaPlaninaMatrice(Mat m){
	if(m.size()>1){
		for(int i=0;i<m.size()-1;i++){
			if(m.at(i).size()!=m.at(i+1).size()) throw std::domain_error("Matrica nije korektna");
		}
	}
	Mat mat(1,std::vector<double>(1));
	
	
	if(m.size()==0 || m.at(0).size()==0) return mat;
	
	
	
	
	int x(0),y(0);
	int max(m.at(x).at(y));
	
	for(int j=0;j<m.size();j++){
		for(int k=0;k<m.at(j).size();k++){
			if(m.at(j).at(k)>max) {
				x=j;
				y=k;
			}
		}
	}
	mat.at(0).at(0)=m.at(x).at(y);
	return mat;
}

int main (){
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	int m;
	std::cin>>m;
	int n;
	std::cin>>n;
	if(m<0 || n<0) std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	else{
	std::cout<<"Unesite elemente matrice:";
	int i(0),j(0);
	Mat mat(m,std::vector<double>(n));
	while(i<m){
		j=0;
		while(j<n){
			std::cin>>mat.at(i).at(j);
			j++;
		}
		i++;
	}
	//for(auto v:mat){for(auto x:v) std::cout<<x<<" ";}
	Mat novo(NajvecaPlaninaMatrice(mat));
	std::cout<<std::endl<<"Najveca planina unesene matrice je:"<<std::endl;
	for(auto v:novo){for(auto x:v) std::cout<<" "<<std::setw(5)<<x;}
	}
	return 0;
}