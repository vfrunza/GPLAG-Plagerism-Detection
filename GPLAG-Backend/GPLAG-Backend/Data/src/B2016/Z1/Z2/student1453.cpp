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

Matrica vertikalna(Matrica m){
	for(int i=0;i<m.size()/2;i++){
		std::vector<double> privremeni;
		privremeni=std::move(m[i]);
		m[i]=std::move(m[m.size()-1-i]);
		m[m.size()-1-i]=std::move(privremeni);
	}
	return m;
}

Matrica horizontalna(Matrica m){
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size()/2;j++){
			double privremeni(m[i][j]);
			m[i][j]=m[i][m[0].size()-j-1];
			m[i][m[0].size()-1-j]=privremeni;
		}
	}

	return m;
}
bool provjera(Matrica m){
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			if(!std::cin) return false;
		}
	}
	return true;
}
bool korektna(Matrica m){
	for(int i=1;i<m.size();i++)
		if(m[i].size()!=m[0].size()) return false;
	return true;
	
}
Matrica OgledaloMatrica(Matrica m){
	if(m.size()==0) return m;
	if(provjera(m)==false || korektna(m)==false) throw std::domain_error("Matrica nije korektna");
	
	Matrica hv(horizontalna(vertikalna(m)));
	Matrica v(vertikalna(m));
	Matrica h(horizontalna(m));
	Matrica glavna(3*m.size(),std::vector<double>(3*m[0].size()));
	for(int i=0;i<hv.size();i++){
		for(int j=0;j<hv[0].size();j++){
			glavna[i][j]=hv[i][j];
			glavna[i+2*hv.size()][j]=hv[i][j];
			glavna[i][j+hv[0].size()*2]=hv[i][j];
			glavna[i+2*hv.size()][j+hv[0].size()*2]=hv[i][j];
			glavna[i][j+v[0].size()]=v[i][j];
			glavna[i+v.size()*2][j+v[0].size()]=v[i][j];
			glavna[i+h.size()][j]=h[i][j];
			glavna[i+h.size()][j+2*h[0].size()]=h[i][j];
			glavna[i+m.size()][j+m[0].size()]=m[i][j];
		}
	}
	return glavna;
}

int main (){
	
	int redova, kolona;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> redova>>kolona;
	if(redova<0 || kolona<0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!" ;
		return 0;
	}
	Matrica m(redova,std::vector<double>(kolona));
	std::cout << "Unesite elemente matrice: ";
	for(int i=0;i<redova;i++){
		for(int j=0;j<kolona;j++)
			std::cin >> m[i][j];
	}
	
	try{
		m=OgledaloMatrica(m);
	
	
		std::cout << "\nRezultantna matrica:" << std::endl;
		for(int i=0;i<m.size();i++){
			for(int j=0;j<m[0].size();j++)
				std::cout <<std::setw(4)<< m[i][j];
			std::cout<<std::endl;
			
		}
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	return 0;
}