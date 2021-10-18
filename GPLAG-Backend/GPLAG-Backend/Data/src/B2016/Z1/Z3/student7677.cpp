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

Matrica RastuciPodnizovi ( std::vector<double> v ){
	
	Matrica M;
    std::vector<double> pomocni;
	
	for ( int i=0; i<v.size()-1; i++){
		

	return M;
}

/*Matrica OpadajuciPodnizovi ( std::vector<double> v1){
	
	Matrica m;
	std::vector<double> pomocni1;
	
	for(int i=0; i<v1.size()-1; i++){
		 pomocni1.resize(0);
		 int p1;
		 if( v1[i]>=v1[i+1]) p1=v1[i+1];
		 pomocni1.push_back(p1);
	}
	m.push_back(pomocni1);
}*/
int main ()
{
    std::vector<double> vektor;
    int n;
    
	std::cout <<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout << "Unesite elemnte vektora: " << std::endl;
	for (int i=0; i<vektor.size(); i++){
		std::cin>>vektor[i];
	}
	Matrica Max= RastuciPodnizovi(vektor);
	std::cout<<"Rastuci podniz: ";
	for ( int i =0; i<Max.size(); i++){
		for ( int j=0; j<Max[0].size(); j++){
			std::cout<<Max[i][j]<<" ";
		}
	}
	return 0;
}