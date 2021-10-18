/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <utility>
#include <algorithm>
#include <memory>
#include <vector>

using namespace std;

const double Eps(1e-10);

typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka T1,T2,T3;
public:
static double Vrijednost_izraza (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    return (t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
}
Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if (Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
    T1=t1; T2=t2; T3=t3;
}
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
     if (Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
    T1=t1; T2=t2; T3=t3;
}
void Postavi(int indeks, const Tacka &t){
    if (indeks==1) T1=t;
    else if (indeks==2) T2=t;
    else if (indeks==3) T3=t;
    if (Orijentacija(T1,T2,T3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
    else throw std::range_error ("Nekorektan indeks");
}
static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if (Vrijednost_izraza(t1,t2,t3)>0) return 1;
    else if (Vrijednost_izraza(t1,t2,t3)<0) return -1; 
    return 0;
}
Tacka DajTjeme(int indeks) const{
    if (indeks==1) return T1;
    else if (indeks==2) return T2;
    else if (indeks==3) return T3;
    else throw std::range_error ("Nekorektan indeks");
}
double DajStranicu(int indeks) const{
    if (indeks==1) return (sqrt(pow((T3.first-T2.first),2)+pow((T3.second-T2.second),2)));
    else if (indeks==2) return (sqrt(pow((T1.first-T3.first),2)+pow((T1.second-T3.second),2)));
    else if (indeks==3) return (sqrt(pow((T2.first-T1.first),2)+pow((T2.second-T1.second),2)));
    else throw std::range_error ("Nekorektan indeks");
}
double DajUgao(int indeks) const{
    auto ab (sqrt(pow((T3.first-T2.first),2)+pow((T3.second-T2.second),2)));
    auto bc (sqrt(pow((T1.first-T3.first),2)+pow((T1.second-T3.second),2)));
    auto ac (sqrt(pow((T2.first-T1.first),2)+pow((T2.second-T1.second),2)));
    if (indeks==1) return (acos((bc*bc+ac*ac-ab*ab)/(2*bc*ac)));
    else if (indeks==2) return (acos((ac*ac+ab*ab-bc*bc)/(2*ab*ac)));
    else if (indeks==3) return (acos((bc*bc-ac*ac+ab*ab)/(2*bc*ab)));
    else throw std::range_error ("Nekorektan indeks");
}
Tacka DajCentar() const{
    Tacka T ((T1.first+T2.first+T3.first)/3.,(T1.second+T2.second+T3.second)/3.);
    return T;
}
double DajObim() const{
     return (DajStranicu(1)+DajStranicu(2)+DajStranicu(3));  
}
double DajPovrsinu() const{
    return (abs(Vrijednost_izraza(T1,T2,T3))/2.);
}
bool DaLiJePozitivnoOrijentiran() const{
    if (Orijentacija(T1,T2,T3)==1) return 1;
    return 0;
}
bool DaLiJeUnutra(const Tacka &t) const{
    auto a (Trougao(t,T2,T3));
    auto b (Trougao(T1,t,T3));
    auto c (Trougao(T1,T2,t));
    auto d (Trougao(T1,T2,T3));
    if ((a.DajPovrsinu()+b.DajPovrsinu()+c.DajPovrsinu()-d.DajPovrsinu())<Eps) return 1;
    return 0;
}
void Ispisi() const{
    std::cout << "((" << T1.first << "," << T1.second << "),(" << T2.first << "," << T2.second << "),(" << T3.first << "," << T3.second << "))";
}
void Transliraj(double delta_x, double delta_y){
    T1.first+=delta_x;T1.second+=delta_y;
    T2.first+=delta_x;T2.second+=delta_y;
    T3.first+=delta_x;T3.second+=delta_y;
}
void Centriraj(const Tacka &t){
    if (DajCentar()!=t) Transliraj(DajCentar().first-t.first,DajCentar().second-t.second);
}
void Rotiraj(const Tacka &t, double ugao){
    if (ugao>0){
    T1=std::make_pair (t.first+(T1.first-t.first)*std::cos(ugao)-(T1.second-t.second)*std::sin(ugao),t.second+(T1.first-t.first)*std::sin(ugao)+(T1.second-t.second)*std::cos(ugao));
    T2=std::make_pair (t.first+(T2.first-t.first)*std::cos(ugao)-(T2.second-t.second)*std::sin(ugao),t.second+(T2.first-t.first)*std::sin(ugao)+(T2.second-t.second)*std::cos(ugao));
    T3=std::make_pair (t.first+(T3.first-t.first)*std::cos(ugao)-(T3.second-t.second)*std::sin(ugao),t.second+(T3.first-t.first)*std::sin(ugao)+(T3.second-t.second)*std::cos(ugao));
    }
}
void Skaliraj(const Tacka &t, double faktor){
    if (faktor==0) throw std::domain_error ("Nekorektan faktor skeliranja");
        T1=std::make_pair(t.first+faktor*(T1.first-t.first),t.second+faktor*(T1.second-t.second));
        T2=std::make_pair(t.first+faktor*(T2.first-t.first),t.second+faktor*(T2.second-t.second));
        T3=std::make_pair(t.first+faktor*(T3.first-t.first),t.second+faktor*(T3.second-t.second));
}
void Rotiraj(double ugao){
    auto t (DajCentar());
    if (ugao>0){
        T1=std::make_pair (t.first+(T1.first-t.first)*cos(ugao)-(T1.second-t.second)*sin(ugao),t.second+(T1.first-t.first)*sin(ugao)+(T1.second-t.second)*cos(ugao));
        T2=std::make_pair (t.first+(T2.first-t.first)*cos(ugao)-(T2.second-t.second)*sin(ugao),t.second+(T2.first-t.first)*sin(ugao)+(T2.second-t.second)*cos(ugao));
        T3=std::make_pair (t.first+(T3.first-t.first)*cos(ugao)-(T3.second-t.second)*sin(ugao),t.second+(T3.first-t.first)*sin(ugao)+(T3.second-t.second)*cos(ugao));
    }
}
void Skaliraj(double faktor){
    auto t (DajCentar());
    T1=std::make_pair(t.first+faktor*(T1.first-t.first),t.second+faktor*(T1.second-t.second));
    T2=std::make_pair(t.first+faktor*(T2.first-t.first),t.second+faktor*(T2.second-t.second));
    T3=std::make_pair(t.first+faktor*(T3.first-t.first),t.second+faktor*(T3.second-t.second));
}
friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    Tacka A1 (t1.DajTjeme(1)); Tacka B1 (t2.DajTjeme(1));
    Tacka A2 (t1.DajTjeme(2)); Tacka B2 (t2.DajTjeme(2));
    Tacka A3 (t1.DajTjeme(3)); Tacka B3 (t2.DajTjeme(3));
    if ((A1==B1 && A2==B2 && A3==B3) || (A1==B1 && A2==B3 && A3==B2) || (A1==B2 && A2==B1 && A3==B3) || (A1==B2 && A2==B3 && A3==B2) || (A1==B3 && A2==B1 && A3==B2) || (A1==B3 && A2==B2 && A3==B1)) return 1;
    else return 0;
}
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    auto a (Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)));
    
    if (abs (t1.DajStranicu(1)-t2.DajStranicu(1))<=Eps && abs (t1.DajStranicu(2)-t2.DajStranicu(2))<=Eps && abs (t1.DajStranicu(3)-t2.DajStranicu(3))<=Eps  
    && a==Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3))) return 1;
    
    if (abs (t1.DajStranicu(1)-t2.DajStranicu(1))<=Eps && abs (t1.DajStranicu(2)-t2.DajStranicu(3))<=Eps && abs (t1.DajStranicu(3)-t2.DajStranicu(2))<=Eps  
    && a==Orijentacija(t2.DajTjeme(1),t2.DajTjeme(3),t2.DajTjeme(2))) return 1;
    
    if (abs (t1.DajStranicu(1)-t2.DajStranicu(2))<=Eps && abs (t1.DajStranicu(2)-t2.DajStranicu(1))<=Eps && abs (t1.DajStranicu(3)-t2.DajStranicu(3))<=Eps  
    && a==Orijentacija(t2.DajTjeme(2),t2.DajTjeme(1),t2.DajTjeme(3))) return 1;
    
    if (abs (t1.DajStranicu(1)-t2.DajStranicu(2))<=Eps && abs (t1.DajStranicu(2)-t2.DajStranicu(3))<=Eps && abs (t1.DajStranicu(3)-t2.DajStranicu(1))<=Eps  
    && a==Orijentacija(t2.DajTjeme(2),t2.DajTjeme(3),t2.DajTjeme(1))) return 1;
    
    if (abs (t1.DajStranicu(1)-t2.DajStranicu(3))<=Eps && abs (t1.DajStranicu(2)-t2.DajStranicu(2))<=Eps && abs (t1.DajStranicu(3)-t2.DajStranicu(1))<=Eps  
    && a==Orijentacija(t2.DajTjeme(3),t2.DajTjeme(2),t2.DajTjeme(1))) return 1;
    
    if (abs (t1.DajStranicu(1)-t2.DajStranicu(3))<=Eps && abs (t1.DajStranicu(2)-t2.DajStranicu(1))<=Eps && abs (t1.DajStranicu(3)-t2.DajStranicu(2))<=Eps  
    && a==Orijentacija(t2.DajTjeme(3),t2.DajTjeme(1),t2.DajTjeme(2))) return 1;
    
    return 0;
}
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    auto a (Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)));
    
    if (abs (t1.DajUgao(1)-t2.DajUgao(1))<=Eps && abs (t1.DajUgao(2)-t2.DajUgao(2))<=Eps && abs (t1.DajUgao(3)-t2.DajUgao(3))<=Eps  
    && a==Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3))) return 1;
    
    if (abs (t1.DajUgao(1)-t2.DajUgao(1))<=Eps && abs (t1.DajUgao(2)-t2.DajUgao(3))<=Eps && abs (t1.DajUgao(3)-t2.DajUgao(2))<=Eps  
    && a==Orijentacija(t2.DajTjeme(1),t2.DajTjeme(3),t2.DajTjeme(2))) return 1;
    
    if (abs (t1.DajUgao(1)-t2.DajUgao(2))<=Eps && abs (t1.DajUgao(2)-t2.DajUgao(1))<=Eps && abs (t1.DajUgao(3)-t2.DajUgao(3))<=Eps  
    && a==Orijentacija(t2.DajTjeme(2),t2.DajTjeme(1),t2.DajTjeme(3))) return 1;
    
    if (abs (t1.DajUgao(1)-t2.DajUgao(2))<=Eps && abs (t1.DajUgao(2)-t2.DajUgao(3))<=Eps && abs (t1.DajUgao(3)-t2.DajUgao(1))<=Eps  
    && a==Orijentacija(t2.DajTjeme(2),t2.DajTjeme(3),t2.DajTjeme(1))) return 1;
    
    if (abs (t1.DajUgao(1)-t2.DajUgao(3))<=Eps && abs (t1.DajUgao(2)-t2.DajUgao(2))<=Eps && abs (t1.DajUgao(3)-t2.DajUgao(1))<=Eps  
    && a==Orijentacija(t2.DajTjeme(3),t2.DajTjeme(2),t2.DajTjeme(1))) return 1;
    
    if (abs (t1.DajUgao(1)-t2.DajUgao(3))<=Eps && abs (t1.DajUgao(2)-t2.DajUgao(1))<=Eps && abs (t1.DajUgao(3)-t2.DajUgao(2))<=Eps  
    && a==Orijentacija(t2.DajTjeme(3),t2.DajTjeme(1),t2.DajTjeme(2))) return 1;
    
    return 0;
}
};

int main ()
{
    int a(0);
    cout << "Koliko zelite kreirati trouglova: ";
	cin >> a;
	std::vector<std::shared_ptr<Trougao>> t1;
	for (int i=0;i<a;i++){
	    int x1,y1,x2,y2,x3,y3;
	    cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
	    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	    try{
	        auto x (std::make_shared<Trougao>(Trougao({x1,y1},{x2,y2},{x3,y3})));
	        t1.push_back (x);
	    }
	    catch (std::domain_error err){
	        cout << err.what() << ", ponovite unos!" << endl;
	        i--;
	    }
	}
	int dx,dy;
	cout << "Unesite vektor translacije (dx dy): ";
	cin >> dx >> dy;
        std::transform (t1.begin(),t1.end(),t1.begin(),[dx,dy](std::shared_ptr<Trougao> t){t->Transliraj(dx,dy);return t;});
    double ug;
	cout << "Unesite ugao rotacije: ";
	cin >> ug;
	    std::transform(t1.begin(),t1.end(),t1.begin(),[ug](std::shared_ptr<Trougao> t){t->Rotiraj(ug);return t;});
	int faktor;
	cout << "Unesite faktor skaliranja: ";
	cin >> faktor;
	try{
	     std::transform(t1.begin(),t1.end(),t1.begin(),[faktor](std::shared_ptr<Trougao> t){t->Skaliraj(t->DajTjeme(1),faktor);return t;});
	}
	catch(std::domain_error err){
	    cout << err.what() << endl;
	}
	std::sort(t1.begin(), t1.end(), [](const std::shared_ptr<Trougao> &t2,const std::shared_ptr<Trougao> &t3){return t2->DajPovrsinu()<t3->DajPovrsinu();});
	cout << "Trouglovi nakon obavljenih transformacija:" << endl;
	std::for_each(t1.begin(), t1.end(), [] (std::shared_ptr<Trougao> t){t->Ispisi();cout << endl;});
	
	cout << "Trougao sa najmanjim obimom: ";
	auto k=std::min_element (t1.begin(),t1.end(),[](const std::shared_ptr<Trougao> &t2,const std::shared_ptr<Trougao> &t3){return t2->DajObim()<t3->DajObim();});
	(*k)->Ispisi();cout<<endl;
	
	int f(0),l(0),m(0);
	for (int i(0);i<t1.size();i++){
	    for(int j(i+1);j<t1.size();j++){
	        if (DaLiSuIdenticni(*t1[i],*t1[j])) f=1;
	        if (DaLiSuPodudarni(*t1[i],*t1[j])) l=1;
	        if (DaLiSuSlicni(*t1[i],*t1[j])) m=1;
	    }
	}
	if (f){
	    cout << "Parovi identicnih trouglova:" << endl;
	    for (int i(0);i<t1.size();i++){
	         for(int j(i+1);j<t1.size();j++){
	             if (DaLiSuIdenticni(*t1[i],*t1[j])){
	                 t1[i]->Ispisi();
	                 cout << " i ";
	                 t1[j]->Ispisi();
	                 cout << endl;
	             }
	        }
	    }
	}
	else cout << "Nema identicnih trouglova!" << endl;
	
	
	if (l){
	    cout << "Parovi podudarnih trouglova:" << endl;
	    for (int i(0);i<t1.size();i++){
	         for(int j(i+1);j<t1.size();j++){
	             if (DaLiSuPodudarni(*t1[i],*t1[j])){
	                 t1[i]->Ispisi();
	                 cout << " i ";
	                 t1[j]->Ispisi();
	                 cout << endl;
	             }
	        }
	    }
	}
	else cout << "Nema podudarnih trouglova!" << endl;
	
	
	if (m){
	    cout << "Parovi slicnih trouglova:" << endl;
	    for (int i(0);i<t1.size();i++){
	         for(int j(i+1);j<t1.size();j++){
	             if (DaLiSuSlicni(*t1[i],*t1[j])){
	                 t1[i]->Ispisi();
	                 cout << " i ";
	                 t1[j]->Ispisi();
	                 cout << endl;
	             }
	        }
	    }
	}
	else cout << "Nema slicnih trouglova!" << endl;
	return 0;
}