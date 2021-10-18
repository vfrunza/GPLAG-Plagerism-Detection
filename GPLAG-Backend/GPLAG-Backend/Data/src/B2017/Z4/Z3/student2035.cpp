/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <utility>
#include <stdexcept>
#include <iomanip>

class Datum {
      int dan, mjesec, godina;
      friend class Pregled;
      void TestIspravnostiDatuma(int a, int b, int c) {
            int mjeseci[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if(c%400==0 || (c%100!=0 && c%4==0))  mjeseci[1]++; 
            if(a<1 || b<1 || b>12) throw std::domain_error("Neispravan datum"); 
            if(a>mjeseci[b-1]) throw std::domain_error("Neispravan datum"); 
            
            
      }
      public:
      Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
      void Postavi(int dan, int mjesec, int godina) {
            TestIspravnostiDatuma(dan, mjesec, godina); 
            this->dan=dan; this->mjesec=mjesec; this->godina=godina; 
      }
      std::tuple<int, int, int> Ocitaj() const { return std::tie(dan, mjesec, godina); }
      void Ispisi() const { std::cout << dan << "/" << mjesec << "/" << godina; }
};

class Vrijeme {
      int sati, minute; 
      friend class Pregled; 
      void TestIspravnostiVremena(int h, int m) {
            if(h<0 || h>23 || m<0 || m>59) throw std::domain_error("Neispravno vrijeme"); 
      }
      public: 
      Vrijeme(int sati, int minute) { Postavi(sati, minute); }
      void Postavi(int sati, int minute) {
            TestIspravnostiVremena(sati, minute);
            this->sati=sati; this->minute=minute; }
      std::pair<int, int> Ocitaj() const { std::pair<int,int> pomocni=std::make_pair(sati, minute); return pomocni;  }
      void Ispisi() const { std::cout << std::setw(2) << std::setfill('0') << sati << ":" << std::setw(2) << minute; }
}; 

class Pregled {
      friend class Pregledi; 
      std::string pacijent; 
      Datum zakazani_datum; 
      Vrijeme zakazano_vrijeme; 
      public: 
      Pregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : pacijent(ime_pacijenta), zakazani_datum(datum_pregleda.dan, datum_pregleda.mjesec, datum_pregleda.godina), zakazano_vrijeme(vrijeme_pregleda.sati, vrijeme_pregleda.minute) {}
      Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : pacijent(ime_pacijenta), zakazani_datum(dan_pregleda,mjesec_pregleda,godina_pregleda), zakazano_vrijeme(sati_pregleda,minute_pregleda) {}
      void PromijeniPacijenta(const std::string &ime_pacijenta) { pacijent=ime_pacijenta; }
      void PromijeniDatum(const Datum &novi_datum) { zakazani_datum.Postavi(novi_datum.dan, novi_datum.mjesec, novi_datum.godina); }
      void PromijeniVrijeme(const Vrijeme &novo_vrijeme) { zakazano_vrijeme.Postavi(novo_vrijeme.sati, novo_vrijeme.minute); }
      void PomjeriDanUnazad();
      void PomjeriDanUnaprijed(); 
      std::string DajImePacijenta() const { return pacijent; }
      Datum DajDatumPregleda() const  { return zakazani_datum; } 
      Vrijeme DajVrijemePregleda() const { return zakazano_vrijeme; }
      static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
      void Ispisi() {
            std::cout << std::setw(30) << std::left << pacijent; 
            zakazani_datum.Ispisi(); std::cout << " "; zakazano_vrijeme.Ispisi();  std::cout << std::endl; 
      }
};

void Pregled::PomjeriDanUnazad() { //provjeri da li radi
      int niz_mjeseci[]{31 ,28 ,31 ,30 ,31 ,30 ,31 ,31 ,30 ,31 ,30 ,31}; 
      if(zakazani_datum.dan>1) zakazani_datum.Postavi(zakazani_datum.dan-1, zakazani_datum.mjesec, zakazani_datum.godina); 
      else if(zakazani_datum.mjesec>1) {
      if((zakazani_datum.godina%4==0 && zakazani_datum.godina%100!=0) || zakazani_datum.godina%400==0) niz_mjeseci[1]++;
      zakazani_datum.Postavi(niz_mjeseci[zakazani_datum.mjesec-2], zakazani_datum.mjesec-1, zakazani_datum.godina); }
      else zakazani_datum.Postavi(31, 12, zakazani_datum.godina-1); 
}

void Pregled::PomjeriDanUnaprijed() {
      int niz_mjeseci[]{31 ,28 ,31 ,30 ,31 ,30 ,31 ,31 ,30 ,31 ,30 ,31}; //ubaci za prestpnu
      if((zakazani_datum.godina%4==0 && zakazani_datum.godina%100!=0) || zakazani_datum.godina%400==0) niz_mjeseci[1]++;
      if(zakazani_datum.dan<niz_mjeseci[zakazani_datum.mjesec-1]) zakazani_datum.Postavi(zakazani_datum.dan+1, zakazani_datum.mjesec, zakazani_datum.godina); 
      else if(zakazani_datum.mjesec!=12) zakazani_datum.Postavi(1, zakazani_datum.mjesec+1, zakazani_datum.godina); 
      else zakazani_datum.Postavi(1,1, zakazani_datum.godina+1); 
}

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) {
      
      if (p1.zakazani_datum.godina<p2.zakazani_datum.godina) return true;
      if (p1.zakazani_datum.godina>p2.zakazani_datum.godina) return false; 
      if (p1.zakazani_datum.mjesec>p2.zakazani_datum.mjesec) return false; 
      if (p1.zakazani_datum.mjesec<p2.zakazani_datum.mjesec) return true; 
      if (p1.zakazani_datum.dan>p2.zakazani_datum.dan) return false; 
      if (p1.zakazani_datum.dan<p2.zakazani_datum.dan) return true;
      if (p1.zakazano_vrijeme.sati>p2.zakazano_vrijeme.sati) return false;
      if (p1.zakazano_vrijeme.sati<p2.zakazano_vrijeme.sati) return true; 
      return p1.zakazano_vrijeme.minute<p2.zakazano_vrijeme.minute; 
}


class Pregledi {
      
      public: 
      explicit Pregledi(int max_br_pregleda); 
      Pregledi(std::initializer_list<Pregled> spisak_pregleda); 
      ~Pregledi();
      Pregledi(const Pregledi &pregledi); 
      Pregledi(Pregled &&pregledi); 
      Pregledi &operator=(const Pregledi &pregledi);
      Pregledi &operator=(Pregledi &&pregledi); 
      void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
      void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
      void RegistrirajPregled(Pregled *pregled);
      
      
}; 


int main ()
{
	return 0;
}
