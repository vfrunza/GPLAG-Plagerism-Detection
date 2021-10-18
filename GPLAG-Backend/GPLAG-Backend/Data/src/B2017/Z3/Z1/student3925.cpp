#include <iostream>
#include <string>

void funkcija(std::string s){
    for(int i(0);i<s.size(); i++) s[i]=(7*s[i]-5)%26+65;
    std::cout << s << std::endl;
}

int main(){
    std::string s="NPSVZKXPSDMZFMMDKZFKXALVKDKJKEKPSXKPZMTPABYJVKUKNTKDKNKXPSDAUEFSJXSIKJSIKJAES";
    funkcija(s);
    return 0;
}