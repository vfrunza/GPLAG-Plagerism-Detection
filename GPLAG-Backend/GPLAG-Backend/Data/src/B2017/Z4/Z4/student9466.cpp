/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include<tuple>
#include<stdexcept>
#include<iomanip>
#include<algorithm>
#include<memory>
#include<vector>
class Datum
{
    int dan;
    int mjesec;
    int godina;
public:
    Datum(int d, int m, int g) {
        dan=d;
        mjesec=m;
        godina=g;
    }
    void Postavi(int d, int m, int g) {
        dan=d;
        mjesec=m;
        godina=g;
    }
    std::tuple<int, int, int> Ocitaj() const {
        std::tuple<int,int,int> t(dan,mjesec,godina);
        return t;
    }
    void Ispisi() const {
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
    int DajDan()const {
        return dan;
    }
    int DajMjesec()const {
        return mjesec;
    }
    int DajGodinu()const {
        return godina;
    }
    void PomjeriDanUnaprijed() {
        dan++;
    }
    void PomjeriDanUnazad() {
        dan--;
    }
};
class Vrijeme
{
    int sati;
    int minute;
public:
    Vrijeme(int s, int m) {
        sati=s;
        minute=m;
    }
    void Postavi(int s, int m) {
        if(s<0 or s>23 or m<0 or m>59) throw std::domain_error("Neispravno vrijeme");
        sati=s;
        minute=m;
    }
    std::pair<int, int> Ocitaj () const {
        std::pair<int, int> p(sati,minute);
        return p;
    }
    void Ispisi() const {
        if(sati<10) std::cout<<0;
        std::cout<<sati<<":";
        if(minute<10) std::cout<<0;
        std::cout<<minute;
    }
    int DajSate(){
        return sati;
    }
    int DajMinute(){
        return minute;
    }
    
};
class Pregled
{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;

public:

    Pregled(const std::string &ime, const Datum &datum,const Vrijeme &vrijeme): datum_pregleda(datum), vrijeme_pregleda(vrijeme) {
        ime_pacijenta=ime;

    }
    Pregled(const std::string &ime, int dan_pregleda, int mjesec_pregleda,int godina_pregleda, int sati_pregleda, int minute_pregleda): datum_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda), vrijeme_pregleda(sati_pregleda,minute_pregleda) {
        ime_pacijenta=ime;
    }
    void PromijeniPacijenta(const std::string &ime) {
        ime_pacijenta=ime;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        datum_pregleda=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        vrijeme_pregleda=novo_vrijeme;
    }
    void PomjeriDanUnaprijed() {
        datum_pregleda.PomjeriDanUnaprijed();
    }
    void PomjeriDanUnazad() {
        datum_pregleda.PomjeriDanUnazad();
    }
    std::string DajImePacijenta() const {
        return ime_pacijenta;
    }
    Datum DajDatumPregleda() const {
        return datum_pregleda;
    }
    Vrijeme DajVrijemePregleda() const {
        return vrijeme_pregleda;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const {
        int i=0;
        for( ; i<ime_pacijenta.size(); i++) {
            std::cout<<ime_pacijenta[i];

        }
        for( ; i<30; i++) {
            std::cout<<" ";
        }
        datum_pregleda.Ispisi();
        std::cout<<" ";
        vrijeme_pregleda.Ispisi();

        std::cout<<std::endl;
    }
};
class Pregledi
{
    int br_kreiranih;
   std::vector<std::shared_ptr<Pregled>> pok;
public:
    explicit Pregledi() {
        
        br_kreiranih=0;
       
    }
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
  
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        
        pok.push_back(std::make_shared<Pregled>(ime_pacijenta,datum_pregleda,vrijeme_pregleda));
        br_kreiranih++;

    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda, int godina_pregleda, int sati_pregleda,int minute_pregleda) {
        
        pok.push_back(std::make_shared<Pregled>(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda));

        br_kreiranih++;
    }
    void RegistrirajPregled( std::shared_ptr<Pregled> pregled) {
        
        pok.push_back(std::make_shared<Pregled>(*pregled));

        br_kreiranih++;
    }
    int DajBrojPregleda() const {
        return br_kreiranih;
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const {
        int k=0;
        for(int i=0; i<br_kreiranih; i++) {
            if((*pok[i]).DajDatumPregleda().DajGodinu()==datum.DajGodinu() and (*pok[i]).DajDatumPregleda().DajMjesec()==datum.DajMjesec() and (*pok[i]).DajDatumPregleda().DajDan()==datum.DajDan()) {
                k++;
            }
        }
        return k;

    }
    Pregled &DajNajranijiPregled(){
        if(br_kreiranih==0) throw std::domain_error("Nema registriranih pregleda");
       return **std::min_element(pok.begin(),pok.end(),[](std::shared_ptr<Pregled> a, std::shared_ptr<Pregled> b){
            if(a->DajDatumPregleda().DajGodinu()==b->DajDatumPregleda().DajGodinu()){
            if((a->DajDatumPregleda().DajMjesec()==b->DajDatumPregleda().DajMjesec())){
                if(a->DajDatumPregleda().DajDan()==b->DajDatumPregleda().DajDan()){
            if(a->DajVrijemePregleda().DajSate()==b->DajVrijemePregleda().DajSate()) return a->DajVrijemePregleda().DajMinute()<b->DajVrijemePregleda().DajMinute();
            return a->DajVrijemePregleda().DajSate()<b->DajVrijemePregleda().DajSate();
                }
                else return a->DajDatumPregleda().DajDan()<b->DajDatumPregleda().DajDan();
            }
                else return ((a->DajDatumPregleda().DajMjesec()<b->DajDatumPregleda().DajMjesec()));
            } else 
            return (a->DajDatumPregleda().DajGodinu()<b->DajDatumPregleda().DajGodinu());
        });
    }
    Pregled DajNajranijiPregled() const{
        if(br_kreiranih==0) throw std::domain_error("Nema registriranih pregleda");
       return **std::min_element(pok.begin(),pok.end(),[](std::shared_ptr<Pregled> a, std::shared_ptr<Pregled> b){
            if(a->DajDatumPregleda().DajGodinu()==b->DajDatumPregleda().DajGodinu()){
            if((a->DajDatumPregleda().DajMjesec()==b->DajDatumPregleda().DajMjesec())){
                if(a->DajDatumPregleda().DajDan()==b->DajDatumPregleda().DajDan()){
            if(a->DajVrijemePregleda().DajSate()==b->DajVrijemePregleda().DajSate()) return a->DajVrijemePregleda().DajMinute()<b->DajVrijemePregleda().DajMinute();
            return a->DajVrijemePregleda().DajSate()<b->DajVrijemePregleda().DajSate();
                }
                else return a->DajDatumPregleda().DajDan()<b->DajDatumPregleda().DajDan();
            }
                else return ((a->DajDatumPregleda().DajMjesec()<b->DajDatumPregleda().DajMjesec()));
            } else 
            return (a->DajDatumPregleda().DajGodinu()<b->DajDatumPregleda().DajGodinu());
        });
       
    }
    void IsprazniKolekciju() {
        for(int i=0; i<br_kreiranih; i++) {
            //delete pok[i];
            pok[i]=nullptr;
        }
        br_kreiranih=0;
    }
    void ObrisiNajranijiPregled(){
        std::shared_ptr<Pregled> p=*std::min_element(pok.begin(),pok.end(),[](std::shared_ptr<Pregled> a, std::shared_ptr<Pregled> b){
            if(a->DajDatumPregleda().DajGodinu()==b->DajDatumPregleda().DajGodinu()){
            if((a->DajDatumPregleda().DajMjesec()==b->DajDatumPregleda().DajMjesec())){
                if(a->DajDatumPregleda().DajDan()==b->DajDatumPregleda().DajDan()){
            if(a->DajVrijemePregleda().DajSate()==b->DajVrijemePregleda().DajSate()) return a->DajVrijemePregleda().DajMinute()<b->DajVrijemePregleda().DajMinute();
            return a->DajVrijemePregleda().DajSate()<b->DajVrijemePregleda().DajSate();
                }
                else return a->DajDatumPregleda().DajDan()<b->DajDatumPregleda().DajDan();
            }
                else return ((a->DajDatumPregleda().DajMjesec()<b->DajDatumPregleda().DajMjesec()));
            } else 
            return (a->DajDatumPregleda().DajGodinu()<b->DajDatumPregleda().DajGodinu());
        });
        for(int i=0;i<br_kreiranih;i++)
        {
            if(p==pok[i]) {
                 //delete pok[i];
                 br_kreiranih--;
                pok[i]=nullptr;
                for(int j=i; j<br_kreiranih; j++) {
                     std::shared_ptr<Pregled> temp=pok[j];
                    pok[j]=pok[j+1];
                    pok[j+1]=temp;
                }
            }
                
            }
        }
        
    
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
        for(int i=0; i<br_kreiranih; i++) {
            if((*pok[i]).DajImePacijenta().compare(ime_pacijenta)==0) {
               // delete pok[i];
                br_kreiranih--;
                pok[i]=nullptr;
                for(int j=i; j<br_kreiranih; j++) {
                     std::shared_ptr<Pregled> temp=pok[j];
                    pok[j]=pok[j+1];
                    pok[j+1]=temp;
                }
            }
        }
    }
    void IspisiPregledeNaDatum(const Datum &datum) const {
        std::sort(pok.begin(),pok.end(),[](std::shared_ptr<Pregled> a, std::shared_ptr<Pregled> b){
            if(a->DajDatumPregleda().DajGodinu()==b->DajDatumPregleda().DajGodinu()){
            if((a->DajDatumPregleda().DajMjesec()==b->DajDatumPregleda().DajMjesec())){
                if(a->DajDatumPregleda().DajDan()==b->DajDatumPregleda().DajDan()){
            if(a->DajVrijemePregleda().DajSate()==b->DajVrijemePregleda().DajSate()) return a->DajVrijemePregleda().DajMinute()<b->DajVrijemePregleda().DajMinute();
            return a->DajVrijemePregleda().DajSate()<b->DajVrijemePregleda().DajSate();
                }
                else return a->DajDatumPregleda().DajDan()<b->DajDatumPregleda().DajDan();
            }
                else return ((a->DajDatumPregleda().DajMjesec()<b->DajDatumPregleda().DajMjesec()));
            } else 
            return (a->DajDatumPregleda().DajGodinu()<b->DajDatumPregleda().DajGodinu());
        });
        for(int i=0; i<br_kreiranih; i++) {
            if((*pok[i]).DajDatumPregleda().DajGodinu()==datum.DajGodinu() and (*pok[i]).DajDatumPregleda().DajMjesec()==datum.DajMjesec() and (*pok[i]).DajDatumPregleda().DajDan()==datum.DajDan()) {
                (*pok[i]).Ispisi();
            }
        }
    }

    void IspisiSvePreglede() const {
        std::sort(pok.begin(),pok.end(),[](std::shared_ptr<Pregled> a, std::shared_ptr<Pregled> b){
            if(a->DajDatumPregleda().DajGodinu()==b->DajDatumPregleda().DajGodinu()){
            if((a->DajDatumPregleda().DajMjesec()==b->DajDatumPregleda().DajMjesec())){
                if(a->DajDatumPregleda().DajDan()==b->DajDatumPregleda().DajDan()){
            if(a->DajVrijemePregleda().DajSate()==b->DajVrijemePregleda().DajSate()) return a->DajVrijemePregleda().DajMinute()<b->DajVrijemePregleda().DajMinute();
            return a->DajVrijemePregleda().DajSate()<b->DajVrijemePregleda().DajSate();
                }
                else return a->DajDatumPregleda().DajDan()<b->DajDatumPregleda().DajDan();
            }
                else return ((a->DajDatumPregleda().DajMjesec()<b->DajDatumPregleda().DajMjesec()));
            } else 
            return (a->DajDatumPregleda().DajGodinu()<b->DajDatumPregleda().DajGodinu());
        });
        for(int i=0; i<br_kreiranih; i++) {
            (*pok[i]).Ispisi();

        }

    }
};
int main ()
{
    Pregledi pregledi();
    std::string kraj="kraj";
    do {
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::string prostor;
        std::getline(std::cin,prostor);
        if(prostor.compare(kraj)==0) break;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        int dan,mjesec,godina,sati,minute;
        std::cin>>dan;
        std::cin >> mjesec;
        std::cin>>godina;
        std::cout<<"Unesite sate i minute pregleda: ";
        std::cin>>sati;
        std::cin>>minute;
        pregledi.RegistrirajPregled(prostor,dan,mjesec,godina,sati,minute);
        
    } while();
    std::cout<<"Trenutno su registrovani sljedeci pregledi\n";
    pregledi.IspisiSvePreglede();
    int n;
    do{
    std::cout<<"\nOdaberite jednu od sljedecih opcija\n1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n4 - Obrisi najraniji pregled\n5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa\n";
    /*Odaberite jednu od sljedecih opcija
    1 - Broj pregleda na datum
    2 - Najraniji pregled
    3 - Obrisi pregled pacijenta
    4 - Obrisi najraniji pregled
    5 - Ispisi sve pregleda na datum
    6 - Ispisi sve preglede
    7 - Kraj programa*/
    
    std::cin>>n;
    switch(n) {
    case 1: {
        //Unesite dan mjesec i godinu : Broj pregleda na datum 31 5 2018 je: 1
        std::cout<<"Unesite dan mjesec i godinu : ";
        int d,m,g;
        std::cin>>d>>m>>g;
        Datum dat(d,m,g);
        std::cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<pregledi.DajBrojPregledaNaDatum(dat);
        break;
    }
    case 2: {
        std::cout<<"Najraniji pregled je:\n";
        pregledi.DajNajranijiPregled().Ispisi();
        break;
    }
    case 3: {
        std::string pac;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::getline(std::cin,pac);
        int u=pregledi.DajBrojPregleda();
        pregledi.ObrisiPregledePacijenta(pac);
        std::cout<<"Unesite ime pacijenta: Uspjesno obrisano "<<u-pregledi.DajBrojPregleda()<<" pregleda";
        break;
    }
    case 4: {
        pregledi.ObrisiNajranijiPregled();
        std::cout<<"Najraniji pregled uspjesno obrisan";
        break;
    }
    case 5: {
        std::cout<<"Unesite dan mjesec i godinu : ";
        int d,m,g;
        std::cin>>d>>m>>g;
        Datum dat(d,m,g);
        std::cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su:\n";
        pregledi.IspisiPregledeNaDatum(dat);
        break;
    }
    case 6: {
        pregledi.IspisiSvePreglede();
        break;
    }
    case 7: {
        break;
    }
    }
    }while(n!=7);
    return 0;
}
