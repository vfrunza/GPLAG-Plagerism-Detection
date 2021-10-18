/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <stdexcept>
#include <cstring>

using namespace std;

vector<int> Razbroji(vector<string> imena, int br_timova)
{
    vector<int> timovi(br_timova);
    if(imena.size()%br_timova==0)
        for(int i=0; i<br_timova; i++)
            timovi[i]=imena.size()/br_timova;
    else
    {
        for(int i=0; i<imena.size()%br_timova; i++)
            timovi[i]=imena.size()/br_timova+1;
        for(int i=imena.size()%br_timova; i<br_timova; i++)
            timovi[i]=imena.size()/br_timova;
    }
    return timovi;
}

int DuzinaRijeci(string rijec)
{
    int d=0;
    for(int i=0; i<rijec.length(); i++)
        if((rijec[i]>='A' && rijec[i]<='Z') || (rijec[i]>='a' && rijec[i]<='z') || (rijec[i]>='0' && rijec[i]<='9'))
            d++;
    return d;
}

bool Ubacen(set<string> imena, string s)
{
    for(auto it=imena.begin(); it!=imena.end(); it++)
        if(*it==s)
            return true;
    return false;
}

vector<set<string>> Razvrstavanje(vector<string> imena, int br_timova)
{
    if(br_timova<1 || br_timova>imena.size())
        throw logic_error("Razvrstavanje nemoguce");
        
    list<string> lista;
    vector<int> timovi=Razbroji(imena, br_timova);
    int pom=0; auto at(lista.begin());
    for(int i=0; i<br_timova; i++)
        for(int j=0; j<timovi[i]; j++)
        {
            lista.push_back(imena[pom]);
            pom++; at++;
        }
    auto it(lista.begin());
    vector<set<string>> gotovo;
    int duzina=DuzinaRijeci(*it);
    int i=0;
    while(lista.size()!=0)
    {
        set<string> tim;
        //cout<<"->"<<*it<<endl;
        if(lista.size()==0)
            break;
        //cout<<" "<<duzina<<" "<<endl;
        for(int k=0; k<timovi[i]; k++)
        {
            if(lista.size()==0)
                break;
            tim.insert(*it);
            //cout<<"Ubacio sam -> "<<*it<<endl;
            duzina=DuzinaRijeci(*it);
            it=lista.erase(it);
            if(lista.size()==0)
                break;
            if(it==lista.end()) it=lista.begin();
            //cout<<"Brojanje krece sada od: "<<*it<<" i to se broji "<<duzina<<" igraca"<<endl;
            //cout<<"Prolazim kroz: ";
            for(int j=0; j<duzina-1; j++)
                {
                   // cout<<"->"<<*it; 
                    it++; 
                    if(it==lista.end()) 
                        it=lista.begin();
                   // cout<<", a j= "<<j<<endl;
                }
            /*cout<<endl<<"Igraci nakon "<<k+1<<". izbacivanja: "<<endl;
            for(auto pok=lista.begin(); pok!=lista.end(); pok++)
                cout<<*pok<<endl;
            cout<<"++++++++++++++++++++++++++"<<endl;
            cout<<"Pokazivac se nalazi na: "<<*it<<endl;
            cout<<"Ostalo je jos "<<lista.size()<<" igraca"<<endl<<endl;*/
        }
        /*cout<<endl<<"Tim "<<i+1<<" ima clanove: "<<endl;
        for(auto at=tim.begin(); at!=tim.end(); at++)
            cout<<*at<<endl;
        cout<<"-----------------------"<<endl;
        for(auto f=lista.begin(); f!=lista.end(); f++)
            cout<<*f;*/
        gotovo.push_back(tim);
        i++;
    }
    
    //for(auto it=lista.begin(); it!=lista.end(); it++)
      //  cout<<*it<<endl;
    return gotovo;
}

int main ()
{
    /*vector<set<string>> vec=Razvrstavanje({"Da2ir", "Ana", "Muh//amed", "Marko", "Ivan", "Mi34ad", "Nikolina", "Al!*en", "Jasmina", "Merima"}, 3);
    for(int i=0; i<vec.size(); i++)
     {
         for(auto it=vec[i].begin(); it!=vec[i].end(); it++)
            cout<<"+"<<*it<<"+ ";
        cout<<endl;
     }*/
     try{
         
         cout<<"Unesite broj djece: ";
         int br_djece;
         cin>>br_djece;
         cout<<"Unesite imena djece: "<<endl;
         vector<string> imena(br_djece);
         string s="";
         getline(cin, s);
         for(int i=0; i<imena.size(); i++)
         {
             getline(cin, s);
             imena[i]=s;
         }
         cout<<"Unesite broj timova: ";
         int broj_timova;
         cin>>broj_timova;
         vector<set<string>> rezultat=Razvrstavanje(imena, broj_timova);
         for(int i=0; i< rezultat.size(); i++)
         { 
             cout<<"Tim "<<i+1<<": ";
             auto at=rezultat[i].begin(); at++;
             for(auto it=rezultat[i].begin(); it!=rezultat[i].end(); it++)
             {
                 if(at!=rezultat[i].end())
                    cout<<*it<<", ";
                else
                    cout<<*it;
                at++;
             }
             cout<<endl;
         }
    	return 0;
     }
     catch(logic_error s)
     {
         cout<<"Izuzetak: "<<s.what();
     }
}