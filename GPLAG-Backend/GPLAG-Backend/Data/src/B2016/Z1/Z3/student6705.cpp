/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
using namespace std;
/*
vector<vector<double> > RastuciPodnizovi(vector<double> v){
	vector<vector<double> > mat;
	int brojac(0);
	if(v.size()==0) return mat;
	for(int i=0;i<v.size();i++){
		if(i==0 && v.at(i)<=v.at(i+1) && i!=v.size()-1) mat[brojac].push_back(v.at(i));
		else if(i!=0 && v.at(i)>=v.at(i-1)) mat[brojac].push_back(v.at(i));
		else if(i!=0 && v.at(i)<v.at(i-1) && v.at(i)<=v.at(i+1) && i!=v.size()-1) mat[brojac].push_back(v.at(i));
		else if(i!=0 && v.at(i)>=v.at(i-1)) mat[brojac].push_back(v.at(i));
		if(v.at(i+1)<=v.at(i) && i!=0) brojac++;
	}
	return mat;
}
*/
vector<vector<double> > OpadajuciPodnizovi(vector<double> v){
	vector<vector<double> > mat;
	int brojac(0);
	if(v.size()==0) return mat;
	for(int i=0;i<v.size();i++){
		if(v[i]>=v[i+1] || v[i]<=v[i-1]) mat[brojac].push_back(v[i]);
		if(mat[brojac].size()!=0 && v[i]<v[i+1] && i!=v.size()-1) brojac++;
	}
	return mat;
}

int main ()
{
	vector<double> v;
	int n;
	double a;
	cout<<"Unesite broj elemenata vektora: "<<endl;
	cin>>n;
	cout<<"Unesite elemente vektora: "<<endl;
	for(int i=0; i<n; i++){
		cin>>a;
		v.push_back(a);
	}/*
	vector<vector<double> > matrica1=RastuciPodnizovi(v);
	for(int i=0;i<matrica1.size();i++){
		for(int j=0;j<matrica1[i].size();j++){
			cout<<matrica1[i][j]<<" ";
		}
		cout<<endl;
	} */
	
	vector<vector<double> > matrica2=OpadajuciPodnizovi(v);
	for(int i=0;i<matrica2.size();i++){
		for(int j=0;j<matrica2[i].size();j++){
			cout<<matrica2[i][j]<<" ";
		}
		cout<<endl;
	} 
	return 0;
}