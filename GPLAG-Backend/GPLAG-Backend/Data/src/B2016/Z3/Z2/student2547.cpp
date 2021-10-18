/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>

using namespace std;

bool DaLiPostoji(string rijec,map <string, set<int>> index){
    bool postoji = false;
    if(index.find(rijec) != index.end()){
        postoji = true;
    }
    
    return postoji;
}

set<int> PretraziIndeksPojmova (string rijec,map<string,set<int>> index){
    
    for(auto x : index){
        
        if(x.first == rijec){
            return x.second;
        }
       
     }
     
     return set<int> ();
}


map<string,set<int>> KreirajIndeksPojmova (string tekst){
    
    char * token = std::strtok( (char *) tekst.c_str(), " ");
    
    
    map <string,set<int>> rez;
    int index = 0;
    
    while(token != NULL)
    {
        if(rez.size() > 0){
            
            if(DaLiPostoji(string(token), rez)){
            rez[string(token)].insert(index);
             }else{
              set<int>a;
               a.insert(index);
               rez.insert(make_pair(string(token), a));
         }
    }else{
        set<int>a;
        a.insert(index);
        rez.insert(make_pair(string(token), a));
    }
    
    index += strlen(token) + 1;
    token = strtok(NULL," ");
    }
    
    
    return rez;
}
//.... POPRAVITI .........
void IspisiIndeksPojmova (map<string, set<int>> index_pojmova){
      
    for(auto x : index_pojmova){
        cout<< x.first << ": ";
        int i = 0;
       for(auto y : x.second){
          cout<< y << ( (i == x.second.size() - 1 ) ? "" : "," );
          i++;
       }
        cout<<endl;
    }
    
}
int main ()
{
    /*
    map<string,set<int>> a = KreirajIndexPojmova("abc qwe stsda abc abc dhi qwe hrkw dhi ");
    
    for(auto x : a){
        cout<< x.first << " : ";
        
        for(auto y : x.second){
            cout<< y<<",";
        }
        cout<<endl;
    }
    
    
    for(auto u : PretraziIndexPojmova("hrw",a)){
        cout<< u << ",";
    }
    */
    
    string unos;
    cout<<"Unesite tekst: ";
    getline(cin,unos);
    
     map<string,set<int>> index_pojmova = KreirajIndeksPojmova(unos);
    
    for(auto x : index_pojmova){
        cout<< x.first << ": ";
        int i = 0;
       for(auto y : x.second){
          cout<< y << ( (i == x.second.size() - 1 ) ? "" : "," );
          i++;
       }
        cout<<endl;
    }

  //  IspisiIndexPojmova(index_pojmova);
    string rijec;
    while(rijec != "."){
        cout<<"Unesite rijec: " ;
        cin.clear();
        getline (cin,rijec);
        int i = 0;
        set<int>indexi = PretraziIndeksPojmova(rijec,index_pojmova);
        if(indexi.size() == 0 && rijec.length() > 0 && rijec != "."){
            cout<<"Unesena rijec nije nadjena!\n";
            continue;
        }
      
        for(auto u : indexi){
            cout<< u << ( (i != indexi.size() - 1) ? " " : " " );
              i++;  
            
        }
        cout<<endl;
    }
	return 0;
}