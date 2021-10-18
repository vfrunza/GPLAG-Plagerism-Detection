/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <iterator>
#include <iomanip>

class Berza {
    
    std::vector<int> v;
    int min, max;
  public:
    
    Berza(int min, int max) {
        if (min<=0 || max<=0) throw std::range_error("Ilegalne granicne cijene");
        Berza::min=min;
        Berza::max=max;
    }
    
    explicit Berza (int max) {
        if (min<=0) throw std::range_error("Ilegalne granicne cijene");
        Berza::min=0;
        Berza::max=max;
    }
    
    void RegistrirajCijenu (int nova) {
        if (nova<min || nova>max) throw std::range_error("Ilegalna cijena");
        v.push_back(nova);
    }
    
    int DajBrojRegistriranihCijena() const { return v.size(); }
    
    void BrisiSve() { v.resize(0); }
    
    int DajMinimalnuCijenu() const {
        if (v.size()==0) throw std::range_error("Nema registriranih cijena");
        return *(std::min_element(v.begin(), v.end()));
    }
    
    int DajMaksimalnuCijenu() const {
        if (v.size()==0) throw std::range_error("Nema registriranih cijena");
        return *(std::max_element(v.begin(), v.end()));
    }
    
    friend bool operator !(const Berza &b);
    
    int DajBrojCijenaVecihOd(int x) const {
        if (v.size()==0) throw std::range_error("Nema registriranih cijena");
        return std::count_if(v.begin(), v.end(), std::bind(std::greater<int>(), std::placeholders::_1, x));
    }
    
    void Ispisi() const {
        std::vector<double> pomocni;
        pomocni.resize(v.size());
        std::transform(pomocni.begin(), pomocni.end(), v.begin(), pomocni.begin(), std::plus<double>());
        std::sort(pomocni.begin(), pomocni.end(), std::greater<int>());
        std::transform(pomocni.begin(), pomocni.end(), pomocni.begin(), std::bind(std::divides<double>(), std::placeholders::_1, 100));
        std::streamsize ss=std::cout.precision();
        std::copy(pomocni.begin(), pomocni.end(), std::ostream_iterator<double>(std::cout << std::fixed << std::setprecision(2), " \n"));
        std::cout.precision(ss);
    }
    
    int operator [] (int k) const {
        if (k<0 || k>=v.size()) throw std::range_error("Neispravan indeks");
        return v.at(k);
    }
    
    friend Berza &operator ++(Berza &berz);
	friend Berza operator ++(Berza &berz, int);
		
	friend Berza &operator --(Berza &berz);
	friend Berza operator --(Berza &berz, int);
    
    friend Berza operator -(const Berza &berz);
    
    friend Berza operator +(const Berza &berz, int n);
    
	friend Berza operator +(int n, const Berza &berz);
	
	friend Berza operator -(const Berza &berz, int n);
	
	friend Berza operator -(int n, const Berza &berz);
		
	friend Berza &operator +=(Berza &berz, int n);
		
	friend Berza &operator -=(Berza &berz, int n);
	
	friend Berza &operator -=(Berza &b1, Berza &b2);
	
	friend Berza operator -(const Berza &b1, const Berza &b2);
    
    friend bool operator == (const Berza &b1, const Berza &b2);
    
    friend bool operator != (const Berza &b1, const Berza &b2);
};

Berza &operator ++(Berza &berz) {
    std::vector<int> pomocni(berz.v);
    std::transform(pomocni.begin(), pomocni.end(), pomocni.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
    if (std::count_if(pomocni.begin(), pomocni.end(), std::bind(std::less<int>(), std::placeholders::_1, berz.min)) || std::count_if(pomocni.begin(), pomocni.end(), std::bind(std::greater<int>(), std::placeholders::_1, berz.max))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    berz.v=pomocni;
    return berz;
}

Berza operator ++(Berza &berz, int) {
	Berza pomocna(berz);
	++berz;
	return pomocna;
}

Berza &operator --(Berza &berz) {
	std::vector<int> pomocni(berz.v);
    std::transform(pomocni.begin(), pomocni.end(), pomocni.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 100));
    if (std::count_if(pomocni.begin(), pomocni.end(), std::bind(std::less<int>(), std::placeholders::_1, berz.min)) || std::count_if(pomocni.begin(), pomocni.end(), std::bind(std::greater<int>(), std::placeholders::_1, berz.max))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    berz.v=pomocni;
	return berz;
}

Berza operator --(Berza &berz, int) {
	Berza pomocna(berz);
	--berz;
	return pomocna;
}

Berza operator -(const Berza &berz) {
    Berza pomocni(berz.min, berz.max);
    pomocni.v=berz.v;
    std::transform(pomocni.v.begin(), pomocni.v.end(), pomocni.v.begin(), std::bind(std::minus<int>(), berz.max+berz.min, std::placeholders::_1));
    return pomocni;
}

Berza operator +(const Berza &berz, int n) {
	Berza pomocna(berz.min, berz.max);
	pomocna.v=berz.v;
	pomocna+=n;
	return pomocna; 
}

Berza operator +(int n, const Berza &berz) {
	return berz+n;
}

Berza operator -(const Berza &berz, int n) {
	Berza pomocna(berz.min, berz.max);
	pomocna.v=berz.v;
	pomocna-=n;
	return pomocna;
}

Berza operator -(int n, const Berza &berz) {
	Berza pomocni(berz.min, berz.max);
	pomocni.v=berz.v;
	
	std::transform(pomocni.v.begin(), pomocni.v.end(), pomocni.v.begin(), std::bind(std::minus<int>(), n, std::placeholders::_1));
	if (std::count_if(pomocni.v.begin(), pomocni.v.end(), std::bind(std::less<int>(), std::placeholders::_1, berz.min)) || std::count_if(pomocni.v.begin(), pomocni.v.end(), std::bind(std::greater<int>(), std::placeholders::_1, berz.max))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
	
	return pomocni;
}

Berza &operator +=(Berza &berz, int n) {
    Berza pomocni(berz.min, berz.max);
	pomocni.v=berz.v;
	if (n<0) {
	    n=-n;
	    std::transform(pomocni.v.begin(), pomocni.v.end(), pomocni.v.begin(), std::bind(std::minus<int>(), std::placeholders::_1, n));
        if (std::count_if(pomocni.v.begin(), pomocni.v.end(), std::bind(std::less<int>(), std::placeholders::_1, berz.min)) || std::count_if(pomocni.v.begin(), pomocni.v.end(), std::bind(std::greater<int>(), std::placeholders::_1, berz.max))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
	}
	else {
	    std::transform(pomocni.v.begin(), pomocni.v.end(), pomocni.v.begin(), std::bind(std::plus<int>(), std::placeholders::_1, n));
        if (std::count_if(pomocni.v.begin(), pomocni.v.end(), std::bind(std::less<int>(), std::placeholders::_1, berz.min)) || std::count_if(pomocni.v.begin(), pomocni.v.end(), std::bind(std::greater<int>(), std::placeholders::_1, berz.max))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
	}
	berz.v=pomocni.v;
	return berz;
}

Berza &operator -=(Berza &berz, int n) {
	berz+=(-n);
	return berz;
}

Berza &operator -=(Berza &b1, Berza &b2) {
    Berza temp(b1-b2);
    b1.v=temp.v;
    return b1;
}

Berza operator -(const Berza &b1, const Berza &b2) {
    if (b1.max!=b2.max || b1.min!=b2.min || b1.v.size()!=b2.v.size()) throw std::domain_error("Nesaglasni operandi");
    
    Berza rez(b1.min, b1.max);
    rez.v=b1.v;
    
    std::transform(b1.v.begin(), b1.v.end(), b2.v.begin(), rez.v.begin(), std::minus<int>());
    if (std::count_if(rez.v.begin(), rez.v.end(), std::bind(std::less<int>(), std::placeholders::_1, b1.min)) || std::count_if(rez.v.begin(), rez.v.end(), std::bind(std::greater<int>(), std::placeholders::_1, b1.max))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    
    return rez;
}

bool operator == (const Berza &b1, const Berza &b2) {
    if (b1.max!=b2.max || b1.min!=b2.min || b1.v.size()!=b2.v.size()) return false;
    return std::equal(b1.v.begin(), b1.v.end(), b2.v.begin(), std::equal_to<int>());
}

bool operator != (const Berza &b1, const Berza &b2) {
    return !(b1==b2);
}

bool operator !(const Berza &b) {
    return !(b.v.size());
}

int main ()
{
    /*try {
        std::vector<int> cijene{50, 120, 133, 540, 3600};
        int min(1), max(3950);
        
        Berza b(min, max);
        
        for (int x: cijene) {
            b.RegistrirajCijenu(x);
        }
        
        b.Ispisi();
    
        std::cout << "Broj reg. cijena je " << b.DajBrojRegistriranihCijena() << std::endl;
        std::cout << "Broj reg. cijena vecih od 120 je " << b.DajBrojCijenaVecihOd(120) << std::endl;
        std::cout << "Minimalna cijena je " << b.DajMinimalnuCijenu() << std::endl;
        std::cout << "Maksimalna cijena je " << b.DajMaksimalnuCijenu() << std::endl;
        
        std::cout << std::endl;
        
        std::cout << "Treca cijena je " << b[2] << std::endl;
    
        b++;
        ++b;
        b.Ispisi();
    
        b--;
        --b;
        b.Ispisi(); 
    
        Berza negb(-b);
        negb.Ispisi();
    
    
        Berza b4(b+3);
        Berza b5(3+b);
    
        if (b4!=b5) std::cout << "Nesto ne valja" << std::endl;
        else std::cout << "Dobro je" << std::endl;
        b4.Ispisi();
    
    
        Berza b6(4000-b);
        b6.Ispisi();
    
        b.BrisiSve();
        if (!b) std::cout << "Obrisalo se";
    }
    catch(std::exception &iz) {
        std::cout << iz.what();
    }*/
    
    try {
         Berza b1 = Berza(600,4000);
         Berza b2 = Berza(600,4000);
         int n;
         std::cout << "Unesite broj cijena: ";
         std::cin >> n;
         try {
             int i=0;
             std::cout << "Unesite cijene u kf: " << std::endl;
             while(i!=n){
                 int kf;
                 std::cin >> kf;
                 b1.RegistrirajCijenu(kf);
                 i++;
             }

         } catch(std::exception &ex) {std::cout << "IZUZETAK: " << ex.what() << std::endl;}
             std::cout << "Broj registrovanih cijena: " << b1.DajBrojRegistriranihCijena() << std::endl;
             if(n-b1.DajBrojRegistriranihCijena()==0) std::cout<< "Sve ok" << std::endl;
             else std::cout << "Neuspjelo zapisivanje " << n-b1.DajBrojRegistriranihCijena() << " cijena" <<std::endl;

         std::cout << "Ispis: " << std::endl;
         b1.Ispisi();
         Berza b3=b1;
         std::cout << b3.DajMaksimalnuCijenu();
         b1.BrisiSve();
         std::cout << "Nakon brisanja b1, broj registrovanih cijena (b1): " << b1.DajBrojRegistriranihCijena();
         std::cout << std::endl;
         std::cout << " Max: " << b3.DajMaksimalnuCijenu() << " Min: " << b3.DajMinimalnuCijenu() <<std::endl;
         std::cout << "Broj cijena vecih od 1500: " << b3.DajBrojCijenaVecihOd(1500);
         if(b3==b2) std::cout << "b2 b3 isti" <<std::endl;
         if(b3!=b2) std::cout << "b2 b3 razlicit" << std::endl;
         std::cout << "Novi b3: ++" << std::endl;
         b3+=234;
         b3.Ispisi();
         std::cout << "Novi b3: --" << std::endl;
         b3-=12;
         b3.Ispisi();
         b2.RegistrirajCijenu(2321);
         b2.RegistrirajCijenu(659);
         b2.RegistrirajCijenu(1337);
         b2.RegistrirajCijenu(3000);
         std::cout << "B2: ispis " <<std::endl;
         b2.Ispisi(); std::cout <<std::endl;
         std::cout << "B3-b2: " << std::endl;
         b3=b3-b2;
         b3.Ispisi();
     } catch(std::exception &ex) {
         std::cout << "Izuzetak: " << ex.what() << std::endl;
     }
    
	return 0;
}
