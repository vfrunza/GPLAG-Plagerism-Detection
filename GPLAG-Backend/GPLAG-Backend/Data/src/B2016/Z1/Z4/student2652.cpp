/*B 2016/2017, Zadaæa 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
typedef std::string rijec;
rijec IzvrniString(std::string s){
   int vel=s.size();
   int i{},j;
   char P;
   j=vel-1;
   while(j!=i){
      P=s[i];
      s[i]=s[j];
      s[j]=P;
      i++;
      if(i==j)
         break;
      j--;
   }
   return s;
}
bool opseg (rijec keno){
    //if (keno=="") return false;
if ( (keno[0] >= 'A' && keno[0] <= 'Z') || (keno[0] >= 'a' && keno[0] <= 'z') ) return false;
return true;
}
rijec ObrniFraze (rijec neki_string, std::vector<rijec> fraze){
    rijec novi,stari;
    int c(0);
    /*for (int i=0; i<neki_string.size(); i++){ //obrni petlje
        for (int j=0; j<fraze.size(); j++){
                rijec prije = "";
                rijec poslije="";
                rijec ks = neki_string.substr(i,fraze[j].size());
                if (i!=0) prije = neki_string.substr(i-1,1);
                if (i+fraze[j].size()<neki_string.size()-1) poslije = neki_string.substr(i+fraze[j].size(),1);
        if ( (opseg(prije) || opseg(poslije)) && ks==fraze[j] )  {  IzvrniString(ks); stari=ks; i = i+ks.size()-1; break;  }
        else stari = neki_string.substr(i,1); }
        novi = novi + stari;
    }
*/
rijec orginal = neki_string;
   for (int j=0; j<fraze.size(); j++ ){ //obrni petlje
   
        for (int i=0; i<neki_string.size(); i++ ){
            
                rijec prije = "";
                rijec poslije="";
                rijec ks = neki_string.substr(i,fraze[j].size());
                if (i!=0) prije = neki_string.substr(i-1,1);
                if (i+fraze[j].size()<neki_string.size()-1) poslije = neki_string.substr(i+fraze[j].size(),1);
        if ( ks==fraze[j] || (ks==fraze[j] && fraze[j].substr(fraze[j].size()-1,1)==" ") )  {   stari=IzvrniString(ks); stari =stari[0]; /*i = i+ks.size()-1;*/ neki_string= neki_string.substr(0, i+1)+ IzvrniString(ks).substr(1,IzvrniString(ks).size()-1) + neki_string.substr(i+IzvrniString(ks).size(),neki_string.size()-1) ;  }
        else stari = neki_string.substr(i,1);
        novi = novi + stari;  }
        neki_string = novi; novi ="";
       // std::cout<<neki_string<<novi<<std::endl;
    }

    return neki_string;
}
rijec transformiraj(std::string s){
   int vel=s.size();
   rijec prvo_slovo = s.substr(0,1);
   rijec ostatak = s.substr(1,vel-1);
   rijec novi_string = ostatak + prvo_slovo+"ay";
  // if (s.substr(vel-1,1)== " " || s.substr(vel-1,1)== "," || s.substr(vel-1,1)== ".")  novi_string+= "ay "; else novi_string+= "ay";
   return novi_string;
}
rijec IzmijeniUPigLatin (rijec neki_string, std::vector<rijec> fraze){
int c;
     for (int i=0; i<fraze.size(); i++){
            for (int j=0; j<fraze[i].size(); j++){
            if ((fraze[i][j]>='A' && fraze[i][j]<='Z' )|| (fraze[i][j]>='a' && fraze[i][j]<='z') )  c =1; else {c=0; break;}
        }
        if (c==0) throw std::domain_error("Nekorektan izbor rijeci");
     }
    // std::cout <<fraze.size();
     if (fraze.size()==0) { 
        // std::cout<<"EVO MEE";
        int d(0), d1(0);
         for (int i=0; i<neki_string.size(); i++) {
        rijec ks = neki_string.substr(i,1); /*std::cout<< ks;*/
        //rijec ks = neki_string.substr(i,fraze[j].size());
        rijec prije, poslije;
        if (i==0)  prije = ""; else  prije = neki_string.substr(i-1,1);
        if (i==neki_string.size()-1) rijec poslije=""; else poslije = neki_string.substr(i+1,1); 
        if (opseg(ks)) continue; 
        if (opseg(prije) ) d = i;
        if (opseg(poslije) ) {d1 = i -d +1; fraze.push_back(neki_string.substr(d, d1));  }
          
         }
     }
     //std::cout<<fraze.size(); 
    // std::cout<<"VEKTOR GLASI"<<fraze[0];
//for (rijec x: fraze ) std::cout<< x<<std:: endl;
    rijec novi,stari;
   /* int q(0);
    std::vector<rijec> orginal;
    if (fraze.size()==0) {
          int i(0);
        for (; ;){
           while( neki_string.substr(i,1) == " ") {i++; if (i==neki_string.size()) {i--; break; }  }
           int d(0);
           while( neki_string.substr(i,1) != " ") {i++;   if (i==neki_string.size()) {i--;   q=1; break;} d++; }
           fraze.push_back(neki_string.substr(i-d,d+q));  if ( i==neki_string.size()-1) break;
        }
    }
     for (int i=0; i<fraze.size(); i++){
        orginal.push_back(fraze[i]);
     }

    std::vector<rijec> zarez;
     std::vector<rijec> tacka;
      for (int i=0; i<fraze.size(); i++){
        zarez.push_back(fraze[i]+ ",");
    }
     for (int i=0; i<fraze.size(); i++){
        tacka.push_back(fraze[i]+ ".");
    }
    for (int i=0; i<fraze.size(); i++){
        fraze[i]=fraze[i]+ " ";
    }
*/

   // fraze [fraze.size()-1] += " ";
    //for (rijec keno : fraze) std::cout <<keno<<"X"<<std::endl<<fraze.size();
   // for (rijec keno : orginal) std::cout <<keno<<"X"<<std::endl<<fraze.size();
c = 0;
   for (int i=0; i<neki_string.size(); i++){ //obrni petlje
        for (int j=0; j<fraze.size(); j++){
                rijec prije = "";
                rijec poslije="";
                rijec ks = neki_string.substr(i,fraze[j].size());
                if (i!=0) prije = neki_string.substr(i-1,1);
                if (i+fraze[j].size()<neki_string.size()-1) poslije = neki_string.substr(i+fraze[j].size(),1);
        if ( (opseg(prije) && opseg(poslije)) && ks==fraze[j] )  {   stari=transformiraj(ks); i = i+ks.size()-1;   break;  }
        else stari = neki_string.substr(i,1); }
        novi = novi + stari;
    }

    return novi;
}

int main(){
int izuzetak(1);
   std::vector<rijec> vektor;
    rijec x;
    rijec a;
    int c;
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin, a);
    std::cout<<"Unesite fraze: ";
    for (; ;){
        std::getline(std::cin, x);
        if (x=="") break;
            vektor.push_back(x);

    }


   rijec b (a);
          try { IzmijeniUPigLatin(a,vektor);}   catch(std::domain_error e)
    {
        std::cout << "Izuzetak: " << e.what()<<std::endl; izuzetak =0;
    }
    if (izuzetak) {std::cout<<"Recenica nakon PigLatin transformacije: "<< IzmijeniUPigLatin(a,vektor) <<std::endl;}

  std::cout<<"Recenica nakon obrtanja fraza: "<< ObrniFraze(b,vektor); 
  /*   try
    {
        std::string s{"Svaka elementarna funkcija je neprekidna gdje je definisana."};
       std::cout <<   ObrniFraze (s, {"elementarna", "je", "gdje", "prekidna"}) << std::endl;
        std::cout <<  IzmijeniUPigLatin (s, {"elementarna", "je", "gdje", "prekidna"}) << std::endl;
    }
    catch(std::domain_error e)
    {
        std::cout << "Izuzetak: " << e.what();
    } 
    /*try
    {
        std::string s1{"Svaka  elementarna funkcija je neprekidna gdje je definisana."};
        std::string s2{"Svakaelementarna   funkcija je neprekidna gdje je definisana."};
        std::cout <<  ObrniFraze (s1, {"elementarna", "gdje", "prekidna gdje"}) << std::endl;
        std::cout <<  ObrniFraze (s2, {"elementarna   ", "je", "definisana"}) << std::endl;
    }
    catch(std::domain_error e)
    {
        std::cout << "Izuzetak: " << e.what();
    } */
	return 0;

}