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

typedef std::vector<std::vector<double>>Matrica;

Matrica KreirajMatricu(int br_redova,int br_kolona){
	return Matrica(br_redova,std::vector<double>(br_kolona));
}
Matrica UnesiMatricu(int br_redova,int br_kolona){
	auto m(KreirajMatricu(br_redova,br_kolona));
	for(int i=0;i<br_redova;i++) {
		for(int j=0;j<br_kolona;j++){
			std::cin>>m[i][j];
		}
	}
	return m;
}
int BrojRedova(Matrica m){
	return m.size();
}
int BrojKolona(Matrica m){
	return m[0].size();
}
Matrica km(Matrica m){
	Matrica km=KreirajMatricu(BrojRedova(m),BrojKolona(m));
	int l=0;
	for(int i=BrojRedova(m)-1;i>=0;i--){
		int s=0;
		for(int j=BrojKolona(m)-1;j>=0;j--){
			km[l][s]=m[i][j];
			s++;
		}
		l++;
	}
	return km;
}
Matrica vm(Matrica m){
	Matrica vm=KreirajMatricu(BrojRedova(m),BrojKolona(m));
	
	for(int i=BrojRedova(m)-1;i>=0;i--){
		for(int j=0;j<BrojKolona(m);j++){
			vm[BrojRedova(m)-1-i][j]=m[i][j];
		}
	}
	return vm;
}
Matrica hm(Matrica m){
	Matrica hm=KreirajMatricu(BrojRedova(m),BrojKolona(m));
	
	for(int i=0;i<BrojRedova(m);i++){
		for(int j=BrojKolona(m)-1;j>=0;j--){
			hm[i][BrojKolona(m)-1-j]=m[i][j];
		}
	}
	return hm;
}




Matrica OgledaloMatrica(Matrica m){
	if(BrojRedova(m)==0 || BrojKolona(m)==0){
		Matrica povratna;
		povratna.resize(3*BrojRedova(m));
		for(int i(0); i<povratna.size(); i++)
			povratna[i].resize(3*BrojKolona(m));
		return povratna;
	}
	Matrica _h = hm(m), _k = km(m), _v(vm(m)), povratna;
	povratna.resize(3*BrojRedova(m));
	for(int i = 0; i<povratna.size(); i++){
		povratna[i].resize(3*BrojKolona(m));
	}
	
	
	for(int i(0); i<povratna.size(); i++){
		int k = 0;
		if(2*BrojRedova(m) <= i && i<3*BrojRedova(m))
			k = 2*BrojRedova(m);
		for(int j(0); j<povratna[0].size(); j++){
			if((0 <= i && i < BrojRedova(m)) || (2*BrojRedova(m) <= i && i<3*BrojRedova(m))){
				if(0 <= j && j < BrojKolona(m)){
					povratna[i][j] = _k[i - k][j];
				}else if(BrojKolona(m) <= j && j < 2*BrojKolona(m)){
					povratna[i][j] = _v[i - k][j-BrojKolona(m)];
				}else{
					povratna[i][j] = _k[i - k][j-2*BrojKolona(m)];
				}
			}else if(BrojRedova(m) <= i && i < 2*BrojRedova(m)){
				if(0 <= j && j < BrojKolona(m))
					povratna[i][j]=_h[i-BrojRedova(m)][j];
				else if(BrojKolona(m) <= j && j < 2*BrojKolona(m))
					povratna[i][j] = m[i-BrojRedova(m)][j-BrojKolona(m)];
				else
					povratna[i][j] = _h[i-BrojRedova(m)][j-2*BrojKolona(m)];
			}
			
			
		}
	}


return povratna;	
}

int main ()
{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!"<<std::endl;
		return 0;
	}
	
	std::cout<<"Unesite elemente matrice: "<<std::endl;

     auto mat(UnesiMatricu(m,n));
     Matrica matr;
     matr=OgledaloMatrica(mat);
     
     std::cout<<"Rezultantna matrica:"<<std::endl;
     for(int i=0;i<matr.size();i++){
     	for(int j=0;j<matr[0].size();j++){
     		std::cout<<std::setw(4)<<matr[i][j];
     	}
     	std::cout<<std::endl;
     }
	
	return 0;
}