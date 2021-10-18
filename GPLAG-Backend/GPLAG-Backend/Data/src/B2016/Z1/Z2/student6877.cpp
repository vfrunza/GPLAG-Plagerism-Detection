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
typedef std::vector<double> Vector;

Matrica KreirajMatricu (int broj_redova,int broj_kolona){
	return Matrica(broj_redova, Vector (broj_kolona));
}

Matrica HorizontalnoOgledalo (Matrica a){
	Matrica b = KreirajMatricu(a.size(),a[0].size());
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[0].size();j++){
			b[i][j]=a[i][a[0].size()-1-j];
		}
     }
	
	return b;
}
Matrica VertikalnoOgledalo (Matrica a){
	Matrica b(a.size(), Vector (a[0].size()));
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[0].size();j++){
			b[i][j]=a[a.size()-1-i][j];
		}
	  }
	
	return b;
}
Matrica KombinovanoOgledalo (Matrica a){
	Matrica c(a.size(), Vector (a[0].size()));
	c = HorizontalnoOgledalo(a);
	Matrica b = VertikalnoOgledalo(c);
	return b;
}


Matrica OgledaloMatrica (Matrica a){
	if (a.size()==0) return a;
	for(int i=0;i<a.size()-1;i++){
	if(a[i].size()!=a[i+1].size()) throw std::domain_error ("Matrica nije korektna!"); 
		}

	Matrica hM = HorizontalnoOgledalo(a);
	Matrica vM = VertikalnoOgledalo(a);
	Matrica kM = KombinovanoOgledalo(a);

	
	
	int red(a.size());
	int kol(a[0].size());
	
	Matrica b = KreirajMatricu(3*red,3*kol);

    for(int i=0;i<3*red;i++){
		for(int j=0;j<3*kol;j++){
			if(i<=red-1) {
				if(j<=kol-1) 			 b[i][j]=kM[i][j];
				if(j>=kol && j<=2*kol-1) b[i][j]=vM[i][j-kol];
				if(j>=2*kol) 			 b[i][j]=kM[i][j-2*kol];
			}
			
			if(i>=red && i<=2*red-1) {
				if(j<=kol-1) 			 b[i][j]=hM[i-red][j];
				if(j>=kol && j<=2*kol-1) b[i][j]=a[i-red][j-kol];
				if(j>=2*kol) 		   	 b[i][j]=hM[i-red][j-2*kol];
			}
			
			if(i>=2*red) {
				if(j<=kol-1)   			 b[i][j]=kM[i-2*red][j];
				if(j>=kol && j<=2*kol-1) b[i][j]=vM[i-2*red][j-kol];
				if(j>=2*kol) 			 b[i][j]=kM[i-2*red][j-2*kol];
			} 
		}
	}
	return b;
}

int main ()
{
	std::cout << "Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin >>m>>n;
	if(m<0 || n<0){ std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0; }
	std::cout << "Unesite elemente matrice: "<<std::endl;;
	Matrica a = KreirajMatricu(m,n);
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			std::cin >> a[i][j];
		}
	}
	try{
	Matrica b = OgledaloMatrica(a);
	
	std::cout<<"Rezultantna matrica: "<<std::endl;
	for(int i=0;i<b.size();i++){
		for(int j=0;j<b[i].size();j++){
			std::cout <<std::right<<std::setw(4)<< b[i][j];
		}
		std::cout << ""<<std::endl;
	}
	}
	catch(std::domain_error izuzetak){
		std::cout<< izuzetak.what()<<std::endl;
	}
	return 0;
}