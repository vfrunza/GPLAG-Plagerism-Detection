#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

Matrica OgledaloMatrica(Matrica Matrix){
	Matrica V(Matrix);
	Matrica H(Matrix);
	Matrica HV(Matrix);
	Matrica pomocna(1);
	
	//vertikalna matrica
	for(int j{0} ; j<V.size() ; j++) {
			pomocna=V[0][j];
			V[0][j]=V[1][j];
			V[1][j]=pomocna;
		
	}
	
	//horizontalna matrica
	for(int j{0} ; j<H[0].size() ; j++) {
			pomocna=H[j][0];
			H[j][2]=H[j][0];
			H[j][2]=pomocna;
		}
	
	
	//horizontalno-vertikalna matrica
	for(int j{0} ; j<HV.size() ; j++) {
			pomocna=HV[0][j];
			HV[0][j]=HV[1][j];
			HV[1][j]=pomocna;
		}
	
	for(int j{0} ; j<HV[0].size() ; j++) {
			pomocna=HV[j][0];
			HV[j][2]=HV[j][0];
			HV[j][2]=pomocna;
		}
	
	//svečano kreiranje matrice
	Matrica M(Matrix.size()*3,std::vector<double>(Matrix[0].size()*3));
	
	for(int i{0} ; i<HV.size() ; i++){
		for(int j{0} ; j<HV[0].size() ; j++){
			M[i][j]=HV[i][j];
		}
	}
	return M;
}

int main ()
{
	std::cout << "Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin >> m >> n;
	Matrica M(m,std::vector<double>(n));
	std::cout << "Unesite elemente matrice: ";
	for(int i{0} ; i<m ; i++){
		for (int j{0} ; j<n ; j++) {
			int element;
			std::cin >> element;
			M[i][j]=element;
		}
	}
	auto rezultantna_matrica(OgledaloMatrica(M));
	
	std::cout << "Rezultantna matrica: " << std::endl;
	for(int i{0};i<rezultantna_matrica.size();i++){
		for(int j{0};j<rezultantna_matrica[0].size();j++){
			std::cout << rezultantna_matrica[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}