/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <utility>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>


typedef std::pair<double, double> Tacka;
class Trougao {
mutable Tacka a, b, c;

public:
Trougao() = default;
Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1, t2, t3);}
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
void Postavi(int indeks, const Tacka &t);
static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
Tacka DajTjeme(int indeks) const;
double DajStranicu(int indeks) const;
double DajUgao(int indeks) const;
Tacka DajCentar() const;
double DajObim() const;
double DajPovrsinu() const;
bool DaLiJePozitivnoOrijentiran() const;
bool DaLiJeUnutra(const Tacka &t) const;
void Ispisi() const;
void Transliraj(double delta_x, double delta_y);
void Centriraj(const Tacka &t);
void Rotiraj(const Tacka &t, double ugao);
void Skaliraj(const Tacka &t, double faktor);
void Rotiraj(double ugao);
void Skaliraj(double faktor);
friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
  a=t1; b=t2; c=t3;
}
void Trougao::Postavi(int indeks, const Tacka &t){
  if(indeks<=0 || indeks>3) throw std::range_error("Nekorektan indeks");
  if(indeks==1) a=t;
  else if(indeks==2) b=t;
  else if(indeks==3) c=t;
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
  double o;
  int orjent(1);
  o = t1.first * (t2.second - t3.second) - t2.first * (t1.first - t3.second) - t3.first * (t1.first - t2.second);	
  if(o==0.) throw std::domain_error ("Nekorektne pozicije tjemena");
  else if(o>=1.) orjent=1;
  else if(o<1.) orjent=-1;
return orjent;  
}
Tacka Trougao::DajTjeme(int indeks) const{ 
  if(indeks<=0 || indeks>3) throw std::range_error("Nekorektan indeks");
  if(indeks==1) return a;
  else if(indeks==2) return b;
return c;
}
double Trougao::DajStranicu(int indeks) const{
  double duzina(0);
  if(indeks<=0 || indeks>3) throw std::range_error("Nekorektan indeks");
  if(indeks==1) duzina=sqrt( pow( (c.first-b.first), 2) + pow( (c.second-b.second), 2) );
  else if(indeks==2) duzina = sqrt( pow((a.first-c.first), 2) + pow((a.second-c.second), 2));
  else if(indeks==3) duzina=sqrt( pow ( (a.first-b.first), 2) + pow((a.second-b.second), 2));
 return duzina;
}
double Trougao::DajUgao(int indeks) const{
  double ugao(0);
  double duzina_a, duzina_b, duzina_c;
  if(indeks<=0 || indeks>3) throw std::range_error("Nekorektan indeks");
  duzina_a= sqrt( pow( (c.first-b.first), 2) + pow( (c.second-b.second), 2));
  duzina_b= sqrt( pow( (a.first-c.first), 2) + pow( (a.second-c.second), 2));
  duzina_c= sqrt( pow( (a.first-b.first), 2) + pow( (a.second-b.second), 2));
  if(indeks==1) ugao=acos( (pow(duzina_b, 2) + pow(duzina_c, 2) - pow(duzina_a, 2))/(2*duzina_b*duzina_c) );
  else if(indeks==2) ugao=acos( (pow(duzina_a, 2) + pow(duzina_c, 2) - pow(duzina_b, 2))/(2*duzina_a*duzina_c) );
  else if( indeks==3) ugao=acos( (pow(duzina_a, 2) + pow(duzina_b, 2) - pow(duzina_c, 2))/(2*duzina_a*duzina_b) );
return ugao;
}
// Metoda “DajCentar” daje kao rezultat tačku koja predstavlja centar odnosno težište trougla

Tacka Trougao::DajCentar() const{
  Tacka T;
  T.first=(a.first+b.first+c.first)/3.;
  T.second=(a.second+b.second+c.second)/3.;
return T;
}
double Trougao::DajObim() const{
  double Obim;
  double duzina_a, duzina_b, duzina_c;
  duzina_a = sqrt( pow( (c.first-b.first), 2) + pow( (c.second-b.second), 2));
  duzina_b = sqrt( pow( (a.first-c.first), 2) + pow( (a.second-c.second), 2));
  duzina_c = sqrt( pow( (a.first-b.first), 2) + pow( (a.second-b.second), 2));
  Obim = duzina_a + duzina_b + duzina_c;
return Obim;
}
double Trougao::DajPovrsinu() const{
  double P;
  P=(1./2)*fabs( a.first * (b.second - c.second) + b.first * (c.first - a.second) + c.first * (a.first - b.second) );
return P;
}
bool Trougao::DaLiJePozitivnoOrijentiran() const{
  bool tacno(1);
  double Or;
  Or = a.first * (b.second - c.second) - b.first * (a.first - c.second) - c.first * (a.first - b.second);	
  if(Or==0.) throw std::domain_error ("Nekorektne pozicije tjemena");
  else if(Or<1.) tacno=0;
return tacno;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
  bool unutra(true);
  double Or_1, Or_2, Or_3, Or_4;
  
  Or_1 = a.first * (b.second - c.second) - b.first * (a.first - c.second) - c.first * (a.first - b.second);
  Or_2 = a.first * (b.second - t.second) - b.first * (a.first - t.second) - t.first * (a.first - b.second);
  Or_3 = b.first * (c.second - t.second) - c.first * (b.first - t.second) - t.first * (b.first - c.second);
  Or_4 = c.first * (a.second - t.second) - a.first * (c.first - t.second) - t.first * (c.first - a.second); 
  if(Or_1<0 || Or_2<0 || Or_3<0 || Or_4<0) unutra=false;
  
return unutra;
}
void Trougao::Ispisi() const{
  std::cout<<"Trougao ima koordinate: ("<<a.first<<", "<<a.second<<"), ("<<b.first<<", "<<b.second<<"), ("<<c.first<<", "<<c.second<<").";
}
void Trougao::Transliraj(double delta_x, double delta_y){
    a.first+=delta_x;
    b.first+=delta_x;
    c.first+=delta_x;
    a.second+=delta_y;
    b.second+=delta_y;
    c.second+=delta_y;
} 
void Centriraj(const Tacka &t){
  Tacka T;
  T.first=t.first;
  T.second=t.second;
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
  Tacka R_a, R_b, R_c;
  R_a.first = t.first + (a.first - t.first)*cos(ugao) - (a.second - t.second)*sin(ugao);
  R_a.second = t.second + (a.first - t.first)*sin(ugao) + (a.second - t.second)*cos(ugao);
  R_b.first = t.first + (b.first - t.first)*cos(ugao) - (b.second - t.second)*sin(ugao);
  R_b.second = t.second + (b.first - t.first)*sin(ugao) + (b.second - t.second)*cos(ugao);
  R_c.first = t.first + (c.first - t.first)*cos(ugao) - (c.second - t.second)*sin(ugao);
  R_c.second = t.second + (c.first - t.first)*sin(ugao) + (c.second - t.second)*cos(ugao);
}
void Trougao::Skaliraj(const Tacka &t, double faktor){
  Tacka S_a, S_b, S_c;
  if(faktor==0.) throw std::domain_error("Nekorektan faktor skaliranja");
  S_a.first = t.first + faktor*(a.first - t.first);
  S_a.second = t.second + faktor*(a.second - t.second);
  S_b.first = t.first + faktor*(b.first - t.first);
  S_b.second = t.second + faktor*(b.second - t.second);
  S_c.first = t.first + faktor*(c.first - t.first);
  S_c.second = t.second + faktor*(c.second - t.second);
}
void Trougao::Rotiraj(double ugao){
  Tacka T, R_a, R_b, R_c;
  T.first=(a.first+b.first+c.first)/3.;  // CENTAR ROTACIJE
  T.second=(a.second+b.second+c.second)/3.;
  
  R_a.first = T.first + (a.first - T.first)*cos(ugao) - (a.second - T.second)*sin(ugao);
  R_a.second = T.second + (a.first - T.first)*sin(ugao) + (a.second - T.second)*cos(ugao);
  R_b.first = T.first + (b.first - T.first)*cos(ugao) - (b.second - T.second)*sin(ugao);
  R_b.second = T.second + (b.first - T.first)*sin(ugao) + (b.second - T.second)*cos(ugao);
  R_c.first = T.first + (c.first - T.first)*cos(ugao) - (c.second - T.second)*sin(ugao);
  R_c.second = T.second + (c.first - T.first)*sin(ugao) + (c.second - T.second)*cos(ugao);
}
void Trougao::Skaliraj(double faktor){
  Tacka T;
  T.first=(a.first+b.first+c.first)/3.;  // CENTAR ROTACIJE
  T.second=(a.second+b.second+c.second)/3.;
  
  Tacka S_a, S_b, S_c;
  
  if(faktor==0.) throw std::domain_error("Nekorektan faktor skaliranja");
  S_a.first = T.first + faktor*(a.first - T.first);
  S_a.second = T.second + faktor*(a.second - T.second);
  S_b.first = T.first + faktor*(b.first - T.first);
  S_b.second = T.second + faktor*(b.second - T.second);
  S_c.first = T.first + faktor*(c.first - T.first);
  S_c.second = T.second + faktor*(c.second - T.second);
}
// testira da li se trouglovi koji joj se prenose kao parametri poklapaju, tj. da li su im tjemena na istim mjestima u ravni
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
  bool Identicni(false);
  if( (t1.a==t2.a || t1.a==t2.b || t1.a==t2.c) && (t1.b==t2.a || t1.b==t2.b || t1.b==t2.c) && (t1.c==t2.a || t1.c==t2.b || t1.c==t2.c ) ) Identicni=true;
  
  return Identicni;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
  bool podudarni(false);
  double duzina_a_t1, duzina_b_t1, duzina_c_t1, duzina_a_t2, duzina_b_t2, duzina_c_t2;
  duzina_a_t1= sqrt( pow( (t1.c.first-t1.b.first), 2) + pow( (t1.c.second-t1.b.second), 2));
  duzina_b_t1= sqrt( pow( (t1.a.first-t1.c.first), 2) + pow( (t1.a.second-t1.c.second), 2));
  duzina_c_t1= sqrt( pow( (t1.a.first-t1.b.first), 2) + pow( (t1.a.second-t1.b.second), 2));
  duzina_a_t2= sqrt( pow( (t2.c.first-t2.b.first), 2) + pow( (t2.c.second-t2.b.second), 2));
  duzina_b_t2= sqrt( pow( (t2.a.first-t2.c.first), 2) + pow( (t2.a.second-t2.c.second), 2));
  duzina_c_t2= sqrt( pow( (t2.a.first-t2.b.first), 2) + pow( (t2.a.second-t2.b.second), 2));
  if( (duzina_a_t1==duzina_a_t2 || duzina_a_t1==duzina_b_t2 || duzina_a_t1==duzina_c_t2) && (duzina_b_t1==duzina_a_t2 || duzina_b_t1==duzina_b_t2 || duzina_b_t1==duzina_c_t2) 
  && ( duzina_c_t1==duzina_a_t2 || duzina_c_t1==duzina_b_t2 || duzina_c_t1==duzina_c_t2) ) podudarni=true;
  
 return podudarni;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
  bool slicni(false);
  double duzina_a_t1, duzina_b_t1, duzina_c_t1, duzina_a_t2, duzina_b_t2, duzina_c_t2;
  double x, y, z, x1, y1, z1, x2, y2, z2;
  duzina_a_t1= sqrt( pow( (t1.c.first-t1.b.first), 2) + pow( (t1.c.second-t1.b.second), 2));
  duzina_b_t1= sqrt( pow( (t1.a.first-t1.c.first), 2) + pow( (t1.a.second-t1.c.second), 2));
  duzina_c_t1= sqrt( pow( (t1.a.first-t1.b.first), 2) + pow( (t1.a.second-t1.b.second), 2));
  duzina_a_t2= sqrt( pow( (t2.c.first-t2.b.first), 2) + pow( (t2.c.second-t2.b.second), 2));
  duzina_b_t2= sqrt( pow( (t2.a.first-t2.c.first), 2) + pow( (t2.a.second-t2.c.second), 2));
  duzina_c_t2= sqrt( pow( (t2.a.first-t2.b.first), 2) + pow( (t2.a.second-t2.b.second), 2));
  x=duzina_a_t1/duzina_a_t2;
  y=duzina_a_t1/duzina_b_t2;
  z=duzina_a_t1/duzina_c_t2;
  x1=duzina_b_t1/duzina_a_t2;
  y1=duzina_b_t1/duzina_b_t2;
  z1=duzina_b_t1/duzina_c_t2; 
  x2=duzina_c_t1/duzina_a_t2;
  y2=duzina_c_t1/duzina_b_t2;
  z2=duzina_c_t1/duzina_c_t2;
  if( (x==int(x) || y==int(y) || z==int(z)) && (x1==int(x1) || y1==int(y1) || z1==int(z1)) && (x2==int(x2) || y2==int(y2) || z2==int(z2)) ) slicni=true;
  return slicni;
}   
    
  /*Napisanu klasu demonstrirajte u testnom programu koji traži da se tastature unese prirodan broj
 , koji zatim treba kreirati prazan vektor od pametnih pokazivača na objekte tipa “Trougao”.
Nakon toga, sa tastature treba redom unositi podatke za trouglova (podaci o svakom trouglu se
unose posebno, redom za prvo, drugo a zatim i za treće tjeme). Za svaki od trouglova, nakon
obavljenog unosa treba dinamički kreirati odgovarajući trougao inicijaliziran u skladu sa
unesenim podacima i pametni pokazivač na tako kreirani kreirani trougao ubaciti u vektor.
Ukoliko korisnik zada tjemena od kojih se ne može formirati trougao, treba ispisati poruku
upozorenja i zatražiti novi unos podataka za isti trougao. Nakon okončanja unosa, program treba
prvo translirati sve trouglove u skladu sa podacima koji se unose sa tastature, a zatim ih rotirati
oko njihovog centra te skalirati uzimajući prvo tjeme kao centar skaliranja, pri čemu se ugao
rotacije i faktor skaliranja unose sa tastature. Za tu svrhu trebate koristiti funkciju “transform” iz
biblioteke “algorithm”, pri čemu transformacionu funkciju koja se prosljeđuje funkciji “transform”
treba izvesti kao lambda funkciju. Nakon obavljenih transformacija, treba sortirati sve trouglove u
rastući poredak po površini (tj. trougao sa manjom površinom dolazi prije trougla sa većom
površinom), te ispisati podatke o svim trouglovima nakon obavljenog sortiranja. Podaci o svakom
trouglu trebaju biti u posebnom redu. Za sortiranje obavezno koristiti bibliotečku funkciju “sort”
uz pogodno definiranu funkciju kriterija kao lambda funkciju, a za ispis treba koristiti funkciju
“foreach” i prikladnu lambda funkcije. Zatim treba ispisati podatke o trouglu koji ima najmanji
obim, za šta ćete iskoristiti funkciju “max_element” uz definiranje prikladne funkcije kriterija
(ponovo kao lambda funkcije). Konačno, na kraju, program treba pronaći sve parove identičnih,
podudarnih i sličnih trouglova i ispisati koji su to trouglovi (ili obavijest da takvih parova nema).
Ovo je okvirni opis šta testni program treba da radi, a precizan izgled dijaloga između korisnika i
programa biće specificiran putem javnih autotestova.*/
    
int main(){
    try{
    int n;
    double t1_x, t2_x, t3_x, t1_y, t2_y, t3_y;
    Tacka T1, T2, T3;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    for(int i=0; i<n; i++){
      std::vector<std::shared_ptr<Trougao>> T;
      std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
      std::cin>>t1_x>>t2_x>>t3_x>>t1_y>>t2_y>>t3_y;
      if(!std::cin){
      std::cout<<"Neispravne koordinate";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      std::cin>>t1_x>>t2_x>>t3_x>>t1_y>>t2_y>>t3_y;
      }
      Tacka T1=std::make_pair(t1_x, t1_y);
      Tacka T2=std::make_pair(t2_x, t2_y);
      Tacka T3=std::make_pair(t3_x, t3_y);
      T.push_back(std::make_shared<Trougao>(T1, T2, T3));
      double delta_x, delta_y;
      std::cin>>delta_x>>delta_y;
      double ugao;
      std::cin>>ugao;
      double faktor;
      std::cin>>faktor;
     
    std::transform(T.begin(), T.end(), T.begin(), [double delta_x, double delta_y](std::make_shared<Trougao> T) {  (*T).Transliraj(delta_x, delta_y); });
    
    //std::transform(T.begin(), T.end(), T.begin(), [ugao, t1_x, t1_y] (std::shared_ptr<Trougao> t1){ Tacka T1=std::make_pair(t1_x, t1_y); t1->Rotiraj(T1, ugao);});
    
   // std::transform(T.begin(), T.end(), T.begin(), [faktor, t1_x, t1_y] (std::shared_ptr<Trougao> t) { Tacka T1=std::make_pair(t1_x, t1_y); t->Skaliraj(T1, faktor);});
    
        //std::sort(T.begin(), T.end());
        //std::for_each(T.begin(), T.end(), []( std::shared_ptr<Trougao> T) { T->Ispisi();});
        //std::max_element(T.begin(), T.end(), [](std::shared_ptr<Trougao> T) {T->DajObim();});*/
 

    }
   
    }
    catch(std::range_error poruka){
      std::cout<<poruka.what()<<std::endl;
    }
    catch(std::domain_error izuzetak){
      std::cout<<izuzetak.what()<<std::endl;
    }
    
    return 0;
}   
   