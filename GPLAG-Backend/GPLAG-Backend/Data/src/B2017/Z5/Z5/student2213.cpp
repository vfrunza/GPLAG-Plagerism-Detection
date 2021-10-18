/B2017/2018: Zadaća 5, Zadatak 5
#include <iostream>
class PolimorfniLik {
 ApstraktniLik *p_lik;
 void Test() const {
 if(!p_lik) throw std::logic_error("Nespecificiran lik!");
 }
public:
 PolimorfniLik() : p_lik(nullptr) {}
 ~PolimorfniLik() { delete p_lik; }
 PolimorfniLik(const ApstraktniLik &lik) : p_lik(lik.DajKopiju()) {}
 PolimorfniLik(const PolimorfniLik &lik) {
 if(!lik.p_lik) p_lik = nullptr;
 else p_lik = lik.p_lik->DajKopiju();
 }
 PolimorfniLik(PolimorfniLik &&lik) {
 p_lik = lik.p_lik; lik.p_lik = nullptr;
 }
 PolimorfniLik &operator =(const PolimorfniLik &lik) {
 ApstraktniLik *p_novi(nullptr);
 if(lik.p_lik != nullptr) p_novi = lik.p_lik->DajKopiju();
 delete p_lik;
 p_lik = p_novi;
 return *this;
 }
 PolimorfniLik &operator =(PolimorfniLik &&lik) {
 std::swap(p_lik, lik.p_lik);
 return *this;
 }
 double DajObim() const { Test(); return p_lik->DajObim(); }
 double DajPovrsinu() const { Test(); return p_lik->DajPovrsinu(); }
 void Ispisi() const { Test(); p_lik->Ispisi(); }
};

int main ()
{
	return 0;
}
