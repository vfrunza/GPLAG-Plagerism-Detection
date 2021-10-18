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

typedef vector<vector<double>> MATRICA;

MATRICA RastuciPodnizovi(vector<double>v){
  vector<int> v1;
  vector<vector<double>> matrica;
  if(v.size()==0 || v.size() == 1) return matrica;
  
  for (int i=0; i<v.size()-1; i++){
		if (v[i]<=v[i+1]){
			v1.push_back(i);
			int brojac(0);
			int j=i;
			do{
					brojac++; j++;
			} while(j<v.size()-1 && v[j]<=v[j+1]);
				v1.push_back(i+brojac);
				i=i+brojac;
			}
		}
	
vector<int> v2;
for(int i=0; i<v1.size() ;i+=2){
    v2.push_back(1+abs(v1[i]-v1[i+1]));
}

vector<int>v3;
for(int i=0; i<v1.size() ;i+=2){
    v3.push_back(v1[i]);
}


matrica.resize(v2.size());
for(int i=0;i<v2.size();i++) matrica[i].resize(v2[i]);

int brojelemenata=0;
for(int i=0;i<v2.size();i++) brojelemenata+=v2[i];

for(int i=0;i<v2.size();i++){
    for(int j=0;j<v2[i];j++){
        matrica[i][j]=v[j+v3[i]];
    }
}
return matrica;
}

MATRICA OpadajuciPodnizovi(vector<double> v){
vector<int> v1;
vector<vector<double>> matrica;
if(v.size()==0 || v.size() == 1) return matrica;
for (int i=0; i<v.size()-1; i++){
		if (v[i]>=v[i+1]){
			v1.push_back(i);
			int brojac(0);
			int j=i;
			do{
					brojac++; j++;
			} while(j<v.size()-1 && v[j]>=v[j+1]);
				v1.push_back(i+brojac);
				i=i+brojac;
			}
		}
vector<int> v2;
for(int i=0; i<v1.size() ;i+=2){
    v2.push_back(1+abs(v1[i]-v1[i+1]));
}

vector<int>v3;
for(int i=0; i<v1.size() ;i+=2){
    v3.push_back(v1[i]);
}


matrica.resize(v2.size());
for(int i=0;i<v2.size();i++) matrica[i].resize(v2[i]);

int brojelemenata=0;
for(int i=0;i<v2.size();i++) brojelemenata+=v2[i];
for(int i=0;i<v2.size();i++){
    for(int j=0;j<v2[i];j++){
        matrica[i][j]=v[j+v3[i]];
    }
}
  return matrica;
}

int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int br_elemenata;
	cin>>br_elemenata;
	cout<<"Unesite elemente vektora: ";
	double elemenat;
	vector<double> v;
	
	for(int i(0);i<br_elemenata;i++){
		cin>>elemenat;
		v.push_back(elemenat);
	}
	MATRICA fin_mat(RastuciPodnizovi(v));
	MATRICA fin_mat1(OpadajuciPodnizovi(v));
	
	cout<<"Maksimalni rastuci podnizovi: "<<endl;;
	for(int i=0;i<fin_mat.size();i++){
    for(int j=0;j<fin_mat[i].size();j++){
        cout<<fin_mat[i][j]<<" ";
    }
    cout<<endl;
}
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
for(int i=0;i<fin_mat1.size();i++){
    for(int j=0;j<fin_mat1[i].size();j++){
        cout<<fin_mat1[i][j]<<" ";
    }
    cout<<endl;
}	

	return 0;
}