/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <stdexcept>
//#include <cstring>
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::map;
using std::set;
bool Provjera(char a)
{
    if((a>='a' && a<='z') || (a>='A' && a<='Z') || (a>='0' && a<='9'))
    return true;
    return false;
}
vector<string> PovadiRijeci(string recenica)
{
    vector<string> rijeci;
    
    for(int i=0;i<recenica.size();i++)
    {
        if(i==0 && i<recenica.size())
        {
            string pom;
            while(!Provjera(recenica[i]) && i<recenica.size())
            i++;
            if(i!=recenica.size())
            {
                while(Provjera(recenica[i]))
                {
                    pom.push_back(recenica[i]);
                    i++;
                    if(i==recenica.size())
                    break;
                }
            }
            for(int j=0;j<pom.size();j++)
            {
                if(pom[j]>='A' && pom[j]<='Z')
                {
                    pom[j]=pom[j]-('A'-'a');
                }
            }
            if(pom.size()!=0)
            rijeci.push_back(pom);
        }
        if(i<recenica.size() && i!=0)
        {
            string pom;
            if(!Provjera(recenica[i-1]))
            {
                while(!Provjera(recenica[i]) && i<recenica.size())
                i++;
                if(i!=recenica.size())
                {
                    while(Provjera(recenica[i]) && i<recenica.size())
                    {
                        pom.push_back(recenica[i]);
                        i++;
                    }
                    for(int j=0;j<pom.size();j++)
                    {
                        if(pom[j]>='A' && pom[j]<='Z')
                        {
                            pom[j]=pom[j]-('A'-'a');
                        }
                    }
                    bool temp(true);
                    for(int j=0;j<rijeci.size();j++)
                    {
                        if(pom==rijeci[j])
                        temp=false;
                    }
                    if(temp && pom.size()!=0)
                    rijeci.push_back(pom);
                }
            }
        }
        if(i==recenica.size()-1 || i==recenica.size())
        break;
    }
    return rijeci;
}
map<string,set<int>> KreirajIndeksPojmova(string recenica)
{
  vector<string> rijeci;
 for(int i=0;i<recenica.size();i++)
  {
      if(recenica[i]>='A' && recenica[i]<='Z')
      recenica[i]=recenica[i]-('A'-'a');
  }
  rijeci=PovadiRijeci(recenica);
  map<string,set<int>> indeksi;
  for(int i=0;i<rijeci.size();i++)
  {
      set<int> skup;
      bool pronadjeno(false);
      for(int j=0;j<recenica.size();j++)
      {
          bool pom(false);
          bool pom2(false);
          if(j==0)
          {
              pom=true;
              if(rijeci[i]==recenica.substr(j,rijeci[i].size()) && recenica.size()==rijeci[i].size())
              {
                pronadjeno=true;
                skup.insert(j); 
              }
              else if(rijeci[i]==recenica.substr(j,rijeci[i].size()) && !Provjera(recenica[j+rijeci[i].size()]))
              {
                  pronadjeno=true;
                  skup.insert(j);
              }
          }
        if(j==recenica.size()-rijeci[i].size() && !pom)
        {
            if(rijeci[i]==recenica.substr(j,rijeci[i].size()) && !Provjera(recenica[j-1]))
            {
              pronadjeno=true;
              skup.insert(j);  
              pom2=true;
            }
        }
         if(!pom && !pom2)
          if(rijeci[i]==recenica.substr(j,rijeci[i].size()) && !Provjera(recenica[j-1]) && !Provjera(recenica[j+rijeci[i].size()]))
          {
          pronadjeno=true;
          skup.insert(j);
          }
      }
     // if(pronadjeno)
      indeksi.insert(std::make_pair(rijeci[i],skup));
  }
  return indeksi;
}

void IspisiIndeksPojmova(map<string,set<int>> mapa)
{
    if(mapa.size()!=0)
    for(auto it=mapa.begin();it!=mapa.end();it++)
    {
        cout<<it->first<<": ";
        int brojac(0);
        for(auto pom: it->second)
        {
        cout<<pom;
        if(brojac!=it->second.size()-1)
        cout<<",";
        brojac++;
        }
        cout<<std::endl;
    }
}
set<int> PretraziIndeksPojmova(string rijec,map<string,set<int>> mapa)
{
   // bool pronadjeno(false);
    set<int> skup;
    for(int i=0;i<rijec.size();i++)
    {
        if(rijec[i]>='A' && rijec[i]<='Z')
        rijec[i]=rijec[i]-('A'-'a');
    }
    for(auto it=mapa.begin();it!=mapa.end();it++)
    {
        if(rijec==it->first)
        {
       // pronadjeno=true;
        skup=it->second;
        return skup;
        }
    }
   // if(!pronadjeno)
    throw std::logic_error("Pojam nije nadjen");
}
int main ()
{
    cout<<"Unesite tekst: ";
    string recenica;
    std::getline(cin,recenica);
    auto mapa=KreirajIndeksPojmova(recenica);
    IspisiIndeksPojmova(mapa);
   // cin.ignore(10000,'\n');
    while(true)
    {
      string pom;
      cout<<"Unesite rijec: ";
      std::getline(cin,pom);
      if(pom.size()==1 && pom[0]=='.')
      break;
      try
      {
          auto skup=PretraziIndeksPojmova(pom,mapa);
          for(auto pom: skup)
          cout<<pom<<" ";
          cout<<std::endl;
          
      }
      catch(std::logic_error izuzetak)
      {
          cout<<"Unesena rijec nije nadjena!"<<std::endl;
      }
    }
	return 0;
}