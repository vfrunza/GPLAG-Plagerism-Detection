class TabFun {
 struct Par {double x, y; };
 Par *parovi;
 int broj_parova, alocirano;
public:
 explicit TabFun(int kapacitet = 30) : broj_parova(0),
 alocirano(kapacitet), parovi(new Par[kapacitet]) {}
 ~TabFun() { delete[] parovi; }
 TabFun(const TabFun &tf);
 TabFun &operator =(const TabFun &tf);
 void DodajPar(double x, double y);
 void BrisiSve() { broj_parova = 0; }
 void Brisi(double x);
 void Tabeliraj(double f(double), double xmin, double xmax, double dx);
 double operator()(double x) const;
 void Sacuvaj(const char ime[]) const;
 TabFun(const char ime[]);
}; 
TabFun::TabFun(const TabFun &tf) : broj_parova(tf.broj_parova),
 alocirano(tf.broj_parova), parovi(new Par[tf.alocirano]) {
 copy(tf.parovi, tf.parovi + broj_parova, parovi);
}
TabFun &TabFun::operator =(const TabFun &tf) {
 if(alocirano < tf.broj_parova) {
 delete[] parovi; parovi = new Par[tf.broj_parova];
 }
 alocirano = broj_parova = tf.broj_parova;
 copy(tf.parovi, tf.parovi + broj_parova, parovi);
 return *this;
} 
void TabFun::DodajPar(double x, double y) {
 for(int i = 0; i < broj_parova; i++)
 if(parovi[i].x == x) throw "Vec postoji par sa zadanom vrijednoscu x!";
 if(broj_parova >= alocirano) {
 Par *novi_prostor(new Par[alocirano + 20]);
 copy(parovi, parovi + broj_parova, novi_prostor);
 delete[] parovi;
 parovi = novi_prostor; alocirano += 20;
 }
 Par p = {x, y};
 parovi[broj_parova++] = p;
} 
void TabFun::Brisi(double x) {
 for(int i = 0; i < broj_parova; i++)
 if(parovi[i].x == x) {
 parovi[i] = parovi[--broj_parova];
 return;
 }
 throw "Ne postoji zadana vrijednost x!";
}
void TabFun::Tabeliraj(double f(double), double xmin, double xmax,
 double dx) {
 for(double x = xmin; x <= xmax; x += dx) DodajPar(x, f(x));
}
double TabFun::operator()(double x) const {
 const double OGROMAN(1e100);
 double x1(-OGROMAN), x2(OGROMAN), y1, y2;
 for(int i = 0; i < broj_parova; i++) {
 if(parovi[i].x <= x && parovi[i].x >= x1) {
 x1 = parovi[i].x; y1 = parovi[i].y;
 }
 if(parovi[i].x > x && parovi[i].x <= x2) {
 x2 = parovi[i].x; y2 = parovi[i].y;
 }
 }
 if(x1 == -OGROMAN || x2 == OGROMAN) throw "Interpolacija nije moguca!";
 return y1 + (y2 - y1) * (x - x1) / (x2 - x1);
} 
void TabFun::Sacuvaj(const char ime[]) const {
 ofstream izlaz(ime, ios::out | ios::binary);
 if(!izlaz) throw "Problem pri kreiranju datoteke!";
 izlaz.write((char*)this, sizeof(TabFun));
 izlaz.write((char*)parovi, broj_parova * sizeof(Par));
 if(!izlaz) throw "Problem pri upisu u datoteku!";
}
TabFun::TabFun(const char ime[]) {
 ifstream ulaz(ime, ios::in | ios::binary);
 if(!ulaz) throw "Problem pri kreiranju datoteke!";
 ulaz.read((char*)this, sizeof(TabFun));
 parovi = new Par[alocirano];
 ulaz.read((char*)parovi, broj_parova * sizeof(Par));
 if(!ulaz) {
 delete[] parovi;
 throw "Problem pri citanju iz datoteke!";
 }
}