#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

int PotencijalniKrivci(char **&znak, std::vector<std::string> SpisakImena){
		try {
				int BrojImena(SpisakImena.size());
			try {
		
			znak=new char*[BrojImena];
			}
			catch (std::bad_alloc) {
				throw;
			}
			int brojac(0);
			for(int i=0;i<BrojImena;i++){
				znak[i]=new char[SpisakImena[i].size()+1];
				int j(0);
				while(j!=SpisakImena[i].size()){
					znak[i][j]=SpisakImena[i][j];
					j++;
				}
				znak[i][j]='\0';
				brojac+=1;
			}
			
		}
		catch(std::bad_alloc){
			throw;
		}
		catch (...) {
			return brojac;
		}
		
	
		
}


int OdbaciOptuzbu(char **&SpisakImena,int velicina,std::string String){
	bool Postoji(false);
	for(int i=0;i<velicina;i++){
	
		int velicina2(0);
		char *ime(SpisakImena[i]);
			while (*ime) {
				velicina2++;
				ime++;
			}
			
			if(velicina2==String.size()){
				int j=0;
				while(ime[i]==String[i]){
					j++;
				}
				if(j==velicina2)
					Postoji=true;
				
				
			}
			
			if(Postoji){
				delete[] SpisakImena[i];
				SpisakImena[i]=nullptr;
				break;
			}
			
			
			
	}
	if(!Postoji) throw std::domain_error("Osoba sa imenom " + String+ " nije bila optuzena");
}






int main ()
{
	return 0;
}