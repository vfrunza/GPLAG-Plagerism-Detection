
#include <iostream>
#include <vector>
#include <string>
#include <set>

std::vector<std::set<std::string>> RasporedTimova(std::vector<std::string>Imena,int BrojTimova){
    int BrojDjece(Imena.size());
    std::vector<std::set<std::string>>Timovi(BrojTimova);
    for(int i(1);i<=BrojTimova;i++){
        for(int j(1);j<BrojDjece%BrojTimova;j++){
        Timovi[j].resize(BrojDjece/BrojTimova+1);
        }
        if(i==BrojDjece%BrojTimova){
            Timovi[i+1].resize(BrojDjece/BrojTimova);
        }
    }
    return Timovi;
}
int main ()
{
    std::vector<std::set<std::string>>Tim;
    std::vector<std::string>imena{"Emir","Nermana","Zeljkica","Vedran","Brkic","Selma","Sencho"};
    Tim=RasporedTimova(imena,2);
    for(int i(0);i<Tim.size();i++){
        std::cout<<Tim[i]<<" ";
    }
	return 0;
}