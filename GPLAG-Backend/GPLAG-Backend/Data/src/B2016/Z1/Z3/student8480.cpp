/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;


std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double>v)
{
	std::vector<std::vector<double>> rezultat;
	std::vector<double>MaliNiz;

	bool kraj;
	int i(0);

	while(i<v.size()) {
		kraj=true;
		if(i<v.size()-1 && v.at(i)<=v.at(i+1)) {
			MaliNiz.push_back(v.at(i));
			kraj=false;
		}

		if(kraj) {
			MaliNiz.push_back(v.at(i));
			if(MaliNiz.size()>=2) rezultat.push_back(MaliNiz);
			MaliNiz.clear();
		}
		i++;
	}
	return rezultat;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double>v)
{
	std::vector<std::vector<double>>rezultat;
	std::vector<double>MaliNiz;

	bool kraj;
	int i=0;

	while(i<v.size()) {
		kraj=true;
		if(i<v.size()-1 && v.at(i+1)<=v.at(i)) {
			MaliNiz.push_back(v.at(i));
			kraj=false;
		}

		if(kraj) {
			MaliNiz.push_back(v.at(i));
			if(MaliNiz.size()>=2)	rezultat.push_back(MaliNiz);
			MaliNiz.clear();
		}
		i++;
	}
	return rezultat;
}

int main ()
{
	int n;
	std::vector<double> v;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;

	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		int broj;
		cin>>broj;
		v.push_back(broj);
	}

	std::vector<std::vector<double>>a(RastuciPodnizovi(v));
	std::vector<std::vector<double>>b(OpadajuciPodnizovi(v));


	cout<<"Maksimalni rastuci podnizovi: "<<"\n";

	for(int i=0; i<a.size(); i++) {
		for(int j=0; j<a[0].size(); j++) {
			cout<<a.at(i).at(j)<<" ";
		}
		cout<<"\n";
	}

	cout<<"Maksimalni opadajuci podnizovi: "<<"\n";

	for(int i=0; i<b.size(); i++) {
		for(int j=0; j<b[0].size(); j++) {
			cout<<b.at(i).at(j)<<" ";
		}
	}
	return 0;

}