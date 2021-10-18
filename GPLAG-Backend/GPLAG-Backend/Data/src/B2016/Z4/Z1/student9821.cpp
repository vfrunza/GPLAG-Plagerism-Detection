/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<utility>
#include<cmath>
#include<stdexcept>
#include<vector>
#include<algorithm>
#include<memory>
#include<new>
typedef std::pair<double,double> Tacka;
class Trougao
{
    Tacka T1, T2, T3;

    void ispitivanje_indexa (int index)const {
        if(index<=0 || index>3) {
            throw std::range_error("Nekorektan indeks");
        }
    }
    double Duzina_str (const Tacka &t1,const Tacka &t2)const {
        return sqrt( (t2.first - t1.first)*(t2.first - t1.first) + (t2.second - t1.second)*(t2.second - t1.second)  );
    }
    double Ugao(double x, double y, double z) const {
        return acos( (y*y + z*z - x*x)/(2*y*z)  );
    }
    double Testiranje_orijentacije(const Tacka &t1,const Tacka &t2,const Tacka &t3)const {
        return t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second) ;
    }

    static bool Test(const Trougao &t1, const Trougao &t2)  {
        if( t1.DajUgao(1)==t1.DajUgao(2) || t1.DajUgao(1)==t1.DajUgao(3) || t1.DajUgao(2)==t1.DajUgao(3) ) {
            return true;
        }

        std::vector<Tacka>V2 ;
        for(int i=1; i<4; i++) {
            for(int j=1; j<4; j++) {
                if( t1.DajUgao(i)==t2.DajUgao(j) ) {
                    V2.push_back( t2.DajTjeme(j)  );
                }
            }
        }

        if( Orijentacija(t1.T1, t1.T2, t1.T3) != Orijentacija( V2[0], V2[1], V2[2] ) ) {
            return false;
        }
        return true;
    }

public:

    Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3) {
        if( Orijentacija(t1,t2,t3) ==0 ) {
            throw std::domain_error("Nekorektne pozicije tjemena");
        }
        T1=t1;
        T2=t2;
        T3=t3;
    }
    void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3) {
        if( Orijentacija(t1,t2,t3) ==0 ) {
            throw std::domain_error("Nekorektne pozicije tjemena");
        }
        T1=t1;
        T2=t2;
        T3=t3;
    }
    void Postavi(int indeks, const Tacka &t) {
        ispitivanje_indexa(indeks);
        if(indeks==1) {
            T1=t;
        }
        if(indeks==2) {
            T2=t;
        }
        if(indeks==3) {
            T3=t;
        }
        if( Orijentacija(T1,T2,T3) ==0 ) {
            throw std::domain_error("Nekorektne pozicije tjemena");
        }
    }
    static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3) {
        double izraz = t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second) ;
        if(izraz>0) {
            return 1;
        }
        if(izraz<0) {
            return -1;
        }
        if(izraz==0) {
            return 0;
        }
    }
    Tacka DajTjeme(int indeks)const {
        ispitivanje_indexa(indeks);
        if(indeks==1) {
            return T1;
        }
        if(indeks==2) {
            return T2;
        }
        if(indeks==3) {
            return T3;
        }
    }
    double DajStranicu(int indeks) const {
        ispitivanje_indexa(indeks);
        if(indeks==1) {
            return Duzina_str(T2,T3);
        }
        if(indeks==2) {
            return Duzina_str(T1,T3);
        }
        if(indeks==3) {
            return Duzina_str(T1,T2);
        }
    }
    double DajUgao(int indeks)const {
        ispitivanje_indexa(indeks);
        if(indeks==1) {
            return Ugao( Duzina_str(T2,T3), Duzina_str(T1,T3), Duzina_str(T1,T2) );
        }
        if(indeks==2) {
            return Ugao( Duzina_str(T1,T3), Duzina_str(T2,T3), Duzina_str(T1,T2) );
        }
        if(indeks==3) {
            return Ugao( Duzina_str(T1,T2), Duzina_str(T1,T3), Duzina_str(T3,T2) );
        }
    }
    Tacka DajCentar()const {
        Tacka T;
        T.first=(T1.first+T2.first+T3.first)/3;
        T.second=(T1.second+T2.second+T3.second)/3;
        return T;
    }
    double DajObim()const  {
        return Duzina_str(T1,T2) + Duzina_str(T1,T3) + Duzina_str(T2,T3) ;
    }
    double DajPovrsinu()const {
        return abs(Testiranje_orijentacije(T1,T2,T3) )*0.5 ;
    }
    bool DaLiJePozitivnoOrijentiran()const {
        if(Orijentacija(T1,T2,T3)) {
            return true;
        }
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const {
        if ( Orijentacija(T1,T2,t) != Orijentacija(T1,T2,T3) || Orijentacija(T2,T3,t) != Orijentacija(T1,T2,T3) || Orijentacija(T3,T1,t) != Orijentacija(T1,T2,T3) ) {
            return false;
        }
        return true;
    }
    void Ispisi()const {
        std::cout << "( (" <<T1.first<<","<<T1.second<<") , ("<<T2.first<<","<<T2.second<<") , ("<<T3.first<<","<<T3.second<<") )";
    }
    void Transliraj( double delta_x, double delta_y) {
        T1.first+=delta_x;
        T1.second+=delta_y;
        T2.first+=delta_x;
        T2.second+=delta_y;
        T3.first+=delta_x;
        T3.second+=delta_y;
    }
    void Centriraj(const Tacka &t) {
        Transliraj(t.first-DajCentar().first, t.second- DajCentar().second);
    }
    void Rotiraj(const Tacka &t, double ugao) {
        T1.first= t.first + (T1.first-t.first)*cos(ugao) - (T1.second-t.second)*sin(ugao) ;
        T1.second= t.second + (T1.first-t.first)*sin(ugao) + (T1.second-t.second)*cos(ugao) ;

        T2.first= t.first + (T2.first-t.first)*cos(ugao) - (T2.second-t.second)*sin(ugao) ;
        T2.second= t.second + (T2.first-t.first)*sin(ugao) + (T2.second-t.second)*cos(ugao) ;

        T3.first= t.first + (T3.first-t.first)*cos(ugao) - (T3.second-t.second)*sin(ugao) ;
        T3.second= t.second + (T3.first-t.first)*sin(ugao) + (T3.second-t.second)*cos(ugao) ;
    }
    void Skaliraj(const Tacka &t,double faktor) {
        if(faktor==0) {
            throw std::domain_error("Nekorektan faktor skaliranja");
        }
        T1.first= t.first + faktor*(T1.first-t.first);
        T1.second= t.second + faktor*(T1.second-t.second);

        T2.first= t.first + faktor*(T2.first-t.first);
        T2.second= t.second + faktor*(T2.second-t.second);

        T3.first= t.first + faktor*(T3.first-t.first);
        T3.second= t.second + faktor*(T3.second-t.second);

        if(faktor<0) {
            Rotiraj(t,180);
        }
    }
    void Rotiraj(double ugao) {
        Rotiraj(DajCentar(),ugao);
    }
    void Skaliraj(double faktor) {
        Skaliraj(DajCentar(),faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};


bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    std::vector<Tacka>V1 { t1.T1, t1.T2, t1.T3 } ;
    if(  std::find( std::begin(V1), std::end(V1), t2.T1 ) == std::end(V1) ) {
        return false;
    }
    if(  std::find( std::begin(V1), std::end(V1), t2.T2 ) == std::end(V1) ) {
        return false;
    }
    if(  std::find( std::begin(V1), std::end(V1), t2.T3 ) == std::end(V1) ) {
        return false;
    }
    return true;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    std::vector<double>V1 { t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3) } ;

    if(  std::find( std::begin(V1), std::end(V1), t2.DajStranicu(1) ) == std::end(V1) ) {
        return false;                                                                             // ispitujemo da li su duzine str jednake
    }
    V1.erase( std::begin(V1)+ (std::find( std::begin(V1), std::end(V1), t2.DajStranicu(1) ) - std::begin(V1) ) );

    if(  std::find( std::begin(V1), std::end(V1), t2.DajStranicu(2) ) == std::end(V1) ) {
        return false;
    }
    V1.erase( std::begin(V1)+ (std::find( std::begin(V1), std::end(V1), t2.DajStranicu(2) ) - std::begin(V1) ) );

    if(  std::find( std::begin(V1), std::end(V1), t2.DajStranicu(3) ) == std::end(V1) ) {
        return false;
    }

    return Trougao::Test(t1,t2);
}

bool DaLiSuSlicni( const Trougao &t1,const Trougao &t2)
{
    std::vector<double>V1 { t1.DajUgao(1), t1.DajUgao(2), t1.DajUgao(3) } ;

    if(  std::find( std::begin(V1), std::end(V1), t2.DajUgao(1) ) == std::end(V1) ) {
        return false;                                                                             // ispitujemo da li su duzine str jednake
    }
    V1.erase( std::begin(V1)+ (std::find( std::begin(V1), std::end(V1), t2.DajUgao(1) ) - std::begin(V1) ) );

    if(  std::find( std::begin(V1), std::end(V1), t2.DajUgao(2) ) == std::end(V1) ) {
        return false;
    }
    V1.erase( std::begin(V1)+ (std::find( std::begin(V1), std::end(V1), t2.DajUgao(2) ) - std::begin(V1) ) );

    if(  std::find( std::begin(V1), std::end(V1), t2.DajUgao(3) ) == std::end(V1) ) {
        return false;
    }


    return Trougao::Test(t1,t2);
}


int main ()
{
    std::cout << "Koliko zelite kreirati trouglova: ";
    int n(0);
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>>Vektor(n) ;
    for(int i=0; i<n; i++) {
        std::cout << "Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): " ;
        Tacka t1,t2,t3;
        std::cin >> t1.first;
        std::cin >> t1.second;
        std::cin >> t2.first;
        std::cin >> t2.second;
        std::cin >>t3.first;
        std::cin >> t3.second;
        try {
            Vektor[i]=std::make_shared<Trougao>(t1,t2,t3);
        } catch(std::domain_error e) {
            std::cout <<e.what()<<", ponovite unos!" << std::endl;
            i--;
        }
    }
    std::cout << "Unesite vektor translacije (dx dy): ";
    double x(0),y(0);
    std::cin >> x>>y;

    std::cout << "Unesite ugao rotacije: ";
    double ugao(0);
    std::cin >> ugao;
ugao=(ugao* 4*atan(1) )/180;
    std::cout << "Unesite faktor skaliranja: ";
    double faktor_skaliranja(0);
    std::cin >> faktor_skaliranja;

 std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
    std::transform(std::begin(Vektor), std::end(Vektor), std::begin(Vektor), [x,y] ( std::shared_ptr<Trougao>t) {
        (*t).Transliraj(x,y);
    return t;});
  
  std::transform(std::begin(Vektor), std::end(Vektor), std::begin(Vektor), [ugao] (std::shared_ptr<Trougao>t) {
      (*t).Rotiraj(ugao);
  return t;});
  
  
  std::transform(std::begin(Vektor), std::end(Vektor), std::begin(Vektor), [faktor_skaliranja] ( std::shared_ptr<Trougao>t) {
      (*t).Skaliraj((*t).DajTjeme(1),faktor_skaliranja);
  return t;});

  std::sort(std::begin(Vektor), std::end(Vektor), [] (std::shared_ptr<Trougao>t1, std::shared_ptr<Trougao>t2) {
      return (*t1).DajPovrsinu()<(*t2).DajPovrsinu() ;
  });

  std::for_each(std::begin(Vektor),std::end(Vektor),[] (std::shared_ptr<Trougao>t) {
      (*t).Ispisi();
      std::cout << std::endl;
  });

  std::cout << "Trougao sa najmanjim obimom: " ;
  auto it =std::min_element(std::begin(Vektor), std::end(Vektor),[] (std::shared_ptr<Trougao>t1, std::shared_ptr<Trougao>t2) {
      return (*t1).DajObim()<(*t2).DajObim() ;
  });
(**it).Ispisi();






  
  return 0;
}
