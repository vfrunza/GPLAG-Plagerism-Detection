/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <map>
#include <queue> 

using namespace std;

enum class Boje {Pik, Tref, Herc, Karo};

typedef list<pair<Boje,string>> Spil;
typedef multimap<Boje,string> Mapa;
typedef pair<Boje,string> Par;
typedef queue<Par> Red;

const vector<string> Karte{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
const vector<string> Znakovi{"Pik","Tref","Herc","Karo"};
const vector<int> Vrijednosti{2,3,4,5,6,7,8,9,10,12,13,14,15};

Spil KreirajSpil()
{
    Spil dek;int br=0;
    for(int i=0;i<52;i++)
    {   
        if(i%13==0 && i!=0) br++;
        dek.push_back(make_pair((Boje)(br),Karte[i%13]));
    }
    
    return dek;
}

void IspisiSpil(Spil dek)
{   
    int br=-1;cout<<"U spilu trenutno ima "<<dek.size()<<" karata, i to:"<<endl;
    if(dek.size()==0)
    {
        for(auto a:Znakovi)
        {
            cout<<a<<": "<<endl;
        }
    }
    else for(auto a:dek)
    {     
        if(br!=(int)a.first){if(br!=-1)cout<<endl;cout<<Znakovi[(int)a.first]<<": ";br++;}
        cout<<a.second<<" ";
        
    }
    cout<<endl;
}

bool Jednaki(Par a,Par b)
{
    return (int)a.first==(int)b.first && a.second==b.second;
}
/*
bool ValjaLista(Spil dek)
{
    for(auto a:dek)
    {
        
    }
}
*/
void IzbaciKarte(Spil &dek,Mapa &m)
{
    if(dek.size()>52) throw logic_error("Neispravna lista!"); 
    for(auto it=dek.begin();it!=dek.end();it++)
    {   
        for(auto mit=m.begin();mit!=m.end();mit++)
        {
            if(Jednaki(*it,*mit))
            {
                it=dek.erase(it);
                mit=m.erase(mit);
                break;    
            }
        }
    }
}

void IspisiMapu(Mapa m)
{
    for(auto a:m)
        cout<<Znakovi[(int)a.first]<<":"<<a.second<<endl;
}

Red IzbaciKarteRazbrajanjem(Spil &dek,const short int &r,const int &b)
{
    if(r<1 || r>52 || b<1) throw logic_error("Neispravni elementi za izbacivanje!");
    if(dek.size()>52)throw logic_error("Neispravna lista!");
    auto it=dek.begin();
    Red q;
    for(int i=0;i<b;i++)
    {
        for(int j=0;j!=r-1;it++,j++)
            if(it==dek.end() && dek.size()!=0)it=dek.begin();
            
                
            
           if(dek.size()==0) break;
                q.push(*it);
                it=dek.erase(it);
                
                
            
    }
    
    return q;   
}

bool ManjiString(string a,string b)
{   
    int i,j;
    for(i=0;i<Karte.size();i++)
        if(a==Karte[i]) break;
    for(j=0;j<Karte.size();j++)
        if(b==Karte[j]) break;
        
        return i<j;
}

void VratiPrvihNKarata(Spil &dek,Red &q,int n)
{
    if(n<0) throw domain_error("Broj n je besmislen!");
    if(n>q.size()) throw range_error("Nedovoljno karata u redu!");
    if(dek.size()>52) throw logic_error("Neispravna lista!"); 
    for(int i=n;i!=0;i--)
    {
        for(auto it=dek.begin();it!=dek.end();it++)
        {    
            if((int)it->first==(int)q.front().first)
            {   //cout<<q.front().second;
                //int i=0,j=0;
                while(ManjiString(it->second,q.front().second) && q.front().second!="A")
                    it++;
               
                 if(q.front().second=="A") 
                    while((int)q.front().first==(int)it->first) it++;
                            
                dek.insert(it,q.front());
               // if(it==dek.end())it=dek.begin();
                q.pop();
                break;
            }
        }
    }
}

int main ()
{   try{
    Spil dek=KreirajSpil();int n,br;
    cout<<"Unesite korak razbrajanja: ";
    cin>>n;
    cout<<"Unesite broj karata koje zelite izbaciti: ";
    cin>>br;
    Red q;
    q=IzbaciKarteRazbrajanjem(dek,n,br);
    
    IspisiSpil(dek);
    cout<<"Unesite broj karata koje zelite vratiti u spil: ";
    cin>>br;
    VratiPrvihNKarata(dek,q,br);
    IspisiSpil(dek);
}
    catch(domain_error er) { cout<<"Izuzetak: "<<er.what();}
    catch(logic_error er) {cout<<"Izuzetak: "<<er.what();}
    catch(range_error er) {cout<<"Izuzetak: "<<er.what();}
  return 0;
}
