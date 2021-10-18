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
#include<stdexcept>
typedef std::vector<std::vector<double>> Matrica;
bool dalijegrbava(Matrica m){
	bool jel(true);
	for(int i=0; i<m.size()-1; i++){
		if(m[i].size()!=m[i+1].size()) jel=false;
	}
	if(!jel) {
		throw std::domain_error("Matrica nije korektna");
	}
	else return jel;
}
Matrica hor( Matrica m){
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size()/2; j++){
			double temp=m[i][j];
			m[i][j]=m[i][m[i].size()-j-1];
			m[i][m[i].size()-j-1]=temp;
		}
	}
	return m;
}
Matrica ver(Matrica m){
	for(int i=0; i<m.size()/2; i++){
		for(int j=0; j<m[i].size(); j++){
			double temp=m[i][j];
			m[i][j]=m[m.size()-i-1][j];
			m[m.size()-i-1][j]=temp;
		}
	}
	return m;
}
Matrica horver(Matrica m){
	Matrica m1(ver(hor(m)));
	return m1;
}
Matrica OgledaloMatrica(Matrica m){
	int vel;
	Matrica x;
	if(m.size()==0) return x;
	try{
		dalijegrbava(m);
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	for(int i=0; i<m.size(); i++) vel=m[i].size();
	Matrica M(3*m.size(), std::vector<double> (3*vel));
	Matrica m1(horver(m));
	for(int i=0; i<m1.size(); i++){
		for(int j=0; j<m1[i].size(); j++){
			M[i][j]=m1[i][j];
		}
	}
	Matrica m2(ver(m));
	for(int i=0; i<m2.size(); i++){
		for(int j=0; j<m2[i].size(); j++){
			M[i][j+vel]=m2[i][j];
		}
	}
	for(int i=0; i<m1.size(); i++){
		for(int j=0; j<m1[i].size(); j++){
			M[i][j+2*vel]=m1[i][j];
		}
	}
	Matrica m3(hor(m));
	for(int i=0; i<m3.size(); i++){
		for(int j=0; j<m3[i].size(); j++){
			M[i+m.size()][j]=m3[i][j];
		}
	}
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size(); j++){
			M[i+m.size()][j+vel]=m[i][j];
		}
	}
	for(int i=0; i<m3.size(); i++){
		for(int j=0; j<m3[i].size(); j++){
			M[i+m.size()][j+2*vel]=m3[i][j];
		}
	}
	for(int i=0; i<m1.size(); i++){
		for(int j=0; j<m1[i].size(); j++){
			M[i+2*m.size()][j]=m1[i][j];
		}
	}
	for(int i=0; i<m2.size(); i++){
		for(int j=0; j<m2[i].size(); j++){
			M[i+2*m.size()][j+vel]=m2[i][j];
		}
	}
	for(int i=0; i<m1.size(); i++){
		for(int j=0; j<m1[i].size(); j++){
			M[i+2*m.size()][j+2*vel]=m1[i][j];
		}
	}
	return M;

}
int main ()
{
	int m, n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std:: cin>>m >>n;
	if(m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica M (m, std::vector<double>(n));
	std::cout<<"Unesite elemente matrice: "<<std::endl;
	for(int i=0; i<M.size(); i++){
		for(int j=0; j<M[i].size(); j++){
			std::cin>>M[i][j];
		}
	}
	M=OgledaloMatrica(M);
	std::cout<<"Rezultantna matrica: "<<std::endl;
	for(int i=0; i<M.size(); i++){
		for(int j=0; j<M[i].size(); j++){
			std::cout<<std::setw(4)<<M[i][j];
		}
		std::cout<<"\n";
	}
	return 0;
}