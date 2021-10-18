/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include<iomanip>
#include<stdexcept>
typedef std::vector<std::vector<double>> matrica;
matrica kreirajmatricu(int redovi, int kolone){
return matrica(redovi,std::vector<double>(kolone));}

matrica OgledaloMatrica(matrica X){
	if(X.size()==0){
		return X;
	}
	for(int i=0;i<X.size()-1;i++){
		for(int j=0;j<X[0].size();j++){
	if(X[i].size()!=X[i+1].size())
		throw std::domain_error("Matrica nije korektna.");
	}}
	matrica Y(kreirajmatricu(3*X.size(),3*X[0].size()));
	matrica horizontalna(kreirajmatricu(X.size(),X[0].size()));
	matrica vertikalna(kreirajmatricu(X.size(),X[0].size()));
	matrica hv(kreirajmatricu(X.size(),X[0].size()));
	for (int i=0;i<X.size();i++){
		for(int j=0;j<X[0].size ();j++){
			horizontalna[i][j]=X[i][X[0].size()-1-j];
		}
}
for (int i=0;i<X.size();i++){
		for(int j=0;j<X[0].size ();j++){
		vertikalna[i][j]=X[X.size()-1-i][j];}}
		
		for (int i=0;i<X.size();i++){
		for(int j=0;j<X[0].size ();j++){
			hv[i][j]=X[X.size()-1-i][X[0].size()-1-j];}}

for(int i=0;i<3*X.size();i++){
	for(int j=0;j<3*X[0].size();j++){
		if((i<X.size()&& j<X[0].size())||(i>=2*X.size()&&j<X[0].size())||(i<X.size()&&j>=2*X[0].size())||(i>=2*X.size()&&j>=2*X[0].size())){
			Y[i][j]=hv[i%X.size()][j%X[0].size()];
		}
		else if (i>=X.size()&&i<2*X.size()&&(j<X[0].size()||j>=2*X[0].size())){
			Y[i][j]=horizontalna[i%X.size()][j%X[0].size()];
	}
	else if (j>=X[0].size()&&j<2*X[0].size()&&(i<X.size()||i>=2*X.size())){
		Y[i][j]=vertikalna[i%X.size()][j%X[0].size()];
	}else {Y[i][j]=X[i%X.size()][j%X[0].size()];
}}}
	return Y;
}
			


	
int main ()
{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0||n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	matrica X(kreirajmatricu(m,n));
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++) std::cin>>X[i][j];
	}
	matrica Y(kreirajmatricu(3*m,3*n));
	try{
	Y=OgledaloMatrica(X);}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
	for(int i=0;i<Y.size();i++){
		for(int j=0;j<Y[0].size();j++)
		std::cout<<std::setw(4)<<Y[i][j];
		std::cout<<std::endl;
		
	}
	
	return 0;
}