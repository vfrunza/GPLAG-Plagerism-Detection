/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::vector;
vector<vector<double>> RastuciPodnizovi(vector<double> vektor)
{
vector<vector<double>> konacni;
vector<double> pom;
for(int i=0;i<vektor.size()-1;i++)
{
pom.resize(0);
int temp(0);
if(vektor.size()>=2) //receno u zadatku
{
while(vektor.at(i+1)>=vektor.at(i))
{
if(temp==0)
pom.push_back(vektor.at(i));
pom.push_back(vektor.at(i+1));
temp++;
if(i<vektor.size()-2)
i++;
else
break;
}
if(pom.size()!=0)
konacni.push_back(pom);
}
else
break;
}
return konacni;
}
vector<vector<double>> OpadajuciPodnizovi(vector<double> vektor)
{
vector<vector<double>> konacni;
vector<double> pom;
for(int i=0;i<vektor.size()-1;i++)
{
	pom.resize(0);
	int temp(0);
	if(vektor.size()>=2)
	{
	while(vektor.at(i+1)<=vektor.at(i))
	{
	if(temp==0)	
	pom.push_back(vektor.at(i));
	pom.push_back(vektor.at(i+1));
	temp++;
	if(i<vektor.size()-2)
	i++;
	else
	break;
	}
	if(pom.size()!=0)
	konacni.push_back(pom);
	}
	else
	break;
}
return konacni;
}
int main ()
{
vector<double> vek;
int broj;
cout<<"Unesite broj elemenata vektora: ";
cin>>broj;
vek.resize(broj);
cout<<"Unesite elemente vektora: ";
double pom;
for(int i=0;i<vek.size();i++)
{
	cin>>pom;
	vek.at(i)=pom;
}
auto rastuci(RastuciPodnizovi(vek));
cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
for(int i=0;i<rastuci.size();i++)
{
	for(int j=0;j<rastuci[i].size();j++)
	cout<<rastuci[i][j]<<" ";
	cout<<std::endl;
}
auto opadajuci(OpadajuciPodnizovi(vek));
cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
for(int i=0;i<opadajuci.size();i++)
{
	for(int j=0;j<opadajuci[i].size();j++)
	cout<<opadajuci[i][j]<<" ";
	cout<<std::endl;
}
	return 0;
}