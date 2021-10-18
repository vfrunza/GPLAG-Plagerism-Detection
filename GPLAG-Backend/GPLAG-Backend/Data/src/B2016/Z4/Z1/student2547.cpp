/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>

typedef std::pair<double,double>Tacka;

class Trougao{
        Tacka A,B,C;
  
    static bool Uporedi(double rezultat, double epsilon = 0.000001){
            if(std::fabs(rezultat - 0)  < epsilon) return true;
            else return false;
                
        }
    
    static bool UporediDva(double a,double b, double epsilon = 0.000001){
            if(std::fabs(a - b )  < epsilon) return true;
            else return false;
                
        }
     /*double pomocna(const Trougao &t){
            return( (A.first * (B.second - C.second)) - (B.first * (A.second - C.second)) - (C.first * (A.second - B.second)));
        }*/
    public:
//... KONSTRUKTOR 
    
    Trougao (const Tacka &t1 = std::make_pair(0,0)  ,const Tacka &t2 = std::make_pair(0,0),const Tacka &t3 = std::make_pair(0,0) ) {
         if(Orijentacija(t1,t2,t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena.\n");
         else {Trougao::A = t1; Trougao::B = t2; Trougao::C = t3;}
           
    }


void Postavi (const Tacka &t1,const Tacka &t2,const Tacka &t3);
void Postavi(int index,const Tacka &t);

void Ispisi()const{
    //..KAKO SE ISPISUJE TACKA PAIR<DOUBLE,DOUBLE>TACKA
        std::cout<<"( ("<<A.first <<","<< A.second<< ") , (" << B.first<<","<<B.second<< ") , ("<< C.first<<","<<C.second<<") )"<<std::endl;
}

    
/*..FUNKCIJA ZAJEDNICKA ZA SVE PRIMJERKE KLASE,STATICKA FUNKCIJA,POZIVA SE KAO OBICNA FUNKCIJA,PRI CEMU NE ZNA NAD KOJIM JE OBJEKTOM POZVANA,MOZE SE KORISTITI
    UNUTAR DRUGIH FUNKCIJA CLANICA*/
static int Orijentacija (const Tacka &t1,const Tacka &t2,const Tacka &t3);
Tacka   DajTjeme (int index) const;
double  DajStranicu(int index) const;
double  DajUgao(int index) const;
Tacka   DajCentar()const;
double  DajObim()const;
double  DajPovrsinu()const;

bool DaLiJePozitivnoOrijentiran()const;
bool DaLiJeUnutra(const Tacka &t)const;

void Transliraj(double delta_x,double delta_y);
void Centriraj(const Tacka &t);    
void Rotiraj(const Tacka &t,double ugao);
void Rotiraj(double ugao);

void Skaliraj(const Tacka &t,double faktor);
void Skaliraj(double faktor);

friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2);
friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2);
friend bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2);
};




//...FUNKCIJ3 CLANICE
void Trougao::Postavi (const Tacka &t1,const Tacka &t2,const Tacka &t3){
     Trougao::A = t1; Trougao::B = t2; Trougao::C = t3;
    
}
    
void Trougao::Postavi(int index,const Tacka &t){
    if(index == 1) A = t;
    else if(index == 2) B = t;
    else  if(index == 3) C = t;
    else throw std::range_error("Nekorektan index.\n");
}

int Trougao::Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3){
    
    double test = (t1.first * (t2.second - t3.second)) - (t2.first * (t1.second - t3.second)) - (t3.first * (t1.second - t2.second));
    if(Uporedi(test)) return 0;
     
    if( test > 0) return 1;
    else if(  test < 0) return -1;
}

Tacka  Trougao:: DajTjeme (int index) const{ 
        if      (index == 1) return A;  
        else if (index == 2) return B;  
        else if (index == 3) return C; 
        else throw std::range_error("Nekorektan index.\n");
        
}

 double Trougao::DajStranicu(int index) const{ 
     if (index == 1){
         
         return std::sqrt( (C.first - B.first) * (C.first - B.first) + (C.second - B.second) * (C.second - B.second));
     }else if( index == 2){
         return std::sqrt( (C.first - A.first) * (C.first - A.first) + (C.second - A.second) * (C.second - A.second));
     }else if(index == 3){
         return std::sqrt( (B.first - A.first) * (B.first - A.first) + (B.second - A.second) * (B.second - A.second));
     }else{
         throw std::range_error("Nekorektan index.\n");
     }
 }
 
double  Trougao::DajUgao(int index) const{
    double pi = std::atan(1) * 4;
    double rad = 180./pi;
    double arg;
    if(index == 1){
        arg = (std::pow(Trougao::DajStranicu(2),2) + std::pow(Trougao::DajStranicu(3),2) - std::pow(Trougao::DajStranicu(1),2)) / (2 * Trougao::DajStranicu(2) * Trougao::DajStranicu(3));
        return (std::acos(arg) * rad);
        
    }else if(index == 2){
         arg = (std::pow(Trougao::DajStranicu(1),2) + std::pow(Trougao::DajStranicu(3),2) - std::pow(Trougao::DajStranicu(2),2)) / (2 * Trougao::DajStranicu(1) * Trougao::DajStranicu(3));
         return (std::acos(arg) * rad);
    }else if(index == 3){
         arg = (std::pow(Trougao::DajStranicu(1),2) + std::pow(Trougao::DajStranicu(2),2) - std::pow(Trougao::DajStranicu(3),2)) / (2 * Trougao::DajStranicu(1) * Trougao::DajStranicu(2));
         return(std::acos(arg) * rad);
    } else{
        throw std::range_error("Nekorektan index.\n");
    }
}

Tacka  Trougao:: DajCentar()const{
    //...TEZISTE TROUGLA
    Tacka teziste;
    teziste.first = (A.first + B.first + C.first) /  3;
    teziste.second = (A.second + B.second + C.second) / 3 ;
    return teziste;
}

double  Trougao::DajObim()const{
    return (DajStranicu(1) + DajStranicu(2) + DajStranicu(3));
}

double  Trougao::DajPovrsinu()const{
    return(std::abs( ( (A.first * (B.second - C.second)) - (B.first * (A.second - C.second)) - (C.first * (A.second - B.second)) ) /  2.)) ;
}


bool Trougao::DaLiJePozitivnoOrijentiran()const{
    if( Orijentacija(A,B,C) == 1) return true;
    else return false;
}

bool Trougao::DaLiJeUnutra(const Tacka &t)const{
    
     if((Orijentacija(A,B,C) == 1 && Orijentacija(A,B,t) == 1 && Orijentacija(B,C,t) == 1 && Orijentacija(C,A,t) == 1) || (Orijentacija(A,B,C) == -1 && Orijentacija(A,B,t) == -1 && Orijentacija(B,C,t) == -1 && Orijentacija(C,A,t) == -1)){
         return true;
     }else{
         return false;
     }
 }
  
void Trougao::Transliraj(double delta_x,double delta_y){
    A.first += delta_x; A.second  += delta_y;
    B.first += delta_x; B.second += delta_y;
    C.first += delta_x; C.second += delta_y;
}

void Trougao::Centriraj(const Tacka &t){
    //...PROVJERI
    double delta_x = t.first + t.first, delta_y = t.second + t.second;
    if(DajCentar() == t) 
        Transliraj(delta_x,delta_y);
    
}

void Trougao::Rotiraj(const Tacka &t,double ugao){
    
    double pi = std::atan(1) * 4;
    A.first =  t.first +  ((A.first - t.first) * cos(ugao *(pi/180.))) - ((A.second - t.second)* sin(ugao *(pi/180.) ));
    A.second = t.second + ((A.first - t.first) * sin(ugao *(pi/180.) )) + ((A.second - t.second) * cos(ugao * (pi/180.)));
   
    B.first =  t.first +  ((B.first - t.first) * cos(ugao * (pi/180.))) - ((B.second - t.second)* sin(ugao * (pi/180.)));
    B.second = t.second + ((B.first - t.first) * sin(ugao * (pi/180.))) + ((B.second - t.second) * cos(ugao * (pi/180.)));
   
    C.first =  t.first +  ((C.first - t.first) * cos(ugao * (pi/180.))) - ((C.second - t.second)* sin(ugao * (pi/180.)));
    C.second = t.second + ((C.first - t.first) * sin(ugao * (pi/180.))) + ((C.second - t.second) * cos(ugao * (pi/180.)));
    
}

void Trougao::Rotiraj(double ugao){
    //..oko tezista trougla
     double pi = std::atan(1) * 4;
    A.first =  DajCentar().first +  ((A.first - DajCentar().first) * cos(ugao *(pi/180.))) - ((A.second - DajCentar().second)* sin(ugao *(pi/180.) ));
    A.second = DajCentar().second + ((A.first - DajCentar().first) * sin(ugao *(pi/180.) )) + ((A.second - DajCentar().second) * cos(ugao * (pi/180.)));
   
    B.first =  DajCentar().first +  ((B.first - DajCentar().first) * cos(ugao * (pi/180.))) - ((B.second - DajCentar().second)* sin(ugao * (pi/180.)));
    B.second = DajCentar().second + ((B.first - DajCentar().first) * sin(ugao * (pi/180.))) + ((B.second - DajCentar().second) * cos(ugao * (pi/180.)));
   
    C.first =  DajCentar().first +  ((C.first - DajCentar().first) * cos(ugao * (pi/180.))) - ((C.second - DajCentar().second)* sin(ugao * (pi/180.)));
    C.second = DajCentar().second + ((C.first - DajCentar().first) * sin(ugao * (pi/180.))) + ((C.second - DajCentar().second) * cos(ugao * (pi/180.)));
}

 void Trougao::Skaliraj(const Tacka &t,double faktor){
     
      if(faktor > 0){
         //...moguca greska u postavci
         A.first = t.first + (faktor*(A.first - t.first));
         A.second = t.second + (faktor * (A.second - t.second));
         
         B.first = t.first + (faktor*(B.first - t.first));
         B.second = t.second + (faktor * (B.second - t.second));
         
         C.first = t.first + (faktor*(C.first - t.first));
         C.second = t.second + (faktor * (C.second - t.second));
     }else if(faktor < 0){
         
         A.first = t.first + (faktor*(A.first - t.first));
         A.second = t.second + (faktor * (A.second - t.second));
         
         B.first = t.first + (faktor*(B.first - t.first));
         B.second = t.second + (faktor * (B.second - t.second));
         
         C.first = t.first + (faktor*(C.first - t.first));
         C.second = t.second + (faktor * (C.second - t.second));
         
         Rotiraj(180);
         
     }else{
         throw std::domain_error("Nekorektan faktor skaliranja.\n");
     }
 }
 
 
void Trougao::Skaliraj(double faktor){
      
      if(faktor > 0){
         //...moguca greska u postavci
         A.first = DajCentar().first + (faktor*(A.first - DajCentar().first));
         A.second = DajCentar().second + (faktor * (A.second - DajCentar().second));
         
         B.first = DajCentar().first + (faktor*(B.first - DajCentar().first));
         B.second = DajCentar().second + (faktor * (B.second - DajCentar().second));
         
         C.first = DajCentar().first + (faktor*(C.first - DajCentar().first));
         C.second = DajCentar().second + (faktor * (C.second - DajCentar().second));
     }else if(faktor < 0){
         
         A.first = DajCentar().first + (faktor*(A.first - DajCentar().first));
         A.second = DajCentar().second + (faktor * (A.second - DajCentar().second));
         
         B.first = DajCentar().first + (faktor*(B.first - DajCentar().first));
         B.second = DajCentar().second + (faktor * (B.second - DajCentar().second));
         
         C.first = DajCentar().first + (faktor*(C.first - DajCentar().first));
         C.second = DajCentar().second + (faktor * (C.second - DajCentar().second));
         
         Rotiraj(180);
         
     }else{
         throw std::domain_error("Nekorektan faktor skaliranja.\n");
     }
}

bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2){
// identicni trouglovi ne moraju imati istu orjentaciju
    if( (t1.A == t2.B && t1.B == t2.A && t1.C == t2.C) || (t1.A == t2.C && t1.B == t2.B && t1.C == t2.A) || (t1.A == t2.B && t1.B == t2.C && t1.C == t2.A)){
        return true;
    }else{
        return false;
    }
}

bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2){
//..popraviti   
   Trougao X = t1, Y = t2;
   X.Trougao::Transliraj(1,1);
   Y.Trougao:: Transliraj(1,1);
   X.Trougao::Rotiraj(90);
   Y.Trougao::Rotiraj(90);
   
if((Trougao::UporediDva(t1.DajStranicu(1) , t2.DajStranicu(1)) && Trougao::UporediDva(t1.DajStranicu(2),  t2.DajStranicu(2) ) && Trougao::UporediDva(t1.DajStranicu(3),t2.DajStranicu(3)) )
        || (Trougao::UporediDva(t1.DajStranicu(1), t2.DajStranicu(1)) && Trougao::UporediDva(t1.DajStranicu(2),t2.DajStranicu(2)) && Trougao::UporediDva(t1.DajUgao(3), t2.DajUgao(3)) )
        || (Trougao::UporediDva(t1.DajStranicu(1), t2.DajStranicu(1)) && Trougao::UporediDva(t1.DajStranicu(3),t2.DajStranicu(3)) && Trougao::UporediDva(t1.DajUgao(2), t2.DajUgao(2)) )
        || (Trougao::UporediDva(t1.DajStranicu(2),t2.DajStranicu(2))  && Trougao::UporediDva(t1.DajStranicu(3),t2.DajStranicu(3)) && Trougao::UporediDva(t1.DajUgao(1), t2.DajUgao(1)) )
        || (Trougao::UporediDva(t1.DajStranicu(1), t2.DajStranicu(1)) && Trougao::UporediDva(t1.DajUgao(2),t2.DajUgao(2)) && Trougao::UporediDva(t1.DajUgao(3),t2.DajUgao(3)) )
        || (Trougao::UporediDva(t1.DajStranicu(2),t2.DajStranicu(2))  && Trougao::UporediDva(t1.DajUgao(1),t2.DajUgao(1)) && Trougao::UporediDva(t1.DajUgao(3),t2.DajUgao(3)) )
        || (Trougao::UporediDva(t1.DajStranicu(3),t2.DajStranicu(3))  && Trougao::UporediDva(t1.DajUgao(1),t2.DajUgao(1)) && Trougao::UporediDva(t1.DajUgao(2), t2.DajUgao(2)))
        || (Trougao::UporediDva(t1.DajStranicu(1),t2.DajStranicu(1))  && Trougao::UporediDva(t1.DajStranicu(3) , t2.DajStranicu(3)) && Trougao::UporediDva(t1.DajUgao(3), t2.DajUgao(3)) )
        || (Trougao::UporediDva(t1.DajStranicu(1),t2.DajStranicu(1))  && Trougao::UporediDva(t1.DajStranicu(2), t2.DajStranicu(2))  && Trougao::UporediDva(t1.DajUgao(2) , t2.DajUgao(2)) )
        || (Trougao::UporediDva(t1.DajStranicu(2) ,t2.DajStranicu(2)) && Trougao::UporediDva(t1.DajStranicu(3),t2.DajStranicu(3))   && Trougao::UporediDva(t1.DajUgao(2),t2.DajUgao(2)) )
        || ( DaLiSuIdenticni(X,Y) == true)
        ){
            return true;
        
        }else {
            return false;
        }
    
}
/*
bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2){
    //...proporcija, poredjenje double
    if(std::ratio_equal<std::ratio_equal<std::ratio<t1.DajStranicu(1),t2.DajStranicu(1)>,std::ratio<t1.DajStranicu(2), t2.DajStranicu(2)>, std::ratio<t1.DajStranicu(3),t2.DajStranicu(3)> >
    || t1.DajUgao(1) : t2.DajUgao(1) == t1.DajUgao(2) == t2.DajUgao(2) == t1.DajUgao(3) == t2.DajUgao(3)){
        Transliraj();
        Rotiraj();
        Skaliraj();
        DaLiSuIdenticni() == true;
    }
}
*/

int main ()
{
   /*   TEST
    std::pair<double,double> t1 = std::make_pair(1,2);
    std::pair<double,double> t2 = std::make_pair(2,3);
    std::pair<double,double> t3 = std::make_pair(3,3);
    Trougao T(t1,t2,t3) ;
    T.Ispisi();
    std::cout<<T.DajTjeme(1).first<<","<< T.DajTjeme(1).second<<std::endl;
    std::cout<< T.DajUgao(2);
    std::cout<<std::endl;
    std::cout<<T.DajCentar().first<< "," << T.DajCentar().second<<std::endl;
    std::cout<<T.DajObim()<< ","<<T.DajPovrsinu()<<std::endl;
    std::cout<<std::boolalpha<<T.DaLiJePozitivnoOrijentiran()<<std::endl;
    std::cout<<T.DaLiJeUnutra(std::make_pair(9,12))<<std::endl;
    double x = 2, y = 4;
    T.Transliraj(x,y);
    T.Ispisi();
    //T.Centriraj(std::make_pair(4, 4));
    T.Postavi(t1,t2,t3);
    T.Centriraj(std::make_pair(4,4));
    T.Ispisi();

    double pi = std::atan(1) * 4;
    double rad = pi/180.;
    std::cout<<std::cos(90 * (pi/180.))<< " " << std::sin(90 * (pi/180.)) ;
    T.Postavi(t1,t2,t3);
    T.Rotiraj(std::make_pair(0,0),90);
    T.Ispisi();
    
    T.Postavi(t1,t2,t3);
    T.Rotiraj(30);
    T.Ispisi();
    
    T.Postavi(t1,t2,t3);
    T.Skaliraj(std::make_pair(2,2), 4);
    T.Ispisi();
    
    T.Postavi(t1,t2,t3);
    T.Skaliraj(-1);
    T.Ispisi();
    
    Trougao t8(std::make_pair(2,1),std::make_pair(6,1),std::make_pair(6,4));
    Trougao t9(std::make_pair(1,3),std::make_pair(1,7),std::make_pair(4,3));
    
     bool ident = DaLiSuIdenticni(t8,t9);
    std::cout<<ident<<std::endl;
    
    std::cout<<DaLiSuPodudarni(t8,t9)<<" = podudarnost"<<std::endl;
    */
    
    int n;
    std::cout<<"Unesite n:\n";
    std::cin >> n;
    
    std::vector<std::shared_ptr<Trougao>> trouglovi (n);
    std::pair<double,double>a;
    std::pair<double,double>b;
    std::pair<double,double>c;
    
    //...UNESI TACKE TROUGLA 
    try{
    for(int i = 0; i < trouglovi.size(); i++){
        std::cout<<"Unesite koordinate " << i + 1<< "-og trougla: \n";
         std::cout<<"A: ";
        std::cin>> a.first >> a.second;
          std::cout<<"B: ";
        std::cin>> b.first >> b.second;
          std::cout<<"C: ";
        std::cin>> c.first >>  c.second;
      //..kada konstruktor baci izuzetak-- ponovi unos istog trougla
      try{
        trouglovi[i] = std::make_shared<Trougao> (a,b,c);
        // trouglovi[i]->Postavi(a,b,c);
      }catch(std::domain_error izuzetak){
          std::cout<<izuzetak.what();
          //...PONOVI UNOS
          i--;
      }
    }
    
    //...TRANSLIRATI SVE TROUGLOVE U SKLADU SAPODACIMA UNESENIM SA TARSTATURE
   // std::transform(trouglovi[0], trouglovi[n], trouglovi[0],[](){
                    
                                                                   //          });
    
    }catch(...){
        std::cout<<"Nedovoljno memorije.\n";
    }
    
    
    
  
    
    
	return 0;
}