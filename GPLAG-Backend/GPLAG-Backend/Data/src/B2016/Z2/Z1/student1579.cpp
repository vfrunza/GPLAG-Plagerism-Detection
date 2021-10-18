/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include<iostream>
#include<vector>
#include<stdexcept>
#include<string>
#include<cmath>
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
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,ZavrsiIgru, KreirajIgru
};
typedef std::vector<std::vector<Polje>> Tabla;
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	for(int i=0;i<mine.size();i++){
		if(mine[i].size()!=2){
			throw std::domain_error("Ilegalan format zadavanja mina");
		}
		for(int j=0;j<mine[i].size();j++){
			if(mine[i][j]>=n) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	Tabla m;
	m.resize(n);
	for(int i=0;i<n;i++)
		m[i].resize(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			m[i][j]=Polje(0);
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<mine.size();k++)
				if(i==mine[k][0] && j==mine[k][1])
					m[i][j]=Polje(2);
	return m;
}
int okol(Tabla polja,int x,int y){
	int br=0;
	if(x==0 && y==0){
		if(polja[0][1]==Polje(2)) br++;
		if(polja[1][1]==Polje(2)) br++;
		if(polja[1][0]==Polje(2)) br++;
	}
	else if(x==polja.size()-1 && y==0){
		if(polja[polja.size()-2][0]==Polje(2)) br++;
		if(polja[polja.size()-2][1]==Polje(2)) br++;
		if(polja[polja.size()-1][1]==Polje(2)) br++;
	}
	else if(y==0 && x!=0 && x!=polja.size()-1){
		if(polja[x-1][y]==Polje(2)) br++;
		if(polja[x-1][y+1]==Polje(2)) br++;
		if(polja[x][y+1]==Polje(2)) br++;
		if(polja[x+1][y]==Polje(2)) br++;
		if(polja[x+1][y+1]==Polje(2)) br++;
	}
	else if(y==polja[0].size()-1 && x==0){
		if(polja[0][polja[0].size()-2]==Polje(2)) br++;
		if(polja[1][polja[0].size()-1]==Polje(2)) br++;
		if(polja[1][polja[0].size()-2]==Polje(2)) br++;
	}
	else if(y==polja[0].size()-1 && x==polja.size()-1){
		if(polja[polja.size()-1][polja[0].size()-2]==Polje(2)) br++;
		if(polja[polja.size()-2][polja[0].size()-1]==Polje(2)) br++;
		if(polja[polja.size()-2][polja[0].size()-2]==Polje(2)) br++;
		
	}
	else if(y==int(polja[0].size()-1) && x!=0 && x!=polja.size()-1){
		if(polja[x-1][y]==Polje(2)) br++;
		if(polja[x-1][y-1]==Polje(2)) br++;
		if(polja[x][y-1]==Polje(2)) br++;
		if(polja[x+1][y]==Polje(2)) br++;
		if(polja[x+1][y-1]==Polje(2)) br++;
	}
	else if(y!=polja[0].size()-1 && x==0 && y!=0){
		if(polja[x][y-1]==Polje(2)) br++;
		if(polja[x][y+1]==Polje(2)) br++;
		if(polja[x+1][y-1]==Polje(2)) br++;
		if(polja[x+1][y]==Polje(2)) br++;
		if(polja[x+1][y+1]==Polje(2)) br++;
	}
	else if(x==polja.size()-1 && y!=polja[0].size()-1 && y!=0){
		if(polja[x][y-1]==Polje(2)) br++;
		if(polja[x][y+1]==Polje(2)) br++;
		if(polja[x-1][y-1]==Polje(2)) br++;
		if(polja[x-1][y]==Polje(2)) br++;
		if(polja[x-1][y+1]==Polje(2)) br++;
	}
	else{
		if(polja[x-1][y-1]==Polje(2)) br++;
		if(polja[x-1][y]==Polje(2)) br++;
		if(polja[x-1][y+1]==Polje(2)) br++;
		if(polja[x][y-1]==Polje(2)) br++;
		if(polja[x][y+1]==Polje(2)) br++;
		if(polja[x+1][y+1]==Polje(2)) br++;
		if(polja[x+1][y]==Polje(2)) br++;
		if(polja[x+1][y-1]==Polje(2)) br++;
	}
	return br;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	if(x<=0 || y<=0 || x>=(polja.size()-1) || y>=(polja[0].size()-1)){
		
		throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	}
	std::vector<std::vector<int>> mat;
	mat.resize(3);
	for(int i=0;i<3;i++)
		mat[i].resize(3);
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja[i].size();j++){
			if(i==x && j==y){
				mat[0][0]=okol(polja,x-1,y-1);
				mat[0][1]=okol(polja,x-1,y);
				mat[0][2]=okol(polja,x-1,y+1);
				mat[1][0]=okol(polja,x,y-1);
				mat[1][1]=okol(polja,x,y);
				mat[1][2]=okol(polja,x,y+1);
				mat[2][0]=okol(polja,x+1,y-1);
				mat[2][1]=okol(polja,x+1,y);
				mat[2][2]=okol(polja,x+1,y+1);
			}
		}
	}
	return mat;
}
void BlokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || y<0 || x>(polja.size()-1) || y>(polja[0].size()-1)){
		throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	}
	if(polja[x][y]==Polje(0)) polja[x][y]=Polje(3);
	if(polja[x][y]==Polje(1)) polja[x][y]=Polje(4);
	if(polja[x][y]==Polje(2)) polja[x][y]=Polje(5);
}
void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || y<0 || x>(polja.size()-1) || y>(polja[0].size()-1)){
		throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	}
	if(polja[x][y]==Polje(3)) polja[x][y]=Polje(0);
	if(polja[x][y]==Polje(4)) polja[x][y]=Polje(1);
	if(polja[x][y]==Polje(5)) polja[x][y]=Polje(2);
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	if((x==0 && (smjer==Smjerovi(1) || smjer==Smjerovi(0) || smjer==Smjerovi(2)))||(x==polja.size()-1 &&(smjer==Smjerovi(5)|| smjer==Smjerovi(4) || smjer==Smjerovi(6))) || (y==polja[0].size()-1 && (smjer==Smjerovi(2)|| smjer==Smjerovi(3) || smjer==Smjerovi(4))) ||(y==0 && (smjer==Smjerovi(0)|| smjer==Smjerovi(6) || smjer==Smjerovi(7)))){
		throw std::out_of_range("Izlazak van igrace table");
	}
	polja[x][y]=Polje(1);
	if(smjer==Smjerovi(1)){
		if(polja[x-1][y]==Polje(3) || polja[x-1][y]==Polje(4) ||polja[x-1][y]==Polje(5)){
		throw std::logic_error("Blokirano polje");
		}
	x--;
	}
	if(smjer==Smjerovi(0)){
		if(polja[x-1][y-1]==Polje(3) || polja[x-1][y-1]==Polje(4) ||polja[x-1][y-1]==Polje(5)){
		throw std::logic_error("Blokirano polje");
	}
	x--; y--;}
	if(smjer==Smjerovi(2)){
		if(polja[x-1][y+1]==Polje(3) || polja[x-1][y+1]==Polje(4) ||polja[x-1][y+1]==Polje(5)){
		throw std::logic_error("Blokirano polje");
	}x--; y++;}
	if(smjer==Smjerovi(3)){
		if(polja[x][y+1]==Polje(3) || polja[x][y+1]==Polje(4) ||polja[x][y+1]==Polje(5)){
		throw std::logic_error("Blokirano polje");
	}y++;}
	if(smjer==Smjerovi(4)){
		if(polja[x+1][y+1]==Polje(3) || polja[x+1][y+1]==Polje(4) ||polja[x+1][y+1]==Polje(5)){
		throw std::logic_error("Blokirano polje");
	}x++; y++;}
	if(smjer==Smjerovi(6)){
		if(polja[x+1][y-1]==Polje(3) || polja[x+1][y-1]==Polje(4) ||polja[x+1][y-1]==Polje(5)){
		throw std::logic_error("Blokirano polje");
	}x++; y--;}
	if(smjer==Smjerovi(5)){
		if(polja[x+1][y]==Polje(3) || polja[x+1][y]==Polje(4) ||polja[x+1][y]==Polje(5)){
		throw std::logic_error("Blokirano polje");
	}x++;}
	if(smjer==Smjerovi(7)){
		if(polja[x][y-1]==Polje(3) || polja[x][y-1]==Polje(4) ||polja[x][y-1]==Polje(5)){
		throw std::logic_error("Blokirano polje");
	}y--;}
	if(polja[x][y]==Polje(2)) {
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++){
				polja[i][j]=Polje(0);
			}
		}
		return Status(1);
	}
	
//	std::cout<<"P1 POSLJE::"<<x<<","<<y<<")"<<std::endl;
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja[i].size();j++){
			if(polja[i][j]==Polje(0)){
				return Status(0);
			}
		}
	}
	return Status(2);
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x<0 || novi_y<0 || novi_x>=polja.size() || novi_y>=polja[0].size()){
			throw std::out_of_range("Izlazak van igrace table");
	}
	bool tr=true;
	if(polja[novi_x][novi_y]==Polje(3)) {
		std::cout << "Blokirano polje" << std::endl;
		tr=false;
	}
	if(polja[novi_x][novi_y]==Polje(4)) {
		std::cout << "Blokirano polje" << std::endl;
		tr=false;
	}
	if(polja[novi_x][novi_y]==Polje(5)) {
		std::cout << "Blokirano polje" << std::endl;
		tr=false;
	}
	if(tr){
	x=novi_x;
	y=novi_y;
	
	if(polja[x][y]==Polje(2)) {
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++){
				polja[i][j]=Polje(0);
			}
		}
		return Status(1);
	}
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja[i].size();j++){
			if(polja[i][j]==Polje(0)){
				return Status(0);
			}
		}
	}
	return Status(2);
	}
	return Status(0);
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string kom;
	std::getline(std::cin,kom);
	
	for(int i=0;i<kom.length();i++){
		if(kom[i]=='Z'){
			i++;
			while(kom[i]==' '){
				i++;
			}
			if(i!=kom.length() && kom[i]!='\0') return false;
			komanda=Komande(5); 
			return true;
		}
		if(kom[i]=='K'){
			i++;
			while(kom[i]==' '){
				i++;
			}
			if(i!=kom.length() && kom[i]!='\0'){greska=KodoviGresaka(2); return false;}
			komanda=Komande(6); 
			return true;
		}
		if(kom[i]=='P'){
			i++;
			if(kom[i]=='1' && kom[i-1]=='P'){
				i++;
				while(kom[i]==' ') i++;
				if(kom[i]=='\0'){greska=KodoviGresaka(1); return false;}
			//	std::cout << "USAO U P1   " <<kom[i] <<std::endl;
				if(kom[i]=='G' || kom[i]=='D' || kom[i]=='L'){
					int poz=i;
					i++;
				//	std::cout<<poz<<"lol"<<"*******";
					while((kom[i]>='a' && kom[i]<='z')|| (kom[i]>='A' && kom[i]<='Z')) {
						i++;
					}
					std::string kom1;
					while(poz!=i){
						kom1.push_back(kom[poz]);
						poz++;
					}
					if(i!=kom.length()){
					//	std::cout << "*******" << std::endl;
					i++;
					while(kom[i]==' '){ i++; }
					if(i!=kom.length() && kom[i]!='\0') {greska=KodoviGresaka(2); return false;}
					}
					if(kom1==std::string("GL")) smjer=Smjerovi(0);
					else if(kom1==std::string("G")) smjer=Smjerovi(1);
					else if(kom1==std::string("GD")) smjer=Smjerovi(2);
					else if(kom1==std::string("D")) smjer=Smjerovi(3);
					else if(kom1==std::string("DoD")) smjer=Smjerovi(4);
					else if(kom1==std::string("Do")) smjer=Smjerovi(5);
					else if(kom1==std::string("DoL")) smjer=Smjerovi(6);
					else if(kom1==std::string("L")) smjer=Smjerovi(7);
					else if(kom1.size()==0) greska=KodoviGresaka(1);
					else greska=KodoviGresaka(3);
					
				
					komanda=Komande(0);
					return true;
				}
				else{
				greska=KodoviGresaka(3);
				return false;
				}
			}
			if(kom[i]=='O' && kom[i-1]=='P'){
				i++;
				while(kom[i]==' '){
					i++;
				}
				if(i!=kom.length() && kom[i]!='\0') {greska=KodoviGresaka(2); return false;}
				
				komanda=Komande(4);
				return true;
			}
			if(kom[i]=='>' && kom[i-1]=='P'){
				i++;
				int px=0,py=0,br=0;
				while(kom[i]==' ')i++;
				if(kom[i]=='\0'){greska=KodoviGresaka(1); return false;}
				if(kom[i]<'0' || kom[i]>'9' ){greska=KodoviGresaka(3); return false;}
				while((kom[i]>='0' && kom[i]<='9') ){
					px=px*pow(10,br)+(kom[i]-'0');
				i++;
				}
				br=0;
				while(kom[i]==' ')i++;
				if(kom[i]<'0' || kom[i]>'9') {greska=KodoviGresaka(3); return false;}
				while((kom[i]>='0' && kom[i]<='9') ){
					py=py*pow(10,br)+(kom[i]-'0'); 
				//if(!(kom[i]>='0' && kom[i]<='9' ) || kom[i]!=' ')
				//	return false;
				if(i!=kom.size()){
				i++;
				}
				while(kom[i]!='\0'){
					if(kom[i]!=' ') {greska=KodoviGresaka(2); return false;}
					i++;
				}
				}
				x=px;
				y=py;
				
		//	std::cout << "USAO U P1   " <<x<<"     "<<y<< std::endl;
			komanda=Komande(1);
			return true;
			}
			else{
				greska=KodoviGresaka(0);
				return false;
			}
		}
		if(kom[i]=='B'){
			i++;
		
				int px=0,py=0,br=0;
				while(kom[i]==' ')i++;
				if(kom[i]=='\0'){greska=KodoviGresaka(1); return false;}
				if(kom[i]<'0' || kom[i]>'9'){greska=KodoviGresaka(3); return false;}
				while((kom[i]>='0' && kom[i]<='9') ){
					px=px*pow(10,br)+(kom[i]-'0');
				i++;
				}
				br=0;
				while(kom[i]==' ')i++;
				if(kom[i]<'0' || kom[i]>'9') {greska=KodoviGresaka(3); return false;}
				while((kom[i]>='0' && kom[i]<='9') ){
					py=py*pow(10,br)+(kom[i]-'0'); 
				//if(!(kom[i]>='0' && kom[i]<='9' ) || kom[i]!=' ')
				//	return false;
				if(i!=kom.size()){
				i++;
				}
				while(kom[i]!='\0'){
					if(kom[i]!=' ') {greska=KodoviGresaka(2); return false;}
					i++;
				}
				}
				x=px;
				y=py;
			
			komanda=Komande(2);
			return true;
			
		}
		if(kom[i]=='D'){
			i++;
				int px=0,py=0,br=0;
				while(kom[i]==' ')i++;
				if(kom[i]=='\0'){greska=KodoviGresaka(1); return false;}
				if(kom[i]<'0' || kom[i]>'9'){greska=KodoviGresaka(3); return false;}
				while((kom[i]>='0' && kom[i]<='9') ){
					px=px*pow(10,br)+(kom[i]-'0');
				i++;
				}
				br=0;
				while(kom[i]==' ')i++;
				if(kom[i]<'0' || kom[i]>'9') {greska=KodoviGresaka(3); return false;}
				while((kom[i]>='0' && kom[i]<='9') ){
					py=py*pow(10,br)+(kom[i]-'0'); 
				//if(!(kom[i]>='0' && kom[i]<='9' ) || kom[i]!=' ')
				//	return false;
				if(i!=kom.size()){
				i++;
				}
				while(kom[i]!='\0'){
					if(kom[i]!=' ') {greska=KodoviGresaka(2); return false;}
					i++;
				}
				}
				x=px;
				y=py;
				//std::cout <<"deblok:"<< x<<"     "<<y << std::endl;
			komanda=Komande(3);
			return true;
			
		}
		
	}
	greska=KodoviGresaka(0);
	return false;
	
}
std::vector<std::vector<int>> unosmina(int n){
	std::vector<std::vector<int>> rez;
	std::vector<std::string> vs;
	
	for(;;){
g3:	g2:g:g1:std::string pom;
		std::getline(std::cin,pom);
		bool dobro=false;
		if(pom==std::string(".")) break;
		for(int i=0;i<pom.length();i++){
			if(pom[i]=='('){
				i++;
				if(pom[i]>='0' && pom[i]<='9'){
					std::string sx;
					while(pom[i]!=','){
						if(!(pom[i]>='0' && pom[i]<='9')){
							std::cout << "Greska, unesite ponovo!" << std::endl;
							goto g2;
						}
						sx.push_back(pom[i]);
						i++;
					}
					int br=0;
					int x=0,y=0;
					for(int a=0;a<sx.length();a++){
						x=x*pow(10,br)+(sx[a]-'0');
						br++;
					}
					//std::cout<<x;
					if(x>=n){
						std::cout << "Greska, unesite ponovo!" << std::endl;
						goto g3;
					}
					i++;
					std::string ys;
					if(pom[i]>='0' && pom[i]<='9'){
						while(pom[i]!=')'){
						if(!(pom[i]>='0' && pom[i]<='9')){
							std::cout << "Greska, unesite ponovo!" << std::endl;
							goto g3;
						}
						ys.push_back(pom[i]);
						i++;
						}
						dobro=true;
					}
					else{
						std::cout << "Greska, unesite ponovo!" << std::endl;
						goto g1;
					}
					br=0;
					for(int a=0;a<ys.length();a++){
						y=y*pow(10,br)+(ys[a]-'0');
						br++;
					}
					if(y>=n){
						std::cout << "Greska, unesite ponovo!" << std::endl;
						goto g3;
					}
					
				}
				else{
					std::cout << "Greska, unesite ponovo!" << std::endl;
					goto g1;
				}
			}
			else{
				std::cout << "Greska, unesite ponovo!" << std::endl;
				goto g;
			}
			
		}
		if(dobro){
			vs.push_back(pom);
		}
	}
	rez.resize(vs.size());
	int a=0;
	for(int i=0;i<vs.size();i++){
		int x=0,y=0;
		std::string pom=vs[i];
		for(int j=0;j<pom.length();j++){
			int poc,kraj;
			if(pom[j]=='('){
				j++;
				poc=j;
				while(pom[j]!=',')j++;
				kraj=j;
				int br=0;
				for(int k=poc;k<kraj;k++){
					x=x*pow(10,br)+(pom[k]-'0');
					br++;
				}
				j++;
				poc=j;
				while(pom[j]!=')')j++;
				kraj=j;
				br=0;
				for(int k=poc;k<kraj;k++){
					y=y*pow(10,br)+(pom[k]-'0');
					br++;
				}
			}
			
		}
		rez[a].push_back(x);
		rez[a].push_back(y);
		a++;
	}
	return rez;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	if(komanda==Komande(6)){
		std::cout << "Unesite broj polja: ";
		int n;
		std::cin>>n;
		std::cout << "Unesite pozicije mina: ";
		std::vector<std::vector<int>> vmina=unosmina(n);
		polja=KreirajIgru(n,vmina);
	}
	if(komanda==Komande(5)){
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++){
				polja[i][j]=Polje(0);
			}
		}
		throw std::runtime_error("Igra zavrsena");
	}
	if(komanda==Komande(4)){
	//	std::cout<<"wtf"<<x<<"      "<<y<<")"<<std::endl;
		std::vector<std::vector<int>> okolina = PrikaziOkolinu(polja, x, y);
		for(int i = 0; i < okolina.size(); i++){
			 for(int j = 0; j < okolina[i].size(); j++) std::cout << okolina[i][j] << " ";
	  	std::cout << std::endl;
		}
	}
	if(komanda==Komande(2)){
		BlokirajPolje(polja,x,y);
	}
	if(komanda==Komande(3)){
		DeblokirajPolje(polja,x,y);
	}
	if(komanda==Komande(0)){
		
		Idi(polja,x,y,p_smjer);
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
		
	}
	if(komanda==Komande(1)){
		if(polja[x][y]!=Polje(3) && polja[x][y]!=Polje(4) && polja[x][y]!=Polje(5)){
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
		Idi(polja,x,y,p_x,p_y);
		}
		 else {
		 std::cout<<"Blokirano polje"<<std::endl;
		 }
	}
}
void PrijaviGresku(KodoviGresaka greska){
	if(greska==KodoviGresaka(0)){
		std::cout << "Nerazumljiva komanda!"<< std::endl;
	}
	if(greska==KodoviGresaka(1)){
		std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	}
	if(greska==KodoviGresaka(2)){
		std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
	}
	if(greska==KodoviGresaka(3)){
		std::cout << "Parametar komande nije ispravan!" << std::endl;
	}
}

int main ()
{
	
    try{
    Komande kom;
	int x=0,y=0,x1=0,y1=0;
	Smjerovi smjer;
	KodoviGresaka greska;
	Tabla polj;
	for(;;){
		std::cout << "Unesite komandu: " ;
		if(UnosKomande(kom,smjer,x,y,greska)){
			IzvrsiKomandu(kom,polj,x,y,smjer,x1,y1);
		//	PrijaviGresku(greska);
		}
	}
    }
    catch(std::runtime_error x){
    }
    std::cout<<"Dovidjenja!";

	return 0;
}

