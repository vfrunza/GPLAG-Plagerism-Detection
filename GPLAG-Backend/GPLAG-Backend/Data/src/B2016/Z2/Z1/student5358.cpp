#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <sstream>
#include <complex>

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;

std::string ZaIzuzetak(int x,int y){
	std::string s="Polje (";
	s+= std::to_string(x);
	s+=",";
	s+= std::to_string(y);
	s+=") ne postoji";
	return s;
}
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	Tabla t(n,std::vector<Polje>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		t[i][j]=Polje::Prazno;
		for(int k=0;k<mine.size();k++){
			if(mine[k].size()!=2)throw std::domain_error("Ilegalan format zadavanja mina");
			int a=mine[k][0];
			int b=mine[k][1];
			if(a<0 || a>n-1 || b<0 || b>n-1)throw std::domain_error("Ilegalne pozicije mina");
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++){
					if(i==a && j==b)t[i][j]=Polje::Mina;
				}
		}
		return t;
}
void BlokirajPolje(Tabla &polja, int x, int y){
	//std::cout<<"s"<<polja.size();
	if(x>polja.size()-1 || y>polja.size()-1)throw std::domain_error(ZaIzuzetak(x,y));;
	for(int i=0;i<polja.size();i++){
		//std::cout<<polja[i].size();
		for(int j=0;j<polja[i].size();j++){
			if(i==x && j==y){
				//std::cout<<"a"<<i<<j;
				if(polja[i][j]==Polje::Prazno)polja[i][j]=Polje::BlokiranoPrazno;
				else if(polja[i][j]==Polje::Posjeceno)polja[i][j]=Polje::BlokiranoPosjeceno;
				else if(polja[i][j]==Polje::Mina)polja[i][j]=Polje::BlokiranoMina;
			}
		}
	}
}
void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x>polja.size()-1 || y>polja.size()-1)throw std::domain_error(ZaIzuzetak(x,y));;
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja[i].size();j++){
			if(i==x && j==y){
				if(polja[i][j]==Polje::BlokiranoPrazno)polja[i][j]=Polje::Prazno;
				else if(polja[i][j]==Polje::BlokiranoPosjeceno)polja[i][j]=Polje::Posjeceno;
				else if(polja[i][j]==Polje::BlokiranoMina)polja[i][j]=Polje::Mina;
			}
		}
	}
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	//std::cout<<"zadar"<<x<<y;
	//polja[x][y]=Polje::Posjeceno;
	if(smjer==Smjerovi::GoreLijevo){if(y==0 || x==0)throw std::out_of_range("Izlazak van igrace table");if(polja[x-1][y-1]==Polje::BlokiranoPosjeceno || polja[x-1][y-1]==Polje::BlokiranoPrazno || polja[x-1][y-1]==Polje::BlokiranoMina )throw std::logic_error("Blokirano polje");x=x-1;y=y-1;polja[x+1][y+1]=Polje::Posjeceno;}
	else if(smjer==Smjerovi::Gore){if(x==0)throw std::out_of_range("Izlazak van igrace table");if(polja[x-1][y]==Polje::BlokiranoPosjeceno || polja[x-1][y]==Polje::BlokiranoPrazno || polja[x-1][y]==Polje::BlokiranoMina )throw std::logic_error("Blokirano polje");x=x-1;polja[x+1][y]=Polje::Posjeceno;}
	else if(smjer==Smjerovi::GoreDesno){if(y==polja.size() || x==0)throw std::out_of_range("Izlazak van igrace table");if(polja[x-1][y+1]==Polje::BlokiranoPosjeceno || polja[x-1][y+1]==Polje::BlokiranoPrazno || polja[x-1][y+1]==Polje::BlokiranoMina )throw std::logic_error("Blokirano polje");x=x-1;y=y+1;polja[x+1][y-1]=Polje::Posjeceno;}
	else if(smjer==Smjerovi::Lijevo){if(y==0)throw std::out_of_range("Izlazak van igrace table");if(polja[x][y-1]==Polje::BlokiranoPosjeceno || polja[x][y-1]==Polje::BlokiranoPrazno || polja[x][y-1]==Polje::BlokiranoMina )throw std::logic_error("Blokirano polje");y=y-1;polja[x][y+1]=Polje::Posjeceno;}
	else if(smjer==Smjerovi::Desno){if(y==polja.size())throw std::out_of_range("Izlazak van igrace table");if(polja[x][y+1]==Polje::BlokiranoPosjeceno || polja[x][y+1]==Polje::BlokiranoPrazno || polja[x][y+1]==Polje::BlokiranoMina )throw std::logic_error("Blokirano polje");y=y+1;polja[x][y-1]=Polje::Posjeceno;}
	else if(smjer==Smjerovi::DoljeLijevo){if(y==0 || x==polja.size())throw std::out_of_range("Izlazak van igrace table");if(polja[x+1][y-1]==Polje::BlokiranoPosjeceno || polja[x+1][y-1]==Polje::BlokiranoPrazno || polja[x+1][y-1]==Polje::BlokiranoMina )throw std::logic_error("Blokirano polje");x=x+1;y=y-1;polja[x-1][y+1]=Polje::Posjeceno;}
	else if(smjer==Smjerovi::Dolje){if(x==polja.size())throw std::out_of_range("Izlazak van igrace table");if(polja[x+1][y]==Polje::BlokiranoPosjeceno || polja[x+1][y]==Polje::BlokiranoPrazno || polja[x+1][y]==Polje::BlokiranoMina )throw std::logic_error("Blokirano polje");x=x+1;polja[x-1][y]=Polje::Posjeceno;}
	else if(smjer==Smjerovi::DoljeDesno){if(y==polja.size() || x==polja.size())throw std::out_of_range("Izlazak van igrace table");if(polja[x+1][y+1]==Polje::BlokiranoPosjeceno || polja[x+1][y+1]==Polje::BlokiranoPrazno || polja[x+1][y+1]==Polje::BlokiranoMina )throw std::logic_error("Blokirano polje");x=x+1;y=y+1;polja[x-1][y-1]=Polje::Posjeceno;}
	//std::cout<<"zadar"<<x<<y;
	if(polja[x][y]==Polje::Mina){
		std::vector<std::vector<int>>v ;
		polja=KreirajIgru(polja.size(),v);
		return Status::KrajPoraz;
	}
	Polje a=Polje::Posjeceno;
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja.size();j++){
			if(x!=i && y!=j)
			if(polja[i][j]!=a && polja[i][j]!=Polje::Mina)return Status::NijeKraj;
		}
	}
	return Status::KrajPobjeda;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	//polja[x][y]=Polje::Posjeceno;
	//std::cout<<x<<y;
	if(novi_x>polja.size()-1 || novi_y>polja.size()-1 || novi_x<0 || novi_y<0)throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoMina || polja[novi_x][novi_y]==Polje::BlokiranoPrazno)throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if(polja[x][y]==Polje::Mina){
		std::vector<std::vector<int>>v ;
		polja=KreirajIgru(polja.size(),v);
		return Status::KrajPoraz;
	}
	Polje a=Polje::Posjeceno;
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja.size();j++){
			if(x!=i && y!=j)
			if(polja[i][j]!=a && polja[i][j]!=Polje::Mina)return Status::NijeKraj;
		}
	}
	return Status::KrajPobjeda;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	if(x>polja.size()-1 || y>polja.size()-1 || x<0 || y<0)throw std::domain_error(ZaIzuzetak(x,y));
	std::vector<std::vector<int>> o(3,std::vector<int>(3));
	//std::cout<<x<<y;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			int bmina=0;
			if(x-1+i>=0 || y-1+j>=0 || x+1+i<=polja.size()-1 || y+1+j<=polja.size()-1){
			int g=x-1+i,h=y-1+j;
			//std::cout<<g<<" "<<h;
			for(int k=0;k<3;k++){
				for(int d=0;d<3;d++){
					if((g-1+k>=0 && h-1+d>=0) && (g+1+k<=polja.size() && h+1+d<=polja.size() ) )
					if(g-1+k>=0 && h-1+d>=0 &&(g-1+k!=x-1+i || h-1+d!=y-1+j) && polja[g-1+k][h-1+d]==Polje::Mina )bmina++;
				}
			}
		}
			o[i][j]=bmina;
		}
	}
	return o;
}
void PrijaviGresku(KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda)std::cout<<"Nerazumljiva komanda!"<<std::endl;
	else if(greska==KodoviGresaka::NedostajeParametar)std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	else if(greska==KodoviGresaka::NeispravanParametar)std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	else std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string s;
    std::getline(std::cin,s);
   // std::cout<<s;
    if(s=="K"){
    	komanda=Komande::KreirajIgru;
    	return true;
    }
    else if(s=="Z"){
    	komanda=Komande::ZavrsiIgru;
    	return true;
    }
    else if(s[0]=='P' && s[1]=='O'){
    	komanda=Komande::PrikaziOkolinu;
    	return true;
    }
    else if(s[0]=='P' && s[1]=='1'){
    	/*for(int i=2;i<s.length();i++){
    		if((s[i]<'0' || s[i]>'9') && s[i]!=' '){
                greska=KodoviGresaka::NeispravanParametar;
                return false;
            }
    	}*/
    	if(s=="P1"){
    		greska=KodoviGresaka::NedostajeParametar;
    		return false;
    	}
    	s.erase(s.begin()+0);
    	s.erase(s.begin()+0);
    	//std::cout<<"W"<<s;
    	std::string pom;
    	for(int i=0;i<s.size();i++){
            if(s[i]==' '){s.erase(s.begin()+i);i--;}
    	}
    	pom=s;
    	if(pom=="GL"){
    		komanda=Komande::PomjeriJednoMjesto;
    		smjer=Smjerovi::GoreLijevo;
    		return true;
    	}
    	else if(pom=="G"){
    		komanda=Komande::PomjeriJednoMjesto;
    		smjer=Smjerovi::Gore;
    		return true;
    	}
    	else if(pom=="GD"){
    		komanda=Komande::PomjeriJednoMjesto;
    		smjer=Smjerovi::GoreDesno;
    		return true;
    	}
    	else if(pom=="D"){
    		komanda=Komande::PomjeriJednoMjesto;
    		smjer=Smjerovi::Desno;
    		return true;
    	}
    	else if(pom=="DoD"){
    		komanda=Komande::PomjeriJednoMjesto;
    		smjer=Smjerovi::DoljeDesno;
    		return true;
    	}
    	else if(pom=="Do"){
    		komanda=Komande::PomjeriJednoMjesto;
    		smjer=Smjerovi::Dolje;
    		return true;
    	}
    	else if(pom=="DoL"){
    		komanda=Komande::PomjeriJednoMjesto;
    		smjer=Smjerovi::DoljeLijevo;
    		return true;
    	}
    	else if(pom=="L"){
    		komanda=Komande::PomjeriJednoMjesto;
    		smjer=Smjerovi::Lijevo;
    		return true;
    	}
    	else{
    		greska=KodoviGresaka::SuvisanParametar;
    		return false;
    	}
    }
    else if(s[0]=='P' && s[1]=='>'){
    	for(int i=2;i<s.length();i++){
    		if((s[i]<'0' || s[i]>'9') && s[i]!=' '){
                greska=KodoviGresaka::NeispravanParametar;
                return false;
            }
    	}
    	if(s=="P>"){
    		greska=KodoviGresaka::NedostajeParametar;
    		return false;
    	}
    	s.erase(s.begin()+0);
    	s.erase(s.begin()+0);
    	//std::cout<<s<<std::endl;
    	std::stringstream d,c;
    	std::string f,g;
    	for(int i=0;i<s.size();i++){
    		while(s[i]==' ')i++;
    		while(s[i]!= ' '){f.push_back(s[i]);i++;}
    		while(s[i]==' ')i++;
    		while(i!=s.size() && s[i]!=' ' ){g.push_back(s[i]);i++;}
    		if(i==s.size())i--;
    		while(i!=s.size()-1 && s[i]==' ' )i++;
    		if(i==s.size() && s[i]!=' '  ){greska=KodoviGresaka::SuvisanParametar;return false;}
    	}
    	//std::cout<<f<<" "<<g;
    	d<<f;
    	d>>x;
    	c<<g;
    	c>>y;
    	komanda=Komande::PomjeriDalje;
    	return true;
    }
    else if(s[0]=='B'){
    	for(int i=1;i<s.length();i++){
    		if((s[i]<'0' || s[i]>'9') && s[i]!=' '){
                greska=KodoviGresaka::NeispravanParametar;
                return false;
            }
    	}
    	s.erase(s.begin()+0);
    	//std::cout<<"sss"<<s;
    	std::stringstream d,c;
    	std::string f,g;
    	for(int i=0;i<s.size();i++){
    		while(s[i]==' ')i++;
    		while(s[i]!= ' '){f.push_back(s[i]);i++;}
    		while(s[i]==' ')i++;
    		while(i!=s.size() && s[i]!=' ' ){g.push_back(s[i]);i++;}
    		if(i==s.size())i--;
    		while(i!=s.size()-1 && s[i]==' ' )i++;
    		if( i==s.size() && s[i]!=' ' ){greska=KodoviGresaka::SuvisanParametar;return false;}
    	}
    	d<<f;
    	d>>x;
    	c<<g;
    	c>>y;
    	komanda=Komande::Blokiraj;
    	return true;
    }
    else if(s[0]=='D'){
    	for(int i=1;i<s.length();i++){
    		if((s[i]<'0' || s[i]>'9') && s[i]!=' '){
                greska=KodoviGresaka::NeispravanParametar;
                return false;
            }
    	}
    	s.erase(s.begin()+0);
    	std::stringstream d,c;
    	std::string f,g;
    	for(int i=0;i<s.size();i++){
    		while(s[i]==' ')i++;
    		while(s[i]!= ' '){f.push_back(s[i]);i++;}
    		while(s[i]==' ')i++;
    		while(i!=s.size() && s[i]!=' ' ){g.push_back(s[i]);i++;}
    		if(i==s.size())i--;
    		while(i!=s.size()-1 && s[i]==' ' )i++;
    		if( i==s.size() && s[i]!=' ' ){greska=KodoviGresaka::SuvisanParametar;return false;}
    	}
    	d<<f;
    	d>>x;
    	c<<g;
    	c>>y;
    	komanda=Komande::Deblokiraj;
    	return true;
    }
    else{
    	greska=KodoviGresaka::PogresnaKomanda;
    	return false;
    }
}
void IspisiPoziciju(int x,int y){
	std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	if(komanda==Komande::KreirajIgru){
		try{
		std::cout<<"Unesite broj polja: ";
		int n;
		std::cin>>n;
		std::cout<<"Unesite pozicije mina: ";
		std::complex<int> z;
		std::vector<std::vector<int>>mine ;
		int b=0;
		std::cin.clear();
        std::cin.ignore(10000,'\n');
		while(true){
			std::string s;
			std::cin>>s;
			if(s==".")break;
			for(int i=0;i<s.size();i++){
				if(s[0]!='('){
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					std::cin.clear();
            		std::cin.ignore(10000,'\n');
        			break;
				}
				i++;
				std::stringstream d,c;
				std::string br1,br2;
				while(s[i]>='0' && s[i]<='9'){br1.push_back(s[i]);i++;}
				if(s[i]!=','){
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					std::cin.clear();
            		std::cin.ignore(10000,'\n');
        			break;
				}
				i++;
				while(s[i]>='0' && s[i]<='9'){br2.push_back(s[i]);i++;}
				if(s[i]!=')'){
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					std::cin.clear();
            		std::cin.ignore(10000,'\n');
        			break;
				}
				if(br1.size()>0 && br2.size()>0){
					int x,y;
					d<<br1;
					d>>x;
					c<<br2;
					c>>y;
					if(x>n-1 || y>n-1 || x<0 || y<0){
						std::cout<<"Greska, unesite ponovo!"<<std::endl;
					std::cin.clear();
            		std::cin.ignore(10000,'\n');
        			break;
					}
					else{
						std::vector<int>v;
						v.push_back(x);
						v.push_back(y);
						mine.push_back(v);
						b++;
					}
				}
				else{
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					std::cin.clear();
            		std::cin.ignore(10000,'\n');
        			break;
				}
			}
		}
		std::cin.clear();
            std::cin.ignore(10000,'\n');
		polja=KreirajIgru(n,mine);
	}
	catch(std::domain_error e){
			std::cout<<"Izuzetak: "<<e.what()<<std::endl;
		}
	}
	else if(komanda==Komande::PomjeriJednoMjesto){
		Status s=Idi(polja,x,y,p_smjer);
		if(s==Status::KrajPobjeda)std::cout<<"Bravo, obisli ste sva sigurna polja";
		else if (s==Status::KrajPoraz){std::cout<<"Nagazili ste na minu"<<std::endl;throw std::runtime_error("Igra zavrsena");}
		//else Idi(polja,x,y,p_smjer);
		IspisiPoziciju(x,y);
	}
	else if(komanda==Komande::PomjeriDalje){
		try{
			Status s=Idi(polja,p_x,p_y,x,y);
		if(s==Status::KrajPobjeda)std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
		else if(s==Status::KrajPoraz){std::cout<<"Nagazili ste na minu"<<std::endl;throw std::runtime_error("Igra zavrsena");}
		//else s;
		IspisiPoziciju(x,y);
		}
		catch(std::out_of_range e){
			std::cout<<"Izuzetak: "<<e.what()<<std::endl;
		}
		catch(std::logic_error e){
			std::cout<<e.what()<<std::endl;
		}
	}
	else if(komanda==Komande::Blokiraj){
		try{
		BlokirajPolje(polja,x,y);
		}
		catch(std::domain_error e){
			std::cout<<"Izuzetak: "<<e.what()<<std::endl;
		}
	}
	else if(komanda==Komande::Deblokiraj){
		try{
		DeblokirajPolje(polja,x,y);
		}
		catch(std::domain_error e){
			std::cout<<"Izuzetak: "<<e.what()<<std::endl;
		}
	}
	else if(komanda==Komande::PrikaziOkolinu){
		try{
		std::vector<std::vector<int>>b=PrikaziOkolinu(polja,x,y) ;
		for(int i=0;i<b.size();i++){
	for(int j=0;j<b[i].size();j++)
	std::cout<<b[i][j]<<" ";
	std::cout<<std::endl;
	}
		}
		catch(std::domain_error e){
			std::cout<<"Izuzetak: "<<e.what()<<std::endl;
		}
	}
	else if(komanda==Komande::ZavrsiIgru){
		std::vector<std::vector<int>>v ;
		polja=KreirajIgru(polja.size(),v);
		throw std::runtime_error("Igra zavrsena");
	}
}
/*void ispisiTablu(std::vector<std::vector<Polje>> polja){
 for(int i = 0; i < polja.size(); i++) {
 for(int j = 0; j < polja[i].size(); j++) std::cout << int(polja[i][j]) << " ";
 std::cout << std::endl;
 }
}*/
int main ()
{
	try{
	Komande komanda;
	int x=0,y=0,p_x,p_y;
	KodoviGresaka greska;
	Smjerovi smjer;
	Tabla t;
	while (true) {
		p_x=x;
		p_y=y;
		std::cout<<"Unesite komandu: ";
		if(UnosKomande(komanda,smjer,x,y,greska)){
			if(komanda==Komande::ZavrsiIgru){
				std::cout<<"Dovidjenja!";
				break;
			}
			
				IzvrsiKomandu(komanda,t,x,y,smjer,p_x,p_y);
		}
		else PrijaviGresku(greska);
	}
	}
	catch(std::runtime_error e){
			std::cout<<"Izuzetak: "<<e.what()<<std::endl;
		}
	return 0;
}