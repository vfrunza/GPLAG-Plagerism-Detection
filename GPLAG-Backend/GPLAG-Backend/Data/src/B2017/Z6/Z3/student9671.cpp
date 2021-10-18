/B2017/2018: Zadaća 6, Zadatak 3

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <sstream>
#include <fstream>
//#include <istream>
//#include <sstream>
#include <vector>

template <typename T> std::string PretvoriUString(T x) {
    std::ostringstream s; s << x; return s.str();
}

template <typename TipEl>
 class Matrica {
 	int br_redova, br_kolona;
 	TipEl **elementi;
 	char ime_matrice;
 	static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
 	static void DealocirajMemoriju(TipEl **elementi, int br_redova);
 	void KopirajElemente(TipEl **elementi);
  public:
 	Matrica(int br_redova, int br_kolona, char ime = 0);
 	Matrica(const Matrica &m);
 	Matrica(Matrica &&m);
 	~Matrica() { DealocirajMemoriju(elementi, br_redova); }
 	Matrica &operator =(const Matrica &m);
 	Matrica &operator =(Matrica &&m);
 	Matrica (std::string ime, bool unos){
 	    if(unos)//binarna
 	    {
 	        std::vector<std::vector<TipEl>> binarni;
    std::ifstream ulazni_tok(ime, std::ios::in | std::ios::binary);
    if(!ulazni_tok.is_open()) throw std::logic_error("Trazena datoteka ne postoji");
    ulazni_tok.seekg(0, std::ios_base::end);
    long int duzinaDat(ulazni_tok.tellg());
    ulazni_tok.seekg(0, std::ios_base::beg);
    long pozicija(ulazni_tok.tellg());
    TipEl broj1;
    int i(0);
    char znak;
    binarni.resize(1);
    while(1)
    {
        ulazni_tok.read(reinterpret_cast <char*>(&broj1), sizeof(broj1));
        if(ulazni_tok.bad()) throw std::logic_error("Problemi sa citanjem iz datoteke");
        if(ulazni_tok.fail()) throw std::logic_error("Problemi pri citanju datoteke");
        pozicija = pozicija + sizeof(broj1);
        ulazni_tok.seekg(pozicija);
        if(pozicija < duzinaDat) ulazni_tok.read(reinterpret_cast<char*>(&znak), sizeof(znak));
        if(ulazni_tok.bad()) throw std::logic_error("Problemi sa citanjem iz datoteke");
        if(ulazni_tok.fail()) throw std::logic_error("Problemi pri citanju datoteke");
        if(znak == ',')
        {
            binarni[i].push_back(broj1);
            pozicija = pozicija + sizeof(char);
            ulazni_tok.seekg(pozicija);
        }
        if(znak == '\r')
        {
            binarni[i++].push_back(broj1);
            binarni.resize(binarni.size() + 1);
            pozicija = pozicija + 2*sizeof(char);
            ulazni_tok.seekg(pozicija);
        }
    }
    ulazni_tok.close();
    for(int i(0); i < binarni.size(); i++) if(binarni[0].size() != binarni [i].size()) throw std::logic_error("Problemi pri citanju datoteke");
    br_redova = binarni.size();
    br_kolona = binarni[0].size();
    AlocirajMemoriju(br_redova, br_kolona);
    for(int i(0); i < br_redova; i++)
    {
        for(int j(0); j < br_kolona; j++)
        {
            elementi[i][j] = binarni[i][j];
        }
    }
 	    }
 	    else//tekstualna
 	    {
 	        std::ifstream ulazni_tok(ime, std::ios::in);
 	    if(!ulazni_tok.is_open()) throw std::logic_error("Trazena datoteka ne postoji");
 	    std::vector<int> velicine;
 	    std::string linija;
 	    while(1){
 	        getline(ulazni_tok, linija);
 	        if(ulazni_tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");
 	            int broj_kolona(0);
 	            for(auto it(linija.begin()); *it!= 0; it++)
 	            {
 	                while((*it >= '0' && *it <= '9') || *it == '.') if(it != linija.end()) it++;
 	                if (it != linija.end() && *it != ',' && *it != 0) throw std::logic_error("Datoteka sadrzi besmislene podatke");
 	                broj_kolona++;
 	            }
 	        velicine.push_back(broj_kolona);
 	        
 	        if(ulazni_tok.eof()) break;
 	    }
 	    for(int i(0); i < velicine.size(); i++) if(velicine[0] != velicine[i]) throw std::logic_error("Datoteka sadrzi besmislene podatke");
 	    br_redova = velicine.size();
 	    br_kolona = velicine[0];
 	    AlocirajMemoriju(br_redova, br_kolona);
        ulazni_tok.seekg(0, std::ios_base::beg);
        int i(0);
        while(1)
    {
    std::string linija1;
    int j(0);
    getline(ulazni_tok, linija1);
    if(ulazni_tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");
    for(auto it(linija1.begin()); it != linija1.end(); it++)
    {
        TipEl broj(0);
        std::string strbroj;
        while((*it != 0 && *it >= '0' && *it <= '9') || *it =='.') strbroj += *it++;
        //std::istringstream s(strbroj);
        auto iter(strbroj.end());
        TipEl proizvod(1);
        iter--;
        for(; iter != strbroj.begin(); iter--)
        {
            broj += (*iter - 48) * proizvod;
            proizvod *= 10;
        }
        broj += (*iter - 48) * proizvod;
        //std::stringstream(strbroj)<<broj;
        //if(s.bad()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
        elementi[i][j++] = broj;
    }
    i++;
    if(ulazni_tok.eof()) break;
    }
    ulazni_tok.close();
 	    }
 	};
 
 	void SacuvajUTekstualnuDatoteku(std::string ime){
 	    std::ofstream tok_izlazni(ime, std::ios::out);
 	    for(int i(0); i < br_redova; i++)
 	    {
 	        for(int j(0); j < br_kolona; j++)
 	        {
 	            if(j < br_kolona - 1) tok_izlazni<<elementi[i][j]<<",";
 	            if(j == br_kolona - 1) tok_izlazni<<elementi[i][j];
 	            if(tok_izlazni.bad()) throw std::logic_error("Problemi sa upisom u datoteku");
 	        }
 	        tok_izlazni<<"\n";
 	        if(tok_izlazni.bad()) throw std::logic_error("Problemi sa upisom u datoteku");
 	    }
 	    tok_izlazni.close();
 	};
 	
 	void SacuvajUBinarnuDatoteku(std::string ime){
 	    std::ofstream izlazni_tok(ime, std::ios::binary | std::ios::out);
 	     for(int i(0); i < br_redova; i++)
    {
        char *enter = new char('\n');
        char *znak0 = new char('\r');
        for(int j(0); j < br_kolona; j++)
        {
            auto broj(elementi[i][j]);
            char *znak = new char(',');
            if(j < br_kolona - 1) {
                    izlazni_tok.write(reinterpret_cast <char*>(&broj), sizeof(broj));
                    izlazni_tok.write(znak, sizeof(char));
            if(izlazni_tok.bad()) throw std::logic_error("Problemi sa upisom u datoteku");
            }
            if(j == br_kolona - 1)  izlazni_tok.write(reinterpret_cast <char*>(&broj), sizeof(broj));
            delete znak;
        }
         izlazni_tok.write(znak0, sizeof(char));
         if(izlazni_tok.bad()) throw std::logic_error("Problemi sa upisom u datoteku");
         
         izlazni_tok.write(enter, sizeof(char));
         if(izlazni_tok.bad()) throw std::logic_error("Problemi sa upisom u datoteku");
         
         delete enter;
         delete znak0;
    }
    izlazni_tok.close();
 	};
 	
 	void ObnoviIzTekstualneDatoteke(std::string ime){
 	    
 	   
 	
 	    std::ifstream ulazni_tok(ime, std::ios::in);
 	    if(!ulazni_tok.is_open()) throw std::logic_error("Trazena datoteka ne postoji");
 	    DealocirajMemoriju(elementi, br_redova);
 	    std::vector<int> velicine;
 	    int brojac(0);
 	    std::string linija1;
 	    TipEl broj;
 	    while(1){
 	        
 	        getline(ulazni_tok, linija1);
 	        if(ulazni_tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");
 	            int broj_kolona(0);
 	            for(auto it(linija1.begin()); *it!= 0; it++)
 	            {
 	                while((*it != 0 && *it >= '0' && *it <= '9') || *it == '.') it++;
 	                if (*it != 0 && *it != ',') throw std::logic_error("Datoteka sadrzi besmislene podatke");
 	                broj_kolona++;
 	            }
 	        velicine.push_back(broj_kolona);
 	        
 	        if(ulazni_tok.eof()) break;
 	    }
 	    for(int i(0); i < velicine.size(); i++) if(velicine[0] != velicine[i]) throw std::logic_error("Datoteka sadrzi besmislene podatke");
 	    br_redova = velicine.size();
 	    br_kolona = velicine[0];
 	    AlocirajMemoriju(br_redova, br_kolona);
        ulazni_tok.seekg(0, std::ios_base::beg);
        int i(0);
        while(1)
    {
    std::string linija;
    int j(0);
    getline(ulazni_tok, linija);
    for(auto it(linija.begin()); it != linija.end(); it++)
    {
        TipEl broj(0);
        std::string strbroj;
        //std::istringstream s(strbroj);
        while((it != linija.end() && *it >= '0' && *it <= '9') || *it =='.') strbroj += *it++;
        //s>>broj;
        auto iter(strbroj.end());
        TipEl proizvod(1);
        iter--;
        for(; iter != strbroj.begin(); iter--)
        {
            broj += (*iter - 48) * proizvod;
            proizvod *= 10;
        }
        broj += (*iter - 48) * proizvod;
        //if(s.bad()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
        elementi[i][j++] = broj;
    }
    i++;
    if(ulazni_tok.eof()) break;
    }
    ulazni_tok.close();
 	};
 	
 	void ObnoviIzBinarneDatoteke(std::string ime){
 	   
    std::vector<std::vector<TipEl>> binarni;
    std::ifstream ulazni_tok(ime, std::ios::in | std::ios::binary);
    if(!ulazni_tok.is_open()) throw std::logic_error("Trazena datoteka ne postoji");
    DealocirajMemoriju(elementi, br_redova);
    ulazni_tok.seekg(0, std::ios_base::end);
    long int duzinaDat(ulazni_tok.tellg());
    ulazni_tok.seekg(0, std::ios_base::beg);
    long pozicija(ulazni_tok.tellg());
    TipEl broj1;
    int i(0);
    char znak;
    binarni.resize(1);
    while(1)
    {
        ulazni_tok.read(reinterpret_cast <char*>(&broj1), sizeof(broj1));
        if(ulazni_tok.bad()) throw std::logic_error("Problemi sa citanjem iz datoteke");
        if(ulazni_tok.fail()) throw std::logic_error("Problemi pri citanju datoteke");
        pozicija = pozicija + sizeof(broj1);
        ulazni_tok.seekg(pozicija);
        if(pozicija < duzinaDat) ulazni_tok.read(reinterpret_cast<char*>(&znak), sizeof(znak));
        if(ulazni_tok.bad()) throw std::logic_error("Problemi sa citanjem iz datoteke");
        if(ulazni_tok.fail()) throw std::logic_error("Problemi pri citanju datoteke");
        if(znak == ',')
        {
            binarni[i].push_back(broj1);
            pozicija = pozicija + sizeof(char);
            ulazni_tok.seekg(pozicija);
        }
        if(znak == '\r')
        {
            binarni[i++].push_back(broj1);
            binarni.resize(binarni.size() + 1);
            pozicija = pozicija + 2*sizeof(char);
            ulazni_tok.seekg(pozicija);
        }
    }
    ulazni_tok.close();
    for(int i(0); i < binarni.size(); i++) if(binarni[0].size() != binarni [i].size()) throw std::logic_error("Problemi pri citanju datoteke");
    br_redova = binarni.size();
    br_kolona = binarni[0].size();
    AlocirajMemoriju(br_redova, br_kolona);
    for(int i(0); i < br_redova; i++)
    {
        for(int j(0); j < br_kolona; j++)
        {
            elementi[i][j] = binarni[i][j];
        }
    }
 	};
 	
 	template <typename Tip2>
 	friend std::istream &operator >> (std::istream &tok, Matrica<Tip2> &mat);
 	template <typename Tip2>
    friend std::ostream &operator <<(std::ostream &tok, const Matrica<Tip2> &mat);
 	template <typename Tip2>
 	friend Matrica<Tip2> operator +(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
 	template <typename Tip2>
    friend Matrica<Tip2> operator -(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
 	template <typename TipElemenata>
    friend Matrica<TipElemenata> operator *(double n, Matrica<TipElemenata> mat);
    template <typename TipElemenata>
    friend Matrica<TipElemenata> operator *(Matrica<TipElemenata> mat, double n);
    template <typename TipElemenata>
    friend Matrica<TipElemenata> operator * (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) ;
    
    template <typename TipElemenata>
    friend Matrica<TipElemenata> operator += (Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2);
    template <typename TipElemenata>
    friend Matrica<TipElemenata> operator *= (Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2);
    template <typename TipElemenata>
    friend Matrica<TipElemenata> operator -= (Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2);
    template <typename TipElemenata>
    friend Matrica<TipElemenata> &operator *= (Matrica<TipElemenata> &m1, double n);
    
    TipEl* operator [](int indeks) const {
        return elementi[indeks];
    }
    
    TipEl* &operator [](int indeks) {
        return elementi[indeks];
    }

    TipEl operator ()(int i, int j) const {
        if (i<1 || i>br_redova) throw std::range_error("Neispravan indeks");
        if (j<1 || j>br_kolona) throw std::range_error("Neispravan indeks");
        return elementi[i-1][j-1];
    }
    
    TipEl &operator ()(int i, int j) {
        if (i<1 || i>br_redova) throw std::range_error("Neispravan indeks");
        if (j<1 || j>br_kolona) throw std::range_error("Neispravan indeks");
        return elementi[i-1][j-1];
    }
    
    operator std::string() const {
        std::string s("{");
        for(int i = 0; i < br_redova; i++) {
            s=s+"{";
 		    for(int j = 0; j < br_kolona; j++) {
 		        s=s+PretvoriUString(elementi[i][j]);
 		        if (j!=br_kolona-1) s=s+",";
 		    }
 		    s=s+"}";
 		    if (i!=br_redova-1) s=s+",";
        }
        s=s+"}";
        return s;
    }

};

template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona) {
 	TipEl **elementi(new TipEl*[br_redova]{});
 	try {
 		for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
 	}
 	catch(...) {
 		DealocirajMemoriju(elementi, br_redova); throw;
 	}
 	return elementi;
}

template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova) {
 	for(int i = 0; i < br_redova; i++) delete[] elementi[i];
 	delete[] elementi;
 	elementi = nullptr; br_redova = 0;
}

template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) : br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime), elementi(AlocirajMemoriju(br_redova, br_kolona)) {}

template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi) {
 	for(int i = 0; i < br_redova; i++)
 		for(int j = 0; j < br_kolona; j++)
 			Matrica::elementi[i][j] = elementi[i][j];
}

template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova), br_kolona(m.br_kolona), ime_matrice(m.ime_matrice), elementi(AlocirajMemoriju(m.br_redova, m.br_kolona)) {
 	KopirajElemente(m.elementi);
}

template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova), br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice) {
	m.br_redova = 0; m.elementi = nullptr;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m) {
 	if(br_redova < m.br_redova || br_kolona < m.br_kolona) {
 		TipEl **novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
 		DealocirajMemoriju(elementi, br_redova);
 		elementi = novi_prostor;
 	}
 	else if(br_redova > m.br_redova) for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
 	
 	br_redova = m.br_redova; br_kolona = m.br_kolona;
 	ime_matrice = m.ime_matrice; KopirajElemente(m.elementi);
 	return *this;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m) {
 	std::swap(br_redova, m.br_redova); std::swap(br_kolona, m.br_kolona);
 	std::swap(ime_matrice, m.ime_matrice); std::swap(elementi, m.elementi);
 	return *this;
}

template <typename TipEl>
std::ostream &operator <<(std::ostream &tok, const Matrica<TipEl> &mat) {
    
    int sirina(tok.width());
    
 	for(int i = 0; i < mat.br_redova; i++) {
 		for(int j = 0; j < mat.br_kolona; j++) {
 			tok << std::setw(sirina) << mat.elementi[i][j];
 		}
 		tok << std::endl;
 	}
 	
 	return tok;
 }

template <typename TipEl>
Matrica<TipEl> operator +(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
 	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
 	Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
 	for(int i = 0; i < m1.br_redova; i++)
 		for(int j = 0; j < m1.br_kolona; j++)
 			m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 	return m3;
}

template <typename TipEl>
Matrica<TipEl> operator -(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
 	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
 	Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
 	for(int i = 0; i < m1.br_redova; i++)
 		for(int j = 0; j < m1.br_kolona; j++)
 			m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
 	return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> operator * (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if (m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    
    Matrica<TipElemenata> m3(m1.br_redova, m2.br_kolona);
    for (int i=0; i<m1.br_redova; i++) {
        for (int j=0; j<m2.br_kolona; j++) {
            m3.elementi[i][j]=0;
            for (int k=0; k<m1.br_kolona; k++) m3.elementi[i][j]+=(m1.elementi[i][k]*m2.elementi[k][j]);
        }
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> &operator *= (Matrica<TipElemenata> &m1, double n) {
    m1=m1*n;
    return m1;
}

template <typename TipElemenata>
Matrica<TipElemenata> operator *(double n, Matrica<TipElemenata> mat) {
    Matrica<TipElemenata> nova(mat.br_redova, mat.br_kolona);
    nova=mat*n;
    return nova;
}

template <typename TipElemenata>
Matrica<TipElemenata> operator += (Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    m1=m1+m2;
    return m1;
}

template <typename TipElemenata>
Matrica<TipElemenata> operator -= (Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    m1=m1-m2;
    return m1;
}

template <typename TipElemenata>
Matrica<TipElemenata> operator *= (Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    m1=m1*m2;
    return m1;
}

 
int main() {
 	
 	/*Matrica<int> m(3,3);
   try{	
 	m.ObnoviIzTekstualneDatoteke("Niovonijedatoteka");
   }
   catch(std::logic_error l)
   {
       std::cout<<l.what()<<std::endl;
   }
   try{	m.ObnoviIzBinarneDatoteke("Nijedatoteka");
 	
   }
   catch(std::logic_error l)
   {
       std::cout<<l.what()<<std::endl;
   }*/
    std::string ime = "matrica1.txt";
    std::ofstream dat(ime);
    dat << "1,2\n3,4";
    dat.close();
    Matrica<int> m1("matrica1.txt", false);
    std::cout << std::setw(6) << m1;
 	return 0;
}





