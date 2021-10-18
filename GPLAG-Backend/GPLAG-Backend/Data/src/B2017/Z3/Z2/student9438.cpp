/B2017/2018: Zadaća 3, Zadatak 2

void IspisiIndeksPojmova(std::map<std::string, std::vector<std::string>> mapa) {
    auto prvi(mapa.begin());
    for (prvi=mapa.begin(); prvi!=mapa.end(); prvi++) {
        std::cout << prvi->first << ":";
        auto drugi(prvi->second.begin());
        for (int i(0); i<prvi->second.size() - 1; i++) {
            std::cout << *drugi << ",";
            drugi++;
        }
        std::cout << *drugi << std::endl;
    }
}

int main ()
{
    std::cout<<"Unesite tekst: ";
  std::string s;
  std::getline(std::cin, s);
  std::map<std::string, std::set<int>>mapa(KreirajIndeksPojmova(s));
  IspisiIndeksPojmova(mapa);
  std::string rijec;
  for (;;) {
      std::cout<<"Unesite rijec: ";
      std::set<int> skup;
      std::getline(std::cin, rijec);
      if (rijec==".") break;
      try { 
         skup=(PretraziIndeksPojmova(rijec, mapa));
         for (auto x:skup) std::cout<<x<<" ";
         std::cout<<std::endl;
      }
      catch (std::logic_error ) {
          std::cout<<"Unesena rijec nije nadjena!\n";
      }
  }

return 0;
}