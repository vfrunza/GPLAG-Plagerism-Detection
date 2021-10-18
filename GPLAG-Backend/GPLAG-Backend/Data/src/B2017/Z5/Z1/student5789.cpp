/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <vector>
#include <stdexcept>
#include <map>

using namespace std;

const vector<string> Godine{ "1", "2", "3", "1/B", "2/B", "3/B", "1/M", "2/M", "1/D", "2/D" , "3/D"};

class Student
{
    int index;
    string ime,godina,adresa,tel;
    
    public:
    Student(int indeks,string ime,string god,string adresa,string tel)
    {
        if(indeks<10000 || indeks>99999) throw domain_error ("Neispravni parametri");
        index=indeks;
        
        int Valja=0;
        for(int i=0;i<Godine.size();i++)
            if(Godine[i]==god) Valja=1;
    
        if(Valja==1) godina=god;
         //  else throw  domain_error ("Neispravni parametri");
        
        Student:: ime=ime;
        Student:: adresa=adresa;
        Student:: tel=tel;
    }
    
    int DajIndeks() const
    { 
        return index;
    }
    
    string DajImePrezime() const
    {
        return ime;
        
    }
    
    string DajGodinuStudija()
    {
        return godina;
    }
    
    string DajAdresu()
    {
        return adresa;
    }
    
    string DajTelefon()
    {
        return tel;
    }
    
    void Ispisi()
    {
        cout<<"Broj indeksa: "<<index<<endl;
        cout<<"Godina studija: "<<godina<<endl;
        cout<<"Ime i prezime: "<<ime<<endl;
        cout<<"Adresa: "<<adresa<<endl;
        cout<<"Telefon: "<<tel<<endl;
    }
};

class Laptop
{
    int ev_broj;
    string naziv,karakteristike;
    Student *kod_koga_je;
    
    public:
    Laptop(int id,string naziv,string karakteristike)
    {   
        if(id<0) throw domain_error("Neispravni parametri");
        ev_broj=id;
        Laptop::naziv=naziv;
        Laptop::karakteristike=karakteristike;
        kod_koga_je=nullptr;
    }
    ~Laptop()
    {
        delete kod_koga_je;
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
    void Zaduzi(const Student &s)
    {
        if(kod_koga_je!=nullptr) throw domain_error("Laptop vec zaduzen");
        kod_koga_je=new Student(s);
    }
    void Razduzi()
    {
        kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzen()
    {
        return kod_koga_je;
    }
    Student &DajKodKogaJe() 
    {   
        if(kod_koga_je==nullptr) throw domain_error("Laptop nije zaduzen");
        return *kod_koga_je;
    }
    Student *DajPokKodKogaJe()
    {
        return kod_koga_je;
    }
    void Ispisi()
    {
        cout<<"Evidencijski broj: "<<ev_broj<<endl;
        cout<<"Naziv: "<<naziv<<endl;
        cout<<"Karakteristike: "<<karakteristike<<endl;
        if(kod_koga_je!=nullptr)
            cout<<"Zaduzio(la): "<<kod_koga_je->DajImePrezime()<<"("<<kod_koga_je->DajIndeks()<<")"<<endl;
        
    }
    
};

class Administracija
{
    map<int,Student*> Studenti;
    map<int,Laptop*> Laptopi;
    
    public:
    Administracija(){};
    Administracija(Administracija &a)
    {
        for(auto b:a.Studenti)
        {
            Studenti[b.first]=new Student(*b.second);
           // delete b.second;
        }
        
        for(auto b:a.Laptopi)
        {
            Laptopi[b.first]=new Laptop(*b.second);
            //delete b.second;
        }
    }
    Administracija(Administracija &&a)
    {
        for(auto b:a.Studenti)
        {
            Studenti[b.first]=b.second;
            b.second=nullptr;
        }
        
        for(auto b:a.Laptopi)
        {
            Laptopi[b.first]=b.second;
            b.second=nullptr;
        }
    }
    Administracija &operator=(Administracija &a)
    {
        if(this!=&a)
        {
            for(auto b:a.Studenti)
            {
                Studenti[b.first]=new Student(*b.second);
               
            }
            
            for(auto b:a.Laptopi)
            {
                Laptopi[b.first]=new Laptop(*b.second);
                
            }
        }
        return *this;
    }
    Administracija &operator=(Administracija &&a)
    {
        if(this!=&a)
        {
            for(auto b:a.Studenti)
            {
                Studenti[b.first]=b.second;
                b.second=nullptr;
            }
            
            for(auto b:a.Laptopi)
            {
                Laptopi[b.first]=b.second;
                b.second=nullptr;
            }
        }
        return *this;
    }
    
    ~Administracija()
    {
        
        for(auto b:Studenti)
        {
            delete b.second;
            b.second=nullptr;
        }
        
        for(auto b:Laptopi)
        {
            delete b.second;
            b.second=nullptr;
        }   
    }
   
    void RegistrirajNovogStudenta(int indeks,string ime,string god,string adresa,string tel)
    {   
        for(auto a:Studenti)
            if(a.first==indeks) throw domain_error("Student s tim indeksom vec postoji");
            
        Studenti[indeks]=new Student(indeks,ime,god,adresa,tel);
    }
    
    void RegistrirajNoviLaptop(int id,string naziv,string karakteristike)
    {
        for(auto a:Laptopi)
            if(a.first==id) throw domain_error("Laptop s tim evidencijskim brojem vec postoji");
        
        Laptopi[id]=new Laptop(id,naziv,karakteristike);
    }
    
    Student &NadjiStudenta(int id)
    {
        for(auto a:Studenti)
            if(a.first==id)
                return *a.second;
        throw domain_error("Student nije nadjen");
    }
    Student NadjiStudenta(int id) const
    {
        for(auto a:Studenti)
            if(a.first==id)
                return *a.second;
        throw domain_error("Student nije nadjen");
    }
    
    Laptop &NadjiLaptop(int id)
    {
        for(auto a:Laptopi)
            if(a.first==id)
                return *a.second;
        throw domain_error("Laptop nije nadjen");
    }
    Laptop NadjiLaptop(int id) const
    {
        for(auto a:Laptopi)
            if(a.first==id)
                return *a.second;
        throw domain_error("Laptop nije nadjen");
    }
    void IzlistajStudente()
    {
        for(auto a:Studenti)
        {
            a.second->Ispisi();
            cout<<endl;
        }
    }
    void IzlistajLaptope()
    {
        for(auto a:Laptopi)
        {
            a.second->Ispisi();
            cout<<endl;
        }
    }
    
    
    void ZaduziLaptop(int sid,int lid)
    {  
        bool ima=0;

        for(auto a:Studenti)
            if(sid==a.first)
                ima=1;
        if(ima==0) throw ("Student nije nadjen");
        ima=0;
        for(auto a:Laptopi)
            if(lid==a.first)
                ima=1;
        //Izuzetak ako je student zaduzio 
        if(ima==0) throw ("Laptop nije nadjen");
        
        if(ima==1 && !Laptopi[lid]->DaLiJeZaduzen())
            Laptopi[lid]->Zaduzi(*Studenti[sid]);
        else 
            throw("Laptop vec zaduzen");
        
        
    }
    
    int NadjiSlobodniLaptop()
    {
        for(auto a:Laptopi)
            if(!a.second->DaLiJeZaduzen())
                return a.first;
                
        throw domain_error("Nema slobodnih laptopa");
    }
    
    void RazduziLaptop(int id)
    {
        bool ima=0;
        for(auto a:Laptopi)
            if(id==a.first)
                ima=1;
        //Izuzetak ako je student zaduzio 
        if(ima==0) throw ("Laptop nije nadjen");
        
        if(ima==1 && Laptopi[id]->DaLiJeZaduzen())
            Laptopi[id]->Razduzi();
        else 
            throw("Laptop nije zaduzen");
        
    }
    void PrikaziZaduzenja()
    {   
        bool ima=0;
        for(auto a:Laptopi)
        {
            if(a.second->DaLiJeZaduzen())
            {   ima=1;
                
                cout<<"Student "<<a.second->DajKodKogaJe().DajImePrezime()
                    <<" ("<<a.second->DajKodKogaJe().DajIndeks()<<") zaduzio/la laptop broj "
                    <<a.first<<endl;
            }
        }
        
        if(ima==0) cout<<"Nema zaduzenja";
    }
    
};

int main ()
{   
    Student s(35124,"Huso Husic Car","3/B","Neka adresa","069/434-072");
    s.Ispisi();
    Laptop l(0,"Acer","Kao nov");
    l.Ispisi();
    
    l.Zaduzi(s);
    cout<<l.DaLiJeZaduzen()<<endl<<endl;
    l.DajKodKogaJe().Ispisi();
    l.Razduzi();
    
    Administracija a;
    Administracija a1(a);
    
    a.RegistrirajNoviLaptop(1,"HP","Smece");
    a.RegistrirajNovogStudenta(18000,"Hello","1/B","negdje","061/111-000");
    
    cout<<"Laptopi: "<<endl;
    a.IzlistajLaptope();
    cout<<"Studenti: "<<endl;
    a.IzlistajStudente();
    
    a.ZaduziLaptop(18000,1);
    cout<<"Zaduzenja: ";
    a.PrikaziZaduzenja();
	return 0;
}
