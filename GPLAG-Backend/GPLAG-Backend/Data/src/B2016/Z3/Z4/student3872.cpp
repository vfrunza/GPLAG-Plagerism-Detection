/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include<stdexcept>
#include<vector>
#include<set>
#include<list>
#include<algorithm>
#include<string>
#include<iomanip>
using namespace std;
int DuzinaImena(string ime)
{
    
    int brojac(0);
    for(int i=0;i<ime.length();i++)
    {
        if((ime[i]>='A' && ime[i]<='Z') || (ime[i]>='a' && ime[i]<='z') || (ime[i]>='0' && ime[i]<='9'))
        brojac++;
    }
    return brojac;
}
vector<set<string>> Razvrstavanje( const vector<string> &ImenaDjece, int broj_timova)
 {
     if(broj_timova<1 || broj_timova>ImenaDjece.size()) throw logic_error("Razvrstavanje nemoguce");
    vector<set<string>> Krajnji;
    set<string> temp;
     list<string> lista_djece;
     for(int i=0;i<ImenaDjece.size();i++)
     lista_djece.push_back(ImenaDjece[i]);
    
     int br_tim=ImenaDjece.size()%broj_timova;
     int broj_clanove(0), broj_timove(0);
     int obican_broj_timova(ImenaDjece.size()/broj_timova);
    int broj_timova_s_vise_djece(ImenaDjece.size()/broj_timova);
    if(br_tim!=0) broj_timova_s_vise_djece++;
     auto it(lista_djece.begin());
     while(!lista_djece.empty())
     {
         int broj(DuzinaImena(*it));
         temp.insert(*it);
         it=lista_djece.erase(it);
         if(it==lista_djece.end())
            it=lista_djece.begin();
            broj_clanove++;
            if(broj_clanove==broj_timova_s_vise_djece)
            {
                Krajnji.push_back(temp);
                broj_clanove=0;
                broj_timove++;
                temp.clear();
            }
            else if(broj_clanove== obican_broj_timova && broj_timove>= br_tim)
            {
                Krajnji.push_back(temp);
                broj_clanove=0;
                temp.clear();
            }
            for(int i(1);i<broj;i++)
            {
                it++;
                if(it==lista_djece.end())
                it=lista_djece.begin();
            }
     }
     return Krajnji;
 }
int main ()
{
    vector<string> djeca;
	int broj_djece;
	cout<<"Unesite broj djece: ";
	cin>>broj_djece;
	
	cin.ignore(1000,'\n');
	cout<<"Unesite imena djece: "<<endl;
	
	for(int i=0;i<broj_djece;i++)
	{
	    string ime;
	    getline(cin, ime);
	    djeca.push_back(ime);
	}
	cout<<"Unesite broj timova: ";

	int broj_timova;
	cin>>broj_timova;
	try
	{
	vector<set<string>> Rezultat;
	Rezultat=Razvrstavanje(djeca, broj_timova);
	int temp(0);
  for(int i=0;i<Rezultat.size();i++)
  {
      cout<<"Tim "<<temp+1<<": ";
      int pom(Rezultat[i].size());
      int brojac(0);
      for(auto p(Rezultat[i].begin());p!=Rezultat[i].end();p++)
      {
          cout<<*p;
          brojac++;
          if(brojac!=pom)
          cout<<", ";
      }
      temp++;
      cout<<endl;
      
  } 
	}
	catch(logic_error izuzetak)
	{
	    cout<<"Izuzetak: "<<izuzetak.what();
	}
  return 0;
	

	return 0;
	
}