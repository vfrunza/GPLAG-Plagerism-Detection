/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <memory>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int cifre(int number)
    {
        int digits = 0;
        if (number < 0) digits = 1;
        while (number) {
            number /= 10;
            digits++;
        }
        return digits;
    }
void ocistirazmake(string &str){
        int zadnje;
        for(int i=0; i<str.size(); i++) if(str[i]!=' ') zadnje=i;
        str=str.substr(0,zadnje+1);
        //cout<<str<<endl<<endl;
        for(int i=0; i<str.size(); i++) if(str[i]!=' ') {zadnje=i; break;}
        str=str.substr(zadnje,str.size());
        for(int i=0;i<str.size();i++)
        {if((str[i]==' ')&&(str[i+1]==' '))
         for(;;)
         {
          if(str[i+1]!=' ')
          break;
          else
         for(int j=i;j<str.size();j++)
          //str[j+1]=str[j];i++;}
          str[j]=str[j+1];str.resize(str.size()-1);} 
         }
    }

class Student{
protected:
    int indeks;
    string godinastudija;
    string imeiprezime;
    string adresa;
    string brtel;
public:
    Student(int ind,string g, string iip, string adr, string brtel){
        if(cifre(ind)!=5) throw domain_error("Neispravni parametri");
        if(g!="1" && g!= "2" && g!= "3"&& g!= "1/B" && g!= "2/B" && g!= "3/B" && g!= "1/M" && g!= "2/M"&& g!= "1/D"&&g!= "2/D" && g!= "3/D") throw domain_error("Neispravni parametri");
        int bkroz=0, bcrta=0;
        for(int i=0; i<brtel.size(); i++)
        {
            if(brtel[i]=='/') bkroz++;
            else if(brtel[i]=='-') bcrta++;
            else if(brtel[i]<'0' || brtel[i]>'9') throw domain_error("Neispravni parametri");
        }
        if(bkroz>1 || bcrta>1) throw domain_error("Neispravni parametri");
        ocistirazmake(iip); ocistirazmake(adr);
        if(g.size()==1) g+="/B";
        indeks=ind; godinastudija=g; imeiprezime=iip; adresa=adr; Student::brtel=brtel;

    }
    int DajIndeks() const { return indeks;}
    string DajGodinuStudija() const { return godinastudija;}
    string DajImePrezime() const { return imeiprezime;}
    string DajAdresu() const { return adresa;}
    string DajTelefon() const { return brtel;}
    void Ispisi(){
        cout<<"Broj indeksa: "<<indeks<<endl;
        cout<<"Godina studija: "<<godinastudija<<endl;
        cout<<"Ime i prezime: "<<imeiprezime<<endl;
        cout<<"Adresa: "<<adresa<<endl;
        cout<<"Telefon: "<<brtel;

    }
};

class Laptop{
    int ev_broj;
    string naziv, karakteristike;
    shared_ptr<Student> kod_koga_je;
public:
    Laptop(int ev, string naz, string kar){
        if(ev<0) throw domain_error("Neispravni parametri");
        ev_broj=ev; naziv=naz; karakteristike=kar;
        kod_koga_je=nullptr;
    }
    int DajEvidencijskiBroj() const
    {
        return ev_broj;
    }
    string DajNaziv() const
    {
        return naziv;
    }
    string DajKarakteristike () const
    {
        return karakteristike;
    }
    void Zaduzi(Student &s){
        if(kod_koga_je!=nullptr) throw domain_error("Laptop vec zaduzen");
        kod_koga_je=make_shared<Student>(s);
    }
    void Razduzi(){
        kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzen() { return kod_koga_je!=nullptr;}
    Student &DajKodKogaJe(){
        if(kod_koga_je==nullptr) throw domain_error("Laptop nije zaduzen");
        Student &s=*kod_koga_je;
        return s;
    }
    void Ispisi(){
        cout<<"Evidencijski broj: "<<ev_broj<<endl;
        cout<<"Naziv: "<<naziv<<endl;
        cout<<"Karakteristike: "<<karakteristike;
    }
};

class Administracija{
    map<int,shared_ptr<Student>> studenti;
    map<int,shared_ptr<Laptop>> laptopi;
public:
    Administracija() {}
    ~Administracija(){
        for(auto i=studenti.begin(); i!=studenti.end(); i++)  i->second=nullptr;
        for(auto i=laptopi.begin(); i!=laptopi.end(); i++) i->second=nullptr;
        studenti.clear(); laptopi.clear();
    }
    Administracija &operator =(const Administracija &a){
        if(&a==this) return *this;
        for(auto i=studenti.begin(); i!=studenti.end(); i++)  i->second=nullptr;
        for(auto i=laptopi.begin(); i!=laptopi.end(); i++)  i->second=nullptr;
        studenti.clear(); laptopi.clear();
        for(auto i=a.studenti.begin(); i!=a.studenti.end(); i++) studenti.insert(make_pair(i->first, make_shared<Student>(i->second->DajIndeks(),i->second->DajGodinuStudija(),i->second->DajImePrezime(), i->second->DajAdresu(),i->second->DajTelefon())));
        for(auto i=a.laptopi.begin(); i!=a.laptopi.end(); i++) laptopi.insert(make_pair(i->first, make_shared<Laptop>(i->second->DajEvidencijskiBroj(), i->second->DajNaziv(), i->second->DajKarakteristike())));
        return *this;
        
    }
    Administracija(const Administracija &a){
      
        for(auto i=a.studenti.begin(); i!=a.studenti.end(); i++) studenti.insert(make_pair(i->first, make_shared<Student>(i->second->DajIndeks(),i->second->DajGodinuStudija(),i->second->DajImePrezime(), i->second->DajAdresu(),i->second->DajTelefon())));
        for(auto i=a.laptopi.begin(); i!=a.laptopi.end(); i++) laptopi.insert(make_pair(i->first, make_shared<Laptop>(i->second->DajEvidencijskiBroj(), i->second->DajNaziv(), i->second->DajKarakteristike())));
        

    }
    Administracija(Administracija &&a){
        studenti=a.studenti;
        laptopi=a.laptopi;
        for(auto it=a.studenti.begin(); it!=a.studenti.end(); it++) it->second=nullptr;
        for(auto it=a.laptopi.begin(); it!=a.laptopi.end(); it++) it->second=nullptr;
        a.studenti.clear();
        a.laptopi.clear();

    }
    void RegistrirajNovogStudenta(int ind,string g, string iip, string adr, string brtel){
        if(studenti.find(ind)!=studenti.end()) throw domain_error("Student s tim indeksom vec postoji");
        studenti[ind]=make_shared<Student>(ind, g, iip, adr, brtel);
    }
    void RegistrirajNoviLaptop(int ev, string naz, string kar){
        if(laptopi.find(ev)!=laptopi.end()) throw domain_error("Laptop s tim evidencijskim brojem vec postoji");
        laptopi[ev]=make_shared<Laptop>(ev,naz,kar);
    }
    Student &NadjiStudenta(int ind){
        if(studenti.find(ind)==studenti.end()) throw domain_error("Student nije nadjen");
        return *studenti[ind];
    }
    Student NadjiStudenta(int ind) const {
        if(studenti.find(ind)==studenti.end()) throw domain_error("Student nije nadjen");
        auto s1=studenti.find(ind)->second;
        Student s(s1->DajIndeks(),s1->DajGodinuStudija(),s1->DajImePrezime(), s1->DajAdresu(),s1->DajTelefon());
        return s;
    }
    Laptop &NadjiLaptop(int ev){
        if(laptopi.find(ev)==laptopi.end()) throw domain_error("Laptop nije nadjen");
        return *laptopi[ev];
    }
    Laptop NadjiLaptop(int ev) const {
        if(laptopi.find(ev)==laptopi.end()) throw domain_error("Laptop nije nadjen");
        auto l=laptopi.find(ev)->second;
        return Laptop(l->DajEvidencijskiBroj(), l->DajNaziv(), l->DajKarakteristike());
    }
    void IzlistajStudente()
    {
        for(auto i=studenti.begin(); i!=studenti.end(); i++)
        {
            i->second->Ispisi();
            cout<<endl<<endl;
        }
    }
    void IzlistajLaptope()
    {
        for(auto i=laptopi.begin(); i!=laptopi.end(); i++)
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
        if(studenti.find(ind)==studenti.end()) throw domain_error("Student nije nadjen");
        if(laptopi.find(ev)==laptopi.end()) throw domain_error("Laptop nije nadjen");
        if((laptopi[ev])->DaLiJeZaduzen()) throw domain_error("Laptop vec zaduzen");
        Student pok=*studenti[ind];
        for(auto it=laptopi.begin(); it!=laptopi.end(); it++){
            try{
                auto pok1=it->second->DajKodKogaJe();
                if(pok.DajImePrezime()==pok1.DajImePrezime() && pok.DajIndeks()==pok1.DajIndeks() && pok.DajGodinuStudija()==pok1.DajGodinuStudija() && pok.DajTelefon()==pok1.DajTelefon())
                    throw domain_error("Student je vec zaduzio laptop");
            } catch(...){}
        }
        laptopi[ev]->Zaduzi(*studenti[ind]);
    }
    int NadjiSlobodniLaptop(){
        auto it=find_if(laptopi.begin(), laptopi.end(), [](pair<int,shared_ptr<Laptop>> lap){
            return !(lap.second->DaLiJeZaduzen());});
        if(it==laptopi.end()) throw domain_error("Nema slobodnih laptopa");
        return it->second->DajEvidencijskiBroj();
    }
    void RazduziLaptop(int ev){
        if(laptopi.find(ev)==laptopi.end()) throw domain_error("Laptop nije nadjen");
        if(!(laptopi[ev]->DaLiJeZaduzen())) throw domain_error("Laptop vec zaduzen");
        laptopi[ev]->Razduzi();
    }
    void PrikaziZaduzenja(){
        auto i=find_if(laptopi.begin(), laptopi.end(), [](pair<int,shared_ptr<Laptop>> lap){
            return (lap.second->DaLiJeZaduzen());});
        if(i==laptopi.end()) { cout<<"Nema zaduzenja"; return;}
        for(auto it=laptopi.begin(); it!=laptopi.end(); it++){
            if(it->second->DaLiJeZaduzen()){
                Student &s=it->second->DajKodKogaJe();
                cout<<"Student "<<s.DajImePrezime()<<" ("<<s.DajIndeks()<<") zaduzio/la laptop broj "<<it->second->DajEvidencijskiBroj()<<endl;
            }
        }
    }
};

int main ()
{ 
    Administracija a;
    int n;
    while(0==0)
    {
        cout<<"1 - registracija studenta"<<endl;
        cout<<"2 - registracija laptopa"<<endl;
        cout<<"3 - pretraga studenata"<<endl;
        cout<<"4 - pretraga laptopa"<<endl;
        cout<<"5 - ispis svih studenata"<<endl;\
        cout<<"6 - ispis svih laptopa"<<endl;
        cout<<"7 - zaduzenje laptopa na studenta"<<endl;
        cout<<"8 - prvi nezaduzen laptop"<<endl;
        cout<<"9 - razduzi laptop"<<endl;
        cout<<"10 - prikaz svih zaduzenja"<<endl;
        cout<<"0 - izlaz"<<endl;
        cout<<"Unesite broj: ";
        cin>>n;
        if(n==0) break;
        else if(n==1)
        {
            try
            {
                cout<<"Unesite indeks, godinu studija, ime i prezime, adresu i broj telefona studenta: ";
                cout<<"Indeks: ";
                int ind;
                cin>>ind;
                cin.ignore(1000, '\n');
                cout<<"Godina studija: ";
                string gs;
                getline(cin,gs);
                //cin.ignore(1000, '\n');
                cout<<"Ime i prezime: ";
                string iip;
                getline(cin,iip);
                //cin.ignore(1000,'\n');
                cout<<"Adresa: ";
                string adr;
                getline(cin,adr);
                //cin.ignore(1000, '\n');
                cout<<"Broj telefona: ";
                string tel;
                getline(cin,tel);
                //cin.ignore(1000, '\n');
                a.RegistrirajNovogStudenta(ind, gs, iip, adr, tel);
                cout<<"Student registrovan!"<<endl<<endl;

            }
            catch(domain_error izuz)
            {
                cout<<izuz.what()<<endl<<"Pokusajte ponovo!"<<endl;
            }
        }
        else if(n==2)
        {
            cout<<"Unesite evidencijski broj, naziv i karakteristike laptopa: "<<endl;
            cout<<"Evidencijski broj: ";
            int ev;
            cin>>ev;
            //cin.ignore(10000, '\n');
            cout<<"Naziv: ";
            string ime;
            getline(cin,ime);
            //cin.ignore(1000, '\n');
            cout<<"Karakteristike: ";
            string chr;
            getline(cin,chr);
            a.RegistrirajNoviLaptop(ev, ime, chr);
            cout<<"Laptop registrovan!"<<endl<<endl;
        }
        else if(n==3)
        {
            cout<<"Unesite indeks studenta kojeg zelite pronaci: ";
            int zlj;
            try
            {
                cin>>zlj;
                Student s = a.NadjiStudenta(zlj);
                cout<<"Student kojeg trazite je: "<<endl;
                s.Ispisi();
            }
            catch(domain_error izuz)
            {
                cout<<izuz.what();
            }
        }
        else if(n==4)
        {
            cout<<"Unesite evidencijski broj laptopa kog trazite: ";
            try
            {
                int zlj;
                cin>>zlj;
                Laptop l = a.NadjiLaptop(zlj);
                cout<<"Laptop kojeg trazite je: "<<endl;
                l.Ispisi();
            }
            catch(domain_error izuz)
            {
                cout<<izuz.what();
            }
        }
        else if(n==5)
        {
            cout<<"Registrovani studenti: "<<endl<<endl;
            a.IzlistajStudente();
        }
        else if(n==6)
        {
            cout<<"Registrovani laptopi: "<<endl<<endl;
            a.IzlistajLaptope();
        }
        else if(n==7)
        {
            cout<<"Unesite indeks studenta i evidencijski broj laptopa kojeg zelite zaduziti na tog studenta: ";
            try
            {
                int zlj, sklj;
                cin>>zlj>>sklj;
                a.ZaduziLaptop(zlj, sklj);
                cout<<"Laptop je zaduzen na trazenog studenta!"<<endl<<endl;
            }
            catch(domain_error izuz)
            {
                cout<<izuz.what();
            }
        }
        else if(n==8)
        {
            try
            {
                cout<<"Prvi nezaduzeni laptop je: "<<endl<<endl;
                int bl = a.NadjiSlobodniLaptop();
                Laptop l = a.NadjiLaptop(bl);
                l.Ispisi();
            }
            catch(domain_error izuz)
            {
                cout<<izuz.what();
            }
        }
        else if(n==9)
        {
            try
            {
                cout<<"Unesite evidencijski broj laptopa kojeg zelite razduziti: ";
                int zlj;
                cin>>zlj;
                a.RazduziLaptop(zlj);
                cout<<"Laptop je uspjesno razduzen!"<<endl<<endl;
            }
            catch(domain_error izuz)
            {
                cout<<izuz.what();
            }
        }
        else if(n==10)
        {
            cout<<"Studenti koji su zaduzili laptope su sljedeci: "<<endl<<endl;
            a.PrikaziZaduzenja();
        }
        else cout<<"Niste unijeli ispravan broj!"<<endl;
    }

	return 0;
}
