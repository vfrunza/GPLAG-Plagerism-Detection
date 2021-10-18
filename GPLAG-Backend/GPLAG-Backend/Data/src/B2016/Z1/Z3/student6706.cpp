/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<vector>
#include<iostream>
using namespace std;
typedef vector<vector<double>>mat;
mat RastuciPodnizovi(vector<double> c){
	mat m;
	int j=0, brojredova=0;
	for(int i=j; i<c.size(); i++){
		if(j==c.size()-1) break;
		vector<double>a;
		while(j<c.size()-1){
			if(c[j]<=c[j+1]) a.push_back(c[j]);
			if(j!=0 && c[j]>c[j+1] && c[j]>=c[j-1]) {a.push_back(c[j]); j++; break;}
			else if (c[j]>c[j+1]) {j++; break;}
			j++;
		}
		if(j==c.size()-1 && c[j]>=c[j-1]) a.push_back(c[j]); 
		if(a.size()>0) brojredova++;
		if(a.size()>=2){
			m.resize(brojredova);
			for(int b=brojredova-1; b<m.size(); b++) m[b].resize(a.size());
			for(int b=brojredova-1; b<m.size(); b++){
				for(int d=0; d<m[b].size(); d++){
					m[b][d]=a[d];
				}
			}
		}
	}
	return m;
}
mat OpadajuciPodnizovi(vector<double> c){
	mat m;
	int j=0, brojredova=0;
	for(int i=j; i<c.size(); i++){
		if(j==c.size()-1) break;
		vector<double>a;
		while(j<c.size()-1){
			if(c[j]>=c[j+1]) a.push_back(c[j]);
			if(j!=0 && c[j]<c[j+1] && c[j]<=c[j-1]) {a.push_back(c[j]); j++; break;}
			else if (c[j]<c[j+1]) {j++; break;}
			j++;
		}
		if(j==c.size()-1 && c[j]<=c[j-1]) a.push_back(c[j]); 
		if(a.size()>0) brojredova++;
		if(a.size()>=2){
			m.resize(brojredova);
			for(int b=brojredova-1; b<m.size(); b++) m[b].resize(a.size());
			for(int b=brojredova-1; b<m.size(); b++){
				for(int d=0; d<m[b].size(); d++){
					m[b][d]=a[d];
				}
			}
		}
	}
	return m;
}
int main(){
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	vector<double> c(n);
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<c.size(); i++) cin>>c[i];
	mat m;
	m=RastuciPodnizovi(c);
	cout<<"Maksimalni rastuci podnizovi:"<<endl;
	for(int i=0; i<m.size(); i++){
	for(int j=0; j<m[i].size();j++){
		cout<<m[i][j]<<" ";
	}
	cout<<endl;
	}
	m=OpadajuciPodnizovi(c);
	cout<<"Maksimalni opadajuci podnizovi:"<<endl;
	for(int i=0; i<m.size(); i++){
	for(int j=0; j<m[i].size();j++){
		cout<<m[i][j]<<" ";
	}
	cout<<endl;
	}
	
	
	return 0;
}
