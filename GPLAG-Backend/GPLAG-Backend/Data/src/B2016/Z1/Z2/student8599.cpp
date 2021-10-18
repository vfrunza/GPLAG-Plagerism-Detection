//B 2016/2017, Zadaća 1, Zadatak 2
	

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

void IspisiMatricu(Matrica m) {
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size(); j++)
		std::cout << std::setw(4) << m[i][j];
		std::cout << std::endl;
	}
}

Matrica Horizontalna(Matrica x){
	for(int i=0; i<x.size(); i++){
		for(int j=0; j<(x[i].size())/2; j++){
			double temp(x[i][j]);
			x[i][j]=x[i][x[i].size()-1-j];
			x[i][x[i].size()-1-j]=temp;
		}
	}
	return x;
}

Matrica Vertikalna(Matrica x){
for(int i=0; i<(x.size())/2; i++){
		for(int j=0; j<x[i].size(); j++){
			double temp(x[i][j]);
			x[i][j]=x[x.size()-1-i][j];
			x[x.size()-1-i][j]=temp;
		}
}
		return x;
}

Matrica Kombinovana(Matrica x){
	x=Horizontalna(x);
	x=Vertikalna(x);
	return x;
}
Matrica	OgledaloMatrica(Matrica a) {
	for(int i=1; i<a.size(); i++){
		if(a[i].size()!=a[0].size()){
		throw std::domain_error("Matrica nije korektna");
		break;
		}
	}
	int br_redova(3*a.size());
//velicina kolone nula kad je sta se radi?	
	int br_kolona;
	if(a.size()==0)
	br_kolona=0;
	else br_kolona=3*a[0].size();
	Matrica Nova(br_redova, std::vector<double>(br_kolona));
	Matrica x(a), hor(Horizontalna(a)), ver(Vertikalna(a)), komb(Kombinovana(a));
	
	for(int i=0; i<br_redova; i++){
		for(int j=0; j<br_kolona; j++){
			if(i<br_redova/3 && j<br_kolona/3)
				Nova[i][j]=komb[i][j];
			else if(i<br_redova/3 && (j>=br_kolona/3 && j<br_kolona*2/3))
				Nova[i][j]=ver[i][j-br_kolona/3];
			else if(i<br_redova/3 && j>=br_kolona*2/3)
				Nova[i][j]=komb[i][j-br_kolona*2/3];
			else if((i>=br_redova/3 && i<br_redova*2/3) && j<br_kolona/3)
				Nova[i][j]=hor[i-br_redova/3][j];
			else if((i>=br_redova/3 && i<br_redova*2/3) && (j>=br_kolona/3 && j<br_kolona*2/3))
				Nova[i][j]=a[i-br_redova/3][j-br_kolona/3];
			else if((i>=br_redova/3 && i<br_redova*2/3) && j>=br_kolona*2/3)
				Nova[i][j]=hor[i-br_redova/3][j-br_kolona*2/3];
			else if(i>=br_redova*2/3 && j<br_kolona/3)
				Nova[i][j]=komb[i-br_redova*2/3][j];
			else if(i>=br_redova*2/3 && (j>=br_kolona/3 && j<br_kolona*2/3))
				Nova[i][j]=ver[i-br_redova*2/3][j-br_kolona/3];
			else if(i>=br_redova*2/3 && j>=br_kolona*2/3)
				Nova[i][j]=komb[i-br_redova*2/3][j-br_kolona*2/3];
			}
		}
		return Nova;
	}

int main ()
{ 
		int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	try{

	std::cin >> m >> n;
	if(m<0 || n<0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
}
catch(std::domain_error izuzetak){
	std::cout << izuzetak.what();
	return 0;
}
	Matrica a(m, std::vector<double>(n));
	std::cout << "Unesite elemente matrice: ";
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			std::cin >> a[i][j];
		}
	}
	
	try{
	a=OgledaloMatrica(a);
	std::cout << std::endl << "Rezultantna matrica:" << std::endl;
	IspisiMatricu(a);
}
	catch(std::domain_error izuzetak){
		std::cout << izuzetak.what();
	}
	return 0;
}