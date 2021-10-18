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

struct Dijete{
 string ime;
 Dijete *sljedeci;
};

    vector<set<string>> Razvrstavanje(vector<string> v, int k){
        if(k<1 || k>v.size()) throw logic_error ("Razvrstavanje nemoguce");
         vector<set<string>> povratni;
         list<string> lista;
         int n=v.size(), i(0);
         Dijete *pocetak(nullptr), *prethodni=nullptr, *novi=nullptr;
         while(1){
          if(i==n) {
           prethodni->sljedeci=pocetak;
           break;
          }
          Dijete *novi (new Dijete);
          novi->ime=v[i];
         novi->sljedeci=nullptr;
          if(!pocetak) pocetak=novi;
          else prethodni->sljedeci=novi;
          prethodni=novi;
          i++;
          
      
         
         }
         
         
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
    
         
         
         
         int z(0), j(0), br_slova, tester(0);
         set<string> pomocni;
  
  
         for(;; ){

             while(tim[j]>z){
                 
                 
                 pomocni.insert(pocetak->ime);
                 tester++;
                 
                   br_slova= BrojSlovaURijeci(pocetak->ime);
                   auto pok(pocetak);
                   pocetak=pocetak->sljedeci;
                   prethodni->sljedeci=pocetak;
                   delete pok;
             
                  
                   if(tester==n) {
                     povratni.push_back(pomocni);
                     break;}
         
            
                  br_slova--;
                   while(br_slova>0){
                    prethodni=pocetak;
                      pocetak=pocetak->sljedeci; 
                       br_slova--;
                   }
                      
                  z++;
             }
    
        
             z=0;
             j++;
             povratni.push_back(pomocni);
              pomocni.erase(pomocni.begin(), pomocni.end());
           if(tester==n) break;
          
           
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
        cout<<"Izuzetak: "<<iz.what();
    }
    catch(...){
     return 0;
    }
    
    
	return 0;
}