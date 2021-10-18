/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>

using namespace std;


void blanko(string &s){
        for(int i=0;i<s.size();i++)
        {if((s[i]==' ')&&(s[i+1]==' '))
         for(;;)
         {
          if(s[i+1]!=' ')
          break;
          else
         for(int j=i;j<s.size();j++)
          s[j]=s[j+1];s.resize(s.size()-1);} 
         }
        int ind;
        for(int i=0; i<s.size(); i++) if(s[i]!=' ') ind=i;
        s=s.substr(0,ind+1);
        for(int i=0; i<s.size(); i++) if(s[i]!=' ') {ind=i; break;}
        s=s.substr(ind,s.size());
    }

class Student{
protected:
    string brtel;
    int indeks;
    string adresa;
    string godinastudija;
    string imeiprezime;

public:
    Student(int ind,string g, string iip, string adr, string brtel){
        int number=ind;
        int digits = 0;
        int bkroz=0, bcrta=0;
        if (number < 0) throw domain_error("Neispravni parametri");
        while (number) {
            number /= 10;
            digits++;
        }
        for(int i=0; i<brtel.size(); i++)
        {
            if(brtel[i]=='/') bkroz++;
            else if(brtel[i]=='-') bcrta++;
            else if(brtel[i]<'0' || brtel[i]>'9') throw domain_error("Neispravni parametri");
        }
        if(digits!=5) throw domain_error("Neispravni parametri");
        if(g!="1" && g!= "2" && g!= "3"&& g!= "1/B" && g!= "2/B" && g!= "3/B" && g!= "1/M" && g!= "2/M"&& g!= "1/D"&&g!= "2/D" && g!= "3/D") throw domain_error("Neispravni parametri");
        blanko(iip); blanko(adr);
        if(g.size()==1) g+="/B";
        if(bkroz>1 || bcrta>1) throw domain_error("Neispravni parametri");
        
        indeks=ind; godinastudija=g; imeiprezime=iip; adresa=adr; Student::brtel=brtel;

    }
    int DajIndeks() const { return indeks;}
    void Ispisi(){
        cout<<"Broj indeksa: "<<indeks<<endl<<"Godina studija: "<<godinastudija<<endl<<"Ime i prezime: "<<imeiprezime<<endl;
        cout<<"Adresa: "<<adresa<<endl<<"Telefon: "<<brtel;

    }
    string DajAdresu() const { return adresa;}
    string DajGodinuStudija() const { return godinastudija;}
    string DajTelefon() const { return brtel;}
    string DajImePrezime() const { return imeiprezime;}
};

class Laptop{
    int ev_broj;
    string naziv, karakteristike;
    shared_ptr<Student>kod_koga_je;
public:
    Laptop(int ev, string naz, string kar){
        if(ev<0) throw domain_error("Neispravni parametri");
        ev_broj=ev; naziv=naz; karakteristike=kar;
        kod_koga_je=nullptr;
    }
    void Zaduzi(Student &s){
        if(kod_koga_je!=nullptr) throw domain_error("Laptop vec zaduzen");
        kod_koga_je=make_shared<Student>(s);
    }
    int DajEvidencijskiBroj() const
    {
        return ev_broj;
    }
    void Razduzi(){
        kod_koga_je=nullptr;
    }
    string DajNaziv() const
    {
        return naziv;
    }
    Student &DajKodKogaJe(){
        if(kod_koga_je==nullptr) throw domain_error("Laptop nije zaduzen");
        Student &s=*kod_koga_je;
        return s;
    }
    string DajKarakteristike () const
    {
        return karakteristike;
    }
    void Ispisi(){
        cout<<"Evidencijski broj: "<<ev_broj<<endl<<"Naziv: "<<naziv<<endl<<"Karakteristike: "<<karakteristike;
    }
    bool DaLiJeZaduzen() { return kod_koga_je!=nullptr;}

};

class Administracija{
    map<int,shared_ptr<Student>> m1;
    map<int,shared_ptr<Laptop>> m2;
public:
    Administracija() {}
    Administracija &operator =(const Administracija &a){
        if(&a==this) return *this;
        for(auto i=m1.begin(); i!=m1.end(); i++)  i->second=nullptr;
        for(auto i=m2.begin(); i!=m2.end(); i++)  i->second=0;
        m1.clear(); m2.clear();
        for(auto i=a.m1.begin(); i!=a.m1.end(); i++) m1.insert(make_pair(i->first, make_shared<Student>(i->second->DajIndeks(),i->second->DajGodinuStudija(),i->second->DajImePrezime(), i->second->DajAdresu(),i->second->DajTelefon())));
        for(auto i=a.m2.begin(); i!=a.m2.end(); i++) m2.insert(make_pair(i->first, make_shared<Laptop>(i->second->DajEvidencijskiBroj(), i->second->DajNaziv(), i->second->DajKarakteristike())));
        return *this;
        
    }
    ~Administracija(){
        for(auto i=m1.begin(); i!=m1.end(); i++) i->second=nullptr;
        for(auto i=m2.begin(); i!=m2.end(); i++) i->second=nullptr;
        m1.clear(); m2.clear();
    }
    Administracija(Administracija &&a){
        m1=a.m1;
        m2=a.m2;
        for(int i=0; i<m2.size(); i++) a.m2[i]=nullptr;
        for(int i=0; i<m1.size(); i++) a.m1[i]=nullptr;
        a.m1.clear();
        a.m2.clear();

    }
    Administracija(const Administracija &a){
        for(auto i=a.m1.begin(); i!=a.m1.end(); i++) m1.insert(make_pair(i->first, make_shared<Student>(i->second->DajIndeks(),i->second->DajGodinuStudija(),i->second->DajImePrezime(), i->second->DajAdresu(),i->second->DajTelefon())));
        for(auto i=a.m2.begin(); i!=a.m2.end(); i++) m2.insert(make_pair(i->first, make_shared<Laptop>(i->second->DajEvidencijskiBroj(), i->second->DajNaziv(), i->second->DajKarakteristike())));
    }
    void RegistrirajNoviLaptop(int ev, string naz, string kar){
        if(m2.find(ev)!=m2.end()) throw domain_error("Laptop s tim evidencijskim brojem vec postoji");
        m2[ev]=make_shared<Laptop>(ev,naz,kar);
    }
    void RegistrirajNovogStudenta(int ind,string g, string iip, string adr, string brtel){
        if(m1.find(ind)!=m1.end()) throw domain_error("Student s tim indeksom vec postoji");
        m1[ind]=make_shared<Student>(ind, g, iip, adr, brtel);
    }
    Laptop &NadjiLaptop(int ev){
        if(m2.find(ev)==m2.end()) throw domain_error("Laptop nije nadjen");
        return *m2[ev];
    }
    Student &NadjiStudenta(int ind){
        if(m1.find(ind)==m1.end()) throw domain_error("Student nije nadjen");
        return *m1[ind];
    }
    Laptop NadjiLaptop(int ev) const {
        if(m2.find(ev)==m2.end()) throw domain_error("Laptop nije nadjen");
        auto l=m2.find(ev)->second;
        return Laptop(l->DajEvidencijskiBroj(), l->DajNaziv(), l->DajKarakteristike());
    }
    Student NadjiStudenta(int ind) const {
        if(m1.find(ind)==m1.end()) throw domain_error("Student nije nadjen");
        auto s1=m1.find(ind)->second;
        Student s(s1->DajIndeks(),s1->DajGodinuStudija(),s1->DajImePrezime(), s1->DajAdresu(),s1->DajTelefon());
        return s;
    }
    void IzlistajLaptope()
    {
        for(auto i=m2.begin(); i!=m2.end(); i++)
        {
            i->second->Ispisi();
            cout<<endl;
            if(i->second->DaLiJeZaduzen())
            {
                Student &s = i->second->DajKodKogaJe();
                cout<<"Zaduzio(la): "<<s.DajImePrezime()<<" ("<<s.DajIndeks()<<")"<<endl;
            }
            cout<<endl;

        }
    }
    void ZaduziLaptop(int ind, int ev){
        if(m1.find(ind)==m1.end()) throw domain_error("Student nije nadjen");
        if(m2.find(ev)==m2.end()) throw domain_error("Laptop nije nadjen");
        if((m2[ev])->DaLiJeZaduzen()) throw domain_error("Laptop vec zaduzen");
        Student pok=*m1[ind];
        for(auto it=m2.begin(); it!=m2.end(); it++){
            try{
                auto pok1=it->second->DajKodKogaJe();
                if(pok.DajImePrezime()==pok1.DajImePrezime() && pok.DajIndeks()==pok1.DajIndeks() && pok.DajGodinuStudija()==pok1.DajGodinuStudija() && pok.DajTelefon()==pok1.DajTelefon())
                    throw domain_error("Student je vec zaduzio laptop");
            } catch(...){}
        }
        m2[ev]->Zaduzi(*m1[ind]);
    }
    void IzlistajStudente()
    {
        for(auto i=m1.begin(); i!=m1.end(); i++)
        {
            i->second->Ispisi();
            cout<<endl<<endl;
        }
    }
    void PrikaziZaduzenja(){
        auto i=find_if(m2.begin(), m2.end(), [](pair<int,shared_ptr<Laptop>> lap){
            return (lap.second->DaLiJeZaduzen());});
        if(i==m2.end()) { cout<<"Nema zaduzenja"; return;}
        for(auto it=m2.begin(); it!=m2.end(); it++){
            if(it->second->DaLiJeZaduzen()){
                Student &s=it->second->DajKodKogaJe();
                cout<<"Student "<<s.DajImePrezime()<<" (";
                cout<<s.DajIndeks()<<") zaduzio/la laptop broj "<<it->second->DajEvidencijskiBroj()<<endl;
            }
        }
    }
    void RazduziLaptop(int ev){
        if(m2.find(ev)==m2.end()) throw domain_error("Laptop nije nadjen");
        if(!(m2[ev]->DaLiJeZaduzen())) throw domain_error("Laptop vec zaduzen");
        m2[ev]->Razduzi();
    }
    int NadjiSlobodniLaptop(){
        auto it=find_if(m2.begin(), m2.end(), [](pair<int,shared_ptr<Laptop>> lap){
            return !(lap.second->DaLiJeZaduzen());});
        if(it==m2.end()) throw domain_error("Nema slobodnih laptopa");
        return it->second->DajEvidencijskiBroj();
    }
};

int main ()
{ 
    

	return 0;
}
