/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <functional>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

template <typename TipElemenata>
 class DatotecniKontejner {
 std::fstream tok;
 public:
 
 DatotecniKontejner(const std::string &ime_datoteke){
     
     
     tok.open(ime_datoteke,ios::binary);
     if(!tok){
         tok.close();
         tok.open(ime_datoteke,ios::binary |ios::out);
         tok.close();
         tok.open(ime_datoteke,ios::out| ios::in|ios::binary);
     } 
     
     if(tok.bad())throw logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
     
     
     
 }
 
 void DodajNoviElement(const TipElemenata &element){
 
 tok.seekp(0,ios::end);
 tok.write((char*)&element,sizeof(element));
 tok.seekp(0);
     
 }
 
 int DajBrojElemenata(){
 
 tok.seekg(0,ios::end);
 int velicina=tok.tellg()/sizeof(TipElemenata);
 tok.seekg(0);
 return velicina;
     
 }
 
 TipElemenata DajElement(int pozicija){
  if(pozicija<0 || pozicija>=DajBrojElemenata())throw range_error("Neispravna pozicija");
 tok.seekg((pozicija)*sizeof(TipElemenata));
 TipElemenata temp;
 tok.read((char*)&temp,sizeof(TipElemenata));
 tok.seekg(0);
 return temp;
     
 }
 
 void IzmijeniElement(int pozicija, const TipElemenata &element){
 
 if(pozicija<0 || pozicija>=DajBrojElemenata())throw range_error("Neispravna pozicija");
 tok.seekp((pozicija)*sizeof(TipElemenata));
 tok.write((char*)&element,sizeof(TipElemenata));
 tok.seekp(0);
     
 }
 
 
 void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)>kriterij = std::less<TipElemenata>()){
     
 int vel=DajBrojElemenata();   
 
 for(int j=0;j<vel;j++){
 for(int i=0;i<vel-1;i++){
     
         TipElemenata temp1,temp2;
         
         tok.seekg(i*sizeof(TipElemenata));//za temp 1
         tok.read((char*)&temp1,sizeof(temp1));
         
         tok.seekg((i+1)*sizeof(TipElemenata));
         tok.read((char*)&temp2,sizeof(temp2));
         
         if(kriterij(temp1,temp2)==false){
             tok.seekp(i*sizeof(TipElemenata));
             tok.write((char*)&temp2,sizeof(temp2));
             tok.seekp((i+1)*sizeof(TipElemenata));
             tok.write((char*)&temp1,sizeof(temp1));
         }
         
     }
     
 }
 tok.seekp(0);tok.seekg(0);
 }
 
 };



int main ()
{
    
    cout<<"Eyo";
      
	return 0;
}
