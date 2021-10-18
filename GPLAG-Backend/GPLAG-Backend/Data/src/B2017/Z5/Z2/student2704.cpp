/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <utility>
#include <memory>

using namespace std;




class Student{
    int index;
    string god,imePrezime,adresa,brojTel;
    
    bool provjeraIndexa(int par);
    bool provjeraIPostavaGodina(string &god);
    void kracenjePraznina(string &ime);
    bool provjeraTelefona(string tel);


public:

    Student(int ix, string godina, string ime, string adr, string broj);
    int DajIndeks() const { return index;}
    string DajGodinuStudija() const { return god;}
    string DajImePrezime() const { return imePrezime; }
    string DajAdresu() const { return adresa; }
    string DajTelefon() const { return brojTel; }
    void Ispisi() const;
};

void Student::Ispisi() const{
    cout<<"Broj indeksa: "<<DajIndeks()<<endl;
    cout<<"Godina studija: "<<DajGodinuStudija()<<endl;
    cout<<"Ime i prezime: "<<DajImePrezime()<<endl;
    cout<<"Adresa: "<<DajAdresu()<<endl;
    cout<<"Telefon: "<<DajTelefon()<<endl;
}


void Student::kracenjePraznina(string &ime){
    bool razmak(false);
    bool biloSlovo(false);
    for(int i=0; i<ime.size(); i++){
        if(ime.at(i)!=' '){
            biloSlovo=true;
            continue;
        }
        if(ime.at(i)==' '){
            if(!biloSlovo or razmak){
                ime.erase(ime.begin()+i);
                i--;
            }
            else
                razmak=true;
        }
        else{
            razmak=false;
            biloSlovo=true;
        }
    }
    if(ime.length()>0 and ime.at(ime.length()-1)==' ')
        ime.erase(ime.end()-1);
}

bool Student::provjeraIndexa(int par){
    if(par<0) return false;
    int brojac(5);
    while(brojac>0){
        if(par==0) return false;
        par/=10;
        brojac--;
    }
    if(par!=0) return false;
    return true;
}

bool Student::provjeraIPostavaGodina(string &god){
    if(god.compare("1")!=0 && god.compare("2")!=0 and god.compare("3")!=0 and god.compare("1/B")!=0 and god.compare("2/B")!=0
    and god.compare("3/B")!=0 and god.compare("1/M")!=0 and god.compare("2/M")!=0 and god.compare("1/D")!=0 and god.compare("2/D")!=0
    and god.compare("3/D")!=0) return false;
    
    if(god.compare("1")==0)
        god="1/B";
    else if (god.compare("2")==0)
        god="2/B";
    else if(god.compare("3")==0)
        god="3/B";
    
    return true;
}

bool Student::provjeraTelefona(string tel){
    if(tel.size()<5) return false; //  minimalna duzina iz primjera 1/1-1
    int i(0),j(0),c('/');
    for(int k=0; k<3; k++){
        for(; i<tel.size(); i++){
            if(!(tel.at(i)>='0' and tel.at(i)<='9') and tel.at(i)!=c) return false;
            if(k<2 and tel.at(i)==c and i==j) return false;
            if(k<2 and tel.at(i)==c) break;
        }
        i++;
        if(k!=2 and tel.size()<=i) return false;
        if(k==0) {
            c='-';
            j=i;
        }
    }
    return true;
}


Student::Student(int ix,string godina, string ime, string adr, string broj){
    if(!provjeraIndexa(ix) or !provjeraIPostavaGodina(godina) or !provjeraTelefona(broj))
        throw domain_error("Neispravni parametri");
    imePrezime=ime;
    kracenjePraznina(imePrezime);
    index=ix;
    god=godina;
    adresa=adr;
    brojTel=broj;
}


class Laptop{
    int ev_broj;
    string naziv;
    string karakteristike;
    Student* kod_koga_je;   //ovdje nema smisla da bude pametni pokazivac jer ne znamo da li ce uopste biti u pitanju dinamicki alociran objekat Student
    
public:

    Laptop(int broj, string naziv, string karakteristike);
    int DajEvidencijskiBroj() const{ return ev_broj;}
    string DajNaziv() const { return naziv;}
    string DajKarakteristike() const { return karakteristike; }
    void Zaduzi( Student& studo);
    void Razduzi();
    bool DaLiJeZaduzen() const;
    Student& DajKodKogaJe() const;
    Student* DajPokKodKogaJe() const;
    void Ispisi() const;
};

void Laptop::Ispisi() const{
    cout<<"Evidencijski broj: "<<ev_broj<<endl;
    cout<<"Naziv: "<<naziv<<endl;
    cout<<"Karakteristike: "<<karakteristike<<endl;
    
}

Student* Laptop::DajPokKodKogaJe() const{
    return kod_koga_je;
}

Student& Laptop::DajKodKogaJe() const {
    if(!DaLiJeZaduzen()) throw domain_error("Laptop nije zaduzen");
    return *kod_koga_je;
}

bool Laptop::DaLiJeZaduzen() const{
    return kod_koga_je!=nullptr;
}


void Laptop::Razduzi(){
    kod_koga_je=nullptr;
}

void Laptop::Zaduzi( Student& studo){
    if(DaLiJeZaduzen()) throw domain_error("Laptop vec zaduzen");
    kod_koga_je=&studo;
}

Laptop::Laptop(int broj, string naziv, string karakteristike){
    if(broj<0) throw domain_error("Neispravni parametri");
    ev_broj=broj;
    this->naziv=naziv;
    this->karakteristike=karakteristike;
    kod_koga_je=nullptr;
}


class Administracija{
    map<int,shared_ptr<Student>> studenti;
    map<int,shared_ptr<Laptop>> laptopi;
    
public:
    Administracija(){};
    Administracija(const Administracija& admini);
    Administracija(Administracija&& admini);
    Administracija& operator =(Administracija admini);      //kopiraj-i-razmijeni
    ~Administracija();
    void RegistrirajNovogStudenta(int ix, string godina, string ime, string adr, string broj);
    void RegistrirajNoviLaptop(int broj, string naziv, string karakteristike);
    Student& NadjiStudenta(int indeks);
    Laptop& NadjiLaptop(int ev);
    void IzlistajStudente() const;
    void IzlistajLaptope() const;
    void ZaduziLaptop(int ix,int ev);
    int NadjiSlobodniLaptop() const;
    void RazduziLaptop(int ev);
    void PrikaziZaduzenja() const;
};

Administracija::~Administracija(){
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++){
        it->second->Razduzi();
    }
    laptopi.clear();
}

void Administracija::PrikaziZaduzenja() const{
    bool ima(false);
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++){
        ima=true;
        if(it->second->DaLiJeZaduzen()){
            Student s(it->second->DajKodKogaJe());
            cout<<"Student "<<s.DajImePrezime()<<" ("<<s.DajIndeks()<<") zaduzio/la laptop broj "<<it->second->DajEvidencijskiBroj()<<endl;
        }
    }
    if(!ima)
        cout<<"Nema zaduzenja"<<endl;
}


void Administracija::RazduziLaptop(int ev){
    Laptop p(NadjiLaptop(ev));
    if(p.DaLiJeZaduzen()==false) throw domain_error("Laptop nije zaduzen");
    NadjiLaptop(ev).Razduzi();
}

int Administracija::NadjiSlobodniLaptop() const{
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++){
        if(it->second->DaLiJeZaduzen()==false) return it->second->DajEvidencijskiBroj();
    }
    throw domain_error("Nema slobodnih laptopa");
}

void Administracija::ZaduziLaptop(int ix, int ev){
    Student s(NadjiStudenta(ix));
    if(NadjiLaptop(ev).DaLiJeZaduzen()) throw domain_error("Laptop vec zaduzen");
    
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++){
        if(it->second->DaLiJeZaduzen() and it->second->DajKodKogaJe().DajIndeks()==s.DajIndeks())
            throw domain_error("Student je vec zaduzio laptop");
    }
    NadjiLaptop(ev).Zaduzi(NadjiStudenta(ix));
}

void Administracija::IzlistajLaptope() const{
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++){
        it->second->Ispisi();
        if(it->second->DaLiJeZaduzen()){
            Student s(it->second->DajKodKogaJe());
            cout<<"Zaduzio(la): "<<s.DajImePrezime()<<" ("<<s.DajIndeks()<<")"<<endl;
        }
        cout<<endl;
    }
}

void Administracija::IzlistajStudente() const{
    for(auto it=studenti.begin(); it!=studenti.end(); it++){
        it->second->Ispisi();
        cout<<endl;
    }
}

Laptop& Administracija::NadjiLaptop(int ev){
    if(laptopi.find(ev)==laptopi.end()) throw domain_error("Laptop nije nadjen");
    return *(laptopi.find(ev)->second);
}

Student& Administracija::NadjiStudenta(int indeks){
    if(studenti.find(indeks)==studenti.end()) throw domain_error("Student nije nadjen");
    return *(studenti.find(indeks)->second);
}

void Administracija::RegistrirajNovogStudenta(int ix, string godina, string ime, string adr, string broj){
    if(studenti.find(ix)!=studenti.end()) throw domain_error("Student s tim indeksom vec postoji");    
    studenti.insert({ix,make_shared<Student>(ix,godina,ime,adr,broj)});
}


void Administracija::RegistrirajNoviLaptop(int broj, string naziv, string karakteristike){
    if(laptopi.find(broj)!=laptopi.end()) throw domain_error("Laptop s tim evidencijskim brojem vec postoji");    
    laptopi.insert({broj,make_shared<Laptop>(broj,naziv,karakteristike)});
}



Administracija& Administracija::operator =(Administracija admini){
    std::swap(studenti,admini.studenti);
    std::swap(laptopi,admini.laptopi);
    return *this;
}

Administracija::Administracija(Administracija&& admini): studenti(admini.studenti), laptopi(admini.laptopi){
    admini.studenti.clear();
    admini.laptopi.clear();
}

Administracija::Administracija(const Administracija& admini){
    for(auto it=admini.studenti.begin(); it!=admini.studenti.end(); it++){
        studenti.insert(make_pair(it->first,make_shared<Student>(*it->second)));
    }
    
    for(auto it=admini.laptopi.begin(); it!=admini.laptopi.end(); it++){
        laptopi.insert(make_pair(it->first,make_shared<Laptop>(*it->second)));
    }
}

int main ()
{
 
    Administracija admini;
    int n(0);
    do{
        cout<<"0. Kraj programa"<<endl;
        cout<<"1. Registriraj novog studenta"<<endl;
        cout<<"2. Registriraj novi laptop"<<endl;
        cout<<"3. Nadji studenta"<<endl;
        cout<<"4. Nadji laptop"<<endl;
        cout<<"5. Izlistaj studente"<<endl;
        cout<<"6. Izlistaj laptope"<<endl;
        cout<<"7. Zaduzi laptop"<<endl;
        cout<<"8. Razduzi laptop"<<endl;
        cout<<"9. Nadji slobodan laptop"<<endl;
        cout<<"10. Izlistaj zaduzenja"<<endl;
        cout<<"Unesite broj opcije: ";
        cin>>n;
        
        
        try{
            switch(n){
                case 0:{
                    return 0;
                }
                case 1:{
                    int indeks;
                    cout<<"Unesite broj indeksa studenta: ";
                    cin>>indeks;
                    cin.ignore(10000,'\n');
                    string godina,ime,adr,telefon;
                    cout<<"Unesite godinu studija u formatu: 1,2,3,1/B,2/B,3/B,1/M,2/M,1/D,2/D ili 3/D: ";
                    getline(cin,godina);
                    cout<<"Unesite ime i prezime studenta: ";
                    getline(cin,ime);
                    cout<<"Unesite adresu stanovanja studenta: ";
                    getline(cin,adr);
                    cout<<"Unesite broj telefona u obliku cifre/cifre-cifre: ";
                    getline(cin,telefon);
                    admini.RegistrirajNovogStudenta(indeks,godina,ime,adr,telefon);
                    cout<<"Student uspjesno dodan!"<<endl<<endl;
                    break;
                }
                case 2:{
                    int ev_broj;
                    cout<<"Unesite evidencijski broj: ";
                    cin>>ev_broj;
                    cin.ignore(10000,'\n');
                    cout<<"Unesite puni naziv laptopa: ";
                    string naziv,opis;
                    getline(cin,naziv);
                    cout<<"Unesite opis specifikacija laptopa: ";
                    getline(cin,opis);
                    admini.RegistrirajNoviLaptop(ev_broj,naziv,opis);
                    cout<<"Laptop uspjesno dodan!"<<endl<<endl;
                    break;
                    
                }
                
                case 3:{
                    int ev;
                    cout<<"Unesite indeks studenta: ";
                    cin>>ev;
                    Student s(admini.NadjiStudenta(ev));
                    cout<<"Student uspjesno pronadjen:\n";
                    s.Ispisi();
                    break;
                    
                }
                
                case 4:{
                    int ev;
                    cout<<"Unesite evidencijski broj laptopa: ";
                    cin>>ev;
                    Laptop p(admini.NadjiLaptop(ev));
                    cout<<"Laptop uspjesno pronadjen:\n";
                    p.Ispisi();
                    break;
                }
                case 5:{
                    cout<<"Lista svih studenata:"<<endl;
                    admini.IzlistajStudente();
                    break;
                }
                case 6:{
                    cout<<"Lista svih laptopa: "<<endl;
                    admini.IzlistajLaptope();
                    break;
                }
                case 7:{
                    cout<<"Unesite indeks studenta koji zaduzuje laptop: ";
                    int indeks;
                    cin>>indeks;
                    cout<<"Unesite evidencijski broj laptopa koji se zaduzuje: ";
                    int ev;
                    cin>>ev;
                    admini.ZaduziLaptop(indeks,ev);
                    cout<<"Laptop uspjesno zaduzen"<<endl;
                    break;
                }
                case 8:{
                    cout<<"Unesite evidencijski broj laptopa koji se razduzuje: ";
                    int ev;
                    cin>>ev;
                    admini.RazduziLaptop(ev);
                    cout<<"Laptop uspjesno razduzen"<<endl;
                    break;
                }
                case 9:{
                    int n(admini.NadjiSlobodniLaptop());
                    cout<<"Evidencijski broj prvog slobodnog laptopa: "<<n<<endl;
                    break;
                }
                case 10:{
                    cout<<"Lista svih zaduzenja:\n";
                    admini.PrikaziZaduzenja();
                    break;
                }
                
            }
        }
        catch(domain_error e){
            cout<<e.what()<<endl<<endl;
        }
    }while(n!=0);
    
	return 0;
}
