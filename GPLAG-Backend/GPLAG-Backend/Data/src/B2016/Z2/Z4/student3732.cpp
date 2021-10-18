#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

static size_t alocirano(0);
static int brojac_new(0);
static int brojac_deleteniz(0);
static size_t alokacije[20];
static size_t RAM = 22;

void *operator new[] (size_t vel)
{
    if (RAM < alocirano+vel) throw std::bad_alloc();
    alokacije[brojac_new]=vel;
    brojac_new++;
    alocirano+=vel;   
    return std::malloc (vel);
}

void operator delete [] ( void* ptr) {
  brojac_deleteniz++;
  free(ptr);
}

int PotencijalniKrivci(char **&mat, const std::vector<std::string> &v) {
  int n(v.size());
  mat = new char*[n];
  for(int i = 0; i < n; i++) mat[i] = nullptr;
  try {
    for(int i = 0; i < n; i++) {
      mat[i] = new char[v[i].length() + 1];
      std::strcpy(mat[i], v[i].c_str());
    }
  }
  catch(...) {
    for(int i = 0; i < n; i++) delete[] mat[i];
    delete[] mat;
    throw;
  }
  return n;
}

int OdbaciOptuzbu(char **&mat, int n, const std::string &ime) {
  int gdje_je(-1), brojac(0), j(0);
  for(int i = 0; i < n; i++)
    if(mat[i] != nullptr)
      if(std::strcmp(mat[i], ime.c_str()) == 0) {
        gdje_je = i; break;
      }
  if(gdje_je == -1)
    throw std::domain_error("Osoba sa imenom " + ime + " nije bila optuzena");
  delete[] mat[gdje_je];
  mat[gdje_je] = nullptr;
  for(int i = 0; i < n; i++)
    if(mat[i] != nullptr) brojac++;
  if(n - brojac <= 10) return n;
  char **novi;
  try {
    novi = new char*[brojac];
  }
  catch(...) {
    return n;
  }
  for(int i = 0; i < n; i++)
    if(mat[i] != nullptr) novi[j++] = mat[i];
  delete[] mat;
  mat = novi;
  return brojac;
}

int DodajOptuzbu(char **&mat, int n, const std::string &ime) {
  char *prostor(new char[ime.length() + 1]);
  std::strcpy(prostor, ime.c_str());
  int gdje_je(-1);
  for(int i = 0; i < n; i++)
    if(mat[i] == nullptr) {
      gdje_je = i; break;
    }
  if(gdje_je != -1) {
    mat[gdje_je] = prostor;
    return n;
  }
  char **novi;
  try {
    novi = new char*[n + 1];
  }
  catch(...) {
    delete[] prostor;
    throw;
  }
  for(int i = 0; i < n; i++) novi[i] = mat[i];
  novi[n] = prostor;
  delete[] mat;
  mat = novi;
  return n + 1;
}
 
void IzlistajOptuzbu(char **mat, int n) {
  for(int i = 0; i < n; i++)
    if(mat[i] != nullptr) std::cout << mat[i] << std::endl;
}



	
void dealociraj(char **mat, int n){
  for(int i = 0; i < n; i++) delete[] mat[i];
    delete[] mat;
}


int main(){
  //AT11 - vise od 10 brisanja, ali alokacija ne uspije
    char** nizPotencijalnih;
    if(sizeof(char*) == 8) RAM = 200;
    else RAM = 150;
    std::vector<std::string> imena = {"Selena", "Murga", "Abid", "Avdija", "Pisonja", "Zuga", "Alma", "Brut", "Gile", "Seki", "Svabo", "Sam", "Gosp.Brams", "Gigo"};
    int n = PotencijalniKrivci(nizPotencijalnih, imena);
    n = OdbaciOptuzbu(nizPotencijalnih, n, "Murga");
    n = OdbaciOptuzbu(nizPotencijalnih, n, "Abid");
    n = OdbaciOptuzbu(nizPotencijalnih, n, "Avdija");
    n = OdbaciOptuzbu(nizPotencijalnih, n, "Pisonja");
    n = OdbaciOptuzbu(nizPotencijalnih, n, "Zuga");
    n = OdbaciOptuzbu(nizPotencijalnih, n, "Alma");
    n = OdbaciOptuzbu(nizPotencijalnih, n, "Brut");
    n = OdbaciOptuzbu(nizPotencijalnih, n, "Gile");
    n = OdbaciOptuzbu(nizPotencijalnih, n, "Seki");
    n = OdbaciOptuzbu(nizPotencijalnih, n, "Svabo");
    

    n = OdbaciOptuzbu(nizPotencijalnih, n, "Sam");
    n = OdbaciOptuzbu(nizPotencijalnih, n, "Selena");
    std::cout << "Treba ostati isti broj elemenata: " << n << std::endl;
    
    
   
    std::cout << "New pozvan " << brojac_new << " puta,  delete [] pozvan " << brojac_deleteniz << " puta, a alocirano ukupno " << alocirano << " bajta i to redom: ";
    for (int i=0; i<brojac_new;i++) std::cout << alokacije[i] << " ";
    dealociraj(nizPotencijalnih, n);
}



//zasto ovo ne radi? 
int __main(){
//AT10 - da li je brisanje ispravno u OdbaciOptuzbu nakon 10 obrisanih
  char **nizPotencijalnih;
    std::vector<std::string> imena = {"Fudo", "Pero", "Meho", "Fata", "Bajro", "Luca", "Jovo", "Amina", "Elma", "Selma", "Admira", "Zora", "Ivanka"};
    int n = PotencijalniKrivci( nizPotencijalnih, imena);
    int m;
    m = OdbaciOptuzbu(nizPotencijalnih, n, "Fudo");
    if(m != n) std::cout << "NOK" << std::endl;
    
    m = OdbaciOptuzbu(nizPotencijalnih, m, "Pero");
    if(m != n) std::cout << "NOK" << std::endl;
    
    m = OdbaciOptuzbu(nizPotencijalnih, m, "Meho");
    if(m != n) std::cout << "NOK" << std::endl;
    
    m = OdbaciOptuzbu(nizPotencijalnih, m, "Fata");
    if(m != n) std::cout << "NOK" << std::endl;
    
    m = OdbaciOptuzbu(nizPotencijalnih, m, "Bajro");
    if(m != n) std::cout << "NOK" << std::endl;
    
    m = OdbaciOptuzbu(nizPotencijalnih, m, "Luca");
    if(m != n) std::cout << "NOK" << std::endl;
    
    m = OdbaciOptuzbu(nizPotencijalnih, m, "Jovo");
    if(m != n) std::cout << "NOK" << std::endl;
    
    m = OdbaciOptuzbu(nizPotencijalnih, m, "Amina");
    if(m != n) std::cout << "NOK" << std::endl;
    
    m = OdbaciOptuzbu(nizPotencijalnih, m, "Elma");
    if(m != n) std::cout << "NOK" << std::endl;
    
    m = OdbaciOptuzbu(nizPotencijalnih, m, "Selma");
    if(m != n) std::cout << "NOK" << std::endl;
    
    m = OdbaciOptuzbu(nizPotencijalnih, m, "Admira");
    if(m == n) std::cout << "NOK" << std::endl;
 
    std::cout << "Kraj" << std::endl;
  
    std::cout << "New pozvan " << brojac_new << " puta,  delete [] pozvan " << brojac_deleteniz << " puta, a alocirano ukupno " << alocirano << " bajta i to redom: ";
    for (int i=0; i<brojac_new;i++) std::cout << alokacije[i] << " ";
    dealociraj(nizPotencijalnih, n);

}


int _main() {
  std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
  int n;
  std::cin >> n;
  std::cout << "Unesite potencijalne krivce: "<<std::endl;
  std::vector<std::string> imena;
  for(int i = 0; i < n; i++) 
  {
    std::string s;
    std::cin >> s;
    imena.push_back(s);
  }
  char **pot;
  int m = PotencijalniKrivci(pot, imena);
  std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog";
  std::cout << " 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
  int opcija;
  std::cin >> opcija;
  while (opcija != 0)
  {
    switch(opcija)
    {
      case 1:
      {
        std::cout << "Unesite ime novog optuzenog: " << std::endl;
        std::string novi;
        std::cin >> novi;
        m = DodajOptuzbu(pot, m, novi);
        break;
      }
      case 2:
      {
        std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
        std::string izbaci;
        std::cin >> izbaci;
        m = OdbaciOptuzbu(pot, m, izbaci);
        break;
      }
      case 3:
      {
        IzlistajOptuzbu(pot, m);
        break;
      }
      default:
        std::cout << "Ne postoji ta opcija!" << std::endl;
    }
  std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
  std::cin >> opcija;
  
  }
}
  

      
  
 
