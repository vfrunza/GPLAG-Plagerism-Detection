#include <stdio.h>
#include <math.h>
#define H1 3.30
#define H2 3.00
#define H3 5.00
#define P1 6.80
#define P2 8.00
#define P3 5.30
#define C1 5.00
#define C2 3.90
#define C3 6.00

int main()
{
	char Mirza,Tarik,Bojan,novi_red;
	float Restoran,Trovac,Bistro,Restoran1,Popust1,TrovacA,TrovacB,TrovacC,TrovacD,TrovacE,TrovacF,TrovacG,TrovacK,TrovacH;
	float BistroA,BistroB,BistroC,BistroD,BistroE,BistroF,BistroG,BistroH,BistroK,Restoran2,Popust2,Popust3,Restoran3,Popust1E,Popust2E;
	float Popust4,Popust5,Restoran4C,Restoran5C,RestoranD,Popust6,Popust7,Restoran6D,Restoran7D,RestoranE,Restoran1E,Restoran2E,RestoranF,Popust1F,Restoran1F,Restoran2F;
	float Popust2F,RestoranG,Popust1G,Popust2G,Restoran1G,Restoran2G,RestoranH,Popust1H,Popust2H,Restoran1H,Restoran2H,RestoranK,Popust1K,Popust2K,Popust3K,Restoran1K,Restoran2K,Restoran3K,RestoranA,RestoranB,RestoranC;
	printf("Unesite jelo za Tarika:");
	scanf("%c", &Tarik);
	scanf("%c", &novi_red);
	printf(" Unesite jelo za Bojana: ");
	scanf("%c", &Bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &Mirza);
	scanf("%c", &novi_red);
	if(Tarik=='H'&& Mirza=='H' && Bojan=='H') {
		Restoran=3*H1;
		Trovac=3*H2;
		Bistro=3*H3;
		Popust1=H1*0.1;
		Restoran1=(Restoran-(3*Popust1));
		
	 if(Trovac<Restoran && Trovac<Bistro && Restoran1<Trovac) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",Trovac);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran1);
	}   else if (Restoran1>Trovac){
			printf("\nNajjeftiniji je Fast-food \"Trovac\" (%.2f KM).",Trovac);
		}
	
 else if (Bistro<Trovac && Bistro<Restoran && Restoran1<Bistro) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",Bistro);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran1); }
		else if (Restoran1>Bistro) {
			printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",Bistro); 
		}
	}
	if(Tarik=='P'&& Mirza=='P' &&Bojan=='P') {
		TrovacA=3*P2;
		RestoranA=3*P1;
		BistroA=3*P3;
		Popust2=P1*0.1;
		Restoran2=RestoranA-3*Popust2; 
			if(RestoranA<TrovacA && RestoranA<BistroA) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",RestoranA);
	}
	else if(TrovacA<RestoranA && TrovacA<BistroA && Restoran2< TrovacA) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacA);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM.)",Restoran2);
	} else if(Restoran2>TrovacA) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacA);
	}
	else if (BistroA<TrovacA && BistroA<RestoranA && Restoran2<BistroA) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroA);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran2);
	} else if(Restoran2>BistroA) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroA); 
	}
}
	if(Tarik=='C' && Mirza=='C' && Bojan=='C') {
		TrovacB=3*C2;
		RestoranB=3*C1;
		BistroB=3*C3;
		Popust3=C3*0.1;
		Restoran3=RestoranB-Popust3; 
			if(RestoranB<TrovacB && RestoranB<BistroB) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",RestoranB);
	}
	else if(TrovacB<RestoranB && TrovacB<BistroB && Restoran3< TrovacB) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacB);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran3);
	} else if(Restoran3>TrovacB) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacB);
	}
	else if (BistroB<TrovacB && BistroB<RestoranB && Restoran3<BistroB) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroB);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran3);
	} else if(Restoran3>BistroB) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroB); 
	}
	}
	if((Tarik=='H' && Mirza=='H' && Bojan=='P')||(Tarik=='H'&& Mirza=='P'&& Bojan=='H')||(Tarik=='P'&& Mirza=='H' && Bojan=='H'))  {
		TrovacC=2*H2+P2;
		RestoranC=2*H1+P1;
		BistroC=2*H3+P3;
		Popust4=H1*0.1;
		Popust5=P1*0.1;
		Restoran4C=RestoranC-2*Popust4;
		Restoran5C=RestoranC-Popust5; 
	if(RestoranC<TrovacC && RestoranC<BistroC) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",RestoranC);
	}
	else if(TrovacC<RestoranC && TrovacC<BistroC && Restoran4C< TrovacC) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacC);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran4C);
  }	else if(TrovacC<RestoranC && TrovacC<BistroC && Restoran5C< TrovacC) {
  	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacC);
  	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran5C);
	} else if (Restoran4C>TrovacC || Restoran5C>TrovacC) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacC);
	}
	else if (BistroC<TrovacC && BistroC<RestoranC && Restoran4C<Bistro) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroC);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran4C); }
		 else if (BistroC<TrovacC && BistroC<RestoranC && Restoran5C<BistroC) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroC);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran5C);
 } else if(Restoran4C>BistroC || Restoran5C>Bistro) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroC);
	} 
	}
	if((Tarik=='H' && Mirza=='H' && Bojan=='C')||(Tarik=='H'&& Mirza=='C'&& Bojan=='H')||(Tarik=='C'&& Mirza=='H'&& Bojan=='H'))  {
		TrovacD=2*H2+C2;
		RestoranD=2*H1+C1;
		BistroD=2*H3+C3;
		Popust6=H1*0.1;
		Popust7=C1*0.1;
	    Restoran6D=RestoranD-2*Popust6;
	    Restoran7D=RestoranD-Popust7; 
	   	if(RestoranD<TrovacD && RestoranD<BistroD) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM)",RestoranD);
	}
	else if(TrovacD<RestoranD && TrovacD<BistroD && Restoran6D< TrovacD) {
		printf("Najjeftiniji je Fast-food \" Trovac\" (%.2f KM).",TrovacD);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran6D);
  }	else if(TrovacD<RestoranD && TrovacD<BistroD && Restoran7D< TrovacD) {
  	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacD);
  	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran7D);
	} else if (Restoran6D>TrovacD || Restoran7D>TrovacD) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacD);
	}
	else if (BistroD<TrovacD && BistroD<RestoranD && Restoran6D<BistroD) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroD);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran6D); }
		 else if (BistroD<TrovacD && BistroD<RestoranD && Restoran7D<BistroD) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroD);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran7D);
 } else if(Restoran6D>BistroD || Restoran7D>BistroD) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroD);
	} 
}
if((Tarik=='P' && Mirza=='P' && Bojan=='H')||(Tarik=='P'&& Mirza=='H'&& Bojan=='P')||(Tarik=='H'&& Mirza=='P' && Bojan=='P'))
{
	TrovacE=2*P2+H2;
	RestoranE=2*P1+H1;
	BistroE=2*P3+H3;
	Popust1E=P1*0.1;
	Popust2E=H1*0.1;
	Restoran1E=RestoranE-2*Popust1E;
	Restoran2E=RestoranE-Popust2E; 
	   	if(RestoranE<TrovacE && RestoranE<BistroE) {
		printf("\nNajjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",RestoranE);
	}
	else if(TrovacE<RestoranE && TrovacE<BistroE && Restoran1E< TrovacE) {
		printf("\nNajjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacE);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran1E);
  }	else if(TrovacE<RestoranE && TrovacE<BistroE && Restoran2E< TrovacE) {
  	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacE);
  	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran2E);
	} else if (Restoran1E>TrovacE || Restoran2E>TrovacE) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacE);
	}
	else if (BistroE<TrovacE && BistroE<RestoranE && Restoran1E<BistroE) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroE);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran1E); }
		 else if (BistroE<TrovacE && BistroE<RestoranE && Restoran2E<BistroE) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroE);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran2E);
 } else if(Restoran1E>BistroE || Restoran2E>BistroE) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroE);
	} 
}

if((Tarik=='P' && Mirza=='P' && Bojan=='C')||(Tarik=='C'&& Mirza=='P'&& Bojan=='P')||(Tarik=='P'&& Mirza=='C'&& Bojan=='P'))
{
	TrovacF=2*P2+C2;
	RestoranF=2*P1+C1;
	BistroF=2*P3+C3;
	Popust1F=P1*0.1;
	Popust2F=C1*0.1;
	Restoran1F=RestoranF-2*Popust1F;
	Restoran2F=RestoranF-Popust2F; 
 	if(RestoranF<TrovacF && RestoranF<BistroF) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",RestoranF);
	}
	else if(TrovacF<RestoranF && TrovacF<BistroF && Restoran1F< TrovacF) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacF);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran1F);
  }	else if(TrovacF<RestoranF && TrovacF<BistroF && Restoran2F< TrovacF) {
  	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacF);
  	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran2F);
	} else if (Restoran1F>TrovacF || Restoran2F>TrovacF) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacF);
	}
	else if (BistroF<TrovacF && BistroF<RestoranF && Restoran1F<BistroF) {
		printf("Najjeftiniji je Bistro \"Lorelei\"(%.2f KM).",BistroF);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran1F); }
		 else if (BistroF<TrovacF && BistroF<RestoranF && Restoran1F<BistroF) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroF);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran1F);
 } else if(Restoran1F>BistroF || Restoran2F>BistroF) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroF);
	} 
}

if((Tarik=='C' && Mirza=='C' && Bojan=='H')||(Tarik=='C'&& Mirza=='H'&& Bojan=='C')||(Tarik=='H'&& Mirza=='C'&& Bojan=='C'))
{
	TrovacG=2*C2+H2;
	RestoranG=2*C1+H1;
	BistroG=2*C3+H3;
	Popust1G=C1*0.1;
	Popust2G=H1*0.1;
	Restoran1G=RestoranG-2*Popust1G;
	Restoran2G=RestoranG-Popust2G; 
		if(RestoranG<TrovacG && RestoranG<BistroG) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",RestoranG);
	}
	else if(TrovacG<RestoranG && TrovacG<BistroG && Restoran1G< TrovacG) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacG);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran1G);
  }	else if(TrovacG<RestoranG && TrovacG<BistroG && Restoran2G< TrovacG) {
  	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM)",TrovacG);
  	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran2G);
	} else if (Restoran1G>TrovacG || Restoran2G>TrovacG) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacG);
	}
	else if (BistroG<TrovacG && BistroG<RestoranG && Restoran1G<BistroG) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroG);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran1G); }
		 else if (BistroG<TrovacG && BistroG<RestoranG && Restoran1G<BistroG) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroG);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran1G);
 } else if(Restoran1G>BistroG || Restoran2G>BistroG) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroG);
	} 
}
if((Tarik=='C' && Mirza=='C' && Bojan=='P')||(Tarik=='C'&& Mirza=='P'&& Bojan=='C')||(Tarik=='P'&& Mirza=='C'&& Bojan=='C'))
{
	TrovacH=2*C2+P2;
	RestoranH=2*C1+P1;
	BistroH=2*C3+P3;
	Popust1H=C1*0.1;
	Popust2H=P1*0.1;
	Restoran1H=RestoranH-2*Popust1H;
	Restoran2H=RestoranH-Popust2H; 
	
	if(RestoranH<TrovacH && RestoranH<BistroH) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",RestoranF);
	}
	else if(TrovacH<RestoranH && TrovacH<BistroH && Restoran1H < TrovacH) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacH);
		if(roundf(TrovacH * 100) / 100 != roundf(Restoran1H * 100) / 100)
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran1H);
  }	else if(TrovacH<RestoranH && TrovacH<BistroH && Restoran2H< TrovacH) {
  	printf("%d %f %f", TrovacH != Restoran2H, TrovacH, Restoran2H);
  	if(roundf(TrovacH * 100) / 100 != roundf(Restoran2H * 100) / 100)
  	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran2H);
	} else if (Restoran1H>TrovacH || Restoran2H>TrovacH) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacH);
	}
	else if (BistroH<TrovacH && BistroH<RestoranH && Restoran1H<BistroH) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroH);
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran1H); }
		 else if (BistroH<TrovacH && BistroH<RestoranH && Restoran1H<BistroH) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM)",BistroH);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran1H);
 } else if(Restoran1H>BistroH || Restoran2H>BistroH) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroH);
	} 
}
if((Tarik=='P' && Mirza=='H' && Bojan=='C')||(Tarik=='P'&& Mirza=='C'&& Bojan=='H')||(Tarik=='H'&& Mirza=='P'&& Bojan=='C')||(Tarik=='H'&& Mirza=='C'&& Bojan=='P')||(Tarik=='C'&& Mirza=='P'&& Bojan=='H')||(Tarik=='C'&& Mirza=='H'&& Bojan=='P'))
{
	TrovacK=P2+H2+C2;
	RestoranK=P1+H1+C1;
	BistroK=P3+H3+C3;
	Popust1K=P1*0.1;
	Popust2K=H1*0.1;
	Popust3K=C1*0.1;
	Restoran1K=RestoranK-Popust1K;
	Restoran2K=RestoranK-Popust2K;
	Restoran3K=RestoranK-Popust3K; 
if(RestoranK<TrovacK && RestoranK<BistroK) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM)",RestoranK);
	}
	else if(TrovacK<RestoranK && TrovacK<BistroK && Restoran1K< TrovacK) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacK);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran1K);
  }	else if(TrovacK<RestoranK && TrovacK<BistroK && Restoran2K< TrovacK) {
  	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacK);
  	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran2K);
  }	else if(TrovacK<RestoranK && TrovacK<BistroK && Restoran3K< TrovacK) {
  	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",TrovacK);
  	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran3K);
	} else if (Restoran1K>TrovacK || Restoran2K>TrovacK || Restoran3K>TrovacK) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM)",TrovacK);
	}
	else if (BistroK<TrovacK && BistroK<RestoranK && Restoran1K<BistroK) {
		printf("Najjeftiniji je Bistro\"Lorelei\"(%.2f KM).",BistroK);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran1K); }
		else if(BistroK<RestoranK && BistroK<TrovacK && Restoran3K< TrovacK) {
  	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",TrovacK);
  	printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran3K);
		 } else if (BistroK<TrovacK && BistroK<RestoranK && Restoran2K<BistroK) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroK);
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Restoran2K);
 } else if(Restoran1K>BistroK || Restoran2K>BistroK || Restoran3K>BistroK) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",BistroK);
 }
}
 return 0;
 } 
