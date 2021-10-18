/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>
int BrojSlova(std::string s){
    int br=0;
    for(int i=0;i<s.length();i++){
        if((s[i]>='0' && s[i]<='9')|| (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))br++;
    }
    return br;
}
std::vector<std::set<std::string>>Razvrstavanje(std::vector<std::string>imena,int timovi){
    if(timovi<1 || timovi>imena.size() )throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> ii;
    std::list<std::string>im;
    int n=imena.size();
    //std::string zadnji(imena[imena.size()-1]);
    //std::cout<<zadnji;
    for(std::string s: imena)
    im.push_back(s);
    int tim=0,brsl;
    bool istina=true;
    int zz=0;
    //std::cout<<im[0];
    //std::cout<<"we"<<im.size();
    //for(auto it=im.begin();it!=im.end();it++)
    int nn=n;
    auto it=im.begin();
    while(nn>0){
        if(it==im.end())it=im.begin();
        if(n%timovi>tim){
            //if(zz>0)it--;
            istina=false;
            std::set<std::string>t;
            for(int i=0;i<int(n/timovi)+1;i++){
                if(it==im.end())it=im.begin();
                //brsl=(*it).length();
                brsl=BrojSlova(*it);
                t.insert(*it);
                it=im.erase(it);
                nn--;
                for(int i=1;i<brsl;i++){
                    if(it==im.end())it=im.begin();
                    it++;
                }
            }
            ii.push_back(t);
        }
        else{
            //if(zz>0)it--;
            if(it==im.end())it=im.begin();
            std::set<std::string>t;
            //if(istina==false){it--;istina=true;}
            for(int i=0;i<int(n/timovi);i++){
                if(it==im.end())it=im.begin();
                //brsl=(*it).length();
                brsl=BrojSlova(*it);
                //std::cout<<"ee"<<*it<<" "<<brsl<<std::endl;
                t.insert(*it);
                it=im.erase(it);
                nn--;
                if(it==im.end())it=im.begin();
                for(int i=1;i<brsl;i++){
                    if(it==im.end())it=im.begin();
                    it++;
                    //std::cout<<"r"<<*it<<std::endl;
                }
                //std::cout<<"ko"<<*it;
                if(it==im.end())it=im.begin();
            }
            if(it==im.end())it=im.begin();
            ii.push_back(t);
        }
        //std::cout<<std::endl<<*it;
        if(it==im.end())it=im.begin();
        //if(*it==zadnji)it--;
        tim++;
        zz++;
    }
    //std::cout<<"sss"<<ii.size();
    return ii;
}
int main ()
{
    //auto s=Razvrstavanje({"Marija", "Dario", "Noa", "Zara", "Armin", "Kenan", "Melisa", "Adna", "Merima" ,"Leon","Ines","Tajra","Dzan","Adin"},2);
    //std::cout<<s.size();
    try{
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::vector<std::string>imena;
    std::cin.clear();
    std::cin.ignore(100000,'\n');
    for(int i=0;i<n;i++){
        std::string ime;
        std::getline(std::cin,ime);
        imena.push_back(ime);
    }
    std::cout<<"Unesite broj timova: ";
    int brtim;
    std::cin>>brtim;
    auto s=Razvrstavanje(imena,brtim);
    for(int i=0;i<s.size();i++){
        std::cout<<"Tim "<<i+1<<": ";
        bool z=true;
        for(std::string d:s[i]){
            if(z){std::cout<<d;z=false;}
            else
            std::cout<<", "<<d;
        }
        std::cout<<std::endl;
    }
    }
    catch(std::logic_error e){
        std::cout <<"Izuzetak: "<<e.what()  << std::endl;
    }
	return 0;
}