/B2017/2018: Zadaća 5, Zadatak 2
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <algorithm>
#include <memory>
using namespace std;

class Student {
    int index;
    string imePrezime;
    string adresa;
    string telefon;
    string godinaStudija;
    static string DajBezExtraSpejsova(const string &input) {
        string vrati;
        unique_copy(input.begin(), input.end(), back_inserter<string>(vrati),[](char a, char b) {
            return(a==' ' && b==' ');});
        if(vrati[0]==' ') vrati.erase(vrati.begin());
        return vrati;
    }
    static bool ValidirajTelefon (string telefon) {
        if(telefon[0]<'0' or telefon[0]>'9') return false;
        int i(0);
        while(i<telefon.length() and telefon[i]>='0' and telefon[i]<='9') i++;
        if(i==telefon.length() or telefon[i]!='/') return false;
        i++;
        while(i<telefon.length() and telefon[i]>='0' and telefon[i]<='9') i++;
        if(i==telefon.length() and telefon[i]!='-') return false;
        i++;
        while(i<telefon.length() and telefon[i]>='0' and telefon[i]<='9') i++;
        if(i!=telefon.length()) return false;
        else return true;
    }
    public:
    Student(int index, string godinaStudija, string imePrezime, string adresa, string telefon) {
        if(index<10000 or index> 99999) throw domain_error("Neispravni parametri");
        else this->index=index;
        this->imePrezime=Student::DajBezExtraSpejsova(imePrezime);
        this->adresa=Student::DajBezExtraSpejsova(adresa);
        if(godinaStudija.length()==1) {
            if(godinaStudija[0]>='1' or godinaStudija[0]<='3') this->godinaStudija=godinaStudija;
            else throw domain_error("Neispravni parametri");
        }
        else if(godinaStudija.length()==3) {
            if(godinaStudija[0]<'1' or godinaStudija[0]>'3') throw domain_error("Neispravni parametri");
            if(godinaStudija[1]!='/') throw domain_error("Neispravni parametri");
            if(godinaStudija[2]!='B' and godinaStudija[2]!='M' and godinaStudija[2]!='D') throw domain_error("Neispravni parametri");
            this->godinaStudija=godinaStudija;
        }
        else throw domain_error("Neispravni parametri");
        if(ValidirajTelefon(telefon)) this->telefon=telefon;
        else throw domain_error("Neispravni parametri");
    }
    int DajIndeks() const  {return index;}
    string DajGodinuStudija() const {
        if(godinaStudija.length()!=1) return godinaStudija;
        else return godinaStudija+"/B";
    }
    string DajImePrezime() const {return imePrezime;}
    string DajAdresu() const {return adresa;}
    string DajTelefon() const {return telefon;}
    
    void Ispisi() const {
        cout<<"Broj indeksa: "<<DajIndeks()<<endl;
        cout<<"Godina studija: "<<DajGodinuStudija()<<endl;
        cout<<"Ime i prezime: "<<DajImePrezime()<<endl;
        cout<<"Adresa: "<<DajAdresu()<<endl;
        cout<<"Telefon: "<<DajTelefon()<<endl;
    }
};

class Laptop {
    int ev_broj;
    string naziv;
    string karakteristike;
    Student* kod_koga_je;
    public:
    Laptop (int ev, string name, string kar) {
        if(ev<0) throw domain_error("Neispravni parametri");
        ev_broj=ev;
        naziv=name;
        karakteristike=kar;
        kod_koga_je=nullptr;
    }
    int DajEvidencijskiBroj() const {return ev_broj;}
    string DajNaziv() const {return naziv;}
    string DajKarakteristike() const {return karakteristike;}
    void Zaduzi(Student &s) {
        if(DaLiJeZaduzen()) throw domain_error("Laptop vec zaduzen");
        kod_koga_je=&s;
    }
    void Razduzi() {
        kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzen() const {
        if(kod_koga_je==nullptr) return false;
        else return true;
    }
    Student DajKodKogaJe() const {
        if(DaLiJeZaduzen()) return *kod_koga_je;
        else throw domain_error("Laptop nije zaduzen");
    }
    Student *DajPokKodKogaJe() const {return kod_koga_je;}
    void Ispisi() const {
        cout<<"Evidencijski broj: "<<DajEvidencijskiBroj()<<endl;
        cout<<"Naziv: "<<DajNaziv()<<endl;
        cout<<"Karakteristike: "<<DajKarakteristike()<<endl; 
    }
};

class Administracija {
    map<int,shared_ptr<Student>> studenti;
    map<int,shared_ptr<Laptop>> laptopi;
    public:
    Administracija() {}
    Administracija &operator=(const Administracija &adm) {
        if(this!=&adm) {
            studenti=adm.studenti;
            laptopi=adm.laptopi;
            for(auto it=adm.studenti.begin();it!=adm.studenti.end();it++) studenti[it->first]=make_shared<Student>(*(it->second));
            for(auto it=adm.laptopi.begin();it!=adm.laptopi.end();it++) laptopi[it->first]=make_shared<Laptop>(*(it->second));
            for(auto it=adm.laptopi.begin();it!=adm.laptopi.end();it++) {
                    Student *kodKoga=laptopi[it->first]->DajPokKodKogaJe();
                    if(kodKoga!=nullptr) {
                        laptopi[it->first]->Razduzi();
                        laptopi[it->first]->Zaduzi(*studenti[kodKoga->DajIndeks()]);
                    }
                }
            }
        return *this;
    }
    Administracija (const Administracija &adm) {
        studenti=adm.studenti;
            laptopi=adm.laptopi;
            for(auto it=adm.studenti.begin();it!=adm.studenti.end();it++) studenti[it->first]=make_shared<Student>(*(it->second));
            for(auto it=adm.laptopi.begin();it!=adm.laptopi.end();it++) laptopi[it->first]=make_shared<Laptop>(*(it->second));
            for(auto it=adm.laptopi.begin();it!=adm.laptopi.end();it++) {
                    Student *kodKoga=laptopi[it->first]->DajPokKodKogaJe();
                    if(kodKoga!=nullptr) {
                        laptopi[it->first]->Razduzi();
                        laptopi[it->first]->Zaduzi(*studenti[kodKoga->DajIndeks()]);
                    }
                }
    }
    
    Administracija (Administracija &&adm) {
        studenti=adm.studenti;
        laptopi=adm.laptopi;
    }
    Administracija &operator=(Administracija &&adm) {
        if(this!=&adm) {
            studenti=adm.studenti;
            laptopi=adm.laptopi;
        }
        return *this;
    }
    void RegistrirajNovogStudenta(int index, string godinaStudija, string imePrezime, string adresa, string telefon) {
        if(studenti.count(index)==0) {
            studenti[index]=make_shared<Student>(index,godinaStudija,imePrezime,adresa,telefon);
        }
        else throw domain_error("Student s tim indeksom vec postoji");
    }
    void RegistrirajNoviLaptop(int ev, string name, string kar) {
        if(laptopi.count(ev)==0) {
            laptopi[ev]=make_shared<Laptop>(ev,name,kar);
        }
        else throw domain_error("Laptop s tim evidencijskim brojem vec postoji");
    }
    Student &NadjiStudenta(int index) {
        if(studenti.count(index)!=0) return *studenti[index];
        else throw domain_error("Student nije nadjen");
    }
    Student NadjiStudenta(int index) const {
        bool ima=false;
        for(auto it=studenti.begin();it!=studenti.end();it++) {
            if(it->first==index) {
                ima=true;
                return *(it->second);
            }
        }
        if(!ima) throw domain_error("Student nije nadjen");
    }
    Laptop &NadjiLaptop(int ev) {
        if(laptopi.count(ev)!=0) return *laptopi[ev];
        else throw domain_error("Laptop nije nadjen");
    }
    Laptop NadjiLaptop(int ev) const {
        bool ima=false;
        for(auto it=laptopi.begin();it!=laptopi.end();it++) {
            if(it->first==ev) {
                ima=true;
                return *(it->second);
            }
        }
        if(!ima) throw domain_error("Laptop nije nadjen");
    }
    void IzlistajStudente() const {
        for(auto it=studenti.begin();it!=studenti.end();it++) {
            it->second->Ispisi();
            cout<<endl;
        }
    }
    void IzlistajLaptope() const {
        for(auto it=laptopi.begin();it!=laptopi.end();it++) {
            it->second->Ispisi();
            Student *tmp=it->second->DajPokKodKogaJe();
            if(tmp!=nullptr) {
                cout<<"Zaduzio(la): "<<tmp->DajImePrezime()<<" ("<<tmp->DajIndeks()<<") \n";
            }
            cout<<endl;
        }
    }
    void ZaduziLaptop(int index, int ev) {
        if(studenti.count(index)==0) throw domain_error("Student nije nadjen");
        if(laptopi.count(ev)==0) throw domain_error("Laptop nije nadjen");
        if(laptopi[ev]->DaLiJeZaduzen()==true) throw domain_error("Laptop vec zaduzen");
        Student *tmp=studenti[index].get();
        for(auto it=laptopi.begin();it!=laptopi.end();it++) {
            if(it->second->DajPokKodKogaJe()==tmp) throw domain_error("Student je vec zaduzio laptop");
        }
        laptopi[ev]->Zaduzi(*tmp);
    }
    int NadjiSlobodniLaptop() const {
        for(auto it=laptopi.begin();it!=laptopi.end();it++) {
            if(it->second->DajPokKodKogaJe()==nullptr) return it->first;
        }
        throw domain_error("Nema slobodnih laptopa");
    }
    void RazduziLaptop(int ev) {
        if(laptopi.count(ev)==0) throw domain_error("Laptop nije nadjen");
        if(laptopi[ev]->DaLiJeZaduzen()==false) throw domain_error("Laptop nije zaduzen");
        else laptopi[ev]->Razduzi();
    }
    void PrikaziZaduzenja() const {
        bool imaZaduzenja=false;
        for(auto it=laptopi.begin();it!=laptopi.end();it++) {
            Student *kodKoga=it->second->DajPokKodKogaJe();
            if(kodKoga!=nullptr) {
                imaZaduzenja=true;
                cout<<"Student "<<kodKoga->DajImePrezime()<<" ("<<kodKoga->DajIndeks()<<") zaduzio/la laptop broj"<<it->first<<endl;
            }
        }
        if(imaZaduzenja==false) cout<<"Nema zaduzenja";
    }
};
int main ()
{
    Administracija t;
    t.RegistrirajNoviLaptop(15,"   a   "," b   x ccc  ");
    t.RegistrirajNovogStudenta(16541,"3/M","amila","hehe","061/252-322");
    t.ZaduziLaptop(16541,15);
    t.IzlistajLaptope();
	return 0;
}
