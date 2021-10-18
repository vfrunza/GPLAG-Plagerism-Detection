
#include <iostream>
#include<vector>
#include<string>
#include<deque> 
#include<iomanip>
#include<type_traits>
#include<stdexcept>
#include <string>

using namespace std;

enum class SmjerKretanja{ NaprijedNazad, NaprijedNaprijed, GoreDolje,DoljeGore, LijevoDesno, DesnoLijevo};

template<typename Tip>
int izuz(Tip &kon) {
	for(int i=0;i<kon.size();i++) {
		for(int j=0;j<kon.at(i).size(); j++) {
			if(kon.at(i).size()%2==0) return 1;
			for(int k=0;k<kon.at(i).at(j).size();k++) {
				if(kon.at(i).at(j).size()%2 ==0) return 1;
				if(kon.at(i).at(j).size()!=kon.at(i).size()) return 2;
			}
		}
	}
	return 0;
}

template<typename Tip, typename Tip1>
void popuni(Tip &kon, Tip1 &ploha, SmjerKretanja s, int i, int j){
	int linija;
	if(j>kon.at(i).at(j).size()/2) linija=kon.at(i).size()-1-j;
			else linija=j;
			typename remove_reference<decltype(kon.at(i).at(j))>::type niz;
			for(int k=linija; k<kon.at(i).at(j).size()-linija;k++){
				if((int)s==0) niz.push_back(kon.at(j).at(i).at(k));
				if((int)s==1) niz.push_back(kon.at(j).at(i).at(k));
				if((int)s==2) niz.push_back(kon.at(i).at(j).at(k));
				if((int)s==3) niz.push_back(kon.at(i).at(j).at(k));
				if((int)s==4) niz.push_back(kon.at(i).at(k).at(j));
				if((int)s==5) niz.push_back(kon.at(i).at(k).at(j));
			}
			ploha.push_back(niz);
}

template<typename Tip>
void jotp(Tip &mod, Tip kon, SmjerKretanja s, bool sm, int i)
{
	typename remove_reference<decltype(kon.at(i))>::type ploha;
	if(sm) {
	for(int j=0;j<kon.at(i).size();j++)
		{
			
			popuni(kon,ploha,s,i,j);
		}	
	}
	else {
		for(int j=kon.at(i).size()-1;j>=0;j--){
			popuni(kon,ploha,s,i,j);
		}
	}
	mod.push_back(ploha);
}

template<typename Tip>
auto PjescaniSat (Tip kon , SmjerKretanja s) -> typename remove_reference<decltype(kon)>::type{
	
if(izuz(kon)==1) throw length_error("3D kontejner ne zadovoljava uvjet neparnosti");
if(izuz(kon)==2) throw domain_error ("3D matrica nema oblik kocke");

typename remove_reference<decltype(kon)>:: type mod;

for(int i=0;i<kon.size();i++) {

	if((int)s%2>0) {
		jotp(mod,kon,s, false, i);
	}
	
	else if((int)s%2==0) {
		jotp(mod,kon,s, true, i);
	}
	
}
return mod;
	
}
	
void unesin(int &n, bool a, string rep){
	while(1==1)
	{
		cin>>n;
		if(a && n<=0) cout<<rep;
		else if(!a && (n>5 || n<0)) cout<<rep;
		else break;
		
	}
}

template<typename t>
void kontejner(t &kon, int n){
	kon.resize(n);
	for(int i=0; i<n; i++) 
		kon.at(i).resize(n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) 
			kon.at(i).at(j).resize(n);
}

int main ()
{
	int n;
	vector<vector<vector<int>>> kon;
	cout<<"Unesite dimenziju (x/y/z): ";
	unesin(n,true,"Dimenzija nije ispravna, unesite opet: ");
	
	kontejner(kon,n);
		
	cout<<"Unesite elemente kontejnera: ";
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++) cin>>kon.at(i).at(j).at(k);
			
	cout<<"Unesite smjer kretanja [0 - 5]: ";
	unesin(n,false,"Smjer nije ispravan, unesite opet: ");
	cout<<endl;
	
	try{
	kon=PjescaniSat(kon,(SmjerKretanja)n);
	//cout<<kon.size()<<" "<<kon[0].size()<<" "<<kon[0][0].size()<<endl;
	cout<<"Pjescani sat unesene matrice je: "<<endl;
	
	for(int i=0;i<kon.size();i++)
	{   
		for(int j=0;j<kon.at(i).size();j++)
		{   
			int razmak=0;
			if(j>kon.at(i).size()/2) razmak=kon.at(i).size()-j;
			else razmak=j+1;
			razmak*=4;
			for(int k=0;k<kon.at(i).at(j).size();k++)
			{   
					
					if(j>0 && j<kon.at(i).size()-1 && k>0 && k<kon.at(i).size()-1) razmak=4;
					cout<<setw(razmak)<<kon.at(i).at(j).at(k);
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
	}
	catch(domain_error ex) {cout<<"Izuzetak: "<<ex.what();}
	catch(logic_error e) {cout<<"Izuzetak: "<<e.what();}
	catch(...) {cout<<"Problem";}
}