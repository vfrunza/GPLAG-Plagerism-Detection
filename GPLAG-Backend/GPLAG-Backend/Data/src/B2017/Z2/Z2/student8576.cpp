#include <iostream>
#include <vector>
#include <stdexcept>
#include <deque>
#include <iomanip>
using namespace std;
enum class SmjerKretanja{ NaprijedNazad=0, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};
template <typename Tip2D>
Tip2D GD(Tip2D &c){
	int n(c.size());
	Tip2D x(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j>=i && j<n-i) x.at(i).push_back(c.at(i).at(j));
			else if(j>=n-1-i && j<=i) x.at(i).push_back(c.at(i).at(j));
		}
	}
	return x;
}
template <typename Tip2D>
Tip2D DG(Tip2D &c){
	int n(c.size());
	Tip2D x(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j>=i && j<n-i) x.at(i).push_back(c.at(n-1-i).at(j));
			else if(j>=n-1-i && j<=i) x.at(i).push_back(c.at(n-1-i).at(j));
		}
	}
	return x;
}
template <typename Tip2D>
Tip2D LD(Tip2D &c){
	int n(c.size());
	Tip2D x(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			x.at(i).push_back(c.at(j).at(i));
		}
	}
	Tip2D y(GD(x));
	return y;
}
template <typename Tip2D>
Tip2D DL(Tip2D &c){
	int n(c.size());
	Tip2D x(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			x.at(i).push_back(c.at(j).at(i));
		}
	}
	Tip2D y(DG(x));
	return y;
}
template <typename Tip>
Tip PjescaniSat(Tip &kont, SmjerKretanja s){
	int duz(kont.size());
	for(int i=0;i<duz;i++){
		if(kont.at(i).size()!=duz) throw domain_error("3D matrica nema oblik kocke");
	}
	int sir(kont.at(0).size());
	for(int i=0;i<duz;i++){
		for(int j=0;j<sir;j++)
		if(kont.at(i).at(j).size()!=sir) throw domain_error("3D matrica nema oblik kocke");
	}
	if(duz%2==0 || sir%2==0) throw length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	Tip kontejner(kont.size());
	if(s==SmjerKretanja::GoreDolje){
	for(int i=0;i<kont.size();i++)
	kontejner.push_back(GD(kont.at(i)));
	}
	else if(s==SmjerKretanja::DoljeGore){
	for(int i=0;i<kont.size();i++)
	kontejner.push_back(DG(kont.at(i)));	
	}
	else if(s==SmjerKretanja::DesnoLijevo){
	for(int i=0;i<kont.size();i++)
	kontejner.push_back(DL(kont.at(i)));		
	}
	else if(s==SmjerKretanja::LijevoDesno){
	for(int i=0;i<kont.size();i++)
	kontejner.push_back(LD(kont.at(i)));	
	}
	/*else if(s==SmjerKretanja::NaprijedNazad){
	for(int i=0;i<kont.size();i++)
	for(int j=0;j<kont.size()/2+1;j++)
	kontejner.at(j).at(i).push_back(kont.at(j).at(i).at(j));
	
	}*/	
	return kontejner;
}
int main ()
{
	/*vector<vector<vector<int>>> v{{{1,8,6},{2,3,5},{4,2,3}},{{1,2,3},{2,3,4},{3,4,5}},{{1,2,3},{2,3,4},{3,4,5}}};
	vector<vector<vector<int>>> x(PjescaniSat(v,SmjerKretanja::DesnoLijevo));
	for(int i=0;i<x.size();i++){
		for(int j=0;j<x.at(i).size();j++){
			for(int k=0;k<x.at(i).at(j).size();k++){
				cout<<x.at(i).at(j).at(k);
			}
			cout<<endl;
		}
		cout<<endl;
	}*/
	cout<<"Unesite dimenziju (x/y/z): ";
	int n;
	cin>>n;
	while(n<=0){
		cout<<"Dimenzija nije ispravna, unesite opet: ";
		cin>>n;
	}
	cout<<"Unesite elemente kontejnera: ";
	vector<deque<deque<int>>> mat(n,deque<deque<int>>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
			int x;
			cin>>x;
			mat.at(i).at(j).push_back(x);
			}
		}
	}
	cout<<"Unesite smjer kretanja [0 - 5]: ";
	int a;
	cin>>a;
	while(a<0 || a>5){
		cout<<"Smjer nije ispravan, unesite opet: ";
		cin>>a;
	}
	try{
	vector<deque<deque<int>>> matrica(PjescaniSat(mat,SmjerKretanja(a)));
	cout<<endl<<"Pjescani sat unesene matrice je: ";
	for(int i=0;i<matrica.size();i++){
		for(int j=0;j<matrica.at(i).size();j++){
			for(int k=0;k<(matrica.at(i).size()-matrica.at(i).at(j).size())/2;k++) cout<<setw(4)<<" ";
			for(int k=0;k<matrica.at(i).at(j).size();k++){
			cout<<setw(4)<<matrica.at(i).at(j).at(k);
			}
			cout<<endl;
		}
		cout<<endl;
	}
	}catch(domain_error izuzetak){
		cout<<endl<<"Izuzetak: "<<izuzetak.what();
	}
	catch(length_error izuzetak){
		cout<<endl<<"Izuzetak: "<<izuzetak.what();
	}
	
	return 0;
}