/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>
using std::cout;
using std::cin;
using std::vector;
using std::fabs;
using std::abs;
int Provjera(int a)
{
	// if(a==0) return 4; //ponavlja se
	//opak=1 , odvratan=2 , gadan=3
	vector<int> b(10,0);
	int pom;
	int pom1;
	pom1=fabs(a);
	while(pom1>0)
	{
		pom=pom1%3;
		b.at(pom)+=1;
		pom1/=3;
	}
	int brojac1(0),brojac2(0);
	for(int j=0;j<b.size();j++)
	{
		if(b.at(j)%2==0 || b.at(j)==0)
		brojac1++;
		if(b.at(j)%2!=0 || b.at(j)==0)
		brojac2++;
	}
	if(brojac2==b.size())
	return 2;
	if(brojac1==b.size())
	return 1;
	else
	return 3;
	
}
vector<int> IzdvojiGadne(vector<int> vektor,bool vrijednost)
{
//int vel(vektor.size());
vector<int> vektor2;
vector<int> vektor3;
vektor2=vektor;
if(vektor.size()==0)
return vektor3;
for(int i=0;i<vektor2.size()-1;i++)
{
	for(int j=i+1;j<vektor2.size();j++)
	{
		if(vektor2.at(i)==vektor2.at(j))
		{
	//	vektor2.at(j)=0;  //ponavlja se-kako nula oznacava kraj unosa, sigurno nece biti unesena pa NECE predstavljati problem
	vektor2.erase(vektor2.begin()+j);
	j--;
		}
    }
}
if(vrijednost)
{
	for(int j=0;j<vektor2.size();j++)
	{
		if(Provjera(vektor2.at(j))==1)
		vektor3.push_back(vektor2.at(j));
		
	}
}
else
for(int k=0;k<vektor2.size();k++)
{
	if(Provjera(vektor2.at(k))==2)
	vektor3.push_back(vektor2.at(k));
}
return vektor3;
}
int main ()
{
vector<int> vek;
int broj;
cout<<"Unesite brojeve (0 za prekid unosa): ";
while(cin>>broj,broj!=0)
{
vek.push_back(broj);
}
vector<int> vek1;
vek1=IzdvojiGadne(vek,true);
cout<<"Opaki: ";
for(int x: vek1)
{
	cout<<x<<" ";
}
cout<<std::endl;
vek1=IzdvojiGadne(vek,false);
cout<<"Odvratni: ";
for(int x: vek1)
{
	cout<<x<<" ";
}
	return 0;
}