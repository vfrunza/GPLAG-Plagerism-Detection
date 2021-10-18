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

//Kreira matricu sa zadanim brojem redova i kolona
Matrica KreirajMatricu (int br_redova, int br_kolona){
	return Matrica(br_redova, std::vector<double>(br_kolona));
}

Matrica UnesiMatricu (int br_redova, int br_kolona){
	auto m(KreirajMatricu(br_redova, br_kolona));
	for (int i=0;i<br_redova;i++){
		for (int j=0;j<br_kolona;j++){
			std::cin >> m[i][j];
		}
	}
	return m;
}

void IspisiMatricu (Matrica m){
	for (auto red : m){
		for (auto x : red)
			std::cout << std::setw(4) << x;
		std::cout << std::endl;
	}
}

Matrica HorizOgledalo (Matrica m){
	auto mat(KreirajMatricu(m.size(),m[0].size()));
	int br1(0);
	for (int i=0;i<m.size();i++){
		int br2(0);
		for (int j=m[i].size()-1;j>=0;j--){
			mat[br1][br2]=m[i][j];
			br2++;
		}
		br1++;
	}
	return mat;
}

Matrica VertikOgledalo (Matrica m){
	auto mat(KreirajMatricu(m.size(),m[0].size()));
	int br1(0);
	for (int i=m.size()-1;i>=0;i--){
		int br2(0);
		for (int j=0;j<m[i].size();j++){
			mat[br1][br2]=m[i][j];
			br2++;
		}
		br1++;
	}
	return mat;
}

Matrica KombinOgledalo (Matrica m){
	auto mat(KreirajMatricu(m.size(),m[0].size()));
	mat=HorizOgledalo(m);
	mat=VertikOgledalo(mat);
	return mat;
}

Matrica OgledaloMatrica (Matrica m){
	if (m.size()==0)
		return m;
	bool grbava_mat(false);
	for (int i=0;i<m.size();i++){
		if (m[i].size()!=m[0].size()){
			grbava_mat=true;
			break;
		}
	}
	if (grbava_mat==true) throw std::domain_error("Matrica nije korektna");
	auto mat(KreirajMatricu(3*m.size(),3*(m[0].size())));
	Matrica mat_kom(KombinOgledalo(m));
	Matrica mat_vert(VertikOgledalo(m));
	Matrica mat_horiz(HorizOgledalo(m));
	int br1(0);
	for(int i=0;i<mat.size();i++){
		int br2(0);
		for (int j=0;j<mat[i].size();j++){
			if (i<m.size() && j<m[0].size())
				mat[br1][br2]=mat_kom[i][j];
			else if (i>=m.size() && i<2*(m.size()) && j>=m[0].size()  && j<2*(m[0].size()))
				mat[br1][br2]=m[i-m.size()][j-m[0].size()];
			else if (i>=m.size() && i<2*(m.size()) && j<m[0].size())
				mat[br1][br2]=mat_horiz[i-m.size()][j];
			else if (j>=m[0].size() && j<2*(m[0].size()) && i<m.size())
				mat[br1][br2]=mat_vert[i][j-m[0].size()];
			else if (j>=2*(m[0].size()) && j<mat[0].size() && i<m.size())
				mat[br1][br2]=mat_kom[i][j-2*m[0].size()];
			else if (j>=2*(m[0].size()) && j<mat[0].size() && i<2*(m.size()))
				mat[br1][br2]=mat_horiz[i-(m.size())][j-2*(m[0].size())];
			else if (j<m[0].size() && i>=2*m.size() && i<mat.size())
				mat[br1][br2]=mat_kom[i-2*m.size()][j];
			else if (i>=2*m.size() && i<mat.size() && j>=m[0].size() && j<2*m[0].size())
				mat[br1][br2]=mat_vert[i-2*m.size()][j-m[0].size()];
			else if (i>=2*m.size() && i<mat.size() && j>=2*m[0].size() && j<mat[0].size())
				mat[br1][br2]=mat_kom[i-2*m.size()][j-2*m[0].size()];
			else
				mat[br1][br2]=0;
			br2++;
		}
		br1++;
	}
	return mat;
}

int main ()
{
	int m,n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if (m<0 || n<0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout << "Unesite elemente matrice: ";
	auto mat(UnesiMatricu(m,n));
	try{
		mat=OgledaloMatrica(mat);
		std::cout << std::endl << "Rezultantna matrica: "<< std::endl;
	}
	catch (std::domain_error izuzetak){
		std::cout << std::endl << "IZUZETAK: " << izuzetak.what() << "!" << std::endl;
	}
	IspisiMatricu(mat);
	return 0;
}