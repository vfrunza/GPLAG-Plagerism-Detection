#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
typedef vector<vector<double>>  nizNizova;
// dodaj podniz u rastuci niz
nizNizova DodajRadniNizURastuciNiz(nizNizova rastuciPodnizovi,vector<double> radniNiz)
{
rastuciPodnizovi.resize(rastuciPodnizovi.size()+1);
rastuciPodnizovi[rastuciPodnizovi.size()-1].resize(radniNiz.size());
for(int i=0;i<radniNiz.size();i++)
rastuciPodnizovi[rastuciPodnizovi.size()-1][i]=radniNiz[i];
return rastuciPodnizovi;
}
// brisanje radnog niza
 vector<double> PrebrisiradniNiz(vector<double> radniNiz)
 {
while(radniNiz.size()>0)
radniNiz.erase(radniNiz.begin());
return radniNiz;


}

nizNizova RastuciPodnizovi(vector<double> inicijalniNiz)
{
vector<double> radniNiz;
nizNizova rastuciPodnizovi;
for(int i=0;i<inicijalniNiz.size();i++)
{
if(radniNiz.size()==0)
radniNiz.push_back(inicijalniNiz[i]);
else
{ if(inicijalniNiz[i]>=radniNiz[radniNiz.size()-1])
radniNiz.push_back(inicijalniNiz[i]);
if(i==inicijalniNiz.size()-1)
{
if(radniNiz.size()>1)
{
rastuciPodnizovi=DodajRadniNizURastuciNiz(rastuciPodnizovi,radniNiz);
radniNiz=PrebrisiradniNiz(radniNiz);
}
}
else if(inicijalniNiz[i]<radniNiz[radniNiz.size()-1])
{
if(radniNiz.size()>1)
rastuciPodnizovi=DodajRadniNizURastuciNiz(rastuciPodnizovi,radniNiz);
radniNiz=PrebrisiradniNiz(radniNiz);
radniNiz.push_back(inicijalniNiz[i]);
}
}
}
return rastuciPodnizovi;
}

nizNizova OpadajuciPodnizovi(vector<double> inicijalniNiz)
{
vector<double> radniNiz;
nizNizova opadajuciPodnizovi;
for(int i=0;i<inicijalniNiz.size();i++)
{
if(radniNiz.size()==0)
radniNiz.push_back(inicijalniNiz[i]);
else
{ if(inicijalniNiz[i]<=radniNiz[radniNiz.size()-1])
radniNiz.push_back(inicijalniNiz[i]);
if(i==inicijalniNiz.size()-1)
{
if(radniNiz.size()>1)
{
opadajuciPodnizovi=DodajRadniNizURastuciNiz(opadajuciPodnizovi,radniNiz);
radniNiz=PrebrisiradniNiz(radniNiz);
}
}
else if(inicijalniNiz[i]>radniNiz[radniNiz.size()-1])
{
if(radniNiz.size()>1)
opadajuciPodnizovi=DodajRadniNizURastuciNiz(opadajuciPodnizovi,radniNiz);
radniNiz=PrebrisiradniNiz(radniNiz);
radniNiz.push_back(inicijalniNiz[i]);
}
}
}
return opadajuciPodnizovi;
}
// funkcija vraca broj redova nizanizova
int BrojRedova(nizNizova n)
{

return n.size();
}
//funkcija ispisuje niz nizova
void IspisiNizNizova(nizNizova rastuciPodnizovi)
{
for(int i=0;i<BrojRedova(rastuciPodnizovi);i++){
for(int j=0;j<rastuciPodnizovi[i].size();j++)
cout<<rastuciPodnizovi[i][j]<<" ";
cout<<endl;
}
}
int main ()
{
int brojelemenata;	
vector<double> inicijalniNiz;
nizNizova rastuciPodnizovi;
nizNizova opadajuciPodnizovi;
cout<<"Unesite broj elemenata vektora: ";
cin>>brojelemenata;
cout<<"Unesite elemente vektora: ";
for(int i=0;i<brojelemenata;i++)
{   int broj;
	cin>>broj;
	inicijalniNiz.push_back(broj);
	
}	
rastuciPodnizovi=RastuciPodnizovi(inicijalniNiz);
cout<<"Maksimalni rastuci podnizovi: "<<endl;
IspisiNizNizova(rastuciPodnizovi);
cout<<endl;
opadajuciPodnizovi=OpadajuciPodnizovi(inicijalniNiz);
cout<<"Maksimalni opadajuci podnizovi: "<<endl;
IspisiNizNizova(opadajuciPodnizovi);
cout<<endl;	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}