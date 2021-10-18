class Liga {
	int broj_timova;
	const int max_br_timova;
	Tim **timovi;
	public:
	explicit Liga(int velicina_lige);
	explicit Liga(std::initializer_list<Tim> lista_timova);
	~Liga();
	Liga(const Liga &l);
	Liga(Liga &&l);
	Liga &operator = (const Liga &l);
	Liga &operator = (Liga &&l);
	void DodajNoviTim(const char ime_tima[]);
	void RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2);
	void IspisiTabelu();
};
void Liga::IspisiTabelu() {
	std::sort(timovi, timovi + broj_timova, [](const Tim *t1, const Tim *t2) {
		if (t1->DajBrojPoena() == t2->DajBrojPoena()) {
			if (t1->DajGolRazliku() == t2->DajGolRazliku()) return (strcmp(t1->DajImeTima(), t2->DajImeTima()) < 0); 
			return t1->DajGolRazliku() > t2->DajGolRazliku();
		}
		return t1->DajBrojPoena() > t2->DajBrojPoena();
	});
	for (int i = 0; i < broj_timova; i++) timovi[i]->IspisiPodatke();
}
void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2) {
	if (rezultat_1 < 0 || rezultat_2 < 0) throw std::range_error ("Neispravan broj golova");
	int index_prvog(-1), index_drugog(-1);
	for (int i = 0; i < broj_timova; i++) {
		if (index_prvog == -1 && std::strcmp(timovi[i]->DajImeTima(), tim1) == 0) index_prvog = i;
		if (index_drugog == -1 && std::strcmp(timovi[i]->DajImeTima(), tim2) == 0) index_drugog = i;
 	}
 	if (index_prvog < 0 || index_drugog < 0) throw std::logic_error ("Tim nije nadjen");
 	timovi[index_prvog]->ObradiUtakmicu(rezultat_1, rezultat_2);
 	timovi[index_drugog]->ObradiUtakmicu(rezultat_2, rezultat_1);
}
void Liga::DodajNoviTim(const char ime_tima[]) {
	if (std::strlen(ime_tima) > 19) throw std::range_error ("Predugacko ime tima");
	if (broj_timova == max_br_timova) throw std::range_error ("Liga popunjena");
	for (int i = 0; i < broj_timova; i++) 
		if (std::strcmp(timovi[i]->DajImeTima(), ime_tima) == 0) throw std::logic_error ("Tim vec postoji");
	timovi[broj_timova++] = new Tim(ime_tima);
}
Liga &Liga::operator =(Liga &&l) {
	if (max_br_timova != l.max_br_timova) throw std::logic_error ("Nesaglasni kapaciteti liga");
	if (&l != this) {
		for (int i = 0; i < broj_timova; i++) delete timovi[i];
		timovi = l.timovi;
		l.broj_timova = 0;
		l.timovi = nullptr;
	}
	return *this;
}
Liga::Liga(Liga &&l) : broj_timova(l.broj_timova), max_br_timova(l.max_br_timova) {
	timovi = l.timovi;
	l.broj_timova = 0;
	l.timovi = nullptr;
}
Liga::Liga(int velicina_lige) : broj_timova(0), max_br_timova(velicina_lige), timovi(new Tim*[velicina_lige] {}) {};
Liga::Liga(std::initializer_list<Tim> lista_timova) : broj_timova(lista_timova.size()), max_br_timova(lista_timova.size()), timovi(new Tim*[lista_timova.size()] {}) {
	int i(0);
	for (auto it(lista_timova.begin()); it != lista_timova.end(); it++) timovi[i++] = new Tim(*it);
};
Liga::~Liga() {
	for (int i = 0; i < broj_timova; i++) delete timovi[i];
	delete[] timovi;
}
Liga::Liga(const Liga &l) : broj_timova(l.broj_timova), max_br_timova(l.max_br_timova), timovi(new Tim*[l.max_br_timova]) {
	if (max_br_timova != l.max_br_timova) throw std::logic_error ("Nesaglasni kapaciteti liga");
	try {
		for (int i = 0; i < l.broj_timova; i++) timovi[i] = new Tim(*l.timovi[i]);
	}
	catch(...) {
		for (int i = 0; i < l.broj_timova; i++) delete timovi[i];
		delete[] timovi; throw;
	}
}
Liga &Liga::operator = (const Liga &l) {
	if (max_br_timova != l.max_br_timova) throw std::logic_error ("Nesaglasni kapaciteti liga");
	if (&l != this) {
		for (int i = 0; i < broj_timova; i++) 
			delete timovi[i]; 
		for (int i = 0; i < l.broj_timova; i++) 
			timovi[i] = new Tim(*l.timovi[i]);
		broj_timova = l.broj_timova;
	}
	return *this;
}