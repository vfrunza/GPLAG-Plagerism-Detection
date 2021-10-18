/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <list>
#include <utility>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>




class Temperature {
    std::list<int> minimalneTemp {};
    std::list<int> maximalneTemp {}; 
     
     static bool provjraMaxMin(std::list<int> minimalna, std::list<int> maximalna) {
         auto br1 = std::count_if(minimalna.begin(), minimalna.end(), std::bind(std::less<int>(), std::placeholders::_1, *(minimalna.begin())));
         auto br2 = std::count_if(minimalna.begin(), minimalna.end(), std::bind(std::greater<int>(), std::placeholders::_1, *(maximalna.begin())));
         auto br3 = std::count_if(maximalna.begin(), maximalna.end(), std::bind(std::less<int>(), std::placeholders::_1, *(minimalna.begin())));
         auto br4 = std::count_if(maximalna.begin(), maximalna.end(), std::bind(std::greater<int>(), std::placeholders::_1, *(maximalna.begin())));
         if( br1 == 0 && br2 == 0 && br3 == 0 && br4 == 0) return true;
         return false;
     }
   
   
    
    public:
    Temperature(int minimalna, int maximalna) {
        if( minimalna > maximalna ) throw std::range_error("Nekorektne temperature");        //temperatura manja od minimalno dozvoljene ili veća od maksimalno dozvoljene ??, ili ukoliko je minimalna dnevna temperatura veća od maksimalne
        
        minimalneTemp.push_back(minimalna);
        maximalneTemp.push_back(maximalna);
    }
    
    void RegistrirajTemperature(const std::pair<int,int> temp) {
            if( temp.first > temp.second || temp.first < *(minimalneTemp.begin()) || temp.first > *(maximalneTemp.begin()) || temp.second < *(minimalneTemp.begin()) || temp.second > *(maximalneTemp.begin())) throw std::range_error("Nekorektne temperature"); //temperatura manja od minimalno dozvoljene ili veća od maksimalno dozvoljene ??, ili ukoliko je minimalna dnevna temperatura veća od maksimalne
           minimalneTemp.push_back(temp.first);
           maximalneTemp.push_back(temp.second);
    }
    
    void BrisiSve()  {
        minimalneTemp.clear();
        maximalneTemp.clear();
    }
    
    void BrisiNegativneTemperature()   {
       auto it2 = maximalneTemp.begin();
       static auto i = minimalneTemp.begin();
      
       auto it = std::find_if(i, minimalneTemp.end(), std::bind(std::less<int>(),std::placeholders::_1, 0));
       if(it != minimalneTemp.end()) {
        
       int dis = std::distance(minimalneTemp.begin(),it);
       
       std::advance(it2,dis);
       if(*it2 > 0) i++;
       if( *it2 < 0) {
           
           minimalneTemp.erase(it);
           maximalneTemp.erase(it2);
       }
        BrisiNegativneTemperature();
        }
        
           
       }
   
    
    int DajBrojRegistriranihTemperatura() const {
        return std::distance(minimalneTemp.begin(),minimalneTemp.end());
    }
    
    int DajMinimalnuTemperaturu() const {
        if(std::distance(minimalneTemp.begin(),minimalneTemp.end()) == 0) throw std::logic_error("Nema registriranih temperatura");
       auto pomocna = *(std::min_element(minimalneTemp.begin(), minimalneTemp.end(), std::bind(std::less<int>(),std::placeholders::_1, std::placeholders::_2)));
        return pomocna;
    }
    
    int DajMaksimalnuTemperaturu() const {
        if(std::distance(maximalneTemp.begin(),maximalneTemp.end()) == 0) throw std::logic_error("Nema registriranih temperatura");
       auto pomocna = *(std::max_element(maximalneTemp.begin(), maximalneTemp.end(), std::bind(std::less<int>(),std::placeholders::_1,std::placeholders::_2)));
        return pomocna;
    }
    
   int DajBrojTemperaturaVecihOd( int temp) const {
        if( std::distance(minimalneTemp.begin(),minimalneTemp.end()) == 0) throw std::logic_error("Nema registriranih temperatura");
        int brojac1 = std::count_if(maximalneTemp.begin(), maximalneTemp.end(),std::bind(std::greater<int>(), std::placeholders::_1, temp));
        return brojac1;
    }
    
    int DajBrojTemperaturaManjihOd(int temp) const {
        if( std::distance(minimalneTemp.begin(),minimalneTemp.end()) == 0) throw std::logic_error("Nema registriranih temperatura");
        int brojac = std::count_if(minimalneTemp.begin(), minimalneTemp.end(), std::bind(std::greater<int>(),temp, std::placeholders::_1));
        return brojac;
    }

    // ! ++ -- << + - += -= == != []
    friend bool operator !(const Temperature &max);
    friend Temperature &operator ++(Temperature &max); // koji valja ++t?
    friend Temperature operator ++( Temperature &max,int); //t++
    friend Temperature &operator --(Temperature &min);
    friend Temperature operator --(Temperature &min,int);
    friend std::ostream &operator <<(std::ostream &tok, const Temperature &t);
    friend std::vector<int> operator *(const Temperature &t);
    friend std::vector<int> operator +(const Temperature &t);
    friend std::vector<int> operator -(const Temperature &t);
    std::pair<int,int> operator [](int indeks) const;
    friend Temperature operator +(const Temperature &t, int q);
    friend Temperature operator -(const Temperature &t, int q);
    friend Temperature operator +(int q, const Temperature &t);
    friend Temperature operator -(int q, const Temperature &t);
    Temperature &operator +=( int q);
    Temperature &operator -=( int q);
    friend bool operator ==(const Temperature &p, const Temperature &q);
    friend inline bool operator !=(const Temperature &p, const Temperature &q);
    
};

  bool operator !(const Temperature &max) {
      auto br = std::distance(max.minimalneTemp.begin(),max.minimalneTemp.end());
      if(br != 0) return false;
      return true;
  }
  
  Temperature &operator ++(Temperature &max) {
     std::transform(max.minimalneTemp.begin(), max.minimalneTemp.end(),max.minimalneTemp.begin(), std::bind(std::plus<int>(),std::placeholders::_1,1));
     std::transform(max.maximalneTemp.begin(), max.maximalneTemp.end(), max.maximalneTemp.begin(), std::bind(std::plus<int>(),std::placeholders::_1,1));
     
     if(!Temperature::provjraMaxMin(max.minimalneTemp, max.maximalneTemp)) throw std::logic_error("Ilegalna operacija");            // il samo minimalne i max svega
     return max;
     
  }
  
  Temperature operator ++( Temperature &max,int) {
      std::transform(max.minimalneTemp.begin(), max.minimalneTemp.end(),max.minimalneTemp.begin(), std::bind(std::plus<int>(),std::placeholders::_1,1));
      std::transform(max.maximalneTemp.begin(), max.maximalneTemp.end(), max.maximalneTemp.begin(), std::bind(std::plus<int>(),std::placeholders::_1,1));
      
       if(!Temperature::provjraMaxMin(max.minimalneTemp, max.maximalneTemp)) throw std::logic_error("Ilegalna operacija");   //ko gore
    
     return max;
    
  }
  
  Temperature &operator --(Temperature &min) {
      std::transform(min.minimalneTemp.begin(), min.minimalneTemp.end(), min.minimalneTemp.begin(), std::bind(std::minus<int>(),std::placeholders::_1,1));
      std::transform(min.maximalneTemp.begin(), min.maximalneTemp.end(), min.maximalneTemp.begin(), std::bind(std::minus<int>(),std::placeholders::_1,1));
      
       if(!Temperature::provjraMaxMin(min.minimalneTemp, min.maximalneTemp)) throw std::logic_error("Ilegalna operacija"); //isto
      return min;
  }
  
  Temperature operator --(Temperature &min,int) {
      std::transform(min.minimalneTemp.begin(), min.minimalneTemp.end(), min.minimalneTemp.begin(), std::bind(std::minus<int>(),std::placeholders::_1,1));
      std::transform(min.maximalneTemp.begin(), min.maximalneTemp.end(), min.maximalneTemp.begin(), std::bind(std::minus<int>(),std::placeholders::_1,1));
      
      if(!Temperature::provjraMaxMin(min.minimalneTemp, min.maximalneTemp)) throw std::logic_error("Ilegalna operacija");  //isto
      return min;
  }

  std::vector<int> operator *(const Temperature &t) {
      std::vector<int> razlika(t.minimalneTemp.size());
      std::transform(t.minimalneTemp.begin(), t.minimalneTemp.end(), t.maximalneTemp.begin(), razlika.begin(),std::minus<int>());
      
      std::transform(razlika.begin(),razlika.end(), razlika.begin(), std::bind(std::multiplies<int>(), std::placeholders::_1,-1));
      razlika.erase(razlika.begin());
      
      return razlika;
  }
  
  std::vector<int> operator +(const Temperature &t) {
      std::vector<int> maxa(t.minimalneTemp.size());
      std::transform(t.maximalneTemp.begin(), t.maximalneTemp.end(), maxa.begin(), std::bind(std::minus<int>(),  std::placeholders::_1, *(t.maximalneTemp.begin())));
      maxa.erase(maxa.begin());
      return maxa;
  }
  
  std::vector<int> operator -(const Temperature &t) {
      std::vector<int> mina(t.minimalneTemp.size());
      std::transform(t.minimalneTemp.begin(), t.minimalneTemp.end(), mina.begin(), std::bind(std::minus<int>(),  std::placeholders::_1, *(t.minimalneTemp.begin())));
      mina.erase(mina.begin());
      return mina;
  }
  
  std::pair<int,int> Temperature::operator [](int indeks) const {
      if( indeks > std::distance(maximalneTemp.begin(), maximalneTemp.end())+1) throw std::range_error("Neispravan indeks");
      
      auto i = minimalneTemp.begin();
      auto j = maximalneTemp.begin();
      std::advance(i, indeks-1);
      std::advance(j, indeks-1);
      std::pair<int,int> paric(std::make_pair(*i,*j));
      return paric;
      
  }
  
  Temperature operator +(const Temperature &t, int q ) {
      Temperature p(t);
      std::transform(p.minimalneTemp.begin(), p.minimalneTemp.end(), p.minimalneTemp.begin(), std::bind(std::plus<int>(), std::placeholders::_1, q));
      std::transform(p.maximalneTemp.begin(), p.maximalneTemp.end(), p.maximalneTemp.begin(), std::bind(std::plus<int>(), std::placeholders::_1, q));
      
    auto kraj = std::find_if(p.minimalneTemp.begin(), p.minimalneTemp.end(), std::bind(std::less<int>(), std::placeholders::_1, *(p.minimalneTemp.begin())));
    if(kraj != p.minimalneTemp.end()) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    auto josnijekraj = std::find_if(p.maximalneTemp.begin(), p.maximalneTemp.end(), std::bind(std::greater<int>(), std::placeholders::_1, *(p.maximalneTemp.begin())));
    if(josnijekraj != p.maximalneTemp.end()) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
      
      return p;
  }
  
  Temperature operator -(const Temperature &t, int q) {
  Temperature p(t);
  std::transform(p.minimalneTemp.begin(), p.minimalneTemp.end(), p.minimalneTemp.begin(), std::bind(std::minus<int>(), std::placeholders::_1, q));
  std::transform(p.maximalneTemp.begin(), p.maximalneTemp.end(), p.maximalneTemp.begin(), std::bind(std::minus<int>(), std::placeholders::_1, q));
  
    auto kraj = std::find_if(p.minimalneTemp.begin(), p.minimalneTemp.end(), std::bind(std::less<int>(), std::placeholders::_1, *(p.minimalneTemp.begin())));
    if(kraj != p.minimalneTemp.end()) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    auto josnijekraj = std::find_if(p.maximalneTemp.begin(), p.maximalneTemp.end(), std::bind(std::greater<int>(), std::placeholders::_1, *(p.maximalneTemp.begin())));
    if(josnijekraj != p.maximalneTemp.end()) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
  
  return p;
  }
  
  Temperature operator +(int q, const Temperature &t) {
      Temperature p(t);
      std::transform(p.minimalneTemp.begin(), p.minimalneTemp.end(), p.minimalneTemp.begin(), std::bind(std::plus<int>(), std::placeholders::_1, q));
      std::transform(p.maximalneTemp.begin(), p.maximalneTemp.end(), p.maximalneTemp.begin(), std::bind(std::plus<int>(), std::placeholders::_1, q));
      
   auto kraj = std::find_if(p.minimalneTemp.begin(), p.minimalneTemp.end(), std::bind(std::less<int>(), std::placeholders::_1,*(p.minimalneTemp.begin())));
    if(kraj != p.minimalneTemp.end()) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    auto josnijekraj = std::find_if(p.maximalneTemp.begin(), p.maximalneTemp.end(), std::bind(std::greater<int>(), std::placeholders::_1, *(p.maximalneTemp.begin())));
    if(josnijekraj != p.maximalneTemp.end()) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
      
      return p;
  }
  
  Temperature operator -(int q, const Temperature &t) {
    Temperature p(t);
    std::transform(t.minimalneTemp.begin(), t.minimalneTemp.end(), p.maximalneTemp.begin(), std::bind(std::minus<int>(), q, std::placeholders::_1));
    std::transform(t.maximalneTemp.begin(), t.maximalneTemp.end(), p.minimalneTemp.begin(), std::bind(std::minus<int>(), q, std::placeholders::_1));
    
    auto kraj = std::find_if(p.minimalneTemp.begin(), p.minimalneTemp.end(), std::bind(std::less<int>(), std::placeholders::_1, *(p.minimalneTemp.begin())));
    if(kraj != p.minimalneTemp.end()) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    auto josnijekraj = std::find_if(p.maximalneTemp.begin(), p.maximalneTemp.end(), std::bind(std::greater<int>(), std::placeholders::_1, *(p.maximalneTemp.begin())));
    if(josnijekraj != p.maximalneTemp.end()) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    
    return p;
  }
  
  Temperature &Temperature::operator +=( int q) {
      std::transform(minimalneTemp.begin(), minimalneTemp.end(),minimalneTemp.begin(),std::bind(std::plus<int>(), std::placeholders::_1,q));// jesul iste vel ? trebal provjravat jel vece od max i min onih vragova
      std::transform(maximalneTemp.begin(),maximalneTemp.end(), maximalneTemp.begin(), std::bind(std::plus<int>(), std::placeholders::_1,q));
      
       if(!Temperature::provjraMaxMin(minimalneTemp, maximalneTemp)) throw std::logic_error("Ilegalna operacija");
      
      return *this;
  }
  
  Temperature &Temperature::operator -=( int q) {
      std::transform(minimalneTemp.begin(), minimalneTemp.end(), minimalneTemp.begin(), std::bind(std::minus<int>(), std::placeholders::_1,q));
      std::transform(maximalneTemp.begin(), maximalneTemp.end(), maximalneTemp.begin(), std::bind(std::minus<int>(), std::placeholders::_1,q));
      
       if(!Temperature::provjraMaxMin(minimalneTemp, maximalneTemp)) throw std::logic_error("Ilegalna operacija");
      
      return *this;
  }
  
  bool operator ==(const Temperature &p, const Temperature &q) { //mozel min i max lista bit razl dimenzija
     if( std::distance(p.minimalneTemp.begin(), p.minimalneTemp.end()) == std::distance(q.minimalneTemp.begin(), q.minimalneTemp.end()) &&    std::equal(p.minimalneTemp.begin(), p.minimalneTemp.end(), q.minimalneTemp.begin()) && std::equal(p.maximalneTemp.begin(), p.maximalneTemp.end(), q.maximalneTemp.begin())) return true;
     return false;
  }
  
  inline bool operator !=(const Temperature &p, const Temperature &q) {
      return !(p == q);
  }
  
  std::ostream &operator <<(std::ostream &tok, const Temperature &t) {
      int vel = std::distance(t.minimalneTemp.begin(), t.minimalneTemp.end());
      int brojac = 0;
      std::for_each(t.minimalneTemp.begin(), t.minimalneTemp.end(),[&brojac,vel,&tok]( int br) {
           if(brojac == vel-1) tok << br<<"\n";
           else  tok << br << " "; // dal poslije zadnjeg ide razmaka i novi red il samo novi red
          brojac++;
         
      });
      brojac = 0;
      std::for_each(t.maximalneTemp.begin(), t.maximalneTemp.end(), [&brojac,vel,&tok](int br) {
           if(brojac == vel-1) tok << br<<"\n";
           else  tok << br << " ";
          brojac++;
         
      } );
      
      return tok;
  }


int main ()
{
    try{
      //  Temperature m = Temperature(0,23);
     //   m.RegistrirajTemperature(std::make_pair(1,22));
    Temperature t = Temperature(-100,100);
    t.RegistrirajTemperature(std::make_pair(3,4));
    t.RegistrirajTemperature(std::make_pair(-3,-2));
    t.RegistrirajTemperature(std::make_pair(-3,-2));
    t.RegistrirajTemperature(std::make_pair(-1,2));
    auto m = 2 + t;
    std::cout<<m;
     auto l = *m;
   for(int a : l) std::cout<<a<<"  \n";
    std::cout<<"\n\n";
    std::cout<<t;
    
    t.BrisiNegativneTemperature();
    std::cout<<t;
    std::cout<< t.DajBrojRegistriranihTemperatura() <<std::endl;
    std::cout << t.DajBrojTemperaturaManjihOd(1) << std::endl;
    std::cout << t.DajBrojTemperaturaVecihOd(2) << std::endl;
    std::cout << t.DajMaksimalnuTemperaturu() << std::endl;
    std::cout << t.DajMinimalnuTemperaturu() << std::endl;
    if(!t) std::cout << "jes" << std::endl;
    else std::cout << "nije" << std::endl;
    t--;
    --t;
    std::cout << t << std::endl;
    t++;
    ++t;
    std::cout << t << std::endl;
    
    auto w = +t;
    for(int q : w) std::cout<<q<<"  \n";
    
    auto s = -t;
    for(int y : s) std::cout<<y<<"  \n";
    
    auto o = *t;
    for(int x : o) std::cout<<x<<"  \n";
    auto pa =t[1];
    std::cout << pa.first<<"    "<<pa.second << std::endl;
    t = t +1;
    std::cout << t << std::endl;
    t = 1 +t;
    std::cout << t << std::endl;
    t = t -1;
    std::cout << t << std::endl;
    t = 1-t;     //ne radi dobro
    std::cout << t << std::endl;
    t += 1;
    std::cout << t << std::endl;
    t -= 1;
    std::cout << t << std::endl;
    if(t == m) std::cout << "jes" << std::endl;
    else std::cout << "nije" << std::endl;
     if(t != m) std::cout << "jes razl" << std::endl;
    else std::cout << "nije" << std::endl;
    t.BrisiSve();
   std::cout << t << std::endl;
    }catch(std::logic_error l) {
        std::cout << l.what() << std::endl;
    }catch(std::range_error r) {
        std::cout << r.what() << std::endl;
    }
	return 0;
}

