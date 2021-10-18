/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
template <typename T> std::string PretvoriUString(T x) {
 std::ostringstream s; s << x; return s.str();
}
enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};
enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};
typedef std::vector<std::vector<Polje>> Tabla;
bool broj(std::string s){
	int broj(0);
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&& s[i]<='9')broj++;
	}
	if(broj==s.length())return true;
	return false;
}
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	Tabla igra(n,std::vector<Polje>(n));
	//auto broj=mine[0].size();
	for(int i=0;i<mine.size();i++){
		if(mine[i].size()!=2)throw std::domain_error("Ilegalan format zadavanja mina");
	}
	for(int i=0;i<mine.size();i++){
		for(int j=0;j<mine[i].size();j++){
			if(mine[i][j]<0 || mine[i][j]>n)throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	for(int i=0;i<mine.size();i++){
		int prva_kor=mine[i][0];
		int druga_kor=mine[i][1];
		igra[prva_kor][druga_kor]=Polje::Mina;
	}
	for(int i=0;i<igra.size();i++){
		for(int j=0;j<igra[i].size();j++){
			if(igra[i][j]!=Polje::Mina)igra[i][j]=Polje::Prazno;
		}
	}
	return igra;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	if(x<0 || y<0 || x>=polja.size() || y>=polja[0].size())throw std::domain_error("Polje ("+PretvoriUString(x)+","+PretvoriUString(y)+") ne postoji");
	std::vector<std::vector<int>> okolina;
	for(int i=x-1;i<=x+1;i++){
		std::vector<int>v;
		for(int j=y-1;j<=y+1;j++){
			int mina(0);
			for(int k=i-1;k<=i+1;k++){
				for(int l=j-1;l<=j+1;l++){
					if((i!=k ||  j!=l) && k>=0 && l>=0 && k<polja.size() && l<polja.size()  && polja[k][l]==Polje::Mina)mina++;
		    }
	    }
	 v.push_back(mina);
	}
	 okolina.push_back(v);
}
	return okolina;
}
void BlokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size())throw std::domain_error("Polje ("+PretvoriUString(x)+","+PretvoriUString(y)+") ne postoji");
			if(polja[x][y]==Polje::Prazno)polja[x][y]=Polje::BlokiranoPrazno;
			if(polja[x][y]==Polje::Mina)polja[x][y]=Polje::BlokiranoMina;
			if(polja[x][y]==Polje::Posjeceno)polja[x][y]=Polje::BlokiranoPosjeceno;
			//std::cout<<"Lamija";
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size())throw std::domain_error("Polje ("+PretvoriUString(x)+","+PretvoriUString(y)+") ne postoji");
	
			if(polja[x][y]==Polje::BlokiranoPrazno)polja[x][y]=Polje::Prazno;
			if(polja[x][y]==Polje::BlokiranoMina)polja[x][y]=Polje::Mina;
			if(polja[x][y]==Polje::BlokiranoPosjeceno)polja[x][y]=Polje::Posjeceno;
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int novax=x,novay=y;
	//	std::cout<<"Laamija";
	if(novax<0 || novay<0 || novax>=polja.size() || novay>=polja.size())throw std::out_of_range("Izlazak van igrace table");
	
	if(polja[novax][novay]==Polje::BlokiranoPosjeceno || polja[novax][novay]==Polje::BlokiranoPrazno || polja[novax][novay]==Polje::BlokiranoMina)throw std::logic_error("Blokirano polje");
		//	polja[novax][novay]=Polje::Posjeceno;
		//	polja[x][y]=Polje::Posjeceno;
			if(smjer==Smjerovi::GoreDesno) {novax--; novay++;}
			if(smjer==Smjerovi::GoreLijevo){novay--;novay--;}
			if(smjer==Smjerovi::DoljeLijevo){novax++;novay--;}
			if(smjer==Smjerovi::DoljeDesno){novax++;novay++;}
			if(smjer==Smjerovi::Gore)novax--;
			if(smjer==Smjerovi::Dolje)novax++;
			if(smjer==Smjerovi::Lijevo)novay--;
			if(smjer==Smjerovi::Desno)novay++;
			if(novax<0 || novay<0 || novax>=polja.size() || novay>=polja.size())throw std::out_of_range("Izlazak van igrace table");
			if(polja[novax][novay]==Polje::BlokiranoPosjeceno || polja[novax][novay]==Polje::BlokiranoPrazno || polja[novax][novay]==Polje::BlokiranoMina)throw std::logic_error("Blokirano polje");
	//	if(novax<0 || novay<0 || novax>=polja.size() || novay>=polja.size())throw std::out_of_range("Izlazak van igrace table");

polja[x][y]=Polje::Posjeceno;
polja[novax][novay]=Polje::Prazno;
	if(polja[novax][novay]==Polje::Mina){
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();i++){
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	bool nema_praznih(true);
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja[i].size();j++){
			if(polja[i][j]==Polje::Prazno)nema_praznih=false;
		}
	}
	if(nema_praznih==true)return Status::KrajPobjeda;
	x=novax;
	y=novay;
//	polja[x][y]=Polje::Posjeceno;
	return Status::NijeKraj;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
		if(x<0 || y<0 || x>=polja.size() || y>=polja.size())throw std::out_of_range("Izlazak van igrace table");
		if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina)throw std::logic_error("Blokirano polje\n");
		polja[x][y]=Polje::Posjeceno;
		if(novi_x<0 || novi_y<0 || novi_x>=polja.size() || novi_y>=polja.size())throw std::out_of_range("Izlazak van igrace table");
			x=novi_x; y=novi_y;
if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina)throw std::logic_error("Blokirano polje\n");
	//	x=novi_x; y=novi_y;
		if(polja[novi_x][novi_y]==Polje::Mina){
			for(int i=0;i<polja.size();i++){
				for(int j=0;j<polja[i].size();j++){
					polja[i][j]=Polje::Prazno;
				}
			}
		return Status::KrajPoraz;
		}
		bool nema_praznih(true);
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++){
				if(polja[i][j]==Polje::Prazno)nema_praznih=false;
			}
		}
		if(nema_praznih==true)return Status::KrajPobjeda;
		//polja[x][y]=Polje::Posjeceno;
		return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda)std::cout<<"Nerazumljiva komanda!\n";
	if(greska==KodoviGresaka::NedostajeParametar)std::cout<<"Komanda trazi parametar koji nije naveden!\n";
	if(greska==KodoviGresaka::SuvisanParametar)std::cout<<"Zadan je suvisan parametar nakon komande!\n";
	if(greska==KodoviGresaka::NeispravanParametar)std::cout<<"Parametar komande nije ispravan!\n";
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska){
	std::string s;
	std::getline(std::cin, s);
	std::vector<std::string> v;
	int i=0;
		while(i<s.length() && s[i]==' ')i++;
	if(s[i]=='K'){
		i++;
		while(i<s.length() && s[i]==' ')i++;
		if(i==s.length()){komanda=Komande::KreirajIgru;return true;}
		else{greska=KodoviGresaka::SuvisanParametar;return false;}
	}
	else if(s[i]=='Z'){
		i++;
		while(i<s.length() && s[i]==' ')i++;
		if(i==s.length()){komanda=Komande::ZavrsiIgru;return true;}
		else{greska=KodoviGresaka::SuvisanParametar;return false;}
		
	}
	else if(s[i]=='B'){
		i++;
		while(i<s.length() && s[i]==' ')i++; //preskoci razmake
		if(i==s.length()){greska=KodoviGresaka::NedostajeParametar;return false;} //dosla do kraja
		if(!(s[i]>='0'&&s[i]<='9')){greska=KodoviGresaka::NedostajeParametar;return false;} //nisam nasla broj
		std::string r;
		while(i<s.size() && s[i]>='0'&&s[i]<='9'){ r.push_back(s[i]);i++;}
		r.push_back('\0');
		int broj1= atoi(r.c_str());
		//int broj1=std::stoi(r);
		while(i<s.length() && s[i]==' ')i++; //preskocila razmake
		if(i==s.length()){greska=KodoviGresaka::NedostajeParametar;return false;} //dosla do kraja
		if(i<s.size() && !(s[i]>='0'&&s[i]<='9')){greska=KodoviGresaka::NedostajeParametar;return false;}//nisam nasla drugu koordinatu
		std::string p;
		while(i<s.size() && s[i]>='0'&&s[i]<='9'){ p.push_back(s[i]);i++;}
		p.push_back('\0');
		int broj2 = atoi(p.c_str());
	//	std::cout<<broj1<<"   pa   "<<broj2;
	//	int broj2=std::stoi(p);
		while(i<s.length() && s[i]==' ')i++; //preskacem razmake
		if(i==s.length()){komanda=Komande::Blokiraj;x=broj1;y=broj2;return true;}
		else {greska=KodoviGresaka::SuvisanParametar;return false;}
	}
	else if(s[i]=='D'){
		i++;
		while(i<s.length() && s[i]==' ')i++; //preskoci razmake
		if(i==s.length()){greska=KodoviGresaka::NedostajeParametar;return false;} //dosla do kraja
		if(!(s[i]>='0'&&s[i]<='9')){greska=KodoviGresaka::NedostajeParametar;return false;} //nisam nasla broj
		std::string r,p;
		while(s[i]>='0'&&s[i]<='9'){r.push_back(s[i]);i++;} //nasla broj
		r.push_back('\0');
		int broj1= atoi(r.c_str());
		while(i<s.length() && s[i]==' ')i++; //preskocila razmake
		if(i==s.length()){greska=KodoviGresaka::NedostajeParametar;return false;} //dosla do kraja
		if(!(s[i]>='0'&&s[i]<='9')){greska=KodoviGresaka::NedostajeParametar;return false;}//nisam nasla drugu koordinatu
		while(s[i]>='0'&&s[i]<='9'){p.push_back(s[i]);i++;}
		p.push_back('\0');
		int broj2= atoi(p.c_str());//trazim broj,drugu koordinatu
		while(i<s.length() && s[i]==' ')i++; //preskacem razmake
		if(i==s.length()){komanda=Komande::Deblokiraj;x=broj1;y=broj2;return true;}
		else {greska=KodoviGresaka::SuvisanParametar;return false;}
	}
		else if(s[i]=='P'){
		i++;
		if(s[i]=='O'){
			i++;
			while(i<s.length() && s[i]==' ')i++;
			if(i==s.length()){komanda=Komande::PrikaziOkolinu;return true;}
			greska=KodoviGresaka::NeispravanParametar;return false;
		}
		if(s[i]=='>'){
		i++;
		 if(i==s.length()){greska=KodoviGresaka::NedostajeParametar;return false;}
		while(i<s.length() && s[i]==' ')i++; //preskoci razmake
		if(i==s.length()){greska=KodoviGresaka::NeispravanParametar;return false;} //dosla do kraja
		if(!(s[i]>='0'&&s[i]<='9')){greska=KodoviGresaka::NeispravanParametar;return false;} //nisam nasla broj
		std::string r;
		while(s[i]>='0'&&s[i]<='9'){r.push_back(s[i]);i++;}         //nasla broj
		r.push_back('\0');
		int broj1= atoi(r.c_str());
		while(i<s.length() && s[i]==' ')i++; //preskocila razmake
		if(i==s.length()){greska=KodoviGresaka::NedostajeParametar;return false;} //dosla do kraja
		if(!(s[i]>='0'&&s[i]<='9')){greska=KodoviGresaka::NeispravanParametar;return false;}//nisam nasla drugu koordinatu
		std::string p;
		while(s[i]>='0'&&s[i]<='9'){p.push_back(s[i]);i++;} //trazim broj,drugu koordinatu
		p.push_back('\0');
		int broj2= atoi(p.c_str());
		while(i<s.length() && s[i]==' ')i++; //preskacem razmake
	//	std::cout<<broj1<<broj2;
		if(i==s.length()){komanda=Komande::PomjeriDalje;x=broj1;y=broj2;return true;}
		else {greska=KodoviGresaka::NeispravanParametar;return false;}
		}
		else if(s[i]=='1'){
			
	//	std::cout<<"Ovo je posebni cenzurisani cout";
		i++;
		while(i<s.length() && s[i]==' ')i++; //preskoci razmake
		if(i==s.length()){greska=KodoviGresaka::NedostajeParametar;return false;} //dosla do kraja
		else if(s[i]=='L'){
			i++;
			while(i<s.length() && s[i]==' ')i++; //preskocila razmake
			if(i==s.length()){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::Lijevo;return true;}
			else {greska=KodoviGresaka::NeispravanParametar;return false;}
		}
		else if(s[i]=='G'){
			i++;
			while(i<s.length() && s[i]==' ')i++; //preskocila razmake
			if(i==s.length()){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::Gore;return true;}
			if(s[i]=='L')i++;
			while(i<s.length() && s[i]==' ')i++; //preskocila razmake
			if(i==s.length()){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::GoreLijevo;return true;}
			if(s[i]=='D')i++;
			while(i<s.length() && s[i]==' ')i++; //preskocila razmake
			while(i<s.length() && s[i]==' ')i++; //preskocila razmake
			if(i==s.length()){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::GoreDesno;return true;}
			while(i<s.length() && s[i]==' ')i++; 
			 greska=KodoviGresaka::NeispravanParametar;return false;
		}
		if(s[i]=='D'){
			i++;
			//while(i<s.length() && s[i]==' ')i++; 
			if(i==s.length()){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::Desno;return true;}
			else if(!(s[i]=='o')){greska=KodoviGresaka::PogresnaKomanda;return false;}
			else if(s[i]=='o')i++;
			while(i<s.length() && s[i]==' ')i++; 
			if(i==s.length()){ komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::Dolje;return true;}
			if(s[i]=='L')i++;
			while(i<s.length() && s[i]==' ')i++; 
			if(i==s.length()){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::DoljeLijevo;return true;}
			else if(s[i]=='D')i++;
			while(i<s.length() && s[i]==' ')i++; //preskocila razmake
			if(i==s.length()){komanda=Komande::PomjeriJednoMjesto;smjer=Smjerovi::DoljeDesno;return true;}
			else {greska=KodoviGresaka::NeispravanParametar;return false;}
		}
			else { greska=KodoviGresaka::NeispravanParametar;return false;}
		}
		else{greska=KodoviGresaka::PogresnaKomanda;return false;}
	}
	else{ greska=KodoviGresaka::PogresnaKomanda;return false;}

}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	if(komanda==Komande::PomjeriJednoMjesto){
	Status novi=Idi(polja,x,y,p_smjer);
		if(novi==Status::NijeKraj){
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")\n";
		
		}
		else if(novi==Status::KrajPoraz){
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")\n";
			std::cout<<std::endl<<"Nagazili ste na minu";
		}
		else if(novi==Status::KrajPobjeda){
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")\n";
			std::cout<<std::endl<<"Bravo, obisli ste sva sigurna polja";
			}
		}
	else if(komanda==Komande::Blokiraj){
		BlokirajPolje(polja,x,y);
	}
	else if(komanda==Komande::Deblokiraj){
		DeblokirajPolje(polja,x,y);
	}
	else if(komanda==Komande::PrikaziOkolinu){
		std::vector<std::vector<int>>mat(PrikaziOkolinu(polja,x,y));
		for(int i=0;i<mat.size();i++){
			for(int j=0;j<mat[i].size();j++){
				std::cout<<mat[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
	}
	else if(komanda==Komande::PomjeriDalje){
		Status novi;
		try{
		 novi= Idi(polja,p_x,p_y, x, y );
	
			if(novi==Status::NijeKraj){
				novi= Idi(polja,p_x,p_y, p_x,p_y );
				std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")\n";
		
			}
			else if(novi==Status::KrajPoraz){
				std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")\n";
				std::cout<<std::endl<<"Nagazili ste na minu";
			}
		else if(novi==Status::KrajPobjeda){
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")\n";
			std::cout<<std::endl<<"Bravo, obisli ste sva sigurna polja";
			}
		}
		catch(std::logic_error e){
			std::cout<<e.what();
		}
	}
		
	else if(komanda==Komande::KreirajIgru){
		std::cout<<"Unesite broj polja: ";
		int n;
		std::cin>>n;
		std::vector<std::vector<int>> vek;
		std::cin.ignore(1000000,'\n');
		std::cout<<"Unesite pozicije mina: ";
		for(;;){
			int broj1,broj2;
			char s1,s2,s3;
			bool nema_greske(true);
			std::vector<int>v;
			std::cin>>s1;
			if(s1=='.'){nema_greske=false;std::cin.clear();std::cin.ignore(10000,'\n');break;}
			else if(!(std::cin) || s1!='('){nema_greske=false;std::cout<<"Greska, unesite ponovo!\n";std::cin.clear();std::cin.ignore(10000,'\n');}
			else{
				std::cin>>broj1;
		if(!(std::cin) || std::cin.peek()=='\n' || broj1>=n){nema_greske=false;std::cout<<"Greska, unesite ponovo!\n";std::cin.clear();std::cin.ignore(1000,'\n');}
				else{
					std::cin>>s3;
					if(!(std::cin)|| std::cin.peek()=='\n'){nema_greske=false;std::cout<<"Greska, unesite ponovo!\n";std::cin.clear();std::cin.ignore(10000,'\n');}
					else{
						std::cin>>broj2;
			if(!(std::cin) || std::cin.peek()=='\n'|| broj2>=n){nema_greske=false;std::cout<<"Greska, unesite ponovo!\n";std::cin.clear();std::cin.ignore(10000,'\n');}
						else{
							std::cin>>s2;
							if(!(std::cin)|| s2!=')'|| std::cin.peek()!='\n'){nema_greske=false;std::cout<<"Greska, unesite ponovo!\n";std::cin.clear();std::cin.ignore(10000,'\n');}
							
						}
					}
				}
			}
			if(nema_greske==true){v.push_back(broj1);v.push_back(broj2);vek.push_back(v);}
		}
	
	polja=KreirajIgru(n,vek);
}
	else if(komanda==Komande::ZavrsiIgru){
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		if(komanda==Komande::ZavrsiIgru)throw std::runtime_error("Dovidjenja!");
	}
}

int main ()
{

Komande NekeKomande;
	Status NekiStatusi;
	Smjerovi NekiSmjerovi;
	KodoviGresaka NekeGreske;
	Tabla prazna;
	int a=0,b=0;
	int x=a;
	int y=b;
	for(;;){
		std::cout<<"Unesite komandu: ";
		try{
		if(UnosKomande(NekeKomande,NekiSmjerovi,x,y,NekeGreske)==true) IzvrsiKomandu(NekeKomande,prazna,x,y,NekiSmjerovi,a,b);
		else PrijaviGresku(NekeGreske);
		}
		catch(std::out_of_range e){
		std::cout<<e.what();}
		catch(std::domain_error e){
		std::cout<<e.what();}
		catch(std::logic_error e){
		std::cout<<e.what();}
		catch(std::runtime_error e){
		std::cout<<e.what();break;}
	}
return 0;
}