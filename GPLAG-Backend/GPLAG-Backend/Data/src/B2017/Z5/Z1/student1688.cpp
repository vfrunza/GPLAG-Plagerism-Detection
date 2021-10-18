class Kontejner {
 Ugao **uglovi;
 int br;
 const int Kapacitet;
public:
 explicit Kontejner(int n) : Kapacitet(n), br(0), uglovi(new Ugao*[n]) {}
 ~Kontejner() { Brisi(); delete[] uglovi; }
 Kontejner(const Kontejner &k);
 Kontejner &operator =(const Kontejner &k);
 void Upisi(int d, int m, int s);
 void Brisi();
 void Ispisi() const;
 void IspisiUDatoteku(const char ime[]) const;
 void Citaj(const char ime[]);
 Ugao Najveci() const;
 Ugao Najmanji() const;
 int BrojUglova() const { return br; }
 int BrojOstrih() const;
 Ugao &operator [](int i);
 Ugao operator[](int i) const;
 void Sacuvaj(const char ime[]) const;
 void Obnovi(const char ime[]);
};
Kontejner::Kontejner(const Kontejner &k) : Kapacitet(k.Kapacitet),
 br(k.br), uglovi(new Ugao*[k.Kapacitet]) {
 for(int i = 0; i < br; i++) uglovi[i] = new Ugao(*k.uglovi[i]);
}
Kontejner &Kontejner::operator =(const Kontejner &k) {
 if(&k == this) return *this;
 if(Kapacitet != k.Kapacitet) throw "Razliciti kapaciteti!\n";
 Brisi(); br = k.br;
 for(int i = 0; i < br; i++) uglovi[i] = new Ugao(*k.uglovi[i]);
 return *this;
}
void Kontejner::Upisi(int d, int m, int s) {
 if(br == Kapacitet) throw "Kontejner popunjen!";
 uglovi[br++] = new Ugao(d, m, s);
}
void Kontejner::Brisi() {
 for(int i = 0; i < br; i++) delete uglovi[i];
 br = 0;
}
void Kontejner::Ispisi() const {
 for(int i = 0; i < br; i++) cout << *uglovi[i] << endl;
}
void Kontejner::IspisiUDatoteku(const char ime[]) const {
 ofstream izlaz(ime);
 for(int i = 0; i < br; i++) izlaz << *uglovi[i] << endl;
}

void Kontejner::Citaj(const char ime[]) {
 ifstream ulaz(ime);
 Brisi();
 Ugao u(0, 0, 0);
 while(ulaz >> u) uglovi[br++] = new Ugao(u); 
 Ugao Kontejner::Najveci() const {
 if(br == 0) throw "Nema upisanih uglova!\n"; // S obzirom da niz "uglovi"
 Ugao *pmax(uglovi[0]); // sadrži pokazivače, ove
 for(int i = 1; i < br; i++) // metode je prilično teško
 if(*uglovi[i] > pmax) pmax = uglovi[i]; // izvesti preko funkcija iz
 return *pmax; // biblioteke "algorithm"...
}
Ugao Kontejner::Najmanji() const {
 if(br == 0) throw "Nema upisanih uglova!\n";
 Ugao *pmin(uglovi[0]);
 for(int i = 1; i < br; i++)
 if(*uglovi[i] < pmin) pmin = uglovi[i];
 return *pmin;
}
int Kontejner::BrojOstrih() const {
 int brojac(0);
 for(int i = 0; i < br; i++)
 if(uglovi[i]-> Stepeni() < 90) brojac++;
 return brojac;
}
Ugao &Kontejner::operator [](int i) {
 if(i < 0 || i >= br) throw "Pogrešan indeks!\n";
 return *uglovi[i];
}
Ugao Kontejner::operator[](int i) const {
 if(i < 0 || i >= br) throw "Pogrešan indeks!\n";
 return *uglovi[i];
}

void Kontejner::Sacuvaj(const char ime[]) const {
 ofstream izlaz(ime, ios::out | ios::binary);
 izlaz.write((char*)this, sizeof *this);
 for(int i = 0; i < broj studenata; i++)
 izlaz.write((char*)uglovi[i], sizeof(Ugao));
}
void Kontejner::Obnovi(const char ime[]) {
 ifstream ulaz(ime, ios::in | ios::binary);
 if(!ulaz) throw "Datoteka ne postoji!\n";
 Brisi(); delete[] uglovi;
 ulaz.read((char*)this, sizeof *this);
 uglovi = new Ugao*[Kapacitet];
 for(int i = 0; i < br; i++) {
 uglovi[i] = new Ugao(0, 0, 0);
 ulaz.read((char*)studenti[i], sizeof(Ugao)); 