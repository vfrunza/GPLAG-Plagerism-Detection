/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <stdexcept>
#include <iterator>

using std::set;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::set;
using std::list;
using std::logic_error;

int BrojKaraktera(string Ime){
        int brojac=0;
        for(int i=0; i<Ime.length(); i++){
            if( (Ime[i]>='0' && Ime[i]<='9') || (Ime[i]>='A' && Ime[i]<='Z') || (Ime[i]>='a' && Ime[i]<='z') ){
                brojac++;
            }
        }
    return brojac;
}

list<string> VektorUListu(vector<string> ImenaDjece){
    list<string>ListaImena;
    for(auto it1=ImenaDjece.begin();it1!=ImenaDjece.end();it1++){
                     ListaImena.push_back(*it1);
                }
                return ListaImena;
}

vector<int> VelBrTimova(int BrojTimova, int temp, int ostatak){
    vector<int>broj;
    for(int i=0;i<BrojTimova;i++){
                    if(ostatak!=0){
                        broj.push_back(temp+1);
                        ostatak--;
                    }
                    else{
                        broj.push_back(temp);
                    }
                }
                return broj;
}

vector<set<string>> Razvrstavanje(vector<string> ImenaDjece, int BrojTimova){
    if(BrojTimova<1 || BrojTimova>ImenaDjece.size()) throw logic_error ("Razvrstavanje nemoguce");
                int temp=(ImenaDjece.size()/BrojTimova);
                int ostatak=(ImenaDjece.size()%BrojTimova); 
                vector<int> broj(VelBrTimova(BrojTimova, temp, ostatak));
                list<string> ListaImena(VektorUListu(ImenaDjece));
                auto it2=ListaImena.begin();
                it2=ListaImena.begin();
                vector<set<string>> Timovi(BrojTimova);
                while(ListaImena.size()!=0){
                    for(int i=0; i<BrojTimova; i++){
                            for(int k=0; k<broj[i]; k++){
                                auto it3=it2;
                                if(it3==ListaImena.end()) it3=ListaImena.begin();
                                else it3++;
                                Timovi[i].insert(*it2);
                                int br_kar=BrojKaraktera(*it2);
                                it2=ListaImena.erase(it2);
                                it2=it3;
                                for(int l=0;l<br_kar;l++){
                                        if(it2==ListaImena.end()) it2=ListaImena.begin();
                                        it2++;
                                }
                                if(it2!=ListaImena.begin()) it2--;
                            }
                        }   
                }
    return Timovi;
}

int main (){
    int djeca;
    cout<<"Unesite broj djece: ";
    cin>>djeca;
    cin.ignore(100000, '\n');
    vector<string> ImenaDjece;
    cout<<"Unesite imena djece: "<<endl;
    for(int i=0; i<djeca; i++){
        string temp;
        getline(cin, temp);
        ImenaDjece.push_back(temp);
    }
    int timovi;
    cout<<"Unesite broj timova: ";
    cin>>timovi;
    try{
        vector<set<string>>Random (Razvrstavanje(ImenaDjece, timovi));
        
    for(int i=0; i<int(Random.size()); i++){
        std::cout<<"Tim "<<i+1<<": ";
        auto it1(Random[i].begin());
        auto it2(Random[i].end());
        it2--;
        
            while(it1!=it2){
                cout<<*it1<<", ";
                it1++;
            }
            
        cout<<*it1<<endl;
            }

    }
    catch(logic_error izuzetak){
        cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    }
    
	return 0;
}