/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int br_redova, int br_kolona){
	return Matrica(br_redova, std::vector<double>(br_kolona));
}

int BrojRedova (Matrica m){
	return m.size();
}

int BrojKolona (Matrica m){
	return m[0].size();
}

Matrica UnesiMatricu (int br_redova, int br_kolona){
	auto m(KreirajMatricu(br_redova, br_kolona));
	for (int i = 0; i < br_redova; i++)
		for (int j = 0; j < br_kolona; j++)
			std::cin >> m[i][j];
	return m;
}

void IspisiMatricu (Matrica m){
	for (int i = 0; i < BrojRedova(m); i++){
		for (int j = 0; j < BrojKolona(m); j++)
			std::cout << std::setw(10) << m[i][j];
		std::cout << std::endl;
	}
}


//Kombinovana ogledala
Matrica Kombinovano(Matrica m){
	Matrica k(KreirajMatricu(BrojRedova(m), BrojKolona(m)));
		
	for (int i = 0; i < BrojRedova(m); i++)
		for (int j = 0; j < BrojKolona(m); j++)
		k[i][j] = m[i][j];
		
	return k;
}

Matrica OgledaloMatrica (Matrica m){
	
	int duzina_reda = BrojKolona(m);
		for(int i = 0; i < BrojRedova(m); i++)
			if (m[i].size() != duzina_reda) 
				throw std::domain_error("Matrica nije korektna");

	Matrica MAT(KreirajMatricu(3*BrojRedova(m), 3*BrojKolona(m)));
	
	Matrica h(KreirajMatricu(BrojRedova(m), BrojKolona(m)));
	Matrica v(KreirajMatricu(BrojRedova(m), BrojKolona(m)));
	Matrica hv(KreirajMatricu(BrojRedova(m), BrojKolona(m)));
	
	//matrica h
	for(int i = 0; i < BrojRedova(m); i++){
		for(int j = BrojKolona(m); j >= 0; j--){
			h[i][BrojKolona(m)-j] = m[i][j];
		}
	}
	
	//matrica v
	for(int i = 0; i < BrojRedova(m); i++){
			 v[i] = m[i];
	}
	
	//matrica hv 
	std::vector<int> pomocna(BrojKolona(m));
	for(int i = 0; i < BrojRedova(m); i++){
			for(int j = BrojKolona(m); j >= 0; j--)
			hv[i][BrojKolona(m)-j] = m[i][j];
	}
	for(int i = (BrojRedova(m))/2 ; i >= 0; i--){
			for(int j = 0; j<BrojKolona((m)))
			 pomocna = std::move(hv[i]);
			 hv[i] = hv[BrojRedova(hv)-1-i];
			 hv[BrojRedova(hv)-1-i] = std::move(pomocna);
	}
	
	
	
	
	for(int i = 0; i < BrojRedova(m); i++)
		for(int j = 0; j < BrojKolona(m); j++){
			MAT[i][j]= hv[i][j];
			MAT[i][3*j]= hv[i][j];
			MAT[3*i][j]= hv[i][j];
			MAT[3*i][3*j]= hv[i][j];
		
			MAT[i][2*j] = v[i][j]; 
			MAT[3*i][2*j] = v[i][j];
		
			MAT[2*i][j] = v[i][j]; 
			MAT[2*i][3*j] = v[i][j];
			
			MAT[2*i][2*j]= m[i][j];
		}
	return MAT;
}

int main ()
{
	try {
			int m, n;			
			std::cout << "Unesite dimenzije matrice:"<<std::endl;
			std::cin >> m >> n;
			
			Matrica M(KreirajMatricu(m,n));
			Matrica MAT(KreirajMatricu(m*3,n*3));
		//	UnesiMatricu(m, n);		
			MAT = OgledaloMatrica(M);		
			
			IspisiMatricu(MAT);
	}
	catch(...){
		return 0;
	}
	
	return 0;
}