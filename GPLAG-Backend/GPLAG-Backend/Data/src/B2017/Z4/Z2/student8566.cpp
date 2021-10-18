bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2){
    if(fabs(k1.x-k2.x)<epsilon*(fabs(k1.x)+fabs(k2.x)) && fabs(k1.y-k2.y)<epsilon*(fabs(k1.y)+fabs(k2.y)) && fabs(k1.z-k2.z)<epsilon*(fabs(k1.z)+fabs(k2.z)) && fabs(k1.r-k2.r)<epsilon*(fabs(k1.r)+fabs(k2.r))) return true;
    return false;
}
bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2){
  
    if(fabs(k1.r+k2.r)<epsilon*(fabs(k1.r)+fabs(k2.r))) return true;
    return false;
}
bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2){
    if(fabs(k1.x-k2.x)<epsilon*(fabs(k1.x)+fabs(k2.x)) && fabs(k1.y-k2.y)<epsilon*(fabs(k1.y)+fabs(k2.y)) && fabs(k1.z-k2.z)<epsilon*(fabs(k1.z)+fabs(k2.z))) return true;
    return false;
    
}
bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2){
    
    if((k1.r+k2.r)==RastojanjeCentara(k1,k2)) return true;
    return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2) {
    if((RastojanjeCentara(k1,k2)+k1.r==k2.r) || (RastojanjeCentara(k1,k2)+k2.r==k1.r)) return true;
    return false;
    
}

bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2){
    if(RastojanjeCentara(k1,k2)<(k1.r+k2.r)) return true;
    return false;
    
}
bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2){
    if(DaLiSeSijeku(k1,k2)==true) return true;
    return false ;
    
  
    }
    
   
    

double RastojanjeCentara(const Kugla &k1,const Kugla &k2){
    double rastojanje;
    rastojanje=sqrt(pow(k1.x-k2.y,2)+pow((k1.y-k2.y),2)+pow((k1.z-k2.z),2));
    return rastojanje;
}