/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
bool ProstiBrojevi(int p) 
{
	int prosti=true;
	if(p==2) 
	{
		return true;
	}
	else 
	{
		for(int i=3;i<p-1;i++)
		{ 
			if(p%i==0) 
			{
				prosti=false;
				break;
			}
	}
	if(prosti==true) 
	{
		return true;
	}
	else
	return false;
}
}

int ObrnutaSuma(int p) 
{
	int suma=0;
	while(p>0)
	{
		suma=suma*10+p%10;
		p/=10;
	}
	return suma;
}


vector<int> IzdvojiSimetricneTernarne(vector<int>c,bool p) {
	vector<int>d;
	if(p==false)
	for(int i=0;i<c.size();i++){
		if(!(ProstiBrojevi(fabs(c.at(i)))))
		d.push_back(c.at(i));
	}
	else if(p==true)
	for(int i=0;i<c.size();i++) {
		if(ProstiBrojevi(fabs(c.at(i))))
		d.push_back(c.at(i));
	}
	
	for(int i=0;i<d.size();i++) {
		int ternarni=fabs(d.at(i));
	
	int br{1};
	int suma{0};
	while(ternarni!=0) 
	{
		suma=suma+br*(ternarni%3);
		ternarni=ternarni/3;
		br=br*10;
	}
	
	if(suma!=ObrnutaSuma(suma)) {
		for(int j=i;j<d.size()-1;j++) {
			d.at(j)==d.at(j+1);
		}
		
		i--;
		d.resize(d.size()-1);
	}
	
}


for(int i=0;i<d.size();i++) {
	if(i!=d.size())
	for(int j=i+1;j<d.size();j++) {
		if(d.at(j)==d.at(i)) {
			for(int m=j;m<d.size()-1;m++) {
				d.at(m)=d.at(m+1);
			}
			j--;
			d.resize(d.size()-1);
		}
	}
}
return d;
}

int main() {
	
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	vector<int>c;

 	
for(int i=3;i<8;) {
	int p;
	cin>>p;
	if(p!=-1)
	c.push_back(p);
	else break;
}

	
	int a;
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for(int i=3;i<8;) {
		cin>>a;
		if(a!=1 && a!=0)
		cout<<"Neispravan unos! Unesite ponovo: ";
		else break;
	}
	
	
	c=IzdvojiSimetricneTernarne(c,a);
	if(a==true && c.size()==0)
	cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else if(a==false && c.size()==0)
	cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	else {
		if(a==true && c.size()!=0 ) cout<<"Prosti simetricni brojevi iz vektora su: ";
		if(a==false && c.size()!=0) cout<<"Slozeni simetricni brojevi iz vektora su: ";
	
		for(int i=0;i<c.size();i++)
		{
			cout<<c.at(i);
if(i!=c.size()-1) cout<<", ";
else cout<<"."<<endl;
		}
	}
	
	


return 0;

}
