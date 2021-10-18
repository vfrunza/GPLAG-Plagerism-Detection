/B2017/2018: Zadaća 4, Zadatak 1

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <iomanip>
#include <initializer_list>
#include <vector>
#include <algorithm>
#include <tuple>
#include <memory>
#include <cmath>
/*
class Tim
{
     char ime_tima[20];
     int broj_odigranih;
     int broj_pobjeda;
     int broj_nerijesenih;
     int broj_poraza;
     int broj_datih;
     int broj_primljenih;
     int broj_poena;
public:
     Tim(const char ime[]) : broj_odigranih(0), broj_pobjeda(0), broj_nerijesenih(0), broj_poraza(0),
          broj_datih(0), broj_primljenih(0), broj_poena(0) {
          if (std::strlen(ime)>19) throw std::range_error("Predugacko ime tima");
          std::strcpy(ime_tima,ime);
     }
     void ObradiUtakmicu(int broj_datih, int broj_primljenih);
     const char *DajImeTima() const {
          return ime_tima;
     }
     int DajBrojPoena() const {
          return broj_poena;
     }
     int DajGolRazliku() const {
          return broj_datih-broj_primljenih;
     }
     void IspisiPodatke() const;
};

void Tim::ObradiUtakmicu(int broj_datih, int broj_primljenih)
{
     if (broj_datih<0 || broj_primljenih<0) throw std::range_error("Neispravan broj golova");
     broj_odigranih++;
     Tim::broj_datih+=broj_datih;
     Tim::broj_primljenih+=broj_primljenih;
     if (broj_datih>broj_primljenih) {
          broj_pobjeda++;
          broj_poena+=3;
     } else if (broj_datih==broj_primljenih) {
          broj_nerijesenih++;
          broj_poena+=1;
     } else broj_poraza++;
}

void Tim::IspisiPodatke() const
{
     std::cout << std::setw(20) << std::left << ime_tima << std::setw(4) << std::right << broj_odigranih << std::setw(4) << std::right << broj_pobjeda
               << std::setw(4) << std::right << broj_nerijesenih << std::setw(4) << std::right << broj_poraza << std::setw(4) << std::right << broj_datih
               << std::setw(4) << std::right << broj_primljenih << std::setw(4) << std::right << broj_poena << std::endl;
}

class Liga
{
     std::vector<std::shared_ptr<Tim>> timovi;
public:
     explicit Liga()=default;
     explicit Liga(std::initializer_list<Tim> lista_timova);
     ~Liga();
     Liga(const Liga &l);
     Liga(Liga &&l);
     Liga &operator =(const Liga &l);
     Liga &operator =(Liga &&l);
     void DodajNoviTim(const char ime_tima[]);
     void RegistrirajUtakmicu(const char tim1[], const char tim2[], int rez_1, int rez_2);
     void IspisiTabelu();
};

Liga::Liga(std::initializer_list<Tim> lista_timova)
{
     for (auto it=lista_timova.begin(); it!=lista_timova.end(); it++) {
          try {
               std::shared_ptr<Tim> p(new Tim(*it));
               timovi.push_back(p);
          } catch(std::bad_alloc) {
               for (int i=0; i<lista_timova.size(); i++)
                    timovi[i]=nullptr;
               throw;
          }
     }
}

Liga::~Liga()
{
     for (int i=0; i<timovi.size(); i++)
          timovi[i]=nullptr;
}

Liga::Liga(const Liga &l)
{
     try {
          timovi.resize(l.timovi.size());
          for (int i=0; i<l.timovi.size(); i++) {
               std::shared_ptr<Tim> p(new Tim(*l.timovi[i]));
               timovi[i]=p;
          }
     } catch(std::bad_alloc) {
          for (int i=0; i<l.timovi.size(); i++)
               timovi[i]=nullptr;
          throw;
     }
}

Liga::Liga(Liga &&l)
{
     timovi=std::move(l.timovi);
}

Liga &Liga::operator =(const Liga &l)
{
     int stara_duzina=timovi.size();
     if (l.timovi.size()>timovi.size()) {
          try {
               for (int i=timovi.size(); i<l.timovi.size(); i++) {
                    std::shared_ptr<Tim> p(new Tim(*l.timovi[i]));
                    timovi.push_back(p);
               }
          } catch(std::bad_alloc) {
               for (int i=timovi.size(); i<l.timovi.size(); i++)
                    timovi[i]=nullptr;
               timovi.resize(stara_duzina);
               throw;
          }
     }
     timovi.resize(l.timovi.size());
     for (int i=0; i<timovi.size(); i++) *timovi[i]=*l.timovi[i];
     return *this;
}

Liga &Liga::operator =(Liga &&l)
{
     timovi=std::move(l.timovi);
     return *this;
}

void Liga::DodajNoviTim(const char ime_tima[])
{
     for (int i=0; i<timovi.size(); i++)
          if (std::strcmp(timovi[i]->DajImeTima(),ime_tima)==0)
               throw std::logic_error("Tim vec postoji");
     std::shared_ptr<Tim> p(new Tim(ime_tima));
     timovi.push_back(p);
}

void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2)
{
     if (rezultat_1<0 || rezultat_2<0) throw std::range_error("Neispravan broj golova");
     bool pronadjen1(false), pronadjen2(false);
     for (int i=0; i<timovi.size(); i++) {
          if (std::strcmp(timovi[i]->DajImeTima(),tim1)==0) pronadjen1=true;
          if (std::strcmp(timovi[i]->DajImeTima(),tim2)==0) pronadjen2=true;
     }
     if (!(pronadjen1 && pronadjen2))
          throw std::logic_error("Tim nije nadjen");
     for (int i=0; i<timovi.size(); i++) {
          if (std::strcmp(timovi[i]->DajImeTima(),tim1)==0)
               timovi[i]->ObradiUtakmicu(rezultat_1,rezultat_2);
          else if (std::strcmp(timovi[i]->DajImeTima(),tim2)==0)
               timovi[i]->ObradiUtakmicu(rezultat_2,rezultat_1);
     }
}

void Liga::IspisiTabelu()
{
     std::sort(timovi.begin(),timovi.end(),[](std::shared_ptr<Tim> p_tim1, std::shared_ptr<Tim> p_tim2) {
          if (p_tim1->DajBrojPoena()!=p_tim2->DajBrojPoena()) return p_tim1->DajBrojPoena()>p_tim2->DajBrojPoena();
          else if (p_tim1->DajBrojPoena()==p_tim2->DajBrojPoena() && p_tim1->DajGolRazliku()!=p_tim2->DajGolRazliku()) return p_tim1->DajGolRazliku()>p_tim2->DajGolRazliku();
          else if (p_tim1->DajBrojPoena()==p_tim2->DajBrojPoena() && p_tim1->DajGolRazliku()==p_tim2->DajGolRazliku()) return std::strcmp(p_tim1->DajImeTima(),p_tim2->DajImeTima())<0;
     });
     for (int i=0; i<timovi.size(); i++)
          timovi[i]->IspisiPodatke();
} */
using namespace std;
double eps=0.00000000001;
double pi=atan(1)*4;

bool jednako(double x, double y){
     return (fabs(x-y)<eps*(fabs(x)+fabs(y)));
}

class NepreklapajucaKugla{
private:
     double xx,yy,zz,cc;
public:
     explicit NepreklapajucaKugla(double r = 0){
         
          if(r<0) throw domain_error("Ilegalan poluprecnik");
          cc=r; xx=0; yy=0; zz=0;
     }
     NepreklapajucaKugla(double x, double y, double z, double r = 0){
        
          if(r<0) throw domain_error("Ilegalan poluprecnik");
          cc=r; xx=x; yy=y; zz=z;
     }
     explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0){
          
          if(r<0) throw domain_error("Ilegalan poluprecnik");
          cc=r;
          xx=get<0>(centar);
          yy=get<1>(centar);
          zz=get<2>(centar);
     }
     double DajX() const { return xx;}
     double DajY() const {return yy;}
     double DajZ() const {return zz;}
     std::tuple<double, double, double> DajCentar() const{
          return make_tuple(xx,yy,zz);
     }
     double DajPoluprecnik() const {
          return cc;
     }
     double DajPovrsinu() const{
          return 4*pi*cc*cc;
     }
     double DajZapreminu() const{return (4*pi*cc*cc*cc)/3;}
     NepreklapajucaKugla &PostaviX(double x) {
           xx=x; return *this;
     }
     NepreklapajucaKugla &PostaviY(double y) { yy=y; return *this;}
     NepreklapajucaKugla &PostaviZ(double z) { zz=z; return *this;}
     NepreklapajucaKugla &PostaviCentar(double x, double y, double z){
          xx=x; yy=y; zz=z; return *this;
     }
     NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar){
          xx=get<0>(centar);;
          yy=get<1>(centar);;
          zz=get<2>(centar);;
          return *this;
     }
    
     NepreklapajucaKugla &PostaviPoluprecnik(double r) { 
          
          if(r<0) throw domain_error("Ilegalan poluprecnik");cc=r;return *this;}
     void Ispisi() const{
          cout<<"{("<<xx<<","<<yy<<","<<zz<<"),"<<cc<<"}"<<endl;
     }
     void Transliraj(double delta_x, double delta_y, double delta_z){
          xx+=delta_x; yy+=delta_y; zz+=delta_z;
     }
     bool DaLiSadrzi(const NepreklapajucaKugla &k) const{
         // return DaLiSePreklapaju(*this,k);
     }
     friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
          return sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())+(k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())+(k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ()));
     }

};

int main()
{
    /* try {
          Liga liga {"Borac","Celik","Jedinstvo","Sarajevo","Zeljeznicar","Zrinjski"};
          do {
               liga.IspisiTabelu();
               char unos1[20], unos2[20];
               std::cout << std::endl << "Unesite ime prvog tima (ENTER za kraj): ";
               if (std::cin.peek()=='\n') return 0;
               std::cin.getline(unos1,sizeof unos1);
               std::cout << "Unesite ime drugog tima: ";
               std::cin.getline(unos2,sizeof unos2);
               int golovi1,golovi2;
               std::cout << "Unesite broj postignutih golova za oba tima: ";
               std::cin >> golovi1 >> golovi2;
               try {
                    liga.RegistrirajUtakmicu(unos1,unos2,golovi1,golovi2);
               } catch(std::logic_error izuzetak) {
                    std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
               } catch(std::range_error izuzetak) {
                    std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
               }
               std::cout << std::endl;
               std::cin.ignore(10000,'\n');
          } while(1);
     } catch(std::bad_alloc) {
          std::cout << "Problemi sa memorijom!" << std::endl;
     } */
    
     return 0;
}
