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

void IspisiMatricu(const Matrica m)
{
   for(int i=0; i< m.size(); i++) {
      for(int j=0; j<m[i].size(); j++)
         std::cout << std::setw(4) << m[i][j];
      std::cout << std::endl;
   }
}

Matrica KreirajMatricu(int br_redova, int br_kolona)
{
   return Matrica(br_redova, std::vector<double>(br_kolona));
}

Matrica Horizontalna(const Matrica m){
	Matrica nova(KreirajMatricu(m.size(), m[0].size()));
	for(int i=0; i < m.size(); i++){
		int k=0;
		for(int j= m[i].size()-1; j>=0; j--){
			nova[i][k] = m[i][j];
			k++;
		}
	}
	return nova;
}

Matrica HorizAndVerti(const Matrica m){
	Matrica nova(KreirajMatricu(m.size(), m[0].size()));
	int k=0;
	for(int i=m.size()-1; i>=0; i--){
		for(int j=0; j<=m[i].size(); j++){
			nova[k][j] = m[i][j];
		}
		k++;
	}
	nova = Horizontalna(nova);
	return nova;
}

Matrica Vertikalna(const Matrica m){
	Matrica nova(KreirajMatricu(m.size(), m[0].size()));
	int k=0;
	for (int i=m.size()-1; i>=0 ; i--){
		for (int j=m[i].size()-1; j>=0; j--){
			nova[k][j] = m[i][j];
		}
		k++;
	}
	return nova;
}

bool JeLiGrbava(const Matrica m){
	bool Jeste(true);
	int duzina = m[0].size();
	for(int i=0; i< m.size(); i++){
		for(int j=0; j< m[i].size(); j++){
			if(m[i].size() != duzina) {
				Jeste = false;
				break;
			}
		}
	}
	return Jeste;
}

Matrica OgledaloMatrica(const Matrica m){
	
	try {
		Matrica nova(KreirajMatricu(3*m.size(), 3* m[0].size()));
		if(!JeLiGrbava(m)) throw std::domain_error("Matrica nije korektna");
		Matrica Vert(Vertikalna(m));
		Matrica Horz(Horizontalna(m));
		Matrica Mix(HorizAndVerti(m));
		
		int sirina = Mix.size();
		int duzina = Mix[0].size();
		
		for(int i=0; i < sirina; i++){				// prva 2 reda
			for(int j=0; j <nova[i].size(); j++){
				if(j < duzina) nova[i][j] = Mix[i][j];
				else if(j>=duzina && j<2*duzina) nova[i][j] = Vert[i][j-duzina];
				else nova[i][j] = Mix[i][j-2*duzina];
			}
		}
		
		for (int i= sirina; i < 2*sirina; i++){ 	// druga 2 reda
			for (int j=0; j<nova[i].size(); j++){
				if(j<duzina) nova[i][j] = Horz[i-sirina][j];
				else if(j>=duzina && j<2*duzina) nova[i][j] = m[i-sirina][j-duzina];
				else nova[i][j] = Horz[i-sirina][j-2*duzina];
			}
		}
		
		for(int i= 2*sirina; i < 3*sirina; i++){ // treca 2 reda
			for(int j=0; j< nova[i].size(); j++){
				if(j<duzina) nova[i][j] = Mix[i-2*sirina][j];
				else if(j>=duzina && j<2*duzina) nova[i][j] = Vert[i-2*sirina][j-duzina];
				else nova[i][j] = Mix[i-2*sirina][j-2*duzina];
			}
		}
		
		return nova;
		
	}
	catch(std::domain_error izuzetak){
		std::cout << izuzetak.what() << std::endl;
	}
}


int main ()
{
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m<0 || n<0){ std::cout << "Dimenzije matrice moraju biti nenegativne!"; return 0; }
	Matrica matrix(KreirajMatricu(m,n));
	
	double element;
	std::cout << "Unesite elemente matrice: ";
	for(int i=0; i<matrix.size(); i++){
		for(int j=0; j<matrix[i].size(); j++){
			std::cin >> element;
			matrix[i][j] = element;
		}
	}
	for (const auto &red : matrix)
		{
			for (const auto &i : red)
				std::cout.width (4), std::cout << i;
			std::cout << std::endl;
		}
	std::cout << "Rezultantna matrica:" << std::endl;
	IspisiMatricu(OgledaloMatrica(matrix));
	return 0;
}