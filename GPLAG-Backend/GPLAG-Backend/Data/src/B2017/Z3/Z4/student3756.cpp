/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include<exception>
#include <stdexcept>
using namespace std;

enum class Boje {Pik, Tref, Herc, Karo};

list<pair<Boje,string>> KreirajSpil()
{
    list<pair<Boje,string>> spil;
    
    for(int i=0;i<4;i++)
    {
        for(int j=2;j<16;j++)
        {  
           if(j==11) continue;
           
           string c;
            
           switch(j)
           {
               case 10:
                c.push_back('1');
                c.push_back('0');
                break;
               
               case 12:
                c.push_back('J');
                break;
                
               case 13:
                c.push_back('Q');
                break;
                
                case 14:
                 c.push_back('K');
                 break;
                
                case 15:
                  c.push_back('A');
                  break;
                  
                default:
                  c.push_back(j+'0');
           }
            
            
          
           
           pair<Boje,string> p=make_pair(Boje(i),c) ;  
           spil.push_back(p);
            
        }
    }
    
    return spil;
}

void IspisiSpil(list<pair<Boje,string>> spil)
{   
    cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<endl;
    vector<string> v={"Pik","Tref","Herc","Karo"};
    
    
    auto it=spil.begin();
    int br=(int)it->first;
    for(;it!=spil.end();)
    {   
        cout<<v[(int)it->first]<<": ";
        while(br==(int)it->first)
        {
            cout<<it->second<<" ";
            if(it!=spil.end()) it++;
        }
        cout<<endl;
        br=(int)it->first;   
     
    }
    
    cout<<endl;
}

void IspisiMapu(multimap<Boje,string> m)
{
    cout<<endl;
    for(auto a:m)
    {
        cout<<(int)a.first<<" "<<a.second<<endl;
    }
}

bool JesuIsti(pair<Boje,string> a,pair<Boje,string> b)
{
    return a.first==b.first && a.second==b.second;
}

void IzbaciKarte(list<pair<Boje,string>> &spil,multimap<Boje,string> m)
{   
    
    for(auto i=spil.begin();i!=spil.end();i++)
    {   
        
        for(auto j=m.begin();j!=m.end();j++)
        {   
            if(JesuIsti(*i,*j))
            {   
                i=spil.erase(i);
                j=m.erase(j);
                if(j==m.end()) break;
                    
            }
        
        }
      
    }
}

void IspisiQueue( queue<pair<Boje,string>> q)
{
    while(q.size()!=0)
    {
        cout<<(int)q.front().first<<" "<<q.front().second<<" ";
        q.pop();
    }
}

queue<pair<Boje,string>>  IzbaciKarteRazbrajanjem(list<pair<Boje,string>> &spil,const short int &r,const int b)
{
    queue<pair<Boje,string>> q;
    
    int i=0;auto it=spil.begin();
    for(;i<b;i++)
    {   
        int br=0;
        
        while(br!=r-1)
        {
            it++;
            br++;
            if(it==spil.end()) it=spil.begin();
        }
        
        q.push(*it);
        it=spil.erase(it);
    }
    return q;
}

bool JelManji(string a,string b)
{
    vector<string> v={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    int index,index1;
    
    for(int i=0;i<v.size();i++)
        if(v[i]==a) index=i;
    
    for(int i=0;i<v.size();i++)
        if(v[i]==b) index1=i;
   
    return index<index1;
}

void VratiPrvihNKarata(list<pair<Boje,string>> &spil,queue<pair<Boje,string>> &q,int n)
{
    int br=0;
    
   // list<pair<Boje,string>> dek=KreirajSpil();
   
        
    if(n>q.size())throw range_error("Nedovoljno karata u redu!");
    while(br!=n)
    {   
        //int br1=0;
        auto it=spil.begin();
       // auto it1=dek.begin(); 
              
         
         while((int)q.front().first!=(int)it->first)
              it++;
            
         while(JelManji(it->second,q.front().second) && (int)q.front().first==(int)it->first)
              it++;
              
       //cout<<endl<<(int)it->first<<" "<<it->second<<endl<<(int)q.front().first<<" "<<q.front().second<<endl<<endl;
       spil.insert(it,q.front());
       q.pop();
      
        br++;
    }
    
    
}

int main ()
{   
    list<pair<Boje,string>> spil;
    spil=KreirajSpil();

int n,n2;
    
    cout<<"Unesite korak razbrajanja: ";
    cin>>n;
    
    cout<<"Unesite broj karata koje zelite izbaciti: ";
    int n1;
    cin>>n1;
    
    if(n<0 || n1<0) {
        cout<<"Izuzetak: Neispravni elementi za izbacivanje!";
        return 0;
    }
    
    queue<pair<Boje,string>> q=IzbaciKarteRazbrajanjem(spil,n,n1);
    IspisiSpil(spil);
    
    try {
        
        
    cout<<"Unesite broj karata koje zelite vratiti u spil: ";
    cin>>n2;
    
    if(n2<0 || !cin) 
        throw domain_error("Broj n je besmislen!");

    
    VratiPrvihNKarata(spil,q,n2);
    IspisiSpil(spil);
    }
    catch (domain_error& e){ cout<<"Izuzetak: "<<e.what();}
    catch(range_error e){cout<<"Izuzetak: "<<e.what();}
         
    
/*    IspisiSpil(spil);
    
    multimap<Boje,string> m;
    
    string c;
    c.push_back('A');
    m.insert(make_pair((Boje)2,c));
    m.insert(make_pair((Boje)0,c));
    m.insert(make_pair((Boje)1,c));
    m.insert(make_pair((Boje)3,c));
    IzbaciKarte(spil,m);
    
    cout<<endl;
    IspisiSpil(spil); 
    
    cout<<endl;
    spil=KreirajSpil();//const short int n=6;
    queue<pair<Boje,string>> q=IzbaciKarteRazbrajanjem(spil,2,23);
    IspisiQueue(q);
    cout<<endl;
    VratiPrvihNKarata(spil,q,13);
    IspisiSpil(spil);*/
    
	return 0;
}
