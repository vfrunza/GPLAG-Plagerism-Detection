/*B 2017/2018, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <string>
#include <vector>

std::string Obrnuto(std::string fraza){
	std::string novi;
	for(int i(fraza.length()-1);i>=0;i--) novi.push_back(fraza.at(i));
	return novi;
}

std::string UbaciUString(std::string gdjeubacam, std::string staubacam, int pozicijaubacanja){
	std::string novi;
	for(int i(0);i<pozicijaubacanja;i++){
		novi.push_back(gdjeubacam.at(i));
	}
//std::cout<<novi<<std::endl;
	for(int i(0);i<staubacam.length();i++){
		novi.push_back(staubacam.at(i));
	}
//std::cout<<novi<<std::endl;
	for(int i(pozicijaubacanja); i<gdjeubacam.length();i++){
		novi.push_back(gdjeubacam.at(i));
	}
//std::cout<<novi<<std::endl;
	return novi;																
}

std::string ObrisiPolaiUbaciPola(std::string gdjeubacam, std::string staubacam, int pozicijaubacanja){
	std::string novi;
	if(staubacam.length()%2==0){
	for(int i(0);i<pozicijaubacanja-(staubacam.length()/2);i++){
		novi.push_back(gdjeubacam.at(i));
	}}
	else{
		for(int i(0);i<(pozicijaubacanja-(staubacam.length()/2))-1;i++){
		novi.push_back(gdjeubacam.at(i));
	}
	}
//std::cout<<novi<<std::endl;
	for(int i(staubacam.length()/2);i<staubacam.length();i++){
		novi.push_back(staubacam.at(i));
	}
//std::cout<<novi<<std::endl;
	for(int i(pozicijaubacanja/*+staubacam.length()*/); i<gdjeubacam.length();i++){
		novi.push_back(gdjeubacam.at(i));
	}
//std::cout<<novi<<std::endl;
	return novi;
}

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> fraze){
	if(recenica.length()==0) return recenica;
	int brojacpoklapanja=0;
	int potpunopoklapanje=0;
	int k,x;
	k=0;
	std::string pomoc=recenica;
	for(int i(0);i<fraze.size();i++){ //prolazi kroz fraze
	int hihi=0;
		for(int j(0); j<recenica.length();j++){ //prolazi kroz recenicu
		        brojacpoklapanja=0;
				potpunopoklapanje=0;
				hihi=0;
			if(fraze.at(i).at(0)==recenica.at(j)) { //ako je prvo slovo te fraze jednako trenutnom slovu u recenici
				x=0; //prolazi kroz slova te fraze
			    k=j; //pamti na kom je slovu u recenici poklapanje sa frazom
				while(fraze.at(i).at(x)==recenica.at(k)){ //dok je slovo fraze jednako slovu recenice
			//	std::cout<<fraze.at(i).at(x)<<" i "<<recenica.at(k)<<" "<<k<<"<"<<recenica.length()-1<<" "<<x<<" < "<<fraze.at(i).length()-1<<std::endl;
					brojacpoklapanja++;
					hihi=0;
					if(k==int(recenica.length())-1 || x==int(fraze.at(i).length())-1){hihi=1; break;}
					 x++; k++;
				}
		    }
		    if(hihi==1) {x++; k++;}
		    if(brojacpoklapanja==fraze.at(i).length()){
		        if(j+fraze.at(i).length()==recenica.length()) /*kraj*/{potpunopoklapanje=1; brojacpoklapanja=0;}
		        else if(recenica.at(j+fraze.at(i).length())==' ' || recenica.at(j+fraze.at(i).length())==',' ){ potpunopoklapanje=1; brojacpoklapanja=0;}}
		    if(potpunopoklapanje==1){
		    	pomoc=UbaciUString(pomoc, Obrnuto(fraze.at(i)),k);
		    	recenica=pomoc;
		    } 
		}
	}
	return recenica;
}
std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> fraze){
	if(recenica.length()==0) return recenica;
	int brojacpoklapanja=0;
	int potpunopoklapanje=0;
	int k,x;
	k=0;
	std::string pomoc=recenica;
	for(int i(0);i<fraze.size();i++){ //prolazi kroz fraze
	int hihi=0;
		for(int j(0); j<recenica.length();j++){ //prolazi kroz recenicu
		        brojacpoklapanja=0;
				potpunopoklapanje=0;
				hihi=0;
			if(fraze.at(i).at(0)==recenica.at(j)) { //ako je prvo slovo te fraze jednako trenutnom slovu u recenici
				x=0; //prolazi kroz slova te fraze
			
			    k=j; //pamti na kom je slovu u recenici poklapanje sa frazom
				while(fraze.at(i).at(x)==recenica.at(k)){ //dok je slovo fraze jednako slovu recenice
					brojacpoklapanja++;
				    if(k==int(recenica.length())-1 || x==int(fraze.at(i).length())-1){hihi=1; break;}
					 x++; k++;
					 hihi=0;
				}
		    }
		    if(hihi==1) {x++; k++;}
		   // if(brojacpoklapanja==fraze.at(i).length() && (recenica.at(j+fraze.at(i).length())==' ' || recenica.at(j+fraze.at(i).length())==',' || j+fraze.at(i).length()==recenica.length())){ potpunopoklapanje=1; brojacpoklapanja=0;}
		    
		    if(brojacpoklapanja==fraze.at(i).length()){
		        if(j+fraze.at(i).length()==recenica.length()) /*kraj*/{potpunopoklapanje=1; brojacpoklapanja=0;}
		        else if(recenica.at(j+fraze.at(i).length())==' ' || recenica.at(j+fraze.at(i).length())==',' ){ potpunopoklapanje=1; brojacpoklapanja=0;}}
		    
		    if(potpunopoklapanje==1){
		    	pomoc=ObrisiPolaiUbaciPola(pomoc, Obrnuto(fraze.at(i)),k);
		    	recenica=pomoc;
		    } 
		}
	}
	return recenica;
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::string recenica1;
	std::string recenica2;
	std::getline(std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	std::string unos;
	std::string predhodni="nista";
	std::vector<std::string> fraze;
	for(;;){
		std::getline(std::cin, unos);
		if(unos.length()==0) break;
		fraze.push_back(unos);
	}
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	recenica1=NapraviPalindrom(recenica,fraze);
	std::cout<<recenica1<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	recenica2=NapraviPoluPalindrom(recenica,fraze);
	std::cout<<recenica2;
	return 0;
}