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
#include <iomanip>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

bool periodicna(vector<int> v, int &per)
{
	per=0;
	for(int i=0; i<v.size()-1; i++)
	{
		int pom=1;
		for(int j=i+1; j<v.size(); j++)
			if(v.at(j)==v.at(i)) { pom=j-1; break;}
		bool valja = true;
		for(int j=0; j<v.size()-pom; j++) if(v.at(j)!=v.at(j+pom)) valja=false;
		if(valja) { per=pom; return true;}
	}
	return false;
}

void popunifrag(int ** &mat, int &najduzi, vector<int> &v)
{
	for(int i=0; i<v.size(); i++)
	{
		int pom=najduzi;
		for(int j=v[i]-1; j>=0; j--)
		{
			mat[i][j]=najduzi; najduzi--;
		}
		najduzi=pom;
	}
}

void testperioda(vector<int> &v, int &koliko_puta, int &p)
{
	if(periodicna(v,p))
	{
		koliko_puta=v.size()/p;
		if(v.size()%p!=0) { 
			while(v.size()%p!=0) v.push_back(v.at(v.size()-p));
			koliko_puta++;
		}
	}
	else {
		v.resize(v.size()*2);
		for(int i=0; i<v.size()/2; i++) v.at(i+(v.size()/2))=v.at(i);
	}
}

int **AlocirajFragmentirano(vector<int> &v, int &koliko_puta)
{
	if(v.size()==0) throw logic_error("Prazan vektor!");
	for(int i=0; i<v.size(); i++) if(v.at(i)<=0) throw domain_error("Neispravan vektor!");
	int p;
	testperioda(v,koliko_puta,p);
	int **mat=nullptr;
	int najduzi=-1;
	for(int i=0; i<v.size(); i++) if(v.at(i)>najduzi) najduzi=v.at(i);
	try{
		mat= new int *[v.size()];
		for(int i=0; i<v.size(); i++) mat[i]=nullptr;
		try{
			for(int i=0; i<v.size(); i++) mat[i]=new int[v.at(i)];
			popunifrag(mat,najduzi,v);
			return mat;
		} catch(...){
			for(int i=0; i<v.size(); i++) delete mat[i];
			throw;
		}
	} catch(...) { delete [] mat; throw;}
}

void popunikont(int ** &mat, vector<int> &v)
{
	for(int i=0; i<v.size(); i++)
	{
		int pom=0; 
		for(int j=v.at(i)-1; j>=0; j--){
			mat[i][j]=pom+1;
			pom++;
		}
	}
}

int **AlocirajKontinualno(vector<int> &v, int &koliko_puta)
{
	if(v.size()==0) throw logic_error("Prazan vektor!");
	for(int i=0; i<v.size(); i++) if(v.at(i)<=0) throw domain_error("Neispravan vektor!");
	int p;
	int **mat=nullptr;
	testperioda(v,koliko_puta,p);
	int suma=0;
	for(int i=0; i<v.size(); i++) suma+=v.at(i);
	try{
		mat= new int *[v.size()];
		try{
			mat[0]=new int[suma];
			for(int i=1; i<v.size(); i++){
				int a=v.at(i-1); mat[i]=mat[i-1]+a;
			}
			popunikont(mat,v);
			return mat;
		}
		catch(...) { delete [] mat; throw;}
	} catch(...) { throw;}
}

int main ()
{
	int koliko;
	int n;
	vector<int> v;
	cout<<"Uneiste broj elemenata vektora: ";
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		int pom; cin>>pom; v.push_back(pom);
	}
	cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	cin>>n;
	int **mat=nullptr;
	try{
		if(n==1) mat=AlocirajFragmentirano(v,koliko);
		else if(n==0) mat=AlocirajKontinualno(v,koliko);
		cout<<"Dinamicki alocirana matrica: "<<endl;
		for(int i=0; i<v.size(); i++)
		{
			for(int j=0; j<v.at(i); j++) cout<<setw(3)<<left<<mat[i][j];
			cout<<endl;
		}
		if(n==0) { delete [] mat[0]; delete [] mat; }
		else { 
			for(int i=0; i<v.size(); i++) delete [] mat[i];
			delete [] mat;
		}
	}
	catch(domain_error d) { cout<<"Izuzetak: "<<d.what(); }
	catch(logic_error l) { cout<<"Izuzetak: "<<l.what();}
	catch(...) { cout<<"Memorija"; }
	return 0;
}