/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>
using namespace std;


int DuzinaStringa( std::string s)
{
    int br(0);
    for( int i=0; i<s.length(); i++)
    {
        while((s[i]>='a' && s[i]<='z' ) ||  ( s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))
        {
            i++;
            br++;
        }
    }
    return br;
}


std::vector<std::multiset<std::string>>Razvrstavanje (std::vector<std::string> imena_djece, int broj_timova)
{
    if(broj_timova<1 || broj_timova>imena_djece.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::multiset<std::string>> ekipe;
    std::list<std::string> djeca;
    for( int i=0; i<imena_djece.size(); i++)
    djeca.push_back(imena_djece[i]);
    auto it=djeca.begin();
    
    std::vector<int> vel_tim;
    int mod(imena_djece.size() % broj_timova);
    for( int i=0; i<broj_timova; i++)
    {
        if(mod!=0)
        {
            vel_tim.push_back((imena_djece.size()/broj_timova) + 1 );
            mod--;
        }
        else 
        {
            vel_tim.push_back(imena_djece.size()/broj_timova);
        }
    }
    
    
    int brojac(0), i(0), j,duz(0);
    j=brojac;
    std::multiset<std::string> jedna_ekipa;
    if(it==djeca.begin())
    {
            jedna_ekipa.insert(*it);
            duz=DuzinaStringa(*it);
            it=djeca.erase(it);
    }
    
    while(djeca.size() != 0)
    {
       brojac++;
        if(brojac==duz)
        {
            
            if(jedna_ekipa.size() == vel_tim[i])
            {
                ekipe.push_back(jedna_ekipa);
                i++;
                std::multiset<std::string> skup;
                jedna_ekipa=skup;
                
                jedna_ekipa.insert(*it);
                duz=DuzinaStringa(*it);
                it=djeca.erase(it);
                brojac=j;
            
            }
            else
            {
                jedna_ekipa.insert(*it);
                duz=DuzinaStringa(*it);
                it=djeca.erase(it);
                brojac=j;
            }
        }
        else it++;
       
      
        if(it==djeca.end()) it=djeca.begin();
    }
    if(jedna_ekipa.size()!=0) ekipe.push_back(jedna_ekipa);
   
    return ekipe;
    
    
    
}




int main ()
{
    
    cout<<"Unesite broj djece: ";
    int n;
    cin>>n;
    cout<<"Unesite imena djece: ";
    cin.ignore( 10000 , '\n');
    std::vector<std::string> imena_djece;
    for( int i=0; i<n; i++)
    {
        std::string ime;
        std::getline(cin, ime);
        imena_djece.push_back(ime);
    }
    cout<<endl<<"Unesite broj timova: ";
    int k;
     cin>>k;
     try
     {
     std::vector<std::multiset<std::string>> ekipe (Razvrstavanje(imena_djece, k));
	for( int i=0; i<ekipe.size(); i++)
	{
	    int br(0);
	    int ispis(0);
	    cout<<"Tim "<<i+1<<": ";
	    for(auto j : ekipe[i])
	    {
	        br++;
	    }
	    for( auto j : ekipe[i])
	    {
	        ispis++;
	        if( ispis==br) cout<<j;
	        else cout<<j<< ", ";
	    }
	    cout<<endl;
	}}
	catch(std::logic_error e)
	{
	    cout<<"Izuzetak: "<<e.what()<<endl;
	}
	
	
	return 0;
}