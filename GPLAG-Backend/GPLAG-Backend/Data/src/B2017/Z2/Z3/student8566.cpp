
#include <iostream>
#include<vector>
#include<new>
#include<stdexcept>
#include <iomanip>


template<typename Tip>

bool DaLiJePeriodican(std::vector<Tip>v,int p){
  
  for(int i(0);i<v.size();i++){
    
  
  
  if(p>=v.size() || p<1) return false;
  if(i+p>=v.size()) break;
  if(v.at(i)!=v.at(i+p)) return false ;
  }
   return true;
  }
  
  template<typename Tip2>
  Tip2 OsnovniPeriod (std::vector<Tip2> v){
      int p(0);
      for(int i(0);i<v.size();i++){
          if(DaLiJePeriodican(v,i)){
          p=i;
          
          return p;
      }
  }
return p;
}
template <typename Tip3>
 Tip3 **AlocirajFragmentirano(const std::vector<Tip3>&v,int &koliko_puta){
  if(v.size()==0) throw std::domain_error("Prazan vektor!");
  for(int i(0);i<v.size();i++){
   if(v[i]<=0) throw std::domain_error("Neispravan vektor!");
  }
  Tip3 ** a=nullptr;
  
  typename std::vector<Tip3>::const_iterator pocetak;
  typename std::vector<Tip3>::const_iterator iza_kraja;
  typename std::vector<Tip3>::const_iterator pomocni;
  //typename std::vector<Tip3>::const_iterator pomocni2;
  
  if(OsnovniPeriod(v)!=0){
   int period(OsnovniPeriod(v));
   pocetak=std::begin(v);
   pomocni = pocetak;
   iza_kraja=std::begin(v)+period;
  
   int glavni(v[0]);
   int brojac(1);
   for(int i(1); i<v.size(); i++){
  
      if(glavni==v[i])
      brojac++;
  
   }
koliko_puta=brojac;

 try{
  a=new Tip3*[period*koliko_puta];
  int duzina=period*koliko_puta;   
  int red(0);
  for(int i(0);i<koliko_puta;i++){
   
   while(pocetak!=iza_kraja){
    
    int broj(*pocetak);
    a[red] = new int[broj];
    red++;pocetak++;
   }
   
   pocetak=pomocni;
  }
  
  pocetak=pomocni;
    
int oduzmi(0);
for(int i(0);i<duzina;i++){
   oduzmi = 0;
   while(pocetak!=iza_kraja){
    
    for(int j(*pocetak - 1); j>=0; j--){  
     a[i][j] = period - oduzmi++; 
    }
    
   if(pocetak == iza_kraja - 1) pocetak = pomocni;
   else pocetak++;
   break;  
   }
}

}catch(...){
 throw;
}
}else{
 
   pocetak=std::begin(v);
   pomocni = pocetak;
   iza_kraja=std::end(v);
  
   koliko_puta=2;

 try{ 
  a=new Tip3*[(iza_kraja - pocetak) * koliko_puta];
  int duzina=(iza_kraja - pomocni)*koliko_puta;
  int red(0);
  
  for(int i(0);i<koliko_puta;i++){
   
   while(pocetak!=iza_kraja){
    
    int broj(*pocetak);
    a[red] = new int[broj];
    red++;pocetak++;
   }
   
   pocetak=pomocni;
  }
  
  pocetak=pomocni;
    
int oduzmi(0);    
for(int i(0);i<duzina;i++){
   oduzmi = 0;
   while(pocetak!=iza_kraja){
    
    for(int j(*pocetak - 1); j>=0; j--){  
     a[i][j] = (iza_kraja-pomocni) - oduzmi++; 
    }
    
   if(pocetak == iza_kraja - 1) pocetak = pomocni;
   else pocetak++;
   break;  
   }
}

}catch(...){
 throw;
}
}

 return a;
  }
  template <typename Tip3>
 Tip3 **AlocirajKontinualno(const std::vector<Tip3>&v,int &koliko_puta){
  if(v.size()==0) throw std::domain_error("Prazan vektor!");
  for(int i(0);i<v.size();i++){
   if(v[i]<=0) throw std::domain_error("Neispravan vektor!");
  }
  Tip3 ** a=nullptr;
  
  typename std::vector<Tip3>::const_iterator pocetak;
  typename std::vector<Tip3>::const_iterator iza_kraja;
  typename std::vector<Tip3>::const_iterator pomocni;
  //typename std::vector<Tip3>::const_iterator pomocni2;
  
  if(OsnovniPeriod(v)!=0){
   int period(OsnovniPeriod(v));
   pocetak=std::begin(v);
   pomocni = pocetak;
   iza_kraja=std::begin(v)+period;
  
   int glavni(v[0]);
   int brojac(1);
   for(int i(1); i<v.size(); i++){
  
      if(glavni==v[i])
      brojac++;
  
   }
koliko_puta=brojac;

 try{
  a=new Tip3*[period*koliko_puta];    
  int duzina=period*koliko_puta;   
  int red(1);
 // 1 2 3 1 2 3 = 12 = koliko_puta na kvadrat * period(3)
 a[0] = new Tip3 [koliko_puta * koliko_puta * period];
 
 for(int i(0);i<koliko_puta;i++){
  
  while(pocetak!=iza_kraja){
   a[red]=a[red-1]+ *pocetak;
   red++;
   if(red == duzina) break;
   if(pocetak==iza_kraja-1) break;
   pocetak++;
   
   
  }
  pocetak=pomocni;
  
 }
 pocetak=pomocni;
 
 int broj(1);
 for(int i(0);i<koliko_puta*period;i++){
  
  while(pocetak!=iza_kraja){
   broj = 1;
   for(int j(*pocetak - 1);j>=0;j--){
    a[i][j]=broj++;
    Tip3 debuger = a[i][j];
    int bezze(0);
   }
 
   if(pocetak!=iza_kraja-1) pocetak++;
   else {
    pocetak=pomocni;
   }
   break; //ovo da nam ide na sljedeci i
   }
  }
    
}catch(...){
 throw;
}
}else{ //ovo sada moramo
 
   pocetak=std::begin(v);
   pomocni = pocetak;
   iza_kraja=std::end(v);
  
   koliko_puta=2;

 try{
  a=new Tip3*[(iza_kraja - pomocni)*koliko_puta];    
  int duzina=(iza_kraja - pomocni)*koliko_puta;   
  int red(1);
 // 1 2 3 1 2 3 = 12 = koliko_puta na kvadrat * period(3)
 a[0] = new Tip3 [koliko_puta * koliko_puta * (iza_kraja - pomocni)];
 
 for(int i(0);i<koliko_puta;i++){
  
  while(pocetak!=iza_kraja){
   a[red]=a[red-1]+ *pocetak;
   red++;
   if(red == duzina) break;
   if(pocetak==iza_kraja-1) break;
    pocetak++;

   
  }
  pocetak=pomocni;
  
 }
 pocetak=pomocni;
 
 int broj(1);
 for(int i(0);i<koliko_puta*(iza_kraja - pomocni); i++){
  
  while(pocetak!=iza_kraja){
   broj = 1;
   for(int j=*pocetak - 1;j>=0;j--){
    a[i][j]=broj++;
   }
 
   if(pocetak!=iza_kraja-1) pocetak++;
   else {
    pocetak=pomocni;
   }
   break; //ovo da nam ide na sljedeci i
   }
  }
    
}catch(...){
 throw;
}
}

return a;
 
  }
int main ()
{
 int broj;
 int n;
std::cout<<"Unesite broj elemenata vektora: ";
std::cin>>n;

 std::vector<int> v;
std::cout<<"Unesite elemente vektora: ";
 for(int i(0);i<n;i++){
  std::cin>>broj;
  v.push_back(broj); }
  int koliko_puta(0);
 
  std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
int alokacija;
std::cin>>alokacija;
if(alokacija==1){
 int **c(nullptr);
 try{
c=AlocirajFragmentirano(v,koliko_puta);

int period = OsnovniPeriod(v);
if(period != 0){
int duzina = period * koliko_puta;

  typename std::vector<int>::const_iterator pocetak(std::begin(v));
  typename std::vector<int>::const_iterator iza_kraja(std::begin(v) + period);
  typename std::vector<int>::const_iterator pomocni(pocetak);

std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
for(int i(0);i<duzina;i++){
 
   while(pocetak!=iza_kraja){
    
    for(int j(0); j<(*pocetak); j++){  
     std::cout<<std::left<<std::setw(3)<<c[i][j]; 
    }
    
   if(pocetak == iza_kraja - 1) pocetak = pomocni;
   else pocetak++;
   break;  
   }
   std::cout<<std::endl;
}

for(int i(0); i<duzina; i++) delete[] c[i];
delete[] c;

}else if(period == 0){

  typename std::vector<int>::const_iterator pocetak(std::begin(v));
  typename std::vector<int>::const_iterator iza_kraja(std::end(v));
  typename std::vector<int>::const_iterator pomocni(pocetak);

   int duzina = (iza_kraja - pocetak) * koliko_puta;
std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
for(int i(0);i<duzina;i++){
 
   while(pocetak!=iza_kraja){
    
    for(int j(0); j<(*pocetak); j++){  
     std::cout<<std::left<<std::setw(3)<<c[i][j]; 
    }
    
   if(pocetak == iza_kraja - 1) pocetak = pomocni;
   else pocetak++;
   break;  
   }
   std::cout<<std::endl;
}

for(int i(0); i<duzina; i++) delete[] c[i];
delete[] c;
}
}catch(std::bad_alloc){
 std::cout<<"Nije uspjelo";
}catch(std::domain_error e){
 std::cout<<"Izuzetak: "<<e.what();
}
  
 }else if(alokacija == 0){ //--------------------------------------------------
  
    int **c(nullptr);
 try{
c=AlocirajKontinualno(v,koliko_puta);

int period = OsnovniPeriod(v);
if(period != 0){
int duzina = period * koliko_puta;

  typename std::vector<int>::const_iterator pocetak(std::begin(v));
  typename std::vector<int>::const_iterator iza_kraja(std::begin(v) + period);
  typename std::vector<int>::const_iterator pomocni(pocetak);

std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
for(int i(0);i<duzina;i++){
 
   while(pocetak!=iza_kraja){
    
    for(int j(0); j<(*pocetak); j++){  
     std::cout<<std::left<<std::setw(3)<<c[i][j]; 
    }
    
   if(pocetak == iza_kraja - 1) pocetak = pomocni;
   else pocetak++;
   break;  
   }
   std::cout<<std::endl;
}

delete[] c[0];
delete[] c;

}else if(period == 0){

  typename std::vector<int>::const_iterator pocetak(std::begin(v));
  typename std::vector<int>::const_iterator iza_kraja(std::end(v));
  typename std::vector<int>::const_iterator pomocni(pocetak);

   int duzina = (iza_kraja - pocetak) * koliko_puta;
std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
for(int i(0);i<duzina;i++){
 
   while(pocetak!=iza_kraja){
    
    for(int j(0); j<(*pocetak); j++){  
     std::cout<<std::left<<std::setw(3)<<c[i][j]; 
    }
    
   if(pocetak == iza_kraja - 1) pocetak = pomocni;
   else pocetak++;
   break;  
   }
   std::cout<<std::endl;
}

delete[] c[0];
delete[] c;
}
}catch(std::bad_alloc){
 std::cout<<"Nije uspjelo";
}catch(std::domain_error e){
 std::cout<<"Izuzetak: "<<e.what();
}
  
  
 }

	return 0;
}