/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <cmath>
#include <stdexcept>

typedef std::pair<double, double> Tacka;

const double pi = 4 * atan(1);

double Duzina(Tacka t1, Tacka t2) {
    double c = sqrt(pow(t1.first - t2.first, 2) + pow(t1.second - t2.second, 2));
    return c;
}

class Trougao {
    Tacka prva, druga, treca;
public:
  Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
      
      if((Duzina(t1,t2)+Duzina(t2,t3) <= Duzina(t3,t1)) || (Duzina(t2,t3)+Duzina(t3,t1) <= Duzina(t3,t1)) || (Duzina(t3,t1) + Duzina(t1,t2) <= Duzina(t2,t3))) throw std::domain_error("Nekorektne pozicije tjemena");
        
        prva.first = t1.first; prva.second = t1.second;
        druga.first = t2.first; druga.second = t2.second;
        treca.first = t3.first; treca.second = t3.second;
      
  } 
  
  void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
      
      prva.first = t1.first; prva.second = t1.second;
      druga.first = t2.first; druga.second = t2.second; 
      treca.first = t3.first; treca.second = t3.second; 
  }
 
 
  void Postavi(int indeks, const Tacka &t) { 
             if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    
                    if(indeks == 1) {
                        prva.first = t.first; prva.second = t.second;
                    }
                    
                    else if(indeks == 2) {
                        druga.first = t.first; druga.second = t.second;
                    }
                    
                    else{
                        treca.first = t.first; treca.second = t.second;
                    }
  }
  
  
  static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
      int ori = t1.first*(t2.second - t3. second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second);
      if(ori>0) return 1;
      else if(ori<0) return -1;
  }

  Tacka DajTjeme(int indeks) const { 
        
         if(indeks<1 || indeks >3) throw std::range_error("Nekorektan indeks");
   
                if(indeks == 1) return prva;
                
                else if(indeks == 2) return druga;
                
                else return treca;
      
  }
      
      
  double DajStranicu(int indeks) const {
             if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
                 double str;
                 if(indeks == 1) {
          
                     str = Duzina(druga, treca);
                      return str;
                } 
      
            else if(indeks == 2) {
                    str = Duzina (prva, treca);
                     return str;
                }
            else {
                str = Duzina(prva, druga);
                return str;
      }
  }
  
  
  double DajUgao(int indeks) const {
      if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indkes");
      double str1 = Duzina(druga, treca);
      double str2 = Duzina(treca, prva);
      double str3 = Duzina(prva, druga);
      
      if(indeks == 1) {
          double alfa = acos (pow(str2, 2) + pow(str3, 2) - pow(str1, 2) / (2* str2 * str3));
          alfa = alfa * (180 / pi);
          return alfa;
      }
      
      else if(indeks == 2) {
          double beta = acos(pow(str1, 2) + pow(str3, 2) - pow(str2, 2) / (2* str1 * str3));
          beta = beta * (180 / pi);
          return beta;
      }
      else {
          double gama = acos(pow(str2, 2) + pow(str1, 2) - pow(str3, 2) / (2* str2 * str1));
          gama = gama * (180 / pi);
          return gama;
      }
      
  }
  
  Tacka DajCentar() const {
      double c1 = (prva.first + druga.first + treca.first)/3;
      double c2 = (prva.second + druga.second + treca.second)/3;
      Tacka centar = std::make_pair(c1,c2);
      return centar;
  }
  
  
  
  double DajObim() const {
      double str1 = Duzina(druga, treca);
      double str2 = Duzina(prva, treca);
      double str3 = Duzina(prva, druga);
      double obim = str1 + str2 + str3;
      return obim; 
  }
  double DajPovrsinu() const { 
  
      double povrsina;
      povrsina = prva.first*(druga.second - treca.second) - druga.first*(prva.second - treca.second) + treca.first(prva.second - druga.second);
      return povrsina;
  }
  bool DaLiJePozitivnoOrijentiran() const{
      
  }
  
  bool DaLiJeUnutra(const Tacka &t) const {
      
  }
 
  void Ispisi() const {
      std::cout<<"(("<<prva.first<<","<<prva.second<<"), ("<<druga.first<<","<<druga.second<<"), ("<<treca.first<<","<<treca.second<<"))";
  }
  
  void Transliraj(double delta_x, double delta_y) {
      prva.first += delta_x;
      druga.first += delta_x;
      treca.first += delta_x;
      
      prva.second += delta_y;
      druga.second += delta_y;
      treca.second += delta_y;
  }
  void Centriraj(const Tacka &t) {
      double razlika_x = t.first - prva.first;  // ovdje treba centar
      double razlika_y = t.second - prva.second;
      Transliraj(razlika_x, razlika_y);
  }
  
  void Rotiraj(double Tacka &t, double ugao) {
      prva.first = t.first + (prva.first - t.first)*cos(ugao) - (prva.second - t.second)*sin(ugao);
      prva.second = t.second + (prva.first - t.first)*sin(ugao) + (prva.second - t.second)*cos(ugao);
      
      druga.first = t.first + (druga.first - t.first)*cos(ugao) - (druga.second - t.second)*sin(ugao);
      druga.second = t.second + (druga.first - t.first)*sin(ugao) + (druga.second - t.second)*cos(ugao);
      
      treca.first = t.first + (treca.first - t.first)*cos(ugao) - (treca.second - t.second)*sin(ugao);
      treca.second = t.second + (treca.first - t.first)*sin(ugao) - (treca.second - t.second)*cos(ugao);
      
      
  }
  void Skaliraj(const Tacka &t, double faktor){
      prva.first = 
  }
  void Rotiraj(double ugao){
      
  }
  void Skaliraj(double faktor) {
      
  }
  friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
  friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
  friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
    
};

int main ()
{
	return 0;
}