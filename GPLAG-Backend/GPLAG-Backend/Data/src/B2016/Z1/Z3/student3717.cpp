#include<iostream>
#include<vector>
#include<iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

typedef vector<vector<double>> Matrica;

Matrica RastuciPodnizovi(vector<double> v){
	Matrica rast;
	int m(0);
	for(int i=0; i<v.size()-1; i++){
		if(i<v.size()-1 && v[i]<=v[i+1]){
			while(i<v.size()-1 && v[i]<=v[i+1]){
				i++;
			}
			m++;
		}
	}
	rast.resize(m);
	for(int i=0; i<rast.size(); i++){
		for(int j=0; j<v.size(); j++){
			if(j==v.size()-1 && v[j]<=v[j-1]) break;
			if(j<v.size()-1 && v[j]<=v[j+1]) rast[i].push_back(v[j]);
			if(v.size()>=2 && j==v.size()-2 && v[j]>=v[j-1] && v[j]<=v[j+1]) rast[i].push_back(v[j+1]);
			if(j<v.size()-1 && v[j]>=v[j+1] && j>0 && v[j]>=v[j-1] && j!=v.size()-2){
				rast[i].push_back(v[j]);
				i++;
			}
		}
	}
	return rast;
}

Matrica OpadajuciPodnizovi(vector<double> v){
	Matrica opad;
	int m(0);
	for(int i=0; i<v.size()-1; i++){
		if(i<v.size()-1 && v[i]>=v[i+1]){
			while(i<v.size()-1 && v[i]>=v[i+1]){
				i++;
			}
			m++;
		}
	}
	opad.resize(m);
	for(int i=0; i<opad.size(); i++){
		for(int j=0; j<v.size(); j++){
			if(j==v.size()-1 && v[j]>=v[j-1]) break;
			if(j<v.size()-1 && v[j]>=v[j+1]) opad[i].push_back(v[j]);
			if(v.size()>=2 && j==v.size()-2 && v[j]<=v[j-1] && v[j]>=v[j+1]) opad[i].push_back(v[j+1]);
			if(j<v.size()-1 && v[j]<=v[j+1] && j>0 && v[j]<=v[j-1] && j!=v.size()-2){
				opad[i].push_back(v[j]);
				i++;
			}
		}
	}
	return opad;
}
int main ()
{
	int n;
	vector<double> v;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	v.resize(n);
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		cin>>v[i];
	}
	cout<<"Maksimalni rastuci podnizovi: ";
	cout<<endl;
	Matrica x=RastuciPodnizovi(v);
	for(int i=0; i<x.size(); i++){
		if(x.size()==0) break;
		for(int j=0; j<x[i].size(); j++){
			cout<<x[i][j]<<" ";
		}
		cout<<endl;
	}
	Matrica y=OpadajuciPodnizovi(v);
	cout<<"Maksimalni opadajuci podnizovi: ";
	cout<<endl;
	for(int i=0; i<y.size(); i++){
		if(y.size()==0) break;     
		for(int j=0; j<y[i].size(); j++){
			cout<<y[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}