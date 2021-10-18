/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>

class Datum {
  int d, m,g;
  public:
  Datum(int dan, int mjesec, int godina){
      if ( dan < 1 && dan > 31) throw std::domain_error("Neispravan datum");
      else d = dan;
      if( mjesec < 1 && mjesec > 12) throw std::domain_error("Neispravan datum");
      else m = mjesec;
      if(godina < 0 ) throw std::domain_error("Neispravan datum");
      else g = godina;
  }
  
  void Postavi(int dan, int mjesec, int godina){
      if ( dan < 1 && dan > 31) throw std::domain_error("Neispravan datum");
      else d = dan;
      if( mjesec < 1 && mjesec > 12) throw std::domain_error("Neispravan datum");
      else m = mjesec;
      if(godina < 0 ) throw std::domain_error("Neispravan datum");
      else g = godina;
  }
  
  friend ostream &operator <<(std::ostream &tok, Datum d){
    tok<<d.d<<"/"<<d.m<<"/"<<d.g<<std::endl;
    return tok;
  }
  
  std::tuple<int,int,int> Ocitaj() const;
  void Ispisi() const{
      std::cout
  }
};

int main ()
{
	return 0;
}
