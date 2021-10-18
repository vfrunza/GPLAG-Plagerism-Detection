/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath> 
#include <stdexcept> 
#include <tuple> 
#include <memory>
#include <algorithm> 
#include <new>
#include <iterator> 
#include <vector>

double const Pi(4*atan(1));


class Kugla{
   double x, y, z, r; 
   
   public:
   
    explicit Kugla(double r = 0){
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik"); 
        Kugla::x = 0; Kugla::y = 0; Kugla::z = 0; 
        Kugla::r = r; 
    }
    Kugla(double x, double y, double z, double r = 0){
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik"); 
        Kugla::x = x, Kugla::y = y; Kugla::z = z; 
        Kugla::r = r; 
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0){
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik"); 
        x = std::get<0>(centar); y = std::get<1>(centar); z = std::get<2>(centar); 
        Kugla::r = r; 
    }
    double DajX() const{ return x; }
    double DajY() const{ return y; }
    double DajZ() const{ return z; }
    std::tuple<double, double, double> DajCentar() const{
        std::tuple<double, double, double> centar; 
        centar = std::make_tuple(x, y, z); 
        return centar;
    }
    double DajPoluprecnik() const{ return r; }
    double DajPovrsinu() const{ return 4*DajPoluprecnik()*DajPoluprecnik()*Pi; }
    double DajZapreminu() const{ return 4/3. * DajPoluprecnik() * DajPoluprecnik() * DajPoluprecnik() * Pi; }
    Kugla &PostaviX(double x) { Kugla::x = x; return *this; }
    Kugla &PostaviY(double y) { Kugla::y = y; return *this; }
    Kugla &PostaviZ(double z) { Kugla::z = z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z){ Kugla::x = x; Kugla::y = y; Kugla::z = z; return *this; } 
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        x = std::get<0>(centar); y = std::get<1>(centar); z = std::get<2>(centar); 
        return *this; 
    }
    Kugla &PostaviPoluprecnik(double r){
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik"); 
        Kugla::r = r; 
        return *this; 
    }
    void Ispisi() const{
        std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}" << std::endl; 
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){
        x += delta_x; y += delta_y; z += delta_z; 
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2); 
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
}; 

    bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
        if(!DaLiSuPodudarne(k1, k2)) return false; 
        if(!DaLiSuKoncentricne(k1, k2)) return false; 
        return true; 
    }
    bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
        if(k1.DajPoluprecnik() == k2.DajPoluprecnik()) return true; 
        return false; 
    }
    
    bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
        if(k1.DajX() != k2.DajX()) return false; 
        if(k1.DajY() != k2.DajY()) return false; 
        if(k1.DajZ() != k2.DajZ()) return false; 
        return true; 
    }
    
    double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
        double rastojanje; 
        rastojanje = sqrt((k1.DajX()-k2.DajX()) * (k1.DajX()-k2.DajX()) + (k1.DajY()-k2.DajY()) * (k1.DajY()-k2.DajY()) + (k1.DajZ()-k2.DajZ()) * (k1.DajZ()-k2.DajZ()));
        return rastojanje;     
    }
    
    bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
        return RastojanjeCentara(k1, k2) == (k1.DajPoluprecnik() + k2.DajPoluprecnik());
    } 
    
    bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
        return RastojanjeCentara(k1, k2) + std::min(k1.DajPoluprecnik(), k2.DajPoluprecnik()) == std::max(k1.DajPoluprecnik(), k2.DajPoluprecnik()); 
    }
    
    bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
        return RastojanjeCentara(k1, k2) >= std::max(k1.DajPoluprecnik(), k2.DajPoluprecnik()) && RastojanjeCentara(k1, k2) < k1.DajPoluprecnik() + k2.DajPoluprecnik() ||
               RastojanjeCentara(k1, k2) < std::max(k1.DajPoluprecnik(), k2.DajPoluprecnik()) && RastojanjeCentara(k1, k2) + std::min(k1.DajPoluprecnik(), k2.DajPoluprecnik()) > std::max(k1.DajPoluprecnik(), k2.DajPoluprecnik());
    }
    
    bool Kugla::DaLiSadrzi(const Kugla &k) const{
        return RastojanjeCentara(*this, k) < this->DajPoluprecnik() && 
               RastojanjeCentara(*this, k) + k.DajPoluprecnik() <= this->DajPoluprecnik();
    }
    
    bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
        if(!DaLiSeDodirujuIznutra(k1, k2) && !DaLiSeDodirujuIzvana(k1, k2) && DaLiSeSijeku(k1, k2)) return true; 
        return false; 
    }
    
   
   
int main ()
{
   
    std::cout << "Unesite broj kugla: "; 
    int n; 
    std::cin >> n; 
    while (!std::cin || n <= 0) {
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl; 
        std::cin.clear(); 
        std::cin.ignore(10000, '\n');
        std::cin >> n; 
    }
    std::vector<std::shared_ptr<Kugla>> vektor_pokazivaca(n); 
    for(int i = 0; i < n; i++){
        
        std::cout << "Unesite centar " << i+1 <<". kugle: "; 
        int x, y, z; 
        std::cin >> x >> y >> z; 
        while (!std::cin) {
            std::cout << "Neispravan centar" << std::endl; 
            std::cout << "Unesite centar " << i+1 <<". kugle: "; 
            std::cin.clear(); 
            std::cin.ignore(10000, '\n'); 
            std::cin >> x >> y >> z; 
        }
        std::cout << "Unesite poluprecnik " << i+1 << ". kugle: "; 
        double r; 
        std::cin >> r; 
        while(!std::cin || r < 0){ 
            std::cout << "Ilegalan poluprecnik" << std::endl; 
            std::cout << "Unesite centar " << i+1 <<". kugle: ";
            std::cin.clear(); 
            std::cin.ignore(10000, '\n');
            std::cin >> x >> y >> z; 
            std::cout << "Unesite poluprecnik " << i+1 << ". kugle: "; 
            std::cin >> r; 
        }
        
        vektor_pokazivaca[i] = std::make_shared<Kugla>(x, y, z, r); 
    }
    
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): "; 
    int delta_x, delta_y, delta_z; 
    std::cin >> delta_x >> delta_y >> delta_z; 
    while (!std::cin) {
        std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl; 
        std::cin.clear(); 
        std::cin.ignore(10000, '\n');
        std::cin >> delta_x >> delta_y >> delta_z; 
    }
    
    std::transform(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), vektor_pokazivaca.begin(), 
    [delta_x, delta_y, delta_z] (std::shared_ptr<Kugla> k)-> std::shared_ptr<Kugla> { (*k).Transliraj(delta_x, delta_y, delta_z); return k; }   );
    
    std::sort(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), 
    [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2){return (*k1).DajZapreminu() < (*k2).DajZapreminu(); }); 
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl; 
    
    std::for_each(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), 
    [](std::shared_ptr<Kugla> k) -> std::shared_ptr<Kugla> {(*k).Ispisi(); return k;});
    
    
    std::vector<std::shared_ptr<Kugla>>::iterator najveci = std::max_element(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), 
    [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2){return (*k1).DajPovrsinu() < (*k2).DajPovrsinu(); } );
    std::cout << "Kugla sa najvecom povrsinom je: "; (**najveci).Ispisi();

    
   static bool st(false); 
   static std::vector<std::pair<std::shared_ptr<Kugla>, std::shared_ptr<Kugla>>> parovi; 
   std::for_each(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), [vektor_pokazivaca](std::shared_ptr<Kugla> p1){
       std::for_each(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), [p1, vektor_pokazivaca](std::shared_ptr<Kugla> p2){
           if(DaLiSeSijeku(*p1, *p2)){
               auto pp = std::make_pair(p2, p1); 
               auto pp1 = std::make_pair(p1, p2); 
               auto it = std::find(parovi.begin(), parovi.end(), pp);
               if(it == parovi.end()){
                   parovi.push_back(pp1); 
                   std::cout << "Presjecaju se kugle: "; 
                   st = true; 
                   p1->Ispisi(); p2->Ispisi();
               }
           }
           
       });
       
   });
    if(!st) std::cout <<"Ne postoje kugle koje se presjecaju!" << std::endl;
    
	return 0;
	
}

