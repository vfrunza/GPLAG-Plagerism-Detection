/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
using std :: cout;
using std :: cin;
using std :: endl;
typedef std:: vector <double> vektor;
typedef std:: vector<std:: vector<double>> matrica;
matrica RastuciPodnizovi(vektor v){
	matrica m;
	int k(0);
	for (int i=0; i< v.size()-1; i++){
		if(v[i]<=v[i+1]){
			m.resize(k+1);
			for (int j=i; j<v.size()-1; j++){
				if(v[j]<=v[j+1]) {m[k].push_back(v[j]); i++;
					if(j+1== v.size()-1)m[k].push_back(v[j+1]);
				}
				else{
					m[k].push_back(v[j]);
					k++;
					break;
				}
			}
		}
		
	}
	return m;
}

matrica OpadajuciPodnizovi(vektor v){
	matrica m;
	int k(0);
	for (int i=0; i< v.size()-1; i++){
		if(v[i]>=v[i+1]){
			m.resize(k+1);
			for (int j=i; j<v.size()-1; j++){
				if(v[j]>=v[j+1]) {m[k].push_back(v[j]); i++;
					if(j+1== v.size()-1) m[k].push_back(v[j+1]);
				}
				else{
					m[k].push_back(v[j]);
					k++;
					break;
				}
			}
		}
		
	}
	return m;
	
}

int main ()
{
	
	cout << "Unesite broj elemenata vektora: ";
	int n;
	cin >> n;
	if(n<0) cout << "Neispravan unos.";
	else{
	vektor v;
	cout << "Unesite elemente vektora: " ;
	for (int i=0; i<n; i++){
		double a;
		cin >> a;
		v.push_back(a);
	}
	
	matrica m= RastuciPodnizovi(v);
	cout << "Maksimalni rastuci podnizovi: "<< endl;
	int max(0);
	for(int i=0; i<m.size(); i++){
		if(m[i].size()>max) max= m[i].size();
			
	}
	for (int i=0; i<m.size(); i++){
		if(m[i].size() ==max){
			for (int j=0; j<m[i].size(); j++) cout << m[i][j]<< " ";
			cout << endl;
		}
	}
	m= OpadajuciPodnizovi(v);
	max=0;
	for(int i=0; i<m.size(); i++){
		if(m[i].size()>max) max= m[i].size();
			
	}
	cout << "Maksimalni opadajuci podnizovi: "<< endl;
	for (int i=0; i<m.size(); i++){
		if(m[i].size() ==max){
			for (int j=0; j<m[i].size(); j++) cout << m[i][j]<< " ";
			cout << endl;
		}
	}
	}
	
	return 0;
}