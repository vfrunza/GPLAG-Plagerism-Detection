/*B 2017/2018, Zadaća 2, Zadatak 1 */
#include <iostream>
#include<vector> 
#include<stdexcept>

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina };
typedef std::vector<std::vector<Polje>> Tabla ;

//1 funkcija dobra 
Tabla KreirajIgru( int n, const std::vector<std::vector<int>> &mine ) {
               // sada trebam ovdje pobacati izuzetke  
	      if(n<=0) throw std::domain_error("Ilegalna velicina"); 
	  
	      bool a=true; 
	       for(int i=0; i<mine.size(); i++) {
	       	    if(mine[i].size()!=2) {
	             	a=false; 
	       	    	break; 
	       	    }
	        }
	        if(a==false) throw std::domain_error("Ilegalan format zadavanja mina");
	        
	        
	     for(int i =0; i<mine.size(); i++) {
	     	  for(int j=0; j<mine[0].size(); j++) {
	     	  	if(mine[i][j]>=n || mine[i][j]<0){
	     	  		 throw std::domain_error("Ilegalne pozicije mina");
	     	  }
	     }
	     
	     	
	     }
     
	  Tabla t(n, std::vector<Polje>(n, Polje::Prazno));
	  
	  for(int i=0; i<mine.size(); i++) {
	  	for(int j=0; j<mine[0].size()-1; j++){
	  	    	   t[mine[i][j]][mine[i][j+1]]=Polje::Mina; 
	  		
	  	}
	  }
	  
	  return t;
	  
	  
	 /* u ovoj funkciji sam kreirala igrau  tablu ,i t su sv polj igrace table ili Praza ili Mina, 
	  u zavisnosti sta mi je rekao drugi parametr funkcije, i n kraju vracam iz funkcije kreiranu tablu , 
	  koja se zove t, funkciju sam provjerla i radi dobro */

}

//2  funkcija je pravo dobra !
std::vector<std::vector<int>> PrikaziOkolinu( const Tabla &polja, int x, int y) {
	           std::vector<std::vector<int>> m(3, std::vector<int>(3));
	            if(x>= polja.size() || y>=polja[0].size())
	              throw std::domain_error("Polje (x,y) ne postoji");
	     
	              // ovdje naci granice 
	             int pocetak1=0; 
	             if(x==0 || x==1)       pocetak1=0; 
	             if(x>1)              pocetak1=x-1;
	             
	              int broj_redova=0;  
	              if(x==polja.size()-1) 	broj_redova=x;
	              if(x<polja.size()-1)     	broj_redova=x+1;
	       
	              int broj_kolona=0; 
	            int pocetak2=0; 
	              if(y==0 || y==1)  	pocetak2=0;
	              if( y>1)              pocetak2=y-1;
	              
	              
	              if(y==polja[0].size()-1)  	broj_kolona=y; 
	              if(y<polja[0].size()-1)    	broj_kolona=y+1; 
	            
	   
	              	           
	              	           int i=0; 
	              	           int j=0;
	              	           	for(int k=pocetak1; k<=broj_redova; k++) {
	              	           		      j=0;
	              	           		         for(int l=pocetak2; l<=broj_kolona; l++) {
	              	           		         
	              	           		         
	              	           		         	  int brojac=0; 
	              	           		         	
	              	           		         	  if(k>0) {
	              	           		         	   
	              	           		         	  	
	              	           		         	     if(polja[k-1][l]==Polje::Mina) brojac++;
	              	           		         	  	if(l>0)  {
	              	           		            	  if(polja[k-1][l-1]==Polje::Mina) brojac++; }
	              	           		         	     if	(l<polja[0].size()-1)  {
	              	           		         	     if(polja[k-1][l+1]==Polje::Mina) brojac++; }
	              	           		         	  }
	              	           		         	  
	              	           		         	  if(k<polja.size()-1) {
	              	           		         	  	if(polja[k+1][l]==Polje::Mina) brojac++;
	              	           		         	  	if(l>0)  { 
	              	           		         	  	if(polja[k+1][l-1]==Polje::Mina) brojac++; }
	              	           		         	  	if(l<polja[0].size()-1)  {
	              	           		         	  	if(polja[k+1][l+1]==Polje::Mina) brojac++; }
	              	           		         	  }
	              	           		         	  
	              	           		         	 if(l>0) {
	              	           		         	 	if(polja[k][l-1]==Polje::Mina) brojac++; 
	              	           		         	 }
	              	           		         	 if(l<polja[0].size()-1){
	              	           		         	 	if(polja[k][l+1]==Polje::Mina) brojac++;
	              	           		         	 }
	              	           		         	 
	              	           		         	 m[i][j]=brojac; 
	              	           		         	
	              	           		         	 j++; 
	              	           		         } 
	              	           		         i++; 
	              	           	}
	              	           	
	          
	     
	     
	     return m;       
}

//3  valjda dobra 
void BlokirajPolje(Tabla &polja, int x, int y) {
	
	      if(x<0 || y<0 || x>=polja.size() || y>=polja[0].size()) 
	      throw std::domain_error("Polje (x,y) ne postoji");
	      
	         if(polja[x][y]!=Polje::BlokiranoPrazno && polja[x][y]!=Polje::BlokiranoMina && polja[x][y]!=Polje::BlokiranoPosjeceno) {
	         	            
	         	            if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	         	            if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	         	            if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
	         }
	         
	      
}



//4 dobra valjda 
void DeblokirajPolje(Tabla &polja, int x, int y) {
	    
	   if(x<0 || y<0 || x>=polja.size() || y>=polja[0].size())
	      throw std::domain_error("Polje (x,y) ne postoji");
	      
	    if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoMina) {
	    	         if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	    	         if(polja[x][y]==Polje::BlokiranoPrazno)   polja[x][y]=Polje::Prazno;
	    	         if(polja[x][y]==Polje::BlokiranoMina)   polja[x][y]=Polje::Mina;
	    }
}


  enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo };
  enum class Status {  NijeKraj, KrajPoraz, KrajPobjeda }; 
//5 
Status  Idi ( Tabla &polja, int &x, int &y, Smjerovi smjer ) {
	           
	            int a=0,b=0; 
	         if(smjer==Smjerovi::GoreLijevo) {
	         	a=-1; 
	         	b=-1; 
	         }
	         if(smjer==Smjerovi::Gore) {
	         	a=-1;
                b=0; 	
	         }
	         if(smjer==Smjerovi::GoreDesno) {
	         	a=-1; 
	         	b=1; 
	         }
	        if(smjer==Smjerovi::Desno) {
	        	a=0; 
	        	b=1;
	        }
	        if(smjer==Smjerovi::DoljeDesno) {
	        	a=1;
	        	b=1;
	        }
	        if(smjer==Smjerovi::Dolje) {
	        	a=1;
	        	b=0; 
	        }
	        if(smjer==Smjerovi::DoljeLijevo) {
	        	 a=1;
	        	 b=-1;
	        }
	        if(smjer==Smjerovi::Lijevo) {
	        	a=0; 
	        	b=-1;
	        }
	        
	        // nisam sigurna treba li ovdje bacati izuzetke
	       if(x+a<0 || x+a>=polja.size() || y+b <0 || y+b>=polja[0].size()) 
	         throw std::out_of_range("Izlazak van igrace table"); 
	
	           if(polja[x+a][y+b]==Polje::BlokiranoPrazno || polja[x+a][y+b]==Polje::BlokiranoMina || polja[x+a][y+b]==Polje::BlokiranoPosjeceno)  
	           throw std::logic_error("Blokirano polje"); 
	  
	     polja[x][y]=Polje::Posjeceno;
	     x=x+a; 
	     y=y+b; 
	    
	
}
//6 i ovdje sam nesto sklepala 
Status Idi( Tabla &polja, int &x, int &y ,   int novi_x, int novi_y) {
	         
	     if(novi_x<0 || novi_x>polja.size()-1  || novi_y <0 || novi_y>polja[0].size()-1)
	        throw std::out_of_range("Izlazak van igrace table"); 
	      
	      if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno ||
	           polja[novi_x][novi_y]==Polje::BlokiranoMina)
	           throw std::logic_error("Blokirano polje"); 
	           
	     if(polja[novi_x][novi_y]==Polje::Mina) {
	     	
	     	 for(int i=0; i<polja.size(); i++) {
	     	 	
	     	 	for(int j=0; j<polja[i].size(); j++)
	     	 	   polja[i][j]==Polje::Prazno; 
	     	 }
	     	return Status::KrajPoraz; 
	     }
	     
	     bool a= true; 
	     for (int i=0; i<polja.size(); i++) {
	     	for(int j=0; j<polja[0].size(); j++) {
	     		if(!((polja[i][j]==Polje::Mina) || (polja[i][j]==Polje::Prazno))){
	     		   a=false; break;}
	     	}
	     	if(a=false) break; 
	     }
	     if(a==true) return Status::KrajPobjeda; 
	      
	      
	      return Status::NijeKraj; 
}    


enum class KodoviGresaka{PogresnaKomanda, NedostajeParametar, SuvisanParametar,NeispravanParametar };
//7
 void  PrijaviGresku(  KodoviGresaka kod) {
  	    if(kod==KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!";
  	    if(kod==KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!";
  	    if(kod==KodoviGresaka::SuvisanParametar) std::cout <<  "Zadan je suvisan paramtar nakon komande!";
  	    if(kod==KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!"; 
  }



enum class Komande{PomjeriJednoMjesto,PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

//8
 bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
 	             
 	             
 	            std::string  pomocni; 
 	            std::getline(std::cin, pomocni);
 	            
 	            
 	            
 	      
 }
 
 
 
 
int main ()  {
	
// ovdje provjeravam drugu funkciju 
  
  int x=2,y=2; 
  
   Tabla t{{Polje::Prazno, Polje::Mina, Polje::BlokiranoPrazno, Polje::BlokiranoMina, Polje::Mina},
          {Polje::BlokiranoPosjeceno, Polje::Prazno, Polje::Prazno, Polje::Mina, Polje::Mina},
          {Polje::Mina, Polje::Mina, Polje::BlokiranoPosjeceno, Polje::Mina, Polje::BlokiranoMina}};
     auto b (PrikaziOkolinu(t,x,y)); 
     
     for(int i=0; i<b.size(); i++) {
     	for(int j=0; j<b[0].size(); j++)
     	  std::cout << b[i][j]; 
     	  std::cout << std::endl; 
     }
     
          
	return 0;
}