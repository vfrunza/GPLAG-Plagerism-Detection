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

vector<vector<double>> RastuciPodnizovi(vector<double> v){
	vector<vector<double>> v1;
	for(int i=0; i<v.size(); i++)
		for(int j=0; j<v.size(); j++){
			if(v[i]<v[i-1])
			v1[i][j]=v[i];
		}

	return v1;
	
}

int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int n; cin>>n; cin.ignore(1000, '\n');
	vector<double> v; 
	if(n==0 || n<0) cout<<"Broj treba biti pozitivan.";
    if(n>0){
	      cout<<"Unesite elemente vektora: ";
	      for(int i=0; i<n; i++) cin>>v[i];
	      vector<double> v1;
	      v1=(v);
	      cout<<"Maksimalni rastuci podnizovi: "<<endl;
	      for(int x:v1) cout<<x<<" ";
	      vector<double> v2;
	      v2=(v);
	      cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	      for(int x:v2) cout<<x<<" ";
    }
	return 0;
}