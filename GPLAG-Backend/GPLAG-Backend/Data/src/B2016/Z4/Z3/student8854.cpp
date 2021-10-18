/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>


class Datum{
	int dan,mjesec,godina;
	public:
	Datum(int dan, int mjesec, int godina){
		int niz[12]{31,28,31,30,31,30,31,31,30,31,30,31};
		if(godina<0 || mjesec<0 || mjesec>=12 || dan<0 || (dan>niz[mjesec-1] && mjesec!=2))
		throw std::domain_error("Neispravan datum");
		if(mjesec==2 && (godina%400==0 ||(godina%4==0 && godina%100!=0)))
		Datum::dan=dan;Datum::mjesec=mjesec;Datum::godina=godina;
		
		
	}
void Postavi(int dan, int mjesec, int godina){
	int niz[12]{31,28,31,30,31,30,31,31,30,31,30,31};
		if(godina<0 || mjesec<0 || mjesec>=12 || dan<0 || (dan>niz[mjesec-1] && mjesec!=2))
		throw std::domain_error("Neispravan datum");
		if(mjesec==2 && (godina%400==0 ||(godina%4==0 && godina%100!=0)))
		Datum::dan=dan;Datum::mjesec=mjesec;Datum::godina=godina;
		
}
int DajDan() const{return dan;}
int DajMjesec() const {return mjesec;}
int DajGodinu() const{return godina;}
void Ispisi() const{std::cout<<dan<<"/"<<mjesec<<"/"<<godina;}
};

class Kupac{
	std::string ime_i_prezime;
	Datum datum_rodjenja{0,0,0};
	public:


Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
{
	for(int i=0;i<ime_i_prezime.size();i++)
	{
		if(!( (ime_i_prezime[i]<='z' && ime_i_prezime[i]>='a') || (ime_i_prezime[i]<='Z' && ime_i_prezime[i]>='A') || ime_i_prezime[i]=='\'' ||  ime_i_prezime[i]==' ' || ime_i_prezime[i]=='-' ))
	    throw std::domain_error("Neispravno ime i prezime");
		
	}
	Kupac::datum_rodjenja.Postavi(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu());
	
	
}
void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
{
	for(int i=0;i<ime_i_prezime.size();i++)
	{
		if(!( (ime_i_prezime[i]<='z' && ime_i_prezime[i]>='a') || (ime_i_prezime[i]<='Z' && ime_i_prezime[i]>='A') || ime_i_prezime[i]=='\'' ||  ime_i_prezime[i]==' ' || ime_i_prezime[i]=='-' ))
	    throw std::domain_error("Neispravno ime i prezime");
		
	}
	Kupac::datum_rodjenja=datum_rodjenja;
}
std::string DajImePrezime() const{return ime_i_prezime;}
Datum DajDatumRodjenja() const{return datum_rodjenja;}
void Ispisi() const{std::cout<<ime_i_prezime<<"(";datum_rodjenja.Ispisi();std::cout<<")";}


};

class Stan{
std::string adresa;
int sprat;
int broj_soba;
bool namjesten;
double kvadratura;
	public:
	
	Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,
double kvadratura){
	if(sprat<0 || broj_soba<0 || kvadratura<0)
	throw std::domain_error("Neispravan unos podataka");
	Stan::adresa=adresa;Stan::sprat=sprat;Stan::broj_soba=broj_soba;Stan::namjesten=namjesten;Stan::kvadratura=kvadratura;
}
void Postavi(const std::string &adresa, int sprat, int broj_soba,
bool namjesten, double kvadratura){
	if(sprat<0 || broj_soba<0 || kvadratura<0)
	throw std::domain_error("Neispravan unos podataka");
	Stan::adresa=adresa;Stan::sprat=sprat;Stan::broj_soba=broj_soba;Stan::namjesten=namjesten;Stan::kvadratura=kvadratura;
}
std::string DajAdresu() const{return adresa;}
int DajSprat() const{return sprat;}
int DajBrojSoba() const{return broj_soba;}
bool DajNamjesten() const{return namjesten;}
double DajKvadraturu() const{return kvadratura;}
void Ispisi() const{std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba<<" soba. Kvadratura stane je "<<kvadratura<<" (m^2) i stan ";
if(namjesten) 
std::cout<<"je";
else
std::cout<<"nije";
std::cout<<" namjesten.";
}

};

class Prodaja{
	std::string ime_agenta_prodaje1;
	double cijena_stana1;
	Datum datum_prodaje1;
	Kupac kupac_stana1;
	Stan kupljeni_stan1;
	public:
	Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan){
	ime_agenta_prodaje1=ime_agenta_prodaje;cijena_stana1=cijena_stana;
    datum_prodaje1.Postavi(datum_prodaje.DajDan(),datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu());
	kupac_stana1.Postavi(kupac_stana.DajImePrezime(),kupac_stana.DajDatumRodjenja());
	kupljeni_stan1.Postavi(kupljeni_stan.DajAdresu(),kupljeni_stan.DajSprat(),kupljeni_stan.DajBrojSoba(),kupljeni_stan.DajNamjesten(),kupljeni_stan.DajKvadraturu());
	
	
}
Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
const std::string &adresa_stana, int sprat_stana, int broj_soba,
bool namjesten_stan, double broj_kvadrata);
	
	
	

void PromijeniKupca(const Kupac &novi_kupac);

void PromijeniStan(const Stan &novi_stan);
void PromijeniDatumKupovine(const Datum &novi_datum);
void PromijeniCijenuProdaje(const double &nova_cijena);
void PomjeriDanUnaprijed();
void PomjeriDanUnazad();
std::string DajImeAgenta() const;
std::string DajImeKupca() const;
Datum DajDatumProdaje() const;
double DajCijenuStana() const;
friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
void Ispisi() const;
};




int main ()
{
	std::cout<<"Ekstrica";
	return 0;
}