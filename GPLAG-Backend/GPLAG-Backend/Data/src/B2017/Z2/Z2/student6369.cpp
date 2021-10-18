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
#include <vector>
#include <string>
#include <deque>
#include <stdexcept>
#include <iomanip>
#include <type_traits>
using namespace std;

enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

template<typename tip>
bool test1 (tip &kont)
{
	for(int i=0; i<kont.size(); i++){
		for(int j=0; j<kont.at(i).size(); j++){
			if(kont.at(i).size()%2==0) return false;
		}
	}
	return true;
}

template<typename tip>
bool test2 (tip &kocka)
{
	for(int i=0; i<kont.size(); i++){
		for(int j=0; j<kont.at(i).size(); j++){
			if(kont.at(i).size()!=kont.at(i).at(j).size()) return false;
		}
	}
	return true;
}

template<typename tip>
auto PjescaniSat(tip kocka, SmjerKretanja s) -> typename remove_reference<decltype(kocka)>::type
{

	if(!test1(kocka)) throw length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	if(!test2(kocka)) throw domain_error("“3D matrica nema oblik kocke");
	typename remove_reference<decltype(kocka)>::type rez;
	for(int i=0; i<kocka.size(); i++)
	{
		int polovina;
		typename remove_reference<decltype(kocka.at(i))>::type pom;
		if(((int)s)%2==0)
		{
			for(int j=0; j<kocka.at(i).size(); j++)
			{
			 	typename remove_reference<decltype(kocka.at(i).at(j))>::type clan;
			 	if(j>kocka.at(i).at(j).size()/2) polovina=kocka.at(i).size()-1-j;
			 	else polovina=j;
			 	for(int k=polovina; k<kocka.at(i).at(j).size()-polovina; k++) {
			 		if((int)s==0)clan.push_back(kocka.at(j).at(i).at(k));
			 		if((int)s==2)clan.push_back(kocka.at(i).at(j).at(k));
			 		if((int)s==4)clan.push_back(kocka.at(i).at(k).at(j));
			 	}
			 	pom.push_back(clan);
			}
		}
		else {
			for(int j=kocka.at(i).size()-1; j>=0; j--)
			{
			 	typename remove_reference<decltype(kocka.at(i).at(j))>::type clan;
			 	if(j>kocka.at(i).at(j).size()/2) polovina=kocka.at(i).size()-1-j;
			 	else polovina=j;
			 	for(int k=polovina; k<kocka.at(i).at(j).size()-polovina; k++) {
			 		if((int)s==1)clan.push_back(kocka.at(j).at(i).at(k));
			 		if((int)s==3)clan.push_back(kocka.at(i).at(j).at(k));
			 		if((int)s==5)clan.push_back(kocka.at(i).at(k).at(j));
			 	}
			 	pom.push_back(clan);
			}
		}
		rez.push_back(pom);
	}
	return rez;
}

int main ()
{
	int n;
	vector<vector<vector<int>>> kocka;
	cout<<"Unesite dimenziju (x/y/z): ";
	while(1==1)
	{
		cin>>n;
		if(n<0) cout<<"Dimenzija nije ispravna, unesite opet: ";
		else break;
		
	}
	kocka.resize(n);
	for(int i=0; i<n; i++) kocka.at(i).resize(n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) 
			kocka.at(i).at(j).resize(n);
		
	cout<<"Unesite elemente kontejnera: ";
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++) cin>>kocka.at(i).at(j).at(k);
			
	cout<<"Unesite smjer kretanja [0 - 5]: ";
	while(1==1)
	{
		cin>>n;
		if(n>5 || n<0) cout<<"Smjer nije ispravan, unesite opet: ";
		else break;
		
	}
	cout<<endl;
	
	try{
	kocka=PjescaniSat(kocka,(SmjerKretanja)n);
	cout<<"Pjescani sat unesene matrice je: "<<endl;
	for(int i=0;i<kocka.size();i++)
	{   
		for(int j=0;j<kocka.at(i).size();j++)
		{   
			int sp=j+1;
			if(j>kocka.at(i).size()/2) sp=kocka.at(i).size()-sp+1;
			for(int k=0;k<kocka.at(i).at(j).size();k++)
			{   
					if(j>0 && j<kocka.at(i).size()-1 && k>0 && k<kocka.at(i).size()-1) cout<<setw(4)<<kocka.at(i).at(j).at(k);
					else cout<<setw((sp)*4)<<kocka.at(i).at(j).at(k);
			}
			cout<<endl;
		}
		cout<<endl;
	}
	}
	catch(domain_error d) {cout<<"Izuzetak: "<<d.what();}
	catch(logic_error l) {cout<<"Izuzetak: "<<l.what();}
	return 0;
}