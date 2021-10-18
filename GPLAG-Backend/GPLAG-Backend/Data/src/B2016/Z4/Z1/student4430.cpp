/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#define eps 1e-10
using namespace std; 
typedef std::pair<double, double> Tacka;
class Trougao{
    Tacka T1, T2, T3; 
    double Povrsina(const Tacka &t1, const Tacka &t2, const Tacka &t3) const {
        return (t1.first*(t2.second-t3.second)+t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))/2;
    }
    static int Izraz(Tacka t1, Tacka t2, Tacka t3){
        return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    }
    static double DuzinaStranice(const Tacka &t1, const Tacka &t2) {
        return sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
    }
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
       Postavi(t1,t2,t3); 
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0) throw domain_error ("Nekorektne pozicije tjemena"); 
        T1=t1, T2=t2, T3=t3; 
    }
    void Postavi(int indeks, const Tacka &t){
        if(indeks<1 || indeks>3) throw range_error ("Nekorektan indeks"); 
        if(indeks==1) T1=t; 
        else if(indeks==2) T2=t; 
        else if(indeks==3) T3=t;
        if(Orijentacija(T1,T2,T3)==0) throw domain_error ("Nekorektne pozicije tjemena"); 
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double izraz=Izraz(t1,t2,t3); 
        if(izraz>0) return 1; 
        if(izraz<0) return -1; 
        return 0; 
}
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
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
        if(t1.T1==t2.T1 || t1.T1==t2.T2 || t1.T1==t2.T3)
            if(t1.T2==t2.T1 || t1.T2==t2.T2 || t1.T2==t2.T3)
                if(t1.T3==t2.T1 || t1.T3==t2.T2 || t1.T3==t2.T3)
                    return true; 
        return false; 
    }
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
       vector<double> str1(3), str2(3); 
       str1[0]=Trougao::DuzinaStranice(t1.DajTjeme(1), t1.DajTjeme(2));
       str1[1]=Trougao::DuzinaStranice(t1.DajTjeme(2), t1.DajTjeme(3)); 
       str1[2]=Trougao::DuzinaStranice(t1.DajTjeme(3), t1.DajTjeme(1)); 
       str2[0]=Trougao::DuzinaStranice(t2.DajTjeme(1), t2.DajTjeme(2)); 
       str2[1]=Trougao::DuzinaStranice(t2.DajTjeme(2), t2.DajTjeme(3)); 
       str2[2]=Trougao::DuzinaStranice(t2.DajTjeme(3), t2.DajTjeme(1));
       int brojac=0;
       for(int i=0; i<3; i++)
           for(int j=0; j<3; j++)
               if(fabs(str1[i]-str2[j])<eps){
               brojac++; break; 
            }
            if(brojac<3) return false;  // nisu sve stranice iste
            
            pair<double, Tacka> jedan[3], dva[3]; 
            
            jedan[0].first=str1[0]; 
            jedan[0].second=t1.Trougao::DajTjeme(3); 
            jedan[1].first=str1[1]; 
            jedan[1].second=t1.Trougao::DajTjeme(1);
            jedan[2].first=str1[2]; 
            jedan[2].second=t1.Trougao::DajTjeme(2);
            dva[0].first=str2[0]; 
            dva[0].second=t2.Trougao::DajTjeme(3);
            dva[1].first=str2[1]; 
            dva[1].second=t2.Trougao::DajTjeme(1);
            dva[2].first=str2[2]; 
            dva[2].second=t2.Trougao::DajTjeme(2);
            
            pair<double, Tacka> *pok; 
            pok=jedan; 
            sort(pok, pok+3); 
            pok=dva; 
            sort(pok, pok+3); 
            if(Trougao::Orijentacija(jedan[0].second, jedan[1].second, jedan[2].second)!=Trougao::Orijentacija(dva[0].second, dva[1].second, dva[2].second))
                return false; 
            return true; 

    }
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
        pair<double, Tacka> jedan[3], dva[3]; 
        if(DaLiSuPodudarni(t1,t2)) return true;
         
            jedan[0].first=t1.Trougao::DuzinaStranice(t1.DajTjeme(1), t1.DajTjeme(2)); 
            jedan[0].second=t1.Trougao::DajTjeme(3); 
            jedan[1].first=t1.Trougao::DuzinaStranice(t1.DajTjeme(2), t1.DajTjeme(3)); 
            jedan[1].second=t1.Trougao::DajTjeme(1);
            jedan[2].first=t1.Trougao::DuzinaStranice(t1.DajTjeme(3), t1.DajTjeme(1)); 
            jedan[2].second=t1.Trougao::DajTjeme(2);
            dva[0].first=t2.Trougao::DuzinaStranice(t2.DajTjeme(1), t2.DajTjeme(2)); 
            dva[0].second=t2.Trougao::DajTjeme(3);
            dva[1].first=t2.Trougao::DuzinaStranice(t2.DajTjeme(2), t2.DajTjeme(3)); 
            dva[1].second=t2.Trougao::DajTjeme(1);
            dva[2].first=t2.Trougao::DuzinaStranice(t2.DajTjeme(3), t2.DajTjeme(1)); 
            dva[2].second=t2.Trougao::DajTjeme(2);
            pair<double, Tacka> *pok; 
            pok=jedan; 
            sort(pok, pok+3); 
            pok=dva; 
            sort(pok, pok+3); 
            if(Trougao::Orijentacija(jedan[0].second, jedan[1].second, jedan[2].second)!=Trougao::Orijentacija(dva[0].second, dva[1].second, dva[2].second))
                return false; 
            for(int i=0; i<=1; i++){
                if(fabs(jedan[i].first/dva[i].first-jedan[i+1].first/dva[i+1].first)>eps)
                return false;
            }
            return true; 
    }
};
Tacka Trougao::DajTjeme(int indeks) const{
    if(indeks==1) return T1; 
    if(indeks==2) return T2; 
    if(indeks==3) return T3; 
    throw range_error ("Nekorektan indeks");
}
double Trougao::DajStranicu(int indeks) const{
    Tacka prva, druga; 
    if(indeks==1) prva=T2, druga=T3; 
    else if(indeks==2) prva=T1, druga=T3; 
    else if(indeks==3) prva=T1, druga=T2; 
    else throw range_error ("Nekorektan indeks"); 
    return sqrt((prva.first-druga.first)*(prva.first-druga.first)+(prva.second-druga.second)*(prva.first-druga.second));
}
double Trougao::DajUgao(int indeks) const{
    int a, b, c; 
    if(indeks==1){
        a=1, b=2, c=3; 
    }
    else if(indeks==2){
        b=1, a=2, c=3; 
    }
    else if(indeks==3){
        c=1, a=2, b=3; 
    }
    else throw range_error ("Nekorektan indeks"); 
    return acos((DajStranicu(c)*DajStranicu(c)+DajStranicu(b)*DajStranicu(b)-DajStranicu(a)*DajStranicu(a))/(2*DajStranicu(b)*DajStranicu(c))); 
}
Tacka Trougao::DajCentar() const{
    Tacka izlaz; 
    izlaz.first=(T1.first+T2.first+T3.first)/3.;
    izlaz.second=(T1.second+T2.second+T3.second)/3.; 
    return izlaz; 
}
double Trougao::DajObim() const{
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3); 
}
double Trougao::DajPovrsinu() const{
    return fabs(T1.first*(T2.second-T3.second)-T2.first*(T1.second-T3.second)+T3.first*(T1.second-T2.second))/2;
}
bool Trougao::DaLiJePozitivnoOrijentiran() const{
    int izlaz=Orijentacija(T1, T3, T3);
    if(izlaz>0) return true; 
    return false; 
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
   double zbir, prva, druga, treca; 
   zbir=DajPovrsinu(); 
   prva=Povrsina(T1,T2,t); 
   druga=Povrsina(T1,T3,t); 
   treca=Povrsina(T2,T3,t); 
   if(fabs(prva)<eps || fabs(druga)<eps || fabs(treca)<eps) return false; 
   double a=prva+druga+treca; 
   return fabs(zbir-a)<eps;
}
void Trougao::Ispisi() const{
    cout << "((" << T1.first << "," << T1.second << "),(" << T2.first << "," << T2.second << "),(" << T3.first << "," << T3.second << "))"; 
}
void Trougao::Transliraj(double delta_x, double delta_y){
    T1.first=T1.first+delta_x; 
    T2.first=T2.first+delta_x; 
    T3.first=T3.first+delta_x; 
    T1.second=T1.second+delta_y; 
    T2.second=T2.second+delta_y; 
    T3.second=T3.second+delta_y; 
}
void Trougao::Centriraj(const Tacka &t){
    Tacka centar=DajCentar(); 
    double delta_x=t.first-centar.first; 
    double delta_y=t.second-centar.second; 
    Transliraj(delta_x,delta_y); 
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
    if(fabs(ugao)<eps) return;
    Tacka prva, druga, treca;  
    prva.first=t.first+(T1.first-t.first)*cos(ugao)-(T1.second-t.second)*sin(ugao); 
    prva.second=t.second+(T1.first-t.first)*sin(ugao)+(T1.second-t.second)*cos(ugao); 
    druga.first=t.first+(T2.first-t.first)*cos(ugao)-(T2.second-t.second)*sin(ugao); 
    druga.second=t.second+(T2.first-t.first)*sin(ugao)+(T2.second-t.second)*cos(ugao);
    treca.first=t.first+(T3.first-t.first)*cos(ugao)-(T3.second-t.second)*sin(ugao); 
    treca.second=t.second+(T3.first-t.first)*sin(ugao)+(T3.second-t.second)*cos(ugao);
    Postavi(prva, druga, treca); 
}
void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(fabs(faktor)<eps) throw domain_error ("Nekorektan faktor skaliranja"); 
    Tacka pom1(T1), pom2(T2), pom3(T3); 
    T1.first=t.first+faktor*(pom1.first-t.first); 
    T1.second=t.second+faktor*(pom1.second-t.second);
    T2.first=t.first+faktor*(pom2.first-t.first); 
    T2.second=t.second+faktor*(pom2.second-t.second);
    T3.first=t.first+faktor*(pom3.first-t.first); 
    T3.second=t.second+faktor*(pom3.second-t.second);
    if(faktor<0) Rotiraj(T1, 4*atan(1));
}
void Trougao::Rotiraj(double ugao){
    Tacka centar=DajCentar(); 
    Rotiraj(centar, ugao); 
}
void Trougao::Skaliraj(double faktor){
    Tacka centar=DajCentar(); 
    Skaliraj(centar,faktor); 
}
int main ()
{
    cout << "Koliko zelite kreirati trouglova: "; 
    int broj_trouglova; 
    cin >> broj_trouglova; 
    vector<shared_ptr<Trougao>> pokazivaci(broj_trouglova); 
    Tacka t1, t2, t3; 
    
    for(int i=0; i<broj_trouglova; i++){
        try{
        cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): "; 
        cin >> t1.first >> t1.second >> t2.first >> t2.second >> t3.first >> t3.second; 
        shared_ptr <Trougao> p(new Trougao(t1,t2,t3));
        pokazivaci[i]=p;
        }
        catch(domain_error poruka){
            cout << poruka.what() << ", ponovite unos!" << endl; 
            i--;
        }
    }
        cout << "Unesite vektor translacije (dx dy): "; 
        double dx, dy; 
        cin >> dx >> dy; 
    
        cout << "Unesite ugao rotacije: "; 
        double ugao_rotacije; 
        cin >> ugao_rotacije; 
   
        cout << "Unesite faktor skaliranja: "; 
        double faktor_skaliranja; 
        cin >> faktor_skaliranja; 
    try{
    transform(pokazivaci.begin(), pokazivaci.end(), pokazivaci.begin(), [dx,dy,ugao_rotacije,faktor_skaliranja] (shared_ptr<Trougao> trougao){
        trougao->Transliraj(dx,dy); 
        trougao->Rotiraj(ugao_rotacije); 
        trougao->Skaliraj(trougao->DajTjeme(1), faktor_skaliranja);
        return trougao; 
    });
    sort(pokazivaci.begin(), pokazivaci.end(), [](shared_ptr<Trougao> trougao1, shared_ptr<Trougao> trougao2){
        return trougao1->DajPovrsinu()<trougao2->DajPovrsinu(); 
    });
    cout << "Trouglovi nakon obavljenih transformacija: " << endl; 
    for_each(pokazivaci.begin(), pokazivaci.end(), [](shared_ptr<Trougao> trougao){
        trougao->Ispisi(); 
        cout << endl; 
    });
    }
    catch(domain_error poruka){
        cout << poruka.what(); 
    }
    catch(range_error poruka){
        cout << poruka.what();
    }
    cout << "Trougao sa najmanjim obimom: ";
    auto najmanji_obim=min_element(pokazivaci.begin(), pokazivaci.end(), [] (shared_ptr<Trougao> trougao1, shared_ptr<Trougao> trougao2)->bool{
        return trougao1->DajObim() < trougao2->DajObim(); 
    }); 
    (*najmanji_obim)->Trougao::Ispisi(); 
    cout << endl; 
    int brojac_identicnih=0; 
    for(int i=0; i<broj_trouglova; i++){
        for(int j=i; j<broj_trouglova; j++){
            if(i!=j)
            if(DaLiSuIdenticni(*pokazivaci[i], *pokazivaci[j])) brojac_identicnih++; 
        }
    }
if(brojac_identicnih!=0){
    cout << "Parovi identicnih trouglova: " << endl; 
    for(int i=0; i<broj_trouglova; i++){
        for(int j=i; j<broj_trouglova; j++){
            if(i!=j)
            if(DaLiSuIdenticni(*pokazivaci[i], *pokazivaci[j])){
                pokazivaci[i]->Trougao::Ispisi(); 
                cout << " i "; 
                pokazivaci[j]->Trougao::Ispisi();
                cout << endl; 
            }
        }
    } 
}
else cout << "Nema identicnih trouglova!" << endl;

    int brojac_podudarnih=0; 
    for(int i=0; i<broj_trouglova; i++){
        for(int j=i; j<broj_trouglova; j++){
            if(i!=j)
            if(DaLiSuPodudarni(*pokazivaci[i], *pokazivaci[j])) brojac_podudarnih++; 
        }
    }
if(brojac_podudarnih!=0){
    cout << "Parovi podudarnih trouglova: " << endl;  
    for(int i=0; i<broj_trouglova; i++){
        for(int j=i; j<broj_trouglova; j++){
            if(i!=j)
            if(DaLiSuPodudarni(*pokazivaci[i], *pokazivaci[j])){
                pokazivaci[i]->Trougao::Ispisi(); 
                cout << " i "; 
                pokazivaci[j]->Trougao::Ispisi(); 
                cout << endl; 
            }
        }
    } 
}
else cout << "Nema podudarnih trouglova!" << endl; 

    int brojac_slicnih=0; 
    for(int i=0; i<broj_trouglova; i++){
        for(int j=i; j<broj_trouglova; j++){
            if(i!=j)
            if(DaLiSuSlicni(*pokazivaci[i], *pokazivaci[j])) brojac_slicnih++; 
        }
    }
if(brojac_slicnih!=0){
    cout << "Parovi slicnih trouglova: " << endl; 
    for(int i=0; i<broj_trouglova; i++){
        for(int j=i; j<broj_trouglova; j++){
            if(i!=j)
            if(DaLiSuSlicni(*pokazivaci[i], *pokazivaci[j])){
                pokazivaci[i]->Trougao::Ispisi(); 
                cout << " i "; 
                pokazivaci[j]->Trougao::Ispisi(); 
                cout << endl; 
            }
        }
    } 
}
else cout << "Nema slicnih trouglova!"; 
    
    
	return 0;
}