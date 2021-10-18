
#include <string>
#include <iostream>
#include <functional>
std::string Desifriraj(std::function<char(int)> f, std::string &s){
    char c[1];
    for(int i=0;i<s.size();i++){
        c[0]=char(f(s.at(i)));
        s.replace(i,1,c);
    }
    return s;
}
int main()
{
    std::string s="CHUGENUHNWFRYNOFYDYVGWUFDUCGJWVLWSYVWSYVUGWLWSYNOLUGYGHEIJYFZEIYFYCVJYB";
    std::cout << "Sifrirana poruka: " << s << std::endl;
    std::cout << "Funkcija desifriranja je: x=mod(11y-121,26)+65" << std::endl;
    Desifriraj([](int x)->char{return ((11*x-121)%26)+65;}, s);
    std::cout << "Desifrirana poruka: "  << s << std::endl;
    return 0;
}