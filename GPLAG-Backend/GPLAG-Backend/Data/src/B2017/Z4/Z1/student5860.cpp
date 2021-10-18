/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <cmath>
#include <vector>
#include <memory>

const double EPS = 0.0000000001;
class Kugla {
private:
    double x, y, z, r;
   // static constexpr double EPS = 0.0000000001;
    static constexpr double PI = 3.14159265359;
    friend double dajIndeks(std::vector<std::shared_ptr<Kugla>> v, std::shared_ptr<Kugla> k);
    
public:
    explicit Kugla(double r = 0) {
      if (r < 0) throw std::domain_error("Ilegalan poluprecnik");
        x = 0; y = 0; z = 0; this->r = r;
    }
    Kugla(double x, double y, double z, double r = 0) {
        if (r < 0) throw std::domain_error("Ilegalan poluprecnik");
        this->x = x; this->y = y; this->z = z; this->r = r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if (r < 0) throw std::domain_error("Ilegalan poluprecnik");
        this->x = std::get<0>(centar);
        this->y = std::get<1>(centar);
        this->z = std::get<2>(centar);
        this->r = r;
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const { return std::make_tuple(x, y, z); }
    double DajPoluprecnik() const { return r; } 
    double DajPovrsinu() const { return 4*r*r*PI; }
    double DajZapreminu() const { return 4./3 * r*r*r * PI; }
    Kugla &PostaviX(double x) {
        this->x = x;
        return *this;
    }
    Kugla &PostaviY(double y) {
        this->y = y;
        return *this;
    }
    Kugla &PostaviZ(double z) {
        this->z = z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z) {
        this->x = x; this->y = y; this->z = z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if (r < 0) throw std::domain_error("Ilegalan poluprecnik");
        this->r = r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z);
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

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
       return true; 
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    if ((fabs(k1.x - k2.x) < EPS * (fabs(k1.x) + fabs(k2.x))) && (fabs(k1.y - k2.y) < EPS * (fabs(k1.y) + fabs(k2.y))) &&
        (fabs(k1.z - k2.z) < EPS * (fabs(k1.z) + fabs(k2.z)))) return true;
        else return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    if (fabs(k1.r - k2.r) < EPS * (fabs(k1.r) + fabs(k2.r))) return true;
    else return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    if ((k1.r + k2.r) > RastojanjeCentara(k1, k2) && RastojanjeCentara(k1,k2) > fabs(k1.r-k2.r)) return true;
    else return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    double dist = RastojanjeCentara(k1,k2), razP = k1.r + k2.r;
    if (fabs(dist - razP) < EPS * (fabs(dist) + fabs(razP))) return true;
    else return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    double dist = RastojanjeCentara(k1,k2), razP = fabs(k1.r - k2.r);
    if (fabs(dist - razP) < EPS * (fabs(dist) + fabs(razP))) return true;
    else return false;
}

void Kugla::Transliraj(double delta_x, double delta_y, double delta_z) {
       
        this->x += delta_x; this->y += delta_y; this->z += delta_z;
   
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return sqrt((k1.x-k2.x)*(k1.x-k2.x) + (k1.y-k2.y)*(k1.y-k2.y) + (k1.z-k2.z)*(k1.z-k2.z));
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    if ((fabs(k1.x-k2.x) < EPS * (fabs(k1.x) + fabs(k2.x))) && (fabs(k1.y-k2.y) < EPS * (fabs(k1.y) + fabs(k2.y))) &&
        (fabs(k1.z-k2.z) < EPS * (fabs(k1.z) + fabs(k2.z))) && (fabs(k1.r-k2.r) < EPS * (fabs(k1.r) + fabs(k2.r)))) return true;
    else return false;
}

double dajIndeks(std::vector<std::shared_ptr<Kugla>> v, std::shared_ptr<Kugla> k) {
    int br{};
    for (int i=0; i<v.size(); i++) {
        if (!DaLiSuIdenticne(*k, *v[i])) br++;
        else break;
    }
    return br;
}

bool jeLiSlovo(std::string x) {
    for (int i=0; i<x.length(); i++) {
        if ((x[i] >= 'A' && x[i] <= 'Z') || (x[i] >= 'a' && x[i] <= 'z')) return true;
        else return false;
    }
}

double dajBroj(std::string x) {
  //  double n{};
  /*  bool xx = false;
     if (x[0] == '-') {
            xx = true;
            x.erase(x.begin()+1);
        }
    for (int i=0, j=x.length(); i<x.length(); i++) {
       
         n += (x[--j] - '0')*pow(10,i);
    }
    if (xx) n *= -1;*/
    return std::stod(x);
}

bool jeLiIspravan(std::string x) {
    if (jeLiSlovo(x)) return false;
    else {
        double n = dajBroj(x);
        if (n < 0) return false;
        else return true;
    }
}

std::tuple<double, double, double> unesitePonovoCentar(int i, std::string poruka, std::string poruka2) {
 
    std::cout<<poruka2;
    std::string x1{}, y1{}, z1{};
    double x{}, y{}, z{};
    do {
        std::cin>>x1>>y1>>z1;
        if (!jeLiSlovo(x1)) {
            x = dajBroj(x1);
            if (!jeLiSlovo(y1)) {
                y = dajBroj(y1);
                if (!jeLiSlovo(z1)) {
                    z = dajBroj(z1);
                    return std::make_tuple(x,y,z);
                }
                else { std::cout<<poruka<<poruka2; /*unesitePonovoCentar(i, poruka, poruka2);*/ }
            }
            else{ std::cout<<poruka<<poruka2; /*unesitePonovoCentar(i, poruka, poruka2);*/ }
        }
        else {
            std::cout<<poruka<<poruka2;
          //  unesitePonovoCentar(i, poruka, poruka2);
        }
        
    }
    while(jeLiSlovo(x1) || jeLiSlovo(y1) || jeLiSlovo(z1));
}


std::tuple<double, double, double> provjeriCentar(std::tuple<std::string, std::string, std::string> centar, int i, std::string poruka, std::string poruka2) {
    if (!jeLiSlovo(std::get<0>(centar))) {
        if (!jeLiSlovo(std::get<1>(centar))) {
            if (!jeLiSlovo(std::get<2>(centar))) {
                double x = dajBroj(std::get<0>(centar));
                double y = dajBroj(std::get<1>(centar));
                double z = dajBroj(std::get<2>(centar));
                return std::make_tuple(x,y,z);
            }
            else {
                std::cout<<poruka;
                std::tuple<double, double, double> d = unesitePonovoCentar(i, poruka, poruka2);
                return d;
            }
        }
        else {
               std::cout<<poruka;
               std::tuple<double, double, double> d = unesitePonovoCentar(i, poruka, poruka2);
               return d;
        }
    }   
    else {
        std::cout<<poruka;
        std::tuple<double, double, double> d = unesitePonovoCentar(i, poruka, poruka2);
        return d;
    }
}

double provjeriPoluprecnik(std::string r, int i, std::tuple<double, double, double> &c) {
    if (!jeLiSlovo(r)) return dajBroj(r);
    else {
           std::cout<<"Ilegalan poluprecnik";
      
           std::string s = "\nUnesite centar "+std::to_string(i)+". kugle: ";
           c = unesitePonovoCentar(i, "Neispravan centar", s);
           std::cout<<"Unesite poluprecnik "<<i<<". kugle: ";
           std::cin>>r;
           if (!jeLiIspravan(r)) provjeriPoluprecnik(r, i, c);
           else return dajBroj(r);
      // }
     //  while (!jeLiIspravan(r));
      
    }
    
}
int main ()
{
    int n{};
    std::string x2;
    std::cout<<"Unesite broj kugla: ";
    do {
     //   std::cout<<"Unesite broj kugla: ";
        std::cin>>x2;
        if (jeLiSlovo(x2)) std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
        else {
            for (int i=0, j=x2.length(); i<x2.length(); i++)
                n += (x2[--j] - '0')*pow(10,i);
            if (n <= 0) { std::cout<<"Neispravan broj kugli, unesite ponovo!\n"; n = 0;}
           
        }
    }
    while (n <= 0 || jeLiSlovo(x2));
   
    std::vector<std::shared_ptr<Kugla>> v(n);
    for (int i=0; i<n; i++) {
        std::string x4{}, y4{}, z4{}, r4{};
        double x{}, y{}, z{}, r{};
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x4>>y4>>z4;
        int b = i+1;
        std::string s = "Unesite centar "+std::to_string(b)+". kugle: ";
        std::tuple<double, double, double> c = provjeriCentar(std::make_tuple(x4, y4, z4), i+1, "Neispravan centar\n",s);
        x = std::get<0>(c); y = std::get<1>(c); z = std::get<2>(c);
       
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r4;
       
        r = provjeriPoluprecnik(r4, i+1, c);
        x = std::get<0>(c); y = std::get<1>(c); z = std::get<2>(c);
        try {
            v[i] = std::make_shared<Kugla> (Kugla(x, y, z, r));
        }
        catch(std::domain_error e) {
            std::cout<<e.what()<<std::endl;
            i--;
        }
    }
     std::string dx, dy, dz;
    double delta_x{}, delta_y{}, delta_z{};
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    std::cin>>dx>>dy>>dz;
    std::tuple<double, double, double> t = provjeriCentar(std::make_tuple(dx, dy, dz), 10, "Neispravni parametri translacije, unesite ponovo!", "");
    if (jeLiSlovo(dx) || jeLiSlovo(dy) || jeLiSlovo(dz)) std::cout<<std::endl;
    delta_x = std::get<0>(t); delta_y = std::get<1>(t); delta_z = std::get<2>(t);
  
    std::transform(v.begin(), v.end(), v.begin(),
        [delta_x, delta_y, delta_z](std::shared_ptr<Kugla> k) {
            k->Transliraj(delta_x, delta_y, delta_z); 
            return k;
        });
        
     std::sort(v.begin(), v.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
         return k1->DajZapreminu() < k2->DajZapreminu();
     });
     
     std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
     std::for_each(v.begin(), v.end(), [](std::shared_ptr<Kugla> k) {
         k->Ispisi(); 
         std::cout<<std::endl;
     });
     
     std::cout<<"Kugla sa najvecom povrsinom je: ";
     Kugla k = **std::max_element(v.begin(), v.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
                return k1->DajPovrsinu() < k2->DajPovrsinu();
     });
     k.Ispisi();
     std::cout<<std::endl;
     
     try {
    int br{1};
    bool daLiSeSijeku = false;
     std::for_each(v.begin(), v.end(), [&v, &br, &daLiSeSijeku](const std::shared_ptr<Kugla> &k) {
                 if (v.size() == 1)  { throw std::domain_error("Ne postoje kugle koje se presjecaju!");  }
                 std::for_each(v.begin()+br, v.end(), [&v,&k, &daLiSeSijeku](const std::shared_ptr<Kugla> &k2) {
                     if (DaLiSeSijeku(*k, *k2)) {
                         std::cout<<"Presjecaju se kugle: ";
                         k->Ispisi();
                         std::cout<<std::endl;
                         k2->Ispisi();
                         std::cout<<std::endl;
                         daLiSeSijeku = true;
                     }
                    
                     
                    
                       
                 });

                br++;
     });
      if (daLiSeSijeku == false) std::cout<<"Ne postoje kugle koje se presjecaju!";
     }
    
     catch(std::domain_error e) {
         std::cout<<e.what()<<std::endl;
     }
     
   
	return 0;
}





