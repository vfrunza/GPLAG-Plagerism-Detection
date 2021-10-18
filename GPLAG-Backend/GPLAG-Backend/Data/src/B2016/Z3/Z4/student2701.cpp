/B2016/2017: Zadaća 3, Zadatak 4

#include <list>
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


string maksimum(set<string> tim){
   string zadnji;
   zadnji=*max_element(tim.begin(),tim.end());
   return zadnji;
}


vector<set<string>> Razvrstavanje(vector<string> djeca, int k)
{
    if(k<1 || k>djeca.size()) throw logic_error("Razvrstavanje nemoguce");
    list<string> children;
   
    vector<set<string>> rezultat(k);

    for(int i=0; i<djeca.size(); i++) {
        children.push_back(djeca[i]);
    }
    
    list<string>::iterator iter(children.begin());
    rezultat[0].insert(*iter);
    string kakosezove;
    kakosezove=*iter;
    kakosezove.c_str();
    int brojacc=0;
    for(int i=0;i<kakosezove.size();i++){
        if((kakosezove[i]>='0' && kakosezove[i]<='9') || (kakosezove[i]>='A' && kakosezove[i]<='Z') || (kakosezove[i]>='a' && kakosezove[i]<='z'))
        brojacc++;
        
    }
    int brojslovaimena=brojacc;
    
    iter=children.erase(iter);
    int brojac=0;
    for(int i=0; i<(djeca.size())%k; i++) {

        int brojacispalih=0;
        while(iter!=children.end()) {

            brojac++;
            string imedjeteta=*iter;
            
            if(brojac!=brojslovaimena) iter++;

            else{
                rezultat[i].insert(imedjeteta);
                brojacispalih++;
                brojac=0;
                imedjeteta.c_str();
                int j=0;
                int novibrojac=0;
                while(j<imedjeteta.size()){
 if((imedjeteta[j]>='0' && imedjeteta[j]<='9') || (imedjeteta[j]>='A' && imedjeteta[j]<='Z') || (imedjeteta[j]>='a' && imedjeteta[j]<='z')){
     novibrojac++;
 }
 j++;
                }
                brojslovaimena=novibrojac;
                iter=children.erase(iter);
            }

            
            if(iter==children.end()) iter=children.begin();
            
            if(brojacispalih==djeca.size()/k && i==0 ) break;
            if(brojacispalih==djeca.size()/k + 1) break;

        }
    }




    for(int j=(djeca.size())%k; j<k; j++) {

        int brojacispalih=0;
        while(iter!=children.end()) {

            string imedjeteta=*iter;

            brojac++;

            if(brojac!=brojslovaimena) iter++;
            else {
                brojacispalih++;
                rezultat[j].insert(imedjeteta);
                imedjeteta.c_str();
                int brojac2=0;
                int f=0;
                while(f<imedjeteta.size()){
 if((imedjeteta[f]>='0' && imedjeteta[f]<='9') || (imedjeteta[f]>='A' && imedjeteta[f]<='Z') || (imedjeteta[f]>='a' && imedjeteta[f]<='z')){
     brojac2++;
 }
 f++;
                }
                
                
                brojslovaimena=brojac2;
                iter=children.erase(iter);
                brojac=0;}



            if(iter==children.end()) iter=children.begin();
            
            if(j==0 && brojacispalih==djeca.size()/k-1) break;
            if(brojacispalih==djeca.size()/k) break;

        }
    }


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