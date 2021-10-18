#include <iostream>
#include <vector>
typedef std::vector<std::vector<double>> vektor ;
vektor RastuciPodnizovi(std::vector<double> a){
   int j=0;
   vektor r_podnizovi(a.size());
   unsigned int i=0;
   while(i<a.size()-1){
      if(i+1>=(int)a.size()) break;
      else{  
      while( a[i]<=a[i+1]){
         if(i+2>=(int)a.size()) break;
         else{
         r_podnizovi[j].push_back(a[i]);
         i++;
         }
      }
      r_podnizovi[j].push_back(a[i]);
      if(i==(int)a.size()-2)
      {
         if(a[a.size()-2]<=a[a.size()-1])
         {
            r_podnizovi[j].push_back(a[a.size()-1]);
         }
      }
      i++;
      j++;
      
   }}
   for( int i=a.size()-1;i>=0;i--){
   if(r_podnizovi[i].size()==0 || r_podnizovi[i].size()==1) r_podnizovi.erase(r_podnizovi.begin()+i);
   }
return r_podnizovi;
}

vektor OpadajuciPodnizovi(std::vector<double> a){
      int j=0;
   vektor o_podnizovi(a.size());
   unsigned int i=1;
   
   while(i<int(a.size())){
      if( i+2>int(a.size())) break;
      else {
         while(a[i-1]>=a[i] && i<int(a.size())){
         if( i+2>int(a.size())) break;
         else{o_podnizovi[j].push_back(a[i-1]);
         i++;
      }}
      o_podnizovi[j].push_back(a[i-1]);
      if(i==(int)a.size()-1)
      {
         if(a[a.size()-2]>=a[a.size()-1])
         {
            o_podnizovi[j].push_back(a[a.size()-1]);
         }
      }
      i++;
      j++;
   }}
   for( int i=int(a.size())-1;i>=0;i--){
   	if(o_podnizovi[i].size()==0 || o_podnizovi[i].size()==1) o_podnizovi.erase(o_podnizovi.begin()+i);
   }
return o_podnizovi;
}

int main ()
{  
double broj;
int n;
   std::vector<double> a;
   std::cout<<"Unesite broj elemenata vektora: ";
   std::cin>>n;
   
   std::cout<<"Unesite elemente vektora: ";
   for(int i=0;i<n;i++){
   	std::cin>>broj;
   	a.push_back(broj);
   } 
    vektor rastuciv=RastuciPodnizovi(a);
   
   std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
   for( int i=0;i<RastuciPodnizovi(a).size();i++){
      for( int j=0;j<RastuciPodnizovi(a)[i].size();j++){
         
          std::cout<<RastuciPodnizovi(a)[i][j]<<" ";
      }
      std::cout<<std::endl;
   }
   std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
   for( int i=0;i<OpadajuciPodnizovi(a).size();i++){
      for( int j=0;j<OpadajuciPodnizovi(a)[i].size();j++){

           std::cout<<OpadajuciPodnizovi(a)[i][j]<<" ";
      }
      std::cout<<std::endl;
   }
	return 0;
}