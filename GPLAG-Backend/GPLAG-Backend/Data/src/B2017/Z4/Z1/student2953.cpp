/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <memory> 
#include <algorithm>
#include <tuple>
#include <utility>
const double pi(4*atan(1));

bool JesuLiJednake(double x, double y, double eps=1e-10) {
    if((x<0 && y>0) || (x>0 && y<0)) return false;
    return fabs(x-y) <= eps*(fabs(x) + fabs(y));
}

class Kugla {
  double x, y, z, r;
  public:
  explicit Kugla(double r=0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
      x=0;
      y=0;
      z=0;
  }
  Kugla(double x, double y, double z, double r=0) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    this -> x=x;
    this -> y=y;
    this -> z=z;
    this -> r=r;
  }
  explicit Kugla(const std::tuple<double, double, double> &centar, double r=0) {
    double x1, y1, z1;
    std::tie(x1, y1, z1) = centar;
    this -> x=x1;
    this -> y=y1;
    this -> z=z1;
    this -> r=r;
  }
  double DajX() const {
      return x;
  }
  double DajY() const {
      return y;
  }
  double DajZ() const {
      return z;
  }
  std::tuple<double, double, double> DajCentar() const {
    return std::make_tuple(x, y, z);
  }
  double DajPoluprecnik() const {
      return r;
  }
  double DajPovrsinu() const {
      return 4*pi*pow(r,2);
  }
  double DajZapreminu() const {
      return 4*pow(r,3)*pi/3.;
  }
  Kugla &PostaviX(double x) {
      Kugla::x=x;//this->x=x;
      return *this;
  }
  Kugla &PostaviY(double y) {
      Kugla::y=y;//this->x=x;
      return *this;
  }
  Kugla &PostaviZ(double z) {
      Kugla::z=z;//this->x=x;
      return *this;
  }
  Kugla &PostaviCentar(double x, double y, double z) {
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    return *this;
  }
  Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
    double x2, y2, z2;
    std::tie(x2, y2, z2) = centar;
    Kugla::x=x2;//this -> x=x;
    Kugla::y=y2;
    Kugla::z=z2;
    return *this;
  }
  Kugla &PostaviPoluprecnik(double r) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
    return *this;
  }
  void Ispisi() const {
    std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}" << std::endl; 
  }
  void Transliraj(double delta_x, double delta_y, double delta_z) {
    x += delta_x;
    y += delta_y;
    z += delta_z;
  }
  friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
  bool DaLiSadrzi(const Kugla &k) const {
    double d(sqrt(fabs(pow(x-k.x,2) + pow(y-k.y,2) + pow(z-k.z,2))));
    if(d<fabs(r-k.r) && !DaLiSeSijeku(*this, k)) return true;
    return false;
  }
  friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
  
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
  if(JesuLiJednake(k1.x, k2.x) && JesuLiJednake(k1.y, k2.y) && JesuLiJednake(k1.z, k2.z) && JesuLiJednake(k1.r, k2.r)) return true;
  return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
  if(JesuLiJednake(k1.r, k2.r)) return true;
  return false;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
  if(JesuLiJednake(k1.x, k2.x) && JesuLiJednake(k1.y, k2.y) && JesuLiJednake(k1.z, k2.z)) return true;
  return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
  double d(sqrt(pow(k1.x-k2.x,2) + pow(k1.y-k2.y,2) + pow(k1.z-k2.z,2)));
  /*if(JesuLiJednake(std::fabs(d), std::fabs(k1.r+k2.r))) return true;
  return false;*/
  if(fabs(d) == fabs(k1.r-k2.r)) return true;
  if(fabs(d) > k1.r+k2.r) return false;
  else return true;
  return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
  double d(sqrt(pow(k1.x-k2.x,2) + pow(k1.y-k2.y,2) + pow(k1.z-k2.z,2)));
  if(DaLiSeDodirujuIzvana(k1,k2) == true) return false;
  if(JesuLiJednake(d, fabs(k1.r-k2.r))) return true;
  return false;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
  if(DaLiSeSijeku(k1,k2) == true && !(RastojanjeCentara(k1,k2) > fabs(k1.r + k2.r))) return false;
  return true;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
  double d(sqrt(pow(k1.x-k2.x,2) + pow(k1.y-k2.y,2) + pow(k1.z-k2.z,2)));
  if(fabs(k2.r-k1.r) < fabs(d) && fabs(d) < k1.r+k2.r) return true;
  return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
  double d(sqrt(pow(k1.x-k2.x,2) + pow(k1.y-k2.y,2) + pow(k1.z-k2.z,2)));
  return d;
}


int main ()
{
  int broj;
  Kugla kugl;
  std::cout << "Unesite broj kugla: ";
  std::cin >> broj;
  while(broj<=0 || !std::cin) {
    std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cin >> broj;
  }
  
  double x, y, z, r;
  std::vector<std::shared_ptr<Kugla>> v(broj);
  for (int i(0); i < broj; i++) {
    try {
      do {
      std::cin.clear();
      std::cin.ignore(1000, '\n');

    std::cout << "Unesite centar " << i+1 << ". kugle: ";
    std::cin >> x >> y >> z;
    if(!std::cin) {
      std::cout << "Neispravan centar" << std::endl;
      std::cin >> x >> y >> z;
      continue;
    }
    std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
    std::cin >> r;
    if(!std::cin) {
      std::cout << "Ilegalan poluprecnik" << std::endl;
    }
    }
    while(!std::cin);
    
    kugl.PostaviX(x);
    kugl.PostaviY(y);
    kugl.PostaviZ(z);
    kugl.PostaviPoluprecnik(r);
    v[i] = std::make_shared<Kugla>(kugl);
    }
    catch(std::domain_error e) {
      std::cout << e.what() << std::endl;
      i--;
    }
    catch(std::bad_alloc) {
      std::cout << "Nema dovoljno memorije!" << std::endl;
      return 0;
    }
    catch(...) {
      std::cout << "nadam se da je ovaj ";
    }
  }
  
  std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
  double delta_z, delta_y, delta_x;
  std::cin >> delta_x >> delta_y >> delta_z;
	while(!std::cin) {
	  std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
	  std::cin.clear(),
	  std::cin.ignore(10000, '\n');
	  std::cin >> delta_x >> delta_y >> delta_z;
	}
	std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
	std::transform(v.begin(), v.end(), v.begin(), [delta_x, delta_y, delta_z](std::shared_ptr<Kugla> &p) {
	  p->Transliraj(delta_x, delta_y, delta_z);
	  return p;
	});
	std::sort(v.begin(), v.end(), [](const std::shared_ptr<Kugla> &p1, const std::shared_ptr<Kugla> &p2) {
	  return p1->DajZapreminu() < p2->DajZapreminu();
	});
	for_each(v.begin(), v.end(), [](const std::shared_ptr<Kugla> &p) {
	  p->Ispisi();
	});
	auto pom(*std::max_element(v.begin(), v.end(), [](const std::shared_ptr<Kugla> &p1, const std::shared_ptr<Kugla> &p2) {
	  return p1->DajPovrsinu() < p2->DajPovrsinu();
	}));
	
	std::cout << "Kugla sa najvecom povrsinom je: ";
	pom->Ispisi();
	
	bool ima(false);
	int indeks(0);
	
	for_each(v.begin(), v.end(), [&indeks, &ima, v](const std::shared_ptr<Kugla> &p) {
	  indeks++;
	  
	  for_each(v.begin() + indeks, v.end(), [&p, &ima](const std::shared_ptr<Kugla> &p2) {
	    
	    if(DaLiSeSijeku(*p, *p2) == true) {
	      std::cout << "Presjecaju se kugle: ";
	      p->Ispisi();
	      p2->Ispisi();
	      ima = true;
	    }
	 
	  });
	});
	
	if(ima==false) std::cout << "Ne postoje kugle koje se presjecaju!" << std::endl;
	
	return 0;
}
