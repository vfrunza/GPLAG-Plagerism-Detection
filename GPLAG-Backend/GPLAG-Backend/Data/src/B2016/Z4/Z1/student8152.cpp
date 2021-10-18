/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <utility>
#include <vector>
#include <memory>
#include <algorithm>
#include <new>


using namespace std;

const double pi = 4 * atan(1);
const double eps = 0.0001;

typedef std::pair<double, double> Tacka;

class Trougao {
    
    Tacka a,b,c;   
    
  public:
 Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1, t2, t3); }
 
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    
    a = t1;
    b = t2;
    c = t3;
    
}

void Postavi(int indeks, const Tacka &t){
    
    if(indeks < 1 || indeks > 3) throw range_error("Nekorektan indeks");
    else {
        
        if(indeks == 1) {
            a.first = t.first;
            a.second = t.second;
        }
        else if(indeks == 2) {
               
            b.first = t.first;
            b.second = t.second;
        }
        else if(indeks == 3) {
            
            c.first = t.first;
            c.second = t.second;
        }
    }
    
}
static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    
    if((t1.first * (t2.second - t3.second) - t2.second * (t1.second - t3.second) + t3.first * (t1.second - t2.second)) > 0) return 1;
    else if((t1.first * (t2.second - t3.second) - t2.second * (t1.second - t3.second) + t3.first * (t1.second - t2.second)) < 0) return -1;
    else return 0;
}

Tacka DajTjeme(int indeks) const {
    
    if(indeks == 1) return a;
    else if(indeks == 2) return b;
    else if(indeks == 3) return c;
    else throw range_error("Nekorektan indeks");
    
}


double DajStranicu(int indeks) const {
    
    double strA = sqrt((c.first - b.first) * (c.first - b.first) + (c.second - b.second) * (c.second - b.second));
    double strB = sqrt((c.first - a.first) * (c.first - a.first) + (c.second - a.second) * (c.second - a.second));
    double strC = sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
    
    if(indeks == 1) return strA;
    else if(indeks == 2) return strB;
    else if(indeks == 3) return strC;
    else throw range_error("Nekorektan indeks");
    
}


double DajUgao(int indeks) const {
    
    if(indeks == 1) return acos((DajStranicu(2) * DajStranicu(2) + DajStranicu(3) * DajStranicu(3) - DajStranicu(1) - DajStranicu(1)) / (2 * DajStranicu(2) * DajStranicu(3)));
    if(indeks == 2) return acos((DajStranicu(1) * DajStranicu(1) + DajStranicu(3) * DajStranicu(3) - DajStranicu(2) - DajStranicu(2)) / (2 * DajStranicu(1) * DajStranicu(3)));
    if(indeks == 3) return acos((DajStranicu(1) * DajStranicu(1) + DajStranicu(2) * DajStranicu(2) - DajStranicu(3) - DajStranicu(3)) / (2 * DajStranicu(2) * DajStranicu(1)));
}

Tacka DajCentar() const;
double DajObim() const {

    return (DajStranicu(1) + DajStranicu(2) + DajStranicu(3));

}
double DajPovrsinu() const {
    
    return (sqrt((DajObim() / 2) * (DajObim() - DajStranicu(1)) * (DajObim() - DajStranicu(2)) * (DajObim() - DajStranicu(3)))); 
    
}
bool DaLiJePozitivnoOrijentiran() const {
    
    if(Orijentacija(a,b,c) > 0) return true;
    else return false;
    
}
bool DaLiJeUnutra(const Tacka &t) const;
void Ispisi() const {
    //Transliraj();
   cout << "((" << a.first << "," << a.second << "),(" << b.first << "," << b.second << "),(" << c.first << "," << c.second << "))" << endl;
   
    
    
}
void Transliraj(double delta_x, double delta_y) {
    
    Trougao::a.first += delta_x;
    Trougao::b.first += delta_x;
    Trougao::c.first += delta_x;
    Trougao::a.second += delta_y;
    Trougao::b.second += delta_y;
    Trougao::c.second += delta_y;

    
}
void Centriraj(const Tacka &t);
void Rotiraj(const Tacka &t, double ugao);
void Skaliraj(const Tacka &t, double faktor);
void Rotiraj(double ugao){
    
    a.first = a.first * cos(ugao) - a.second * sin(ugao);
    a.second = a.first * sin(ugao) - a.second * cos(ugao);
    
    b.first = b.first * cos(ugao) - b.second * sin(ugao);
    b.second =b.first * sin(ugao) - b.second * cos(ugao);
    
    c.first = c.first * cos(ugao) - c.second * sin(ugao);
    c.second = c.first * sin(ugao) - c.second * cos(ugao);
    
}
void Skaliraj(double faktor) {
    
    if(faktor == 0) throw domain_error("Ilegalan faktor skaliranja");
    
    a.first = faktor * a.first;
    a.second = faktor * a.second;
    
    b.first = faktor * b.first;
    b.second = faktor * b.second;
    
    c.first = faktor * c.first;
    c.second = faktor * c.second;
    
    
}
friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    
    if(fabs(t1.DajStranicu(1) - t2.DajStranicu(1)) < eps && fabs(t1.DajStranicu(2) - t2.DajStranicu(2)) < eps && fabs(t1.DajStranicu(3) - t2.DajStranicu(3)) < eps) return true;
    if(fabs(t1.DajStranicu(1) - t2.DajStranicu(2)) < eps && fabs(t1.DajStranicu(2) - t2.DajStranicu(1)) < eps && fabs(t1.DajStranicu(3) - t2.DajStranicu(3)) < eps) return true;
    if(fabs(t1.DajStranicu(1) - t2.DajStranicu(3)) < eps && fabs(t1.DajStranicu(2) - t2.DajStranicu(2)) < eps && fabs(t1.DajStranicu(3) - t2.DajStranicu(1)) < eps) return true;
    if(fabs(t1.DajStranicu(1) - t2.DajStranicu(1)) < eps && fabs(t1.DajStranicu(3) - t2.DajStranicu(2)) < eps && fabs(t1.DajStranicu(2) - t2.DajStranicu(3)) < eps) return true;
    return false;
    
} 
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    
    if(fabs(t1.DajStranicu(1) / t1.DajStranicu(2) / t1.DajStranicu(3) - t2.DajStranicu(1) / t2.DajStranicu(2) / t2.DajStranicu(3)) < eps) return true;
    if(fabs(t1.DajStranicu(2) / t1.DajStranicu(1) / t1.DajStranicu(3) - t2.DajStranicu(2) / t2.DajStranicu(1) / t2.DajStranicu(3)) < eps) return true;
    if(fabs(t1.DajStranicu(3) / t1.DajStranicu(2) / t1.DajStranicu(1) - t2.DajStranicu(3) / t2.DajStranicu(2) / t2.DajStranicu(1)) < eps) return true;
    return false;
}
    
    
};
int main ()
{
    int n;
    double x,y;
    Tacka a,b,c;
    Trougao *niz[100];
    cout << "Koliko zelite kreirati trouglova: ";
    cin >> n;
    vector<shared_ptr<Trougao>> trouglovi;
    
    try {
    for(int i = 0;i < n; i++) {
        
        cout << "Unesite podatke za " << i + 1 <<". trougao (x1 y1 x2 y2 x3 y3): ";
        cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
        niz[i] = new Trougao(a,b,c);
        shared_ptr<Trougao> pomocni(make_shared<Trougao>(Trougao(a,b,c)));
        trouglovi.push_back(pomocni);
        
    }
    cout << "Unesite vektor translacije (dx dy): ";
    cin >> x >> y;
   // transform(niz, (niz + n), niz, [x,y](Trougao t){t->Transliraj(x,y);});
    sort(trouglovi.begin(), trouglovi.end(), [](shared_ptr<Trougao> prvi, shared_ptr<Trougao> drugi){return (prvi ->DajPovrsinu() > drugi -> DajPovrsinu());});
    for(auto x : trouglovi) x -> Transliraj(1,0);
    for(auto x : trouglovi) x -> Rotiraj(1);
    for(auto x : trouglovi) x -> Skaliraj(5);
    for(auto x : trouglovi) x -> Ispisi();
    
    }catch(range_error er){
        
        cout << er.what();
        
    }catch(domain_error err){
        
        cout << err.what();
    }
    
    
    
	return 0;
}