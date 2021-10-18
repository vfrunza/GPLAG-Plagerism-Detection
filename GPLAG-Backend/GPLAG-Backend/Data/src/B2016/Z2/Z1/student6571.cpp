/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <complex>
enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};

enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};

enum class Status { NijeKraj, KrajPoraz, KrajPobjeda};

enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar,  SuvisanParametar, NeispravanParametar};

enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};
typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<std::vector<int>> Matrica;

Tabla KreirajMatricu(int br_redova, int br_kolona) {
	return Tabla(br_redova,std::vector<Polje>(br_kolona));
	
}
Matrica Kreiraj(int br_redova, int br_kolona){
	return Matrica(br_redova, std::vector<int>(br_kolona));
}
Matrica UnesiMatricu(int br_redova, int br_kolona) {

	Matrica m(br_redova, std::vector<int>(br_kolona));
	for(int i=0; i<20; i++){
		for(int j=0; j<2; j++){
			std::cin>>m[i][j];
			if(m[i][j]=='.') break;
		}
	}
	return m;
}
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	
	Tabla A=KreirajMatricu(n,n);
	
	for(int i=0; i<A.size(); i++){
		for(int j=0; j<A[i].size(); j++){
			A[i][j]=Polje::Prazno;
		}
	}
	
	Tabla Polja=KreirajMatricu(n,n);
	
	for(int i=0; i<A.size(); i++){
		for(int j=0; j<A[i].size(); j++){
			for(int k=0; k<mine.size(); k++){
				if(i==mine[k][0] && j==mine[k][1]){
					Polja[i][j]=Polje::Mina;
				}
				
			}
		}
	}

	return Polja;
	
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
		std::vector<int> niz_okolina;
	if(x==1 && y==1){
	
		int glh=x-1, glv=y-1;
		int gsh=x-1, gsv=y;
		int gdh=x-1, gdv=y+1;
		
		int slh=x, slv=y-1;
		int tth=x,ttv=y;
		int sdh=x, sdv=y+1;
		
		int dlh=x+1,dlv=y-1;
		int dsh=x+1, dsv=y;
		int ddh=x+1, ddv=y+1;
		
		int brojac1=0,brojac2=0,brojac3=0,brojac4=0,brojac5=0,brojac6=0,brojac7=0,brojac8=0,brojac9=0;
		
		for(int i=glh; i<glh+2; i++){
			for(int j=glv; j<glv+2; j++){
				if(polja[i][j]==Polje::Mina) brojac1++;
				
				if(i==glh && j==glv && polja[i][j]==Polje::Mina) brojac1 = brojac1 - 1;
			}
		}
		niz_okolina.push_back(brojac1);
		
		for(int i=gsh; i<gsh+2; i++){
			for(int j=gsv-1; j<gsv+2; j++){
				if(polja[i][j]==Polje::Mina) brojac2++;
				if(i==gsh && j==gsv && polja[i][j]==Polje::Mina) brojac2 = brojac2 - 1;
			}
		}
		niz_okolina.push_back(brojac2);
	
		for(int i=gdh; i<gdh+2; i++){
			for(int j=gdv-1; j<gdv+2; j++){
				if(polja[i][j]==Polje::Mina) brojac3++;
				
				if(i==gdh && j==gdv && polja[i][j]==Polje::Mina) brojac3 = brojac3-1;
			}
		}
		niz_okolina.push_back(brojac3);
		
		for(int i=slh-1; i<slh+2; i++){
			for(int j=slv; j<slv+2; j++){
				if(polja[i][j]==Polje::Mina) brojac4 ++;
				
				if(i==slh && j==slv && polja[i][j]==Polje::Mina) brojac4 = brojac4 - 1;
			}
		}
		niz_okolina.push_back(brojac4);
		
		for(int i=tth-1; i<tth+2; i++){
			for(int j=ttv-1; j<ttv+2; j++){
				if( polja[i][j]==Polje::Mina) brojac5 ++;
				
				if(i==tth && j==ttv && polja[i][j]==Polje::Mina) brojac5 = brojac5-1;
			}
		}
		niz_okolina.push_back(brojac5);
		
		for(int i=sdh-1; i<sdh+2; i++){
			for(int j=sdv-1; j<sdv+2; j++){
				if(polja[i][j]==Polje::Mina) brojac6++;
				
				if(i==sdh && j==sdv && polja[i][j]==Polje::Mina) brojac6 = brojac6-1;
			}
		}
		niz_okolina.push_back(brojac6);
		
		for(int i=dlh-1; i<dlh+2; i++){
			for(int j=dlv; j<dlv+2; j++){
				if(polja[i][j]==Polje::Mina) brojac7 ++;
				
				if(i==dlh && j==dlv && polja[i][j]==Polje::Mina) brojac7 = brojac7 - 1;
			}
		}
		niz_okolina.push_back(brojac7);
		
		for(int i=dsh-1; i<dsh+2; i++){
			for(int j=dsv-1; j<dsv+2; j++){
				if(polja[i][j]==Polje::Mina) brojac8 ++;
				
				if(i==dsh && j==dsv && polja[i][j]==Polje::Mina) brojac8 = brojac8 - 1;
			}
		}
		niz_okolina.push_back(brojac8);
		
		for(int i=ddh-1; i<ddh+2; i++){
			for(int j=ddv-1; j<ddv+2; j++){
				if(polja[i][j]==Polje::Mina) brojac9 ++;
				
				if(i==ddh && j==ddv && polja[i][j]==Polje::Mina) brojac9 = brojac9-1;
			}
		}
		niz_okolina.push_back(brojac9);
		
		Matrica MatricaPonavljanja=Kreiraj(3,3);
		int c(0);
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				MatricaPonavljanja[i][j]=niz_okolina[c];
				c++;
				
				
			}
		}
		return MatricaPonavljanja;
		
	}
	
	if(x>=2 && y>=2){
		int glh=x-1, glv=y-1;
		int gsh=x-1, gsv=y;
		int gdh=x-1, gdv=y+1;
		
		int slh=x,slv=y-1;
		int tth=x,ttv=y;
		int sdh=x, sdv=y+1;
		
		int dlh=x+1,dlv=y-1;
		int dsh=x+1,dsv=y;
		int ddh=x+1,ddv=y+1;
		
		int brojac1=0,brojac2=0,brojac3=0,brojac4=0,brojac5=0,brojac6=0,brojac7=0,brojac8=0,brojac9=0;
		
		for(int i=glh-1; i<glh+2; i++){
			for(int j=glv-1; j<glv+2; j++){
				if(polja[i][j]==Polje::Mina) brojac1 ++;
				
				if(i==glh && j==glv && polja[i][j]==Polje::Mina) brojac1 = brojac1-1;
			}
		}
		niz_okolina.push_back(brojac1);
		
		for(int i=gsh-1; i<gsh+2; i++){
			for(int j=gsv-1; j<gsv+2; j++){
				if(polja[i][j]==Polje::Mina) brojac2 ++;
				
				if(i==gsh && j==gsv && polja[i][j]==Polje::Mina) brojac2 = brojac2-1;
			}
		}
		niz_okolina.push_back(brojac2);
		
		for(int i=gdh-1; i<gdh+2; i++){
			for(int j=gdv-1; j<gdv+2; j++){
				if(polja[i][j]==Polje::Mina) brojac3++;
				
				if(i==gdh && j==gdv && polja[i][j]==Polje::Mina) brojac3 = brojac3 -1;
			}
		}
		niz_okolina.push_back(brojac3);
		
		for(int i=slh-1; i<slh+2; i++){
			for(int j=slv-1; j<slv+2; j++){
				if(polja[i][j]==Polje::Mina) brojac4 ++;
				
				if(i==slh && j==slv && polja[i][j]==Polje::Mina) brojac4 = brojac4 - 1;
			}
		}
		niz_okolina.push_back(brojac4);
		
		for(int i=tth-1; i<tth+2; i++){
			for(int j=ttv-1; j<ttv+2; j++){
				if(polja[i][j]==Polje::Mina) brojac5++;
				
				if(i==tth && j==ttv && polja[i][j]==Polje::Mina) brojac5 = brojac5 - 1;
			}
		}
		niz_okolina.push_back(brojac5);
		
		for(int i=sdh-1; i<sdh+2; i++){
			for(int j=sdv-1; j<sdv+2; j++){
				if(polja[i][j]==Polje::Mina) brojac6 ++;
				
				if(i==sdh && j==sdv && polja[i][j]==Polje::Mina) brojac6 = brojac6-1;
			}
		}
		niz_okolina.push_back(brojac6);
		
		for(int i=dlh-1; i<dlh+2; i++){
			for(int j=dlv-1; j<dlv+2; j++){
				if(polja[i][j]==Polje::Mina) brojac7++;
				
				if(i==dlh && j==dlv && polja[i][j]==Polje::Mina) brojac7 = brojac7-1;
			}
		}
		niz_okolina.push_back(brojac7);
		
		for(int i=dsh-1; i<dsh+2; i++){
			for(int j=dsv-1; j<dsv+2; j++){
				if(polja[i][j]==Polje::Mina) brojac8 ++;
				
				if(i==dsh && j==dsv && polja[i][j]==Polje::Mina) brojac8 = brojac8 - 1;
			}
		}
		niz_okolina.push_back(brojac8);
		
		for(int i=ddh-1; i<ddh+2; i++) {
			for(int j=ddv-1; j<ddv+2; j++){
				if(polja[i][j]==Polje::Mina) brojac9 ++;
				
				if(i==ddh && j==ddv && polja[i][j]==Polje::Mina) brojac9 = brojac9 - 1;
			}
		}
		niz_okolina.push_back(brojac9);
		
		Matrica MatricaPonavljanja=Kreiraj(3,3);
		int c(0);
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				MatricaPonavljanja[i][j]=niz_okolina[c];
				c++;
			}
		}
		return MatricaPonavljanja;
		
		
	}
	
}

void BlokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || x>polja.size() || y<0 || y>polja[0].size()) throw std::domain_error("Polje (x,y) ne postoji");
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja[i].size(); j++){
			if(i==x && j==y){
				if(polja[i][j]==Polje::Prazno) polja[i][j]=Polje::BlokiranoPrazno;
				
				if(polja[i][j]==Polje::Posjeceno) polja[i][j]=Polje::BlokiranoPosjeceno;
				
				if(polja[i][j]==Polje::Mina) polja[i][j]=Polje::BlokiranoMina;
			}
		}
	}
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || x>polja.size() || y<0 || y>polja[0].size()) throw std::domain_error("Polje (x,y) ne postoji");
	
	for(int i=0; i<polja.size(); i++){
		for(int j=0; j<polja[i].size(); j++){
			if(i==x && j==y){
				if(polja[i][j]==Polje::BlokiranoPrazno) polja[i][j]=Polje::Prazno;
				
				if(polja[i][j]==Polje::BlokiranoPosjeceno) polja[i][j]=Polje::Posjeceno;
				
				if(polja[i][j]==Polje::BlokiranoMina) polja[i][j]=Polje::Mina;
			}
		}
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	Status s;
	for(int i=0; i<polja.size(); i++){
		for(int j=0; j<polja[i].size(); j++){
			if(i==x && j==y){ polja[i][j]=Polje::Posjeceno;
		  }
	   }
	}
	for(int i=0; i<polja.size(); i++){
		for(int j=0; j<polja[i].size(); j++){
			if(smjer==Smjerovi::GoreLijevo) {
				if(polja[i][j]==Polje::Mina){
					s=Status::KrajPoraz;
					return s;
				}
				else if(polja[i][j]==Polje::Prazno){
				x=x-1;
				y=y-1;
				s=Status::NijeKraj;
				return s;
			
			    }
			    else if((i==polja.size()-1||j==polja[i].size()-1)&&polja[i][j]==Polje::Prazno){
			    	s=Status::KrajPobjeda;
			    	return s;
			    }
		   }
			else if(smjer==Smjerovi::Gore){
				if(polja[i][j]==Polje::Mina){
					s=Status::KrajPoraz;
					return s;
				}
				else if(polja[i][j]==Polje::Prazno){
					x=x-1;
					s=Status::NijeKraj;
					return s;
				}
				 else if((i==polja.size()-1||j==polja[i].size()-1)&&polja[i][j]==Polje::Prazno){
			    	s=Status::KrajPobjeda;
			    	return s;
			    }
				
			}
			else if(smjer==Smjerovi::GoreDesno){
				if(polja[i][j]==Polje::Mina){
					s=Status::KrajPoraz;
					return s;
				}
				else if(polja[i][j]==Polje::Prazno){
					x+1;
					y+1;
					s=Status::NijeKraj;
					return s;
				}
				 else if((i==polja.size()-1||j==polja[i].size()-1)&&polja[i][j]==Polje::Prazno){
			    	s=Status::KrajPobjeda;
			    	return s;
			    }
				
			}
			else if(smjer==Smjerovi::Lijevo){
				if(polja[i][j]==Polje::Mina){
					s=Status::KrajPoraz;
					return s;
				}
				else if(polja[i][j]==Polje::Prazno){
				y=y-1;
				s=Status::NijeKraj;
				return s;
				}
				 else if((i==polja.size()-1||j==polja[i].size()-1)&&polja[i][j]==Polje::Prazno){
			    	s=Status::KrajPobjeda;
			    	return s;
			    }
			}
			else if(smjer==Smjerovi::Desno){
				if(polja[i][j]==Polje::Mina){
					s=Status::KrajPoraz;
					return s;
				}
				else if(polja[i][j]==Polje::Prazno){
				x=x+1;
				s=Status::NijeKraj;
				return s;
				}
				 else if((i==polja.size()-1||j==polja[i].size()-1)&&polja[i][j]==Polje::Prazno){
			    	s=Status::KrajPobjeda;
			    	return s;
			    }
			}
			else if(smjer==Smjerovi::DoljeLijevo){
				if(polja[i][j]==Polje::Mina){
					s=Status::KrajPoraz;
					return s;
				}
				else if(polja[i][j]==Polje::Prazno){
				x=x+1;
				y=y-1;
				s=Status::NijeKraj;
				return s;
				}
				 else if((i==polja.size()-1||j==polja[i].size()-1)&&polja[i][j]==Polje::Prazno){
			    	s=Status::KrajPobjeda;
			    	return s;
			    }
			}
			else if(smjer==Smjerovi::Dolje){
				if(polja[i][j]==Polje::Mina){
					s=Status::KrajPoraz;
					return s;
				}
				else if(polja[i][j]==Polje::Prazno){
				x=x+1;
				s=Status::NijeKraj;
				return s;
				}
				 else if((i==polja.size()-1||j==polja[i].size()-1)&&polja[i][j]==Polje::Prazno){
			    	s=Status::KrajPobjeda;
			    	return s;
			    }
		
			}
			else if(smjer==Smjerovi::DoljeDesno){
				if(polja[i][j]==Polje::Mina){
					s=Status::KrajPoraz;
					return s;
				}
				else if(polja[i][j]==Polje::Prazno){
				x=x+1;
				y=y+1;
				s=Status::NijeKraj;
				return s;
					
					}
					 else if((i==polja.size()-1||j==polja[i].size()-1)&&polja[i][j]==Polje::Prazno){
			    	s=Status::KrajPobjeda;
			    	return s;
			    }
		   	}
	   	}
	
   	}
}


Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x<0 || novi_x>polja.size() || novi_y<0 || novi_y>polja[0].size()) throw std::out_of_range ("Izlazak van igrace table");
	
	for(int i=0; i<polja.size(); i++){
		for(int j=0; j<polja[i].size(); j++){
			if(i==novi_x && j==novi_y){
				if (polja[i][j]==Polje::BlokiranoPrazno) throw std::logic_error ("Blokirano polje");
				
				if( polja[i][j]==Polje::BlokiranoPosjeceno) throw std::logic_error ("Blokirano polje");
				
				if(polja[i][j]==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
				x=novi_x;
				y=novi_y;
			
				

			}  
			
			
		}
	}
}

bool UnesiKomandu(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string kkomanda;
	std::string novakomanda;
	std::getline(std::cin, kkomanda);
	for(int i=0; i<kkomanda.length(); i++){
		while(kkomanda[i]==' ') i++;
		
		while(kkomanda[i]!=' '&& i<kkomanda.length()){
			novakomanda.push_back(kkomanda[i]);
			i++;
		}
	}
	for(int i=0; i<novakomanda.length(); i++){
		if(novakomanda[i]=='P'&&novakomanda[i+1]=='1'){
			komanda=Komande::PomjeriJednoMjesto;
			if(novakomanda[i+2]=='G'&&novakomanda[i+3]=='L'){
				smjer=Smjerovi::GoreLijevo;
				return true;
			}
			else if(novakomanda[i+2]=='G') {
				smjer=Smjerovi::Gore;
				return true;
			}
			else if(novakomanda[i+2]=='G'&&novakomanda[i+3]=='D'){
				smjer=Smjerovi::GoreDesno;
				return true;
			}
			else if(novakomanda[i+2]=='D'){
				smjer=Smjerovi::Desno;
				return true;
			}
			else if(novakomanda[i+2]=='D'&&novakomanda[i+3]=='o'&&novakomanda[i+4]=='D'){
				smjer=Smjerovi::DoljeDesno;
				return true;
			}
			else if(novakomanda[i+2]=='D'&&novakomanda[i+3]=='o'){
				smjer=Smjerovi::Dolje;
				return true;
			}
			else if(novakomanda[i+2]=='D'&&novakomanda[i+3]=='o'&&novakomanda[i+4]=='L'){
				smjer=Smjerovi::DoljeLijevo;
				return true;
			}
			else if(novakomanda[i+2]=='L'){
				smjer=Smjerovi::Lijevo;
				return true;
			}
			else{
				greska=KodoviGresaka::PogresnaKomanda;
				return false;
			}
		}
		else if(novakomanda[i]=='P'&&novakomanda[i+1]=='>'){
			komanda=Komande::PomjeriDalje;
			if(novakomanda[i+2]>='0'&&novakomanda[i+2]<'9' && novakomanda[i+3]>='0'&& novakomanda[i+3]<='9'){
				x=novakomanda[i+2];
				y=novakomanda[i+3];
				return true;
			}
			else if(!(novakomanda[i+2]>='0'&&novakomanda[i+2]<='9')||!(novakomanda[i+3]>='0'&&novakomanda[i+3]<='9')){
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			else{
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
		}
		else if(novakomanda[i]=='B'){
			komanda=Komande::Blokiraj;
			if(novakomanda[i+1]>='0' && novakomanda[i+1]<='9' && novakomanda[i+2]>='0' && novakomanda[i+2]<='9'){
				x=novakomanda[i+1];
				y=novakomanda[i+2];
				return true;
			}
			else if(!(novakomanda[i+1]>='0'&&novakomanda[i+1]<='9')||!(novakomanda[i+2]>='0'&&novakomanda[i+2]<='9')){
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			else{
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
		}
		else if(novakomanda[i]=='D'){
			komanda=Komande::Deblokiraj;
			if(novakomanda[i+1]>='0' && novakomanda[i+1]<='9' && novakomanda[i+2]>='0'&&novakomanda[i+2]<='9'){
				x=novakomanda[i+1];
				y=novakomanda[i+2];
				return true;
			}
			else if(!(novakomanda[i+1]>='0'&&novakomanda[i+1]<='9')||!(novakomanda[i+2]>='0'&&novakomanda[i+2]<='9')){
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			else{
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
		}
		if(novakomanda[i]=='P'&&novakomanda[i+1]=='O'){
			komanda=Komande::PrikaziOkolinu;
			if((novakomanda[i+2]>='A'&&novakomanda[i+2]<='Z')||(novakomanda[i+2]>='0'&&novakomanda[i+2]<='9')){
				greska=KodoviGresaka::SuvisanParametar;
			}
		}
		if(novakomanda[i]=='Z'){
			komanda=Komande::ZavrsiIgru;
			if(novakomanda[i+1]=='\0'){
				return true;
			}
			else if((novakomanda[i+1]>='A'&&novakomanda[i+1]<='Z')||(novakomanda[i+1]>='0'&&novakomanda[i+1]<='9')){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
		}
		if(novakomanda[i]=='K'){
			komanda=Komande::KreirajIgru;
			if(novakomanda[i+1]=='\0'){
				return true;
			}
			else if((novakomanda[i+1]>='A'&&novakomanda[i+1]<='Z')||(novakomanda[i+1]>='0'&&novakomanda[i+1]<='9')){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
		}
	}
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0) {
	
	if(komanda==Komande::PomjeriJednoMjesto || komanda==Komande::PomjeriDalje) {
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")";
		Status status=Idi(polja, x,y,p_smjer);
		if(status==Status::KrajPobjeda) std::cout<<"Bravo, obisli ste sva sigurna polja";
		
		if(status==Status::KrajPoraz){ 
			std::cout<<"Nagazili ste na minu";
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[i].size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
	    }
    }
    else if(komanda==Komande::PrikaziOkolinu){
    	Matrica P= PrikaziOkolinu(polja,x,y);
    	for(int i=0; i<P.size(); i++){
    		for(int j=0; j<P[i].size(); j++){
    			std::cout<<P[i][j];
    		}
    		std::cout<<std::endl;
    	}
    }
    else if(komanda==Komande::ZavrsiIgru){
    	for(int i=0; i<polja.size(); i++){
    		for(int j=0; j<polja[i].size(); j++){
    			polja[i][j]=Polje::Prazno;
    		}
    	}
    	throw std::runtime_error ("Igra zavrsena");
    }
    else if(komanda==Komande::KreirajIgru){
    	std::complex<int> z;
    	std::vector<std::complex<int>> v;
    	int n;
    	std::cout<<"Unesite broj polja: "<<std::endl;
    	std::cin>>n;
    	std::cout<<"Unesite pozicije mina: "<<std::endl;
    	while(std::cin.peek()!='.'){
    		std::cin>>z;
    		if(z.real()>n || z.imag()>n){
    			std::cout<<"Greska, unesite ponovo!";
    		}
    	}
    	
    
    }


}



int main ()
{
	return 0;
}