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

typedef vector<vector<double>> Matrica;

Matrica RastuciPodnizovi(vector<double> v){
	Matrica m;
	if(v.size()==0){
		return m;
	}
	else{
		int br(0);
		vector<double> v1;
		for(int i=0;i<v.size()-1;i++){
			br=0;
			while(i<v.size()-1 && v.at(i)<=v.at(i+1)){
				v1.push_back(v[i]);
				i++;
				br++;
			}
			if(br>=1){
				v1.push_back(v[i]);
				m.push_back(v1);
				i--;
			}
			v1.resize(0);
		}
		return m;
	}
}

Matrica OpadajuciPodnizovi(vector<double> v){
	Matrica m;
	if(v.size()==0){
		return m;
	}
	else{
		int br(0);
		vector<double> v1;
		for(int i=0;i<v.size()-1;i++){
			br=0;
			while(i<v.size()-1 && v.at(i)>=v.at(i+1)){
				v1.push_back(v[i]);
				i++;
				br++;
			}
			if(br>=1){
				v1.push_back(v[i]);
				m.push_back(v1);
				i--;
			}
			v1.resize(0);
		}
		return m;
	}
}

int main ()
{
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	vector<double> v;
	cout<<"Unesite elemente vektora: ";
	double broj;
	for(int i=0;i<n;i++){
		cin>>broj;
		v.push_back(broj);
	}
	Matrica m1(RastuciPodnizovi(v));
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	for(int i=0;i<m1.size();i++){
		for(int j=0;j<m1[i].size();j++){
			cout<<m1[i][j]<<" ";
		}
		cout<<endl;
	}
	Matrica m2(OpadajuciPodnizovi(v));
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	for(int i=0;i<m2.size();i++){
		for(int j=0;j<m2[i].size();j++){
			cout<<m2[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}