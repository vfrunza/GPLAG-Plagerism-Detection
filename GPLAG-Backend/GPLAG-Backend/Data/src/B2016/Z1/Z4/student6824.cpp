#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
void Okreni(std::string &s, std::vector<std::string>f, int i, int pocetak, int kraj, int duz){
    int l{0}, pocetak1{0}, kraj1{0}, pokaz1{0}, duz1{0}, j{0};
    char slovo;
    for(int k=0; k<s.size(); k++){
        if(s[k]==f[i][pocetak+l]){
            if(pokaz1==0){
                pokaz1=1;
                pocetak1=k;
                kraj1=k;
            }
            else
               kraj1=k;
             duz1++;
             l++;
        }
        else{
            if(duz==duz1){
                j=kraj1;
                for(int p=0; p<duz1/2; p++){
                    slovo=s[pocetak1+p];
                    s[pocetak1+p]=s[j];
                    s[j]=slovo;
                    j--;
                }
            }
            l=0;
            pokaz1=0;
            duz1=0;
        }
    }
    if(duz==duz1){
        j=kraj1;
        for(int p=0; p<duz1/2; p++){
            slovo=s[pocetak1+p];
            s[pocetak1+p]=s[j];
            s[j]=slovo;
            j--;
        }
    }
}
std::string ObrniFraze(std::string s, std::vector<std::string>f){
    int pokaz{0}, pocetak{0}, kraj{0}, duz{0};
    for(int i=0; i<f.size(); i++){
        pokaz=0;
        duz=0;
        for(int j=0;;j++){
            if(f[i][j]=='\0') {break;}
            if(pokaz==0){
                pokaz=1;
                pocetak=j;
                kraj=j;
            }
            else{
                kraj=j;
            }
        }
        duz=kraj+1-pocetak;
        Okreni(s,f,i,pocetak,kraj,duz);
    }
    return s;
}
void Promijeni1(std::string &s){
    char slovo;
    int pokaz1{0}, pocetak1{0}, kraj1{0};
    for(int k=0; k<s.size(); k++){
        if((s[k]>='A' && s[k]<='Z') || (s[k]>='a' && s[k]<='z')){
            if(pokaz1==0){
                pokaz1=1;
                slovo=s[k];
                pocetak1=k;
                kraj1=k;
            }
            else{
                kraj1=k;
            }
        }
        else{
            if(pokaz1==1){
                s.insert(s.begin()+kraj1+1,slovo);
                s.insert(s.begin()+kraj1+2,'a');
                s.insert(s.begin()+kraj1+3,'y');
                s.erase(s.begin()+pocetak1);
                pokaz1=0;
                k++;
            }
        }
    }
    if(pokaz1==1){
    s.insert(s.begin()+kraj1+1,slovo);
    s.insert(s.begin()+kraj1+2,'a');
    s.insert(s.begin()+kraj1+3,'y');
    s.erase(s.begin()+pocetak1);
    }
}
void Promijeni(std::string &s, std::vector<std::string>f, int i, int pocetak, int kraj, int duz){
    int l{0}, pocetak1{0}, kraj1{0}, pokaz1{0}, duz1{0}, brojac{0}, ind{0};
    char slovo;
    for(int k=0; k<s.size(); k++){
        if((s[k]>='A' && s[k]<='Z') || (s[k]>='a' && s[k]<='z')){
         if(s[k]==f[i][pocetak+l]){
            if(pokaz1==0){
                pokaz1=1;
                slovo=s[k];
                pocetak1=k;
                kraj1=k;
            }
            else
             kraj1=k;
             duz1++;
             l++;
         }
         else{brojac++;}
        }
        else{
            if(duz1>0) {duz1=duz1+brojac; if(brojac>0) ind=1; brojac=0;}
            else brojac=0;
            if(duz1==duz && ind==0){
                for(int p=0; p<3; p++){
                    if(p==0) s.insert(s.begin()+kraj1+1,slovo);
                    if(p==1) s.insert(s.begin()+kraj1+2,'a');
                    if(p==2) s.insert(s.begin()+kraj1+3,'y');
                }
                s.erase(s.begin()+pocetak1);
            }
            l=0;
            pokaz1=0;
            duz1=0;
            ind=0;
        }
    }
    if(duz1>0){duz1=duz1+brojac; brojac=0;}
    else brojac=0;
    if(duz1==duz){
        for(int p=0; p<3; p++){
            if(p==0) s.insert(s.begin()+kraj1+1,slovo);
            if(p==1) s.insert(s.begin()+kraj1+2,'a');
            if(p==2) s.insert(s.begin()+kraj1+3,'y');
        }
        s.erase(s.begin()+pocetak1);
    }
}
std::string IzmijeniUPigLatin(std::string s, std::vector<std::string>f){
        int pokaz{0}, pocetak{0}, kraj{0}, ind{0}, duz{0}, j{0};
        for(int i=0; i<f.size(); i++){
            j=0;
            pokaz=0;
            while(f[i][j]!='\0'){
                if(f[i][j]=='\0') {break;}
                if(pokaz==0){
                    pokaz=1;
                    pocetak=j;
                    kraj=j;
                }
                else{
                    kraj=j;
                    if(f[i][j]==' '){throw std::domain_error("Nekorektan izbor rijeci");}
                }
                j++;
            }
        }
        if(f.size()==0) {Promijeni1(s);}
        else{
         for(int i=0; i<f.size(); i++){
            pokaz=0;
            ind=0;
            duz=0;
            for(int j=0;;j++){
                if(f[i][j]=='\0'){break;}
                if(pokaz==0){
                    pokaz=1;
                    pocetak=j;
                    kraj=j;
                }
                else{
                    kraj=j;
                    if(f[i][j]==' ') ind=1;
                }
            }
            duz=kraj+1-pocetak;
            if(ind==1){}
            else{
                Promijeni(s,f,i,pocetak,kraj,duz);
            }
         }
        }
    return s;
}
int main ()
{
    std::string s;
    std::vector<std::string>f;
	try{
	    std::cout<<"Unesite recenicu: ";
	    std::getline(std::cin,s);
	    std::cout<<"Unesite fraze: ";
	    std::string pomoc;
	    while(std::cin.peek()!='\n'){
	        std::getline(std::cin,pomoc);
	        for(int i=0; i<pomoc.size(); i++){
	            if(!((pomoc[i]>='A' && pomoc[i]<='Z') || (pomoc[i]>='a' && pomoc[i]<='z') || (pomoc[i]==' ')))
	            throw std::domain_error("Nekorektan izbor rijeci");
	        }
	        f.push_back(pomoc);
	    }
	    std::string s1;
	    s1=IzmijeniUPigLatin(s,f);
	    std::cout<<"Recenica nakon PigLatin transformacije: ";
	    for(int i=0; i<s1.size(); i++)
	     std::cout<<s1[i];
	}
	catch(std::domain_error izuzetak){
	    std::cout <<"Izuzetak: "<<izuzetak.what();
	}
	std::string s2;
	std::cout<<std::endl<<"Recenica nakon obrtanja fraza: ";
	s2=ObrniFraze(s,f);
	for(int i=0; i<s2.size(); i++)
	 std::cout<<s2[i];
	return 0;
}