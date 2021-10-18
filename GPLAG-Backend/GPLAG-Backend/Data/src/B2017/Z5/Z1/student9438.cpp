/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <map>
#include <iterator>
using namespace std;

class Student
{
    int broj_indeksa;
    string godina_studija;
    string ime_i_prezime;
    string adresa;
    string broj_tel;
    
public:
    Student (int broj_indeksa, string godina_studija, string ime_i_prezime, string adresa, string broj_tel):broj_indeksa(broj_indeksa), ime_i_prezime(ime_i_prezime), adresa(adresa), broj_tel(broj_tel) {}
    
    int DajIndeks() const
    {
        return broj_indeksa;
    }
    
    string DajGodinuStudija() const
    {
        return godina_studija;
    }
    
    string DajImePrezime() const
    {
        return ime_i_prezime;
    }
    
    string DajAdresu() const
    {
        return adresa;
    }
    
    string DajTelefon() const
    {
        return broj_tel;
    }
    
    void Ispisi() const
    {
        cout << "Broj indeksa: " << broj_indeksa << endl;
        cout << "Godina studija: " << godina_studija << endl;
        cout << "Ime i prezime: " << ime_i_prezime << endl;
        cout << "Adresa: " << adresa << endl;
        cout << "Telefon: " << broj_tel << endl;
    }
};

class Laptop
{
    int ev_broj;
    string naziv;
    string karakteristike;
    Student *kod_koga_je;
    
public:
    Laptop(int ev_broj, string naziv, string karakteristike):ev_broj(ev_broj), naziv(naziv), karakteristike(karakteristike), kod_koga_je(nullptr) {
        if(ev_broj < 0) throw domain_error("Neispravni parametri!");
    }

    int DajEvidencijskiBroj() const
    {
        return ev_broj;
    }
    
    string DajNaziv() const
    {
        return naziv;
    }
    
    string DajKarakteristike() const
    {
        return karakteristike;
    }
    
    Student *DajKodKogaJe()
    {
        return kod_koga_je;
    }
    
    Student &DajKodKogaJe() const {
        if(kod_koga_je == nullptr) throw domain_error("Laptop nije zaduzen");
        return *kod_koga_je;
    }
    
    void Zaduzi(Student &zaduzioc)
    {
        kod_koga_je=&zaduzioc;
    }
    
    void Razduzi()
    {
        kod_koga_je=nullptr;
    }
    
    bool DaLiJeZaduzen()
    {
        if(!kod_koga_je || kod_koga_je==nullptr) return false;
        return true;
    }
    
    void Ispisi() const
    {
        cout << "Evidencijski broj: " << ev_broj << endl;
        cout << "Naziv: " << naziv << endl;
        cout << "Karakteristike: " << karakteristike << endl;
    }

};

class Administracija
{
    vector<shared_ptr <Student>> studenti;
    vector<shared_ptr <Laptop>> laptopi;
    
public:
    Administracija() {}
    Administracija (const Administracija &a) = delete;
    Administracija &operator=(const Administracija &a) = delete;
    
    void RegistrirajNovogStudenta(int broj_indeksa, string godina_studija, string ime_i_prezime, string adresa, string broj_tel) {
        bool ima=false;
        for(int i(0); i < studenti.size(); i++)
        {
            if(studenti[i] -> DajIndeks()==broj_indeksa)
            {
                ima=true;
                break;
            }
        }
        
        if(ima) throw domain_error("Student sa tim indeksom vec postoji");
        
        shared_ptr<Student> pomocni=make_shared<Student>(broj_indeksa, ime_i_prezime, adresa, broj_tel);
        studenti.push_back(pomocni);
        //studenti[broj_indeksa] = new Student(broj_indeksa, godina_studija, ime_i_prezime, adresa, broj_tel);
    }
    
    void RegistrirajNoviLaptop(int ev_broj, string naziv, string karakteristike)
    {
        bool ima=false;
        for(int i(0); i < laptopi.size(); i++)
        {
            if(laptopi[i] -> DajEvidencijskiBroj()==ev_broj)
            {
                ima=true;
                break;
            }
        }
        
        if(ima) throw domain_error("Laptop sa tim evidencijskim brojem vec postoji");
        
        shared_ptr<Laptop> pomocni=make_shared<Laptop>(ev_broj, naziv, karakteristike);
        laptopi.push_back(pomocni);
        //laptopi[ev_broj] = new Laptop(ev_broj, naziv, karakteristike);
    }
    
    Student &NadjiStudenta(int br_indeksa)
    {
        for(int i=0; i<studenti.size(); i++)
        {
            if(studenti[i]->DajIndeks()==br_indeksa) return *studenti[i];
        }
        throw domain_error("Student nije nadjen");
    }
    
    Laptop &NadjiLaptop(int ev_br)
    {
        for(int i=0; i<laptopi.size(); i++)
        {
            if(laptopi[i]->DajEvidencijskiBroj()==ev_br) return *laptopi[i];
        }
        throw domain_error("Laptop nije nadjen");
    }
    
    void IzlistajStudente()
    {
        for(auto x: studenti)
        {
            x->Ispisi();
            cout<<endl;
        }

    }
    
    void IzlistajLaptope()
    {
        for(auto x: laptopi)
        {
            x->Ispisi();
            if(x->DaLiJeZaduzen())
            {
                cout<<"Zaduzena kod clana:\n";
                auto vb=x->DajKodKogaJe();
                vb->Ispisi();
            }
            cout<<endl;
        }
    }
    
    void RazduziLaptop(int ev_br)
    {
        try
        {
            NadjiLaptop(ev_br);
        }
        catch(domain_error x)
        {
            throw x;
        }
        if(!NadjiLaptop(ev_br).DaLiJeZaduzen()) throw domain_error("Laptop nije zaduzen");
        NadjiLaptop(ev_br).Razduzi();
    }
    void ZaduziLaptop(int ev_br, int br_indeksa)
    {
        try
        {
            NadjiLaptop(ev_br);
            NadjiStudenta(br_indeksa);
        }
        catch(domain_error x)
        {
            throw x;
        }
        if(NadjiLaptop(ev_br).DaLiJeZaduzen()) throw domain_error("Laptop vec zaduzena");
        NadjiLaptop(ev_br).Zaduzi(NadjiStudenta(br_indeksa));
    }
    
    void PrikaziZaduzenja(int br_indeksa) {
        try
        {
            NadjiStudenta(br_indeksa);
            if (!laptopi.size()) cout<<"Nema zaduzenja za tog studenta!\n";
            bool test=false;
            for(auto x: laptopi)
            {
                if(x->DaLiJeZaduzen())
                {
                    test=false;
                    auto vb=x->DajKodKogaJe();
                    if(vb->DajIndeks()==br_indeksa) x->Ispisi();
                    else test=true;
                }else test=true;
                cout<<endl;
            }
            if(test) cout<<"Nema zaduzenja za tog studenta!\n";
        }
        catch(domain_error x)
        {
            throw x;
        }
    }
};

int main() {
    
    Administracija baza;
    while(true)
    {
        cout<<"\nIzbornik:\n\n\n1. Dodaj studenta\n2. Dodaj laptop\n3. Nadji studenta\n4. Nadji laptop\n5. Izlistaj studente\n6. Izlistaj laptope\n7. Zaduzi laptop\n8. Razduzi laptop\n9. Izlistaj zaduzenja\n10. IZLAZ\n\n\nVas izbor: ";
        int n;
        cin>>n;
        if(n<=0 || n>10) cout<<"Broj koji ste unijeli se ne nalazi u izborniku, molimo pokusajte ponovo!\n";
        else if(n==1)
        {
            cin.ignore(10, '\n');
            int broj_indeksa;
            string godina_studija;
            string ime_i_prezime;
            string adresa;
            string broj_tel;
            cout<<"Unesite ime i prezime novog studenta: ";
            getline(cin, ime_i_prezime);
            cout<<"Unesite adresu novog studenta: ";
            getline(cin, adresa);
            cout<<"Unesite broj telefona novog studenta: ";
            getline(cin, broj_tel);
            cout<<"Unesite clanski(evidencijski) broj novog studenta: ";
            cin>>broj_indeksa;
            try
            {
                baza.RegistrirajNovogStudenta(broj_indeksa, godina_studija, ime_i_prezime, adresa, broj_tel);
            }catch(domain_error x)
            {
                cout<<x.what();
            }
            cout<<"Uspjesno ste dodali novog studenta.\n";
        }
        else if(n==2)
        {
            cin.ignore(10, '\n');
            int ev_broj;
            string naziv;
            string karakteristike;
            cout<<"Unesite naziv: ";
            getline(cin, naziv);
            cout<<"Unesite karakteristike: ";
            getline(cin, karakteristike);
            cout<<"Unesite evidencijski broj laptopa: ";
            cin>>ev_broj;
            try
            {
                baza.RegistrirajNoviLaptop(ev_broj, naziv, karakteristike);
            }catch(domain_error x)
            {
                cout<<x.what();
            }
            cout<<"Uspjesno ste dodali novi laptop!\n";
        }
        else if (n==3)
        {
            cin.ignore(10, '\n');
            cout<<"Unesite broj indeksa studenta: ";
            int br_indeksa;
            cin>>br_indeksa;
            try
            {
                Student nadjen = baza.NadjiStudenta(br_indeksa);
                cout<<"Student sa brojem indeksa "<<br_indeksa<<" je: ";
                nadjen.Ispisi();
            }catch(domain_error x)
            {
                cout<<x.what();
            }

        }
        else if(n==4)
        {
            cin.ignore(10, '\n');
            cout<<"Unesite evidencijski broj laptopa: ";
            int ev_br;
            cin>>ev_br;
            try
            {
                Laptop nadjen = baza.NadjiLaptop(ev_br);
                cout<<"Laptop sa evidencijskim brojem "<<ev_br<<" je: ";
                nadjen.Ispisi();
            }catch(domain_error x)
            {
                cout<<x.what();
            }
        }else if(n==5)
        {
            cout<<"<----------Studenti---------->\n\n";
            baza.IzlistajStudente();
        }else if(n==6)
        {
            cout<<"<----------Laptopi----------->\n\n";
            baza.IzlistajLaptope();
        }
        else if(n==7)
        {
            cout<<"Unesite evidencijski broj laptopa koji se zaduzuje: ";
            int ev_br;
            cin>>ev_br;
            cout<<"Unesite broj indeksa studenta koji zaduzuje laptop: ";
            int br_indeksa;
            cin>>br_indeksa;
            try
            {
                baza.ZaduziLaptop(ev_br, br_indeksa);
            }catch(domain_error x)
            {
                cout<<x.what();
            }
            cout<<"Uspjesno ste zaduzili laptop!\n";
        }
        else if (n==8)
        {
            cout<<"Unesite evidencijski broj laptopa koji se razduzuje: ";
            int ev_br;
            cin>>ev_br;
            try
            {
                baza.RazduziLaptop(ev_br);
            }catch(domain_error x)
            {
                cout<<x.what();
            }
            cout<<"Uspjesno ste razaduzili laptop!\n";

        }
        else if (n==9)
        {
            cout<<"Unesite broj indeksa studenta za kojeg provjeravate zaduzenja: ";
            int br_indeksa;
            cin>>br_indeksa;
            try
            {
                baza.PrikaziZaduzenja(br_indeksa);
            }catch(domain_error x)
            {
                cout<<x.what();
            }
        }
        else if (n==10)
        {
            break;
        }
    }
}
