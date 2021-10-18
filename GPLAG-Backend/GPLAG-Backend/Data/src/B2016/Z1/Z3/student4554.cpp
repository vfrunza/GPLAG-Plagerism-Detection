#include <iostream>
#include <vector>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

typedef std::vector<std::vector<double>> Matrica;

void IspisiMatricu(Matrica m) {
	
	for(int i=0; i<m.size(); i++) {
      for(int j=0; j<m[0].size(); j++) {
         cout << std::setprecision(12) << m[i][j] << " ";
      }
      cout << endl;
   }
}

std::vector<double> daj_vektor(std::vector<double>v, int poc, int koliko_mjesta){
	
	std::vector<double>podniz;
	
	for(int i=poc; i<=poc+koliko_mjesta; i++) {
		podniz.push_back(v[i]);
	}
	return podniz;
}

Matrica RastuciPodnizovi(std::vector<double> v) {
	
	Matrica rastuca;
	int koliko_mjesta,poc;
	
	if(!v.size())
		return rastuca;
	
	for(int i=0; i<v.size()-1; i++) {
		koliko_mjesta=0;
		if(i+1<v.size() && v[i]<=v[i+1]) {
			poc=i;
			while(i+1<v.size() && v[i]<=v[i+1]) {
				koliko_mjesta++;
				i++;
			}
			rastuca.push_back(daj_vektor(v,poc,koliko_mjesta));
		}
	}
	return rastuca;
}

Matrica OpadajuciPodnizovi(std::vector<double> v) {
	
	Matrica opadajuca;
	int koliko_mjesta,poc;
	
	if(!v.size())
		return opadajuca;
	
	for(int i=0; i<v.size()-1; i++) {
		koliko_mjesta=0;
		if(i+1<v.size() && v[i]>=v[i+1]) {
			poc=i;
			while(i+1<v.size() && v[i]>=v[i+1]) {
				koliko_mjesta++;
				i++;
			}
			opadajuca.push_back(daj_vektor(v,poc,koliko_mjesta));
		}
	}
	return opadajuca;
}

int main ()
{
	int n;
	
	cout << "Unesite broj elemenata vektora: ";
	cin >> n;
	
	cout << "Unesite elemente vektora: ";
	
	double broj;
	std::vector<double> v(n);
	
	for (int i=0; i<n; i++) {
		cin >> broj;
		v[i] = broj;
	}
	
	cout << "Maksimalni rastuci podnizovi: " << endl;
	IspisiMatricu(RastuciPodnizovi (v));
	
	cout << "Maksimalni opadajuci podnizovi: " << endl;
	IspisiMatricu(OpadajuciPodnizovi (v));
	
	return 0;
}