/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<stdexcept>
#include<iomanip>
#include<vector>
#include<memory>
#include<algorithm>
#include<utility>
#include<cmath>
#include<math.h>
using namespace std;
typedef std::pair<double, double> Tacka;
class Trougao{
    Tacka t1;
    Tacka t2;
    Tacka t3;
    public:
Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3) == 0) throw domain_error("Nekorektne pozicije tjemena");
    Trougao::t1 = t1;
    Trougao::t2 = t2;
    Trougao::t3 = t3;
}
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
     if(Orijentacija(t1,t2,t3) == 0) throw domain_error("Nekorektne pozicije tjemena");
    Trougao::t1 = t1;
    Trougao::t2 = t2;
    Trougao::t3 = t3;
}
void Postavi(int indeks, const Tacka &t){
    if(indeks == 1){ t1 = t; t2 = t2; t3 = t3;  if(Orijentacija(t1,t2,t3) == 0) throw domain_error("Nekorektne pozicije tjemena");}
    if(indeks == 2){ t1 = t1; t2 = t; t3 = t3;  if(Orijentacija(t1,t2,t3) == 0) throw domain_error("Nekorektne pozicije tjemena");}
    if(indeks == 3){ t1 = t1; t2 = t2; t3 = t;  if(Orijentacija(t1,t2,t3) == 0) throw domain_error("Nekorektne pozicije tjemena");}
    if(indeks !=1 && indeks !=2 && indeks !=3) throw range_error("Nekorektan indeks");
}
static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double izraz =  t1.first*(t2.second-t3.second)-t2.first*(t1.second - t3.second) + t3.first*(t1.second-t2.second);
    if(izraz > 0) return 1;
    if(izraz < 0) return -1;
    return 0;
}
Tacka DajTjeme(int indeks) const{ 
    if(indeks == 1){ return Trougao::t1; }
    if(indeks == 2){ return Trougao::t2; }
    if(indeks == 3){ return Trougao::t3; }
    if(indeks !=1 && indeks !=2 && indeks !=3) throw range_error("Nekorektan indeks");
    return t1; //da vrati sta bilo zbog povratng tipa//
}
double DajStranicu(int indeks) const{
    double stranica;
    if(indeks !=1 && indeks !=2 && indeks !=3) throw range_error("Nekorektan indeks");
    if(indeks == 1){ stranica = sqrt((t3.first - t2.first)*(t3.first - t2.first) + (t3.second - t2.second)*(t3.second - t2.second)); }
    if(indeks == 2){ stranica = sqrt((t3.first - t1.first)*(t3.first - t1.first) + (t3.second - t1.second)*(t3.second - t1.second)); }
    if(indeks == 3){ stranica = sqrt((t2.first - t1.first)*(t2.first - t1.first) + (t2.second - t1.second)*(t2.second - t1.second)); }
    return stranica;
}
double DajUgao(int indeks) const{
     double ugao(0.0);
    if(indeks !=1 && indeks !=2 && indeks !=3) throw range_error("Nekorektan indeks");
    if(indeks == 1){ 
    double privremena = (DajStranicu(3)*DajStranicu(3) + DajStranicu(2)*DajStranicu(2) - DajStranicu(1)*DajStranicu(1))/2*DajStranicu(3)*DajStranicu(2);
    privremena = acos(privremena);
    }
    if(indeks == 2){ 
    double privremena = (DajStranicu(1)*DajStranicu(1) + DajStranicu(3)*DajStranicu(3) - DajStranicu(2)*DajStranicu(2))/2*DajStranicu(1)*DajStranicu(3);
    privremena = acos(privremena);
    }
    if(indeks == 3){ 
    double privremena = (DajStranicu(1)*DajStranicu(1) + DajStranicu(2)*DajStranicu(2) - DajStranicu(3)*DajStranicu(3))/2*DajStranicu(1)*DajStranicu(2);
    privremena = acos(privremena);
    }
    return ugao;
}
Tacka DajCentar() const{
    double centa = (t1.first + t2.first + t3.first)/3;
    double centari = (t1.second + t2.second + t3.second)/3;
    Tacka centar;
    centar.first = centa;
    centar.second = centari;
    return centar;
}
double DajObim() const{
    double obim(0.0);
    obim = DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
    return obim;
}
double DajPovrsinu() const{
    double povrsina = (t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second) + t3.first*(t1.second-t2.second))/2;
    if(povrsina < 0) povrsina *=-1;
    return povrsina;
}
bool DaLiJePozitivnoOrijentiran() const{
    bool pozitivno(false);
    if(Orijentacija(t1,t2,t3) == 1)pozitivno = true;
    return pozitivno;
}
bool DaLiJeUnutra(const Tacka &t) const{
    bool unutra(false);
    if(Orijentacija(t1, t2, t3) == Orijentacija(t, t2, t3) && Orijentacija(t1, t2, t3) == Orijentacija(t1, t, t3) && Orijentacija(t1, t2, t3)==Orijentacija(t1,t2,t))unutra = true;
    return unutra;
}
void Ispisi() const{ cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";}
void Transliraj(double delta_x, double delta_y){
    t1.first += delta_x;
    t1.second +=delta_y;
    t2.first += delta_x;
    t2.second +=delta_y;
    t3.first += delta_x;
    t3.second +=delta_y;
}
void Centriraj(const Tacka &t){
    Tacka centar = DajCentar();
    double delta_x = t.first - centar.first;
    double delta_y = t.second - centar.second;
    Trougao::Transliraj(delta_x, delta_y);
}
void Rotiraj(const Tacka &t, double ugao){
    Tacka prva(t1), druga(t2), treca(t3);
    t1.first = t.first +(prva.first-t.first)*cos(ugao)-(prva.second-t.second)*sin(ugao);
    t1.second =t.second + (prva.first-t.first)*sin(ugao) + (prva.second-t.second)*cos(ugao);
    t2.first = t.first +(druga.first -t.first)*cos(ugao) - (druga.second-t.second)*sin(ugao);
    t2.second =t.second + (druga.first - t.first)*sin(ugao) + (druga.second-t.second)*cos(ugao);
    t3.first = t.first +(treca.first - t.first)*cos(ugao) - (treca.second-t.second)*sin(ugao);
    t3.second =t.second + (treca.first - t.first)*sin(ugao) + (treca.second-t.second)*cos(ugao);
}
void Skaliraj(const Tacka &t, double faktor){
   if(fabs(faktor - 0) <= 1e-10*(fabs(faktor) - fabs(0))) throw domain_error("Nekorektan faktor skaliranja");
    Tacka t11(t1), t22(t2), t33(t3);
    t1.first = t.first + faktor*(t11.first - t.first);
    t1.second = t.second + faktor*(t11.second - t.second);
    t2.first = t.first + faktor*(t22.first - t.first);
    t2.second = t.second + faktor*(t22.second - t.second);
    t3.first = t.first + faktor*(t33.first - t.first);
    t3.second = t.second + faktor*(t33.second - t.second);
}
void Rotiraj(double ugao){
    Tacka t = DajCentar();
      Tacka t11(t1), t22(t2), t33(t3);
    t1.first = t.first +(t11.first - t.first)*cos(ugao) -(t11.second - t.second)*sin(ugao);
    t1.second =t.second + (t11.first - t.first)*sin(ugao) + (t11.second - t.second)*cos(ugao);
    t2.first = t.first +(t22.first - t.first)*cos(ugao) - (t22.second - t.second)*sin(ugao);
    t2.second =t.second + (t22.first - t.first)*sin(ugao) + (t22.second - t.second)*cos(ugao);
    t3.first = t.first +(t33.first - t.first)*cos(ugao) -(t33.second - t.second)*sin(ugao);
    t3.second =t.second + (t33.first - t.first)*sin(ugao) + (t33.second - t.second)*cos(ugao);
}
void Skaliraj(double faktor){
    if(fabs(faktor - 0) <= 1e-10*(fabs(faktor) - fabs(0))) throw domain_error("Nekorektan faktor skaliranja");
    Tacka t = DajCentar();
     Tacka t11(t1), t22(t2), t33(t3);
    t1.first = t.first + faktor*(t11.first - t.first);
    t1.second = t.second + faktor*(t11.second - t.second);
    t2.first = t.first + faktor*(t22.first - t.first);
    t2.second = t.second + faktor*(t22.second - t.second);
    t3.first = t.first + faktor*(t33.first - t.first);
    t3.second = t.second + faktor*(t33.second - t.second);
    
}
friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    bool identicni(false);
  //sortiraj tacke trouglova//
  vector<Tacka> tackeprvog(3);
  tackeprvog[0] = t1.DajTjeme(1);
  tackeprvog[1] = t1.DajTjeme(2);
  tackeprvog[2] = t1.DajTjeme(3);
  vector<Tacka> tackedrugog(3);
  tackedrugog[0] = t2.DajTjeme(1);
  tackedrugog[1] = t2.DajTjeme(2);
  tackedrugog[2] = t2.DajTjeme(3);
  for(int i=0; i<3; i++){
      for(int j=i+1; j<3; j++){
          if(tackeprvog[i] > tackeprvog[j]){
              Tacka privremena = tackeprvog[i];
              tackeprvog[i] = tackeprvog[j];
              tackeprvog[j] = privremena;
          }
           if(tackedrugog[i] > tackedrugog[j]){
              Tacka privremena = tackedrugog[i];
              tackedrugog[i] = tackedrugog[j];
              tackedrugog[j] = privremena;
          }
      }
  }
  //nadji identicne stranice i koliko ih ima//
  int brojac = 0;
 if((fabs(tackeprvog[0].first - tackedrugog[0].first) <= 1e-10 * (fabs(tackeprvog[0].first) - fabs(tackedrugog[0].first))) 
 && (fabs(tackeprvog[0].second - tackedrugog[0].second) <= 1e-10 * (fabs(tackeprvog[0].second) - fabs(tackedrugog[0].second))))brojac++;
  if((fabs(tackeprvog[1].first - tackedrugog[1].first) <= 1e-10 * (fabs(tackeprvog[1].first) - fabs(tackedrugog[1].first))) 
 && (fabs(tackeprvog[1].second - tackedrugog[1].second) <= 1e-10 * (fabs(tackeprvog[1].second) - fabs(tackedrugog[1].second))))brojac++;
  if((fabs(tackeprvog[2].first - tackedrugog[2].first) <= 1e-10 * (fabs(tackeprvog[2].first) - fabs(tackedrugog[2].first))) 
 && (fabs(tackeprvog[2].second - tackedrugog[2].second) <= 1e-10 * (fabs(tackeprvog[2].second) - fabs(tackedrugog[2].second))))brojac++;
    if(brojac == 3){
          identicni=true;
    }
    return identicni;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    bool podudarni(false);
    //parovi za tacke i nasuprotne stranice//
     vector<pair<Tacka, double>> prviparovi;
    prviparovi.push_back(make_pair(t1.t1,t1.DajStranicu(1)));
    prviparovi.push_back(make_pair(t1.t2,t1.DajStranicu(2)));
    prviparovi.push_back(make_pair(t1.t3,t1.DajStranicu(3)));
    vector<pair<Tacka, double>> drugiparovi;
    drugiparovi.push_back(make_pair(t2.t1,t2.DajStranicu(1)));
    drugiparovi.push_back(make_pair(t2.t2,t2.DajStranicu(2)));
    drugiparovi.push_back(make_pair(t2.t3,t2.DajStranicu(3)));
    //brojac istih stranica//
    int brojac = 0;
    //sortiranje vektora//
    for( int i = 0; i < 3; i++){
        for( int j = i+1; j < 3; j++){
            if(prviparovi[i].second > prviparovi[j].second){
                double privremena = prviparovi[i].second;
                Tacka temp = prviparovi[i].first;
                prviparovi[i].second = prviparovi[j].second;
                prviparovi[i].first = prviparovi[j].first;
                prviparovi[j].second = privremena;
                prviparovi[j].first = temp;
            }
        }
    }
      for( int i = 0; i < 3; i++){
        for( int j = i+1; j < 3; j++){
            if(drugiparovi[i].second > drugiparovi[j].second){
                double privremena = drugiparovi[i].second;
                Tacka temp = drugiparovi[i].first;
                drugiparovi[i].second = drugiparovi[j].second;
                drugiparovi[i].first = drugiparovi[j].first;
                drugiparovi[j].second = privremena;
                drugiparovi[j].first = temp;
            }
        }
    }
    if((fabs(prviparovi[0].second - drugiparovi[0].second)) <= 1e-10 * (fabs(prviparovi[0].second) - fabs(drugiparovi[0].second))) brojac++; 
    if((fabs(prviparovi[1].second - drugiparovi[1].second)) <= 1e-10 * (fabs(prviparovi[1].second) - fabs(drugiparovi[1].second))) brojac++; 
     if((fabs(prviparovi[2].second - drugiparovi[2].second)) <= 1e-10 * (fabs(prviparovi[2].second) - fabs(drugiparovi[2].second))) brojac++; 
    //provjeri orijentaciju//
    if(brojac == 3){
        if(t1.Orijentacija(prviparovi[0].first, prviparovi[1].first, prviparovi[2].first) == t2.Orijentacija(drugiparovi[0].first, drugiparovi[1].first, drugiparovi[2].first))
        podudarni = true;
    }
    return podudarni;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    bool slicni(false);
     //parovi za tacke i nasuprotne stranice//
     vector<pair<Tacka, double>> prviparovi;
    prviparovi.push_back(make_pair(t1.t1,t1.DajStranicu(1)));
    prviparovi.push_back(make_pair(t1.t2,t1.DajStranicu(2)));
    prviparovi.push_back(make_pair(t1.t3,t1.DajStranicu(3)));
    vector<pair<Tacka, double>> drugiparovi;
    drugiparovi.push_back(make_pair(t2.t1,t2.DajStranicu(1)));
    drugiparovi.push_back(make_pair(t2.t2,t2.DajStranicu(2)));
    drugiparovi.push_back(make_pair(t2.t3,t2.DajStranicu(3)));
    //sortiranje vektora//
    for( int i = 0; i < 3; i++){
        for( int j = i+1; j < 3; j++){
            if(prviparovi[i].second > prviparovi[j].second){
                double privremena = prviparovi[i].second;
                Tacka temp = prviparovi[i].first;
                prviparovi[i].second = prviparovi[j].second;
                prviparovi[i].first = prviparovi[j].first;
                prviparovi[j].second = privremena;
                prviparovi[j].first = temp;
            }
        }
    }
      for( int i = 0; i < 3; i++){
        for( int j = i+1; j < 3; j++){
            if(drugiparovi[i].second > drugiparovi[j].second){
                double privremena = drugiparovi[i].second;
                Tacka temp = drugiparovi[i].first;
                drugiparovi[i].second = drugiparovi[j].second;
                drugiparovi[i].first = drugiparovi[j].first;
                drugiparovi[j].second = privremena;
                drugiparovi[j].first = temp;
            }
        }
    }
    //nadji odnose jedne stranice prvog trougla i ostalih stranica drugog trougla//
    double odnos1 = prviparovi[0].second / drugiparovi[0].second;
    double odnos2 = prviparovi[1].second / drugiparovi[1].second;
    double odnos3 = prviparovi[2].second / drugiparovi[2].second;
    // trazi petljom tri ista odnosa//
    int brojac1 = 0, brojac2 = 0, brojac3 = 0; 
     for(int i = 0; i < 3; i++){
       for(int j = 0; j < 3; j++){
            if(prviparovi[i].second / drugiparovi[j].second == odnos1){ brojac1++; break; }
            if(prviparovi[i].second / drugiparovi[j].second == odnos2){ brojac2++; break; }
            if(prviparovi[i].second / drugiparovi[j].second == odnos3){ brojac3++; break; }
        }
    }
    //provjeri orijentaciju//
     if(brojac1 == 3 || brojac2 ==3 || brojac3 ==3){
        if(t1.Orijentacija(prviparovi[0].first, prviparovi[1].first, prviparovi[2].first) == t2.Orijentacija(drugiparovi[0].first, drugiparovi[1].first, drugiparovi[2].first))
        slicni = true;
    }
    return slicni;
}
int main ()
{
    cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    cin>>n;
    vector<shared_ptr<Trougao>> vektor;
    int i=0; 
    while(i < n){
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        double prva1, prva2, druga1, druga2, treca1, treca2;
        cin>>prva1>>prva2>>druga1>>druga2>>treca1>>treca2;
        Tacka t1 = make_pair(prva1, prva2);
        Tacka t2 = make_pair(druga1, druga2);
        Tacka t3 = make_pair(treca1, treca2);
        shared_ptr<Trougao> pokazivac;
        try{
            pokazivac = make_shared<Trougao> (t1, t2, t3);
        }
        catch(...){
            cout<<"Nekorektne pozicije tjemena, ponovite unos!"<<endl;
            continue;
        }
        vektor.push_back(pokazivac);
        i++;
    }
    cout<<"Unesite vektor translacije (dx dy): ";
    double delta_x, delta_y;
    cin>>delta_x>>delta_y;
    cout<<"Unesite ugao rotacije: ";
    double ugaorotacije;
    cin>>ugaorotacije;
    cout<<"Unesite faktor skaliranja: ";
    double faktor;
    cin>>faktor;
    transform(vektor.begin(), vektor.end(), vektor.begin(), [delta_x, delta_y, ugaorotacije, faktor](shared_ptr<Trougao> trougao){
        (*trougao).Transliraj(delta_x, delta_y);
        (*trougao).Rotiraj(ugaorotacije);
        (*trougao).Skaliraj((*trougao).DajTjeme(1), faktor);
        return trougao;
    });
    sort(vektor.begin(), vektor.end(), [](shared_ptr<Trougao> trougao1, shared_ptr<Trougao> trougao2){ return (*trougao1).DajPovrsinu() < (*trougao2).DajPovrsinu(); });
    cout<<"Trouglovi nakon obavljenih transformacija:"<<endl;
    for_each(vektor.begin(), vektor.end(), [](shared_ptr<Trougao> trougao){ (*trougao).Ispisi(); cout<<endl;});
    cout<<"Trougao sa najmanjim obimom: ";
    auto najmanji = max_element(vektor.begin(), vektor.end(), [](shared_ptr<Trougao> trougao1, shared_ptr<Trougao> trougao2){ return (*trougao1).DajObim() > (*trougao2).DajObim(); });
    (*najmanji)->Ispisi();
    cout<<endl;
    int imapodudarnih=0, imaslicnih=0, imaidenticnih=0;
    for(int i=0; i<vektor.size(); i++){
        for(int j=i+1; j<vektor.size(); j++){
            if(DaLiSuIdenticni(*vektor[i], *vektor[j]) == true)imaidenticnih++;
            if(DaLiSuPodudarni(*vektor[i], *vektor[j]) == true)imapodudarnih++;
            if(DaLiSuSlicni(*vektor[i], *vektor[j]) == true)imaslicnih++;
        }
    }
    if(imaidenticnih == 0)cout<<"Nema identicnih trouglova!"<<endl;
    if(imapodudarnih == 0)cout<<"Nema podudarnih trouglova!"<<endl;
    if(imaslicnih == 0)cout<<"Nema slicnih trouglova!"<<endl;
    if(imaidenticnih !=0){
        cout<<"Parovi identicnih trouglova:"<<endl;
        for(int i=0; i<vektor.size(); i++){
            for(int j=i+1; j<vektor.size(); j++){
             if(DaLiSuIdenticni(*vektor[i], *vektor[j]) == true){ (*vektor[i]).Ispisi(); cout<<" i "; (*vektor[j]).Ispisi(); cout<<endl; }
        }
    }
    }
      if(imapodudarnih !=0){
        cout<<"Parovi podudarnih trouglova:"<<endl;
        for(int i=0; i<vektor.size(); i++){
            for(int j=i+1; j<vektor.size(); j++){
             if(DaLiSuPodudarni(*vektor[i], *vektor[j]) == true){ (*vektor[i]).Ispisi(); cout<<" i "; (*vektor[j]).Ispisi(); cout<<endl; }
        }
    }
    }
    if(imaslicnih !=0){
        cout<<"Parovi slicnih trouglova:"<<endl;
        for(int i=0; i<vektor.size(); i++){
            for(int j=i+1; j<vektor.size(); j++){
             if(DaLiSuSlicni(*vektor[i], *vektor[j]) == true){ (*vektor[i]).Ispisi(); cout<<" i "; (*vektor[j]).Ispisi(); cout<<endl; }
        }
    }
    }
  
  
	return 0;
}