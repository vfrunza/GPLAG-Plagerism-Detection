/B2016/2017: Zadaća 3, Zadatak 5


#include <string>
#include <cstdio>
#include <vector>
#include <new>
#include <stdexcept>
#include <set>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Dijete{
    string ime;
    Dijete *sljedeci;
};

string maksimum(set<string> tim){
   string zadnji;
   zadnji=*max_element(tim.begin(),tim.end());
   return zadnji;
}


vector<set<string>> Razvrstavanje(vector<string> djeca, int k)
{
    if(k<1 || k>djeca.size()) throw logic_error("Razvrstavanje nemoguce");
   
   
    vector<set<string>> rezultat(k);

   

    return rezultat;
}


int main ()
{
    try {
        cout<<"Unesite broj djece: ";
        int n;
        cin>>n;
        cin.ignore(10000,'\n');
        cout<<"Unesite imena djece: "<<endl;
        vector<string> djeca(n);

        for(int i=0; i<n ; i++) {
        
            getline(cin,djeca[i]);
         
        }
        cout<<"Unesite broj timova: ";
        int k;
        cin>>k;
        vector<set<string>> poziv;
        poziv=Razvrstavanje(djeca,k);

        for(int i=0; i<k; i++) {
           
            cout<<"Tim "<<i+1<<": ";
            for(auto x: poziv[i]) {
                string maks;
                maks=maksimum(poziv[i]);
                if (x==maks) cout<<x;
                else cout<<x<<", ";
            }
            cout<<endl;
        }


    } catch(logic_error izuzetak){  cout<<"Izuzetak: "<<izuzetak.what();}
    return 0;
}