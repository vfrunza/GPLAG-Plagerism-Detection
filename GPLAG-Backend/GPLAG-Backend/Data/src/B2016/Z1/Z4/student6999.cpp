#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
/*NE ZABORAVITI DODATI RUBNE SLUCAJEVE PLUS STA AKO JE LISTA PRAZNA !!!*/
bool slovo(char s){
    if((s>='A' && s<='Z')||(s>='a' && s<='z')) return true;
    return false;
}
std::string okreni(std::string s){
    std::string izlaz;
    izlaz.resize(s.size());
    int j=0;
    for(int i=s.size()-1;i>=0;i--){
        izlaz[j++] =s[i];
    }
    return izlaz;
}
std::string zamijeniprvoizadnje(std::string s){ //Ne mijenja prvo i zadnje
//u pocetku izrade zadace sam pogresno shvatio sta piglatin radi pa sam ispravio sad
//ostalo je zamijeniprvoizadnje zbog ljenosti.
    char temp(s[0]);
    for(int i=0;i<s.size();i++){
        s[i] = s[i+1];
    }
    s[s.size()-1] = temp;
    return s;
}
std::string ObrniFraze(std::string s, std::vector<std::string> lista){
    for(int i=0;i<lista.size();i++){
        std::string trenutna_fraza=lista[i];
        int duzina_fraze=trenutna_fraza.length();
        for(int j=0;j<s.length();j++){
            bool isti_su=true;
            for(int k=0;k<duzina_fraze;k++){
                if(s[k+j] != trenutna_fraza[k]){
                    isti_su=false;
                    break;
                }
            }
            if(isti_su){
                std::string zamjena =okreni(trenutna_fraza);
                for(int h=0;h<trenutna_fraza.length();h++){
                    s[j+h]=zamjena[h];
                }
            }
        }
    }
    return s;
}
std::string IzmijeniUPigLatin(std::string s,std::vector<std::string> lista){
    if(lista.size()!=0){
        for(int i=0;i<lista.size();i++){
            for(int j=0;j<lista[i].size();j++){
                if(!slovo(lista[i][j])) throw std::domain_error("Nekorektan izbor rijeci");
            }
        }
        
        
    for(int i=0;i<lista.size();i++){
        std::string trenutna_fraza=lista[i];
        for(int j=0;j<s.size();j++){
            if(s[j]==lista[i][0]){
                if(j!=0){
                    if(slovo(s[j-1])) continue;
                }
                //nasao prvo isto slovo, sad dalje treba ici
                bool isti_su=true;
                int pocetni_index=j;
                for(int k=0;k<lista[i].size();k++){
                    if(s[j+k]!=lista[i][k]) { isti_su=false; break;}
                    if((k==lista[i].size()-1) && (j+k)!=s.size() && slovo(s[j+k+1])) isti_su=false;
                    
                } 
                if(j!=0 && isti_su && slovo(s[j-1])) isti_su=false;
                if(isti_su){
                    //nasao odg. rijec
//                    if(j!=0 && j+trenutna_fraza.length()!= s.length() && slovo(s[j-1]) && slovo(s[j+trenutna_fraza.length()])) continue;
//                    if(j==0 && j+trenutna_fraza.length()!= s.length() && slovo(s[j+trenutna_fraza.length()])) continue;
                    std::string zamjena=zamijeniprvoizadnje(lista[i]);
                    for(int k=0;k<lista[i].size();k++){
                        s[j+k]=zamjena[k];
                    }s.insert(s.begin()+pocetni_index+lista[i].size(),'a');
                    s.insert(s.begin()+pocetni_index+lista[i].size()+1,'y');
                }
            }
        }
    }
}else if(lista.size()==0){
    for(int i=0;i<s.size();i++){
        // ide kroz string
        while(!slovo(s[i])){ i++; if(i==s.length()-1) return s;} //dolazimo do prve rijeci;
        //sad smo na prvoj rijeci
        int pocetak(i);
        std::string zamjena;
        while(slovo(s[pocetak])){
            //sve dok imas rijec
            zamjena.push_back(s[pocetak++]);
        }
        if(zamjena.size()){
        zamjena = zamijeniprvoizadnje(zamjena);
        for(int k=0;k<zamjena.size();k++){
            //prelijepi preko svega zamjenu
            s[i+k]=zamjena[k];
        }s.insert(s.begin()+i+zamjena.size(),'a');
        s.insert(s.begin()+i+zamjena.size()+1,'y');
        i=pocetak+2;
        }
    }
}
    return s;
}
int main ()
{
    std::cout<<"Unesite recenicu: ";
    std::string ulaz;
    std::getline(std::cin,ulaz);
    std::vector<std::string> lista;
    int i=0;
    std::cout<<"Unesite fraze: ";
    while(1){
        std::string temp;
        std::getline(std::cin,temp);
        if(temp.size() != 0) lista.push_back(temp);
        if(temp.size() == 0)break;
    }
    std::string izlaz1=ObrniFraze(ulaz,lista);
    try{
    std::string izlaz2=IzmijeniUPigLatin(ulaz,lista);
    std::cout<<"Recenica nakon PigLatin transformacije: "<<izlaz2;
    }catch(std::exception &a){
        std::cout<<"Izuzetak: "<<a.what();
    }
    std::cout<<std::endl<<"Recenica nakon obrtanja fraza: "<<izlaz1;
	return 0;
}