/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector> 
#include <algorithm>
#include <memory>

using namespace std ; 

typedef std::pair<double, double> Tacka ; 
class Trougao
{
   private : 
   Tacka A,B,C ;
   static double IzracunajIzraz(const Tacka &t1, const Tacka &t2, const Tacka &t3)
   {
       return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second) ;
   }
   static bool JesuLiJednaki(double x, double y)
   {
       double Eps = 1e-10 ; 
       return (fabs(x-y) <= Eps* (fabs(x)+fabs(y))) ;
   }
   public :
   Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
   void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) ; 
   void Postavi(int indeks,const Tacka &t) ; 
   static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) ;
   Tacka DajTjeme(int indeks) const ; 
   double DajStranicu(int indeks) const ; 
   double DajUgao(int indeks) const ; 
   Tacka DajCentar() const ; 
   double DajObim() const ; 
   double DajPovrsinu() const ; 
   bool DaLiJePozitivnoOrijentiran() const ; 
   bool DaLiJeUnutra(const Tacka &t) const ; 
   void Ispisi() const ; 
   void Transliraj(double delta_x, double delta_y) ; 
   void Centriraj(const Tacka &t) ; 
   void Rotiraj(const Tacka &t, double ugao) ;
   void Skaliraj(const Tacka &t, double faktor) ;
   void Rotiraj(double ugao) ; 
   void Skaliraj(double faktor) ; 
   friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) ;
   friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) ;
   friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) ;
}; 
Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if((JesuLiJednaki(t1.first, t2.first) && JesuLiJednaki(t1.first,t3.first)) || (JesuLiJednaki(t1.second,t2.second) && JesuLiJednaki(t2.second,t3.second)) || Orijentacija(t1,t2,t3)==0)
        throw domain_error("Nekorektne pozicije tjemena") ;
    A = t1  ;
    B = t2 ; 
    C = t3 ;
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if((JesuLiJednaki(t1.first,t2.first) && JesuLiJednaki(t1.first,t3.first)) || (JesuLiJednaki(t1.second,t2.second) && JesuLiJednaki(t2.second,t3.second)) || Orijentacija(t1,t2,t3)==0)
        throw domain_error("Nekorektne pozicije tjemena") ;
    A = t1  ;
    B = t2 ; 
    C  = t3 ; 
}
void Trougao::Postavi(int indeks, const Tacka &t)
{
    if(indeks <1 || indeks> 3)
        throw range_error("Nekorektan indeks") ; 
    if(indeks==1)
    {
        if((JesuLiJednaki(t.first,B.first) && JesuLiJednaki(t.first,C.first)) || (JesuLiJednaki(t.second,B.second) && JesuLiJednaki(t.second,C.second)))
            throw domain_error("Nekorektne pozicije tjemena") ; 
        A = t ; 
    }
    else if(indeks==2)
    {
        if((JesuLiJednaki(t.first,A.first) && JesuLiJednaki(t.first,C.first)) || (JesuLiJednaki(t.second,A.second) && JesuLiJednaki(t.second, C.second)))
            throw domain_error("Nekorektne pozicije tjemena") ; 
        B = t ; 
    }
    else
    {
        if((JesuLiJednaki(t.first,A.first) && JesuLiJednaki(t.first,B.first)) || (JesuLiJednaki(t.second,A.second) && JesuLiJednaki(t.second,B.second)))
            throw domain_error("Nekorektne pozicije tjemena") ;
        C  =t  ;
    }
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    double x = IzracunajIzraz(t1,t2,t3) ;
    if(JesuLiJednaki(x,0)) return 0 ; 
    else if(x>0) return 1 ; 
    else return -1 ; 
}
Tacka Trougao::DajTjeme(int indeks) const 
{
    if(indeks < 1 || indeks > 3)
        throw range_error("Nekorektan indeks") ;
    if(indeks == 1) return A  ;
    if(indeks == 2) return B ; 
    return C ;
}
double Trougao::DajStranicu(int indeks) const
{
    if(indeks<1 || indeks>3)
        throw range_error("Nekorektan indeks") ;
    if(indeks==1) return sqrt((C.first-B.first)*(C.first-B.first)+(C.second-B.second)*(C.second-B.second)) ; 
    else if(indeks==2) return sqrt((C.first-A.first)*(C.first-A.first)+(C.second-A.second)*(C.second-A.second)) ; 
    return sqrt((B.first-A.first)*(B.first-A.first)+(B.second-A.second)*(B.second-A.second)) ; 
}
double Trougao::DajUgao(int indeks) const
{
    if(indeks < 1 || indeks > 3)
        throw range_error("Nekorektan indeks");
    if(indeks==1)
    {
        double kosinus = DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1) ;
        kosinus/= (2*DajStranicu(2)*DajStranicu(3)) ;
        return acos(kosinus) ;
    }
    else if(indeks==2)
    {
        double kosinus = DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2) ;
        kosinus/= (2*DajStranicu(1)*DajStranicu(3)) ;
        return  acos(kosinus) ;
    }
    else
    {
        double kosinus = DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3) ;
        kosinus/= (2*DajStranicu(1)*DajStranicu(2)) ;
        return acos(kosinus) ; 
    }
}
Tacka Trougao::DajCentar() const
{
    return {(A.first+B.first+C.first)/3, (A.second+B.second+C.second)/3} ;
}
double Trougao::DajObim() const 
{
    return DajStranicu(1)+ DajStranicu(2) + DajStranicu(3) ;
}
double Trougao::DajPovrsinu() const
{
    return abs(0.5 * IzracunajIzraz(A,B,C)) ;
}
bool Trougao::DaLiJePozitivnoOrijentiran() const
{
    return Orijentacija(A,B,C) > 0 ; 
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const
{
    bool orijentacijaABT = IzracunajIzraz(A,B,t) > 0 ; 
    bool orijentacijaBCT = IzracunajIzraz(B,C,t) > 0 ; 
    bool orijentacijaCAT = IzracunajIzraz(C,A,t) > 0 ;
    if(orijentacijaABT == orijentacijaBCT && orijentacijaBCT == orijentacijaCAT)
        return true ; 
    return false ; 
}
void Trougao::Ispisi() const 
{
    cout << "((" << A.first << "," << A.second << "),(" << B.first << "," << B.second << "),(" << C.first << "," << C.second << "))" ;
}
void Trougao::Transliraj(double delta_x, double delta_y)
{
    A.first +=delta_x ; 
    B.first +=delta_x ; 
    C.first +=delta_x ; 
    A.second +=delta_y ; 
    B.second +=delta_y ; 
    C.second +=delta_y ;
}
void Trougao::Centriraj(const Tacka &t)
{
    double udaljenostAx = A.first - DajCentar().first ; 
    double udaljenostAy = A.second - DajCentar().second ; 
    double udaljenostBx = B.first - DajCentar().first ; 
    double udaljenostBy = B.second - DajCentar().second ;
    double udaljenostCx = C.first - DajCentar().first ; 
    double udaljenostCy = C.second - DajCentar().second ; 
    A.first = t.first + udaljenostAx ; 
    A.second = t.second +udaljenostAy ; 
    B.first = t.first + udaljenostBx ;
    B.second = t.second + udaljenostBy ; 
    C.first = t.first + udaljenostCx ;
    C.second = t.second + udaljenostCy ;
 }
 void Trougao::Rotiraj(const Tacka &t, double ugao)
 {
     double Ax = t.first + (A.first-t.first)*cos(ugao) - (A.second-t.second)*sin(ugao) ;
     double Ay = t.second + (A.first-t.first)*sin(ugao) + (A.second-t.second)*cos(ugao) ;
     double Bx = t.first +(B.first-t.first)*cos(ugao) - (B.second-t.second)*sin(ugao) ;
     double By= t.second + (B.first-t.first)*sin(ugao) + (B.second-t.second)*cos(ugao) ;
     double Cx= t.first +(C.first-t.first)*cos(ugao) - (C.second-t.second)*sin(ugao) ;
     double Cy= t.second + (C.first-t.first)*sin(ugao) + (C.second-t.second)*cos(ugao);
     A.first = Ax ; 
     A.second = Ay ; 
     B.first = Bx ; 
     B.second = By ;
     C.first = Cx ;
     C.second = Cy ;
 }
 void Trougao::Skaliraj(const Tacka &t, double faktor)
 {
     if(JesuLiJednaki(faktor,0)) throw domain_error("Nekorektan faktor skaliranja") ;
     double Ax = t.first + faktor*(A.first-t.first) ;
     double Ay = t.second + faktor*(A.second-t.second) ;
     double Bx = t.first + faktor*(B.first-t.first) ;
     double By = t.second + faktor*(B.second-t.second) ;
     double Cx = t.first + faktor*(C.first-t.first) ;
     double Cy = t.second + faktor*(C.second-t.second);
     A.first = Ax ; 
     A.second = Ay ; 
     B.first = Bx ; 
     B.second = By ;
     C.first = Cx ; 
     C.second = Cy ;
 }
 void Trougao::Rotiraj(double ugao)
 {
     Tacka t = DajCentar() ;
     Rotiraj(t, ugao) ;
 }
 void Trougao::Skaliraj(double faktor)
 {
     Tacka t = DajTjeme(1);
     Skaliraj(t,faktor) ;
 }
 bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
 {
     vector<Tacka> trougaoJedan, trougaoDva ; 
     trougaoJedan.push_back(t1.A) ;
     trougaoJedan.push_back(t1.B) ;
     trougaoJedan.push_back(t1.C) ; 
     trougaoDva.push_back(t2.A) ; 
     trougaoDva.push_back(t2.B) ;
     trougaoDva.push_back(t2.C) ;
     sort(trougaoJedan.begin(), trougaoJedan.end());
     sort(trougaoDva.begin(), trougaoDva.end()) ;
     return trougaoJedan == trougaoDva ; 
 }
 bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
 {
     double A1 = t1.DajStranicu(1) ;
     double B1 = t1.DajStranicu(2) ;
     double C1 = t1.DajStranicu(3) ;
     double A2 = t2.DajStranicu(1) ;
     double B2 = t2.DajStranicu(2) ;
     double C2 = t2.DajStranicu(3) ;
     if(Trougao::JesuLiJednaki(A1/A2,B1/B2) && Trougao::JesuLiJednaki(A1/A2,C1/C2) && t1.Orijentacija(t1.A,t1.B,t1.C)==t2.Orijentacija(t2.A, t2.B, t2.C))
        return true ; 
     if(Trougao::JesuLiJednaki(A1/A2,B1/C2) && Trougao::JesuLiJednaki(A1/A2,C1/B2) && t1.Orijentacija(t1.A,t1.B,t1.C)==t2.Orijentacija(t2.A, t2.C, t2.B))    
        return true ;
     if(Trougao::JesuLiJednaki(A1/C2,B1/B2) && Trougao::JesuLiJednaki(C1/A2,A1/C2) && t1.Orijentacija(t1.A,t1.B,t1.C)==t2.Orijentacija(t2.C,t2.B,t2.A))
        return true ; 
     if(Trougao::JesuLiJednaki(B1/A2,A1/C2) && Trougao::JesuLiJednaki(C1/B2,A1/C2) && t1.Orijentacija(t1.A,t1.B,t1.C)==t2.Orijentacija(t2.C,t2.A,t2.B))
        return true ; 
     if(Trougao::JesuLiJednaki(A1/B2,B1/C2) && Trougao::JesuLiJednaki(C1/A2,A1/B2) && t1.Orijentacija(t1.A,t1.B,t1.C)==t2.Orijentacija(t2.B,t2.C,t2.A))
        return true ;
     if(Trougao::JesuLiJednaki(A1/B2,B1/A2) && Trougao::JesuLiJednaki(C1/C2,A1/B2) && t1.Orijentacija(t1.A,t1.B,t1.C)==t2.Orijentacija(t2.B,t2.A,t2.C))
        return true ;
    return false ; 
 }
 bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
 {
     vector<double> prvi = {t1.DajStranicu(1), t1.DajStranicu(2),t1.DajStranicu(3) };
     vector<double> drugi = {t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3) };
     if(t1.DaLiJePozitivnoOrijentiran() == t2.DaLiJePozitivnoOrijentiran())
     {
         if(Trougao::JesuLiJednaki(prvi[0],drugi[0]) && Trougao::JesuLiJednaki(prvi[1],drugi[1]) && Trougao::JesuLiJednaki(prvi[2],drugi[2]))
                return true ;
         else if(Trougao::JesuLiJednaki(prvi[0],drugi[1]) && Trougao::JesuLiJednaki(prvi[1],drugi[2]) && Trougao::JesuLiJednaki(prvi[2],drugi[0]))
                return true ; 
         else if( Trougao::JesuLiJednaki(prvi[0],drugi[2]) && Trougao::JesuLiJednaki(prvi[1],drugi[0]) && Trougao::JesuLiJednaki(prvi[2],drugi[1]))
                return true ; 
         else return false ; 
     }
     else 
     {
         if(Trougao::JesuLiJednaki(prvi[0],drugi[0]) && Trougao::JesuLiJednaki(prvi[1],drugi[2]) && Trougao::JesuLiJednaki(prvi[2],drugi[1]))
            return true ; 
        else if(Trougao::JesuLiJednaki(prvi[0],drugi[1]) && Trougao::JesuLiJednaki(prvi[1],drugi[0]) && Trougao::JesuLiJednaki(prvi[2],drugi[2]))
            return true ; 
        else if(Trougao::JesuLiJednaki(prvi[0],drugi[2]) && Trougao::JesuLiJednaki(prvi[1],drugi[1]) && Trougao::JesuLiJednaki(prvi[2],drugi[0]))
            return true ; 
        else return false ; 
     }
 }
int main ()
{
    cout << "Koliko zelite kreirati trouglova: " ;
    int x ;
    cin >> x ; 
    vector<shared_ptr<Trougao>> v ; 
    v.reserve(x) ;
    for(int i = 0 ; i<x ; i++)
    {
        cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): " ;
        double x1, x2,x3,y1,y2,y3 ; 
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ; 
        try{
        v.push_back(shared_ptr<Trougao>(new Trougao(make_pair(x1,y1),make_pair(x2,y2), make_pair(x3,y3)))) ; 
        }
        catch(domain_error e)
        {
            cout << e.what() << ", ponovite unos!" << endl ; 
            i-- ; 
        }
    }
    cout << "Unesite vektor translacije (dx dy): " ; 
    double dx, dy ;
    cin >> dx >> dy ;
    cout << "Unesite ugao rotacije: " ; 
    double ugao ; 
    cin >> ugao ; 
    cout << "Unesite faktor skaliranja: " ; 
    double faktor ; 
    cin >> faktor ; 
    cout << "Trouglovi nakon obavljenih transformacija:" << endl ; 
    transform(v.begin(), v.end(), v.begin(), [dx,dy,ugao,faktor] (shared_ptr<Trougao> &p)
    {
        p->Transliraj(dx,dy) ; 
        p->Rotiraj(ugao) ;  
        p->Skaliraj(faktor) ;
        return p ; 
    }) ;
    sort(v.begin(), v.end(), [](shared_ptr<Trougao> p, shared_ptr<Trougao> q)
    {
        return p->DajPovrsinu() < q->DajPovrsinu() ;
    });
    for_each(v.begin(), v.end(), [](shared_ptr<Trougao>&p)
    {
       p->Ispisi() ; cout << endl ; 
    }); 
    cout << "Trougao sa najmanjim obimom: " ;
    auto it = min_element(v.begin(), v.end(), [](shared_ptr<Trougao>&p, shared_ptr<Trougao> &q)
    {
        return p->DajObim() < q->DajObim() ;
    });
    (*it)->Ispisi() ; 
    cout << endl ; 
    int broj_identicnih = 0 ; 
    for(int i=0 ; i<v.size() ; i++)
    {
        for(int j = i+1 ; j< v.size() ; j++)
        {
            if(DaLiSuIdenticni(*v[i],*v[j]))
                broj_identicnih++ ; 
        }
    }
    if(broj_identicnih == 0) cout << "Nema identicnih trouglova!" << endl ; 
    else 
    {
        cout << "Parovi identicnih trouglova: " << endl ; 
        for(int i= 0 ; i<v.size() ; i++)
        {
            for(int j=i+1 ; j < v.size() ; j++)
            {
                if(DaLiSuIdenticni(*v[i],*v[j]))
                {
                    (*v[i]).Ispisi() ; 
                    cout << " i " ;
                    (*v[j]).Ispisi() ;
                    cout << endl ; 
                }
            }
        }
    }
    int broj_podudarnih = 0 ;
    for(int i=0 ; i<v.size() ; i++)
    {
        for(int j=i+1 ; j<v.size() ;j++)
        {
            if(DaLiSuPodudarni(*v[i],*v[j]))
                broj_podudarnih++ ;
        }
    }
    if(broj_podudarnih== 0) cout << "Nema podudarnih trouglova!" << endl ;
    else
    {
        cout <<   "Parovi podudarnih trouglova: " << endl ; 
        for(int i=0 ; i<v.size();i++)
        {
            for(int j=i+1 ; j<v.size() ;j++)
            {
                if(DaLiSuPodudarni(*v[i],*v[j]))
                {
                    (*v[i]).Ispisi();
                    cout << " i " ; 
                    (*v[j]).Ispisi() ;
                    cout << endl ; 
                }
            }
        }
    }
    int broj_slicnih = 0 ; 
    for(int i=0 ; i<v.size() ; i++)
    {
        for(int j=i+1 ; j<v.size() ;j++)
        {
            if(DaLiSuSlicni(*v[i],*v[j]))
                broj_slicnih++ ;
        }
    }
    if(broj_slicnih == 0) cout << "Nema slicnih trouglova!" << endl ;
    else
    {
        cout << "Parovi slicnih trouglova: " << endl ; 
        for(int i=0 ; i<v.size(); i++)
        {
            for(int j=i+1 ; j<v.size() ; j++)
            {
                if(DaLiSuSlicni(*v[j],*v[i]))
                {
                    (*v[i]).Ispisi();
                    cout << " i " ; 
                    (*v[j]).Ispisi();
                    cout << endl ; 
                }
            }
        }
    }
	return 0;
}