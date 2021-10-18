#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>

bool Alfabet(char c)
{
    if(c<'A' || c>'z' || (c>'Z' && c<'a')) return false;
    else return true;
}
std::string ObrniFraze(std::string recenica, std::vector<std::string> fraze)
{
    for(std::string fraza: fraze)
    {
        int poc=0,kraj=0;
        while(poc<recenica.length())
        {
            kraj=poc;
            while(kraj<recenica.length())
            {
                if(recenica.substr(poc,kraj-poc+1)==fraza)
                {
                    int i=poc, j=kraj;
                    while(i<=(kraj+poc)/2 && j>=(kraj+poc)/2)
                    {
                        char temp(recenica[i]);
                        recenica[i]=recenica[j];
                        recenica[j]=temp;
                        i++; j--;
                    }
                    
                    break;
                    
                }
                else kraj++;
            }
            poc++;
        }
    }
    return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> fraze)
{
    if(fraze.size()==0)
    {
        int poc=0, kraj=0;
        while(poc<recenica.length())
        {
            kraj=poc;
            while(kraj<recenica.length())
            {
                if((poc==0 && Alfabet(recenica[kraj+1])==false) || (poc!=0 && Alfabet(recenica[poc-1])==false && kraj<recenica.length()-1 && Alfabet(recenica[kraj+1])==false)
                || (poc!=0 && Alfabet(recenica[poc-1])==false && kraj==recenica.length()-1))
                {
                    recenica.insert(recenica.begin()+kraj+1,recenica[poc]);
                    recenica.insert(recenica.begin()+kraj+2,'a');
                    recenica.insert(recenica.begin()+kraj+3,'y');
                    recenica.erase(recenica.begin()+poc);
                    poc=kraj+3;
                }
                else kraj++;
            }
            poc++;
        }
    }
    else {
        for(std::string fraza: fraze)
    {
        for(char c: fraza)
        {
            if(Alfabet(c)==false) throw std::domain_error("Nekorektan izbor rijeci");
        }
        int poc=0,kraj=0;
        while(poc<recenica.length())
        {
            kraj=poc;
            while(kraj<recenica.length())
            {
                if(recenica.substr(poc,kraj-poc+1)==fraza && (
                (poc==0 && Alfabet(recenica[kraj+1])==false) || (poc!=0 && Alfabet(recenica[poc-1])==false && kraj<recenica.length()-1 && Alfabet(recenica[kraj+1])==false)
                || (poc!=0 && Alfabet(recenica[poc-1])==false && kraj==recenica.length()-1)))
                {
                    recenica.insert(recenica.begin()+kraj+1,recenica[poc]);
                    recenica.insert(recenica.begin()+kraj+2,'a');
                    recenica.insert(recenica.begin()+kraj+3,'y');
                    recenica.erase(recenica.begin()+poc);
                    
                }
                else kraj++;
            }
            poc++;
        }
    }
    }
    return recenica;
}

int main ()
{
    
    std::cout<<"Unesite recenicu: ";
    std::string recenica;
    std::getline(std::cin,recenica);
    std::cout<<"Unesite fraze: ";
    std::vector<std::string> fraze;
    for(;;)
    {
        std::string fraza;
        std::getline(std::cin, fraza);
        fraze.push_back(fraza);
        if(char(std::cin.peek())=='\n') break;
    }
    try{
    std::string s1=IzmijeniUPigLatin(recenica,fraze);
    std::string s2=ObrniFraze(recenica,fraze);
    std::cout<<"Recenica nakon PigLatin transformacije: "<<s1<<std::endl;
    std::cout<<"Recenica nakon obrtanja fraza: "<<s2<<std::endl;
    }
    
    catch(std::domain_error izuzetak)
    {
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
        std::string s2=ObrniFraze(recenica,fraze);
        std::cout<<"Recenica nakon obrtanja fraza: "<<s2<<std::endl;
        
    }
	return 0;
}