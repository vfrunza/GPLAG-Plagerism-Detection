#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

bool DaLiJeGrbava(std::vector<std::vector<double>> matrica) {
	bool t(false); 
	for(unsigned int i=0; i<matrica.size(); i++) {
		for(unsigned int j=i+1; j<matrica.size(); j++) {
			if(matrica[i].size()!=matrica[j].size()) return true;
			if(j==matrica.size()-1) break;
		}
		if(i==matrica.size()-1) break;
	}
	return t;
}

int BrojRedova(std::vector<std::vector<double> > matrica) {
	
	return matrica.size();
}

int BrojKolona(std::vector<std::vector<double> > matrica) {
	if(matrica.size()==0) return 0;
	return matrica[0].size();
	
}

std::vector<std::vector<double> > KreirajMatricu(int brojredova, int brojkolona) {
	
	std::vector<std::vector<double> > matrica(brojredova, std::vector<double>(brojkolona));
	return matrica;
	
}

std::vector<std::vector<double> > UnesiMatricu(int brojredova, int brojkolona) {
	auto matrica(KreirajMatricu(brojredova, brojkolona));
	if(DaLiJeGrbava(matrica)) throw std::domain_error("Matrica nije korektna");
	for(unsigned int i=0; i<brojredova; i++) {
	for(unsigned int j=0; j<brojkolona; j++) {
		std::cin >> matrica[i][j];
		if(j==brojkolona-1) break;
	} 
		if(i==brojredova-1) break;
	} 
	return matrica;
}


void IspisiMatricu(std::vector<std::vector<double> > matrica) {
	for(auto red : matrica) {
		for(auto x : red) {
			std::cout << std::setw(4) << x;
		}
		std::cout << std::endl;
	}
}

std::vector<std::vector<double> > hM(std::vector<std::vector<double> > matrica) {
	auto hM(KreirajMatricu(BrojRedova(matrica), BrojKolona(matrica)));
	for(unsigned int i=0; i<BrojRedova(hM); i++) {
		for(unsigned int j=0; j<BrojKolona(hM); j++) {
			int k;
			k=BrojKolona(hM)-j-1;
			hM[i][j]=matrica[i][k];
			if(j==BrojKolona(hM)-1) break;
		}
	if(i==BrojRedova(hM)-1) break;	
	}
	return hM;
}

std::vector<std::vector<double> > vM(std::vector<std::vector<double> > matrica) {
	auto vM(KreirajMatricu(BrojRedova(matrica), BrojKolona(matrica)));
	for(unsigned int i=0; i<BrojRedova(vM); i++) {
		for(unsigned int j=0; j<BrojKolona(vM); j++) {
			int k;
			k=BrojRedova(vM)-i-1;
			vM[i][j]=matrica[k][j];
			if(j==BrojKolona(vM)-1) break;
		
		}
		if(i==BrojRedova(vM)-1) break;
	}
	return vM;
}

std::vector<std::vector<double> > hvM(std::vector<std::vector<double> > matrica) {
	auto hvM(hM(matrica));
	return vM(hvM);
}

std::vector<double> Spoji(std::vector<double> v1, std::vector<double> v2) {
	std::vector<double> spojen;
	for(unsigned int i=0; i<2*v1.size()+v2.size(); i++) {
		if(i<v1.size()) spojen.push_back(v1[i]);
		else if(i>=v1.size() && i<v1.size()+v2.size()) spojen.push_back(v2[i-v1.size()]);
		else spojen.push_back(v1[i-v1.size()-v2.size()]);
		if(i==2*v1.size()+v2.size()) break;
	}
	return spojen;
}	


std::vector<std::vector<double> > OgledaloMatrica(std::vector<std::vector<double> > matrica) {

		auto a(KreirajMatricu(3*BrojRedova(matrica), 3*BrojKolona(matrica)));
	
		for(unsigned int i=0; i<BrojRedova(a); i++) {
			
			for(unsigned int j=0; j<BrojRedova(matrica); j++) {
			if(i<int(BrojRedova(a)/3.+0.5))	a[i]=Spoji(hvM(matrica)[j], vM(matrica)[j]);
			else if(i<int((2*BrojRedova(a))/3.+0.5)) a[i]=Spoji(hM(matrica)[j], matrica[j]);
			else a[i]=Spoji(hvM(matrica)[j], vM(matrica)[j]);
				if(j==BrojRedova(matrica)-1) break;
				if(i==BrojRedova(a)-1) break;
				i++;
				
			}
	if(i==BrojRedova(a)-1) break;	}
	return a;
}
	
	
	int main ()
{
	
	std::cout << "Unesite dimenzije matrice (m n): ";
	int m, n;
	std::cin >> m >> n;
	if(m<0 || n<0) {std::cout<< "Dimenzije matrice moraju biti nenegativne!"; return 0;}
	std::cout << "Unesite elemente matrice: " ;
	try {
	auto a(UnesiMatricu(m, n)); 
	auto b(OgledaloMatrica(a));
	std::cout<< std::endl << "Rezultantna matrica: " << std::endl;
	IspisiMatricu(b); }
	catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
  	
	return 0; 
} 