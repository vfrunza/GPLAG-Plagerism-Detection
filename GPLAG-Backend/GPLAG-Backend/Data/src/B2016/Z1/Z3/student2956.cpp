/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

bool isti(double a,double b, double eps=1e-10){
	return std::fabs(a-b)<=eps*(std::fabs(a)+std::fabs(b));
}

vector<vector<double>>RastuciPodnizovi(vector<double> v)
{
	vector<vector<double>> mat;
	int i(1),x(0);
	int brojac;
	while(i<v.size()){ brojac=1;
		while(i<v.size() && (isti(v[i],v[i-1])||v[i]>=v[i-1])){
			brojac++;
			i++;
		}
		if(brojac>1){
			x++;
			mat.resize(x);
			mat[x-1].resize(brojac);
			for(int j=0;j<brojac;j++)
			mat[x-1][j]=v[i-brojac+j];
		}
		i++;
	}
	return mat;
}

vector<vector<double>>OpadajuciPodnizovi(vector<double>v){
	vector<vector<double>>mat;
	int x(0),i(1);
	int brojac;
	while(i<v.size()){ brojac=1;
		while(i<v.size() && (isti(v[i],v[i-1])||v[i]<=v[i-1])){
			brojac++;
			i++;
		}
		if(brojac>1){
			x++;
			mat.resize(x);
			mat[x-1].resize(brojac);
			for(int j(0);j<brojac;j++)
			mat[x-1][j]=v[i-brojac+j];
		}
		i++;
	}
	return mat;
}




int main()
{
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	vector<double>x(n);
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	cout<<"Maksimalni rastuci podnizovi: ";
	cout<<endl;
	for(auto a:RastuciPodnizovi(x)){
		for(auto y:a) cout<<y<<" ";
		cout<<endl;
	}
	cout<<"Maksimalni opadajuci podnizovi: ";
	cout<<endl;
	for(auto a:OpadajuciPodnizovi(x)){
		for(auto y:a) cout<<y<<" ";
		cout<<endl;
	}
	return 0;
	
}




	
	
