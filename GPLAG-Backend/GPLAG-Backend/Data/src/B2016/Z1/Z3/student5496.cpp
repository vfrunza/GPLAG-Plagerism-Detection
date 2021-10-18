/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
using std::vector;
typedef std::vector<std::vector<int>> matrica;
matrica RastuciPodniz(vector<int> v){
	matrica V1;
	if(v.size()==0) return V1;
}
matrica OpadajuciPodniz(vector<int> v){
    matrica V2;
    if(v.size()==0) return V2;
}
int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	vector<int> niz;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		int element;
		std::cin>>element;
		niz.push_back(element);
	}
	std::cout<<"Maksimalni rastuci podniz: ";
	matrica e=RastuciPodniz(niz);
    std::cout<<"Maksimalni opadajuci podniz: ";
    matrica f= OpadajuciPodniz(niz);
	return 0;
}