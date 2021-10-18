/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <functional>
#include <algorithm>
#include <iterator>  
#include <vector>


class Temperature {
    private:
    std::list<int> minimalne;
    std::list<int> maximalne;
    int min_temp;
    int max_temp;
    public:
    Temperature(int min, int max) {
        if(min>max) throw std::range_error("Nekorektne temperature");
        else {min_temp=min; 
            max_temp=max;
        }
        
    }
    
    void RegistrirajTemperature(std::pair<int,int> par) {
        if(par.first>par.second) throw std::range_error("Nekorektne temperature");
        if(par.first<min_temp || par.second>max_temp) throw std::range_error("Nekorektne temperature");
        else {minimalne.push_back(par.first); 
            maximalne.push_back(par.second);
        }
    }
    
    void BrisiSve() {
        minimalne.clear();
        maximalne.clear();
    }
    void BrisiNegativneTemperature() {
        auto it1=minimalne.begin();
        auto it2=maximalne.begin();
        int brojac=0;
        while(it1!=minimalne.end()) {
            if (*it1<0 || *it2<0) {minimalne.remove(brojac); maximalne.remove(brojac);}
            brojac++;
            it1++;
            it2++;
        }
    }
    int DajBrojRegistriranihTemperatura() {return minimalne.size();}
    
    int DajMinimalnuTemperaturu() {
        int min= *min_element(minimalne.begin(),minimalne.end());
        return min;
    }
    int DajMaksimalnuTemperaturu() { 
        int max= *max_element(maximalne.begin(),maximalne.end());
        return max;
    }
    int DajBrojTemperaturaVecihOd(int a) {
        int brojac= count_if(maximalne.begin(),maximalne.end(),bind(std::greater<int>(),std::placeholders::_1,a));
        return brojac;
    }
     int DajBrojTemperaturaManjihOd(int a) {
       int brojac= count_if(minimalne.begin(),minimalne.end(),bind(std::less<int>(),std::placeholders::_1,a));
        return brojac;
    }
    bool operator !() {if (minimalne.size()==0) return true; else return false;}
    
    Temperature &operator ++() {
        std::list<int> lista(minimalne.size(),1);
        std::list<int> pomocna(minimalne.size(),0);
        transform(minimalne.begin(),minimalne.end(),lista.begin(),minimalne.begin(), std::plus<int>());
        copy(minimalne.begin(),minimalne.end(),pomocna.begin());
        transform(pomocna.begin(),pomocna.end(),maximalne.begin(),pomocna.begin(), std::minus<int>());
       
         int brojac = count_if(pomocna.begin(),pomocna.end(),bind(std::greater<int>(),std::placeholders::_1, 0));
        if(brojac>0){ 
            transform(minimalne.begin(),minimalne.end(),lista.begin(),minimalne.begin(), std::minus<int>());
            throw std::logic_error("Ilegalna operacija");}
            return *this;
    }
    
    
    Temperature &operator --() {
        std::list<int> lista(minimalne.size(),-1);
        std::list<int> pomocna(minimalne.size(),0);
        transform(maximalne.begin(),maximalne.end(),lista.begin(),maximalne.begin(), std::plus<int>());
        copy(maximalne.begin(),maximalne.end(),pomocna.begin());
        transform(pomocna.begin(),pomocna.end(),minimalne.begin(),pomocna.begin(), std::minus<int>());
       
         int brojac = count_if(pomocna.begin(),pomocna.end(),bind(std::less<int>(),std::placeholders::_1, 0));
        if(brojac>0){ 
            transform(maximalne.begin(),maximalne.end(),lista.begin(),maximalne.begin(), std::minus<int>());
            throw std::logic_error("Ilegalna operacija");}
            return *this;
    }
    
    Temperature operator --(int a) {
        Temperature rez =*this;
        std::list<int> lista(minimalne.size(),-1);
        std::list<int> pomocna(minimalne.size(),0);
        transform(maximalne.begin(),maximalne.end(),lista.begin(),maximalne.begin(), std::plus<int>());
        copy(maximalne.begin(),maximalne.end(),pomocna.begin());
        transform(pomocna.begin(),pomocna.end(),minimalne.begin(),pomocna.begin(), std::minus<int>());
       
         int brojac = count_if(pomocna.begin(),pomocna.end(),bind(std::less<int>(),std::placeholders::_1, 0));
        if(brojac>0){ 
            transform(maximalne.begin(),maximalne.end(),lista.begin(),maximalne.begin(), std::minus<int>());
            throw std::logic_error("Ilegalna operacija");}
            return rez;;
            
    }
    
    Temperature operator++(int a) {
        
        Temperature rez = *this;
        std::list<int> lista(minimalne.size(),1);
        std::list<int> pomocna(minimalne.size(),0);
        transform(minimalne.begin(),minimalne.end(),lista.begin(),minimalne.begin(), std::plus<int>());
        copy(minimalne.begin(),minimalne.end(),pomocna.begin());
        transform(pomocna.begin(),pomocna.end(),maximalne.begin(),pomocna.begin(), std::minus<int>());
       
         int brojac = count_if(pomocna.begin(),pomocna.end(),bind(std::greater<int>(),std::placeholders::_1, 0));
        if(brojac>0){ 
            transform(minimalne.begin(),minimalne.end(),lista.begin(),minimalne.begin(), std::minus<int>());
            throw std::logic_error("Ilegalna operacija");}
      return rez;  
    }
    
    std::vector<int> operator*() {
        std::vector<int> v(minimalne.size());
        transform(maximalne.begin(),maximalne.end(),minimalne.begin(),v.begin(),std::minus<int>());
        return v;
    }
    
    std::pair<int,int> operator [](int a) {
        if (a>minimalne.size()) throw std::range_error("Neispravan indeks");
        int prvi, drugi;
        auto it1=minimalne.begin();
        auto it2 =maximalne.begin();

       advance(it1,a-1);
       advance(it2,a-1);
        prvi=*it1;
        drugi= *it2;
        return std::pair<int,int>(prvi, drugi);
    }
    
    friend Temperature operator+(Temperature t, int a) {
        std::vector<int> v(t.minimalne.size(),a);
        std::vector<int> pomocna_maximalna(t.minimalne.size(),t.max_temp);
        std::vector<int> pomocna_minimalna(t.minimalne.size(),t.min_temp);
       
        
         transform(t.minimalne.begin(),t.minimalne.end(),v.begin(),t.minimalne.begin(),std::plus<int>());
          transform(t.maximalne.begin(),t.maximalne.end(),v.begin(),t.maximalne.begin(),std::plus<int>());
         
          transform(pomocna_maximalna.begin(),pomocna_maximalna.end(),t.maximalne.begin(),pomocna_maximalna.begin(),std::minus<int>());
          
          transform(pomocna_minimalna.begin(),pomocna_minimalna.end(),t.minimalne.begin(),pomocna_minimalna.begin(),std::minus<int>());
          
          int brojac1 = count_if(pomocna_maximalna.begin(),pomocna_maximalna.end(),bind(std::less<int>(),std::placeholders::_1, 0));
          int brojac2 = count_if(pomocna_minimalna.begin(),pomocna_minimalna.end(),bind(std::greater<int>(),std::placeholders::_1, 0));
          
          if (brojac1>0 || brojac2>0) {
             
              transform(t.minimalne.begin(),t.minimalne.end(),v.begin(),t.minimalne.begin(),std::minus<int>());
          transform(t.maximalne.begin(),t.maximalne.end(),v.begin(),t.maximalne.begin(),std::minus<int>());
          
          throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
              
          }
          
          return t;
    }
    
    friend std::vector<int> operator+(Temperature t) {
        std::vector<int> pomocna(t.minimalne.size(),t.max_temp);
        std::vector<int> v(t.minimalne.size(),0);
        transform(pomocna.begin(),pomocna.end(),t.maximalne.begin(),v.begin(),std::minus<int>());
        return v;
    }
    
    friend std::vector<int> operator-(Temperature t) {
        std::vector<int> pomocna(t.minimalne.size(),t.min_temp);
        std::vector<int> v(t.minimalne.size(),0);
        transform(t.minimalne.begin(),t.minimalne.end(),pomocna.begin(),v.begin(),std::minus<int>());
        return v;
    }
    
    friend Temperature operator+(int a,Temperature t) {
        std::vector<int> v(t.minimalne.size(),a);
        std::vector<int> pomocna_maximalna(t.minimalne.size(),t.max_temp);
        std::vector<int> pomocna_minimalna(t.minimalne.size(),t.min_temp);
       
        
         transform(t.minimalne.begin(),t.minimalne.end(),v.begin(),t.minimalne.begin(),std::plus<int>());
          transform(t.maximalne.begin(),t.maximalne.end(),v.begin(),t.maximalne.begin(),std::plus<int>());
         
          transform(pomocna_maximalna.begin(),pomocna_maximalna.end(),t.maximalne.begin(),pomocna_maximalna.begin(),std::minus<int>());
          
          transform(pomocna_minimalna.begin(),pomocna_minimalna.end(),t.minimalne.begin(),pomocna_minimalna.begin(),std::minus<int>());
          
          int brojac1 = count_if(pomocna_maximalna.begin(),pomocna_maximalna.end(),bind(std::less<int>(),std::placeholders::_1, 0));
          int brojac2 = count_if(pomocna_minimalna.begin(),pomocna_minimalna.end(),bind(std::greater<int>(),std::placeholders::_1, 0));
          
          if (brojac1>0 || brojac2>0) {
              
              transform(t.minimalne.begin(),t.minimalne.end(),v.begin(),t.minimalne.begin(),std::minus<int>());
          transform(t.maximalne.begin(),t.maximalne.end(),v.begin(),t.maximalne.begin(),std::minus<int>());
          
          throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
              
          }
          
          return t;
    }
    friend Temperature operator-(Temperature t, int a) {
        std::vector<int> v(t.minimalne.size(),a);
        std::vector<int> pomocna_maximalna(t.minimalne.size(),t.max_temp);
        std::vector<int> pomocna_minimalna(t.minimalne.size(),t.min_temp);
        
         transform(t.minimalne.begin(),t.minimalne.end(),v.begin(),t.minimalne.begin(),std::minus<int>());
          transform(t.maximalne.begin(),t.maximalne.end(),v.begin(),t.maximalne.begin(),std::minus<int>());
          
          
          transform(pomocna_maximalna.begin(),pomocna_maximalna.end(),t.maximalne.begin(),pomocna_maximalna.begin(),std::minus<int>());
          
          transform(pomocna_minimalna.begin(),pomocna_minimalna.end(),t.minimalne.begin(),pomocna_minimalna.begin(),std::minus<int>());
          
          int brojac1 = count_if(pomocna_maximalna.begin(),pomocna_maximalna.end(),bind(std::less<int>(),std::placeholders::_1, 0));
          int brojac2 = count_if(pomocna_minimalna.begin(),pomocna_minimalna.end(),bind(std::greater<int>(),std::placeholders::_1, 0));
          
          if (brojac1>0 || brojac2>0) {
              
              transform(t.minimalne.begin(),t.minimalne.end(),v.begin(),t.minimalne.begin(),std::minus<int>());
          transform(t.maximalne.begin(),t.maximalne.end(),v.begin(),t.maximalne.begin(),std::minus<int>());
          
          throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
              
          }
          
          return t;
    }
    friend Temperature operator-(int a,Temperature t) {
        std::vector<int> v(t.minimalne.size(),a);
        std::list<int> pomocna(t.minimalne.size(),0);
        std::vector<int> pomocna_maximalna(t.minimalne.size(),t.max_temp);
        std::vector<int> pomocna_minimalna(t.minimalne.size(),t.min_temp);
        
        transform(v.begin(),v.end(),t.minimalne.begin(),t.minimalne.begin(),std::minus<int>());
        transform(v.begin(),v.end(),t.maximalne.begin(),t.maximalne.begin(),std::minus<int>());
         //transform(t.minimalne.begin(),t.minimalne.end(),v.begin(),t.minimalne.begin(),std::minus<int>());
          //transform(t.maximalne.begin(),t.maximalne.end(),v.begin(),t.maximalne.begin(),std::minus<int>());
          copy(t.minimalne.begin(),t.minimalne.end(),v.begin());
          copy(t.maximalne.begin(),t.maximalne.end(),t.minimalne.begin());
          copy(v.begin(),v.end(),t.maximalne.begin());
          
         copy(t.minimalne.begin(),t.minimalne.end(),pomocna.begin());
        transform(pomocna.begin(),pomocna.end(),t.maximalne.begin(),pomocna.begin(), std::minus<int>());
        
        transform(pomocna_maximalna.begin(),pomocna_maximalna.end(),t.maximalne.begin(),pomocna_maximalna.begin(),std::minus<int>());
          
          transform(pomocna_minimalna.begin(),pomocna_minimalna.end(),t.minimalne.begin(),pomocna_minimalna.begin(),std::minus<int>());
          
          int brojac1 = count_if(pomocna_maximalna.begin(),pomocna_maximalna.end(),bind(std::less<int>(),std::placeholders::_1, 0));
          int brojac2 = count_if(pomocna_minimalna.begin(),pomocna_minimalna.end(),bind(std::greater<int>(),std::placeholders::_1, 0));
          
          if (brojac1>0 || brojac2>0) {
              
              transform(t.minimalne.begin(),t.minimalne.end(),v.begin(),t.minimalne.begin(),std::minus<int>());
          transform(t.maximalne.begin(),t.maximalne.end(),v.begin(),t.maximalne.begin(),std::minus<int>());
          
          throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
              
          }
       
         int brojac = count_if(pomocna.begin(),pomocna.end(),bind(std::greater<int>(),std::placeholders::_1, 0));
        if(brojac>0){ 
            
            copy(v.begin(),v.end(),t.minimalne.begin());
          copy(t.minimalne.begin(),t.minimalne.end(),t.maximalne.begin());
          copy(t.maximalne.begin(),t.maximalne.end(),v.begin());
            
            throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");}
          
          return t;
    }
    
    Temperature operator += (int a) {*this=*this+a; return *this;}
     Temperature operator -= (int a) {*this=*this-a; return *this;}
     
     friend bool operator == (Temperature t1, Temperature t2) {
         std::vector<int> v1 (t1.minimalne.size(),0);
         std::vector<int> v2 (t1.minimalne.size(),0);
         if (t1.minimalne.size()==t2.minimalne.size()&&t1.max_temp==t2.max_temp && t1.min_temp==t2.min_temp) {
             std::vector<int> v1 (t1.minimalne.size(),0);
             transform(t1.minimalne.begin(),t1.minimalne.end(),t2.minimalne.begin(),v1.begin(),std::minus<int>());
             transform(t1.maximalne.begin(),t1.maximalne.end(),t2.maximalne.begin(),v2.begin(),std::minus<int>());
             int brojac1 = count(v1.begin(),v1.end(),0);
             int brojac2 = count(v2.begin(),v2.end(),0);
             if(brojac1==t1.minimalne.size() && brojac2==t1.maximalne.size()) return true;
         }
         return false;
         
     }
      
      friend bool operator != (Temperature t1, Temperature t2) {return !(t1==t2);}
        
    friend std::ostream &operator <<(std::ostream &tok, const Temperature &temp) {
        std::ostream_iterator<int> it(tok, " ");
        copy(temp.minimalne.begin(),temp.minimalne.end(),it);
        std::cout<<std::endl;
        copy(temp.maximalne.begin(),temp.maximalne.end(),it);
        std::cout<<std::endl;
        
        return tok;
    }
    
    
};




int main ()
{   Temperature t1(-20,20);
    t1.RegistrirajTemperature(std::pair<int,int>(3,4));
    t1.RegistrirajTemperature(std::pair<int,int>(-5,-5));
    Temperature t2(-20,20);
    t2.RegistrirajTemperature(std::pair<int,int>(3,4));
    t2.RegistrirajTemperature(std::pair<int,int>(-5,-5));
    //t.RegistrirajTemperature(std::pair<int,int>(1,13));
    //t.RegistrirajTemperature(std::pair<int,int>(-7,20));
    //std::pair <int,int> par = t[3];
    //std::cout<<par.first<<", "<<par.second;
    //std::vector<int> v= +t;
   //t-=2;
    //if (t1!=t2) std::cout<<"da"; else std::cout<<"ne";
   // t.Ispisi();
   /*std::vector<int> v= -t;
     t.Ispisi();
    for (int i=0;i<v.size();i++) {std::cout<<v[i]<<std::endl;}*/
   std::cout<<t1<<t2;
   // int veci = t.DajBrojTemperaturaManjihOd(3);
    //std::cout<<veci;
	return 0;
}


