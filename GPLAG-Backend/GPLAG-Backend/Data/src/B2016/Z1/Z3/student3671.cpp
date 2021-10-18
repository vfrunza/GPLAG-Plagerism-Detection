/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
using namespace std;

vector<vector<double>>RastuciPodnizovi(vector<double>v){
	vector<vector<double>> f;
	for(int i=0;i<v.size();i++){
		vector<double>g(1,v[i]);
		for(int j=i+1;j<v.size();j++){
			if((v[j]>=v[i])){
			g.push_back(v[j]);
			i++;
			}
			else break;
		}
		if(g.size()>1)
		f.push_back(g);
	}
	return f;
}

vector<vector<double>>OpadajuciPodnizovi(vector<double>v){
	vector<vector<double>>h;
	for(int i=0;i<v.size();i++){
		vector<double>vek(1,v[i]);
		for(int j=i+1;j<v.size();j++){
			if(v[j]<=v[i]){
			vek.push_back(v[j]);
			i++;
			}
			else break;
		}
		if(vek.size()>1)
		h.push_back(vek);
	}
	return h;
}


int main ()
{
	int n;
	vector<double>v;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		int element;
		cin>>element;
		v.push_back(element);
	}
	vector<vector<double>> f;
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	f=RastuciPodnizovi(v);
	for(int i=0;i<f.size();i++){
		for(int j=i;j<f[i].size();j++){
			cout<<f[i][j]<<" ";
		}
		cout<<endl;
	}
	vector<vector<double>> h;
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	h=OpadajuciPodnizovi(v);
	for(int i=0;i<h.size();i++){
		for(int j=i;j<h[i].size();j++){
			cout<<h[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}