#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <memory>

int duzina__rijeci(std::string s){
    int brojac = 0;
    for(auto c: s){
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') )brojac++;
    }
    return brojac;
}

struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete>sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int k){
    
    if(k<1 || k>v.size())throw std::logic_error("Razvrstavanje nemoguce");
    
    int vel = v.size();                               //23 i 3
    int br_prvih_timova = vel%k;                     //2
    int br_clanova1 = vel/k+1;                       //8
    int br_clanova2 = vel/k;                         //7
   
    std::vector<std::set<std::string>> t;
    t.resize(k);
    
    std::shared_ptr<Dijete> pocetak(nullptr),prethodni(nullptr);
    for(int i=0;i<v.size();i++){
        std::shared_ptr<Dijete> novi(std::make_shared<Dijete>());
        novi->ime = v[i]; novi->sljedeci = nullptr; 
       
        if(pocetak == nullptr)pocetak = novi;
        else prethodni->sljedeci = novi;
        prethodni = novi;
    }
    
    prethodni->sljedeci = pocetak;// zadnji pok na cvor postavljamo da pokazuje na pocetak
   
   int tr_vel = 0;
   std::shared_ptr<Dijete> trenutni = nullptr;
   for(int i=0;i<k;i++){
            for(int j=0;(i>=br_prvih_timova) ? (j<br_clanova2) : (j<br_clanova1);j++){
                //brisem pocetak, prethodni i dalje pokazuje prije pocetka !!
                if(i==0 && j==0){
                t[i].insert(pocetak->ime);
                tr_vel = duzina__rijeci(pocetak->ime);  
                prethodni->sljedeci = pocetak->sljedeci;
           
                pocetak = pocetak->sljedeci;
                
                trenutni = pocetak;
                
                }else{
                    std::shared_ptr<Dijete> prijetrenutnog = nullptr;
                for(int h=0;h<tr_vel-1;h++){
                    if(h==tr_vel-2)prijetrenutnog = trenutni;
                    trenutni = trenutni->sljedeci;
                    
                }
                
                t[i].insert(trenutni->ime);
                
                tr_vel = duzina__rijeci(trenutni->ime);
                prijetrenutnog->sljedeci = trenutni->sljedeci;
               
                trenutni = trenutni->sljedeci;
               
                }
            }
    }
   trenutni->sljedeci = nullptr;
   trenutni = nullptr;
   
    return t;
}


int main ()
{
  std::cout<<"Unesite broj djece: ";
  int br;
  std::cin>>br;
  std::cin.ignore(1,'\n');
  std::cout<<"Unesite imena djece: \n";
  std::vector<std::string> v(br);
  for(int i=0;i<br;i++){
      std::getline(std::cin,v[i]);
      
  }
   //std::cin.ignore(1,'\n');
  int k;
  std::cout<<"Unesite broj timova: ";
  std::cin>>k;
 
  
  std::vector<std::set<std::string>> t;
  try{
       t = Razvrstavanje(v,k);
  }catch(std::logic_error temp){
      std::cout<<"Izuzetak: "<<temp.what()<<std::endl;
      return 0;
  }
  
  
  for(int i=0;i<k;i++){
      std::cout<<"Tim "<<i+1<<": ";
      auto q = t[i].begin();
      int vel = t[i].size();
      for(int j=0;j<vel-1;j++)q++;
      
      for(auto p = t[i].begin();p!=t[i].end();p++){
          if(p != q)std::cout<<*p<<", ";
          else std::cout<<*p<<std::endl;
      }
  }
	return 0;
}