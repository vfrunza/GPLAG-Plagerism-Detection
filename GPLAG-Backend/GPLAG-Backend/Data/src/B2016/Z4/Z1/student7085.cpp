/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>
#define pi 4*atan(1)
#define epsi 0.00001


typedef std::pair<double, double> Tacka;

class Trougao{

Tacka x,y,z;
void ispravnost_indexa( int indeks) const;
static int RacunajOnuFormulu(const Tacka &t1, const Tacka &t2, const Tacka &t3);
void IzracunajStraniceTrougla(double &a, double &b, double &c) const;
Tacka FormulaZaRotaciju(const Tacka &t, double ugao, Tacka koord);
Tacka FaktorSkaliranja(const Tacka &t, double faktor, Tacka koord);
double Pomocna(double a, double b, double c) const;
static bool UporediStranice(const Trougao &t1, const Trougao &t2) ;
static bool Izokreni(const Trougao &t1, const Trougao &t2);
static bool UporediUglove(const Trougao &t1, const Trougao &t2);
static double IzracunajFaktor(double prva, double druga);
Trougao MojeSkaliranje(const Tacka &t, double faktor);

public:    
Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3);
void Postavi (int indeks, const Tacka &t );
static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3);
Tacka DajTjeme (int indeks) const;
double DajStranicu (int indeks) const;
double DajUgao (int indeks) const;
Tacka DajCentar() const;
double DajObim() const;
double DajPovrsinu () const;
bool DaLiJePozitivnoOrijentiran () const;
bool DaLiJeUnutra(const Tacka &t) const;
void Ispisi() const;
void Transliraj (double delta_x, double delta_y);
void Centriraj (const Tacka &t);
void Rotiraj( const Tacka &t, double ugao);
void Skaliraj(const Tacka &t, double faktor);
void Rotiraj( double ugao);
void Skaliraj(double faktor);
friend bool DaLiSuIdenticni( const Trougao &t1, const Trougao &t2);
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuSlicni( const Trougao &t1, const Trougao &t2);
    
};

Trougao:: Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3 ){ 
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    x=t1; y=t2; z=t3;
    
}
void Trougao:: Postavi( const Tacka &t1, const Tacka &t2, const Tacka &t3){
    x=t1;y=t2;z=t3;
    if(Orijentacija(x,y,z)==0) throw std::domain_error("Nekorektne pozicije tjemena");
}

//pomocna
void Trougao::ispravnost_indexa(int indeks)const{
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
}

void Trougao:: Postavi(int indeks, const Tacka &t){
    ispravnost_indexa(indeks);
    if(indeks==1) x=t;
    else if(indeks==2) y=t;
    else if(indeks==3) z=t;
}
//pomocna
int Trougao::RacunajOnuFormulu(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    return t1.first*(t2.second- t3.second)-t2.first*(t1.second- t3.second)+t3.first*(t1.second- t2.second);
}
int Trougao:: Orijentacija( const Tacka &t1, const Tacka &t2, const Tacka &t3){
    //std::cout << "Orijentacija " << RacunajOnuFormulu(t1,t2,t3) << std::endl;
    if(RacunajOnuFormulu(t1,t2,t3)>0) return 1;
    if(RacunajOnuFormulu(t1,t2,t3)<0) return -1;
    if(RacunajOnuFormulu(t1,t2,t3)==0) return 0;
}
Tacka Trougao:: DajTjeme(int indeks) const{
    ispravnost_indexa(indeks);
    if(indeks==1) return x;
    if(indeks==2) return y;
    if(indeks==3) return z;
}
double Trougao::DajStranicu (int indeks) const{
    ispravnost_indexa(indeks);
    if(indeks==1)
    return sqrt((y.first-z.first)*(y.first-z.first) + (y.second-z.second)*(y.second-z.second));
    if(indeks==2)
    return sqrt((z.first-x.first)*(z.first-x.first) + (z.second-x.second)*(z.second-x.second));
    if(indeks==3)
    return sqrt((y.first-x.first)*(y.first-x.first) + (y.second-x.second)*(y.second-x.second));
}
void Trougao:: IzracunajStraniceTrougla(double &a, double &b, double &c) const{
    a=DajStranicu(1);
    b=DajStranicu(2);
    c=DajStranicu(3);
}
double Trougao::DajUgao (int indeks) const{
    ispravnost_indexa(indeks);
    double a,b,c;
    IzracunajStraniceTrougla(a,b,c);
    if(indeks==1)
    return acos((b*b+c*c-a*a)/(2*b*c))*pi/180; //alfa
    if(indeks==2)
    return acos((a*a+c*c-b*b)/(2*a*c))*pi/180; //beta
    if(indeks==3)
    return acos((a*a+b*b-c*c)/(2*a*b))*pi/180; //gama
}
double Trougao:: Pomocna(double x, double y, double z) const{
    if(x+y+z>0 && x+y+z<1) return 0;
    else 
    return x+y+z;
}
Tacka Trougao:: DajCentar() const{
    Tacka Centar;
    //ovde mora postojati fja koja vraca 0 ako je zbir koordinata <0 a ako je veci ovaj return
    return std::make_pair(Pomocna(x.first, y.first, z.first)/3 , Pomocna(x.second, y.second, z.second)/3); 
    
    //return std::make_pair((x.first+y.first+z.first)/3., (x.second+ y.second +z.second)/3.);
}
double Trougao::DajObim() const{
    double a,b,c;
    IzracunajStraniceTrougla(a,b,c);
    return a+b+c;
}
double Trougao:: DajPovrsinu () const{
    return 0.5*abs(RacunajOnuFormulu(x,y,z));
}
bool Trougao::DaLiJePozitivnoOrijentiran () const{ 
    if(Orijentacija(x,y,z)==1 )
    return true;
    else return false;
}
bool Trougao:: DaLiJeUnutra(const Tacka &t) const{
    if(Orijentacija(x,y,z)==1 && Orijentacija(x,y,t)==1 && Orijentacija(y,z,t)==1 && Orijentacija(z,x,t)==1) 
    return true;
    else return false;
}
void Trougao:: Ispisi() const{
    std::cout<<"((" <<x.first<< "," <<x.second<< "),(" <<y.first<< ","<<y.second<<"),("<<z.first<<","<<z.second<<"))";
}
void Trougao:: Transliraj (double delta_x, double delta_y){
    x.first+=delta_x; x.second+=delta_y;
    y.first+=delta_x; y.second+=delta_y;
    z.first+=delta_x; z.second+=delta_y;
    
}
void Trougao:: Centriraj (const Tacka &t){
    double deltaX,deltaY;
    Tacka C=DajCentar();
    deltaX=t.first-C.first;
    deltaY=t.second-C.second;
   // std::cout<<std::endl<<deltaX<<" "<<deltaY<<std::endl;
    Transliraj(deltaX,deltaY);
    /*if(deltaX<0 && deltaY<0) Transliraj(-deltaX, -deltaY);
    if(deltaX>0 && deltaY>0) Transliraj(deltaX, deltaY);
    if(deltaX<0 && deltaY>0) Transliraj(-deltaX, deltaY);
    if(deltaX>0 && deltaY<0) Transliraj(deltaX, -deltaY); */
}
//pomocna
Tacka Trougao:: FormulaZaRotaciju(const Tacka &t, double ugao, Tacka koord){
    //koord.first=t.first+(koord.first=t.first)*cos(ugao)-(koord.second-t.second)*sin(ugao);
    //koord.second=koord.second+(koord.first-t.first)*sin(ugao)+(koord.second-t.second)*cos(ugao);
    return std::make_pair(t.first+(koord.first-t.first)*cos(ugao)-(koord.second-t.second)*sin(ugao), t.second+(koord.first-t.first)*sin(ugao)+(koord.second-t.second)*cos(ugao));
}
void Trougao:: Rotiraj(const Tacka &t, double ugao){
    x=FormulaZaRotaciju(t,ugao,x);
    y=FormulaZaRotaciju(t,ugao,y);
    z=FormulaZaRotaciju(t,ugao,z);
}
Tacka Trougao:: FaktorSkaliranja( const Tacka &t, double faktor, Tacka koord){
   // koord.first=t.first+faktor*(koord.first-t.first);
   // koord.second=t.second+faktor*(koord.second-t.second);
    return std::make_pair(t.first+faktor*(koord.first-t.first), t.second+faktor*(koord.second-t.second));
}
void Trougao:: Skaliraj(const Tacka &t, double faktor){
    if((faktor-0)<epsi) throw std::domain_error("Nekorektan faktor skaliranja");
    x=FaktorSkaliranja(t,faktor,x);
    y=FaktorSkaliranja(t,faktor,y);
    z=FaktorSkaliranja(t,faktor,z);
}
void Trougao:: Skaliraj(double faktor){
    if((faktor-0)<epsi) throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka C=DajCentar();
    x=FaktorSkaliranja(C,faktor,x);
    y=FaktorSkaliranja(C,faktor,y);
    z=FaktorSkaliranja(C,faktor,z);
}
void Trougao:: Rotiraj( double ugao){
    Tacka C=DajCentar();
    x=FormulaZaRotaciju(C,ugao,x);
    y=FormulaZaRotaciju(C,ugao,y);
    z=FormulaZaRotaciju(C,ugao,z);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
  Tacka prvi[3]={t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3)};
    Tacka drugi[3]={t2.DajTjeme(1), t2.DajTjeme(2), t2.DajTjeme(3)};
    std::vector<int> pom;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(std::fabs(prvi[i].first-drugi[j].first)<epsi && std::fabs(prvi[i].second-drugi[j].second)<epsi){
                pom.push_back(1); 
                break;
            }
    if(pom.size()==3){
        for(int i(0);i<pom.size();i++)
            if(pom[i]!=1) return false;
        return true;
    }
    else return false;
}
bool Trougao:: UporediStranice(const Trougao &t1, const Trougao &t2) {
    double prvi[3]={t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3)};
    double drugi[3]={t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3)};
    std::vector<int> pom;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if((prvi[i]-drugi[j])<epsi){
                pom.push_back(1); 
                break;
            }
    if(pom.size()==3){
        for(int i(0);i<pom.size();i++)
            if(pom[i]!=1) return false;
        return true;
    }
    else return false;
}

bool Trougao:: Izokreni(const Trougao &t1, const Trougao &t2){
    double a,b,c, a1, b1, c1;
    std::vector<Tacka> v2={t2.DajTjeme(1), t2.DajTjeme(2), t2.DajTjeme(3)};
    std::vector<Tacka> v1={t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3)};
    while(Orijentacija(v2[0], v2[1], v2[2]) != Orijentacija(v1[0], v1[1], v1[2]) ){
        v2[0]=v2[0]; 
        Tacka p=v2[1];
        v2[1]=v2[2]; v2[2]=p;
    }
    Trougao pom(v2[0], v2[1], v2[2]);
    a=t1.DajStranicu(1); b=t1.DajStranicu(2); c=t1.DajStranicu(3);
    a1=pom.DajStranicu(1); b1=pom.DajStranicu(2); c1=pom.DajStranicu(3);
    double stranice_prvog[3]={a, b, c}; //3 5 4
    double stranice_drugog[3]={a1, b1, c1}; //5 3 4
    double pom1[3]={b,c,a}; //5 4 3
    double pom11[3]={c,a,b}; // 4 3 5
    
    if((stranice_drugog[0]-stranice_prvog[0])<epsi && (stranice_drugog[1]-stranice_prvog[1])<epsi && (stranice_drugog[2]-stranice_prvog[2])<epsi)
    return true;
    if((stranice_drugog[0]-pom1[0])<epsi && (stranice_drugog[1]- pom1[1])<epsi && (stranice_drugog[2]-pom1[2])<epsi)
    return true;
    if((stranice_drugog[0]-pom11[0])<epsi && (stranice_drugog[1]-pom11[1])<epsi && (stranice_drugog[2]-pom11[2])<epsi)
    return true;
    return false;
  
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    if(Trougao::Izokreni(t1,t2) && Trougao:: UporediStranice(t1, t2)){
    return true;
    }
    return false;
}
bool Trougao:: UporediUglove(const Trougao &t1, const Trougao &t2) {
    double prvi[3]={t1.DajUgao(1), t1.DajUgao(2), t1.DajUgao(3)};
    double drugi[3]={t2.DajUgao(1), t2.DajUgao(2), t2.DajUgao(3)};
    std::vector<int> pom;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if((prvi[i]-drugi[j])<epsi){
                pom.push_back(1); 
                break;
            }
    if(pom.size()==3){
        for(int i(0);i<pom.size();i++)
            if(pom[i]!=1) return false;
        return true;
    }
    else return false;
}
double Trougao::IzracunajFaktor(double prva, double druga){
    return prva/druga;
}
Trougao Trougao::MojeSkaliranje(const Tacka &t,double faktor){
    if((faktor-0)<epsi) throw std::domain_error("Nekorektan faktor skaliranja");
    x=FaktorSkaliranja(t,faktor,x);
    y=FaktorSkaliranja(t,faktor,y);
    z=FaktorSkaliranja(t,faktor,z);
    Trougao pom(x,y,z);
    return pom;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
   double a, b, c, a1, b1, c1;
   t1.IzracunajStraniceTrougla(a,b,c);
   t2.IzracunajStraniceTrougla(a1, b1, c1);
   std::vector<double> v1={a,b,c};
   std::vector<double> v2={a1,b1,c1};
   std::sort(v1.begin(), v1.end(),[](double a, double b){return a>b;});
   std::sort(v2.begin(), v2.end(), [](double a, double b){return a>b;});
   
   Trougao pom (t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3));
   double faktor=Trougao::IzracunajFaktor(v1[0], v2[0]);
   pom=pom.MojeSkaliranje(t1.DajCentar(),faktor);
   //std::cout<< pom.DajStranicu(1)<<" "<<pom.DajStranicu(2)<<" "<<pom.DajStranicu(3)<<std::endl;
   //std::cout<<t2.DajStranicu(1)<<" "<<t2.DajStranicu(2)<<" "<<t2.DajStranicu(3)<<std::endl;
   if((faktor-Trougao::IzracunajFaktor(v1[1], v2[1]))<epsi && (faktor-Trougao::IzracunajFaktor(v1[2], v2[2]))<epsi && Trougao::UporediUglove(pom,t2) && DaLiSuPodudarni(pom ,t2 ))
   return true;
   return false;

}


typedef std::shared_ptr<Trougao> pametni;

int main ()
{
    int n; 
    std::cout<<"Koliko zelite kreirati trouglova: "; 
    std::cin>>n; 
    std::vector<pametni>v(n,nullptr); 
    
    Tacka prvo, drugo, trece;
    for(static int i=0; i<n;i++){
        try{
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>prvo.first>>prvo.second;
        std::cin>>drugo.first>>drugo.second;
        std::cin>>trece.first>>trece.second;
        v[i]=std::make_shared<Trougao>(Trougao(prvo, drugo, trece));
    
    }catch(std::bad_alloc){ std::cout<<"Problemi sa memorijom, molimo Vas ponovite unos za "; i--;}
    catch(std::domain_error e){
        std::cout<<e.what()<<", ponovite unos!"<<std::endl;
        i--;
    }
    
    catch(std::range_error e){
        std::cout<<e.what();
    }
    }

    double deltaX, deltaY, ugao, faktor;
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>deltaX>>deltaY;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor;
    
    std::transform(v.begin(), v.end(), v.begin(), [deltaX, deltaY,ugao,faktor](pametni trougao){trougao->Transliraj(deltaX,deltaY); return trougao;});
    std::transform(v.begin(), v.end(), v.begin(), [deltaX, deltaY, ugao, faktor](pametni trougao){trougao->Rotiraj(ugao); return trougao;});
    std::transform(v.begin(), v.end(), v.begin(), [deltaX, deltaY, ugao, faktor](pametni trougao){trougao->Skaliraj(trougao->DajTjeme(1), faktor); return trougao;});
    std::sort(v.begin(), v.end(), [](const pametni &prvi ,const pametni &drugi){ return prvi->DajPovrsinu()< drugi->DajPovrsinu();});
    
    std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
    std::for_each(v.begin(), v.end(),[](const pametni &trougao){trougao->Ispisi(); std::cout<<std::endl;});
    
    auto it_min=std::min_element(v.begin(), v.end(), [](const pametni &prvi, const pametni &drugi){return prvi->DajObim()<drugi->DajObim();});
    
    std::cout<<"Trougao sa najmanjim obimom: ";
    (*it_min)->Ispisi();
    std::cout<<std::endl;
    
    std::vector<std::pair<Trougao, Trougao>> identicni, podudarni, slicni;
    for(int i(0);i<v.size();i++)
    for(int j=i+1;j<v.size();j++){
        if(DaLiSuIdenticni(*v[i], *v[j])) identicni.push_back(std::make_pair(*v[i], *v[j]));
        if(DaLiSuPodudarni(*v[i], *v[j])) podudarni.push_back(std::make_pair(*v[i], *v[j]));
        if(DaLiSuSlicni(*v[i], *v[j])) slicni.push_back(std::make_pair(*v[i], *v[j]));
    }
    if(identicni.size()){
        std::cout<<"Parovi identicnih trouglova: "<<std::endl;
        for(int i=0;i<identicni.size();i++){
            identicni[i].first.Ispisi();
            std::cout<<" i ";
            identicni[i].second.Ispisi();
            std::cout<<std::endl;
        }
    }
    else std::cout<<"Nema identicnih trouglova!"<<std::endl;
   if(podudarni.size()){
       std::cout<<"Parovi podudarnih trouglova: "<<std::endl;
       for(int i(0);i<podudarni.size();i++){
           podudarni[i].first.Ispisi();
           std::cout<<" i ";
           podudarni[i].second.Ispisi();
           std::cout<<std::endl;
       }
   }
   else std::cout<<"Nema podudarnih trouglova!"<< std::endl;
   if(slicni.size()){
       std::cout<<"Parovi slicnih trouglova: "<<std::endl;
       for(int i(0);i<slicni.size();i++){
           slicni[i].first.Ispisi();
           std::cout<<" i ";
           slicni[i].second.Ispisi();
           std::cout<<std::endl;
       }
   }
   if(!slicni.size()) std::cout<<"Nema slicnih trouglova!";
        
    return 0;
}
    
    
    
    
    
    
    
    /*
    
    Tacka x(2,1), y(6,1), z(6,4);
    Trougao ABC(x,y,z);
    Tacka x1(3,5), y1(13, 15), z1(21,27);
    Trougao DEF(x1,y1,z1);
    Tacka C(4,1);
    //DEF.Transliraj(0,0); 
    //std::cout<< C.first<<" "<< C.second<<std::endl;
    //Tacka C1;
    //C1=DEF.DajCentar();
    //std::cout<<DEF.DajTjeme(1).first<<" "<<DEF.DajTjeme(2).first<<" "<<DEF.DajTjeme(3).first<<std::endl;
    //std::cout<< C1.first<<" "<< C1.second<<std::endl;
    //DEF.MojeSkaliranje(x1,)
    //std::cout<<ABC.DajStranicu(1)<<" "<<ABC.DajStranicu(2)<<" "<<ABC.DajStranicu(3)<<std::endl;
    //std::cout<<DEF.DajStranicu(1)<<" "<<DEF.DajStranicu(2)<<" "<< DEF.DajStranicu(3)<<std::endl;
    std:: cout<< ABC.DaLiJeUnutra(C) << " ";
    
    //std::cout << ABC.DaLiJePozitivnoOrijentiran() << " " << DEF.DaLiJePozitivnoOrijentiran() << std::endl;
    return 0;
}
   */
