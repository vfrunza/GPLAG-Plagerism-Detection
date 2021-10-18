#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
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
typedef std::vector<std::vector<int>> Matrica;
bool provjera(std::string s){
    bool dobroje=false,prva=false,druga=false,treca=false,cetvrta=false,peta=false,bila=false;
            for(int i=0;i<s.size();i++){
                char znak=s[i];
            if(s[i]==' '||s[i]=='('||s[i]==')'||s[i]==','||(s[i]>='0'&&s[i]<='9')) dobroje=true;
            else{
                dobroje=false;
                break;
            }
            if(s[i]=='(') prva=true;
            if(s[i]>='0'&&s[i]<='9'){
                if(!prva){dobroje=false;
                 break;}
                 druga=true;
            }
            if(s[i]==','){
                bila=true;
                if(!prva||!druga){
                    dobroje=false;
                    break;
                }
                treca=true;
                i++;
            }
           if(s[i]>='0'&&s[i]<='9'&&bila){
                if(!prva||!druga||!treca){dobroje=false;
                 break;}
                 cetvrta=true;
            }
            if(s[i]==')'){
                if(!prva||!druga||!treca||!cetvrta){
                    dobroje=false;
                    break;
                }
                peta=true;
                i++;
                while(i!=s.size()){
                	if(s[i]!=' ') dobroje=false;
                	i++;
                	
                }
            }
            }
            if(!prva||!druga||!treca||!cetvrta||!peta) dobroje=false;
            return dobroje;
}

Tabla KreirajIgru(int n, std::vector<std::vector<int>> &mine){
    for(int i=0;i<mine.size();i++) if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	Tabla m(n,std::vector<Polje>(n,Polje::Prazno));
	for (int i=0;i<mine.size();i++){
	    if(mine[i][0]<0||mine[i][1]<0||mine[i][0]>=n||mine[i][1]>=n) throw std::domain_error("Ilegalne pozicije mina");
	    m[mine[i][0]][mine[i][1]]=Polje::Mina;
	}
	return m;
}
int brojac(Tabla &polja,int x, int y){
     int broj{0};
     for(int i=-1;i<=1;i++){
     	if(x+i>=0&&x+i<polja.size()){
     		for(int j=-1;j<=1;j++){
     			if(i==0&&j==0) continue;
     			else {if(y+j>=0&&y+j<polja[i+1].size()) if(polja[x+i][y+j]==Polje::Mina) broj++;}
     		}
     	}
     }
     return broj;
}
Matrica PrikaziOkolinu(Tabla &polja, int x, int y){
    Matrica m(3,std::vector<int>(3,0));
    if(x<0||y<0||x>=polja.size()||y>=polja.size()) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
    for(int i=-1;i<=1;i++){
     	if(x+i>=0&&x+i<polja.size()){
     		for(int j=-1;j<=1;j++){
     			if(y+j>=0&&y+j<polja[i+1].size()) m[i+1][j+1] = brojac(polja,x+i,y+j);
     		}
     	}
     }
     return m;
}
void BlokirajPolje(Tabla &polja, int x, int y){
	if(x<0||x>=polja.size()||y<0||y>=polja.size()) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
	if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
}
void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x<0||x>=polja.size()||y<0||y>=polja.size()) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
	if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){         //GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
    int x1=x,y1=y;
	if(smjer==Smjerovi::GoreLijevo){
		if(x-1<0||y-1<0) throw std::out_of_range("Izlazak van igrace table");
		x1-=1;y1-=1;
	}
	if(smjer==Smjerovi::Gore){
		if(x-1<0) throw std::out_of_range("Izlazak van igrace table");
		x1-=1;
	}
	if(smjer==Smjerovi::GoreDesno){
		if(x-1<0||y+1>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
		x1-=1;y+=1;
	}
	if(smjer==Smjerovi::Desno){
		if(y+1>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
		y1+=1;
	}
	if(smjer==Smjerovi::DoljeDesno){
		if(x+1>=polja.size()||y+1>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
		y1+=1;x1+=1;
	}
	if(smjer==Smjerovi::Dolje){
		if(x+1>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
		x1+=1;
	}
	if(smjer==Smjerovi::DoljeLijevo){
		if(x+1>=polja.size()||y-1<0) throw std::out_of_range("Izlazak van igrace table");
		x1+=1;y1-=1;
	}	
	if(smjer==Smjerovi::Lijevo){
		if(x-1<0) throw std::out_of_range("Izlazak van igrace table");
		y1-=1;
	}
	if(polja[x1][y1]==Polje::BlokiranoPosjeceno||polja[x1][y1]==Polje::BlokiranoPrazno||polja[x1][y1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x=x1;y=y1;
	
	if(polja[x][y]==Polje::Mina){
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++) polja[i][j]=Polje::Prazno;
		}
		return Status::KrajPoraz;
	} 
	if(polja[x][y]==Polje::Posjeceno||polja[x][y]==Polje::Prazno){
		bool kraj{true};
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++){
				if(i==x&&j==y) continue;
				else{
				if(polja[i][j]==Polje::Prazno){ 
					kraj=false; 
				    break;
			   }
				}
			}
		}
		if(kraj) return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x<0||novi_x>=polja.size()||novi_y<0||novi_y>=polja.size())throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno||polja[novi_x][novi_y]==Polje::BlokiranoPrazno||polja[novi_x][novi_y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	x=novi_x;y=novi_y;
	if(polja[x][y]==Polje::Mina){
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++) polja[i][j]=Polje::Prazno;
		}
		return Status::KrajPoraz;
	}
	if(polja[x][y]==Polje::Posjeceno||polja[x][y]==Polje::Prazno){
		bool kraj{true};
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++){
				if(i==x&&j==y) continue;
				else {if(polja[i][j]==Polje::Prazno){ 
					kraj=false; 
				    break;
			   }
				}
			}
		};
		if(kraj) return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}
void PrijaviGresku(KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	if(greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	if(greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	if(greska==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska){
    char znak;
  
    std::cin>>znak;

    if(znak!='P'&&znak!='B'&&znak!='D'&&znak!='Z'&&znak!='K'){
    	greska=KodoviGresaka::PogresnaKomanda;
    	std::cin.ignore(1000,'\n');
    	return false;
    }
    if(znak=='P'){
    	if(std::cin.peek()=='\n'){
    		greska=KodoviGresaka::NedostajeParametar; return false; std::cin.ignore(1000,'\n');
    	}
    	znak=char(std::cin.get());
        if(znak!='1'&&znak!='>'&&znak!='O'){
        	std::cin.ignore(1000,'\n');
             greska=KodoviGresaka::PogresnaKomanda;
             return false;
        }        
        if(znak=='O'){
        	while(std::cin.peek()==' ') znak=char(std::cin.get());
        	if(std::cin.peek()!='\n'){
        		std::cin.ignore(1000,'\n');
        		greska=KodoviGresaka::SuvisanParametar;
        		return false;
        	}
        	komanda=Komande::PrikaziOkolinu;std::cin.ignore(1000,'\n');
        	
        	return true;
        }
    	if(znak=='1'){
    		if(std::cin.peek()=='\n'){
    			std::cin.ignore(1000,'\n');
    		greska=KodoviGresaka::NedostajeParametar; return false;
         	}
         	while(std::cin.peek()==' ') znak=std::cin.get();
         	znak=char(std::cin.get());
    		                   // “GL”, “G”, “GD”, “D”, “DoD”, “Do”, “DoL” ili “L”, 
    		if(znak=='\n'){
    			std::cin.ignore(1000,'\n');
    		greska=KodoviGresaka::NedostajeParametar; return false;
         	}
         	if(znak!='G'&&znak!='D'&&znak!='L'){
         		greska=KodoviGresaka::NeispravanParametar;
         		std::cin.ignore(1000,'\n');
         		return false;
         	}
    		if(znak=='G'&&(std::cin.peek()=='\n'||std::cin.peek()==' ')){
    			while(std::cin.peek()==' ') znak=char(std::cin.get());
    			if(std::cin.peek()!='\n'){
    				std::cin.ignore(1000,'\n');
    				greska=KodoviGresaka::SuvisanParametar;
    				return false;
    			}
    			smjer=Smjerovi::Gore;
    			komanda=Komande::PomjeriJednoMjesto;std::cin.ignore(1000,'\n');
    			return true;
    		}
    		if(znak=='D'&&(std::cin.peek()==' '||std::cin.peek()=='\n')){
    			while(std::cin.peek()==' ') znak=char(std::cin.get());
    			if(std::cin.peek()!='\n'){
    				std::cin.ignore(1000,'\n');
    				greska=KodoviGresaka::SuvisanParametar;
    				return false;
    			}
    			smjer=Smjerovi::Desno;
    			komanda=Komande::PomjeriJednoMjesto; std::cin.ignore(1000,'\n');
    			return true;
    		} 
    		if(znak=='L'){
    			while(std::cin.peek()==' ') znak=char(std::cin.get());
    			if(std::cin.peek()!='\n'){
    				std::cin.ignore(1000,'\n');
    				greska=KodoviGresaka::SuvisanParametar;
    				return false;
    			}
    			smjer=Smjerovi::Lijevo;
    			komanda=Komande::PomjeriJednoMjesto;std::cin.ignore(1000,'\n');
    			return true;
    		}
    		if(znak=='G'){
    			znak=std::cin.get();
    		        if(znak!='L'&&znak!='D'){
    					std::cin.ignore(1000,'\n');
    					greska=KodoviGresaka::NeispravanParametar;
    					return false;
    				}		
    			if(znak=='L'){
    			while(std::cin.peek()==' ') znak=char(std::cin.get());
    			if(std::cin.peek()!='\n'){
    				std::cin.ignore(1000,'\n');
    				greska=KodoviGresaka::SuvisanParametar;
    				return false;
    			}
    			  smjer=Smjerovi::GoreLijevo;
    			  komanda=Komande::PomjeriJednoMjesto; std::cin.ignore(1000,'\n');
    			  return true;
    			}
    			if(znak=='D'){
    			while(std::cin.peek()==' ') znak=char(std::cin.get());
    			if(std::cin.peek()!='\n'){
    				std::cin.ignore(1000,'\n');
    				greska=KodoviGresaka::SuvisanParametar;
    				return false;
    			}
    			smjer=Smjerovi::GoreDesno;
    			komanda=Komande::PomjeriJednoMjesto; std::cin.ignore(1000,'\n');
    			return true;
    			}
    		}
    		if(znak=='D'){
    			if(std::cin.peek()!='o'){
    				std::cin.ignore(1000,'\n');
    				greska=KodoviGresaka::NeispravanParametar;
    				return false;
    			}
    			znak=std::cin.get();
    			if(znak=='o'&&(std::cin.peek()=='\n'||std::cin.peek()==' ')){
    				while(std::cin.peek()==' ') znak=char(std::cin.get());
    				if(std::cin.peek()!='\n'){
    					std::cin.ignore(1000,'\n');
    				greska=KodoviGresaka::SuvisanParametar;
    				return false;
    			    }
    			    smjer=Smjerovi::Dolje;
    			    komanda=Komande::PomjeriJednoMjesto;
    			    return true;
    			} 
    			if(znak=='o'){
    				znak=char(std::cin.get());
    				if(znak!='L'&&znak!='D'){
    					std::cin.ignore(1000,'\n');
    					greska=KodoviGresaka::NeispravanParametar;
    					return false;
    				}
    				if(znak=='L'){
    					while(std::cin.peek()==' ') znak=char(std::cin.get());
    					if(std::cin.peek()!='\n'){
    						std::cin.ignore(1000,'\n');
    				    greska=KodoviGresaka::SuvisanParametar;
    				    return false;
    			        }
    			        
    			        smjer=Smjerovi::DoljeLijevo;
    			        komanda=Komande::PomjeriJednoMjesto;
    			        return true;
    				}
    				if(znak=='D'){
    					while(std::cin.peek()==' ') znak=char(std::cin.get());
    					if(std::cin.peek()!='\n'){
    						std::cin.ignore(1000,'\n');
    				    greska=KodoviGresaka::SuvisanParametar;
    				    return false;
    			        }
    			        smjer=Smjerovi::DoljeDesno;
    			        komanda=Komande::PomjeriJednoMjesto;
    			        return true;
    				}
    				
    			}
    		}
    	}
    	if(znak=='>'){
    		if(std::cin.peek()=='\n'){
    			std::cin.ignore(1000,'\n');
    			greska=KodoviGresaka::NedostajeParametar; return false;
    		}
    		while(std::cin.peek()==' ') znak=char(std::cin.get());
    		
    		int broj1,broj2;
    		if(std::cin.peek()!='1'&&std::cin.peek()!='2'&&std::cin.peek()!='3'&&std::cin.peek()!='4'&&std::cin.peek()!='5'&&std::cin.peek()!='6'&&std::cin.peek()!='7'&&std::cin.peek()!='8'&&std::cin.peek()!='9'){
    			std::cin.ignore(1000,'\n');
    			greska=KodoviGresaka::NeispravanParametar;
    			return false;
    		}
    		if(!(std::cin>>broj1)){
    			std::cin.ignore(1000,'\n');
    			greska=KodoviGresaka::NeispravanParametar;
    			return false;
    		}
    		while(std::cin.peek()==' ') znak=std::cin.get();
    		if(!(std::cin>>broj2)){
    			std::cin.ignore(1000,'\n');
    			greska=KodoviGresaka::NeispravanParametar;return false;
    		}
    		while(std::cin.peek()==' ') znak=std::cin.get();
    		if(std::cin.peek()!='\n'){
    			std::cin.ignore(1000,'\n');
    			greska=KodoviGresaka::SuvisanParametar;return false;
    		}
    		komanda=Komande::PomjeriDalje;
    		x=broj1;y=broj2;
    		return true;
    	}
    }
	if(znak=='B'){
    		if(std::cin.peek()=='\n'){
    			std::cin.ignore(1000,'\n');
    			greska=KodoviGresaka::NedostajeParametar; return false;
    		}
    		while(std::cin.peek()==' ') znak=char(std::cin.get());
    		int broj1,broj2;
    		if(!(std::cin>>broj1)){
    			std::cin.ignore(1000,'\n');
    			greska=KodoviGresaka::NeispravanParametar;
    			return false;
    		}
    		while(std::cin.peek()==' ') znak=char(std::cin.get());
    		if(!(std::cin>>broj2)){
    			std::cin.ignore(1000,'\n');
    			greska=KodoviGresaka::NeispravanParametar;return false;
    		}
    		while(std::cin.peek()==' ') znak=char(std::cin.get());
    		if(std::cin.peek()!='\n'){
    			std::cin.ignore(1000,'\n');
    			greska=KodoviGresaka::SuvisanParametar;return false;
    		}
    		komanda=Komande::Blokiraj;
    		x=broj1;y=broj2;
    		return true;
    	} 
    if(znak=='D'){
    		if(std::cin.peek()=='\n'){
    			std::cin.ignore(1000,'\n');
    			greska=KodoviGresaka::NedostajeParametar; return false;
    		}
    		while(std::cin.peek()==' ') znak=char(std::cin.get());
    		int broj1,broj2;
    		if(!(std::cin>>broj1)){
    			std::cin.ignore(1000,'\n');
    			greska=KodoviGresaka::NeispravanParametar;
    			return false;
    		}
    		while(std::cin.peek()==' ') znak=char(std::cin.get());
    		if(!(std::cin>>broj2)){
    			std::cin.ignore(1000,'\n');
    			greska=KodoviGresaka::NeispravanParametar;return false;
    		}
    		while(std::cin.peek()==' ') znak=char(std::cin.get());
    		if(std::cin.peek()!='\n'){
    			std::cin.ignore(1000,'\n');
    			greska=KodoviGresaka::SuvisanParametar;return false;
    		}
    		komanda=Komande::Deblokiraj;
    		x=broj1;y=broj2;
    		return true;
    	}
    if(znak=='Z'){
    	while(std::cin.peek()==' ') znak=char(std::cin.get());
    	if(std::cin.peek()!='\n'){
    		std::cin.ignore(1000,'\n');
    		greska=KodoviGresaka::SuvisanParametar;
    		return false;
    	}
    	komanda=Komande::ZavrsiIgru;
    	return true;
    }
    if(znak=='K'){
    	while(std::cin.peek()==' ') znak=char(std::cin.get());
    	if(std::cin.peek()!='\n'){
    		std::cin.ignore(1000,'\n');
    		greska=KodoviGresaka::SuvisanParametar;
    		return false;
    	}
    	komanda=Komande::KreirajIgru; std::cin.ignore(1000,'\n');
    	return true; 
    }
    return false;
 }
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
 	// PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
 	if(komanda==Komande::PomjeriJednoMjesto){
 		Status s=Idi(polja,x,y,p_smjer);
 		if(s==Status::KrajPoraz){
 				komanda=Komande::ZavrsiIgru;
 			std::cout<<"Nagazili ste na minu"<<std::endl;
 			
 		}
 		if(s==Status::KrajPobjeda){
 				komanda=Komande::ZavrsiIgru;
 			std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
 		}
 		if(s==Status::NijeKraj){
 			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
 		}
 	}
 	if(komanda==Komande::PomjeriDalje){
 		Status f=Idi(polja,x,y,p_x,p_y);
 		if(f==Status::KrajPoraz){
 			std::cout<<"Nagazili ste na minu"<<std::endl;
            	komanda=Komande::ZavrsiIgru;
 		}
 		if(f==Status::KrajPobjeda){
 			komanda=Komande::ZavrsiIgru;
 			std::cout<<"Bravo, obisli ste sva sigurna polja";

 		}
 		if(f==Status::NijeKraj){
 			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
 		}
 	}
 	if(komanda==Komande::Blokiraj){
 		BlokirajPolje(polja,p_x,p_y);
 	}
 	if(komanda==Komande::Deblokiraj){
 		DeblokirajPolje(polja,p_x,p_y);
 	}
 	if(komanda==Komande::PrikaziOkolinu){
 		auto m=PrikaziOkolinu(polja,x,y);
 		for(int i=0;i<m.size();i++){
 			for(int j=0;j<m[i].size();j++) std::cout<<m[i][j]<<" ";
 			std::cout<<std::endl;
 		}
 	}
 	if(komanda==Komande::ZavrsiIgru){
 		for(int i=0;i<polja.size();i++){
 			for(int j=0;j<polja[i].size();j++) polja[i][j]=Polje::Prazno;
 		}
 		throw std::runtime_error("Dovidjenja!");
 	}
 	if(komanda==Komande::KreirajIgru){
 		int n;
 		std::cout<<"Unesite broj polja: ";
 		std::cin>>n;
 		std::cin.ignore(100,'\n');
 		std::vector<std::vector<int>> mine;

 		int zlj=0;
 		std::cout<<"Unesite pozicije mina: ";
 		while(1){
 	         std::string s;
 	         std::getline(std::cin,s);
 	         bool tacka=false;
 	         for(int i=0;i<s.size();i++){
 	         	if(s[i]=='.') tacka=true;
 	         	if(s[i]!=' '&&s[i]!='.'){
 	         		tacka=false;
 	         		break;
 	         	}
 	         }
 	         if(tacka) break;
 	         bool belaj=provjera(s);
 	         if(!belaj){
 	         	std::cout<<"Greska, unesite ponovo!"<<std::endl;
 	         }
 	         else{
 	         	int broj1=0,broj2=0;
 	         	for(int i=0;i<s.size();i++){
 	         		while(s[i]==' ') i++;
 	         		if(s[i]=='('){
 	         			i++;
 	         			while(s[i]==' ') i++;
 	         			while(s[i]>='0'&&s[i]<='9'){broj1=broj1*10+(s[i]-'0');
 	         			i++;}
 	         		}
 	         		if(s[i]==','){
 	         			i++;
 	         			while(s[i]>='0'&&s[i]<='9'){broj2=broj2*10+(s[i]-'0');
 	         			i++;}
 	         			break;
 	         		}
 	         	}
 	         	if(broj1>=n||broj2>=n){
 	         		std::cout<<"Greska, unesite ponovo!"<<std::endl;
 	         	}
 	         	else{
 	         	mine.push_back(std::vector<int>());
 	         	mine[zlj].push_back(broj1);
 	         	mine[zlj].push_back(broj2);
 	         	zlj++;
 	         	}
 	         }
 		}
 		polja=KreirajIgru(n,mine);
 		
 		
 	}
 	
 	
 	
 }
 
int main ()
{
	Tabla f;
	int x,y,x1=0,y1=0;
	Smjerovi smjer;
	KodoviGresaka greska;
	Komande k;
	while(1){
		std::cout<<"Unesite komandu: ";
		bool unos=UnosKomande(k,smjer,x,y,greska);
		if(unos){
			try{
		IzvrsiKomandu(k,f,x1,y1,smjer,x,y);
			}
			catch(std::runtime_error iz){
				std::cout<<iz.what()<<std::endl;
				return 0;
			}
            catch(std::domain_error izi){
				std::cout<<izi.what()<<std::endl;
			}	
	        catch(std::out_of_range izu){
				std::cout<<izu.what()<<std::endl;
			}
			catch(std::logic_error e){
				std::cout<<e.what()<<std::endl;
			}
		}
		else{
			PrijaviGresku(greska);
		}
		if(k==Komande::ZavrsiIgru) break;
		
	}
	return 0;
}  

