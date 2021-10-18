/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>

class KolekcijaLikova {
 int broj_likova, kapacitet;
 ApstraktniLik **likovi;
public:
explicit KolekcijaLikova(int kapacitet): broj_likova(0),
 kapacitet(kapacitet), likovi(new ApstraktniLik*[kapacitet]{}) {}
 ~KolekcijaLikova() {
for(int i= 0; i < broj_likova; i++) delete likovi[i];
 delete[] likovi;
}

KolekcijaLikova(const KolekcijaLikova &k):
 likovi(new ApstraktniLik*[k.kapacitet]{}), kapacitet(k.kapacitet),
 broj likova(k.broj likova) {
 try {
for(int i= 0; i < broj likova; i++)
likovi[i]= k.likovi[i]->DajKopiju();
 }
 catch(...) {
for(int i= 0; i < broj likova; i++) delete likovi[i];
 delete[] likovi; throw;
 }

 KolekcijaLikova(KolekcijaLikova &&k);
KolekcijaLikova &operator=(const KolekcijaLikova &k);
KolekcijaLikova &operator=(KolekcijaLikova &&k);
 void DodajLik(ApstraktniLik *lik) {
if(broj_likova >= kapacitet) {
delete lik; throw std::range_error("Kolekcija popunjena!");
 }
likovi[broj_likova++]= lik;
}

void DodajKrug(std::string boja, double r) { DodajLik(new Krug(boja, r)); }
void DodajPravougaonik(std::string boja, double a, double b) {
 DodajLik(new Pravougaonik(boja, a, b));
 }
void DodajTrougao(std::string boja, double a, double b, double c) {
 DodajLik(new Trougao(boja, a, b, c));
 }
 void IspisiKolekciju() constt {
for(int i= 0; i < broj_likova; i++) likovi[i]->Ispisi();
};


class krug
ApstraktniLik *DajKopiju() const override { return new Krug(*this); };
};
int main ()
{
	return 0;
}
