/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void kreirajDatotetkuZbii1()
{
    std::string ime = "matrica.txt";
    std::ofstream dat(ime);
    dat << "1, 2\n3, 4";
    dat.close();
}

void kreirajDatotetkuZbii2()
{
    std::string ime = "matrica.txt";
    std::ofstream dat(ime);
    dat << "1.4, 2.54\n3.7, -4.7";
    dat.close();
}

template<typename TipEl>
class Matrica
{
    int br_redova,br_kolona;
    TipEl **elementi;
    char ime_matrice;
    static TipEl **AlocirajMemoriju(int br_redova,int br_kolona);
    static void DealocirajMemoriju(TipEl **elementi,int br_redova);
    void KopirajElemente(TipEl **elementi);
    
    public:
    Matrica(int br_redova, int br_kolona, char ime = 0);
    Matrica(const Matrica &m);
    Matrica(Matrica &&m);
    
    ~Matrica() { DealocirajMemoriju(elementi, br_redova); }
     Matrica &operator =(const Matrica &m);
     Matrica &operator =(Matrica &&m);
     void Unesi();
     void Ispisi(int sirina_ispisa) const;
     template <typename Tip2>
     friend Matrica<Tip2> ZbirMatrica(const Matrica<Tip2> &m1,
     const Matrica<Tip2> &m2);
     
     
      Matrica(string s, bool a);
      void SacuvajUTekstualnuDatoteku(string s)
      {
          ofstream buff(s);
          if(!buff) throw logic_error("Problem s upisom u datoteku");
          for(int i=0;i<br_redova;i++)
          {
              for(int j=0;j<br_kolona-1;j++)
              {
                  buff<<elementi[i][j]<<",";
                
              }
              buff<<elementi[i][br_kolona-1]<<"\n";
          }
      }
      void ObnoviIzTekstualneDatoteke(string s)
      {
         ifstream buff(s);
         if(!buff) throw logic_error("Trazena datoteka ne postoji");
         DealocirajMemoriju(elementi,br_redova);
         
         vector<string> redovi;
         string temp;
         while(getline(buff,temp))
         {
            if(!buff) throw logic_error("Problemi pri citanju iz datoteke");
            redovi.push_back(temp);
         }
         
         int br=0;
         for(int i=0;i<redovi[0].size();i++)
            if(redovi[0][i]==',') br++;
         
        AlocirajMemoriju(redovi.size(),br+1);
        
        
      }
      void SacuvajUBinarnuDatoteku(string s)
      {
          ofstream buff(s,ios::binary);
          if(!buff) throw logic_error("Problem s upisom u datoteku");
          for(int i=0;i<br_redova;i++)
          {
              for(int j=0;j<br_kolona-1;j++)
              {
                  buff.write(reinterpret_cast<char*>(&elementi[i][j]),sizeof elementi[i][j]);
                  buff<<",";
                
              }
             buff.write(reinterpret_cast<char*>(&elementi[i][br_kolona-1]),sizeof elementi[i][br_kolona-1]);
             buff<<"\n";
          }
       
      }
      void ObnoviIzBinarneDatoteke(string s)
      {
          ifstream buff(s,ios::binary);
          if(!buff) throw logic_error("Trazena datoteka ne postoji");
          DealocirajMemoriju(elementi,br_redova);
          
      }
};

template <typename TipEl>
 TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona) {
     TipEl **elementi(new TipEl*[br_redova]{});
     try {
     for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
     }
     catch(...) {
     DealocirajMemoriju(elementi, br_redova); throw;
     }
     return elementi;
 }
 
template <typename TipEl>
 void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova) {
     for(int i = 0; i < br_redova; i++) 
         delete[] elementi[i];
     delete[] elementi;
 }
 
template <typename TipEl>
 Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) : br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),elementi(AlocirajMemoriju(br_redova, br_kolona)) {}

template <typename TipEl>
 void Matrica<TipEl>::KopirajElemente(TipEl **elementi) {
     for(int i = 0; i < br_redova; i++)
     for(int j = 0; j < br_kolona; j++)
     Matrica::elementi[i][j] = elementi[i][j];
 }
 
template <typename TipEl>
 Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova),br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),elementi(AlocirajMemoriju(m.br_redova, m.br_kolona)) {
    KopirajElemente(m.elementi);
 }

template <typename TipEl>
 Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice) {
    m.br_redova = 0; m.elementi = nullptr;
 }

template <typename TipEl>
 Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m) {
     if(br_redova < m.br_redova || br_kolona < m.br_kolona) {
     TipEl **novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
     DealocirajMemoriju(elementi, br_redova);
     elementi = novi_prostor;
     }
     else if(br_redova > m.br_redova)
     for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
     br_redova = m.br_redova; br_kolona = m.br_kolona;
     ime_matrice = m.ime_matrice; KopirajElemente(m.elementi);
     return *this;
 }
 
template <typename TipEl>
 Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m) {
     std::swap(br_redova, m.br_redova); std::swap(br_kolona, m.br_kolona);
     std::swap(ime_matrice, m.ime_matrice); std::swap(elementi, m.elementi);
     return *this;
 }
 
 template <typename TipEl>
 void Matrica<TipEl>::Unesi() {
     for(int i = 0; i < br_redova; i++)
     for(int j = 0; j < br_kolona; j++) {
     std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
     std::cin >> elementi[i][j];
 }
 }
 
template <typename TipEl>
 void Matrica<TipEl>::Ispisi(int sirina_ispisa) const {
     for(int i = 0; i < br_redova; i++) {
        for(int j = 0; j < br_kolona; j++)
            std::cout << setw(sirina_ispisa) << elementi[i][j];
        std::cout << std::endl;
     }
 }
 
template <typename TipEl>
 Matrica<TipEl> ZbirMatrica(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
     if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
     throw std::domain_error("Matrice nemaju jednake dimenzije!");
     Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
     for(int i = 0; i < m1.br_redova; i++)
     for(int j = 0; j < m1.br_kolona; j++)
     m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
     return m3;
 }
 

int main ()
{
     try
    {
        kreirajDatotetkuZbii1();
        Matrica<int> m1(2,2);
        m1.ObnoviIzTekstualneDatoteke("matrica.txt");
//        Matrica<int> m1("matrica.txt", false);
      //  std::cout << std::setw(6) << m1;
    }
    catch (const std::logic_error& e)
    {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
    std::cout << std::endl << std::endl;
    try
    {
        kreirajDatotetkuZbii2();
       // Matrica<double> m1("matrica.txt", false);
      ///  std::cout << std::setw(6) << m1;
    }
    catch (const std::logic_error& e)
    {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
	return 0;
}
