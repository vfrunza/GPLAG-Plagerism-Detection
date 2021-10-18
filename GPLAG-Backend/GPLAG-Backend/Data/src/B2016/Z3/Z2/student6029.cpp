/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <stdexcept>

using namespace std;

map<string, set<int>> KreirajIndeksPojmova(string tekst)
{
    string pom1(""), pom2=""; int poc=0;
    map<string, set<int>> mapa;
    bool bila=false;
    int i=0;
    while(i<tekst.length())
    {
         bool nasao=false;
        while((tekst[i]>='A' && tekst[i]<='Z') || (tekst[i]>='a' && tekst[i]<='z') || (tekst[i]>='0' && tekst[i]<='9'))
            {
                pom1+=tolower(tekst[i]); i++; nasao=true;
            }
            poc=i;
        if(nasao)
        {
            set<int> indexi;
            indexi.insert(i-pom1.length());
            //cout<<i-pom1.length()<<endl;
            while(poc<tekst.length())
            {
                while((tekst[poc]>='A' && tekst[poc]<='Z') || (tekst[poc]>='a' && tekst[poc]<='z') || (tekst[poc]>='0' && tekst[poc]<='9'))
                {
                    pom2+=tolower(tekst[poc]); poc++;
                }
                if(pom1==pom2 && pom1!="")
                    {indexi.insert(poc-pom2.length());
                    //cout<<"-"<<poc-pom2.length()<<endl<<"duzina od pom2="<<pom2.length()<<endl<<pom2<<"=="<<pom1<<endl;
                    }
                    pom2="";
                poc++;
            }
            mapa.insert(make_pair(pom1, indexi));
        }
        pom1="";
        i++;
    }
    return mapa;
}


set<int> PretraziIndeksPojmova(string tekst, map<string, set<int>> mapa)
{
    string pom1("");
    set<int> indexi;
    for(int i=0; i<tekst.size(); i++)
        tekst[i]=tolower(tekst[i]);
        
    for(auto it=mapa.begin(); it!=mapa.end(); it++)
        if(tekst==it->first)
        {
            for(auto at=it->second.begin(); at!=it->second.end(); at++)
                indexi.insert(*at);
            return indexi;
        }
    
    throw logic_error("Pojam nije nadjen");
}
    
  


void IspisiIndeksPojmova(map<string, set<int>> mapa)
{
    for(auto it = mapa.begin(); it != mapa.end(); it++)
    {
        cout <<it->first << ": ";
        for(auto at=it->second.begin(); at!=it->second.end(); at++)
        {
            auto p=at; p++;
            cout<<*at;
            if(p!=it->second.end())
                cout<<",";
        }
        cout<<endl;
    }
}


int main ()
{
    //map<string, set<int>> mapa=KreirajIndeksPojmova("abc qwe stsda Abc abc dhi qwe hrkw dhi");
    string tekst, rijec;
    set<int> indexi;
    cout<<"Unesite tekst: ";
    getline(cin, tekst);
    map<string, set<int>> mapa;
    mapa=KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(mapa);
    while(1)
    {
        cout<<"Unesite rijec: ";
        getline(cin, rijec);
        if(rijec==".")
            return 0;
        try
        {
            indexi=PretraziIndeksPojmova(rijec, mapa);
        }
        catch(logic_error)
        {
            cout<<"Unesena rijec nije nadjena!"<<endl;
            continue;
        }
        for(auto it=indexi.begin(); it!=indexi.end(); it++)
            cout<<*it<<" ";
        cout<<endl;
    }
	return 0;
}