/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
int ch(char x){return x-48;}
class GradjaninBiH
{
  public:
    std::string ime;
    long long JMBG;
    GradjaninBiH* prije;
    static GradjaninBiH* posljednji;
    static bool ValidanDatum(int dan, int mj, int god);
    static int Ocitaj(long long jmbg, int ind);
  public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol);
    
    GradjaninBiH& operator=(const GradjaninBiH& g) = delete;
    GradjaninBiH(const GradjaninBiH& g) = delete;
    
    std::string DajImeIPrezime() const { return ime; }
    long long int DajJMBG() const { return JMBG; }
    int DajDanRodjenja() const { return Ocitaj(JMBG, 0); }
    int DajMjesecRodjenja() const { return Ocitaj(JMBG, 1); }
    int DajGodinuRodjenja() const { return Ocitaj(JMBG, 2); }
    int DajSifruRegije() const { return Ocitaj(JMBG, 3); }
    Pol DajPol() const { return Pol(Ocitaj(JMBG, 4) >= 500); }
    void PromijeniImeIPrezime(std::string novo_ime) { ime = novo_ime; }
    ~GradjaninBiH();
};
GradjaninBiH* GradjaninBiH::posljednji = nullptr;

    bool GradjaninBiH::ValidanDatum(int dan, int mj, int god)
    {
        int niz[]{31,28,31,30,31,30,31,31,30,31,30,31};
        if(god%4 == 0 && !(god%400 != 0 && god % 100 == 0)) niz[1]++;
        if(mj < 0 || mj > 12 || dan > niz[mj-1] || dan < 0 || god <= 1917 || god > 2017 ) return false;
        return true;
    }
    int GradjaninBiH::Ocitaj(long long jmbg, int ind)
    {
      auto j = std::to_string(jmbg);
      if(j.size() == 12) j = "0" + j;
      int v[] = {ch(j[0])*10+ch(j[1]), ch(j[2])*10+ch(j[3]), ch(j[4])*100+ch(j[5])*10+ch(j[6]), 
                              ch(j[7])*10+ch(j[8]), ch(j[9])*100+ch(j[10])*10+ch(j[11]), ch(j[12])};
      if(v[2] > 917) v[2]+=1000;
      else if(v[2] <= 17) v[2]+=2000;
      return v[ind];
    }
    GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long jmbg)
    {
      auto s = std::to_string(jmbg);
      int c[13];
      
      if(s.size()==12) s = "0" + s;
      for(int i=0; i<13; i++) c[i] = s[i]-'0';
      
        if( (s.size() != 13) || !ValidanDatum(Ocitaj(jmbg, 0), Ocitaj(jmbg, 1), Ocitaj(jmbg, 2)) || 
          (11 - (7*(c[0]+c[6]) + 6*(c[1]+c[7]) + 5*(c[2]+c[8]) + 4*(c[3]+c[9]) + 3*(c[4]+c[10]) + 2*(c[5]+c[11])) % 11) % 11  != c[12]) 
            throw std::logic_error("JMBG nije validan");
      auto p = posljednji;
      if(posljednji == nullptr) this->prije = nullptr;
      while(p != nullptr)
      {
        if(p->JMBG == jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        p = p->prije;
      }
      prije = posljednji;
      posljednji = this;
      GradjaninBiH::ime = ime_i_prezime;
      GradjaninBiH::JMBG = jmbg;
    }
    
  GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol)
  {
      if(!ValidanDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja) || sifra_regije < 0 || sifra_regije > 99)
          throw std::logic_error("Neispravni podaci");
      
      auto po = posljednji;
      int niz[500];
      int vel = 0;
      while(po != nullptr) 
      {
        if(Ocitaj(po->JMBG, 0) == dan_rodjenja && Ocitaj(po->JMBG, 1) == mjesec_rodjenja && Ocitaj(po->JMBG, 2) == godina_rodjenja && 
           Ocitaj(po->JMBG, 3) == sifra_regije) niz[vel++] = Ocitaj(po->JMBG, 4);
        po = po->prije;
      }
      int min = 0;
      if(pol == Zensko) min = 500;
      for( ;; min++)
      {
        if(pol == Zensko && min >= 1000) throw "xx";
        else if (pol == Musko && min >= 500) throw "xy";
        if(std::count(niz, niz+vel, min) == 0)
        {
          std::string j = std::to_string(dan_rodjenja);
          if(j.size() == 1) j = "0" + j;
          auto p = std::to_string(mjesec_rodjenja);
          if(p.size() == 1) p = "0" + p;
          j += p;
          p = std::to_string(godina_rodjenja);
          p = p.substr(1, p.size());
          j += p;
          p = std::to_string(sifra_regije);
          if(p.size() == 1) p = "0" + p;
          j += p;
          p = std::to_string(min);
          if(p.size() == 1) p = "0" + p;
          if(p.size() == 2) p = "0" + p;
          j += p;
      
          j += "0";
          auto s = j;
          int c[13];
    
          if(s.size()==12) s = "0" + s;
          for(int i=0; i<13; i++) c[i] = s[i]-'0';
          j[12] = '0' +  (11 - (7*(c[0]+c[6]) + 6*(c[1]+c[7]) + 5*(c[2]+c[8]) + 4*(c[3]+c[9]) + 3*(c[4]+c[10]) + 2*(c[5]+c[11])) % 11) % 11;
          if(j[12]  == '0' + 10) continue;
          if(j[0] == '0') j = j.substr(1, j.size());
          GradjaninBiH::JMBG =std::stoll(j);
          GradjaninBiH::ime = ime_i_prezime;
          prije = posljednji;
          posljednji = this;
          break;
        }
    }
  }
  GradjaninBiH::~GradjaninBiH()
  {
    if(posljednji == this) posljednji = prije;
    else if(posljednji != nullptr)
    {
      GradjaninBiH* p = posljednji;
      while(p != nullptr)
      {
        if(p -> prije == this)
        {
          p -> prije = this -> prije;
          break;
        }
        p = p -> prije;
      }
    }
  }
int main ()
{
 std::string ime;
 long long jmbg;
 char x;
 int N, N2, d, m, g, reg;
 GradjaninBiH** gradjani, **gradjani2;
 std::cout<< "Koliko gradjana zelite unijeti po JMBG? \n";
 std::cin>>N;
 
  try
  {
    gradjani = nullptr;
    gradjani = new GradjaninBiH*[N];
    for(int i=0; i<N; i++) gradjani[i] = nullptr;
    for(int i=0; i<N; i++)
    {
      std::cout<< "Unesite ime i prezime (u istom redu): \n";
      std::cin.ignore(1000, '\n');
      std::getline(std::cin, ime);
      std::cout<< "Unesite JMBG: \n";
      std::cin>> jmbg;
      try 
      {
        gradjani[i] = new GradjaninBiH(ime, jmbg);
        std::cout<< "Unijeli ste gradjanina "<<ime;
        std::cout<<" rodjenog "<<gradjani[i]->DajDanRodjenja()<<"."<<gradjani[i]->DajMjesecRodjenja()<<"."<<gradjani[i]->DajGodinuRodjenja();
        std::cout<< " u regiji "<< gradjani[i]->DajSifruRegije()<<", "<< (gradjani[i]->DajPol() ? "zensko." : "musko.")<<std::endl;
      }
      catch (std::logic_error error) 
      {
        std::cout << error.what() << std::endl;
        i--;
      }
    }
  }
  catch(std::bad_alloc)
  {
    if(!gradjani)
      for(int i=0;i<N; i++) delete gradjani[i];
    delete[] gradjani;
  }
  
  std::cout<< "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? \n";
  std::cin>> N2;
  try
  {
    gradjani2 = nullptr;
    gradjani2 = new GradjaninBiH*[N2];
    for(int i=0;i<N2;i++) gradjani2[i] = nullptr;
    for(int i=0;i<N2;i++)
    {
      std::cout<<"Unesite ime i prezime (u istom redu): \n";
      std::cin.ignore(1000,'\n');
      std::getline(std::cin, ime);
      std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): \n";
      std::cin>>d>>x>>m>>x>>g;
      std::cout<< "Unesite sifru regije: \n";
      std::cin>>reg;
      std::cout<< "Unesite M za musko, Z za zensko: \n";
      std::cin>>x;
      try
      {
        gradjani2[i] = new GradjaninBiH(ime, d, m, g, reg, GradjaninBiH::Pol(x != 'M'));
        std::cout<< "Unijeli ste gradjanina "<<ime;
        std::cout<< " JMBG: "<< gradjani2[i]->DajJMBG()<<".\n";
      }
      catch(std::logic_error e)
      {
        std::cout<<e.what()<<std::endl;
        i--;
      }
    }
  }
  catch(std::bad_alloc)
  {
    if(!gradjani2)
    for(int i=0;i<N2;i++) delete gradjani2[i];
    delete[] gradjani2;
  }
for(int i=0;i<N2;i++) delete gradjani2[i];
    delete[] gradjani2;
  for(int i=0;i<N;i++) delete gradjani[i];
    delete[] gradjani;
	return 0;
}