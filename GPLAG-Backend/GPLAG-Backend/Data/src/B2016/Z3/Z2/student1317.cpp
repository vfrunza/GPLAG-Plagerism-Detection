/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <iterator>
#include <stdexcept>

using namespace std;

void PretvoriUMala(string &s)
{
    for(int i=0; i<s.length(); i++)
        if(s[i]>='A' && s[i]<='Z') s[i]+=('a'-'A');

    return;
}

// Funkcija KreirajIndeksPojmova kreira popis pojmova koji se nalaze u tekstu,
// pri cemu se uz svaki pojam navode i pozicije
map<string, set<int>> KreirajIndeksPojmova(string tekst)
{
    map<string, set<int>> mapa;
    for(int i=0; i<tekst.length(); i++)
    {
        if(!((tekst[i]>='A' && tekst[i]<='Z') || (tekst[i]>='a' && tekst[i]<='z') || (tekst[i]>='0' && tekst[i]<='9'))) continue;
        int indeks(i);
        while(((tekst[indeks]>='A' && tekst[indeks]<='Z') || (tekst[indeks]>='a' && tekst[indeks]<='z') || (tekst[indeks]>='0' && tekst[indeks]<='9')) && indeks!=tekst.length()) indeks++;
        if(i==0 && !((tekst[indeks]>='A' && tekst[indeks]<='Z') || (tekst[indeks]>='a' && tekst[indeks]<='z') || (tekst[indeks]>='0' && tekst[indeks]<='9')))    
        {
            string pomocni(tekst.substr(i, indeks-i));
            PretvoriUMala(pomocni);
            mapa.insert(make_pair(pomocni, set<int>()));
        }
        if(i>0 && !((tekst[indeks]>='A' && tekst[indeks]<='Z') || (tekst[indeks]>='a' && tekst[indeks]<='z') || (tekst[indeks]>='0' && tekst[indeks]<='9')) && !((tekst[i-1]>='A' && tekst[i-1]<='Z') || (tekst[i-1]>='a' && tekst[i-1]<='z') || (tekst[i-1]>='0' && tekst[i-1]<='9')))
        {
            string pomocni(tekst.substr(i, indeks-i));
            PretvoriUMala(pomocni);
            mapa.insert(make_pair(pomocni, set<int>()));
        }
    }
    
    for(auto it=mapa.begin(); it!=mapa.end(); it++) 
    {
        for(int i=0; i<tekst.length(); i++)
        {
            if(!((tekst[i]>='A' && tekst[i]<='Z') || (tekst[i]>='a' && tekst[i]<='z') || (tekst[i]>='0' && tekst[i]<='9'))) continue;
            int indeks(i);
            while(((tekst[indeks]>='A' && tekst[indeks]<='Z') || (tekst[indeks]>='a' && tekst[indeks]<='z') || (tekst[indeks]>='0' && tekst[indeks]<='9')) && indeks!=tekst.length()) indeks++;
            if(i==0 && !((tekst[indeks]>='A' && tekst[indeks]<='Z') || (tekst[indeks]>='a' && tekst[indeks]<='z') || (tekst[indeks]>='0' && tekst[indeks]<='9')))    
            {
                string pomocni(tekst.substr(i, indeks-i));
                PretvoriUMala(pomocni);
                if((it->first)==pomocni) it->second.insert(i);
            }
            if(i>0 && !((tekst[indeks]>='A' && tekst[indeks]<='Z') || (tekst[indeks]>='a' && tekst[indeks]<='z') || (tekst[indeks]>='0' && tekst[indeks]<='9')) && !((tekst[i-1]>='A' && tekst[i-1]<='Z') || (tekst[i-1]>='a' && tekst[i-1]<='z') || (tekst[i-1]>='0' && tekst[i-1]<='9')))
            {
                string pomocni(tekst.substr(i, indeks-i));
                PretvoriUMala(pomocni);
                if((it->first)==pomocni) it->second.insert(i);
            }
        }
    }
    
    return mapa;
}

// Funkcija PretraziIndeksPojmova kreira odgovarajuci skup pozicija za datu
// rijec pronadjenu u datom indeksu pojmova
set<int> PretraziIndeksPojmova(string rijec, map<string, set<int>> mapa)
{
    bool pronadjena(false);
    set<int> indeksi;
    for(auto it=mapa.begin(); it!=mapa.end(); it++)
	{
	    if(it->first==rijec)
	    {
	        pronadjena=true;
	        indeksi=it->second;
	        break;
	    }
	 }
	 if(!pronadjena) throw std::logic_error("Pojam nije nadjen");
	 
	 return indeksi;
}

void IspisiIndeksPojmova(map<string, set<int>> mapa)
{
    for(auto it=mapa.begin(); it!=mapa.end(); it++)
	{
	    cout << it->first << ": ";
	    auto it1=(it->second).begin();
	    for(it1=(it->second).begin(); it1!=(it->second).end(); it1++)
	    {
	        if(distance(it1, (it->second).end())==1) break;
	        cout << *it1 << ",";
	    }
	    cout << *it1 << endl;
	}
	return;
}

int main ()
{
    try
    {
    	string tekst;
    	cout << "Unesite tekst: ";
    	getline(cin, tekst);
    	
    	map<string, set<int>> mapa(KreirajIndeksPojmova(tekst));
    	IspisiIndeksPojmova(mapa);
    	while(1)
    	{
    	    string rijec;
    	    cout << "Unesite rijec: ";
    	    getline(cin, rijec);
    	    if(rijec.length()==1 && rijec[0]=='.') break;
    //	    set<int> indeksi(PretraziIndeksPojmova(rijec, mapa));
    	    bool pronadjena(false);
    	    for(auto it=mapa.begin(); it!=mapa.end(); it++)
    	    {
    	        if(it->first==rijec)
    	        {
    	            pronadjena=true;
    	            for(auto it1=(it->second).begin(); it1!=(it->second).end(); it1++)
    	                cout << *it1 << " ";
    	            cout << endl;
    	            break;
    	        }
    	    }
    	    if(!pronadjena) cout << "Unesena rijec nije nadjena!" << endl;
    	}
    }
    catch(std::logic_error izuzetak)
    {
        cout << izuzetak.what() << endl;
    }
    
	return 0;
}


