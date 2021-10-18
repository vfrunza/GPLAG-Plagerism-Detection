#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
bool jelislovo(char c){
	if((c>='a' && c<='z') || (c>='A' && c<='Z'))return true;
	return false;
}
std::string ObrniFraze(std::string tekst,std::vector<std::string> fraze){
	int j,k,pocetak,kraj;
	for(int i=0; i<fraze.size();i++){
		if(fraze[i].size()!=0 && tekst.size()!=0){
			j=0;
			k=0;
			do{
				while(j<tekst.size() && fraze[i][0]!=tekst[j])j++;
				if(j!=tekst.size())pocetak=j;
				else break;
				k=0;
				while(j<tekst.size() && k<fraze[i].size() && fraze[i][k]==tekst[j]){j++; k++;}
				kraj=j-1;
				if(k==fraze[i].size()){
					char c;
					for(int f=0;f<(kraj-pocetak)/2+1;f++){
						c=tekst[f+pocetak];
						tekst[f+pocetak]=tekst[kraj-f];
						tekst[kraj-f]=c;
					}
				}
				//j++;
			}while(j<tekst.size());
		}
	}
	return tekst;
}
std::string IzmijeniUPigLatin(std::string tekst,std::vector<std::string> fraze){
	for(int i=0; i<fraze.size();i++){
		for(int j=0; j<fraze[i].size();j++){
			if(!((fraze[i][j]>='a' && fraze[i][j]<='z') || (fraze[i][j]>='A' && fraze[i][j]<='Z')))throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	if(fraze.size()==0){
		if(tekst.size()!=0){
			int i(0),pocetak,kraj;
			do{
				while(i<tekst.size() && !jelislovo(tekst[i]))i++; //do prvog slova
				if(i!=tekst.size())pocetak=i;
				else pocetak=-1;
				while(i<tekst.size() && jelislovo(tekst[i]))i++; //do kraja rijeci
				kraj=i-1; //zadnje slovo rijeci
				if(pocetak!=-1){
					char pslovo=tekst[pocetak];
					for(int j=pocetak;j<kraj;j++){
						tekst[j]=tekst[j+1];
					}
					tekst[kraj]=pslovo;
					if(i!=tekst.size()){
						tekst.insert(tekst.begin() + i, 'y');
						tekst.insert(tekst.begin() + i, 'a');
					}else tekst+="ay";
					i+=2;
				}
			}while(i<tekst.size());
		}
	}else{
		for(int i=0; i<fraze.size();i++){
			int j(0),k(0),pocetak;
			do{
				k=0;
				while(j<tekst.size() && !jelislovo(tekst[j]))j++; //do prvog slova
				pocetak=j;
				
				while (j<tekst.size() && k<fraze[i].size() && tekst[j]==fraze[i][k]){j++; k++;}//do kraja rijeci(dok se poklapa)
				if(k==fraze[i].size() && fraze[i].size()!=0 && (j==tekst.size() || !jelislovo(tekst[j]))){
					char pslovo=tekst[pocetak];
					for(int f=pocetak;f<j-1;f++){
						tekst[f]=tekst[f+1];
					}
					tekst[j-1]=pslovo;
					if(i!=tekst.size()){
						tekst.insert(tekst.begin() + j, 'y');
						tekst.insert(tekst.begin() + j, 'a');
					}else tekst+="ay";
					j+=2;
				}else{
					while(j<tekst.size() && jelislovo(tekst[j]))j++;
				}
			}while(j<tekst.size());
		}
	}
	return tekst;
}
int main ()
{
	try
    {
        std::cout <<  ObrniFraze ("kapak", {"kap"}) << std::endl;
        std::cout <<  ObrniFraze ("kapak", {"kapak"}) << std::endl;
        std::cout <<  ObrniFraze ("kapap", {"kap"}) << std::endl; //Ovo ocigledno nije palindrom ali 
                                                                  //rezultat bi bio u slucaju pogresnog obrtanja.
        
    }
    catch(std::domain_error e)
    {
        std::cout << "Izuzetak: " << e.what();
    }
	/*
	std::string recenica,t,fraz;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze(0);
	while(std::cin.peek()!='\n'){
		std::getline(std::cin,fraz);
		fraze.push_back(fraz);
	}
	try{
		t=IzmijeniUPigLatin(recenica,fraze);
		std::cout<<"Recenica nakon PigLatin transformacije: "<<t<<std::endl;//dodaj
	}catch(std::domain_error z){
		std::cout<<"Izuzetak: "<<z.what()<<std::endl;
	}
	
	t=ObrniFraze(recenica,fraze);
	std::cout<<"Recenica nakon obrtanja fraza: "<<t<<std::endl;*/
	return 0;
}