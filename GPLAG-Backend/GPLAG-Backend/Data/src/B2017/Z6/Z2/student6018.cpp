/B2017/2018: Primjer ispita 6, zadaci 1 2
/*#include <iostream>
#include <string>
#include <vector>

class A {
 double x;
 int y, z;
public:
 A(int z, int x) : x(x), y(z), z(0) { std::cout << "A0 "; }
 A(int z = 2, double x = 1) : x(0), y(x), z(z) { std::cout << "A1 "; }
 explicit A(double A) : x(1), y(A), z(x) { std::cout << "A2 "; }
 A(A &a) : x(a.y), y(2), z(a.x) { a.x = 3; x *= 2; std::cout << "A3 "; }
 A(const A &a) : x(a.y), y(2), z(a.x) { x *= -2; std::cout << "A4 "; }
 int operator =(int x) {
 std::cout << "A5 ";
 return A(this->x + x + this->y).DajX();
 }
 int operator =(const A &y) {
 std::cout << "A6 ";
 return A(this->x + y.y + this->y, 1).DajY();
 }
 double DajX () const { return x; }
 int DajY () const { return -y; }
 int DajY () { return y; }
 int DajZ () const { return z; }
 void f() { std::cout << "Muu "; }
 virtual void g() { std::cout << "Bee "; }
 friend std::ostream &operator <<(std::ostream &tok, const A &a) {
 return tok << "x = " << a.DajY() << ", y = " << a.DajZ()
 << ", z = " << a.DajX() << " ";
 }
};
struct B : public A {
 B() { std::cout << "B0 ";}
 void f() { std::cout << "Njaa "; }
 void g() { std::cout << "Mjau "; }
};
void VoliMe(A a) { a.f(); a.g(); }
void NeVoliMe(A &a) { a.f(); a.g(); }
int main() {
 A a(4), b(3.5), c(1, 2), d, e(3, 2.);
 std::cout << std::endl;
 std::cout << B() << std::endl;
 const A f(7, 11);
 A g(f), h(c);
 B p;
 VoliMe(g); NeVoliMe(g); VoliMe(p); NeVoliMe(p);
 std::cout << std::endl << c << "| " << h << "| " << g << std::endl;
 auto op1 = (c = 3), op2 = (b = e);
 std::cout << op1 * 5; std::cout << " " << op2;
 return 0;
}*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <fstream>
#include <ios>




class Stan {
    std::string naselje;
    int broj_soba;
    double kvadratura;
public:
    virtual ~Stan(){}
    Stan (std::string naselje, int broj_soba, double kvadratura) : naselje(naselje), broj_soba(broj_soba), kvadratura(kvadratura) {}
    virtual int DajCijenu() const { return kvadratura*1000; }
    std::string DajNaselje() const { return naselje; }
    int DajBrojSoba () const { return broj_soba; }
    double DajKvadraturu () const { return kvadratura; }
    Stan* DajKopiju() const {
        return new Stan (naselje, broj_soba, kvadratura);
    }
    void PromijeniBrojSoba(int broj){
        broj_soba=broj;       //ovdje nesto ne stima
    }
    virtual std::string Ispisi () const {
        std::string s;
     s=naselje+'\n'+std::to_string(broj_soba)+'\n'+std::to_string(kvadratura)+'\n'+std::to_string(DaLiJeNamjesten())+'\n';
     return s;
    }
    virtual int DaLiJeNamjesten () const { return 0; }
};
class NamjesteniStan : public Stan {
    std::vector<std::pair<std::string, int>> stvari; // <naziv,cijena>
public:
    ~NamjesteniStan () {}
    NamjesteniStan (std::string ime, int broj_soba, double kvadratura, std::vector<std::pair<std::string, int>> stvari) :
        Stan(ime, broj_soba,kvadratura), stvari(stvari){}
     int DajCijenu() const override{
         int suma(0);
         for (auto x : stvari){
             suma+=x.second;
         }
         return DajKvadraturu()*2000+suma;
     }
    Stan* DajKopiju() const {
        return new NamjesteniStan(*this);
    }
    int DaLiJeNamjesten() const override { return 1; }
     std::string Ispisi () const override {
        std::string s;
     s=DajNaselje()+'\n'+std::to_string(DajBrojSoba())+'\n'+std::to_string(DajKvadraturu())+'\n'+std::to_string(DaLiJeNamjesten())+'\n'+std::to_string(stvari.size())+'\n';
        for (auto x : stvari){
            s+= x.first + '\n' +std::to_string(x.second) + '\n';
        }
        return s;
    }
    
};
class StambenaAgencija {
    Stan **stanovi;
    int broj, kapacitet;
public:
    int DajBroj() const { return broj; }
    ~StambenaAgencija (){
        for (int i=0; i<broj; i++) 
            delete stanovi [i];
        delete [] stanovi;
    }
    StambenaAgencija(int kapacitet=50) : broj(0), kapacitet(kapacitet) {}            //ALOCIRANJE
    void DodajStan(std::string ime, int broj_soba, int kvadratura){
        stanovi[broj]=new Stan(ime, broj_soba, kvadratura);
        broj++;
    }
    void DodajStan(const Stan &s){
        
        stanovi[broj]=s.DajKopiju();
        broj++;
    }
    StambenaAgencija (const StambenaAgencija &s){
        broj=s.broj;
        kapacitet=s.kapacitet;
        stanovi= new Stan* [s.kapacitet]{};
        for (int i=0; i<broj; i++){
            stanovi[i]=new Stan(*(s.stanovi[i]));   //OVO SVE STAVIS U TRY CATCH    
        }
    }
    StambenaAgencija (StambenaAgencija &&s){            //A KRADE B
        stanovi=s.stanovi;
        s.stanovi=nullptr;
        broj=s.broj;
        kapacitet=s.kapacitet;
        }
        
    StambenaAgencija& operator = (const StambenaAgencija &s){
        if(&s!=this){
        
        for (int i=0; i<broj; i++) 
            delete stanovi [i];
            delete [] stanovi;
        
        broj=s.broj;
        kapacitet=s.kapacitet;
        stanovi= new Stan* [kapacitet];
        for (int i=0; i<broj; i++){
            stanovi[i]=new Stan(*(s.stanovi[i]));   //OVO SVE STAVIS U TRY CATCH
    }
        }
        return *this;
    }
    StambenaAgencija& operator = (StambenaAgencija &&s){
        std::swap(broj, s.broj);
        std::swap(kapacitet,s.kapacitet);
        std::swap(stanovi, s.stanovi);
        return *this;
    }
    Stan& DajNajveciStan() const{
        return **(std::max_element(stanovi,stanovi+broj, [] (Stan* s1, Stan* s2){
                                                            return (s1->DajKvadraturu()>s2->DajKvadraturu());
                                                            }));
    }
    void DodajNamjestenStan(const NamjesteniStan &stan){            //PROVJERA DA LI IMA MJESTA
        stanovi[broj]=new NamjesteniStan(stan);
        broj++;
        
    }
    void DodajNamjestenStan(std::string ime, int broj_soba, int kvadratura, std::vector<std::pair<std::string,int>> v){            //PROVJERA DA LI IMA MJESTA
        stanovi[broj]=new NamjesteniStan(ime, broj_soba, kvadratura, v);
        broj++;
        
    }
    friend StambenaAgencija operator + (const StambenaAgencija &s1, const StambenaAgencija &s2 ){
        StambenaAgencija s3;
        s3.broj=s1.broj+s2.broj;
        if (s3.broj>50) throw ("prekoracen kapacitet");
        
        /*for(int i=0; i<s1.broj; i++){
            s3.stanovi[i]=new Stan(s1.stanovi[i]);
        }
        for(int i=s1.broj; i<s1.broj+s2.broj; i++){
            s3.stanovi[i]=new Stan(s2.stanovi[i-s1.broj]);         //sve u TRY CATCH da nema problema
        }*/
        for(int i=0; i<s1.broj; i++){
            s3.stanovi[i]=(s1.stanovi[i]->DajKopiju());
        }
        for(int i=s1.broj; i<s1.broj+s2.broj; i++){
            s3.stanovi[i]=(s2.stanovi[i-s1.broj]->DajKopiju());
        }
        return s3;
    }
    StambenaAgencija& operator += (const StambenaAgencija &s2){
        int n(broj);
        broj=broj+s2.broj;
        if (broj>50) throw ("prekoracen kapacitet");
        for(int i=0; i<s2.broj; i++){
            stanovi[i+n]=(s2.stanovi[i]->DajKopiju());         //sve u TRY CATCH da nema problema
        }
        return *this;
    }
    
    
    void Prodaj (int brojstana){
        delete stanovi[brojstana-1];
        for (int i=brojstana-1; i<broj-1; i++){
            stanovi[i]=stanovi[i+1];
        }
        broj--;
    }                       
    double operator () (std::string naziv){ //vraca ukupnu kvadraturu, prije se moze provjeriti da li tog stana
                                            //uopste ima, ako nema da izbaci izuzetak!
        double ukupna(0);
        for (int i=0; i<broj; i++){
            if (stanovi[i]->DajNaselje()== naziv) ukupna += stanovi[i]->DajKvadraturu();
        }
        return ukupna;
    }
    friend std::ostream& operator << (std::ostream &tok, const StambenaAgencija &s){
        tok << s.kapacitet << s.broj << std::endl;
        for (int i=0;i<s.broj;i++) {
            tok << s.stanovi[i]->Ispisi();
        }
        return tok;
    }
    
     StambenaAgencija (std::string ime_datoteke){
        std::ifstream tok(ime_datoteke);
        char znak;
        tok>>kapacitet>>broj>>znak;
        stanovi=new Stan*[kapacitet]{};
        std::string naselje;
        int broj_soba,provjera;
        double kvadratura;
        char jedem;
        for (int i=0; i<broj; i++){
        std::getline(tok,naselje);
        tok >> broj_soba>>jedem>>kvadratura>>jedem>>provjera>>jedem;
        if (provjera) {
            std::vector<std::pair<std::string,int>> vektor;
            int velicina;
            tok >> velicina >> jedem;
            for (int i=0; i<velicina ; i++){
                std::string ime;
                int iznos;
                std::getline(tok,ime);
                tok >> iznos >> jedem;
                vektor.push_back(std::make_pair(ime,iznos));
            }
            stanovi[i]=new NamjesteniStan(naselje, broj_soba, kvadratura, vektor);
        }
        else {
            stanovi[i]=new Stan(naselje, broj_soba, kvadratura);
        }
        }
    }
    
    
    
    
};
int main () {
    StambenaAgencija s1(10); // (1)
//StambenaAgencija s1 = 10; // ovo se ne smije kompajlirati
    s1.DodajStan("Novo Sarajevo", 3, 60); // (2)
    Stan stan("Ilidza", 4, 75.5); // (3)
    s1.DodajStan(stan); // (4) - dodaje kopiju stana
    StambenaAgencija s2(s1); // (5)
    Stan &ref = s2.DajNajveciStan(); // (6)
    std::vector<std::pair<std::string, int>> stvari {{"Televizor", 700},
        {"Frizider", 450}, {"Ormar", 300}}; // {naziv, cijena}
    NamjesteniStan nstan("Vratnik", 2, 50, stvari); // (7)
    s2.DodajNamjestenStan(nstan); // (8)
    Stan &sref(nstan);
    s2.DodajNamjestenStan("Bjelave", 3, 70, {{"Jacuzzi", 4450},
        {"Ves masina", 500}
    }); // (9)
    std::cout << "Cijena stana: " << ~stan; // (10)
// cijena se računa kao kvadratura * 1000
std::cout << "Cijena namjestenog stana: " << ~sref; // (11)     //DODAJ OVAJ OPERATOR(int operator ~())
// cijena se računa kao kvadratura * 2000 + vrijednost stvari
    StambenaAgencija s3; // (12) - s3 ima kapacitet od 50 stanova
    s3 = s1 + s2; // (13) - s3 će sadržavati sve stanove iz s1 i iz s2
    s1 += s2; // (14) - u s1 dodaje sve stanove iz s2
    const StambenaAgencija &cs3(s3); // referenca na const
    const Stan *moj_stan = cs3[1]; // (15) moj_stan je pokazivač                //DODAJ OVAJ OPERATOR
    s1[0].PromijeniBrojSoba(3); // (16) označava renoviranje stana
    s3.Prodaj(2); // (17) briše 2. stan iz kolekcije
    std::cout << "Ukupna kvadratura za naselje: " << s2("Novo Sarajevo"); // (18)
    std::ofstream dat("stanovi.txt");
    dat << s3; // (19)
    StambenaAgencija s4("stanovi.txt"); // (20) učitava iz datoteke
    std::cout << s4; // daje isti ispis kao i std::cout << s3
    return 0;
}
