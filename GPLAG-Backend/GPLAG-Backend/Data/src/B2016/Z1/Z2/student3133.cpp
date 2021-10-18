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

matrica Horizontalno(matrica m){
	matrica h(m.size(),std::vector<double>(m[0].size()));
	for(int i=0; i<h.size(); i++){
		for(int j=0; j<h[i].size(); j++){
			h[i][j]=m[i][m[i].size()-1-j];
		}
	}
	return h;
}

matrica Vertikalno(matrica m){
	matrica v(m.size(), std::vector<double>(m[0].size()));
	for(int j=0; j<v.size(); j++){
		for(int i=0; i<v[j].size(); i++){
			v[j][i]=m[m.size()-1-j][i];
		}
	}
	return v;
}

matrica Kombinacija(matrica m){
	matrica hv(m.size(), std::vector<double>(m[0].size()));
	hv=Horizontalno(m);
	hv=Vertikalno(hv);
	return hv;
}

matrica OgledaloMatrica(matrica m){
	if(m.size()==0) return m;
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m.size(); j++){
			if(m[i].size()!=m[j].size()) throw std::domain_error("Matrica nije korektna");
		}
	}
	matrica ogledalo(3*m.size(), std::vector<double>(3*m[0].size()));
	matrica h=Horizontalno(m);
	matrica v=Vertikalno(m);
	matrica hv=Kombinacija(m);
	for(int i=0; i<ogledalo.size(); i++){
		for(int j=0; j<ogledalo[i].size(); j++){
			if(i<m.size()&&j<m[0].size()) ogledalo[i][j]=hv[i][j];
			else if(i<m.size()&&j>=m[0].size()&&j<m[0].size()*2) ogledalo[i][j]=v[i][j-m[0].size()];
			else if(i<m.size()&&j>=m[0].size()*2) ogledalo[i][j]=hv[i][j-m[0].size()*2];
			else if(i<m.size()*2&&i>=m.size()&&j<m[0].size()) ogledalo[i][j]=h[i-m.size()][j];
			else if(i<m.size()*2&&i>=m.size()&&j>=m[0].size()&&j<m[0].size()*2) ogledalo[i][j]=m[i-m.size()][j-m[0].size()];
			else if(i<m.size()*2&&i>=m.size()&&j>=m[0].size()*2) ogledalo[i][j]=h[i-m.size()][j-m[0].size()*2];
			else if(i<m.size()*3&&i>=m.size()*2&&j<m[0].size()) ogledalo[i][j]=hv[i-m.size()*2][j];
			else if(i<m.size()*3&&i>=m.size()*2&&j>=m[0].size()&&j<m[0].size()*2) ogledalo[i][j]=v[i-m.size()*2][j-m[0].size()];
			else ogledalo[i][j]=hv[i-m.size()*2][j-m[0].size()*2];
		}
	}
	return ogledalo;
}

int main ()
{
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m, n;
	std::cin>>m>>n;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	matrica c(m, std::vector<double>(n));
	std::cout<<"Unesite elemente matrice:";
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			std::cin>>c[i][j];
		}
	}
	try{
	c=OgledaloMatrica(c);
	std::cout<<std::endl<<"Rezultantna matrica:"<<std::endl;
	for(std::vector<double> red: c){
		for(double x: red) std::cout<<std::right<<std::setw(4)<<x;
		std::cout<<std::endl;
	}
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	return 0;
}