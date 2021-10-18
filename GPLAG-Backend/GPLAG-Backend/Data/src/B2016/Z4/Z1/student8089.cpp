#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <memory>

typedef std::pair<double, double> Tacka;

class Trougao{
        Tacka t1, t2, t3;
    public:
        Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
            if (Orijentacija(t1, t2, t3) == 0) throw std::domain_error ("Nekorektne pozicije tjemena");
            
            Trougao::t1 = t1; Trougao::t2 = t2; Trougao::t3 = t3;
        } //Testirana i radi
        
        void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3){
            if (Orijentacija(t1, t2, t3) == 0) throw std::domain_error ("Nekorektne pozicije tjemena");
            
            Trougao::t1 = t1; Trougao::t2 = t2; Trougao::t3 = t3;
        } //Testirana i radi
        
        void Postavi(int indeks, const Tacka &t){
            if (indeks != 1 && indeks != 2 && indeks != 3  ) throw std::range_error("Nekorektan indeks");
            
            if (indeks == 1) {
                if (Orijentacija(t, t2, t3) == 0) throw std::domain_error ("Nekorektne pozicije tjemena");
                t1 = t;
            }
            else if (indeks == 2){
              if (Orijentacija(t1, t, t3) == 0) throw std::domain_error ("Nekorektne pozicije tjemena");
              t2 = t;  
            } 
            else if (indeks == 3){
              if (Orijentacija(t1, t2, t) == 0) throw std::domain_error ("Nekorektne pozicije tjemena");
              t3 = t;  
            } 
        } //Testirana i radi
        
        static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
            double suma{t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second)};
            
            if (suma > 0) {return 1;}
            else if (suma < 0) {return -1;}
            
            return 0;
        } //Testirana i radi
        
        Tacka DajTjeme (int indeks) const{
            if (indeks != 1 && indeks != 2 && indeks != 3  ) throw std::range_error("Nekorektan indeks");
            if (indeks == 1) return t1;
            else if (indeks == 2) return t2;
            else if (indeks == 3) return t3;
        } // Testirana i radi
        
        double DajStranicu (int indeks) const{
            if (indeks != 1 && indeks != 2 && indeks != 3  ) throw std::range_error("Nekorektan indeks");
            if (indeks == 1) return sqrt((t3.first - t2.first)*(t3.first - t2.first) + (t3.second - t2.second)*(t3.second - t2.second));
            else if (indeks == 2) return sqrt((t1.first - t3.first)*(t1.first - t3.first) + (t1.second - t3.second)*(t1.second - t3.second));
            else if (indeks == 3) return sqrt((t1.first - t2.first)*(t1.first - t2.first) + (t1.second - t2.second)*(t1.second - t2.second));
        }  // Testirana i radi
        
        double DajUgao (int indeks) const{
            if (indeks != 1 && indeks != 2 && indeks != 3  ) throw std::range_error("Nekorektan indeks");
            if (indeks == 1){
                double A(DajStranicu(1)), B(DajStranicu(2)), C(DajStranicu(3));
                return std::acos((B*B + C * C - A*A) / (2*B*C));
            }
            else if (indeks == 2){
                double B(DajStranicu(1)), A(DajStranicu(2)), C(DajStranicu(3));
                return std::acos((B*B + C * C - A*A) / (2*B*C));
            }
            else if (indeks == 3){
                double C(DajStranicu(1)), B(DajStranicu(2)), A(DajStranicu(3));
                return  std::acos((B*B + C * C - A*A) / (2*B*C));
            }
        } // Testirana i valjda radi !!!MOZDA NIJE TACNO
        
        double DajObim () const{
            return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
        } //Testirana i radi
        
        double DajPovrsinu() const{
            return abs(t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second));
        } //Testirana i radi
        
        Tacka DajCentar () const{
            return {((t1.first + t2.first + t3.first)/3), ((t1.second + t2.second + t3.second)/3)};
        } // Testuraba u radu
        
        bool DaLiJePozitivnoOrijentiran() const{
            if (Orijentacija(t1,t2,t3) == 1) return true;
            
            return false;
            
        } //Radi
        
        bool DaLiJeUnutra(const Tacka &t) const{
            if (Orijentacija(t1, t2, t3) ==  Orijentacija(t1, t2, t) == Orijentacija(t2, t3, t) == Orijentacija(t3, t1, t)) return true;
            
            return false;
        } // Valjda radi
        
        void Ispisi() const{
            std::cout << "((" << t1.first << "," << t1.second << "),(" << t2.first << "," << t2.second << "),(" << t3.first << "," << t3.second << "))";
        } //Radi, samo treba paziti ako AT-ovi budu trazili std::endl na kraju
        
        void Transliraj (double delta_x, double delta_y){
            t1.first += delta_x; t2.first += delta_x; t3.first += delta_x;
            t1.second += delta_y; t2.second += delta_y; t3.second += delta_y;
        } // OKay :D
        
        void Centriraj (const Tacka &t){
            Tacka bivsiCentar(DajCentar());
            Transliraj((t.first-bivsiCentar.first), (t.second-bivsiCentar.second));
        } // trebala bi biti ok
        
        void Rotiraj (const Tacka &t, double ugao){
            double tempy;
            
            tempy = (t.first + (t1.first - t.first)*cos(ugao) - (t1.second - t.second)*sin(ugao));
            t1.second = (t.second + (t1.first - t.first)*sin(ugao) + (t1.second - t.second)*cos(ugao));
            t1.first = tempy;
            
            tempy = (t.first + (t2.first - t.first)*cos(ugao) - (t2.second - t.second)*sin(ugao));
            t2.second = (t.second + (t2.first - t.first)*sin(ugao) + (t2.second - t.second)*cos(ugao));
            t2.first = tempy;
            
            tempy = (t.first + (t3.first - t.first)*cos(ugao) - (t3.second - t.second)*sin(ugao));
            t3.second = (t.second + (t3.first - t.first)*sin(ugao) + (t3.second - t.second)*cos(ugao));
            t3.first = tempy;
        } //Valjda radi
        
        void Skaliraj (const Tacka &t, double faktor){
            if (faktor == 0) throw std::domain_error ("Nekorektan faktor skaliranja"); //Moram da popravim ovdje jer komparira realne br
            
            if (faktor < 0) {Rotiraj(t, 180); faktor *= -1;}
            
            
            t1.first = t.first + faktor*(t1.first - t.first);
            t1.second = t.second + faktor*(t1.second - t.second);
            
            t2.first = t.first + faktor*(t2.first - t.first);
            t2.second = t.second + faktor*(t2.second - t.second);
            
            t3.first = t.first + faktor*(t3.first - t.first);
            t3.second = t.second + faktor*(t3.second - t.second);
        }
        
        void Rotiraj (double ugao){
            
            Rotiraj(DajCentar(), ugao);
            
        } //Valjda radi
        
        void Skaliraj (double faktor){
            Skaliraj(DajCentar(), faktor);
        } // Radi
        
        friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2);
        
        //friend bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2);
        
        //friend bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2);
};

int main (){
 
	return 0;
}

bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2){
    
    std::vector<Tacka> v1{t1.t1, t1.t2, t1.t3}, v2{t2.t1, t2.t2, t2.t3};
    
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            if (v1[i].first == v2[j].first && v1[i].second == v2[j].second) {v1.erase(v1.begin()+i); v2.erase(v2.begin()+j); i--; break; }
        }
    }
    
   
    
    if (v1.size() == 0) return true;
    
    return false;
    
} // Trebala bi biti ok :D