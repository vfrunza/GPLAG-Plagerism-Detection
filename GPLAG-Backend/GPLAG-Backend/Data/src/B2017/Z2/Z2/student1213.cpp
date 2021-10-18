/*B 2017/2018, Zadaća 2, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <string>
#include <deque>
#include <iomanip>
#include <vector>
#include <type_traits>
#include <stdexcept>
using namespace std;

enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

template<typename T>
void parnitip(T &kont, T &kont1, SmjerKretanja smjerr, int i)
{
	//out<<"ASDADADA";
	typename remove_reference<decltype(kont.at(i))>::type vektor;
	for(int j=0; j<kont.at(i).size(); j++)
			{
				int pom;
				typename remove_reference<decltype(kont.at(i).at(j))>::type mat;
				if(j>kont.at(i).at(j).size()/2) pom=kont.at(i).size()-1-j;
				else pom=j;
				if((int)smjerr==0) for(int k=pom; k<kont.at(i).at(j).size()-pom; k++) mat.push_back(kont.at(j).at(i).at(k));
			 	else if((int)smjerr==2) for(int k=pom; k<kont.at(i).at(j).size()-pom; k++) mat.push_back(kont.at(i).at(j).at(k));
			 	else if((int)smjerr==4) for(int k=pom; k<kont.at(i).at(j).size()-pom; k++) mat.push_back(kont.at(i).at(k).at(j));
				vektor.push_back(mat);
			}
		kont1.push_back(vektor);
}

void unesi(int &n)
{
	for(;;)
	{
		cin>>n;
		if(n<0) cout<<"Dimenzija nije ispravna, unesite opet: ";
		else break;
	}
}

template<typename T>
void neparnitip(T kont, T &kont1, SmjerKretanja smjerr, int i) 
{
	typename remove_reference<decltype(kont.at(i))>::type vektor;
	for(int j=kont.at(i).size()-1; j>=0; j--)
			{
			 	//typename remove_reference<decltype(kont.at(i).at(j))>::type mat;
			 	int pom;
				typename remove_reference<decltype(kont.at(i).at(j))>::type mat;
				if(j>kont.at(i).at(j).size()/2) pom=kont.at(i).size()-1-j;
				else pom=j;
			 	if((int)smjerr==1) 
			 		for(int k=pom; k<kont.at(i).at(j).size()-pom; k++)
			 			mat.push_back(kont.at(j).at(i).at(k));
			 	else if((int)smjerr==3) 
			 			for(int k=pom; k<kont.at(i).at(j).size()-pom; k++)
			 				mat.push_back(kont.at(i).at(j).at(k));
			 	else if((int)smjerr==5) 
			 			for(int k=pom; k<kont.at(i).at(j).size()-pom; k++)
			 				mat.push_back(kont.at(i).at(k).at(j));
			 	vektor.push_back(mat);
			}
		kont1.push_back(vektor);
}

template<typename T>
void unoselementi(T &kont, int n)
{
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++) 
				cin>>kont.at(i).at(j).at(k);
}

template<typename T>
auto PjescaniSat(T kont, SmjerKretanja smjerr) -> typename remove_reference<decltype(kont)>::type
{
	for(int i=0; i<kont.size(); i++){
		for(int j=0; j<kont.at(i).size(); j++){
				if(kont.at(i).size()!=kont.at(i).at(j).size()) throw domain_error("3D matrica nema oblik kocke");
				if(kont.at(i).size()%2==0) throw length_error("3D kontejner ne zadovoljava uvjet neparnosti");
		}
	}
	typename remove_reference<decltype(kont)>::type kont1;
	for(int i=0; i<kont.size(); i++)
	{
		if(((int)smjerr)==0 || ((int)smjerr)==2 || ((int)smjerr)==4)
		{
			parnitip(kont,kont1,smjerr,i);
		}
		else {
			neparnitip(kont,kont1,smjerr,i);
		}
	}
	return kont1;
}

int main ()
{
	int n;
	deque<deque<deque<int>>> kont;
	cout<<"Unesite dimenziju (x/y/z): ";
	unesi(n);
	kont.resize(n);
	for(int i=0; i<n; i++) 
		kont.at(i).resize(n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) 
			kont.at(i).at(j).resize(n);
			
	cout<<"Unesite elemente kontejnera: ";
	unoselementi(kont,n);
			
	cout<<"Unesite smjer kretanja [0 - 5]: ";
	while(1==1)
	{
		cin>>n;
		if(n>5) cout<<"Smjer nije ispravan, unesite opet: ";
		else if(n<0) cout<<"Smjer nije ispravan, unesite opet: ";
		else break;
		
	}
	cout<<endl;
	
	try{
	kont=PjescaniSat(kont,(SmjerKretanja)n);
	cout<<"Pjescani sat unesene matrice je: "<<endl;
	for(int i=0;i<kont.size();i++)
	{   
		int br=kont.at(i).size()/2;
		for(int j=0;j<kont.at(i).size();j++)
		{   
			int sp=j+1;
			if(j>br) {
				sp=kont.at(i).size()-sp; 
				sp+=1;
			}
			for(int k=0;k<kont.at(i).at(j).size();k++)
			{   
					int spejsevi=4;
					if (!(j>0 && j<kont.at(i).size()-1 && k>0 && k<kont.at(i).size()-1)) spejsevi*=sp;
					cout<<setw(spejsevi)<<kont.at(i).at(j).at(k);
			}
			cout<<endl;
		}
		cout<<endl;
	}
	}
	catch(domain_error iz) 
		{cout<<"Izuzetak: "<<iz.what();}
	catch(logic_error iz) 
		{cout<<"Izuzetak: "<<iz.what();}
	return 0; 
}