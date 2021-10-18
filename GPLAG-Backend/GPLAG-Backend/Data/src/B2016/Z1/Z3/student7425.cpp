#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<double>> RastuciPodnizovi(vector<double> v) {
	vector<vector<double>> mat;
	for(int i=0;i<v.size()-1;i++) {
		vector<double> v1;
		bool a=false;
		while(i<v.size()-1 &&v[i]<=v[i+1] ) {
			a=true;
			v1.push_back(v[i]);
			i++;
		}
		if(a==true && i<v.size()) {
			v1.push_back(v[i]);
			mat.push_back(v1);
		}
	}
	return mat;
}

vector<vector<double>> OpadajuciPodnizovi(vector<double> v) {
	vector<vector<double>> mat;
	for(int i=0;i<v.size()-1;i++) {
		vector<double> v1;
		bool a=false;
		while(i<v.size()-1 &&v[i]>=v[i+1] ) {
			a=true;
			v1.push_back(v[i]);
			i++;
		}
		if(a==true && i<v.size()) {
			v1.push_back(v[i]);
			mat.push_back(v1);
		}
	}
	return mat;
}

int main ()
{
	vector<double> v;
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	v.resize(n);
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<v.size();i++) {
		cin>>v[i];
	}
	vector<vector<double>> mat1=RastuciPodnizovi(v), mat2=OpadajuciPodnizovi(v);
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	for(int i=0;i<mat1.size();i++) {
		for(int j=0;j<mat1[i].size();j++) {
			cout<<mat1[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	for(int i=0;i<mat2.size();i++) {
		for(int j=0;j<mat2[i].size();j++) {
			cout<<mat2[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}