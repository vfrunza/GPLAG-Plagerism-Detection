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

typedef std::vector<std::vector<double>> Matrica;

//Kreira matricu sa zadanim brojem redova i kolona 
Matrica KreirajMatricu (int br_red, int br_kol){
	return Matrica (br_red, std::vector<double> (br_kol));
}

//Vraca broj redova zadane matrice 
int BrojRedova(Matrica mat){
	return mat.size();
}

//Vraca broj kolona zadane matrice
int BrojKolona (Matrica mat){
	return mat[0].size();
}


//Unosi sa tastature matricu sa zadanim br kolona i redova i vraca je kao re{zultat
Matrica UnesiMatricu (int br_red, int br_kol){
	auto mat(KreirajMatricu(br_red, br_kol));
	for (int i = 0; i < br_red; i++){
		for (int j = 0; j < br_kol; j++){
			std::cout << "Element (" << i + 1 << "," << j + 1 << "): ";
			std::cin >> mat[i][j];
		}
	}
	return mat;
}

//Ispisi matricu 
void IspisiMatricu (Matrica mat){
	for (int i = 0; i < BrojRedova(mat); i++){
		for (int j = 0; j < BrojKolona(mat); j++)
		std::cout << std::setw(4) << mat[i][j];
		std::cout << std::endl;
	}
}

Matrica OgledaloMatrica(Matrica mat){
	Matrica h, v, hv, M;
	//int j2(0);
	for (int i = 0; i < BrojRedova(mat); i++){
		for (int j = BrojKolona(mat); j > 0; j--){
		h[i][j] = mat[i][j2];
		mat[i]][j] = h[i][j2];
		
		}
	}
	for (int i = BrojRedova(mat); i > 0; i--){
		for (int j = 0; j < BrojKolona(mat); j++){
			int i2;
			v[i][j] = mat[i2][j];
		}
		i2++;
	}
	for (int i = BrojRedova(mat); i > 0; i--){
		for (int j = BrojKolona(mat); j > 0; j--){
			
		}
	}
}

int main ()
{
	return 0;
}