//B 2016/2017, Zadaća 1, Zadatak 4
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

typedef std::vector<std::string> vektor;

std::string ObrniFraze(std::string STRING, vektor Obrni){
    int j(0);
    
    for(int i=0; i<Obrni.size(); i++){
        char 
        while(STRING.at(j)<STRING.length()){
            if(STRING.at(j)=='\n') 
            
            if(Obrni[i]==STRING[j]){
                
                std::string OBILJEZI(STRING[j]);
                for(int k=OBILJEZI.length()-1, e=0; e<i; i--, j++){
                    char TEMP=OBILJEZI.at(e);
                    OBILJEZI.at(e)=OBILJEZI.at(k);
                    OBILJEZI.at(k)=TEMP;
                }
            }
        }
    }
    return STRING;
}

/*std::string IzmijeniUPigLatin(std::string STRING, vektor PigLatinRijeci){
    std::string pomocni;
    pomocni(STRING);
    
    
    return pomocni;
}*/

int main ()
{
    std::string s;
    std::string fraze;
    vektor VEK;
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin, s);
    
    std::cout<<"Unesite fraze: ";
    for(;;){
         std::getline(std::cin, fraze);
         if(fraze.length()==0) break;
         VEK.push_back(fraze);
    }
    
   
    auto OBRNUTO(ObrniFraze(s, VEK));
    /*auto PIG(IzmijeniUPigLatin(s, VEK));
    
    std::cout<<"Recenica nakon PigLatin transformacije: ";
    for(int i=0; i<PIG.length(); i++){
        std::cout<<PIG[i];
    }*/
    
    std::cout<<"Recenica nakon obrtanja fraza: ";
    for(int i=0; i<OBRNUTO.length(); i++){
        std::cout<<OBRNUTO[i];
    }
    
	return 0;
}