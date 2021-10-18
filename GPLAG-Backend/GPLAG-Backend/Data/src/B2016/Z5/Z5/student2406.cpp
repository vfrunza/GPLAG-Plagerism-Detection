#include <iostream>
#include <memory>
#include <functional>
#include <list>
#include <cmath>
#include <vector> 
#include <stdexcept>
#include <algorithm>
#include <memory>

class Temperature
{
    std::list<int> min_temp;
    std::list<int> max_temp;
    int max, min;
public:

    Temperature(int Max, int Min) {
        if(min>max) throw std::range_error("Nekorektne temperature"); 
        max=Max;
        min=Min;
    }
        void RegistrirajTemperature(std::pair<int,int>x) {
            std::for_each(max_temp.begin(),max_temp.end(),[x](const int &y) {
                if(x.second>x.first||x.first>max) throw std::range_error("Nekorektne temperature");
                max_temp.push_back(y);
            });
             std::for_each(min_temp.begin(),min_temp.end(),[x](const int &z) {
                if(x.second>min) throw std::range_error("Nekorektne temperature");
                min_temp.push_back(z);
            });
     }

    bool operator !() {
        bool x(false);
        if(max_temp.size()==0||min_temp.size()==0) x=true;
        return x;
    }
    
    int &operator ++(int &x) {
     if(x>max) throw std::logic_error("Ilegalna operacija");
        x++;
        return x;
    }
    int operator ++(int &x,int){
        if(x>max) throw std::logic_error("Ilegalna operacija");
        int temp(x); 
        x++;
        return pomocni;
    }
    void operator --(int &x){
        if(x<min) throw std::logic_error("Ilegalna operacija");
        int temp(x); 
        x--;
        return pomocni;
    }
     void &operator --(int &x,int){
         if(x<min) throw std::logic_error("Ilegalna operacija");
        x--;
        return x;
    }
    std::vector<int> &operator *(Temperature &T){
        auto it=T.min_temp.begin(); std::vector<int> v(T.max_temp.size());
        std::for_each(T.max_temp.begin(),T.max_temp.end(),[&it](int &p){
            v.push_back(p-(*it));
            it++;
        });
            return v;
    }
    std::vector<int> &operator +(Temperature &T){
        std::vector<int> v(T.max_temp.size());
        std::for_each(T.max_temp.begin(),T.max_temp.end(),[](int &p){
            v.push_back(max-p);
            it++;
        });
            return v;
    }
    std::vector<int> &operator -(Temperature &T){
     std::vector<int> v(T.max_temp.size());
        std::for_each(T.min_temp.begin(),T.min_temp.end(),[](int &p){
            v.push_back(p-min);
            it++;
        });
            return v;
    }
    std::pair<int,int> &operator [](int x){
        std::pair<int,int> temp;
         auto it=T.min_temp.begin(); 
         std::vector<int> v(T.max_temp.size());
        std::for_each(T.max_temp.begin(),T.max_temp.end(),[&it](int &p){
            if((t-T.min_temp.begin()==x){
             temp=std::make_pair(p,*it));   
            }
            it++;
        });
    }
   

   /* void BrisiSve() {

    }
    void BrisiNegativneBrojeve() {

    }
    */
    int DajBrojRegistriranihTemperatura() {
         int brojac(0);
     std::for_each(max_temp.begin(),max_temp.end(),[]() {
         brojac++;
            });
   return brojac;
    }

    int DajBrojTemperaturaVecihOd() {
    std::for_each(max_temp.begin(),max_temp.end(),[](const int &y) {
        
            });

    throw std::logic_error("Nema registriranih temperatura.")
    }
 
};

int main ()
{
    try{
        
        
    }
    catch(std::range_error &e){
    std::cout<<e.what();
    }
    catch(std::logic_error &e){
    std::cout<<e.what();    
    }
    
    return 0;
}