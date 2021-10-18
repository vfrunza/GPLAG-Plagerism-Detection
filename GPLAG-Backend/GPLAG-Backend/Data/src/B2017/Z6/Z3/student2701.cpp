/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
class PolimorfniSpremnik {
 shared_ptr<Spremnik> p_lik;
 void Test() const {
 if(!p_lik) throw std::logic_error("Nespecificiran spremnik");
 }
public:
     PolimorfniSpremnik() : p_lik(nullptr) {}
     ~PolimorfniSpremnik() { p_lik=nullptr; }
     PolimorfniSpremnik(const Spremnik &lik)  {
         p_lik=lik.DajKopiju();
     }
     PolimorfniSpremnik(PolimorfniSpremnik &lik) {
         if(!lik.p_lik) p_lik = nullptr;
         else p_lik = lik.p_lik->DajKopiju();
     }
     PolimorfniSpremnik(PolimorfniSpremnik &&lik) {
         p_lik = lik.p_lik; lik.p_lik = nullptr;
     }
     PolimorfniSpremnik &operator =(PolimorfniSpremnik &lik) {
         shared_ptr<Spremnik>p_novi(nullptr);
         if(lik.p_lik != nullptr) p_novi = lik.p_lik->DajKopiju();
         p_lik=nullptr;
         p_lik = p_novi;
         return *this;
         }
     PolimorfniSpremnik &operator =(PolimorfniSpremnik &&lik) {
         std::swap(p_lik, lik.p_lik);
         return *this;
     }
     double DajTezinu() const { Test(); return p_lik->DajTezinu();}
     string DajNaziv() const { Test(); return p_lik->DajNaziv();}
     double DajUkupnuTezinu() const { Test(); return p_lik->DajUkupnuTezinu();}
     void Ispisi() const { Test(); p_lik->Ispisi();}
};
int main ()
{
	return 0;
}
