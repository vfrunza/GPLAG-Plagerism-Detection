#include <iostream>
#include <string>
#include <vector>
std::string IstakniFraze(std::string recenica,std::vector<std::string>fraza){
    int a=0;
    while(a<fraza.size()){
        for(int i=0;i<recenica.length()-1;i++){
            int k=fraza[a].size();
            if(recenica.substr(i,k)==fraza[a] && fraza[a]!=" "){
                recenica.insert(recenica.begin()+i,'(');
                i+=k+1;
                recenica.insert(recenica.begin()+i,')');
            }
        }
        a++;
    }
    return recenica;
}
int main() {
    std::string recenica;
    std::cout << "Unesite recenicu: " << std::endl;
    std::getline(std::cin,recenica);
    std::vector<std::string>fraze;
    std::string djeno;
    std::string kraj(" ");
    do{
        std::cout << "Unesi frazu" << std::endl;
        std::getline(std::cin,djeno);
        if(djeno=="\n")break;
        fraze.push_back(djeno);
    }while(djeno!=kraj);
    std::cout << IstakniFraze(recenica,fraze) << std::endl;
    return 0;
}

