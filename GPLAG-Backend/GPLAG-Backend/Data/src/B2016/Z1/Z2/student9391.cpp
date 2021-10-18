/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica NapraviMatricu (int br_redova, int br_kolona) {
	Matrica m(br_redova);
	for(int i=0;i<br_redova;i++)
	m.at(i).resize(br_kolona);
	return m;
}

int BrojRedova(Matrica m) {
	return m.size();
}

int BrojKolona(Matrica m) {
	if (BrojRedova(m)>0)
	return m[0].size();
	else 
	return 0;
}

bool JeLiGrbava(Matrica m) {
	int brojac=m.at(0).size();
	bool grbava=false;
	for(int i=0; i<m.size(); i++) {
		if(brojac!=m.at(i).size()) {
			grbava=true;
			break;
		}
		grbava=false;
		}
	return brojac;
}

Matrica UnesiMatricu (int br_redova, int br_kolona) {
	Matrica m(NapraviMatricu(br_redova, br_kolona));
	std::cout << "Unesite elemente matrice:"<<std::endl;
	for(int i=0;i<br_redova;i++) {
		for(int j=0;j<br_kolona;j++) {
			std::cin >> m[i][j];
		}
	}
	return m;
}

void IspisiMatricu(Matrica m) {
	for(int i=0; i<BrojRedova(m); i++) {
		for(int j=0; j<BrojKolona(m); j++) {
			std::cout << std::setw(4) << m[i][j];
		}
		std::cout<<std::endl;
	}
}

Matrica H(Matrica m) {
	Matrica K(NapraviMatricu(BrojRedova(m), BrojKolona(m)));
	for(int i=0; i<BrojRedova(m);i++) {
		for(int j=BrojKolona(m)-1; j>=0; j--) {
			K[i][j]=m[i][BrojKolona(m)-1-j];
		}
		std::cout << std::endl;
	}
	return K;
}

Matrica V(Matrica m) {
	Matrica K(NapraviMatricu(BrojRedova(m),BrojKolona(m)));
	for(int i=BrojRedova(m)-1;i>=0;i--) {
		for(int j=0;j<BrojKolona(m);j++) {
			K[i][j]=m[BrojRedova(m)-1-i][j];
		}
		std::cout<<std::endl;
	}
	return K;
}

Matrica OgledaloMatrica(Matrica m) {
	int br_r=3,br_k=3;
	
	if (BrojKolona(m)==0) {
		{
		Matrica Izlaz;
		Izlaz.resize(3*BrojRedova(m));
		for (int i=0; i<3*BrojRedova(m); i++) Izlaz.at(i).resize(0);
	}
	}
	
	if (BrojRedova(m)==0){
		Matrica Izlaz;
		Izlaz={};
	}
	
	Matrica Izlaz(NapraviMatricu(br_r*BrojRedova(m),br_k*BrojKolona(m)));
	for(int i=0; i<BrojRedova(m); i++) {
		for(int j=0; j<BrojKolona(m); j++) {
			Izlaz[i][j]=H(V(m))[i][j];//lijeva gornja
			Izlaz[i][j+BrojKolona(m)]=V(m)[i][j];//srednja gornja
			Izlaz[i][j+2*BrojKolona(m)]=H(V(m))[i][j];//desna gornja
			Izlaz[i+BrojRedova(m)][j]=H(m)[i][j];//lijeva srednja
			Izlaz[i+BrojRedova(m)][j+BrojKolona(m)]=m[i][j];//srednja
			Izlaz[i+BrojRedova(m)][j+2*BrojKolona(m)]=H(m)[i][j];//srednja desna
			Izlaz[i+2*BrojRedova(m)][j]=H(V(m))[i][j];//donja lijeva
			Izlaz[i+2*BrojRedova(m)][j+BrojKolona(m)]=V(m)[i][j];//donja srednja
			Izlaz[i+2*BrojRedova(m)][j+2*BrojKolona(m)]=H(V(m))[i][j];//donja lijeva
		}
	}
	return Izlaz;
}


int main ()
{
	int m,n;
//	Matrica a={{1,2},{7}};
//	std::cout << JeLiGrbava(a) <<std::endl;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m<0 || n<0) {
		std::cout<< "Dimenzije matrice moraju biti nenegativne!";
	} else {
	Matrica Mat(UnesiMatricu(m, n));
	std::cout << "Rezultantna matrica:" << std::endl; 
	IspisiMatricu(OgledaloMatrica(Mat));
	}
	return 0;
}