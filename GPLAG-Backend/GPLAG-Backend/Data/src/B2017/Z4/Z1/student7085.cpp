/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

const double  PI = 4 * atan(1);
const double EPSILON = pow (10,-10);

class Kugla
{


    double X,Y,Z,R;
 
    
    public:

    explicit Kugla(double r = 0) {if (r < 0) throw std::domain_error ("Ilegalan poluprecnik"); X=0;Y=0;Z=0;R=r;}
    
    Kugla(double x, double y, double z, double r = 0) {
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik");

        X = x;
        Y = y;
        Z = z;
        R = r;
       
        
    };
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik");
        R=r;
        X = std::get<0>(centar);
        Y = std::get<1>(centar);
        Z = std::get<2>(centar);

    }  ;

    double DajX() const {
        return X;
    };
    double DajY() const {
        return Y;
    };
    double DajZ() const {
        return Z;
    };
    std::tuple<double, double, double> DajCentar() const {
        std::tuple<double,double,double> temp;
        temp = std::make_tuple(X,Y,Z);
        return temp;

    };
    double DajPoluprecnik() const {
        return R;
    };

    double DajPovrsinu() const {
        double P;
        P = PI * R * R;

        return P;

    };
    double DajZapreminu() const {
        double Vol;
        Vol = ((4.0 / 3.0) * PI * (R * R * R));
        return Vol;

    };

    Kugla &PostaviX(double x) {
        X = x;
        return *this;

    }
    Kugla &PostaviY(double y) {
        Y = y;
        return *this;
    };
    Kugla &PostaviZ(double z) {
        Z = z;
        return *this;
    };
    Kugla &PostaviCentar(double x, double y, double z) {
        X = x;
        Y = y;
        Z = z;
        return *this;


    };
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        
        X = std::get<0>(centar);
         Y = std::get<1>(centar);
          Z = std::get<2>(centar);
        
        return *this;
    };


    Kugla &PostaviPoluprecnik(double r) {
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik");
        R = r;
        return *this;
    };

    void Ispisi() const {

        std::cout << "{(" << X << "," << Y << "," << Z << ")," << R << "}\n";

    };
    void Transliraj(double delta_x, double delta_y, double delta_z) {

        X += delta_x;
        Y += delta_y;
        Z += delta_z;

    };

    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
        // x = y ODNOSNO fabs (x-y) < epsilon * (fabs(x)+fabs(y))
        if (!(k1.X - k2.X < EPSILON * (fabs(k1.X)+fabs(k2.X)))) return false;
        else if (!(k1.Y - k2.Y < EPSILON * (fabs(k1.Y)+fabs(k2.Y)))) return false;
        else if (!(k1.Z - k2.Z < EPSILON * (fabs(k1.Z)+fabs(k2.Z)))) return false;
        else if (!(k1.R - k2.R < EPSILON * (fabs(k1.R)+fabs(k2.R)))) return false;

        return true;


    };


    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {

        if ((fabs(k1.R - k2.R) < EPSILON * (fabs(k1.R)+fabs(k2.R)))) return true;

        return false;


    };

    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {

        std::tuple<double,double,double> prva,druga;
        prva = k1.DajCentar();
        druga = k2.DajCentar();

        if (!fabs((std::get<0>(prva) - std::get<0>(druga)) < EPSILON * (fabs(std::get<0>(prva))+fabs(std::get<0>(druga))))) return false;
        if (!fabs((std::get<1>(prva) - std::get<1>(druga)) < EPSILON * (fabs(std::get<1>(prva))+fabs(std::get<1>(druga))))) return false;
        if (!fabs((std::get<2>(prva) - std::get<2>(druga)) < EPSILON * (fabs(std::get<2>(prva))+fabs(std::get<2>(druga))))) return false;

        return true;


    };



    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {

        double x = RastojanjeCentara(k1,k2);
        double y = k1.R + k2.R;

        if (!(fabs(x - y) < EPSILON * (fabs(x)+fabs(y)))) return false;
        return true;

    };

    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {

        double x = RastojanjeCentara(k1,k2);
        double y = k1.DajPoluprecnik() - k2.DajPoluprecnik();

        if (!(fabs(x - y) < EPSILON * (fabs(x)+fabs(y)))) return false;
        return true;


    };


    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {

        double x = RastojanjeCentara(k1,k2);
        double razlikaP = k1.R - k2.R;

        if (fabs(razlikaP) < x) return true;
        return false;

    };


    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
        double x = RastojanjeCentara(k1,k2);
        double temp = k1.R + k2.R;
        double tempminus = fabs(k1.R-k2.R);
        if (!(x<temp && x>tempminus)) return false;
        return true;
        
       
            };

    bool DaLiSadrzi(const Kugla &k) const {

        double AB = sqrt ((pow((k.X-X),2)) +(pow((k.Y-Y),2)) + (pow((k.Z-Z),2)));
        return (fabs(k.R-R) - AB < 0);


    };


    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {

        std::tuple<double,double,double> prva,druga;
        prva = k1.DajCentar();
        druga = k2.DajCentar();

        double povratna;
        
      
        povratna = sqrt( pow( std::get<0>(prva) - std::get<0>(druga), 2 ) +
                     pow( std::get<1>(prva) - std::get<1>(druga), 2 ) +
                     pow( std::get<2>(prva) - std::get<2>(druga), 2 ));
                     
        return povratna;

    };


};

void OcistiTok ()
{
    std::cin.clear();
    std::cin.ignore (1000,'\n');
}




void UnosBroja (std::string s, double &broj)  //Kopirana sa jedne od prethodnih zadaca
{

    std::cin >> broj;

    while (!std::cin || broj<=0) {


        std::cout << s << std::endl;
        std::cin.clear();
        std::cin.ignore (1000,'\n');
        std::cin >> broj;

    }
}




int main ()
{

    double n;
    
    
    std::cout << "Unesite broj kugla: ";
    UnosBroja("Neispravan broj kugli, unesite ponovo!",n);

    std::vector<std::shared_ptr<Kugla>> pok(n);

    try {

        for (int i = 0; i < n; i++) {
            double x,y,z,r;


            for (;;) {
                std::cout << "Unesite centar " << i+1 << ". kugle: ";
                std::cin >> x >> y >> z;

                if (!std::cin) {
                    std::cout << "Neispravan centar\n";
                    OcistiTok();
                    continue;
                }


                std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";

                std::cin >> r;

                if (!std::cin || r<0) {
                    std::cout << "Ilegalan poluprecnik\n";
                    OcistiTok();
                    continue;
                }

                break;
            }
            try {

                std::shared_ptr<Kugla> p(new Kugla(x,y,z,r));
                
                pok[i] = p;

            } catch(const std::domain_error &e) {
                std::cout << e.what() << std::endl;
            } catch (std::bad_alloc) {
                throw;
            }

        }
    } catch (...) {
        std::cout << "Problemi sa memorijom";
    }

    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double xi,yi,zi;


    for (;;) {
        std::cin >> xi >> yi >> zi;

        if (!std::cin) {
            std::cout << "Neispravni parametri translacije, unesite ponovo!\n";
            OcistiTok();
            continue;
        }
        break;
    }
    std::transform (pok.begin(),pok.end(),pok.begin(), [xi,yi,zi] (std::shared_ptr<Kugla> p)  {
       (*p).Transliraj(xi,yi,zi);
        
        return p;  });
    
    std::sort (pok.begin(),pok.end(),[] (std::shared_ptr<Kugla> prva, std::shared_ptr<Kugla> druga) -> bool {
        return (*prva).DajZapreminu()<(*druga).DajZapreminu();
    });
    
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";

    std::for_each(pok.begin(), pok.end(), [](std::shared_ptr<Kugla> sladoleda) {(*sladoleda).Ispisi();});
    
    std::cout << "Kugla sa najvecom povrsinom je: ";
    auto pokazivac = (*(*max_element(pok.begin(),pok.end(),[](std::shared_ptr<Kugla> prva,std::shared_ptr<Kugla> druga) {
            
            return (*prva).DajPovrsinu()<(*druga).DajPovrsinu();
        
    })));
    
    pokazivac.Ispisi();

    int brojac(0);
    std::for_each(pok.begin(), pok.end(), [pok,&brojac](std::shared_ptr<Kugla> prva) {
        
      auto it(std::find(pok.begin(),pok.end(),prva));
      int indeks (it-pok.begin());
      
        
       std::for_each(pok.begin()+indeks+1, pok.end(), [prva,&brojac](std::shared_ptr<Kugla> druga) {
           
       
         
            if(DaLiSeSijeku(*prva,*druga)) {
                brojac++;
                std::cout << "Presjecaju se kugle: ";
                (*prva).Ispisi();
                (*druga).Ispisi();
            }});
        
        
        
    });
    
        if (brojac==0) std::cout << "Ne postoje kugle koje se presjecaju!";
        
    return 0;
}
