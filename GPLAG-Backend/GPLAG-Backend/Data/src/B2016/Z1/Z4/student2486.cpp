#include<iostream> 
#include<vector>
#include<stdexcept>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::domain_error;
//pomocna funkcija za izvrtanje stringa
string Izvrnistring(string rijec)
{ 
    char b; 
    for(int i=0; i<(rijec.size())/2; i++) {
        b=rijec[i];
        rijec[i]=rijec[rijec.size()-1-i];
        rijec[rijec.size()-1-i]=b;
    }
    return rijec;
} 

string ObrniFraze(string recenica, vector <string> fraze)
{
    int k=0,j=0;
    string rijec;
    bool isti{};
for(string element: fraze)
for(int i=0;i<recenica.size();i++)
{
    if(element[j]==recenica[i])//nasao slovo
   { j++; isti=true;}
else if(element[j] != recenica[i])
 {j=0; isti=false;}
if(j==element.size()){
    rijec=Izvrnistring(element);
    int z=0;
    for(int p=i-element.size()+1;p<=i;p++){
        recenica[p]=rijec[z];
        z++;
    }
    
}
   
}return recenica;}
string IzmijeniUPigLatin2(string rijec){
    char slovo;//pomocna funkcija za stavljanje slova na zadnje mjesto
    for(int i=0;i<rijec.size();i++){
        if(i==0){
        slovo=rijec[i];
             for(int j=0;j<rijec.size()-1;j++){
                rijec[j]=rijec[j+1];
            }
            rijec[rijec.size()-1]=slovo;
      
    }}
    return rijec;
}

string IzmijeniUPigLatin(string recenica, vector <string> fraze){
    for(string element: fraze)
    for(char slovo: element)
    if(!((slovo>='A' && slovo<='Z') || (slovo>='a' && slovo<='z')))
    throw domain_error("Nekorektan izbor rijeci");//baca izuzetak
    int k=0;
    string rijec;  
  bool cisto=true;
    for(int i=0; i<fraze.size(); i++) {
        for(int s=0;s<recenica.size();s++){
      if(s!=0){
      if((recenica[s-1]>='A' && recenica[s-1]<='Z')||(recenica[s-1]>='a' && recenica[s-1]<='z'))
      {cisto=false;}}//ako je slovo prije fraze ne mijenja ga
      for(int j=0;j<fraze[i].size();j++){
            if(fraze[i][j]==recenica[s]) {
                 
                k++; 
                s++;    
            } else 
                k=0;  
                if(s!=recenica.size()-1 && j==fraze[i].size()-1){
                    if((recenica[s]>='A' && recenica[s]<='Z') || (recenica[s]<='z' && recenica[s]>='a'))
                    {cisto=false;}
                }
            
            if(k==fraze[i].size() && cisto) { 
        
         
                
                rijec = IzmijeniUPigLatin2(fraze[i]);
                int z=0,p(0);
                for( p=s-fraze[i].size(); p<s; p++) {
                    recenica[p]=rijec[z];
                    z++;
                    
                }
                recenica.insert(recenica.begin()+p, 'a');//dodavanje a i y
                recenica.insert(recenica.begin()+1+p, 'y');
            }
            }
            cisto=true;
        k=0; 
    
    }
    }
    return recenica;

}

int main ()
{
    
    string nekistring;
    vector <string> fraze;
    cout<<"Unesite recenicu: ";
    getline(cin,nekistring);
    string obrnifraze;
    string piglatin;
    string fraza;
    cout<<"Unesite fraze: ";
    do {
        getline(cin,fraza);
        if(fraza.size()!=0)fraze.push_back(fraza);   
        if(fraza.size()==0)break;
        
    }while(true);
        
    obrnifraze= ObrniFraze(nekistring, fraze);
   try{ piglatin=IzmijeniUPigLatin(nekistring, fraze);
           cout<<"Recenica nakon PigLatin transformacije: ";
    cout<<piglatin<<endl;
   }  catch(domain_error greska){cout<<"Izuzetak: "<<greska.what()<<endl;}

    cout<<"Recenica nakon obrtanja fraza: ";
  cout<<obrnifraze<<endl;
        
    

  
    return 0;
}