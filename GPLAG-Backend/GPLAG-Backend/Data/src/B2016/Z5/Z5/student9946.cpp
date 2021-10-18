/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <list>
using namespace std;

typedef pair<int,int> par_temperatura;

class Temperature{
    
  int donja_granica;
    int gornja_granica;
    list<int> listaminimalnih;
    list<int> listamaksimalnih;
    
    
    public:
    Temperature (int min, int max){
        donja_granica=min;
        gornja_granica=max;
        }
    
    void RegistrirajTemperature(par_temperatura registrovane){
        try{
             if(registrovane.first<donja_granica || registrovane.second>gornja_granica || registrovane.first>registrovane.second )
                throw range_error ("Nekorektne temperature");
             
            listaminimalnih.push_back(registrovane.first);
            
            listamaksimalnih.push_back(registrovane.second);
            
        }
        catch (range_error e){
            cout<<e.what()<<endl;
        }
    }
    
    void BrisiSve(){
        listamaksimalnih.clear();
        listaminimalnih.clear();
    }
    void BrisiTemperature(par_temperatura proslijedjena ){
       int prvapozicija= listamaksimalnih.find(registrovane.second);
       int drugapozicija=listaminimalnih.find(registrovane.first);
       if(prvapozicija==drugapozicija){
           listamaksimalnih.erase(prvapozicija);
           listaminimalnih.erase(prvapozicija);
       }
    }
};






int main ()
{
    
    
    
	return 0;
}