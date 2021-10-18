#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>
#include <vector>
#include <algorithm>

class Student{
     int index;
     std::string ime, adresa, telefon, godina_studija;
     public:
     bool ProvjeraIndexa(int indeks){
          if(indeks<10000) return false;
          return true;
     }
     bool ProvjeraStudGodine(std::string god_stud){
          if(god_stud.length()>3 || god_stud.length()==2 || god_stud.length()==0) return false;
    if(god_stud.length()==1 && god_stud[0]!='1' && god_stud[0]!='2' && god_stud[0]!='3') return false;
    if(godina_studija.length()==3) {
    for(int i(0);i<3;i++) {
        if(god_stud[0]!='1' && god_stud[0]!='2' && god_stud[0]!='3') return false;
        if(god_stud[1]!='/') return false;
        if(god_stud[2]!='B' && god_stud[2]!='M' && god_stud[2]!='D') return false;
        if(god_stud[0]=='3' && god_stud[2]=='M') return false;
    }
    }
    return true;
     }
     bool ProvjeraBrojaTelefona(std::string br_tel){
          if(br_tel.length()<5) return false;
          for(int i=0;i<br_tel.length();i++) {
        if(br_tel[0]<'0' || br_tel[0]>'9')
            return false;
        if(br_tel[i]!='/' && br_tel[i]!='-' && (br_tel[i]<'0' || br_tel[i]>'9'))
            return false;
        if(br_tel[br_tel.length()-1]=='-' || br_tel[br_tel.length()-1]=='/')
            return false;
    }
    int br1=0,br2=0;
    for(int i=0;i<br_tel.length();i++) {
        if(br_tel[i]=='/') {
            br1++;
            if(br1>1) return false;
        }
        if(br_tel[i]=='-') {
            br2++;
            if(br2>1) return false;
        }
    }
    if(br1==0 || br2==0) return false;

    for(int i=0;i<br_tel.length();i++) {
        if(br_tel[i]=='/' && (br_tel[i-1]=='-' || br_tel[i+1]=='-'))
            return false;
    }
    return true;
     }


     std::string SrediIme(std::string s){
          int duzina=s.size();
    for(int i=0;i<duzina-1;i++) {
        if(s[i]==' ' && s[i+1]==' ' && i!=0) {
            for(int j=i;j<duzina-1;j++) {
                s[j]=s[j+1];
            }
            duzina--;
            i--;
        }
        if(s[0]==' ') {
            for(int j=i;j<duzina-1;j++)
                s[j]=s[j+1];
            duzina--;
            i--;
        }
    }

    if(s[duzina-1]==' ' || s[0]==' ') duzina--;

    std::string pomocni;
    for(int i=0;i<duzina;i++){

        pomocni.push_back(s[i]);
    }
    s.resize(0);
    for(int i=0;i<duzina;i++) {
        s.push_back(pomocni[i]);
    }
    return s;
     }
     
     
     Student(int indeks, std::string god_stud, std::string ime_prezime, std::string a_stanovanja, std::string br_tel){
          if(!ProvjeraIndexa(indeks)) throw std::domain_error("Neispravni parametri");
          if(!ProvjeraStudGodine(god_stud)) throw std::domain_error("Neispravni parametri");
          if(!ProvjeraBrojaTelefona(br_tel)) throw std::domain_error("Neispravni parametri");

          index=indeks;
          godina_studija=god_stud;
          ime=SrediIme(ime_prezime);
          adresa=SrediIme(a_stanovanja);
          telefon=br_tel;
     }

     int DajIndeks() const{
          return index;
     }
     std::string DajGodinuStudija() {
          if(godina_studija.length()==1 && (godina_studija[0]=='1' || godina_studija[0]=='2' || godina_studija[0]=='3'))
        godina_studija=godina_studija+std::string("/B");
    return godina_studija;
     }
     std::string DajImePrezime() const{
          return ime;
     }
     std::string DajAdresu() const{
          return adresa;
     }
     std::string DajTelefon(){
          return telefon;
     }
     void Ispisi(){
          std::cout<<"Broj indeksa: "<<index<<std::endl;
          std::cout<<"Godina studija: "<<(*this).DajGodinuStudija()<<std::endl;
          std::cout<<"Ime i prezime: "<<ime<<std::endl;
          std::cout<<"Adresa: "<<adresa<<std::endl;
          std::cout<<"Telefon: "<<telefon<<std::endl;
     }
    
};


class Laptop{
    int evidencijski_broj;
    std::string naziv, karakteristike ;
    std::shared_ptr<Student> kod_koga_je=nullptr;
public:
std::string SrediIme(std::string s){
          int duzina=s.size();
    for(int i=0;i<duzina-1;i++) {
        if(s[i]==' ' && s[i+1]==' ' && i!=0) {
            for(int j=i;j<duzina-1;j++) {
                s[j]=s[j+1];
            }
            duzina--;
            i--;
        }
        if(s[0]==' ') {
            for(int j=i;j<duzina-1;j++)
                s[j]=s[j+1];
            duzina--;
            i--;
        }
    }

    if(s[duzina-1]==' ' || s[0]==' ') duzina--;

    std::string pomocni;
    for(int i=0;i<duzina;i++){

        pomocni.push_back(s[i]);
    }
    s.resize(0);
    for(int i=0;i<duzina;i++) {
        s.push_back(pomocni[i]);
    }
    return s;
     }

    Laptop(int ev_broj, std::string naziv_laptopa, std::string karakteristike_l){
    if (ev_broj < 0) throw std::domain_error("Neispravni parametri");
    evidencijski_broj = ev_broj;
    naziv = SrediIme(naziv_laptopa);
    karakteristike = SrediIme(karakteristike_l);
    }
    
    
    int DajEvidencijskiBroj(){ return evidencijski_broj; }
    std::string DajNaziv(){ return naziv; }
    std::string DajKarakteristike(){ return karakteristike; }
    
    void Zaduzi(Student &s){
    if(kod_koga_je != nullptr) throw std::domain_error("Laptop vec zaduzen");
    kod_koga_je = std::make_shared<Student>(s);
    }
    
    void Razduzi(){ kod_koga_je = nullptr; }
    
    bool DaLiJeZaduzen(){ 
         if(kod_koga_je != nullptr) return true;
    else return false; }
    
    
    Student &DajKodKogaJe(){
         if(kod_koga_je==nullptr) throw std::domain_error("Laptop nije zaduzen");
         return *kod_koga_je;
    }
    
  std::shared_ptr<Student> DajPokKodKogaJe(){
         return kod_koga_je;
   }
    
    void Ispisi(){
         std::cout << "Evidencijski broj: " << evidencijski_broj << std::endl;
    std::cout << "Naziv: " << naziv << std::endl;
    std::cout << "Karakteristike: " << karakteristike << std::endl;
    }
};


class Administracija{
    std::vector<std::shared_ptr<Student>> studenti;
    std::vector<std::shared_ptr<Laptop>> laptopi;
public:
    Administracija(){}
    Administracija &operator=(Administracija &a) = delete;
    Administracija(const Administracija &a) = delete;
    Administracija(Administracija &&a){
    studenti = std::move(a.studenti);
    }
  
    Administracija &operator=(Administracija &&a){
    studenti = std::move(a.studenti);
    return *this;
    }
    void RegistrirajNovogStudenta(int indeks, std::string god_stud, std::string ime_prezime, std::string a_stanovanja, std::string br_tel){
     for(int i = 0; i < studenti.size(); i++){
        if(studenti[i]->DajIndeks() == indeks) throw std::domain_error("Student s tim indeksom vec postoji");
    }
    studenti.resize(studenti.size() + 1);
    studenti[studenti.size() - 1] = std::make_shared<Student>(Student(indeks, god_stud, ime_prezime, a_stanovanja, br_tel));

    }
    void RegistrirajNoviLaptop(int ev_broj, std::string naziv_laptopa, std::string karakteristike_l){
    for(int i = 0; i < laptopi.size(); i++){
        if(laptopi[i]->DajEvidencijskiBroj() == ev_broj) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
    }
    laptopi.resize(laptopi.size() + 1);
    laptopi[laptopi.size() - 1] = std::make_shared<Laptop>(Laptop(ev_broj, naziv_laptopa, karakteristike_l));

    }
    Student &NadjiStudenta(int indeks){
    for(int i = 0; i < studenti.size(); i++){
        if(studenti[i]->DajIndeks() == indeks) return *(studenti[i]);
    }
    throw std::domain_error("Student nije nadjen");
    }
    Student NadjiStudenta(int indeks) const{
    std::shared_ptr<Student> s;
    for(int i = 0; i < studenti.size(); i++){
        if(studenti[i]->DajIndeks() == indeks){
            s = std::make_shared<Student>(*(studenti[i]));
            return *s;
        }
    }
    throw std::domain_error("Student nije nadjen");
    }
    Laptop &NadjiLaptop(int ev_broj){
        for(int i = 0; i < laptopi.size(); i++){
        if(laptopi[i]->DajEvidencijskiBroj() == ev_broj) return *(laptopi[i]);
    }
    throw std::domain_error("Laptop nije nadjen");
    }
    Laptop NadjiLaptop(int ev_broj) const{
    std::shared_ptr<Laptop> l;
    for(int i = 0; i < laptopi.size(); i++){
        if(studenti[i]->DajIndeks() == ev_broj){
            l = std::make_shared<Laptop>(*(laptopi[i]));
            return *l;
        }
    }
    throw std::domain_error("Laptop nije nadjen");
    }
    void IzlistajStudente() const{
     for(int i = 0; i < studenti.size(); i++){
        studenti[i]->Ispisi();
        std::cout << std::endl;
    }
    }
    
    void IzlistajLaptope() const{
    for(int i = 0; i < laptopi.size(); i++){
        laptopi[i]->Ispisi();
        if(laptopi[i]->DaLiJeZaduzen()) std::cout << "Zaduzio(la): " << laptopi[i]->DajKodKogaJe().DajImePrezime() <<" (" << laptopi[i]->DajKodKogaJe().DajIndeks() << ")" << std::endl;
    std::cout << std::endl;
    }
    }
    void ZaduziLaptop(int indeks, int ev_broj){
    for(int i = 0; i < studenti.size(); i++){
        if(studenti[i]->DajIndeks() == indeks) break;
        if(i == studenti.size() - 1) throw std::domain_error("Student nije nadjen");
    }
    for(int j = 0; j < laptopi.size(); j++){
        if(laptopi[j]->DajEvidencijskiBroj() == ev_broj) break;
        if(j == laptopi.size() - 1) throw std::domain_error("Laptop nije nadjen");
    }

    if(NadjiLaptop(ev_broj).DaLiJeZaduzen()) throw std::domain_error("Laptop vec zaduzen");

    for(int k = 0; k < laptopi.size(); k++){
        if(laptopi[k]->DajKodKogaJe().DajIndeks() == indeks) std::domain_error("Student je vec zaduzio laptop");
    }

    NadjiLaptop(ev_broj).Zaduzi(NadjiStudenta(indeks));
    }
    
    
    int NadjiSlobodniLaptop(){
    for(int i = 0; i < laptopi.size(); i++){
        if(laptopi[i]->DaLiJeZaduzen() == false) return laptopi[i]->DajEvidencijskiBroj();
        if(i == laptopi.size() - 1) throw std::domain_error("Nema slobodnih laptopa");
    }
    }
    void RazduziLaptop(int ev_broj){
    if(NadjiLaptop(ev_broj).DaLiJeZaduzen() == false) throw std::domain_error("Laptop nije zaduzen");
    NadjiLaptop(ev_broj).Razduzi();
    }
    void PrikaziZaduzenja() const{
        bool tacno(false);
    for(int i = 0; i < laptopi.size(); i++){
        if(laptopi[i]->DaLiJeZaduzen()){
            std::cout << "Student " << laptopi[i]->DajKodKogaJe().DajImePrezime() << " (" << laptopi[i]->DajKodKogaJe().DajIndeks()
            << ") zaduzio/la laptop broj " << laptopi[i]->DajEvidencijskiBroj() << std::endl;
            tacno = true;
        }
    }
    if(!tacno) throw std::domain_error("Nema zaduzenja");
    }
};



int main() { try{
 Student studentica(17353,"1/B","     Segmedina     Kavaz    ","Sejmenska       10","061/463-514");
 std::shared_ptr<Student> student;
 
 std::cout<<student;
    studentica.Ispisi();
    Laptop l(102,"acer","z8      kejdn");
    l.Ispisi();
    Administracija etf;

    etf.RegistrirajNoviLaptop(123, "Dell", "CPU 3.0 GHz, 4 GB RAM");
    etf.RegistrirajNoviLaptop(331, "ASUS", "CPU 3.5 GHz, 2 GB RAM");
    etf.RegistrirajNoviLaptop(122, "Dell 2", "CPU 3.2 GHz, 6 GB RAM");


    etf.RegistrirajNovogStudenta(14212, "1","Benjamin", "Francuska revolucija 23", "12/34-56");
    etf.RegistrirajNovogStudenta(17528, "2","Ivan", "Trg vjecnih studenata 12", "048/597-585");
    etf.RegistrirajNovogStudenta(17525, "3", "Ante" ,"Trg vjecnih studenata 11", "062/582-757");

    etf.ZaduziLaptop(14212, 122);
    etf.ZaduziLaptop(17525,331);
    etf.IzlistajLaptope();}
    catch (std::domain_error e){
        std::cout<<e.what();
    }
    return 0;
}
