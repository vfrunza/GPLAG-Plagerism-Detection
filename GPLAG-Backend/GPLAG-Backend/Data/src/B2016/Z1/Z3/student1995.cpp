/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<double> vektor;
typedef std::vector<std::vector<double>> matrica;

matrica KreirajMatricu(int red, int kolona){
	return matrica(red, vektor(kolona));
}

matrica RastuciPodnizovi(vektor v){
	 matrica d;
	 for(unsigned i(0);i<=v.size()-1;i++){
	 	for(int x(0);x<d.size();x++){
	for(int j(0);j<d[i].size();j++){
		if(v[i]<v[i+1])
		d[x][j]=v[i];
		
	}
	 	}
	 }
	 return d;

}
int main ()
{
	
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	vektor v(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0);i<n;i++){
		std::cin>>v[i];
	}
	matrica m(RastuciPodnizovi(v));
	std::cout<<"Maksimalni rastuci podnizovi: ";
	for(int i(0);i<m.size();i++)
		for(int j(0);j<m[i].size();j++)
		std::cout<<m[i][j];
	
	
	return 0;
}