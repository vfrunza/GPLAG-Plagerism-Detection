#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

std::string ObrniFraze(std::string s, std::vector<std::string> v){
	
	//testirati prazan string ovdje !! i provjeriti sta ce biti sa praznim vektorom !!!
	if(s.empty() || v.empty())return s;
	int k = 0;
	
	while(k != v.size()){
		std::string pom(v[k]);
		
		for(int i = 0;i<s.size();i++){
			
			int h = 0;
			if(s[i] == pom[h]){
			 	int poc = i;
				while(s[i] == pom[h]){
					i++;
					h++;
					if(i == s.size() || h == pom.size())break;
				}
				
				if(h==pom.size()){
					if(/*(i==s.size() || s[i] == ' ' || s[i]==',' || s[i]=='.' ) && (poc==0 || s[poc-1]==' ')*/true){
					//	std::cout<<"JEA"<<std::endl;
						char temp;
						i--;
						int kraj = i;
						while(poc <= i ){
							
							temp = s[i];
							s[i] = s[poc];
							s[poc] = temp;
							
							poc++;
							i--;
						}
						
						i = kraj;
					}
					
				}else{
					i--;
				}
				
			}
			
		}
		

		k++;
	}
	 
	
	

	return s;
}


//druga fja !!!

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v){
	
	if(s.empty())return s;
	
	if(!(v.empty())){
		
	int k = 0;
	//prvo cemo provijeriti da li se prosljedeni vektor sastoji samo od slova engleskog alfabeta

		for(std::string p: v){
			for(char c: p){
				if(!((c>='A' && c<='Z') || (c>='a' && c<='z')) )throw std::domain_error("Nekorektan izbor rijeci");
			}
		}
	
	
	while(k != v.size()){
		std::string pom(v[k]);
		
		for(int i = 0;i<s.size();i++){
			
			int h = 0;
			if(s[i] == pom[h]){
			 	int poc = i;
				while(s[i] == pom[h]){
					i++;
					h++;
					if(i == s.size() || h == pom.size())break;
				}
				
				if(h==pom.size()){
					if( (i==s.size() || (!((s[i] >='A' && s[i]<='Z')|| (s[i] >='a' && s[i]<='z'))) ) && (poc==0 || (!((s[poc -1] >='A' && s[poc -1]<='Z')|| (s[poc-1] >='a' && s[poc-1]<='z'))))){
						
						
						//ovdje prebacimo prvo slovo na kraj rijeci u stringu !
						char temp = s[poc];
						i--;
					
						while(poc<i){
							s[poc] = s[poc+1];
							poc++;
						}
						s[i] = temp;
						
						//sada preostaje da na kraj svake rijeci dodaomo "ay"
						s.resize(s.size()+2);
				//		int kraj = i;  // i je sada na kraju rijeci
						
						int krajnji = s.size();
						//petlja za prosirivanje stringa
						while(krajnji>i){
							
							s[krajnji] = s[krajnji-2];
					
							krajnji--;
						}
						s[++i]='a';
						s[++i]='y';
						
						
					}
					
				}else{
					i--;
				}
				
			}
			
		}
		

		k++;
	}
	 
	}else {
		//ako je vektor prazan zamjenjujemo sve rijeci !!!
		
	
		for(int i = 0;i<s.size();i++){
			
			//dok je s[i] neslovo
			while(  (!((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')  )) && i!=s.size()   ){
				i++;
				if(i==s.size())return s;
				
			}
			
			
			int poc = i;
			//dok je s[i] slovo
			while( ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) && i!=s.size()){
				i++;
				if(i==s.size())break;
			}
			i--;
			//sada poc pokazuje na pocetak rijeci a i na kraj rijeci
			char temp = s[poc];
						
						
						while(poc<i){
							s[poc] = s[poc+1];
							poc++;
						}
						s[i] = temp;
						
						//sada preostaje da na kraj svake rijeci dodaomo "ay"
						s.resize(s.size()+2);
						
						
						int krajnji = s.size();
						//petlja za prosirivanje stringa
						while(krajnji>i){
							
							s[krajnji] = s[krajnji-2];
					
							krajnji--;
						}
						s[++i]='a';
						s[++i]='y';
			
			
			
		}
		
	}
	

	return s;
}



int main ()
{
	

	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin,recenica);
	
	
	std::vector<std::string> v;
	std::cout<<"Unesite fraze: ";
	
	std::string s;
	

	while(true){
	
		std::getline(std::cin,s);
		      
		if(s.length()==0)break;
	
		
			v.push_back(s);
	
	}
	

	
	try{
		
		IzmijeniUPigLatin(recenica,v);
		std::cout<<"Recenica nakon PigLatin transformacije: ";
		std::cout<<IzmijeniUPigLatin(recenica,v)<<std::endl;
	}catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
	
	std::cout<<"Recenica nakon obrtanja fraza: ";
	std::cout<<ObrniFraze(recenica,v);

	
	return 0;
}






















