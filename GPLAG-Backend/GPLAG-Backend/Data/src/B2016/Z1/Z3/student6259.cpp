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
using std::endl;
using std::vector;

vector<vector<double>> RastuciPodnizovi(vector<double>a) {
	vector<vector<double>>nizovi;
	
	for(int i(0); i<a.size()-1; i++) {
		int ii=i;
		if(a.at(i)<=a.at(i+1)) {
				nizovi.resize(nizovi.size()+1);
				nizovi.at(nizovi.size()-1).push_back(a.at(i));
				for(int j=i; j<a.size()-1; ++j) {
					ii=j;
					if(a.at(j)<=a.at(j+1)) nizovi.at(nizovi.size()-1).push_back(a.at(j+1));
					else break;
				}
		}
		i=ii;
	}
	
	return nizovi;
}

vector<vector<double>> OpadajuciPodnizovi(vector<double>a) {
	vector<vector<double>>nizovi;
	
	for(int i(0); i<a.size()-1; i++) {
		int ii=i;
		if(a.at(i)>=a.at(i+1)) {
			nizovi.resize(nizovi.size()+1);
			nizovi.at(nizovi.size()-1).push_back(a.at(i));
			for(int j=i; j<a.size()-1; ++j) {
				ii=j;
				if(a.at(j)>=a.at(j+1)) nizovi.at(nizovi.size()-1).push_back(a.at(j+1));
				else break;
			}
		}
		i=ii;
	}
	
	return nizovi;
}

void ispisi_nizove(vector<vector<double>> a) {
	for(int i(0); i<a.size(); i++) {
		for(int j(0); j<a.at(i).size(); j++) {
			//if(j!=a.size()-1) cout<<a[i][j]<<" ";
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main ()
{	
	int n, broj;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	
	vector<double>vektor;
	//vector<vector<double>> a;
	
	cout<<"Unesite elemente vektora: ";
	for(int i(0); i<n; i++) {
		cin>>broj;
		vektor.push_back(broj);
	}
	
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	ispisi_nizove(RastuciPodnizovi(vektor));
	cout<<"Maksimalni opadajuci podnizovi:"<<endl;
	ispisi_nizove(OpadajuciPodnizovi(vektor));
	
	return 0;
}