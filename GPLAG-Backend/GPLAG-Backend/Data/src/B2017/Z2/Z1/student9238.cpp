/*B 2017/2018, Zadaća 2, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>

enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};
typedef std::vector<std::vector<Polje>> Tabla;
bool DaLiJeChar(char c){
	return c>='0' && c<='9';
}
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
		Tabla matrica(n,std::vector<Polje>(n,Polje::Prazno));
		for(int i=0; i<mine.size(); i++){
			if(mine[i].size()!=2)throw std::domain_error("Ilegalan format zadavanja mina");
			if(mine[i][0]<0 ||mine[i][0]>=n || mine[i][1]<0 ||mine[i][1]>=n) throw std::domain_error("Ilegalne pozicije mina");
			matrica[mine[i][0]][mine[i][1]]=Polje::Mina;
		}
		return matrica;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	for(int i=0; i<polja.size(); i++)
		if(x<0 || x>=polja[i].size() || y<0 || y>=polja.size())throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	
	if(polja.size()==0)throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	std::vector<std::vector<int>> okolina(3,std::vector<int> (3,0));
	int brmina(0);
	
	for(int xo=x-1; xo<=x+1;xo++){
		for(int yo=y-1;yo<=y+1;yo++){
			brmina=0;
			for(int i=xo-1; i<=xo+1;i++){
				for(int j=yo-1; j<=yo+1;j++){
					if( (i!=xo || yo!=j) && i>=0 && j>=0 && i<polja.size() && j<polja.size() && polja[i][j]==Polje::Mina)brmina++;
					if(j==yo+1)break;
				}
				if(i==xo+1)break;
			}
			okolina[xo-(x-1)][yo-(y-1)]=brmina;
			if(yo==y+1)break;
		}
		if(xo==x+1)break;
	}
	return okolina;
}
void BlokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size()){
		throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	}
	if(polja[x][y]==Polje::Posjeceno)polja[x][y]=Polje::BlokiranoPosjeceno;
	else if(polja[x][y]==Polje::Mina)polja[x][y]=Polje::BlokiranoMina;
	else if(polja[x][y]==Polje::Prazno)polja[x][y]=Polje::BlokiranoPrazno;
}
void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size()){
		throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	}
	if(polja[x][y]==Polje::BlokiranoPosjeceno)polja[x][y]=Polje::Posjeceno;
	else if(polja[x][y]==Polje::BlokiranoMina)polja[x][y]=Polje::Mina;
	else if(polja[x][y]==Polje::BlokiranoPrazno)polja[x][y]=Polje::Prazno;
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int x1(x);
	int y1(y);
	if(smjer==Smjerovi::GoreLijevo){x1--;y1--;}
	else if(smjer==Smjerovi::Gore)x1--;
	else if(smjer==Smjerovi::GoreDesno){x1--; y1++;}
	else if(smjer==Smjerovi::Desno){y1++;}
	else if(smjer==Smjerovi::DoljeDesno){x1++; y1++;}
	else if(smjer==Smjerovi::Dolje){x1++;}
	else if(smjer==Smjerovi::DoljeLijevo){y1--;x1++;}
	else if(smjer==Smjerovi::Lijevo){y1--;}
	if(x1<0 || y1<0 || x1>=polja.size() || y1>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
	
	if(polja[x1][y1]==Polje::BlokiranoPrazno || polja[x1][y1]==Polje::BlokiranoPosjeceno  || polja[x1][y1]==Polje::BlokiranoMina ) throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x=x1;
	y=y1;
	if(polja[x1][y1]==Polje::Mina){
		for(int i=0; i<polja.size(); i++)
			for(int j=0; j<polja[i].size();j++)
				polja[i][j]=Polje::Prazno;
		return Status::KrajPoraz;
	}
	bool kraj(true);
	for(int i=0; i<polja.size(); i++){
		for(int j=0; j<polja[i].size();j++){
			if((polja[i][j]== Polje::Prazno ||polja[i][j]==Polje::BlokiranoPrazno) && !(i==x1 && j==y1))kraj=false;
		}
	}
	if(!kraj)return Status::NijeKraj;
	return Status::KrajPobjeda;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x<0 || novi_y<0 || novi_x>=polja.size() || novi_y>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno  || polja[novi_x][novi_y]==Polje::BlokiranoMina ) throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if(polja[novi_x][novi_y]==Polje::Mina){ 
		for(int i=0; i<polja.size(); i++)
			for(int j=0; j<polja[i].size();j++)
				polja[i][j]=Polje::Prazno;
		return Status::KrajPoraz;}
	for(int i=0; i<polja.size(); i++){
		for(int j=0; j<polja[i].size();j++){
			if((polja[i][j]== Polje::Prazno || polja[i][j]== Polje::BlokiranoPrazno )&& !(i==novi_x && j==novi_y))return Status::NijeKraj;
		}
	}
	if(polja[novi_x][novi_y]==Polje::Prazno)return Status::KrajPobjeda;
	return Status::KrajPobjeda;
}
void PrijaviGresku(KodoviGresaka greska){
	switch(greska){
		case KodoviGresaka::PogresnaKomanda:
			std::cout<<"Nerazumljiva komanda!"<<std::endl;
			break;
		case KodoviGresaka::NedostajeParametar:
			std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
			break;
		case KodoviGresaka::NeispravanParametar:
			std::cout<<"Parametar komande nije ispravan!"<<std::endl;
			break;
		case KodoviGresaka::SuvisanParametar:
			std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
			break;
	}
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska){
	std::string ulaz;
	std::getline(std::cin,ulaz);
	int i(0);
	while(i<ulaz.size() && ulaz[i]==' ')i++;
	if(i==ulaz.size()){
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	switch(ulaz[i]){
		case 'K':{
			i++;
			if(i==ulaz.size()){
				komanda=Komande::KreirajIgru;
				return true;
			}
			while(i<ulaz.size() && ulaz[i]==' ')i++;
			if(i<ulaz.size()){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			komanda=Komande::KreirajIgru;
			return true;}
			break;
		case 'Z':{
			i++;
			if(i==ulaz.size()){
				komanda=Komande::ZavrsiIgru;
				return true;
			}
			while(i<ulaz.size() && ulaz[i]==' ')i++;
			if(i<ulaz.size()){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			komanda=Komande::ZavrsiIgru;
			return true;}
			break;
		case 'B':{
			i++;
			while(i<ulaz.size() && ulaz[i]==' '){ i++;}
			if(i==ulaz.size()){
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			if(!DaLiJeChar(ulaz[i])){
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			int x1(0);
			int y1(0);
			int znak(1);
			while(i<ulaz.size() && DaLiJeChar(ulaz[i])){
				if(ulaz[i]=='-')znak=-1;
				else{
					x1*=10;
					x1+=ulaz[i]-'0';
				}
				i++;
			}
			x1*=znak;
			while(i<ulaz.size() && ulaz[i]==' ')i++;
			if(i==ulaz.size()){
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			znak=1;
			while(i<ulaz.size() && DaLiJeChar(ulaz[i])){
				if(ulaz[i]=='-')znak=-1;
				else{
					y1*=10;
					y1+=ulaz[i]-'0';
				}
				i++;
			}
			y1*=znak;
			while(i<ulaz.size() && ulaz[i]==' ')i++;
			if(i!=ulaz.size()){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			komanda=Komande::Blokiraj;
			x=x1;
			y=y1;
			return true;
		}
			break;
		case 'D':{
			i++;
			while(i<ulaz.size() && ulaz[i]==' '){i++;}
			if(i==ulaz.size()){
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			if(!DaLiJeChar(ulaz[i])){
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			int x1(0);
			int y1(0);
			int znak(1);
			while(i<ulaz.size() && DaLiJeChar(ulaz[i])){
				if(ulaz[i]=='-')znak=-1;
				else{
					x1*=10;
					x1+=ulaz[i]-'0';
				}
				i++;
			}
			x1*=znak;
			while(i<ulaz.size() && ulaz[i]==' ')i++;
			if(i==ulaz.size()){
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			znak=1;
			while(i<ulaz.size() && DaLiJeChar(ulaz[i])){
				if(ulaz[i]=='-')znak=-1;
				else{
					y1*=10;
					y1+=ulaz[i]-'0';
				}
				i++;
			}
			y1*=znak;
			while(i<ulaz.size() && ulaz[i]==' ')i++;
			if(i!=ulaz.size()){
				greska=KodoviGresaka::SuvisanParametar; 
				return false;
			}
			komanda=Komande::Deblokiraj;
			x=x1;
			y=y1;
			return true;}
			break;
		case 'P':{
			i++;
			if(i==ulaz.size()){
				greska=KodoviGresaka::PogresnaKomanda;
				return false;
			}
			if(ulaz[i]=='1'){
				i++;
				while(i<ulaz.size() && ulaz[i]==' ')i++;
				if(i==ulaz.size()){
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
				std::string kom;
				while(i<ulaz.size() && ulaz[i]!=' '){kom.push_back(ulaz[i]); i++;}
				while(i<ulaz.size() && ulaz[i]==' ')i++;
				if(i!=ulaz.size()){
					greska=KodoviGresaka::SuvisanParametar; 
					return false;
				}
				Smjerovi gr;
				if(kom=="GL")gr=Smjerovi::GoreLijevo;
				else if(kom=="G")gr=Smjerovi::Gore;
				else if(kom=="GD")gr=Smjerovi::GoreDesno;
				else if(kom=="D")gr=Smjerovi::Desno;
				else if(kom=="DoD")gr=Smjerovi::DoljeDesno;
				else if(kom=="Do")gr=Smjerovi::Dolje;
				else if(kom=="DoL")gr=Smjerovi::DoljeLijevo;
				else if(kom=="L")gr=Smjerovi::Lijevo;
				else{
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
				smjer=gr;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}else if(ulaz[i]=='O'){
				i++;
				while(i<ulaz.size() && ulaz[i]==' ') i++;
				if(i!=ulaz.size()){
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
				komanda=Komande::PrikaziOkolinu;
				return true;
			}else if(ulaz[i]=='>'){
				i++;
				while(i<ulaz.size() && ulaz[i]==' '){ i++;}
				
				if(i==ulaz.size()){
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
				if(!DaLiJeChar(ulaz[i])){
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
				int x1(0);
				int y1(0);
				int znak(1);
				while(i<ulaz.size() && DaLiJeChar(ulaz[i])){
					if(ulaz[i]=='-')znak=-1;
					else{
						x1*=10;
						x1+=ulaz[i]-'0';
					}
					i++;
				}
				x1*=znak;
				while(i<ulaz.size() && ulaz[i]==' ')i++;
				if(i==ulaz.size()){
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
				znak=1;
				while(i<ulaz.size() && DaLiJeChar(ulaz[i])){
					if(ulaz[i]=='-')znak=-1;
					else{
						y1*=10;
						y1+=ulaz[i]-'0';
					}
					i++;
				}
				y1*=znak;
				while(i<ulaz.size() && ulaz[i]==' ')i++;
				if(i!=ulaz.size()){
					greska=KodoviGresaka::SuvisanParametar; 
					return false;
				}
				komanda=Komande::PomjeriDalje;
				x=x1;
				y=y1;
				return true;
			}else{
				greska=KodoviGresaka::PogresnaKomanda;
				return false;
			}
		}
			break;
		default:
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		break;
	}
	return true;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	switch(komanda){
		case Komande::PomjeriJednoMjesto:
			try{
				Status rez(Idi(polja,x,y,p_smjer));
				if(rez==Status::NijeKraj){std::cout<<"Tekuca pozicija igraca je ("<<std::to_string(x)<<","<<std::to_string(y)<<")"<<std::endl;}
				else if(rez==Status::KrajPoraz){std::cout<<"Nagazili ste na minu"<<std::endl;
					for(int i=0; i<polja.size();i++)
						for(int j=0; j<polja[i].size();j++)
							polja[i][j]=Polje::Prazno;
					throw std::runtime_error("Igra zavrsena");
				}else if(rez==Status::KrajPobjeda){
					std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
					for(int i=0; i<polja.size();i++)
						for(int j=0; j<polja[i].size();j++)
							polja[i][j]=Polje::Prazno;
					throw std::runtime_error("Igra zavrsena");
				}
			}
			catch(std::out_of_range a){std::cout<<a.what()<<std::endl;}
			catch(std::logic_error b){std::cout<<b.what()<<std::endl;}
			break;
		case Komande::PomjeriDalje:
			try{
				Status rez(Idi(polja,x,y,p_x,p_y));
				if(rez==Status::NijeKraj){std::cout<<"Tekuca pozicija igraca je ("<<std::to_string(x)<<","<<std::to_string(y)<<")"<<std::endl;}
				else if(rez==Status::KrajPoraz){std::cout<<"Nagazili ste na minu"<<std::endl;
						for(int i=0; i<polja.size();i++)
							for(int j=0; j<polja[i].size();j++)
								polja[i][j]=Polje::Prazno;
						throw std::runtime_error("Igra zavrsena");
				}else if(rez==Status::KrajPobjeda){
					std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
					for(int i=0; i<polja.size();i++)
						for(int j=0; j<polja[i].size();j++)
							polja[i][j]=Polje::Prazno;
					throw std::runtime_error("Igra zavrsena");
				}
			}
			catch(std::out_of_range a){std::cout<<a.what()<<std::endl;}
			catch(std::logic_error b){std::cout<<b.what()<<std::endl;}
			break;
		case Komande::Blokiraj:
			try{
				BlokirajPolje(polja,p_x,p_y);
			}catch(std::domain_error a){std::cout<< a.what()<<std::endl;}
			break;
		case Komande::Deblokiraj:
			try{
				DeblokirajPolje(polja,p_x,p_y);
			}catch(std::domain_error a){std::cout<< a.what()<<std::endl;}
			break;
		case Komande::PrikaziOkolinu:
			try{
				std::vector<std::vector<int>> ok;
				ok=PrikaziOkolinu(polja,x,y);
				for(int i=0; i<ok.size();i++){
					for(int j=0; j<ok[i].size();j++){
						std::cout<<ok[i][j]<<" ";
					}
					std::cout<<std::endl;
				}
			}catch(std::domain_error x){
				std::cout<<x.what()<<std::endl;
			}
			break;
		case Komande::ZavrsiIgru:
			for(int i=0; i<polja.size();i++)
				for(int j=0; j<polja[i].size();j++)
					polja[i][j]=Polje::Prazno;
			throw std::runtime_error("Dovidjenja!");
			break;
		case Komande::KreirajIgru:
			int brp;
			std::cout<<"Unesite broj polja: ";
			std::cin>>brp;
			std::vector<std::vector<int>> mine(0);
			std::string ulaz;
			int brmina(0);
			std::cout<<"Unesite pozicije mina: ";
			std::cin.ignore(10000,'\n');
			while(true){	
				std::getline(std::cin,ulaz);
				if(ulaz=="."){
					break;}
				int i(0);
				int prva(0);
				int druga(0);
				bool nemagr(true);
				while(i<ulaz.size() && ulaz[i]!='('){if(ulaz[i]!=' ')nemagr=false; i++;}
				if(nemagr && ulaz[i]=='('){
					i++;
					while(i<ulaz.size() && ulaz[i]==' ')i++;
					int znak(1);
					while(i<ulaz.size() && DaLiJeChar(ulaz[i])){
						if(ulaz[i]=='-')znak=-1;
						else {prva*=10; prva+=ulaz[i]-'0';}
						i++;
					}
					prva*=znak;
					while(i<ulaz.size() && ulaz[i]==' ')i++;
					if(i<ulaz.size() && ulaz[i]==','){
						i++;
						while(i<ulaz.size() && ulaz[i]==' ')i++;
						znak=1;
						while(i<ulaz.size() && DaLiJeChar(ulaz[i])){
							if(ulaz[i]=='-')znak=-1;
							else {druga*=10; druga+=ulaz[i]-'0';}
							i++;
						}
						druga*=znak;
						while(i<ulaz.size() && ulaz[i]==' ')i++;
						if(i<ulaz.size() && ulaz[i]==')'){
							if(prva>brp ||druga>brp ||prva<0 || druga<0 ||(prva==0 && druga==0))std::cout<<"Greska, unesite ponovo!"<<std::endl;
							else{
								i++;
								while(i<ulaz.size() && ulaz[i]==' ')i++;
								if(i==ulaz.size()){
									bool imavec(false);
									for(int i=0; i<mine.size();i++)
										if(mine[i][0]==prva && mine[i][1]==druga){imavec=true;break;}
									if(!imavec){mine.push_back({prva,druga});
									brmina++;}
								}else std::cout<<"Greska, unesite ponovo!"<<std::endl;
							}
						}
						else std::cout<<"Greska, unesite ponovo!"<<std::endl;
					}else std::cout<<"Greska, unesite ponovo!"<<std::endl;
				}else std::cout<<"Greska, unesite ponovo!"<<std::endl;
			}
			try{
				polja=KreirajIgru(brp,mine);
			}catch(std::domain_error a){
				std::cout<<a.what()<<std::endl;
			}
			break;
	}
}
int main (){
	Smjerovi smj;
	int x(0);
	int y(0);
	int xu(0);
	int yu(0);
	KodoviGresaka greska;
	Komande kom;
	std::vector<std::vector<int>> nulm(0);
	Tabla a(KreirajIgru(0,nulm));
	bool ok(true);
	while(true){
		std::cout<<"Unesite komandu: ";
		try{
			ok=UnosKomande(kom,smj,xu,yu,greska);
			if(ok)
				IzvrsiKomandu(kom,a,x,y,smj,xu,yu);
			else
				PrijaviGresku(greska);
		}catch(std::runtime_error a){
			std::cout<<a.what()<<std::endl;
			break;
		}catch(...){
			break;
		}
	}
	return 0;
}
