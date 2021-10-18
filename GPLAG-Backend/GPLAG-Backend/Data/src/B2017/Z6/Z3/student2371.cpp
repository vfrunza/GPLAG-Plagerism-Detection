/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;



//template<typename t>
//bool testiraj(vector<vector<string>> v, Matrica<t> mat);

template <typename IspisiviTip>
 std::string PretvoriUString(const IspisiviTip &nesto) {
 std::ostringstream tok;
 tok << nesto;
 return tok.str();
 }
template <typename NekiTip>
 NekiTip PretvoriIzStringa(string s) {
 std::istringstream tok(s);
 NekiTip nesto;
 tok >> nesto;
 if(!tok || tok.peek() != EOF)
 throw std::domain_error("Pretvorba nije moguća");
 return nesto;
 }


vector<string> izvoji(string s)
{
   vector<string> rez;
   for(int i=0; i<s.size(); i++){
     string pom; while(i!=s.size() && s[i]!=',') {pom.push_back(s[i]); i++;}
     rez.push_back(pom);
   }
   return rez;
}

 template<typename t>
bool testiraj(vector<vector<string>> v, t** mat)
{
 
 for(int i=1; i<v.size(); i++) {
   if(v[i].size()!=v[0].size()) return false;
 }
 for(int i=0; i<v.size(); i++)
 {
  for(int j=0; j<v.size(); j++)
  {
   std::istringstream tok(v[i][j]);
   t nesto;
   tok >> nesto;
   if(!tok || tok.peek() != EOF) return false;
  }
 }
 return true;
}


template <typename TipEl>
 class Matrica {
     int br_redova, br_kolona;
     TipEl **elementi;
     char ime_matrice;
     static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
     static void DealocirajMemoriju(TipEl **elementi, int br_redova);
     void KopirajElemente(TipEl **elementi);
 public:
     Matrica(int br_redova, int br_kolona, char ime = 0);
     Matrica(const Matrica &m);
     Matrica(Matrica &&m);
     
     
     Matrica(string s, bool a)
     {
        if(!a)
        {
          ifstream tok(s);
        if(!tok) throw logic_error("Trazena datoteka ne postoji");
       
        vector<vector<string>> v1;
        string pom;
        while(getline(tok,pom))
        {
         if(!tok) throw logic_error("Problemi pri citanju iz datoteke");
           vector<string> lajn = izvoji(pom);
           v1.push_back(lajn);
        }
        if(!testiraj(v1,elementi)) throw logic_error("Datoteka sadrzi besmislene podatke");
        br_redova=v1.size(); br_kolona=v1[0].size();
        //AlocirajMemoriju(v1.size(), v1[0].size());
        //cout<<v1.size()<<" "<<v1[0].size()<<endl;
       //cout<<br_redova<<" "<<br_kolona<<endl; 
       
       br_redova=v1.size(); br_kolona=v1[0].size();
       elementi=new TipEl*[v1.size()];
       for(int i=0; i<v1.size(); i++) elementi[i]= new TipEl[v1[0].size()];
       
        for(int i=0; i<v1.size(); i++)
         for(int j=0; j<v1[0].size(); j++) {
           istringstream tok(v1[i][j]);
           //typename remove_reference<decltype(elementi[0][0])>::type nesto;
           TipEl nesto;
           tok >> nesto;
         //  cout<<nesto;
           if(!tok || tok.peek() != EOF)
            throw std::domain_error("Pretvorba nije moguća");
           elementi[i][j]=nesto;
         }
        }
        else{
          ifstream tok(s, std::ios::binary);
        if(!tok) throw logic_error("Trazena datoteka ne postoji");
        
       
        vector<vector<string>> v1;
        unsigned int size=0;
        while(tok.read(reinterpret_cast<char*>(&size), sizeof (size)))
        {
         string buffer; buffer.resize(size);
         tok.read(&buffer[0], buffer.size());
           vector<string> lajn = izvoji(buffer);
           
           v1.push_back(lajn);
        }
        br_redova=v1.size(); br_kolona=v1[0].size();
        AlocirajMemoriju(v1.size(), v1[0].size());
        
        for(int i=0; i<v1.size(); i++)
         for(int j=0; j<v1[0].size(); j++) {
           istringstream tok(v1[i][j]);
           typename remove_reference<decltype(elementi[0][0])>::type nesto;
           tok >> nesto;
           if(!tok || tok.peek() != EOF)
            throw std::domain_error("Pretvorba nije moguća");
           elementi[i][j]=nesto;
         }
        }
     }
     
     template<typename tip>
     friend ostream &operator << (ostream &tok, const Matrica<tip> &m);
     
     ~Matrica() { DealocirajMemoriju(elementi, br_redova); }
     Matrica &operator =(const Matrica &m);
     Matrica &operator =(Matrica &&m);
     void Unesi();
     void Ispisi(int sirina_ispisa) const;
     template <typename Tip2>
     friend Matrica<Tip2> ZbirMatrica(const Matrica<Tip2> &m1,
     const Matrica<Tip2> &m2);
     
     void SacuvajUTekstualnuDatoteku(string s)
     {
         ofstream tok(s);
         if(!tok) throw logic_error("Problem s upisom u datoteku");
         for(int i=0; i<br_redova; i++)
         {
             for(int j=0; j<br_kolona; j++)
             {
                 tok<<elementi[i][j];
                 if(!tok) throw logic_error("Problem s upisom u datoteku");
                 if(j!=br_kolona-1) tok<<",";
             }
             tok<<"\n";
         }
     }
     void ObnoviIzTekstualneDatoteke(string s)
     {
      
        ifstream tok(s);
        if(!tok) throw logic_error("Trazena datoteka ne postoji");
        
        
       
        vector<vector<string>> v1;
        string pom;
        while(getline(tok,pom))
        {
         if(!tok) throw logic_error("Problemi pri citanju iz datoteke");
           vector<string> lajn = izvoji(pom);
           v1.push_back(lajn);
        }
        if(!testiraj(v1, elementi)) throw logic_error("Datoteka sadrzi besmislene podatke");
        //cout<<"DDDDDDDDDDDDDDD";
        br_redova=v1.size(); br_kolona=v1[0].size();
        for(int i=0; i<br_redova; i++) delete [] elementi[i];
        delete [] elementi;
        AlocirajMemoriju(v1.size(), v1[0].size());
        br_redova=v1.size(); br_kolona=v1[0].size();
        for(int i=0; i<v1.size(); i++)
         for(int j=0; j<v1[0].size(); j++) {
           istringstream tok(v1[i][j]);
           typename remove_reference<decltype(elementi[0][0])>::type nesto;
           tok >> nesto;
           if(!tok || tok.peek() != EOF)
            throw std::domain_error("Pretvorba nije moguća");
           elementi[i][j]=nesto;
         }
     }
     void SacuvajUBinarnuDatoteku(string s)
     {
        std::ofstream tok(s, std::ios::binary);

         if(!tok) throw logic_error("Problem s upisom u datoteku");
         for(int i=0; i<br_redova; i++)
         {
             for(int j=0; j<br_kolona; j++)
             {
                 tok.write(reinterpret_cast<char*>(&elementi[i][j]), sizeof elementi[i][j]);
                 if(j!=br_kolona-1) tok<<",";
             }
             tok<<"\n";
         }
     }
     void ObnoviIzBinarneDatoteke(string s)
     {
        
        ifstream tok(s, std::ios::binary);
        if(!tok) throw logic_error("Trazena datoteka ne postoji");
        
        for(int i=0; i<br_redova; i++) delete [] elementi[i];
        delete [] elementi;
       
        vector<vector<string>> v1;
        unsigned int size=0;
        while(tok.read(reinterpret_cast<char*>(&size), sizeof (size)))
        {
         //cout<<"ASDADSADSDA";
         string buffer; buffer.resize(size);
         tok.read(&buffer[0], buffer.size());
           vector<string> lajn = izvoji(buffer);
           cout<<endl<<lajn[0]<<endl;
           //v1.push_back(lajn);
        }
        br_redova=v1.size(); br_kolona=v1[0].size();
        AlocirajMemoriju(v1.size(), v1[0].size());
        
        for(int i=0; i<v1.size(); i++)
         for(int j=0; j<v1[0].size(); j++) {
           istringstream tok(v1[i][j]);
           typename remove_reference<decltype(elementi[0][0])>::type nesto;
           tok >> nesto;
           if(!tok || tok.peek() != EOF)
            throw std::domain_error("Pretvorba nije moguća");
           elementi[i][j]=nesto;
         }
     }
     
     TipEl const* operator[]( int const y ) const
     {
        return elementi[y];
     }

    TipEl* operator[]( int const y )
     {
        return elementi[y];
     }
 };
 
 
 /* template <typename t>
  ostream &Matrica<t>::operator<<(ostream &tok, const Matrica &m)
  {
       for(int i = 0; i < m.br_redova; i++) {
        for(int j = 0; j < m.br_kolona; j++)
            tok << std::setw(5) << m.elementi[i][j];
        tok << std::endl;
     }
     return tok;
   }
 */
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
     for(int i = 0; i < br_redova; i++) delete[] elementi[i];
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
            std::cout << std::setw(sirina_ispisa) << elementi[i][j];
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
 
 template<typename tip>
 ostream &operator << (ostream &tok, const Matrica<tip> &m)
     {
       for(int i = 0; i < m.br_redova; i++) {
        for(int j = 0; j < m.br_kolona; j++)
            tok<< std::setw(6) << m.elementi[i][j];
        tok << std::endl;
     }
     return tok;
   }


int main ()
{
    try
    {
        Matrica<int> m0{2, 2};
        for (int i{0}; i < 2; i++)
            for (int j{0}; j < 2; j++)
                m0[i][j] = i + j;
        cout<<m0;
        m0.SacuvajUBinarnuDatoteku("matrica1.dat");
        Matrica<int> m1("matrica1.DAT", true);
        std::cout << std::setw(6) << m1;
    }
    catch (const std::logic_error& e)
    {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
	return 0;
}
