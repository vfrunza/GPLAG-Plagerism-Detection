/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <math.h>
#include <vector>
#include <memory>
#include <algorithm>
#include <climits>

typedef std::pair<double, double> Tacka;
const double eps = 1E-10;

bool AreDoubleSame(double a, double b){
    return std::fabs(a - b) < eps;
}

class Trougao{
    private:
        Tacka t1, t2, t3;
    public:
        Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
            Postavi(t1, t2, t3);
        }
        void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
            double stranica1, stranica2, stranica3;
            stranica1 = sqrt( (t1.first - t2.first)*(t1.first - t2.first) + (t1.second - t2.second)*(t1.second - t2.second) );
            stranica2 = sqrt( (t1.first - t3.first)*(t1.first - t3.first) + (t1.second - t3.second)*(t1.second - t3.second) );
            stranica3 = sqrt( (t2.first - t3.first)*(t2.first - t3.first) + (t2.second - t3.second)*(t2.second - t3.second) );
            if(stranica1+stranica2>stranica3 && stranica1+stranica3>stranica2 && stranica2+stranica3>stranica1){
                Trougao::t1 = t1; Trougao::t2 = t2; Trougao::t3 = t3;
            } else {
                std::cout << std::endl << std::endl << "| " << t1.first << ", " << t1.second << " | " << t2.first << ", " << t2.second << " | " << t3.first << ", " << t3.second << " |" << std::endl;
                throw std::domain_error("Nekorektne pozicije tjemena");
            }
        }
        void Postavi(int index, const Tacka &t){
            if(index == 1){
                Postavi(t, Trougao::t2, Trougao::t3);
            }else if(index == 2){
                Postavi(Trougao::t1, t, Trougao::t3);
            }else if(index == 3){
                Postavi(Trougao::t1, Trougao::t2, t);
            }else{
                throw std::range_error("Nekorektan index");
            }
        }
        double DajStranicu(int index) const{
            double stranica1, stranica2, stranica3;
            stranica1 = sqrt( (t2.first - t3.first)*(t2.first - t3.first) + (t2.second - t3.second)*(t2.second - t3.second) );
            stranica2 = sqrt( (t1.first - t3.first)*(t1.first - t3.first) + (t1.second - t3.second)*(t1.second - t3.second) );
            stranica3 = sqrt( (t1.first - t2.first)*(t1.first - t2.first) + (t1.second - t2.second)*(t1.second - t2.second) );
            if(index == 1){
                return stranica1;
            }else if(index == 2){
                return stranica2;
            }else if(index == 3){
                return stranica3;
            }else{
                throw std::range_error("Nekorektan index");
            }
        }
        double DajUgao(int index) const{
            if(index == 1){
                return acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)));
            }else if(index == 2){
                return acos((DajStranicu(3)*DajStranicu(3)+DajStranicu(1)*DajStranicu(1)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(3)*DajStranicu(1)));
            }else if(index == 3){
                return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)));
            }else{
                throw std::range_error("Nekorektan index");
            }
        }
        static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
            double provjera;
            provjera = t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second);
            if(provjera > 0){
                return 1;
            } else if(provjera < 0){
                return -1;
            } else {
                return 0;
            }
            
        }
        Tacka DajTjeme(int index) const{
            if(index == 1){
                return t1;
            }else if(index == 2){
                return t2;
            }else if(index == 3){
                return t3;
            }else{
                throw std::range_error("Nekorektan index");
            }
        }
        double DajObim() const{
            return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
        }
        double DajPovrsinu() const{
            double tmp = (DajStranicu(1) + DajStranicu(2) + DajStranicu(3)) / 2;
            double povrsina = sqrt ( tmp*(tmp-DajStranicu(1))*(tmp-DajStranicu(2))*(tmp-DajStranicu(3)) );
            return povrsina;
        }
        Tacka DajCentar() const{
            Tacka centar;
            centar.first = (t1.first + t2.first + t3.first)/3;
            centar.second = (t1.second + t2.second + t3.second)/3;
            return centar;
        }
        bool DaLiJeUnutra(const Tacka &t) const{
            if(Orijentacija(Trougao::t1, Trougao::t2, Trougao::t3)>0 && Orijentacija(Trougao::t1, Trougao::t2, t)>0 && Orijentacija(Trougao::t1, t, Trougao::t3)>0 && Orijentacija(t, Trougao::t2, Trougao::t3)>0){
                return true;
            } else if(Orijentacija(Trougao::t1, Trougao::t2, Trougao::t3)<0 && Orijentacija(Trougao::t1, Trougao::t2, t)<0 && Orijentacija(Trougao::t1, t, Trougao::t3)<0 && Orijentacija(t, Trougao::t2, Trougao::t3)<0){
                return true;
            } else {
                return false;
            }
        }
        bool DaLiJePozitivnoOrijentiran() const{
            if(Orijentacija(t1, t2, t3) == 1 ){
                return true;
            } else if(Orijentacija(t1, t2, t3) == -1){
                return false;
            }
            return false;
        }
        void Transliraj(double delta_x, double delta_y){
            t1.first = t1.first + delta_x; t1.second = t1.second + delta_y;
            t2.first = t2.first + delta_x; t2.second = t2.second + delta_y;
            t3.first = t3.first + delta_x; t3.second = t3.second + delta_y;
        }
        void Centriraj(const Tacka &t){
            Tacka centar = DajCentar();
            double x, y;
            x = t.first - centar.first;
            y = t.second - centar.second;
            Transliraj(x, y);
        }
        void Rotiraj(const Tacka &t, double ugao){
            Tacka tmp1, tmp2, tmp3;
            // ROTACIJA PRVE TACKE
            tmp1.first = t.first + (t1.first - t.first) * cos(ugao) - (t1.second - t.second) * sin(ugao);
            tmp1.second = t.second + (t1.first - t.first) * sin(ugao) + (t1.second - t.second) * cos(ugao);
            // ROTACIJA DRUGE TACKE
            tmp2.first = t.first + (t2.first - t.first) * cos(ugao) - (t2.second - t.second) * sin(ugao);
            tmp2.second = t.second + (t2.first - t.first) * sin(ugao) + (t2.second - t.second) * cos(ugao);
            // ROTACIJA TRECE TACKE
            tmp3.first = t.first + (t3.first - t.first) * cos(ugao) - (t3.second - t.second) * sin(ugao);
            tmp3.second = t.second + (t3.first - t.first) * sin(ugao) + (t3.second - t.second) * cos(ugao);
            Postavi(tmp1, tmp2, tmp3);
        }
        void Skaliraj(const Tacka &t, double faktor){
            if(AreDoubleSame(faktor, 0)){
                throw std::domain_error ("Nekorektan faktor skaliranja");
            }
            Tacka tmp1, tmp2, tmp3;
            // SKALIRANJE PRVE TACKE
            tmp1.first = t.first + faktor*(t1.first - t.first);
            tmp1.second = t.second + faktor*(t1.second - t.second);
            // SKALIRANJE DRUGE TACKE
            tmp2.first = t.first + faktor*(t2.first - t.first);
            tmp2.second = t.second + faktor*(t2.second - t.second);
            // SKALIRANJE TRECE TACKE
            tmp3.first = t.first + faktor*(t3.first - t.first);
            tmp3.second = t.second + faktor*(t3.second - t.second);
            Postavi(tmp1, tmp2, tmp3);
        }
        void Rotiraj(double ugao){
            Tacka point = DajCentar();
            Rotiraj(point, ugao);
        }
        void Skaliraj(double faktor){
            Tacka point = DajCentar();
            Skaliraj(point, faktor);
        }
        friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2){
            bool identicni(false);
            Tacka tjeme1_t1 = t1.DajTjeme(1);
            Tacka tjeme2_t1 = t1.DajTjeme(2);
            Tacka tjeme3_t1 = t1.DajTjeme(3);
            
            Tacka tjeme1_t2 = t2.DajTjeme(1);
            Tacka tjeme2_t2 = t2.DajTjeme(2);
            Tacka tjeme3_t2 = t2.DajTjeme(3);
            
            if( (tjeme1_t1 == tjeme1_t2) || (tjeme1_t1 == tjeme2_t2) || (tjeme1_t1 == tjeme3_t2) ){
                identicni = true;
            } else {
                return false;
            }
            
            if( (tjeme2_t1 == tjeme1_t2) || (tjeme2_t1 == tjeme2_t2) || (tjeme2_t1 == tjeme3_t2) ){
                identicni = true;
            } else {
                return false;
            }
            
            if( (tjeme3_t1 == tjeme1_t2) || (tjeme3_t1 == tjeme2_t2) || (tjeme3_t1 == tjeme3_t2) ){
                identicni = true;
            } else {
                return false;
            }
            
           /* if( (tjeme1_t1.first == tjeme1_t2.first && tjeme1_t1.second == tjeme1_t2.second) || (tjeme1_t1.first == tjeme2_t2.first && tjeme1_t1.second == tjeme2_t2.second) || (tjeme1_t1.first == tjeme3_t2.first && tjeme1_t1.second == tjeme3_t2) ){
                identicni = true;
            } else {
                return false;
            }
            
            if( (tjeme1_t1.first == tjeme1_t2.first && tjeme1_t1.second == tjeme1_t2.second) || (tjeme1_t1.first == tjeme2_t2.first && tjeme1_t1.second == tjeme2_t2.second) || (tjeme1_t1.first == tjeme3_t2.first && tjeme1_t1.second == tjeme3_t2) ){
                identicni = true;
            } else {
                return false;
            }
            
            if( (tjeme2_t1.first == tjeme1_t2.first && tjeme2_t1.second == tjeme1_t2.second) || (tjeme2_t1.first == tjeme2_t2.first && tjeme2_t1.second == tjeme2_t2.second) || (tjeme2_t1.first == tjeme3_t2.first && tjeme1_t2.second == tjeme3_t2) ){
                identicni = true;
            } else {
                return false;
            }
            
            if( (tjeme3_t1.first == tjeme1_t2.first && tjeme3_t1.second == tjeme1_t2.second) || (tjeme3_t1.first == tjeme2_t2.first && tjeme3_t1.second == tjeme2_t2.second) || (tjeme3_t1.first == tjeme3_t2.first && tjeme3_t1.second == tjeme3_t2) ){
                identicni = true;
            } else {
                return false;
            }*/
            
            return identicni;
        }
        friend bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2){
            bool istina(true);
            double stranica1_t1 = t1.DajStranicu(1);
            double stranica2_t1 = t1.DajStranicu(2);
            double stranica3_t1 = t1.DajStranicu(3);
            double stranica1_t2 = t2.DajStranicu(1);
            double stranica2_t2 = t2.DajStranicu(2);
            double stranica3_t2 = t2.DajStranicu(3);
            
            if (DaLiSuIdenticni(t1,t2)){
                return istina;
            } else if ( (t1.Orijentacija(t1.t1,t1.t2,t1.t3) == t2.Orijentacija(t2.t1,t2.t2,t2.t3) && AreDoubleSame(stranica1_t1, stranica2_t2) && AreDoubleSame(stranica2_t1, stranica3_t2) && AreDoubleSame(stranica3_t1, stranica1_t2) ) || ( (t1.Orijentacija(t1.t1,t1.t2,t1.t3) != t2.Orijentacija(t2.t1,t2.t2,t2.t3) && AreDoubleSame(stranica1_t1, stranica2_t2) && AreDoubleSame(stranica2_t1, stranica1_t2) && AreDoubleSame(stranica3_t1, stranica3_t2) ) ) ){
                return istina;
            } else if ( (t1.Orijentacija(t1.t1,t1.t2,t1.t3) != t2.Orijentacija(t2.t1,t2.t2,t2.t3) && AreDoubleSame(stranica1_t1, stranica3_t2) && AreDoubleSame(stranica2_t1, stranica2_t2) && AreDoubleSame(stranica3_t1, stranica1_t2) ) || ( (t1.Orijentacija(t1.t1,t1.t2,t1.t3) == t2.Orijentacija(t2.t1,t2.t2,t2.t3) && AreDoubleSame(stranica1_t1, stranica3_t2) && AreDoubleSame(stranica2_t1, stranica1_t2) && AreDoubleSame(stranica3_t1, stranica2_t2) ) ) ){
                return istina;
            } else if ( (t1.Orijentacija(t1.t1,t1.t2,t1.t3) == t2.Orijentacija(t2.t1,t2.t2,t2.t3) && AreDoubleSame(stranica1_t1, stranica1_t2) && AreDoubleSame(stranica2_t1, stranica2_t2) && AreDoubleSame(stranica3_t1, stranica3_t2) ) || ( (t1.Orijentacija(t1.t1,t1.t2,t1.t3) != t2.Orijentacija(t2.t1,t2.t2,t2.t3) && AreDoubleSame(stranica1_t1, stranica1_t2) && AreDoubleSame(stranica2_t1, stranica3_t2) && AreDoubleSame(stranica3_t1, stranica2_t2) ) ) ){
                return istina;
            }
                
            return false;
        }
        friend bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2){
            double stranica1_t1 = t1.DajStranicu(1);
            double stranica2_t1 = t1.DajStranicu(2);
            double stranica3_t1 = t1.DajStranicu(3);
            double stranica1_t2 = t2.DajStranicu(1);
            double stranica2_t2 = t2.DajStranicu(2);
            double stranica3_t2 = t2.DajStranicu(3);
            
            //potrebno skalirati trougao t1 u trougao t2 pa onda izvrisiti projeru DaLiSuSlicni
            
            Trougao TMP11 = t1, TMP12 = t1, TMP13 = t1;
            Trougao TMP21 = t1, TMP22 = t1, TMP23 = t1;
            Trougao TMP31 = t1, TMP32 = t1, TMP33 = t1;
            
            double faktor11 = stranica1_t2 / stranica1_t1;
            double faktor12 = stranica1_t2 / stranica2_t1;
            double faktor13 = stranica1_t2 / stranica3_t1;
            
            double faktor21 = stranica2_t2 / stranica1_t1;
            double faktor22 = stranica2_t2 / stranica2_t1;
            double faktor23 = stranica2_t2 / stranica3_t1;
            
            double faktor31 = stranica3_t2 / stranica1_t1;
            double faktor32 = stranica3_t2 / stranica2_t1;
            double faktor33 = stranica3_t2 / stranica3_t1;
            
            TMP11.Skaliraj(faktor11);
            TMP12.Skaliraj(faktor12);
            TMP13.Skaliraj(faktor13);
            TMP21.Skaliraj(faktor21);
            TMP22.Skaliraj(faktor22);
            TMP23.Skaliraj(faktor23);
            TMP31.Skaliraj(faktor31);
            TMP32.Skaliraj(faktor32);
            TMP33.Skaliraj(faktor33);
            
            
            if (DaLiSuIdenticni(t1,t2)){
                return true;
            }
            if (DaLiSuPodudarni(TMP11, t2) || DaLiSuPodudarni(TMP12, t2) || DaLiSuPodudarni(TMP13, t2)){
                return true;
            }
            if (DaLiSuPodudarni(TMP21, t2) || DaLiSuPodudarni(TMP22, t2) || DaLiSuPodudarni(TMP23, t2)){
                return true;
            }
            if (DaLiSuPodudarni(TMP31, t2) || DaLiSuPodudarni(TMP32, t2) || DaLiSuPodudarni(TMP33, t2)){
                return true;
            }
            
            
            return false;
        }
        void Ispisi() const{
            std::cout << "(" << "(" << t1.first << "," << t1.second << "),(" << t2.first << "," << t2.second << "),(" << t3.first << "," << t3.second << ")" << ")";
        }
};

bool ImaLiIdenticnih (std::vector<std::shared_ptr<Trougao>> v, int koliko_trouglova){
    int brojac = 0;
    for (int i=0;i<koliko_trouglova-1;i++){
        for (int j=i+1;j<koliko_trouglova;j++){
            if (DaLiSuIdenticni(*v[i],*v[j])){
                brojac++;
            }
        }
    }
    if(brojac == 0){
        return false;
    }
    return true;   
}
void IspisiIdenticne (std::vector<std::shared_ptr<Trougao>> v, int koliko_trouglova){
    std::cout << std::endl << "Parovi identicnih trouglova:" << std::endl;
    for (int i=0;i<koliko_trouglova-1;i++){
        for (int j=i+1;j<koliko_trouglova;j++){
            if (DaLiSuIdenticni(*v[i],*v[j])){
            v[i]->Ispisi();
            std::cout << " i "; 
            v[j]->Ispisi();
            }
        }
    }
    
}

bool ImaLiPodudarnih (std::vector<std::shared_ptr<Trougao>> v, int koliko_trouglova){
    int brojac = 0;
    for(int i=0; i<koliko_trouglova-1; i++){
        for(int j=i+1; j<koliko_trouglova; j++){
            if(DaLiSuPodudarni(*v[i], *v[j])){
                brojac++;
            }
        }
    }
    if(brojac == 0){
        return false;
    }
    return true;   
}
void IspisiPodudarne (std::vector<std::shared_ptr<Trougao>> v, int koliko_trouglova){
    std::cout << std::endl << "Parovi podudarnih trouglova:" << std::endl;
    for(int i=0; i<koliko_trouglova-1; i++){
        for(int j=i+1; j<koliko_trouglova; j++){
            if(DaLiSuPodudarni(*v[i], *v[j])){
                v[i] -> Ispisi();
                std::cout << " i ";
                v[j] -> Ispisi();
                std::cout << std::endl;
            }
        }
    }
    
}

bool ImaLiSlicnih (std::vector<std::shared_ptr<Trougao>> v, int koliko_trouglova){
    int brojac = 0;
    for(int i=0; i<koliko_trouglova-1; i++){
        for(int j=i+1; j<koliko_trouglova; j++){
            if(DaLiSuSlicni(*v[i], *v[j])){
                brojac++;
            }
        }
    }
    if(brojac == 0){
        return false;
    }
    return true;  
}
void IspisiSlicne (std::vector<std::shared_ptr<Trougao>> v, int koliko_trouglova){
    std::cout << "Parovi slicnih trouglova: " << std::endl;
    for(int i=0; i<koliko_trouglova-1; i++){
        for(int j=i+1; j<koliko_trouglova; j++){
            if(DaLiSuSlicni(*v[i], *v[j])){
                v[i]->Ispisi();
                std::cout << " i ";
                v[j] -> Ispisi();
                std::cout << std::endl;
            }
        }
    }
    
}

int main (){
    /*
    std::pair<double, double> tacka1 (-6,7);
    std::pair<double, double> tacka2 (-6,-3);
    std::pair<double, double> tacka3 (5,-2);
    
    Trougao trokut (tacka1, tacka2, tacka3);
    std::cout << trokut.DajStranicu(1) << " " << trokut.DajStranicu(2) << " " << trokut.DajStranicu(3) << std::endl;
    std::cout << trokut.DajUgao(1) << " " << trokut.DajUgao(2) << " " << trokut.DajUgao(3) << std::endl;
    
    std::pair<double, double> tmp1 = trokut.DajTjeme(1);
    std::pair<double, double> tmp2 = trokut.DajTjeme(2);
    std::pair<double, double> tmp3 = trokut.DajTjeme(3);
    
    std::cout << tmp1.first << " " << tmp1.second << std::endl;
    std::cout << tmp2.first << " " << tmp2.second << std::endl;
    std::cout << tmp3.first << " " << tmp3.second << std::endl;
    
    std::cout << "Obim: " << trokut.DajObim() << std::endl;
    std::cout << "Povrsina: " << trokut.DajPovrsinu() << std::endl;
    
    std::pair<double, double> centar = trokut.DajCentar();
    std::cout << "Centar: " << centar.first << " " << centar.second << std::endl;
    
    std::pair<double, double> unutrasnja (-3,1);
    std::pair<double, double> vanjska (-8,2);
    std::pair<double, double> na_trouglu (-6,2);
    
    std::cout << std::boolalpha << trokut.DaLiJeUnutra(unutrasnja) << " " << trokut.DaLiJeUnutra(vanjska) << " " << trokut.DaLiJeUnutra(na_trouglu);

    std::pair<double, double> promjena_tacke1(3, -2);
    trokut.Postavi(3, promjena_tacke1);
    std::cout << promjena_tacke1.first << " " << promjena_tacke1.second << std::endl; */
    try{
        std::vector<std::shared_ptr<Trougao>> v;
        std::cout << "Koliko zelite kreirati trouglova: ";
        int koliko_trouglova; 
        std::cin >> koliko_trouglova;
        
        for (int i = 0; i < koliko_trouglova; i++) {
            Tacka tacka1, tacka2, tacka3;
            std::cout << "Unesite podatke za " << i + 1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            std::cin >> tacka1.first >> tacka1.second;
            std::cin >> tacka2.first >> tacka2.second;
            std::cin >> tacka3.first >> tacka3.second;
            //izuzetak
            if (Trougao::Orijentacija(tacka1, tacka2, tacka3) == 0) {
                std::cout << "Nekorektne pozicije tjemena, ponovite unos!" << std::endl;
                i--;
                continue;
            }
            v.push_back(std::make_shared<Trougao> (tacka1, tacka2, tacka3));
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
        
        // Operacije
        std::transform(v.begin(), v.end(), v.begin(), [dx,dy,ugao,faktor](std::shared_ptr<Trougao> x) {
            (*x).Transliraj(dx, dy);
            (*x).Rotiraj((*x).DajCentar(), ugao);
            (*x).Skaliraj((*x).DajTjeme(1), faktor);
            return x;
        });
        
        // SORTIRANJE
        std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> x, std::shared_ptr<Trougao> y) {return (*x).DajPovrsinu() < (*y).DajPovrsinu();});
        
        std::cout <<"Trouglovi nakon obavljenih transformacija: " << std::endl;
        std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> x) {(*x).Ispisi(); std::cout << std::endl;});
        
        // OBIM
        std::shared_ptr<Trougao> najmanji_obim;
        najmanji_obim = *(std::max_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> x, std::shared_ptr<Trougao> y) {return ((*x).DajObim() > (*y).DajObim());}));
        std::cout << "Trougao sa najmanjim obimom: ";
        (*najmanji_obim).Ispisi();
        
        // IDENTICNI TROUGLOVI
        bool istina1 = ImaLiIdenticnih(v, koliko_trouglova);
        if (istina1 == false){
            std::cout << std::endl << "Nema identicnih trouglova!" << std::endl;
        }
        else{
            IspisiIdenticne(v, koliko_trouglova);
        }
        
        // PODUDARNI TROUGLOVI
        bool istina2 = ImaLiPodudarnih(v, koliko_trouglova);
        if(istina2 == false){
            std::cout << "Nema podudarnih trouglova!" << std::endl;
        } else {
            IspisiPodudarne(v, koliko_trouglova);
        }
        
        // ISPIS SLICNIH TROUGLOVA
        bool istina3 = ImaLiSlicnih(v, koliko_trouglova);
        if(istina3 == false){
            std::cout << "Nema slicnih trouglova!" << std::endl;
        } else {
            IspisiSlicne(v, koliko_trouglova);
        }
        
    // IZUZETCI
    } catch (std::domain_error e){
        std::cout << e.what() << std::endl;
    } catch (std::range_error e){
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}