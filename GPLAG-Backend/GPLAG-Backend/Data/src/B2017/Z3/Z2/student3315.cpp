/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

typedef map<string, vector<string>> Knjiga;
typedef Knjiga Book;

void convertToLowerCase(Book& book)
{
    for(auto it = book.begin(); it != book.end(); ++it)
    {
        for(int i = 0; i < it->second.size(); ++i)
        {
            for(int j = 0; j < it->second[i].length(); ++j)
            {
                it->second[i][j] = tolower(it->second[i][j]);
            }
        }
    }
}

map<string, set<tuple<string, int, int>>> KreirajIndeksPojmova(Book book)
{
    convertToLowerCase(book);
    map<string, set<tuple<string, int, int>>> result;
    for(auto it = book.begin(); it != book.end(); ++it) // Poglavlje
    {
        for(int i = 0; i < it->second.size(); ++i) // Stranica
        {
            string word = "";
            for(int j = 0; j < it->second[i].length(); ++j) // String
            {
                char c = it->second[i][j];
                if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
                {
                    word += c;
                }
                else if(word != "")
                {
                    result[word].insert(make_tuple(it->first, i + 1, j - word.length()));
                    word = "";
                }
            }
            if(word != "")
            {
                result[word].insert(make_tuple(it->first, i + 1, it->second[i].length() - word.length()));
                word = "";
            }
        }
    }
    return result;
}

set<tuple<string, int, int>> PretraziIndeksPojmova(string word, const map<string, set<tuple<string, int, int>>>& indexes)
{
    auto it = indexes.find(word);
    if(it != indexes.end())
    {
        return it->second;
    }
    throw logic_error("Unesena rijec nije nadjena!");
}

void IspisiIndeksPojmova(map<string, set<tuple<string, int, int>>> indexes)
{
    for(auto it1 = indexes.begin(); it1 != indexes.end(); ++it1)
    {
        cout << it1->first << ": ";
        for(auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2)
        {
            cout << get<0>(*it2) << "/" << get<1>(*it2) << "/" << get<2>(*it2);
            auto it3 = it2;
            it3++;
            if(it3 != it1->second.end())
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

int main ()
{
    Book book;
    std::string poglavlje,stranica,naziv;

    std::string rijec;
    std::vector<string> vektor_stringova;
   
   int i=1;
   while(1){
           std::cout<<"Unesite naziv poglavlja: ";
           std::getline(std::cin,poglavlje);
           
           
           
           
           if(poglavlje=="."){
               break;
           }
       
       
       
       while(1){
           std::cout<<"Unesite sadrzaj stranice "<<i<<": ";
           std::getline(std::cin,rijec);
           if(rijec=="."){
               book.insert(make_pair(poglavlje,vektor_stringova));
               vektor_stringova.clear();
               break;
           }
           vektor_stringova.push_back(rijec);
           i++;
       }
      
   }
   
    //book.insert(make_pair(poglavlje,vektor_stringova));
    
    
   
    std::cout<<"\nKreirani indeks pojmova: \n";
    auto result=KreirajIndeksPojmova(book);
    IspisiIndeksPojmova(result);
    
    /*try{
     auto a = PretraziIndeksPojmova("qwe", result);
    
    
    for(auto it = a.begin(); it != a.end(); ++it)
    {
        cout << get<0>(*it) << "/" << get<1>(*it) << "/" << get<2>(*it);
    }
    }
    catch(std::logic_error error){
        std::cout<<error.what()<<std::endl;
    }*/
    
    
    
    while(1){
        std::string rijec;
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,rijec);
        
        if(rijec=="."){
            return 0;
        }
        
        try{
        auto a=PretraziIndeksPojmova(rijec,result);
        
        
        for(auto it=a.begin();it!=a.end();++it){
            std::cout<<get<0>(*it)<<"/"<<get<1>(*it)<<"/"<<get<2>(*it) << " ";
        }
        
        std::cout<<std::endl;
        
        }
        catch(std::logic_error error){
            std::cout<<error.what()<<std::endl;
        }
       
        /*try{
            auto b=PretraziIndeksPojmova(rijec,result);
            
      }
        
        catch(logic_error error){
            std::cout<<error.what()<<std::endl;
        }*/
        
    }
    
    
    
    /*
    Book book;
    vector<string> page;
    page.push_back("abc qwe stsda abc abc dhi qwe hrkw dhi");
    page.push_back("pqr, ab/123 (qwe) tt2 ");
    book.insert(make_pair("I", page));
    auto result = KreirajIndeksPojmova(book);
    IspisiIndeksPojmova(result);
    auto a = PretraziIndeksPojmova("qwe", result);
    for(auto it = a.begin(); it != a.end(); ++it)
    {
        cout << get<0>(*it) << "/" << get<1>(*it) << "/" << get<2>(*it);
    }
    try
    {
        auto b = PretraziIndeksPojmova("jaid", result);
    }
    catch(logic_error error)
    {
        cout << error.what() << endl;
    }
    */
	
}
    