/B 2016/2017, Zadaća 4, Zadatak 1

#include <iostream>
#include <stdexcept>
#include <utility>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory> 

typedef std::pair<double, double> Tacka;
const double eps = 1E-10;

class Trougao{
  Tacka t1, t2, t3;
  
  
public:
    
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);                 //gotov
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);            //gotov
    void Postavi(int indeks, const Tacka &t);                                   //gotov
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3); //gotov
    Tacka DajTjeme(int indeks) const;                                           //gotov
    double DajStranicu(int indeks) const;                                       //gotov
    double DajUgao(int indeks) const;                                           //gotov
    Tacka DajCentar() const;                                                    //gotov
    double DajObim() const;                                                     //gotov
    double DajPovrsinu() const;                                                 //gotov
    bool DaLiJePozitivnoOrijentiran() const;                                    //gotov
    bool DaLiJeUnutra(const Tacka &t) const;                                    //gotov
    void Ispisi() const;                                                        //gotov
    void Transliraj(double delta_x, double delta_y);                            //gotov
    void Centriraj(const Tacka &t);                                             //gotov
    void Rotiraj(const Tacka &t, double ugao);                                  //gotov
    void Skaliraj(const Tacka &t, double faktor);                               //gotov
    void Rotiraj(double ugao);                                                  //gotov
    void Skaliraj(double faktor);                                               //gotov
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);          //gotov
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);          //gotov
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);             //gotov
                                                                                //jos main zavrsiti(pametni pokazivaci!)
};

double Povrsina_trougla(Tacka t1, Tacka t2, Tacka t3){
    return 0.5 * fabs(std::get<0>(t1) * (std::get<1>(t2) - std::get<1>(t3)) - std::get<0>(t2) * (std::get<1>(t1) - std::get<1>(t3)) + std::get<0>(t3) * (std::get<1>(t1) - std::get<1>(t2)));
}

bool uporedi(double a, double b) {
    return fabs(a-b) < eps;
}

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
    Trougao::t1 = t1;
    Trougao::t2 = t2;
    Trougao::t3 = t3;
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    Trougao::t1 = t1;
    Trougao::t2 = t2;
    Trougao::t3 = t3;
}

void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    if(indeks == 1) Trougao::t1 = t;
    if(indeks == 2) Trougao::t2 = t;
    if(indeks == 3) Trougao::t3 = t;
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double orijentacija;
    orijentacija = std::get<0>(t1) * (std::get<1>(t2) - std::get<1>(t3)) - std::get<0>(t2) * (std::get<1>(t1) - std::get<1>(t3)) + std::get<0>(t3) * (std::get<1>(t1) - std::get<1>(t2)); 
    
    if(orijentacija < 0) return -1;
    else if(orijentacija > 0) return 1;
    else return 0;
}

Tacka Trougao::DajTjeme(int indeks) const{
    if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    if(indeks == 1) return Trougao::t1;
    if(indeks == 2) return Trougao::t2;
    else return Trougao::t3;
}

double Trougao::DajStranicu(int indeks) const{
    if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    double stranica;
    
    if(indeks == 1) {
        stranica = sqrt( (std::get<0>(Trougao::t3) - std::get<0>(Trougao::t2)) * (std::get<0>(Trougao::t3) -std::get<0>(Trougao::t2)) + (std::get<1>(Trougao::t3) - std::get<1>(Trougao::t2))*(std::get<1>(Trougao::t3) -std::get<1>(Trougao::t2)) );
    }
    
    if(indeks == 2) {
        stranica = sqrt( (std::get<0>(Trougao::t3) - std::get<0>(Trougao::t1)) * (std::get<0>(Trougao::t3) -std::get<0>(Trougao::t1)) + (std::get<1>(Trougao::t3) - std::get<1>(Trougao::t1))*(std::get<1>(Trougao::t3) -std::get<1>(Trougao::t1)) );
    }
    
    if(indeks == 3) {
        stranica = sqrt( (std::get<0>(Trougao::t2) - std::get<0>(Trougao::t1)) * (std::get<0>(Trougao::t2) -std::get<0>(Trougao::t1)) + (std::get<1>(Trougao::t2) - std::get<1>(Trougao::t1))*(std::get<1>(Trougao::t2) -std::get<1>(Trougao::t1)) );
    }
    
    return stranica;
    
}


double Trougao::DajUgao(int indeks) const{
    if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    double ugao;
    
    if(indeks == 1){
        ugao = acos( (pow(DajStranicu(1),2) - pow(DajStranicu(2), 2) - pow(DajStranicu(3), 2) ) / (-2 * DajStranicu(2) * DajStranicu(3) ) );
    }
    if(indeks == 2){
        ugao = acos( (pow(DajStranicu(2),2) - pow(DajStranicu(1), 2) - pow(DajStranicu(3), 2) ) / (-2 * DajStranicu(1) * DajStranicu(3) ) );
    }
    if(indeks == 3){
        ugao = acos( (pow(DajStranicu(3),2) - pow(DajStranicu(1), 2) - pow(DajStranicu(2), 2) ) / (-2 * DajStranicu(1) * DajStranicu(2) ) );
    }
    
    return ugao;
}

Tacka Trougao::DajCentar() const{
    Tacka centar;
    
    std::get<0>(centar) = (std::get<0>(Trougao::t1) + std::get<0>(Trougao::t2) + std::get<0>(Trougao::t3)) / 3;
    std::get<1>(centar) = (std::get<1>(Trougao::t1) + std::get<1>(Trougao::t2) + std::get<1>(Trougao::t3)) / 3;
    
    return centar;
}

double Trougao::DajObim() const{
    return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
}

double Trougao::DajPovrsinu() const{
    return 0.5 * fabs(std::get<0>(t1) * (std::get<1>(t2) - std::get<1>(t3)) - std::get<0>(t2) * (std::get<1>(t1) - std::get<1>(t3)) + std::get<0>(t3) * (std::get<1>(t1) - std::get<1>(t2)));
}

bool Trougao::DaLiJePozitivnoOrijentiran() const{
    if(Orijentacija(Trougao::t1,Trougao::t2,Trougao::t3) == 1) return true;
    else return false;
}

void Trougao::Ispisi() const{
    std::cout << "((" << std::get<0>(Trougao::t1) << "," << std::get<1>(Trougao::t1) << "),(" 
                       << std::get<0>(Trougao::t2) << "," << std::get<1>(Trougao::t2) << "),(" 
                       << std::get<0>(Trougao::t3) << "," << std::get<1>(Trougao::t3) << "))";
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    double P, P1, P2, P3;
    
    P = Povrsina_trougla(Trougao::t1, Trougao::t2, Trougao::t3);
    P1 = Povrsina_trougla(t, Trougao::t1, Trougao::t2);
    P2 = Povrsina_trougla(t, Trougao::t2, Trougao::t3);
    P3 = Povrsina_trougla(t, Trougao::t1, Trougao::t3);
    
    if(uporedi((P1 + P2 + P3), P)) return true;
    else return false;
}

void Trougao::Transliraj(double delta_x, double delta_y){
    std::get<0>(Trougao::t1) += delta_x; std::get<1>(Trougao::t1) += delta_y;
    std::get<0>(Trougao::t2) += delta_x; std::get<1>(Trougao::t2) += delta_y;
    std::get<0>(Trougao::t3) += delta_x; std::get<1>(Trougao::t3) += delta_y;
}

void Trougao::Centriraj(const Tacka &t){
    Tacka centar = DajCentar();
    double delta_x = std::get<0>(t) - std::get<0>(centar);
    double delta_y = std::get<1>(t) - std::get<1>(centar);
    Transliraj(delta_x, delta_y);
    
}

void Trougao::Rotiraj(const Tacka &t, double ugao){
    double x_c = std::get<0>(t);           double y_c = std::get<1>(t);
    double x_1 = std::get<0>(Trougao::t1); double y_1 = std::get<1>(Trougao::t1);
    double x_2 = std::get<0>(Trougao::t2); double y_2 = std::get<1>(Trougao::t2);
    double x_3 = std::get<0>(Trougao::t3); double y_3 = std::get<1>(Trougao::t3);
    
    std::get<0>(Trougao::t1) = x_c + (x_1 - x_c) * cos(ugao) - (y_1 - y_c) * sin(ugao);
    std::get<1>(Trougao::t1) = y_c + (x_1 - x_c) * sin(ugao) + (y_1 - y_c) * cos(ugao);
    
    std::get<0>(Trougao::t2) = x_c + (x_2 - x_c) * cos(ugao) - (y_2 - y_c) * sin(ugao);
    std::get<1>(Trougao::t2) = y_c + (x_2 - x_c) * sin(ugao) + (y_2 - y_c) * cos(ugao);
    
    std::get<0>(Trougao::t3) = x_c + (x_3 - x_c) * cos(ugao) - (y_3 - y_c) * sin(ugao);
    std::get<1>(Trougao::t3) = y_c + (x_3 - x_c) * sin(ugao) + (y_3 - y_c) * cos(ugao);
}

void Trougao::Skaliraj(const Tacka &t, double faktor){
    
    if(uporedi(faktor, 0)) throw std::domain_error("Nekorektan faktor skaliranja");
    
    double x_c = std::get<0>(t);
    double y_c = std::get<1>(t);
    
    std::get<0>(Trougao::t1) = x_c + faktor * (std::get<0>(Trougao::t1) - x_c);
    std::get<1>(Trougao::t1) = y_c + faktor * (std::get<1>(Trougao::t1) - y_c);
    
    std::get<0>(Trougao::t2) = x_c + faktor * (std::get<0>(Trougao::t2) - x_c);
    std::get<1>(Trougao::t2) = y_c + faktor * (std::get<1>(Trougao::t2) - y_c);
    
    std::get<0>(Trougao::t3) = x_c + faktor * (std::get<0>(Trougao::t3) - x_c);
    std::get<1>(Trougao::t3) = y_c + faktor * (std::get<1>(Trougao::t3) - y_c);
}

void Trougao::Rotiraj(double ugao){
    Tacka centar = DajCentar();
    Rotiraj(centar, ugao);
}

void Trougao::Skaliraj(double faktor){
    Tacka centar = DajCentar();
    Skaliraj(centar, faktor);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    bool identicni(false);
 if(t1.t1 ==t2.t1 || t1.t1 == t2.t2 || t1.t1 == t2.t3){
     if(t1.t2 == t2.t1 || t1.t2 ==t2.t2 || t1.t2 == t2.t3 ){
        if(t1.t3 == t2.t1 || t1.t3 == t2.t2 || t1.t3 == t2.t3)
            identicni = true;
     }
 }   
 
 return identicni;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    
    int brojac; 
    brojac = 0;
    
    Tacka tacka1;
    Tacka tacka2;
    Tacka tacka3;
    
    for(int i=1; i<4; i++){
        for(int j=1; j<4; j++){
            if(uporedi(t1.DajUgao(i),t2.DajUgao(j)) && uporedi(t1.DajStranicu(i), t2.DajStranicu(j))){
                if(brojac == 0) tacka1 = t2.DajTjeme(j);
                if(brojac == 1) tacka2 = t2.DajTjeme(j);
                if(brojac == 2) tacka3 = t2.DajTjeme(j);
                brojac += 1;
                break;
            }    
        }
    }
    Trougao pomocni(t1);
    if(brojac == 3) pomocni.Postavi(tacka1, tacka2, tacka3);
    return (t1.DaLiJePozitivnoOrijentiran() == pomocni.DaLiJePozitivnoOrijentiran() && brojac == 3);
}



bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    int brojac; 
    brojac = 0;
    Tacka tacka1;
    Tacka tacka2;
    Tacka tacka3;
    
    for(int i=1; i<4; i++){
        for(int j=1; j<4; j++){
            if(uporedi(t1.DajUgao(i),t2.DajUgao(j)) ){
                if(brojac == 0) tacka1 = t2.DajTjeme(j);
                if(brojac == 1) tacka2 = t2.DajTjeme(j);
                if(brojac == 2) tacka3 = t2.DajTjeme(j);
                brojac += 1;
                break;
            }    
        }
    }
    Trougao pomocni(t1);
    if(brojac == 3) pomocni.Postavi(tacka1, tacka2, tacka3);
    return (t1.DaLiJePozitivnoOrijentiran() == pomocni.DaLiJePozitivnoOrijentiran() && brojac == 3);
    
}



int main (){
      
   int n;
   std::cout << "Koliko zelite kreirati trouglova: ";
   std::cin >> n;
   
   double x1, y1, x2, y2, x3, y3;
   Tacka t1, t2, t3;
   std::vector<std::shared_ptr<Trougao>> Trouglovi(n, nullptr);
   
   for(int i=0; i<n; i++){
       try{
       std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
       std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
       t1 = std::make_pair(x1, y1);
       t2 = std::make_pair(x2, y2);
       t3 = std::make_pair(x3, y3);
       Trouglovi[i] = std::shared_ptr<Trougao> (new Trougao(t1,t2,t3)) ;
       }
       catch(std::domain_error e){
           std::cout << "Nekorektne pozicije tjemena, ponovite unos! " << std::endl;
           i--;
       }
   }
   
   std::cout << "Unesite vektor translacije (dx dy): ";
   double dx, dy;
   std::cin >> dx >> dy;
   
   std::cout << "Unesite ugao rotacije: ";
   double ugao;
   std::cin >> ugao;
   
   std::cout << "Unesite faktor skaliranja: ";
   double faktor;
   std::cin >> faktor;
   
   std::transform(Trouglovi.begin(), Trouglovi.end(), Trouglovi.begin(), [dx, dy, ugao, faktor] (const std::shared_ptr<Trougao> &t1) { t1 ->Transliraj(dx,dy); t1 ->Rotiraj(ugao); t1->Skaliraj(t1->DajTjeme(1), faktor); return t1; });
   
   std::sort(Trouglovi.begin(), Trouglovi.end(), [] (const std::shared_ptr<Trougao> t1, const std::shared_ptr<Trougao> t2) -> bool {return (t1->DajPovrsinu() < t2->DajPovrsinu());} );
   
   std::cout << "Trouglovi nakon obavljenih transformacija: " << std::endl; 
   
   std::for_each(Trouglovi.begin(), Trouglovi.end(), [](const std::shared_ptr<Trougao> &t) {t -> Ispisi(); std::cout << std::endl; });
   
   std::cout << "Trougao sa najmanjim obimom: ";
   auto najmanji(*std::min_element(Trouglovi.begin(), Trouglovi.end(), [](const std::shared_ptr<Trougao>t1, const std::shared_ptr<Trougao>t2)->bool{return t1->DajObim()<t2->DajObim();} ));
   najmanji->Ispisi();  std::cout << std::endl;
   
   //za identicne
   std::vector<std::pair<Trougao, Trougao>> identicni;
   for(int i=0; i<n; i++){
       for(int j=i+1; j<n; j++){
           if(DaLiSuIdenticni(*Trouglovi[i], *Trouglovi[j]) == true && i != j){
               identicni.push_back(std::make_pair(*Trouglovi[i], *Trouglovi[j]));
           }
       }
   }
   if(identicni.size() == 0) std::cout << "Nema identicnih trouglova!" << std::endl;
   else {
       std::cout<<"Parovi identicnih trouglova: " << std::endl;
    for(int i=0; i<identicni.size(); i++){
       (std::get<0>(identicni[i])).Ispisi(); std::cout << " i "; (std::get<1>(identicni[i])).Ispisi(); std::cout << std::endl;
    }
   }
   //za podudarne
   std::vector<std::pair<Trougao, Trougao>> podudarni;
   for(int i=0; i<n; i++){
       for(int j=i+1; j<n; j++){
           if(DaLiSuPodudarni(*Trouglovi[i], *Trouglovi[j]) == true && i != j){
               podudarni.push_back(std::make_pair(*Trouglovi[i], *Trouglovi[j]));
           }
       }
   }
   if(podudarni.size() == 0) std::cout << "Nema podudarnih trouglova!" << std::endl;
   else {
       std::cout<<"Parovi podudarnih trouglova: " << std::endl;
    for(int i=0; i<podudarni.size(); i++){
       (std::get<0>(podudarni[i])).Ispisi(); std::cout << " i "; (std::get<1>(podudarni[i])).Ispisi(); std::cout << std::endl;
    }
   }
   //za slicne
   std::vector<std::pair<Trougao, Trougao>> slicni;
   for(int i=0; i<n; i++){
       for(int j=i+1; j<n; j++){
           if(DaLiSuSlicni(*Trouglovi[i], *Trouglovi[j]) == true && i != j){
               slicni.push_back(std::make_pair(*Trouglovi[i], *Trouglovi[j]));
           }
       }
   }
   if(slicni.size() == 0) std::cout << "Nema slicnih trouglova!" <<  std::endl;
   else {
       std::cout<<"Parovi slicnih trouglova: " << std::endl;
    for(int i=0; i<slicni.size(); i++){
       (std::get<0>(slicni[i])).Ispisi(); std::cout << " i "; (std::get<1>(slicni[i])).Ispisi(); std::cout << std::endl;
    }
   }
	return 0;
}