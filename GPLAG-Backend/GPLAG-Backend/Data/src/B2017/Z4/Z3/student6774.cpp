#include <iostream>
#include<stdexcept>
#include<tuple>
#include<utility>
#include<algorithm>

int BrojDana(int mjesec, int godina) {
int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
broj_dana[1]++;
return broj_dana[mjesec - 1];
}
class Datum {
int dan,mjesec,godina;
public:
Datum(){
    dan=0;mjesec=0;godina=0;
}
Datum(int dan, int mjesec, int godina){
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12|| dan > BrojDana(mjesec, godina))
    throw std::domain_error("Neispravan datum!");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}
void Postavi(){
    dan=0;mjesec=0;godina=0;
}
friend class Pregledi;
    Datum(const Datum &d){
    dan=d.dan;mjesec=d.mjesec;godina=d.godina;
    }
void Postavi(const Datum &d){
dan=d.dan;mjesec=d.mjesec;godina=d.godina;
}

friend class Pregled;
void Postavi(int dan, int mjesec, int godina) {
if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12|| dan > BrojDana(mjesec, godina))
throw std::domain_error("Neispravan datum!");
Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}
std::tuple<int, int, int> Ocitaj() const{return std::make_tuple(dan,mjesec,godina);}
void Ispisi() const{std::cout << dan<<"/"<<mjesec<<"/"<<godina ;}
};


class Vrijeme{
int h,m;
public:
Vrijeme(){
h=0;m=0;
}
friend class Pregled;
void Postavi(const Vrijeme &c){
h=c.h;m=c.m;
}
Vrijeme(int sati, int minute){
if(sati<0||sati>23||minute<0||minute>59)throw std::domain_error("Neispravno vrijeme");
h=sati;m=minute;
}
void Postavi(int sati, int minute){ 
if(sati<0||sati>23||minute<0||minute>59)throw std::domain_error("Neispravno vrijeme");
h=sati;m=minute;
}
void Postavi(){
h=0;m=0;
}
std::pair<int, int> Ocitaj () const{
    return std::make_pair(h,m);
}
  void Ispisi()const {
         if(h>9)std::cout <<  h<<":";
    else std::cout << "0"<<h<<":";
    if(m>9)std::cout <<  m;
    else std::cout << "0"<<m;
    }
friend     class Pregledi;
};
class Pregled{
    std::string ime;
    Datum dat;
    Vrijeme vr;
    public:
    Pregled(){
       ime="";dat=Datum();vr=Vrijeme(); 
    }
    friend class Pregledi;
  Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
 const Vrijeme &vrijeme_pregleda){
     ime=ime_pacijenta;dat=datum_pregleda;vr=vrijeme_pregleda;
 }
Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
 int godina_pregleda, int sati_pregleda, int minute_pregleda){
     ime=ime_pacijenta;dat=Datum(dan_pregleda,mjesec_pregleda,godina_pregleda);vr=Vrijeme(sati_pregleda,minute_pregleda);
 }
void PromijeniPacijenta(const std::string &ime_pacijenta){
    ime=ime_pacijenta;
}
void PromijeniDatum(const Datum &novi_datum){
    dat=novi_datum;
}
void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
    vr=novo_vrijeme;
}
void PomjeriDanUnaprijed(){
    if(dat.dan==BrojDana(dat.mjesec,dat.godina)){dat.dan=1;if(dat.mjesec==12){dat.mjesec=1;dat.godina++;}else dat.mjesec++;}else dat.dan++;
}
void PomjeriDanUnazad(){
    if(dat.dan==1){if(dat.mjesec==1){dat.mjesec=12;dat.godina--;}else dat.mjesec--;dat.dan=BrojDana(dat.mjesec,dat.godina);}else dat.dan--;
}
std::string DajImePacijenta() const{return ime;}
Datum DajDatumPregleda() const{return dat;}
Vrijeme DajVrijemePregleda() const{return vr;}
static bool DolaziPrije(const Pregled &p1, const Pregled &p2){
    if(p1.dat.godina<p2.dat.godina)return true;if(p1.dat.godina>p2.dat.godina)return false;
    if(p1.dat.mjesec<p2.dat.mjesec)return true;if(p1.dat.mjesec>p2.dat.mjesec)return false;
    if(p1.dat.dan<p2.dat.dan)return true;if(p1.dat.dan>p2.dat.dan)return false;
    if(p1.vr.h<p2.vr.h)return true;if(p1.vr.h>p2.vr.h)return false;
    if(p1.vr.m<p2.vr.m)return true;if(p1.vr.m>p2.vr.m)return false;
    return false;
}
void Ispisi() const{
for(int i=0;i<30;i++){
    if(i<ime.size())std::cout << ime[i] ;
    else std::cout << " " ;
}dat.Ispisi(); std::cout<<" ";vr.Ispisi();std::cout <<   std::endl;
}
};
class Pregledi{
    Pregled **p;
    int broj_pregleda=0;
    int max;
    public:
  explicit Pregledi(int max_broj_pregleda){
      max=max_broj_pregleda;
      broj_pregleda=0;
  }
Pregledi(std::initializer_list<Pregled> spisak_pregleda){
     max=broj_pregleda=spisak_pregleda.size();
     auto it(spisak_pregleda.begin());
     for(int i=0;i<broj_pregleda;i++){
          p[i]=new Pregled(it->ime,it->dat,it->vr);
          it++;
      }
     
}
~Pregledi(){
    for(int i=0;i<broj_pregleda;i++){
        delete p[i];
    }
}
Pregledi(const Pregledi &pregledi){
    max=broj_pregleda=pregledi.broj_pregleda;
    for(int i=0;i<broj_pregleda;i++){
        p[i]=new Pregled(pregledi.p[i]->ime,pregledi.p[i]->dat,pregledi.p[i]->vr);
    }
}
Pregledi(Pregledi &&pregledi){
     max=broj_pregleda=pregledi.broj_pregleda;
    for(int i=0;i<broj_pregleda;i++){
        p[i]=new Pregled(pregledi.p[i]->ime,pregledi.p[i]->dat,pregledi.p[i]->vr);
    }
}
Pregledi &operator =(const Pregledi &pregledi){
     max=broj_pregleda=pregledi.broj_pregleda;
    for(int i=0;i<broj_pregleda;i++){
        p[i]=new Pregled(pregledi.p[i]->ime,pregledi.p[i]->dat,pregledi.p[i]->vr);
    }
}
Pregledi &operator =(Pregledi &&pregledi){
    max= broj_pregleda=pregledi.broj_pregleda;
    for(int i=0;i<broj_pregleda;i++){
        p[i]=new Pregled(pregledi.p[i]->ime,pregledi.p[i]->dat,pregledi.p[i]->vr);
    }
}
void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
    if(broj_pregleda==max)throw std::range_error{"Dostignut maksimalni broj pregleda"};
    p[broj_pregleda]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
   
    broj_pregleda++;
    
}
void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda,int minute_pregleda){
     if(broj_pregleda==max)throw std::range_error{"Dostignut maksimalni broj pregleda"};
      p[broj_pregleda]=new Pregled(ime_pacijenta,Datum(dan_pregleda,mjesec_pregleda,godina_pregleda),Vrijeme(sati_pregleda,minute_pregleda));
    broj_pregleda++;
}
void RegistrirajPregled(Pregled *pregled){
     if(broj_pregleda==max)throw std::range_error{"Dostignut maksimalni broj pregleda"};
    p[broj_pregleda]=pregled;
    broj_pregleda++;
}
int DajBrojPregleda() const{
    return broj_pregleda;
}
int DajBrojPregledaNaDatum(const Datum &datum) const{
    std::vector<int> v{1,2,3,4,5,6,7};
    auto zs3w=  std::count_if(v.begin(),v.end(),[](int a){return a==1;});
    int u=0;
    for(int i=0;i<broj_pregleda;i++){
        if(p[i]->dat.dan==datum.dan&&p[i]->dat.mjesec==datum.mjesec&&p[i]->dat.godina==datum.godina)u++;
    }
return u;
}
Pregled &DajNajranijiPregled(){
    std::vector<int> v{1,2,3,4,5,6,7};
    auto zs3w=  std::min_element(v.begin(),v.end(),[](int a,int b){return a<b;});
    int zapamti=0;
    Pregled min(*p[0]);
    for(int i=0;i<broj_pregleda;i++){
       if(Pregled::DolaziPrije(*p[i],min)){min=*p[i];zapamti=i;}
    }
    return *p[zapamti];
}
Pregled DajNajranijiPregled() const{
     std::vector<int> v{1,2,3,4,5,6,7};
    auto zs3w=  std::min_element(v.begin(),v.end(),[](int a,int b){return a<b;});
    int zapamti=0;
    Pregled min(*p[0]);
    for(int i=0;i<broj_pregleda;i++){
       if(Pregled::DolaziPrije(*p[i],min)){min=*p[i];zapamti=i;}
    }
    return *p[zapamti];
}
void IsprazniKolekciju();
void ObrisiNajranijiPregled();
void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
void IspisiPregledeNaDatum(const Datum &datum) const;
void IspisiSvePreglede() const;
  
};
int main (){
    Pregledi s(3);
    Datum d(1,2,3),d1(3,4,5);
    Vrijeme v(6,7),v1(8,9);
    s.RegistrirajPregled("Ivo Ivanovic",d,v);
    s.RegistrirajPregled("Ivanko Ivankovic",d1,v1);
    s.DajNajranijiPregled().Ispisi();
    return 0;
}
