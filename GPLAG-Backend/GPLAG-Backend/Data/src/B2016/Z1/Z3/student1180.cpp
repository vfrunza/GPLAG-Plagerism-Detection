/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double>v)
{
	Matrica rastuci;
	if(v.size()==0 || v.size()==1) return rastuci;
	else {
		std::vector<double>a;
		for(int i=0; i<v.size(); i++) {
			if(i!=v.size()-1 && v.at(i)<=v.at(i+1)) a.push_back(v[i]);
			else if((i!=0 && i!=v.size()-1 && v.at(i)>=v.at(i+1) && v.at(i)>=v.at(i-1)) || (i==v.size()-1 && v.at(i)>=v.at(i-1))) {
				a.push_back(v[i]);
				if(a.size()>=2) {
					rastuci.push_back(a);
					a.resize(0);
				}
			}
		}
	}
	return rastuci;
}

Matrica OpadajuciPodnizovi(std::vector<double>v)
{
	Matrica opadajuci;
	if(v.size()==0 || v.size()==1) return opadajuci;
	else {
		std::vector<double>b;
		for(int i=0; i<v.size(); i++) {
			if(i!=v.size()-1 && v.at(i)>=v.at(i+1)) b.push_back(v[i]);
			else if((i!=0 && i!=v.size()-1 && v.at(i)<=v.at(i+1) && v.at(i)<=v.at(i-1)) || (i==v.size()-1 && v.at(i)<=v.at(i-1))) {
				b.push_back(v[i]);
				if(b.size()>=2) {
					opadajuci.push_back(b);
					b.resize(0);
				}
			}
		}
	}
	return opadajuci;
}

int main ()
{
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	std::vector<double>v;
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		double el;
		cin>>el;
		v.push_back(el);
	}

	auto a(RastuciPodnizovi(v));
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	for(int i=0; i<a.size(); i++) {
		for(int j=0; j<a.at(i).size(); j++) {
			cout<<std::setprecision(12)<<a.at(i).at(j)<<" ";
		}
		cout<<endl;
	}
	auto b(OpadajuciPodnizovi(v));
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	for(int i=0; i<b.size(); i++) {
		for(int j=0; j<b.at(i).size(); j++) {
			cout<<std::setprecision(12)<<b.at(i).at(j)<<" ";
		}
		cout<<endl;
	}

	return 0;
}