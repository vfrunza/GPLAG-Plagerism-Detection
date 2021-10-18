/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int r, int k){
	return Matrica(r,std::vector<double>(k));
}

Matrica UnesiMatricu(int r, int k){
	auto m(KreirajMatricu(r, k));
	for(int i=0 ; i<r ; i++){
		for(int j=0 ; j<k ; j++){
			
			std::cin>> m.at(i).at(j);
		}
	}
	return m;
}
Matrica Kopiraj(Matrica m,int a,int b,int x){
	int vel(2*x+1);
	Matrica m1(KreirajMatricu(vel,vel));
	a=a-x;
	b=b-x;
	for(int i=0; i<vel ; i++){
		for(int j=0 ; j<vel; j++){
			m1.at(i).at(j)=m.at(a).at(b);
			b++;
		}
		b=b-vel;
		a++;
	
	}
	return m1;
}
int BrojKoncentricnihKvadrata(Matrica m,int r,int k){
	int a(1), suma(0);
	if(r==0 || k==0 || r==m.size()-1 || k==m.at(0).size()-1) return 0;
	for(int i = r-a ; i <= r+a ; i++){
			for( int j = k-a ; j <= k+a ; j++){
				suma += m.at(i).at(j);
			}
		}
	if(suma-m.at(r).at(k)>=m.at(r).at(k)) return 0;
	if(r-a<=0 || k-a<=0 ||  r+a>=m.size() || k+a>=m.size()) return 1;
	int suma1(suma-m.at(r).at(k));
	for( ; ; ){
		int suma2(suma1);
		a++;
		for(int i = r-a ; i <= r+a ; i++){
			for( int j = k-a ; j <= k+a ; j++){
				if(i==r-a || i==r+a || j==r-a || j==r+a)	suma1 += m.at(i).at(j);
			}
		}
		if(suma1>=suma2) break;
		if(r-a<=0 || k-a<=0 || r+a>=m.size()-1 || k+a>=m.size()-1) break;
	}
	
	return a;
}

Matrica NajvecaPlaninaMatrice(Matrica m){
	Matrica N(0),m1;
	if(m.size() == 0 || m.at(0).size() == 0) {
		Matrica m2(KreirajMatricu(0,0));
		return m2;
	}
	
	for(int i=0 ; i<m.size()-1; i++){
		if(m.at(i).size()!=m.at(i+1).size()) throw std::domain_error ("Matrica nije korektna");
	}
	
	for( int i=0 ; i<m.size() ; i++){
		for( int j=0; j<m.at(i).size() ; j++){
			if(BrojKoncentricnihKvadrata(m,i,j)>=0){
				int x=BrojKoncentricnihKvadrata(m,i,j);
				m1=Kopiraj(m,i,j,x);
				if(m1.size()>N.size()){
					N=Kopiraj(m,i,j,x);
				}
				if(m1.size()==N.size()){
					if(m.at(i).at(j)>N.at(x).at(x)) N=Kopiraj(m,i,j,x);
				}
			}
		}
	}
	return N;
}



int main ()
{
	 try {
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m >>n;
	if(m<0 || n<0) throw std::domain_error ("Dimenzije matrice moraju biti nenegativne!");
	
		std::cout<<"Unesite elemente matrice: ";
	    Matrica x;
		x=UnesiMatricu(m,n);
		Matrica y(NajvecaPlaninaMatrice(x));
		
		std::cout<<std::endl<<"Najveca planina unesene matrice je: ";
		std::cout<<std::endl;
		 for(int i=0 ; i<y.size(); i++){
			for(int j=0 ; j<y.at(i).size(); j++){
				std::cout<<std::setw(6)<<y.at(i).at(j);
			}
			std::cout<<std::endl;
		 }
	}
	
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	return 0;
}