/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

typedef std::vector<std::vector<double>> mvDouble;
typedef std::vector<double> vDouble;

void ispis(mvDouble ulaz){
	for (auto i : ulaz) {
		for (auto j : i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}
}
mvDouble RastuciPodnizovi(vDouble ulaz){
	vDouble tmp;
	mvDouble izlaz;
	if(ulaz.size()==0 || ulaz.size()==1)return izlaz;
	int i;
	for ( i = 0; i < ulaz.size()-1; i++) {
		double trenutni = ulaz.at(i);
		if(ulaz.at(i+1)>=trenutni){
			tmp.push_back(trenutni);
		}
		else{
			tmp.push_back(trenutni);
			if(tmp.size()>1)izlaz.push_back(tmp);
			tmp.clear();
		}
	}
	if(ulaz.at(i)>=ulaz.at(i-1))tmp.push_back(ulaz.at(i));
	if(tmp.size()>1)izlaz.push_back(tmp);
	return izlaz;
}
mvDouble OpadajuciPodnizovi(vDouble ulaz){
	vDouble tmp;
	mvDouble izlaz;
	if(ulaz.size()==0 || ulaz.size()==1)return izlaz;
	int i;
	for ( i = 0; i < ulaz.size()-1; i++) {
		double trenutni = ulaz.at(i);
		if(ulaz.at(i+1)<=trenutni){
			tmp.push_back(trenutni);
		}
		else{
			tmp.push_back(trenutni);
			if(tmp.size()>1)izlaz.push_back(tmp);
			tmp.clear();
		}
	}
	if(ulaz.at(i)<=ulaz.at(i-1))tmp.push_back(ulaz.at(i));
	if(tmp.size()>1)izlaz.push_back(tmp);
	return izlaz;
}
int main ()
{
	int n;
	vDouble ulaz;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	for (int i = 0; i < n; i++) {
		double a;
		cin>>a;
		ulaz.push_back(a);
	}
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	ispis(RastuciPodnizovi(ulaz));
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	ispis(OpadajuciPodnizovi(ulaz));
	return 0;
}