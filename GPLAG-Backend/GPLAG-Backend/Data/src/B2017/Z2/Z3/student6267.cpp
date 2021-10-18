/*B 2017/2018, Zadaća 2, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

using namespace std;


typedef vector<vector<int>> Matrica;

 void UnistiMatricu(int **mat, int br_redova) {
 if(!mat) return;
 for(int i = 0; i < br_redova; i++) delete[] mat[i];
 delete[] mat;
 }
 


template<typename t1>
bool Test(vector<t1> v){
	if(v.size()==0)return false;
	
		for(int i=0;i<v.size();i++){
		if(v.at(i)<=0)return false;
		
	}
	return true;
	
}

template<typename t1>
bool TestPerioda(vector<t1> v,int p){
	if(p<=0)return false;
	if(int(v.size())-p<=0)return false;
	for(int i=0;i<int(v.size())-p;i++)
		if(v[i]!=v[p+i])return false;
	return true;
}

template<typename t1>
int OdrediOsnovniPeriod (vector<t1> v){
	for(int i=1;i<v.size();i++)
		if(TestPerioda(v,i))return i;
	return 0;
}



template<typename t1>
int **AlocirajKontinualno(vector<t1> &v,int &koliko_puta){
	
	if(v.size()==0)throw domain_error("Prazan vektor!");
	
	for(int i=0;i<v.size();i++){
		if(v.at(i)<=0)throw domain_error("Neispravan vektor!");
	}
	
	int x=OdrediOsnovniPeriod(v);
	
	if(x==0){
		int y=v.size();
		for(int i=0;i<y;i++)
			v.push_back(v.at(i));
			koliko_puta=2;
	}
	else{
		int y=v.size();
		if(y%x!=0){
			int z=y%x;
			for(int i=z;i<x;i++)
			v.push_back(v.at(i));
		}
	}
	
	
 int **a(new int*[v.size()]{});
 
 try {
 for(int i = 0; i < v.size(); i++)
 a[i] = new int[v.at(i)];
 }
 catch(...) {
 UnistiMatricu(a, v.size());
 }

	for(int i=0;i<v.size();i++){
		for(int j=0;j<v.at(i);j++){
			a[i][j]=v.at(i)-j;
		}
	}
	
return a;
}

//----------------------------------

template<typename t1>
int **AlocirajFragmentirano(vector<t1> &v,int &koliko_puta){
	
	if(v.size()==0)throw domain_error("Prazan vektor!");
	
		for(int i=0;i<v.size();i++){
		if(v.at(i)<=0)throw domain_error("Neispravan vektor!");
	}
	
	t1 max=v.at(0);
	for(int i=0;i<v.size();i++)
	if(max<v.at(i))max=v.at(i);
	
	
	int x=OdrediOsnovniPeriod(v);
	
	if(x==0){
		int y=v.size();
		for(int i=0;i<y;i++)
			v.push_back(v.at(i));
			koliko_puta=2;
	}
	else{
		int y=v.size();
		if(y%x!=0){
			int z=y%x;
			for(int i=z;i<x;i++)
			v.push_back(v.at(i));
		}
	}
	
	

	 int **a(new int*[v.size()]{});
 try {
 for(int i = 0; i < v.size(); i++)
 a[i] = new int[v.at(i)];
 }
 catch(...) {
 UnistiMatricu(a, v.size());
 }

	for(int i=0;i<v.size();i++){
		for(int j=0;j<v.at(i);j++){
			a[i][j]=max+j-v.at(i)+1;
		}
	}

	return a;
}


int main ()
{
	
	
	vector<int> v={};
	int k;
	
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	
	cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int s;
	cin>>s;
	if(s==0)
	try{
		if(Test(v))
		cout<<"Dinamicki alocirana matrica:"<<endl;
		int **a=AlocirajKontinualno(v,k);
		
		for(int i=0;i<v.size();i++){
			for(int j=0;j<v.at(i);j++){
				cout<<setw(3)<<left<<a[i][j];
			}cout<<endl;
		}
		UnistiMatricu(a,v.size());
		
	
	}catch(domain_error izuzetak){
		cout<<"Izuzetak: "<<izuzetak.what();
	}
	else try{
		if(Test(v))
		cout<<"Dinamicki alocirana matrica:"<<endl;
		int **a=AlocirajFragmentirano(v,k);
		
		for(int i=0;i<v.size();i++){
			for(int j=0;j<v.at(i);j++){
				cout<<setw(3)<<left<<a[i][j];
			}cout<<endl;
		}
		UnistiMatricu(a,v.size());
	}catch(domain_error izuzetak){
		cout<<"Izuzetak: "<<izuzetak.what();
	}
	
	
	return 0;
}