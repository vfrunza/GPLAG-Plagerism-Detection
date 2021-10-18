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

matrica v (matrica m) {
	for(int i=0; i<m.size()/2; i++) {
		std::vector<double> t (std::move(m[i]));
		m[i]=std::move(m[m.size()-1-i]);
		m[m.size()-1-i]=std::move(t);
	}
	return m;
}

matrica h (matrica m) {
	int br_redova(m.size());
	int br_kolona(m[0].size());
	for(int i=0; i<br_kolona/2; i++) {
		for(int j=0; j<br_redova; j++) {
			double t (m[j][i]);
			m[j][i]=m[j][br_kolona-1-i];
			m[j][br_kolona-1-i]=t;
		}
	}
	return m;
}

matrica hv (matrica m) {
	return h(v(m));
}

matrica OgledaloMatrica (matrica m) {
	if(m.size() != 0) {
	for(int i=0; i<m.size()-1; i++)
		if(m[i].size() != m[i+1].size())
			throw std::domain_error("Matrica nije korektna");
	}
	matrica mat;
	for(int i=0; i<m.size(); i++) {
		std::vector<double>	tmp;
		matrica mtmp(hv(m));
		for(int j=0; j<m[i].size(); j++)
			tmp.push_back(mtmp[i][j]);
		mtmp=v(m);
		for(int j=0; j<m[i].size(); j++)
			tmp.push_back(mtmp[i][j]);
		mtmp=hv(m);
		for(int j=0; j<m[i].size(); j++)
			tmp.push_back(mtmp[i][j]);
		
		mat.push_back(tmp);
	}
	
	for(int i=0; i<m.size(); i++) {
		std::vector<double> tmp;
		matrica mtmp(h(m));
		for(int j=0; j<m[i].size(); j++)
			tmp.push_back(mtmp[i][j]);
		for(int j=0; j<m[i].size(); j++)
			tmp.push_back(m[i][j]);
		mtmp=h(m);
		for(int j=0; j<m[i].size(); j++)
			tmp.push_back(mtmp[i][j]);
			
		mat.push_back(tmp);
	}
	
	for(int i=0; i<m.size(); i++) {
		std::vector<double> tmp;
		matrica mtmp(hv(m));
		for(int j=0; j<m[i].size(); j++)
			tmp.push_back(mtmp[i][j]);
		mtmp=v(m);
		for(int j=0; j<m[i].size(); j++)
			tmp.push_back(mtmp[i][j]);
		mtmp=hv(m);
		for(int j=0; j<m[i].size(); j++)
			tmp.push_back(mtmp[i][j]);
			
		mat.push_back(tmp);
	}
	return mat;
}

int main ()
{
	try{
		std::cout<<"Unesite dimenzije matrice (m n): ";
		int m, n;
		std::cin>>m>>n;
		if(m < 0 || n < 0) {
			std::cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 1;	
		}
		matrica mat(m, std::vector<double>(n));
		std::cout<<"Unesite elemente matrice: "<<std::endl;
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				std::cin>>mat[i][j];
				
		matrica mat2 = OgledaloMatrica(mat);
		std::cout<<"Rezultantna matrica: "<<std::endl;
		for(int i=0; i<mat2.size(); i++) {
			for(int j=0; j<mat2[i].size(); j++)
				std::cout<<std::setw(4)<<mat2[i][j];
			std::cout<<std::endl;
		}
	}
	catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what();
	}
	return 0;
}