/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>

#include <stdexcept>


int BrojCifara(long long int broj)
{
	int brojac(0);
	if(broj==0) return 1;
	while(broj!=0)
	{
		broj=broj/10;
		brojac++;
		
	}
	return brojac;
}

int NadjiCifru(long long int broj,int cifra)
{
	int broj1=0;
	if(cifra>BrojCifara(broj))
	return 0;
	while(++broj1!=cifra)
	{
		
		broj=broj/10;
	}
	
	return broj%10;
}


long long int Cener(int n)
{
	long long int broj=1;
	for(int i=0;i<n;i++)
	broj=broj*10;
	return broj;
}






class GradjaninBiH{
	 std::string imeiprezime{};
	 int dan=0;
	 int mjesec=0;
	 int godinarodjenja=0;
	 int sifraregije=0;
	 long long int jmbg=0;
	 
	 GradjaninBiH* poka_na_proslu=nullptr;
	 static GradjaninBiH* trenutna;
	 public:
	 enum Pol {Musko, Zensko};
	 
	 

GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
int godina_rodjenja, int sifra_regije, Pol pol);
~GradjaninBiH(){delete poka_na_proslu;}
std::string DajImeIPrezime() const;
long long int DajJMBG() const;
int DajDanRodjenja() const;
int DajMjesecRodjenja() const;
int DajGodinuRodjenja() const;
int DajSifruRegije() const;
Pol DajPol() const;
void PromijeniImeIPrezime(std::string novo_ime);
};


GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
	
	
	if(NadjiCifru(jmbg,1)!=(11-(7*(NadjiCifru(jmbg,13)+NadjiCifru(jmbg,7))+6*(NadjiCifru(jmbg,12)+NadjiCifru(jmbg,6))+5*(NadjiCifru(jmbg,11)+NadjiCifru(jmbg,5))+4*(NadjiCifru(jmbg,10)+NadjiCifru(jmbg,4))+3*(NadjiCifru(jmbg,9)+NadjiCifru(jmbg,3))+2*(NadjiCifru(jmbg,8)+NadjiCifru(jmbg,2)))%11)%11)
	throw std::logic_error("JMBG nije validan");
	
	
	long long int gg,mj,dn;
	gg=(jmbg/Cener(7))%1000;
	mj=(jmbg/Cener(9))%100;
	dn=jmbg/(Cener(11));
	
	if(NadjiCifru(jmbg,9)!=0)
	gg=1000+NadjiCifru(jmbg,9)*100+NadjiCifru(jmbg,8)*10+NadjiCifru(jmbg,7);
	else
	gg=2000+NadjiCifru(jmbg,8)*10+NadjiCifru(jmbg,7);
	
	
	
	int niz[12]{31,28,31,30,31,30,31,31,30,31,30,31};
	

		if(gg<0 || mj<0 || mj>12 || dn<0 || (dn>niz[mj-1] && mj!=2))
		throw std::logic_error("JMBG nije validan");
		if(mj==2)
		{
			if(dn>niz[1]+(gg%400==0 ||(gg%4==0 && gg%100!=0)))
			throw std::logic_error("JMBG nije validan");
		}
	poka_na_proslu=trenutna;
	trenutna=this;
	auto p=poka_na_proslu;
	while(p!=nullptr)
	{
		if(p->jmbg==jmbg)
		throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
		p=p->poka_na_proslu;
		
	}
	
	
	
	
	
	dan=NadjiCifru(jmbg,13)*10+NadjiCifru(jmbg,12);
	mjesec=NadjiCifru(jmbg,11)*10+NadjiCifru(jmbg,10);
	if(NadjiCifru(jmbg,9)!=0)
	godinarodjenja=1000+NadjiCifru(jmbg,9)*100+NadjiCifru(jmbg,8)*10+NadjiCifru(jmbg,7);
	else
	godinarodjenja=2000+NadjiCifru(jmbg,8)*10+NadjiCifru(jmbg,7);
	
	imeiprezime=ime_i_prezime;
	sifraregije=10*NadjiCifru(jmbg,6)+NadjiCifru(jmbg,5);
	/*if(NadjiCifru(jmbg,4)>=5)
	pol=Zensko;
	else
	pol=Musko;*/
	GradjaninBiH::jmbg=jmbg;
	
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
int godina_rodjenja, int sifra_regije, Pol pol){
	{int niz[12]{31,28,31,30,31,30,31,31,30,31,30,31};
		if(sifra_regije<0 || sifra_regije>99 || godina_rodjenja<0 || mjesec_rodjenja<0 || mjesec_rodjenja>12 || dan_rodjenja<0 || (dan_rodjenja>niz[mjesec_rodjenja-1] && mjesec_rodjenja!=2))
		throw std::logic_error("Neispravni podaci");
		if(mjesec_rodjenja==2)
		{
			if(dan_rodjenja>niz[1]+(godinarodjenja%400==0 ||(godinarodjenja%4==0 && godinarodjenja%100!=0)))
			throw std::logic_error("Neispravni podaci");
		}
	}
	int broj=0;
	if(pol==Zensko)
	broj=500;
	int brojac=0;
	int kontrola;
	poka_na_proslu=trenutna;
	trenutna=this;
	GradjaninBiH* p=poka_na_proslu;
        
    kontrola=(11-(7*(NadjiCifru(dan_rodjenja,2)+NadjiCifru(godina_rodjenja,1))+6*(NadjiCifru(dan_rodjenja,1)+NadjiCifru(sifra_regije,2))+5*(NadjiCifru(mjesec_rodjenja,2)+NadjiCifru(sifra_regije,1))+4*(NadjiCifru(mjesec_rodjenja,1)+NadjiCifru(broj,3))+3*(NadjiCifru(godina_rodjenja,3)+NadjiCifru(broj,3))+2*(NadjiCifru(godina_rodjenja,2)+NadjiCifru(broj,2)))%11)%11;

 	    while(p!=nullptr)
	    {
		     kontrola=(11-(7*(NadjiCifru(dan_rodjenja,2)+NadjiCifru(godina_rodjenja,1))+6*(NadjiCifru(dan_rodjenja,1)+NadjiCifru(sifra_regije,2))+5*(NadjiCifru(mjesec_rodjenja,2)+NadjiCifru(sifra_regije,1))+4*(NadjiCifru(mjesec_rodjenja,1)+NadjiCifru(broj,3))+3*(NadjiCifru(godina_rodjenja,3)+NadjiCifru(broj,3))+2*(NadjiCifru(godina_rodjenja,2)+NadjiCifru(broj,2)))%11)%11;
             if(kontrola==10)
             {
            	broj++;brojac++;
            	return;
             }
        
		    
		    if(p->dan==dan_rodjenja && p->mjesec==mjesec_rodjenja && p->godinarodjenja==godina_rodjenja && p->sifraregije==sifra_regije && (NadjiCifru(p->jmbg,4)*100+NadjiCifru(p->jmbg,3)*10+NadjiCifru(p->jmbg,2))==broj && kontrola==(p->jmbg)%10)
	        {
	        	broj++;
	        	brojac++;
	        }
	        if(brojac==500 )
	        {
	        	break;
	        }
		    p=p->poka_na_proslu;
		 
	    }
	    
	if(brojac==500)
	std::cout<<"Belajcina";
	else
	jmbg=kontrola+Cener(1)*broj+Cener(4)*sifra_regije+Cener(6)*(godina_rodjenja%1000)+Cener(9)*mjesec_rodjenja+Cener(11)*dan_rodjenja;
}
std::string GradjaninBiH::DajImeIPrezime() const{return imeiprezime;}

long long int GradjaninBiH::DajJMBG() const{
	return jmbg;
}
int GradjaninBiH::DajDanRodjenja() const{return dan;}
int GradjaninBiH::DajMjesecRodjenja() const{return mjesec;}
int GradjaninBiH::DajGodinuRodjenja() const{return godinarodjenja;}
int GradjaninBiH::DajSifruRegije() const{return sifraregije;}
GradjaninBiH::Pol GradjaninBiH::DajPol() const{
	
	if(NadjiCifru(jmbg,4)<5)
	return Pol::Musko;
	else
	return Pol::Zensko;
	
}
void GradjaninBiH::PromijeniImeIPrezime(std::string novo_ime){imeiprezime=novo_ime;}






GradjaninBiH* GradjaninBiH::trenutna(nullptr); 

int main ()
{
	
{std::cout<<"Koliko gradjana zelite unijeti po JMBG?"<<std::endl;
	int n;
	std::cin>>n;
	std::cin.ignore(10000,'\n');
	GradjaninBiH** pok=nullptr;
	try{
	pok=new GradjaninBiH*[n]{};
	}
	catch(...)
	{
		std::cout<<"Nedovoljno memorije!";
		return 0;
	}

	
	for(int i=0;i<n;i++)
	{
	
		std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
		std::string a;
		std::getline(std::cin,a);
		long long int jmbg;
		std::cout<<"Unesite JMBG: "<<std::endl;
		std::cin>>jmbg;
		std::cin.ignore(10000,'\n');
		GradjaninBiH* p=nullptr;
		
		
		try{
			p=new GradjaninBiH(a,jmbg);
		
		pok[i]=p;
		std::cout<<"Unijeli ste gradjanina "<<a<<" rodjenog "<<pok[i]->DajDanRodjenja()<<"."<<pok[i]->DajMjesecRodjenja()<<"."<<pok[i]->DajGodinuRodjenja()<<" ";
		std::cout<<"u regiji "<<pok[i]->DajSifruRegije()<<", ";
		if(pok[i]->DajPol()==GradjaninBiH::Pol::Musko)
		std::cout<<"musko."<<std::endl;
		else
		std::cout<<"zensko."<<std::endl;
		}
		catch(std::logic_error e)
		{
			std::cout<<e.what()<<std::endl;i--;
		}
		
	}
	for(int i=0;i<n;i++)
	delete pok[i];
	delete[] pok;
}

{
	std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<std::endl;
	int n;
	std::cin>>n;
	std::cin.ignore(10000,'\n');
	GradjaninBiH** pok=nullptr;
	try{
	pok=new GradjaninBiH*[n]{};
	}
	catch(...)
	{
		std::cout<<"Nedovoljno memorije!";
		return 0;
	}
	
	for(int i=0;i<n;i++)
	{
pok[i]=nullptr;
		try{std::string a;
		std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
		std::getline(std::cin,a);
		
		std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<std::endl;
		std::string datum;
		std::getline(std::cin,datum);
		int ddd,mmm,ggg;
		ddd=(datum[0]-'0')*10+datum[1]-'0';
		mmm=(datum[3]-'0')*10+datum[4]-'0';
		ggg=(datum[6]-'0')*1000+(datum[7]-'0')*100+(datum[8]-'0')*10+datum[9]-'0';
		std::cout<<"Unesite sifru regije: "<<std::endl;
		int sifra;
		std::cin>>sifra;
		std::cout<<"Unesite M za musko, Z za zensko: "<<std::endl;
		
		char r;
		std::cin>>r;
		std::cin.ignore(10000,'\n');
		GradjaninBiH::Pol o;
		if(r=='M')
		o=GradjaninBiH::Pol::Musko;
		else
		o=GradjaninBiH::Pol::Zensko;
		
		GradjaninBiH* p=nullptr;
		
			p=new GradjaninBiH(a,ddd,mmm,ggg,sifra,o);
		pok[i]=p;
		std::cout<<"Unijeli ste gradjanina "<<a<<" JMBG: "<<pok[i]->DajJMBG()<<"."<<std::endl;
		
		}
		catch(std::logic_error e){
			std::cout<<e.what()<<std::endl;i--;}
		
	}
		
	for(int i=0;i<n;i++)
	delete pok[i];
	delete[] pok;
}


	return 0;
}

