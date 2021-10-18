#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
 
using namespace std;
 
class SkladisniPredmet
{
    
protected:
    string naziv;
    double tezina_skl_pr;
public:
   
    SkladisniPredmet(string naziv, double tezina_skl_pr) : naziv(naziv),
        tezina_skl_pr(tezina_skl_pr) {}
    
    virtual void Ispisi() const = 0; 
    virtual double DajUkupnuTezinu() const = 0 ;
    string DajNaziv() const
    {
        return this->naziv;
    }
    double DajTezinuSKLPR() const
    {
        return this->tezina_skl_pr;
    }
};
int main(){
     
     return 0;
}