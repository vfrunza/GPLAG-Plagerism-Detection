#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> matrica;

matrica KreirajMatricu(int broj_redova, int broj_kolona) {
 return matrica(broj_redova, std::vector<double>(broj_kolona));
}

matrica UnesiMatricu(int broj_redova, int broj_kolona, matrica m) {
    for(int i = 0; i < broj_redova; i++)
        for(int j = 0; j < broj_kolona; j++){
            std::cin >> m[i][j];
    }
    return m;
}
int BrojRedova (matrica m){
	return m.size();
}
int BrojKolona (matrica m){
	return m[0].size();
}
void IspisiMatricu(matrica m) {
    for(int i = 0; i < BrojRedova(m); i++) {
        for(int j = 0; j < BrojKolona(m); j++)
            std::cout << std::setw(4) << m[i][j];
        std::cout << std::endl;
    }
}

matrica v(matrica m){
	double zamjena;
	for(int i = 0; i<m.size()/2;++i){
		for(int j=0; j<m[0].size(); ++j){
			zamjena = m[i][j];
			m[i][j] = m[m.size()-1-i][j];
			m[m.size()-1-i][j] = zamjena;
		}
	}
return m;
}
matrica h (matrica m){
	double zamjena1;
	for(int i = 0; i<m[0].size()/2;++i){
		for(int j = 0; j<m.size(); ++j){
			zamjena1 = m[j][i];
			m[j][i] = m[j][m[0].size()-1-i];
			m[j][m[0].size()-1-i] = zamjena1;
		}
	}
return m;
}
matrica hv(matrica m){
	matrica khor, vracam;
	khor = h(m);
	vracam = v(khor);

return vracam;
}

//KONACNO
matrica OgledaloMatrica(matrica m){
	if(m.size()==0) return m;
	matrica konacna, hor, ver, horver;
	
	konacna.resize(3*m.size());
	for(int i=0; i<konacna.size(); ++i)
		konacna[i].resize(3*m[0].size());

	hor = h(m);
	ver = v(m);
	horver = hv(m);
	//std::cout<<vracam.size();
	//std::cout<<vracam[0].size();
	for(int i=0; i<m.size()-1;++i){
		if(m[i].size()!=m[i+1].size()) throw std::domain_error("Matrica nije korektna");
	}
	for(int i=0; i<konacna.size(); ++i){
		for(int j=0; j<konacna[0].size(); ++j){		
			if (j<m[0].size() && i<m.size()) konacna[i][j]=horver[i][j];
            if (j>=m[0].size() && j<2*m[0].size() && i<m.size()) konacna[i][j] = ver[i][j-m[0].size()];
            if (j>=2*m[0].size() && j<konacna[0].size() && i<m.size()) konacna[i][j] = horver[i][j-2*m[0].size()];

            if (i<2*m.size() && i>=m.size() && j<m[0].size() ) konacna[i][j]=hor[i-m.size()][j];
            if (i<2*m.size() && i>=m.size() && (j>=m[0].size() && j<2*m[0].size())) konacna[i][j]=m[i-m.size()][j-m[0].size()];
            if (i<2*m.size() && i>=m.size() && (j>=2*m[0].size() && j<konacna[0].size())) konacna[i][j]=hor[i-m.size()][j-2*m[0].size()];


            if (j<m[0].size() && i>=2*m.size() && i<3*m.size()) konacna[i][j]=horver[i-2*m.size()][j];
            if (i>=2*m.size() && i<3*m.size() && (j>=m[0].size() && j<2*m[0].size())) konacna[i][j]=ver[i-2*m.size()][j-m[0].size()];
            if (i>=2*m.size() && i<3*m.size() && (j>=2*m[0].size() && j<konacna[0].size())) konacna[i][j]=horver[i-2*m.size()][j-2*m[0].size()];
		}
	}

return konacna;
}
int main (){
	try {
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>> m>> n;
	if(m<0 || n<0) throw std::domain_error ("Dimenzije matrice moraju biti nenegativne!");
	matrica kreiraj (m, std::vector<double> (n));
	
	std::cout<<"Unesite elemente matrice: "<< std::endl;
	for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            std::cin >> kreiraj[i][j];
  
	std::cout<<"Rezultantna matrica: "<< std::endl;
	matrica moja;
	moja = OgledaloMatrica(kreiraj);
	IspisiMatricu(moja);
	}
	catch (std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	return 0;
}