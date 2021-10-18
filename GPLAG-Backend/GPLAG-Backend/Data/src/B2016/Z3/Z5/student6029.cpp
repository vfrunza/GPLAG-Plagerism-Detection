/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <stdexcept>
//#include "TestCurenja.h"

using namespace std;

struct Dijete
{
    string ime;
    Dijete *sljedeci;
};

int DuzinaRijeci(string rijec)
{
    int d=0;
    for(int i=0; i<rijec.length(); i++)
        if((rijec[i]>='A' && rijec[i]<='Z') || (rijec[i]>='a' && rijec[i]<='z') || (rijec[i]>='0' && rijec[i]<='9'))
            d++;
    return d;
}


void IspisiListu(Dijete *lista)
{   //cout<<"\n*ISPISI LISTU*\n"<<endl;
    
    //cout<<"ajd sad "<<lista->ime<<" "<<lista->sljedeci->ime<<" "<<lista->sljedeci->sljedeci->ime<<" "<<lista->sljedeci->sljedeci->sljedeci->ime<<endl;
    Dijete *pom=lista;
    while(pom->sljedeci!=lista)
    {
        cout<<pom->ime<<endl;
        pom=pom->sljedeci;
    }
    cout<<pom->ime<<endl;
}

vector<int> Razbroji(vector<string> imena, int br_timova)
{
    //cout<<"\n*RAZBROJI*\n";
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

Dijete* NapraviListu(vector<string> imena)
{
    //cout<<"\n*NAPRAVI LISTU*\n";
    Dijete *lista=nullptr;
    Dijete *t=lista;
    try
    {
        Dijete *novi=new Dijete;
        novi->ime=imena[0];
        lista=novi;
        t=novi;
        try
        {
            for(int i=1; i<imena.size(); i++)
            {
                Dijete *novi= new Dijete;
                novi->ime=imena[i];
                novi->sljedeci=t->sljedeci;
                t->sljedeci=novi;
                t=novi;
                //delete novi;
            }
            t->sljedeci=lista;
            //cout<<"da vidim nesto "<<t->ime<<" "<<t->sljedeci->ime<<" "<<lista->ime<<" "<<lista->sljedeci->ime<<endl;
            //IspisiListu(lista);
            return lista;
        }
        catch(...){ throw "Izuzetak"; }
    }
    catch(...){ throw bad_alloc(); }
}


Dijete* IzbaciDijete(Dijete* lista, string ime)
{
    //cout<<endl<<"*IZBACI DIJETE*"<<endl;
    Dijete *pom=lista;
    while (pom->sljedeci!=lista)
    {
        if(pom->ime==ime)
        {
            //cout<<"Nasao sam: "<<pom->ime<<endl;
            Dijete *pom2=pom->sljedeci;
            while(pom2->sljedeci!=pom)
                pom2=pom2->sljedeci;
            //cout<<"ime na pom2 "<<pom2->ime<<endl<<"ime na pom->sljedeci "<<pom->sljedeci->ime<<endl<<"ime na pom "<<pom->ime<<endl<<endl;
            pom2->sljedeci=pom->sljedeci;
            if(pom!=nullptr)
            delete pom;
            pom=pom2;
            //cout<<pom->ime<<" "<<pom->sljedeci->ime<<" "<<" "<<pom->sljedeci->sljedeci->ime<<" "<<pom->sljedeci->sljedeci->sljedeci->ime<<" "<<pom->sljedeci->sljedeci->sljedeci->sljedeci->ime<<endl;
            //cout<<"Lista nakon izbacivanja: ";
            //IspisiListu(pom);
            //delete pom2;
            return pom;
        }
        pom=pom->sljedeci;
    }
    //delete pom; 
    return lista;
}


vector<set<string>> Razvrstavanje(vector<string> imena, int br_timova)
{
    //cout<<"\n*RAZVRSTAVANJE*\n";
    
    if(br_timova<1 || br_timova>imena.size())
        throw logic_error("Razvrstavanje nemoguce");
    Dijete *lista=NapraviListu(imena);
    
    vector<int> timovi=Razbroji(imena, br_timova); 
    vector<set<string>> gotovo;
    Dijete *pom=lista;
    int duzina=DuzinaRijeci(pom->ime), i=0;
    while(i<timovi.size())
    {
        set<string> tim;
        for(int k=0; k<timovi[i]; k++)
        {
            tim.insert(pom->ime);
            duzina=DuzinaRijeci(pom->ime);
            pom=IzbaciDijete(lista, pom->ime);
            for(int j=0; j<duzina; j++)
                pom=pom->sljedeci;
        }
        gotovo.push_back(tim);
        i++;
    }
    
   //delete lista; delete pom;
    return gotovo;
}


int main ()
{
    //UKLJUCI_OBAVJESTAVANJE;
    cout<<"Unesite broj djece: ";
    int br_djece;
    cin>>br_djece;
    cout<<"Unesite imena djece: "<<endl;
    vector<string> imena(br_djece);
         for(int i=0; i<br_djece; i++)
         {
             string s;
             cin>>s;
             imena[i]=s;
         }
    cout<<"Unesite broj timova: ";
    int broj_timova;
    cin>>broj_timova;
    vector<set<string>> rezultat=Razvrstavanje(imena, broj_timova);
    //vector<set<string>> rezultat=Razvrstavanje({"Damir", "Ana","Muhamed", "Marko", "Ivan", "Mirsad", "Nikolina", "Alen", "Jasmina", "Merima" }, 3);
    try
    {
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
        cout<<s.what();
    }
}