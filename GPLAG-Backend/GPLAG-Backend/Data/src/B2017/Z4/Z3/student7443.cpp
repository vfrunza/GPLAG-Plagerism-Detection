/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <new>
#include <cstring>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <string>
class Datum
{
    int dan,mjesec,godina;
public:
    Datum(int d=0, int m=0,int g=0) {
        Postavi(d,m,g);
    }
    void Postavi(int d, int m,int g);
    std::tuple<int,int,int> Ocitaj()const;
    void Ispisi() const;
};
void Datum::Postavi(int d, int m, int g)
{
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(g%4==0 && g%100!=0 || g%400==0) broj_dana[1]++;
    if(g<1 || d<1 || m<1 || m>12 || d<broj_dana[m-1]) throw std::domain_error("Neispravan datum");
    dan=d;
    mjesec=m;
    godina=g;
}
std::tuple<int,int,int> Datum::Ocitaj() const
{

    std::tuple<int,int,int> datum;

    datum=std::make_tuple(dan, mjesec, godina);

    return datum;

}
void Datum::Ispisi() const
{
    std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
}

class Vrijeme
{
    int sati,minute;
public:
    Vrijeme(int h=0, int m=0) {
        Postavi(h,m);
    }
    void Postavi(int h, int m);
    std::pair<int,int>  Ocitaj() const;
    void Ispisi() const;
};

void Vrijeme::Postavi(int h, int min)
{
    if((h<0 || h>23) || (min<0 || min>59)) throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati=h;
    Vrijeme::minute=min;
}
std::pair<int,int> Vrijeme::Ocitaj()const
{
    std::pair<int,int> vrijeme;

    vrijeme= std::make_pair(sati, minute);
    return vrijeme;
}
void Vrijeme::Ispisi() const
{
    if(sati<10)
        std::cout<<"0"<<sati<<":";
    else std::cout<<sati<<":";
    if(minute<10)
        std::cout<<"0"<<minute<<":";
    else std::cout<<minute;
}

class Pregled
{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
   
public:
    Pregled(const std::string &ime, const Datum &datum, const Vrijeme &vrijeme);
    Pregled(const std::string &ime, int dan, int mjesec, int godina,int sati,int minute);// {
    //  Postavi(ime,dan,mjesec,godina,sati,minute);}

    void PromijeniPacijenta( const std::string &ime) {
        ime_pacijenta=ime;
    }

    void PromijeniDatum(const Datum &novi_datum) {

        datum_pregleda = novi_datum;
    }

    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        vrijeme_pregleda=novo_vrijeme;

    }

    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();

    std::string DajImePacijenta() const {
        return ime_pacijenta;
    }
    Datum DajDatumPregleda()const {
        return datum_pregleda;
    }
    Vrijeme DajVrijemePregleda() const {
        return vrijeme_pregleda;
    }

    void Ispisi() const;

static  bool DolaziPrije(const Pregled &p1, const Pregled &p2)
{
    if(std::get<2>(p1.datum_pregleda.Ocitaj())<std::get<2>(p2.datum_pregleda.Ocitaj())) return true;
    else if(std::get<2>(p1.datum_pregleda.Ocitaj())>std::get<2>(p2.datum_pregleda.Ocitaj())) return false;
    else {
        if(std::get<1> (p1.datum_pregleda.Ocitaj()) <std::get<1> (p2.datum_pregleda.Ocitaj())) return true;
         else if(std::get<1>(p1.datum_pregleda.Ocitaj())>std::get<1>(p2.datum_pregleda.Ocitaj())) return false;
        else {
            if(std::get<0>(p1.datum_pregleda.Ocitaj())<std::get<0>(p2.datum_pregleda.Ocitaj())) return true;
           else if(std::get<0>(p1.datum_pregleda.Ocitaj())>std::get<0>(p2.datum_pregleda.Ocitaj())) return true;
            else {
                
                if(p1.vrijeme_pregleda.Ocitaj().first<p2.vrijeme_pregleda.Ocitaj().first) return true;
                else if(p1.vrijeme_pregleda.Ocitaj().first>p2.vrijeme_pregleda.Ocitaj().first) return true;
                else {
                    if(p1.vrijeme_pregleda.Ocitaj().second < p2.vrijeme_pregleda.Ocitaj().second) return true;
                    else  return false;
                 
                }
            }
        }
    }
    return false;

}
};
Pregled::Pregled(const std::string &ime, const Datum &datum, const Vrijeme &vrijeme)
{
    Pregled::ime_pacijenta=ime;
    Pregled::datum_pregleda=datum;
    Pregled::vrijeme_pregleda=vrijeme;

}

Pregled::Pregled(const  std::string &ime, int dan, int mjesec, int godina,int sati,int minute) :
    datum_pregleda(Datum(dan,mjesec,godina)), vrijeme_pregleda(Vrijeme(sati,minute))
{
    Pregled::ime_pacijenta=ime;


}

void Pregled::PomjeriDanUnaprijed()
{
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};

    int dan=std::get<0>(datum_pregleda.Ocitaj());
    int mjesec=std::get<1>(datum_pregleda.Ocitaj());
    int godina=std::get<2>(datum_pregleda.Ocitaj());
    // a=datum_pregleda.Ocitaj();
    if(godina%4==0 && godina%100!=0 ||godina%400==0) broj_dana[1]++;
    if(dan==broj_dana[mjesec-1]) {
        dan=1;
        if(mjesec==12) {
            mjesec=1;
            godina++;
        } else mjesec++;
    }
    datum_pregleda.Postavi(dan,mjesec,godina);
}

void Pregled::PomjeriDanUnazad()
{

    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    int dan=std::get<0>(datum_pregleda.Ocitaj());
    int mjesec=std::get<1>(datum_pregleda.Ocitaj());
    int godina=std::get<2>(datum_pregleda.Ocitaj());
    if(godina%4==0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
    if(dan==1) {
        if(mjesec==1) {
            mjesec=12;
            godina--;
            if(godina%4==0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
            dan=broj_dana[mjesec];
        } else {

            mjesec--;
            broj_dana[mjesec-1];
        }
    } else  dan--;
    datum_pregleda.Postavi(dan,mjesec,godina);
}


void Pregled::Ispisi() const
{
    std::cout<<std::left<<std::setw(30)<<DajImePacijenta()<<" ";
    DajDatumPregleda().Ispisi();
    std::cout<<" ";
    DajVrijemePregleda().Ispisi();
    std::cout<<std::endl;
}

class Pregledi
{
    int broj_pregleda;
    const int max_broj_pregleda;
    Pregled **spisak;
public:
    explicit Pregledi(int max_pregleda);
    Pregledi (std::initializer_list<Pregled> lista_pregleda);

    ~Pregledi() {
        for(int i=0; i<broj_pregleda; i++)
            delete spisak[i];
        delete[] spisak;
    }

    Pregledi(const Pregledi &p);
    Pregledi (Pregledi &&p);
    Pregledi &operator= (const Pregledi &p);
    Pregledi &operator=(Pregledi &&p);
    void RegistrirajPregled( const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled( const std::string &ime_pacijenta,  int dan_pregleda, int mjese_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const;
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IspraznijiKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledNaDatum(const Datum &datum) const;
    void IspisiSvePreglede()const;

};

Pregledi::Pregledi(int max_pregleda): max_broj_pregleda(max_pregleda), broj_pregleda(0), spisak(new Pregled*[max_pregleda] {}) {}

Pregledi::Pregledi (std::initializer_list<Pregled> lista_pregleda): max_broj_pregleda(lista_pregleda.size()), broj_pregleda(lista_pregleda.size())
{
    spisak=new Pregled*[lista_pregleda.size()] {};
    int brojac=0;
    try {
        for(auto x:lista_pregleda) spisak[brojac++] = new Pregled(x);
    } catch(...) {
        for(int i=0; i<brojac; i++) delete spisak[i];
        throw;

    }

}

Pregledi::Pregledi(const Pregledi &p) : spisak(new Pregled*[p.max_broj_pregleda]),
    max_broj_pregleda(p.max_broj_pregleda), broj_pregleda(p.broj_pregleda)
{
    for(int i=0; i<p.broj_pregleda; i++) {
        spisak[i]=new Pregled(*p.spisak[i]);
    }
}
Pregledi::Pregledi (Pregledi &&p) : spisak(p.spisak),max_broj_pregleda(p.max_broj_pregleda),broj_pregleda(p.broj_pregleda)
{
    p.spisak=nullptr;
    p.broj_pregleda=0;
}

Pregledi &Pregledi::operator= (const Pregledi &p)
{

    if(p.max_broj_pregleda!=max_broj_pregleda) throw std::logic_error("Dosrignut maksimalni broj pregleda");//komentaaar
    if(p.broj_pregleda>broj_pregleda)
        for(int i=0; i<broj_pregleda; i++) {
            *spisak[i]=*p.spisak[i];
            for(int i=broj_pregleda; i<p.broj_pregleda; i++)
                spisak[i]=new Pregled(*p.spisak[i]);
        }
    else {
        for(int i=0; i<p.broj_pregleda; i++)
            *spisak[i]=*p.spisak[i];
        for(int i=p.broj_pregleda; i<broj_pregleda; i++)
            delete spisak[i];
    }
    broj_pregleda=p.broj_pregleda;
    return *this;

}

Pregledi &Pregledi::operator=(Pregledi &&p)
{
    if(p.max_broj_pregleda!=max_broj_pregleda) throw;            //   mozda treba izuzetak----------------- Da treba kolegice :)
    if(&p!=this) {
        for(int i=0; i<broj_pregleda; i++) delete spisak[i];
        spisak=p.spisak;
        broj_pregleda=p.broj_pregleda;
        p.spisak=nullptr;
        p.broj_pregleda=0;
    }
    return *this;
}

void Pregledi::RegistrirajPregled( const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    if(broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    else
        spisak[broj_pregleda++]=new Pregled(Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda));
        
    std::sort(spisak,spisak+broj_pregleda,[](Pregled *p1,Pregled *p2){
       return  Pregled::DolaziPrije(*p1,*p2);
    });

}

void Pregledi::RegistrirajPregled( const std::string &ime_pacijenta,  int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
{
    if(broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    spisak[broj_pregleda++]=new Pregled(Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda, godina_pregleda, sati_pregleda,minute_pregleda));
    
    
    std::sort(spisak,spisak+broj_pregleda,[](Pregled *p1,Pregled *p2){
       return  Pregled::DolaziPrije(*p1,*p2);
    });
}

void Pregledi::RegistrirajPregled(Pregled *pregled)
{

    if(broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");

    spisak[broj_pregleda++]=pregled;
    pregled=nullptr;
    
    std::sort(spisak,spisak+broj_pregleda,[](Pregled *p1,Pregled *p2){
        return Pregled::DolaziPrije(*p1,*p2);
    });
}

int Pregledi::DajBrojPregleda() const
{
    return broj_pregleda;
}
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    int broj;

    broj=std::count_if(spisak, spisak+broj_pregleda, [datum](Pregled *p) {
        std::tuple<int,int,int> a,b;

        a=p->DajDatumPregleda().Ocitaj(); //prvi element niza  je objekat tipa pregled koji ima clanicu daj datum pregleda rezultat datum ++
        b=datum.Ocitaj();
        if(std::get<0>(a)==std::get<0>(b) && std::get<1>(a)==std::get<1>(b) && std::get<2>(a)==std::get<2>(b)) return true;
        return false;
    });
    return broj;
}

Pregled &Pregledi::DajNajranijiPregled()
{
    if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
   
   auto a = std::min_element (spisak,spisak+broj_pregleda,[](Pregled *p1, Pregled *p2) {
        Pregled p11(*p1);
        Pregled p22(*p2);
        return Pregled::DolaziPrije(p11,p22);
    });
    return **a;
}

//ispravi i ovu metodu ko onu gore sve isto

Pregled Pregledi::DajNajranijiPregled() const
{
    if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");

    auto a=std::min_element (spisak,spisak+broj_pregleda,[](Pregled *p1, Pregled *p2) {
        Pregled p11(*p1);
        Pregled p22(*p2);
        return Pregled::DolaziPrije(p11,p22);
    });

    return **a;

}
void Pregledi::IspraznijiKolekciju()
{
    for(int i=0; i<broj_pregleda; i++) delete  spisak[i];
    delete[] spisak;
    broj_pregleda=0;
    spisak=nullptr;
}


void Pregledi::ObrisiNajranijiPregled()
{
    if(broj_pregleda==0) throw std::range_error("Prazna kolekcija");  
    for(int i=0; i<broj_pregleda; i++) {
        if(std::get<0>(spisak[i]->DajDatumPregleda().Ocitaj()) == std::get<0>(DajNajranijiPregled().DajDatumPregleda().Ocitaj()) &&
                std::get<1>(spisak[i]->DajDatumPregleda().Ocitaj()) ==std::get<1>(DajNajranijiPregled().DajDatumPregleda().Ocitaj()) &&
                std::get<2>(spisak[i]->DajDatumPregleda().Ocitaj()) ==std::get<2>(DajNajranijiPregled().DajDatumPregleda().Ocitaj()) &&
                spisak [i]->DajVrijemePregleda().Ocitaj().first==DajNajranijiPregled().DajVrijemePregleda().Ocitaj().first &&
                spisak[i]->DajVrijemePregleda().Ocitaj().second == DajNajranijiPregled().DajVrijemePregleda().Ocitaj().second) {
            delete spisak[i];
            spisak[i]=nullptr;
            for(int k=i; i<=broj_pregleda-1; i++) {
                spisak[k]=spisak[k+1];
            }
            broj_pregleda--;
        }
    }
    std::sort(spisak, spisak+broj_pregleda, [](Pregled *p1, Pregled *p2){
       return  Pregled::DolaziPrije(*p1,*p2);
    });
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) 
{
    for(int i=0; i<broj_pregleda; i++) {
        if(spisak[i]->DajImePacijenta()==ime_pacijenta) {
            
            delete spisak[i];
            spisak[i]=nullptr;
            for(int k=i; k!=broj_pregleda-1; k++) {
                spisak[k]=spisak[k+1];
            }
            broj_pregleda--;

        }
    }
    std::sort(spisak,spisak+broj_pregleda,[](Pregled *p1,Pregled *p2){
        return Pregled::DolaziPrije(*p1,*p2);
    });
}

void Pregledi::IspisiPregledNaDatum(const Datum &datum) const  {
    for(int i=0; i<broj_pregleda; i++) {
        int dan = std::get<0>(spisak[i]->DajDatumPregleda().Ocitaj());
        int mjesec =  std::get<1>(spisak[i]->DajDatumPregleda().Ocitaj());
        int godina = std::get<2>(spisak[i]->DajDatumPregleda().Ocitaj());
        if(dan==std::get<0>(datum.Ocitaj()) && mjesec==std::get<1>(datum.Ocitaj()) && godina==std::get<2>(datum.Ocitaj())) {
        spisak[i]->Ispisi();
        }
    }
}


void Pregledi::IspisiSvePreglede()const
{
    for(int i=0; i<broj_pregleda; i++) {

        spisak[i]->Ispisi();
    }

}
int main ()
{
  
    int max_pregleda;
    std::cout<<"Unesite maksimalan broj pregleda ";
    std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
    std::cout<<" Unesite dan mjesec i godinu pregleda: " <<"Unesite sate i minute pregleda: "<< "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: "<<"Unesite dan mjesec i godinu pregleda: "<<"Unesite sate i minute pregleda: Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: "<<"Trenutno su registrovani sljedeci pregledi "

    return 0;
}