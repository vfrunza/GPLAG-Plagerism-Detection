/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

using namespace std;

 int BrojSlovaURijeci (string &s){
     int brojac(0);
     
     for(int i=0; i<s.size(); i++)
     if((s[i]>='0'&& s[i]<='9') || (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
     brojac++;
     
     return brojac;
 }

    vector<set<string>> Razvrstavanje(vector<string> v, int k){
        if(k<1 || k>v.size()) throw logic_error ("Razvrstavanje nemoguce");
         vector<set<string>> povratni;
         list<string> lista;
         int n=v.size();
         for(int i=0; i<n; i++) lista.push_back(v[i]);
         
         vector<int> tim;
         if(n%k==0){
             int temp=n/k;
             tim.resize(k);
             for(int i=0; i<tim.size(); i++)
             tim[i]=temp;
         }
         else if(n%k!=0){
             int temp, suma(0);
             temp=n/k;
             suma=k*temp;
             tim.resize(k);
             for(int i=0; i<tim.size(); i++)
             tim[i]=temp;
             int j(0);
             while(suma<n){
                 tim[j]++;
                 j++;
                 suma+=1;
             }
         }
      /*  cout<<"broj clanova po timovima:";
         for(int i=0; i<tim.size(); i++){
             cout<<tim[i]<<" ";
         }*/
         
         
         
         int z(0), j(0), br_slova;
         set<string> pomocni;
        // auto uk=lista.begin();
         for(list<string>::iterator i=lista.begin(); i!=lista.end(); ){
            
             while(tim[j]>z){
                 
                 
                 pomocni.insert(*i);
                   br_slova= BrojSlovaURijeci(*i);
            
                  
                  i=lista.erase(i); //erase vraca iterator na element koji dolazi poslije obrisanog
                  //kad nap samo lista.erase(i); i ce pokazivati  na viseci objekat, pa je to viseci operator
                  //zbog toga mem greska bila :D Elhamdulillah
                  
                   if(lista.size()==0) break;
                  if(i==lista.end()) i=lista.begin();
                  br_slova--;
                   while(br_slova>0){
                    
                       i++; 
                       br_slova--;
                       if(i==lista.end()) i=lista.begin();
                       
                   }
                  z++;
             }
           
        
             z=0;
             j++;
             povratni.push_back(pomocni);
              pomocni.erase(pomocni.begin(), pomocni.end());
           
             
            if(lista.size()==0) break;
             if(i==lista.end()) i=lista.begin();
           
         }
         
         return povratni;
        
    }
int main ()
{
    cout<<"Unesite broj djece: ";
    int n; cin>>n;
    cout<<"Unesite imena djece: ";
    vector<string> imena;
    string s;
    try{
    cin.ignore(10000, '\n');
    for(int i=0; i<n; i++){
        getline(cin, s);
        imena.push_back(s);
        s.resize(0);
       //cin.ignore(10000, '\n');
    }
    cout<<"\nUnesite broj timova: ";
    int k; cin>>k; 
    vector<set<string>> novi;
    novi=Razvrstavanje(imena, k);
    set<string> temp;
    for(int i=0; i<k; i++){
        cout<<"Tim "<< i+1<<": ";
        temp=novi[i];
        for(auto j=temp.begin(); j!=temp.end(); ){
            
        cout<<*j;
        j++;
        if(j!=temp.end()) cout<<", ";
        }
        cout<<endl;
        temp.erase(temp.begin(), temp.end());
    }
    }
    catch(logic_error iz){
        cout<<"Izuzetak: "<< iz.what();
    }
    catch(...){
     return 0;
    }
    
	return 0;
}