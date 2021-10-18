#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <fstream>
#include<vector>

template <typename TipEl>
 class Matrica {
  std::vector<std::vector<TipEl>>v;
  public:
  Matrica(int a,int b){
   v.resize(a);
   for(int i=0;i<a;i++){
    v[i].resize(b);
   }
  }
  Matrica(std::string s,bool b){
   if(b){
    ObnoviIzBinarneDatoteke(s);
   }else {
    ObnoviIzTekstualneDatoteke(s);
   }
  }

  template<typename T>
  friend std::ostream &operator <<(std::ostream &tok,const Matrica<T> &m);
  
  std::vector<std::vector<TipEl>> ObnoviIzTekstualneDatoteke(std::string s){
   std::ifstream ulaz (s);
   if(!ulaz)throw std::logic_error {"Trazena datoteka ne postoji"};
   std::string a,b;
   int red=0;
   while(std::getline(ulaz,a)){
    if(red==0)b=a;
    red++;
   }
      if(ulaz.eof());
else if(ulaz.bad()) throw std::logic_error  {"Datoteka je vjerovatno oštećena!\n"};
else throw std::logic_error{"Datoteka sadrzi besmislene podatke"};
   int kol=0;
   for(int i=0;i<b.size();i++){
    if(b[i]==',')kol++;
   }
    std::vector<std::vector<TipEl>> e(red);
    for(int i=0;i<red;i++){
     e[i].resize(kol+1);
    }
   ulaz.close();
   ulaz.open(s);
   for(int i=0;i<red;i++){
    for(int j=0;j<kol+1;j++){
     TipEl temp;
     char c;
     ulaz>>temp;

     if(j!=kol)ulaz>>c;
    e[i][j]=temp;
    }
   }
      if(ulaz.eof());
else if(ulaz.bad()) throw std::logic_error  {"Datoteka je vjerovatno oštećena!\n"};
else throw std::logic_error{"Datoteka sadrzi besmislene podatke"};
   v=e;
   return e;
  }
   std::vector<TipEl> &operator [](int i){
   return v[i];
  }
  void SacuvajUTekstualnuDatoteku(std::string s){
   std::ofstream izlaz(s);
   for(int i=0;i<v.size();i++){
    for(int j=0;j<v[i].size();j++){
     izlaz<<v[i][j];
     if(j!=v[i].size()-1)izlaz<<',';
    }izlaz  << std::endl;
   }
  }
  void SacuvajUBinarnuDatoteku(std::string s){
   std::ofstream izlaz(s, std::ios::binary);
   int a,b;
   a=v.size();
   b=v[0].size();
    izlaz.write(reinterpret_cast<char*>(&a), sizeof a);
    izlaz.write(reinterpret_cast<char*>(&b), sizeof b);
   for(int i=0;i<v.size();i++){
    for(int j=0;j<v[i].size();j++){
     izlaz.write(reinterpret_cast<char*>(&v[i][j]), sizeof v[i][j]);
    }
   }
  }
  void ObnoviIzBinarneDatoteke(std::string s){
    std::ifstream ulaz(s, std::ios::binary);
    if(!ulaz)throw std::logic_error {"Trazena datoteka ne postoji"};
    int a,b;
    ulaz.read(reinterpret_cast<char*>(&a),sizeof a);
    ulaz.read(reinterpret_cast<char*>(&b),sizeof b);
    v.resize(a);
    for(int i=0;i<a;i++)v[i].resize(b);
    for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
     ulaz.read(reinterpret_cast<char*>(&v[i][j]), sizeof v[i][j]);
    }
    }
  }
 };
 template <typename TipEl>
 std::ostream &operator <<(std::ostream &tok,const Matrica<TipEl> &m){
     int w(tok.width());
 for(int i = 0; i < m.v.size(); i++) {
 for(int j = 0; j < m.v[i].size(); j++)
 tok << std::setw(w) << m.v[i][j];
 tok << std::endl;
 }return tok;
  }
int main() {
try
    {
        Matrica<int> m0{2, 2};
        for (int i{0}; i < 2; i++)
            for (int j{0}; j < 2; j++){
                m0[i][j] = i + j;
            }
        m0.SacuvajUBinarnuDatoteku("matrica1.DAT");
        Matrica<int> m1("matrica1.DAT", true);
        std::cout << std::setw(6) << m1;
    }
    catch (const std::logic_error& e)
    {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
    
    std::cout << std::endl << std::endl;
    
    try
    {
        Matrica<double> m0{2, 2};
        for (int i{0}; i < 2; i++)
            for (int j{0}; j < 2; j++)
                m0[i][j] = i + j + 0.5;
        m0.SacuvajUBinarnuDatoteku("matrica2.DAT");
        Matrica<double> m1("matrica2.DAT", true);
        std::cout << std::setw(6) << m1;
    }
    catch (const std::logic_error& e)
    {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }

 return 0;
}