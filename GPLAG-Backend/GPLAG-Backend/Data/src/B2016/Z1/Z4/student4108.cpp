/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string ObrniFraze(std::string recenica, std::vector<std::string> rijeci){
	for(int a=0;a<rijeci.size();a++){
		for(int i=0;i<recenica.length();i++){
			if(recenica[i]==rijeci[a][0]){
				std::string rijec1=recenica.std::string::substr(i,rijeci[a].length());
				if(rijec1==rijeci[a]){
					char temp;
					for(int j=0;j<int(rijec1.length()/2);j++){
						temp=recenica[i+j];
						recenica[i+j]=recenica[i+rijec1.length()-1-j];
						recenica[i+rijec1.length()-1-j]=temp;
					}
				}
			i=i+rijec1.length()-1;
			}
		}
	}
	return recenica;
}


std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> rijeci){
	for(int i=0;i<rijeci.size();i++){
		for(int j=0;j<rijeci[i].size();j++){
			if(rijeci[i][j]<'A' || (rijeci[i][j]>'Z' && rijeci[i][j]<'a') || rijeci[i][j]>'z') throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	if(rijeci.size()==0){                                     //ako se posalje prazan vektor 'rijeci', mijenja u piglatin svaku rijec u recenici//
		int i=0;
		while(i<recenica.size()){
			if((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='A' && recenica[i]<='Z')){
				int poc=i;
				int br=0;
				while((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='A' && recenica[i]<='Z')) {i++; br++;}
				recenica[i]=recenica[poc];
				for(int j=0;j<br;j++){
					recenica[poc+j]=recenica[poc+j+1];
				}
				recenica.insert(recenica.begin()+i,'a'); i++;
				recenica.insert(recenica.begin()+i,'y'); i++;
				recenica[i]=' ';
				i++;
			}
			else i++;
		}
	}
	else{
    	for(int a=0;a<rijeci.size();a++){
    		for(int i=0;i<recenica.length();i++){
    			if((i==0 && recenica[i]==rijeci[a][0]) || (i!=0 && (recenica[i-1]<'A' || (recenica[i-1]>'Z' && recenica[i-1]<'a') || recenica[i-1]>'z') && (recenica[i]==rijeci[a][0])))      //provjerava da li je se rijec iz vektora poklapa sa prvom rijecju u recenici, ili ako se poklapa sa nekom rijeci u sredini, da li je znak prije pocetnog slova rijeci "neslovo"
    			{
    				std::string rijec1=recenica.std::string::substr(i,rijeci[a].length());
    				if(rijec1==rijeci[a] && i+rijec1.length()<recenica.length() && (recenica[i+rijec1.length()]<'A' || (recenica[i+rijec1.length()]>'Z' && recenica[i+rijec1.length()]<'a') || recenica[i+rijec1.length()]>'z')){ //uslov za "kraj rijeci"-da li je znak poslije "neslovo"
    					recenica[i+rijec1.length()]=recenica[i];      //prebacuje zadnje slovo na kraj rijeci//
    				for(int k=0;k<rijec1.length();k++){
    						recenica[i]=recenica[i+1];                    //pomjeri sva slova ulijevo//
    						i++;
    					}
    					recenica.resize(recenica.length()+2);               //poveca recenicu da mogu stati 'ay' u pronadjenu rijec//
    					for(int j=recenica.length()-1;j>=i;j--){
    					recenica[j]=recenica[j-2];                 //pomjeranje ostatka recenice udesno da se mogu ubaciti 'ay'
    					}
    					recenica[i]='a';
    					recenica[i+1]='y';
    					recenica[i+2]=' ';
    				}
    			}
    		}
    	}
	}
   return recenica;
}

int main ()
{   
	std::string recenica,rijec;
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin,recenica);
    std::vector<std::string>rijeci;
    std::cout<<"Unesite fraze: ";
    for(;;){
    	std::getline(std::cin,rijec);
    	if(rijec=="") break;
    	rijeci.push_back(rijec);
    }
    try{
    	std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica,rijeci)<<std::endl;
    	}
    catch(std::domain_error izuzetak){
    	std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    }
    std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica,rijeci);
	return 0;
}