#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int broj_redova , int broj_kolona){
	return Matrica(broj_redova, std::vector<double>(broj_kolona));
}

void IspisiMatricu(Matrica m){
	for(int i = 0; i < m.size(); i++){
		for(int j = 0; j < m[0].size(); j++){
			std::cout << std::setw(4) << m[i][j];
		}
		std::cout << std::endl;
	}
}

Matrica KreirajH(Matrica m){
	int broj_redova = m.size();
	int broj_kolona = m[0].size();
	Matrica h = Matrica(broj_redova, std::vector<double>(broj_kolona));
	for(int i = 0; i < broj_redova; i++){
		for(int j = 0; j < broj_kolona; j++){
			h[i][j] = m[i][broj_kolona-1-j];
		}
	}
	return h;
}

Matrica KreirajV(Matrica m){
	int broj_redova = m.size();
	int broj_kolona = m[0].size();
	Matrica v = Matrica(broj_redova, std::vector<double>(broj_kolona));
	for(int i = 0; i < broj_redova; i++){
		for(int j = 0; j < broj_kolona; j++){
			v[i][j] = m[broj_redova-1-i][j];
		}
	}
	return v;
}

Matrica KreirajHV(Matrica m){
	int broj_redova = m.size();
	int broj_kolona = m[0].size();
	Matrica hv = Matrica(broj_redova, std::vector<double>(broj_kolona));
	for(int i = 0; i < broj_redova; i++){
		for(int j = 0; j < broj_kolona; j++){
			hv[i][j] = m[broj_redova-1-i][broj_kolona-1-j];
		}
	}
	return hv;
}

Matrica OgledaloMatrica(Matrica m){
	int uslov(true);
	for(int i = 0; i < m.size(); i++){
		if(m[0].size() != m[i].size()){
			uslov = false;
			break;
		}
	}
	if(!uslov) throw std::domain_error("Matrica nije korektna");
	if(m.size() == 0) return m;
	else{
		Matrica rez(KreirajMatricu(3*m.size(),3*m[0].size()));
		Matrica h(KreirajH(m));
		Matrica v(KreirajV(m));
		Matrica hv(KreirajHV(m));
		
		for(int i = 0; i < rez.size(); i++){
			for(int j = 0; j < rez[0].size(); j++){
				if(i < m.size()){
					if(j < m[0].size()) rez[i][j] = hv[i][j];
					else if (j < 2*m[0].size()) rez[i][j] = v[i][j-m[0].size()];
					else rez[i][j] = hv[i][j-2*m[0].size()];
				}
				else if(i < 2*m.size()){
					if(j < m[0].size()) rez[i][j] = h[i-m.size()][j];
					else if (j < 2*m[0].size()) rez[i][j] = m[i-m.size()][j-m[0].size()];
					else rez[i][j] = h[i-m.size()][j-2*m[0].size()];
				}
				else{
					if(j < m[0].size()) rez[i][j] = hv[i-2*m.size()][j];
					else if (j < 2*m[0].size()) rez[i][j] = v[i-2*m.size()][j-m[0].size()];
					else rez[i][j] = hv[i-2*m.size()][j-2*m[0].size()];
				}
			}
		}
		return rez;
	}
}

int main ()
{
	int m,n;
	std::cout <<"Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m >= 0 && n >= 0){
		Matrica mat;
		mat = KreirajMatricu(m,n);
		std::cout << "Unesite elemente matrice: ";
		for(int i = 0 ; i < m ; i++ ){
			for(int j = 0 ; j < n ; j++){
				std::cin >> mat[i][j] ;
			}
		}
		try{
			Matrica m2(OgledaloMatrica(mat));
			std::cout << std::endl << "Rezultantna matrica:" << std::endl;
			IspisiMatricu(m2);
		}
		catch(std::domain_error izuzetak){
			std::cout << izuzetak.what() << std::endl;
		}
	}
	else std::cout << "Dimenzije matrice moraju biti nenegativne!";
	return 0;
}