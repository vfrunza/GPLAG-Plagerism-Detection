/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <algorithm> 
class GradjaninBiH {
  std::string ime; 
  long long JMBG;
  GradjaninBiH *prethodni{};
  static GradjaninBiH *posljednji;
  static std::string Pretvori(long long JMBG) {
    long long tmp = JMBG; std::string ret = "";
    while (tmp) {
      ret += (tmp % 10) + '0';
      tmp /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
public:
  enum Pol {Musko, Zensko};
  GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
    int vrijednosti[13]{};
    std::string konvertovan = Pretvori(jmbg);
    for (int i = 0; i < konvertovan.length(); i++)
      vrijednosti[i] = konvertovan[i] - '0';
    int Dan = vrijednosti[0] * 10 + vrijednosti[1];
    int Mjesec = vrijednosti[2] * 10 + vrijednosti[3];
    int Godina = vrijednosti[4] * 100 + vrijednosti[5] * 10 + vrijednosti[6];
    int Regija = vrijednosti[7] * 10 + vrijednosti[8];
    int Kod = vrijednosti[9] * 100 + vrijednosti[10] * 10 + vrijednosti[11];
    int Kontrolna = vrijednosti[12];
    if (Kontrolna == 10) throw std::domain_error("JMBG nije validan");
    int Vrijednost = 11 - ((7 * (vrijednosti[0] + vrijednosti[6]) + 6 * (vrijednosti[1] + vrijednosti[7]) + 5 * (vrijednosti[2] + vrijednosti[8]) + 4 * (vrijednosti[3] + vrijednosti[9]) + 3 * (vrijednosti[4] + vrijednosti[10]) + 2 * (vrijednosti[5] + vrijednosti[11])) % 11);
    if (Vrijednost == 11) Vrijednost = 0;
    //std::cout << Kontrolna << " " << Vrijednost << "\n";
    if (Kontrolna != Vrijednost) throw std::domain_error("JMBG nije validan");
    int broj_dana[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((Godina % 4 == 0 && Godina % 100 != 0) || Godina % 400 == 0) broj_dana[2]++;
    if (Dan > broj_dana[Mjesec] || Dan < 0 || Mjesec > 12 || Mjesec < 1) throw std::domain_error("JMBG nije validan");
    ime = ime_i_prezime;
    JMBG = jmbg;
    if (!posljednji)
    for (auto x = posljednji; x != nullptr; x = x -> prethodni) {
      if (JMBG == x->JMBG) {
        throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
      }
    }  
    if (!posljednji) { posljednji = this; prethodni = 0; } 
    else {
      prethodni = posljednji; 
      posljednji = this;
    }
  }
  GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
    int Dan = dan_rodjenja;
    int Mjesec = mjesec_rodjenja; 
    int Godina = godina_rodjenja;
    int broj_dana[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((Godina % 4 == 0 && Godina % 100 != 0) || Godina % 400 == 0) broj_dana[2]++;
    if (Mjesec > 12 || Mjesec < 1) throw std::domain_error("JMBG nije validan");
    if (Dan > broj_dana[Mjesec] || Dan < 0 || Mjesec > 12 || Mjesec < 1) throw std::domain_error("JMBG nije validan");
    if (!(sifra_regije >= 0 && sifra_regije <= 99)) throw std::domain_error("JMBG nije validan");
    std::string stvori = ""; std::string pomocni = "";
    while (Dan) {
      pomocni += (Dan % 10) + '0';
      Dan /= 10;
    }
    if (pomocni.length() == 1) pomocni += "0";
    reverse(pomocni.begin(), pomocni.end()); stvori += pomocni; pomocni = "";
    while (Mjesec) {
      pomocni += (Mjesec % 10) + '0';
      Mjesec /= 10;
    }
    if (pomocni.length() == 1) pomocni += "0";
    reverse(pomocni.begin(), pomocni.end()); stvori += pomocni; pomocni = "";
    while (Godina > 10) {
      pomocni += (Godina % 10) + '0';
      Godina /= 10;
    }
    reverse(pomocni.begin(), pomocni.end());
    stvori += pomocni; pomocni = "";
    int Sifra = sifra_regije;
    while (Sifra) {
      pomocni += (Sifra % 10) + '0';
      Sifra /= 10;
    }
    if (pomocni.length() == 1) pomocni += "0";
    reverse(pomocni.begin(), pomocni.end()); stvori += pomocni; pomocni = "";
    std::string ProvjeraJMBG = stvori;
    int lowerlimit, upperlimit;
    if (pol == Pol::Musko) {
      lowerlimit = 0;
      upperlimit = 499;
    }
    else {
      lowerlimit = 500;
      upperlimit = 999;
    }
    for (int Vrijednost = lowerlimit; Vrijednost <= upperlimit; Vrijednost++) {
      int tmp = Vrijednost;
      std::string probni = "";
      ProvjeraJMBG = stvori; 
      while (tmp) {
        probni += (tmp % 10) + '0';
        tmp /= 10;
      }
      while (probni.length() < 3) probni += "0";
      reverse(probni.begin(), probni.end());
      ProvjeraJMBG += probni;
      int vri[13]{};
      for (int i = 0; i < ProvjeraJMBG.length(); i++)
        vri[i] = ProvjeraJMBG[i] - '0';
      int cifra = 11 - ((7 * (vri[0] + vri[6]) + 6 * (vri[1] + vri[7]) + 5 * (vri[2] + vri[8]) + 4 * (vri[3] + vri[9]) + 3 * (vri[4] + vri[10]) + 2 * (vri[5] + vri[11])) % 11);
      if (cifra == 11) cifra = 0;
      if (cifra == 10) continue;
      ProvjeraJMBG += (cifra + '0');
      vri[12] = cifra;
      long long Value = 0;
      long long zadana = 1;
      for (int i = 12; i >= 0; i--, zadana *= 10)
        Value += (vri[i]) * zadana; 
      
      bool Postoji = 0;
      if (!posljednji)
      for (auto xx = posljednji; xx != nullptr; xx = xx -> prethodni) {
        if (Value == xx -> JMBG) {
          Postoji = 1;
          break;
        }
      }
      if (Postoji) continue;
      ime = ime_i_prezime;
      JMBG = Value;
      GradjaninBiH(ime_i_prezime, Value);
      break;
    }
  }
  std::string DajImeIPrezime() const { return ime; }
  long long int DajJMBG() const { return JMBG; }
  int DajDanRodjenja() const { std::string konvertovan = Pretvori(JMBG); return (konvertovan[0] - '0') * 10 + (konvertovan[1] - '0'); }
  int DajMjesecRodjenja() const { std::string konvertovan = Pretvori(JMBG); return (konvertovan[2] - '0') * 10 + (konvertovan[3] - '0'); }
  int DajGodinuRodjenja() const { 
    std::string konvertovan = Pretvori(JMBG); 
    int add = 0;
    if (konvertovan[4] == '0') add = 1000;
    return 1000 + add + (konvertovan[4] - '0') * 100 + (konvertovan[5] - '0') * 10 + (konvertovan[6] - '0'); }
  int DajSifruRegije() const { std::string konvertovan = Pretvori(JMBG); return (konvertovan[7] - '0') * 10 + (konvertovan[8] - '0'); }
  Pol DajPol() const { 
    std::string konvertovan = Pretvori(JMBG); int value = (konvertovan[9] - '0') * 100 + (konvertovan[10] - '0') * 10 + (konvertovan[11] - '0');
    if (value >= 0 && value < 500) return Pol(Musko);
    else return Pol(Zensko);
  }
  void PromijeniImeIPrezime(std::string novo_ime) { ime = novo_ime; }
};
GradjaninBiH *GradjaninBiH::posljednji = nullptr;
int main ()
{
  int N1, N2;
  std::cout << "Koliko gradjana zelite unijeti po JMBG? \n"; std::cin >> N1;
  std::cin.clear();
  std::cin.ignore(10000, '\n');
  for (int i = 0; i < N1; i++) {
    std::string Imence;
    long long int jmbgic; 
    while (1) {
      std::cout << "Unesite ime i prezime (u istom redu): \n"; getline(std::cin, Imence);
      std::cout << "Unesite JMBG: \n"; std::cin >> jmbgic;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      try {
        GradjaninBiH g(Imence, jmbgic);
        std::cout << "Unijeli ste gradjanina " << g.DajImeIPrezime() << " rodjenog " << g.DajDanRodjenja() << "." << g.DajMjesecRodjenja() << "." << g.DajGodinuRodjenja() << " u regiji " << g.DajSifruRegije() << ", ";
        if (g.DajPol() == GradjaninBiH::Pol::Musko) std::cout << "musko.\n";
        else std::cout << "zensko.\n";
        break;
      }
      catch(...) {
        std::cout << "JMBG nije validan\n";
        
      }
    }
  }
  std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? \n"; std::cin >> N2;
  std::cin.clear();
  std::cin.ignore(10000, '\n');
  for (int i = 0; i < N2; i++) {
    std::string Imence;
    char c, sp;
    int d, m, g;
    GradjaninBiH::Pol pp;
    int sifra;
    while (1) {
      std::cout << "Unesite ime i prezime (u istom redu): \n"; getline(std::cin, Imence);
      std::cout << "Unesite datum rodjenja (format dd/mm/gggg): \n"; std::cin >> d >> c >> m >> c >> g;
      std::cout << "Unesite sifru regije: \n"; std::cin >> sifra;
      std::cout << "Unesite M za musko, Z za zensko: \n"; std::cin >> sp;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      if (sp == 'M') pp = GradjaninBiH::Pol::Musko;
      else pp = GradjaninBiH::Pol::Zensko;
      try {
        GradjaninBiH h(Imence, d, m, g, sifra, pp);
        std::cout << "Unijeli ste gradjanina " << h.DajImeIPrezime() << " JMBG: " << h.DajJMBG() << ".\n";
        break;
      }
      catch(...) {
        std::cout << "Neispravni podaci\n";
      }
    }
  }
  
	return 0;
}