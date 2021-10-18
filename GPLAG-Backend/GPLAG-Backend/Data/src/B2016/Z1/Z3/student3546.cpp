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
using std::vector;

vector<vector<double>> RastuciPodnizovi(vector<double> v){
	vector<vector<double>> rp;
	if(v.size()==0)
	return rp;
	int k(0);
	for(int i=0;i<v.size()-1;i++){
		if(v[i]<=v[i+1]){
			k++;
			rp.resize(k);
			while(i<v.size()-1 && v[i]<=v[i+1]){
				rp[k-1].push_back(v[i]);
				i++;
			}
			if(v[i]>=v[i-1])
			rp[k-1].push_back(v[i]);
		}
	}
	return rp;
}
vector<vector<double>> OpadajuciPodnizovi(vector<double> v){
	vector<vector<double>> op;
	if(v.size()==0)
	return op;
	int k(0);
	for(int i=0;i<v.size()-1;i++){
		if(v[i]>=v[i+1]){
			k++;
			op.resize(k);
			while(i<v.size()-1 && v[i]>=v[i+1]){
				op[k-1].push_back(v[i]);
				i++;
			}
			if(v[i]<=v[i-1])
			op[k-1].push_back(v[i]);
		}
	}
	return op;
}

int main ()
{
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	vector<double> v(n);
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<v.size();i++){
		cin>>v[i];
	}
	vector<vector<double>> rp=RastuciPodnizovi(v);
	vector<vector<double>> op=OpadajuciPodnizovi(v);
	cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0;i<rp.size();i++){
		for(int j=0;j<rp[i].size();j++){
			cout<<rp[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0;i<op.size();i++){
		for(int j=0;j<op[i].size();j++){
			cout<<op[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}