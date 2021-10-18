/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>>Matrica;
Matrica KreirajMatricu(int br_redova,int br_kolona){
	return Matrica(br_redova,std::vector<double>(br_kolona));
}
Matrica RastuciPodnizovi(std::vector<double>vektor){

	Matrica nova;
	for(int i=0;i<vektor.size();i++){
		
		
	}
	
return nova;	
}
int main ()
{
	int vel,n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>vel;
	std::cout<<"Unesite elemente vektora: ";
	
	std::vector<double>vektor;
	while(vel!=0){
		std::cin>>n;
		vektor.push_back(n);
		vel--;
	}
	Matrica mat=RastuciPodnizovi(vektor);
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[0].size();j++)
		std::cout<<mat[i][j]<<" ";
	}
	return 0;
}