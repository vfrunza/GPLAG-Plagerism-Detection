#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
   std::string ZamijeniPremaRjecniku(std::string S,std::map<std::string,std::string> Mapa ){
        std::string Novi;
        for ( int i = 0; i < S.size(); i++ ) {
                
            
                while( S[i] == ' ' && i <S.size()) {
                    Novi.push_back(S[i]);
                    i++;
                }
                    int j(i);
                    std::string help;
                while ( S[j] != ' ' && j < S.size()) {
                    help.push_back(S[j]);
                    j++;
                }
            auto it(Mapa.find(help));
            if ( it == Mapa.end())  {
               for (int k = i; k < j; k++) Novi.push_back(S[k]);
               i = j;
               i--;
                continue;
            }
            else  {
                help = it->second;
                for ( int k = 0 ; k < help.length(); k++) Novi.push_back(help[k]);
                i=j;
                i--;
                continue;
            }
            
        }
        return Novi
        ;
    }
    
int main ()
{
    std::ma}p<std::string,std::string>moj_rjecnik{{"jabuka","apple"},{"da","yes"},{"kako","how"},{"ne","no"},{"majmun","monkey"}};
    std::cout<< ZamijeniPremaRjecniku("kako da ne",moj_rjecnik);
	return 0;
}