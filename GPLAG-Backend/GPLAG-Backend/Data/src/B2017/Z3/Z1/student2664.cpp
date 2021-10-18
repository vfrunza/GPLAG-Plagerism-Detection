/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility> //pair
#include <functional>
#include <algorithm>
#include <exception>
#include <cstring>
#include <cmath> //??
#include <string>

using std::vector;
using std::pair;
using std::function;
using std::sort;
using std::domain_error;
using std::range_error;
using std::cout;
using std::cin;
using std::endl;
using std::lower_bound;
using std::upper_bound;
using std::binary_search;
using std::make_pair;
using std::fabs; //??
using std::sin; //??
using std::string;

typedef pair<double, double> Par;

const double EPS(0.0001);

bool PonavljaLiSePrvi(const vector<Par> &vec, Par par){
  int br(-1);
  for(const Par &x : vec) 
    if(fabs(x.first - par.first) < EPS) {
      br++;
      if(br>0) return true;
    }
  return false;
}

bool FjaKriterija(Par par1, Par par2){
  return par1.first < par2.first;  
}

double fja(double x){ return x*x + sin(x);}

template <typename TipPrvog, typename TipDrugog>
  pair<TipPrvog, TipDrugog> NapraviPar(TipPrvog prvi, TipDrugog drugi){
    return {prvi, drugi};
  }

function<double(double)> LinearnaInterpolacija(vector<Par> vec){
  sort(vec.begin(), vec.end(), FjaKriterija);
  for(Par par : vec)  if(PonavljaLiSePrvi(vec, par)) throw domain_error("Neispravni cvorovi");
  
  return [vec](double x){
    if(x < vec[0].first || x > vec[vec.size()-1].first) throw range_error("Argument izvan opsega");
    
    Par tmp_par(NapraviPar(x,0));
    if(binary_search(vec.begin(), vec.end(), tmp_par, FjaKriterija)) return lower_bound(vec.begin(), vec.end(), tmp_par, FjaKriterija) -> second;
    
    auto it_manji = upper_bound(vec.begin(), vec.end(), tmp_par, FjaKriterija);
    auto it_veci = lower_bound(vec.begin(), vec.end(), tmp_par, FjaKriterija);
    if(it_manji == it_veci) it_manji--;
    
    double y(it_manji->second);
    y += (x - it_manji->first)*(it_veci->second - it_manji->second)/(it_veci->first - it_manji->first);
    return y;
  };
  
}

function<double(double)> LinearnaInterpolacija(function<double(double)> fun, double xmin, double xmax, double deltax){
 if(xmin > xmax || deltax <= 0) throw domain_error("Nekorektni parametri"); 
 
 vector<Par> vec;
 double x(xmin);
 while(x < xmax) {
   vec.push_back({x, fun(x)});
   x += deltax;
 }
 
 return LinearnaInterpolacija(vec);
}


int main (){
  int opcija(0), broj_cvorova(0);
  
  cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): "; 
  cin >> opcija;
  function<double(double)> f;
  string approx("");
  
  if(opcija == 1){
    vector<Par> vec;
    cout << "Unesite broj cvorova: ";
    cin >> broj_cvorova;
    cout << "Unesite cvorove kao parove x y: ";
    for(int i=0; i<broj_cvorova; i++){
      double x, y;
      cin >> x >> y;
      vec.push_back({x, y});
    }
    try{
      f = LinearnaInterpolacija(vec);
    }
    catch(range_error er){
      cout << er.what() << endl;
      return 0;
    }
    catch(domain_error er){
      cout << er.what() << endl;
      return 0;
    }
  }
  else if(opcija == 2){
    approx = "approx";
    cout << "Unesite krajeve intervala i korak: ";
    double minx, maxx, deltax;
    cin >> minx >> maxx >> deltax;
    try{
      f = LinearnaInterpolacija(fja, minx, maxx, deltax);
    }
    catch(range_error er){ //??
      cout << er.what() << endl;
      return 0;
    }
    catch(domain_error er){
      cout << er.what() << endl;
      return 0;
    }
  } 
  //else  //??
  
  do{
    double argument;
    cout << "Unesite argument (ili \"kraj\" za kraj): ";
    cin >> argument;
    if(!cin){
      cin.ignore(10000, '\n');
      break;
    }
    
    try{
      f(argument);
    }
    catch(range_error er){
      cout << er.what() << endl;
      continue;
    }
    catch(domain_error er){
      cout << er.what() << endl;
      continue;
    }
    if(opcija == 2) cout << "f(" << argument << ") = " << fja(argument) << " ";
    cout << "f" << approx << "(" << argument << ") = " << f(argument) << endl;
    }while(1);  
  
	return 0;
}
