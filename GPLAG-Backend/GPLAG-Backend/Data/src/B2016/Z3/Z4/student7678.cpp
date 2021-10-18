/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::logic_error;
using std::getline;
using std::set;
using std::list;

vector<set<string>> Razvrstavanje(vector<string> imena, int br_tim){
    
    if(br_tim<1 || br_tim>imena.size())throw logic_error("Razvrstavanje nemoguce");
    
    list<string> limena;
    
    for(int i=0; i<imena.size(); i++){
        limena.push_back(imena[i]);
    }
    
    int broj_clanova = imena.size()/br_tim;
    vector<int> velicina_tima(br_tim, broj_clanova);
    

    int br_vecih_timova = int(imena.size())%br_tim;
    
    
    for(int k=0; k<br_vecih_timova; k++){
        velicina_tima[k] = broj_clanova+1; 
    }
    
    // sad imam vektor velicina_tima u kojem se za prvi tim indeks 0 nalazi broj clanova tima 1(iznad)
    
    
    vector<set<string>> timovi(br_tim);
    
    auto it = limena.begin();
        
        for(int i=0; i<br_tim; i++){
            set<string> tim;
            for(int j=0; j<velicina_tima[i]; j++){
                
                if(i==0 && j==0){
                    tim.insert(*it);
                    string ime = *it;
                    
                    int pomjeranje = 0;
                    for(int l = 0; l<ime.length(); l++){
                        if((ime[l]>='A' && ime[l]<='Z') || (ime[l]>='a' && ime[l]<='z') || (ime[l]>='0' && ime[l]<='9'))pomjeranje++;
                        else continue;
                    }
                    
                    it = limena.erase(it);
                    if(it==limena.end())it = limena.begin();
                    
                    for(int m=0; m<pomjeranje-1; m++){
                         if(it==--limena.end()) it=limena.begin();
                        else it++;
                       
                    }
                    continue;
                }
                
                tim.insert(*it);
                string ime = *it;
                int pomjeranje = 0;
                    for(int l = 0; l<ime.length(); l++){
                        if((ime[l]>='A' && ime[l]<='Z') || (ime[l]>='a' && ime[l]<='z') || (ime[l]>='0' && ime[l]<='9'))pomjeranje++;
                        else continue;
                    }
                it = limena.erase(it);
                if(it==limena.end())it = limena.begin();
                
                for(int m=0; m<pomjeranje-1; m++){
                    if(it==--limena.end()) it=limena.begin();
                    else it++;
                    
                }
                
                
            }
            
            timovi[i] = tim;
        }
        
    
    
    return timovi;
    
}
int main ()
{
    try{
        cout<<"Unesite broj djece: ";
        int n;
        cin>>n;
        vector<string> imena;
        cout<<"Unesite imena djece: "<<endl;
        cin.ignore(1000,'\n');
        for(int i=0; i<n; i++){
            string ime;
            getline(cin, ime);
            imena.push_back(ime);
        }
        
        int br_tim;
        cout<<"Unesite broj timova: ";
        cin>>br_tim;
        
        auto konacni = Razvrstavanje(imena, br_tim);
        
        for(int i = 0; i<br_tim; i++){
            cout<<"Tim "<<i+1<<": ";
            for(auto x : konacni[i]){
                if(x==*(--konacni[i].end())){cout<<x; break;}
                cout<<x<<", ";
            }
            cout<<endl;
            
        }
    }
    catch(logic_error i){
        cout<<"Izuzetak: "<<i.what();
    }
        
        
    	return 0;
}