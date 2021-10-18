#include <iostream>
#include<stdexcept>
#include <tuple>
#include<string>
#include<iomanip>
#include<initializer_list>
#include<new>
#include<algorithm>

 bool b;

class Datum {
	int dan,mjesec,godina;
	public:
	
	Datum(int dan,int mjesec,int godina){
		if(dan<0 || dan>31 || mjesec<0 || mjesec>12 || godina<0) throw std::domain_error("Neispravan datum");
		else {
		Datum::dan=dan;
		Datum::mjesec=mjesec;
		Datum::godina=godina; }
	}
	void Postavi(int dan,int mjesec,int godina){
		if(dan<0 || dan>31 || mjesec<0 || mjesec>12 || godina<0) throw std::domain_error ("Neispravan datum");
		else {
			Datum::dan=dan;
			Datum::mjesec=mjesec;
			Datum::godina=godina; }
		}
	
	std::tuple<int,int,int> Ocitaj() const {
		std::tuple<int,int,int> novi;
 novi=std::make_tuple(dan,mjesec,godina);
		return novi;
	}
	void Ispisi() const{
		std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
	}
	
	friend class Pregled;
};


class Pregled {
	std::string ime_p;
	Datum datump;
	Vrijeme vrijemep;
	
	public:
	
	Pregled(const std::string &ime_pacijenta,const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda):datump(datum_pregleda),vrijemep(vrijeme_pregleda) {
		ime_p=ime_pacijenta;
	
	}
	
	Pregled(const std::string &ime_pacijenta,int dan_pregleda,int mjesec_pregleda,int godina_pregleda,int sati_pregleda,int minute_pregleda) : 
	datump(dan_pregleda,mjesec_pregleda,godina_pregleda),
	vrijemep(sati_pregleda,minute_pregleda) {
	
	ime_p=ime_pacijenta;
	
		
	}
	
	Vrijeme DajVrijemePregleda() const {
		return vrijemep;
	}
	
	static bool DolaziPrije(const Pregled &p1,const Pregled &p2){
		if(p1.datump.mjesec<p2.datump.mjesec && p1.datump.godina<p2.datump.godina) return true;
	     else if(p1.datump.mjesec==p2.datump.mjesec && p1.datump.godina==p2.datump.godina && p1.datump.dan<p2.datump.dan) return true;
		else if(p1.vrijemep.sati==p2.vrijemep.sati  && p1.vrijemep.minute<p2.vrijemep.minute) return true;
		 else return false;
		}
	void Ispisi(){
		std::cout<<std::left<<std::setprecision(30)<<ime_p<<" ";
		datump.Ispisi();
		std::cout<<" ";
		vrijemep.Ispisi();
		std::cout<<std::endl;
	}
	
		};
		class Pregledi{
			int br_p;
			int max_broj_p;
			Pregled **pregledii;
			explicit Pregledi(int max_broj_pregleda) : br_p(0), max_broj_p(max_broj_pregleda){
				pregledii=new Pregled*[max_broj_pregleda];
			}
			Pregledi(std::initializer_list<Pregled> spisak_pregleda): max_broj_p(spisak_pregleda.size()),br_p(spisak_pregleda.size()){
				pregledii=new Pregled *[br_p];
				int i(0);
				for(auto x=std::begin(spisak_pregleda);x!=std::end(spisak_pregleda);x++)
				pregledii[i]=new Pregled(*x);
				i++; 
			}
			~Pregledi(){
				for(int i(0);i<br_p;i++) delete pregledii[i];
				delete [] pregledii;	
				
			}
				Pregledi(const Pregledi &pregledi): max_broj_p(pregledi.max_broj_p),br_p(pregledi.br_p){
					pregledii=new Pregled *[pregledi.br_p]{};
					for(int i(0);i<pregledi.br_p;i++)
						pregledii[i]=new Pregled (*pregledi.pregledii[i]);
						}
						
						Pregledi(Pregledi &&pregledi){
							std::swap(pregledii,pregledi.pregledii);
							pregledi.pregledii=nullptr;
						}
						
						Pregledi &operator =(const Pregledi &pregledi){
						
							for(int i(0);i<br_p;i++) delete pregledii[i];
							delete [] pregledii;
							
							br_p=pregledi.br_p;
							pregledii=new Pregled *[pregledi.br_p];
							for(int i(0);i<pregledi.br_p;i++)
							pregledii[i]=new Pregled(*pregledi.pregledii[i]);
							
							
						}
							
							Pregledi &operator=(Pregledi &&pregledi){
								
								pregledii=std::move(pregledi.pregledii);
								return *this;
							}
							
			           void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda){
			           	
			           }
							
						
		};
int main ()
{   try {
	Vrijeme v(12,3);
	Datum d(12,4 ,2003);
	Datum d1(12,4,2005);
	Vrijeme v1(12,1);


	
 }


  catch(std::domain_error e){
		std::cout<<e.what();
	}
	return 0;
}
