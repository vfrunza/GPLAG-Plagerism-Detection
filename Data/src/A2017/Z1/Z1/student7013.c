#include <stdio.h>

int main()
{
	char t,m,b,nr;
	double pRestoran,hRestoran,cRestoran,pTrovac,hTrovac,cTrovac,pBistro,hBistro,cBistro;
	double PPPrestoran,HHHrestoran,CCCrestoran,PPCrestoran,PPHrestoran,HHCrestoran,HHPrestoran,CCPrestoran,CCHrestoran,PHCrestoran;
	double PPPfastfood,HHHfastfood,CCCfastfood,PPCfastfood,PPHfastfood,HHCfastfood,HHPfastfood,CCPfastfood,CCHfastfood,PHCfastfood;
	double PPPbistro,HHHbistro,CCCbistro,PPCbistro,PPHbistro,HHCbistro,HHPbistro,CCPbistro,CCHbistro,PHCbistro;
	double popustPPP,popustHHH,popustCCC,popustPPC,popustPPH,popustHHC,popustHHP,popustCCP,popustCCH,popustPHC;
	pRestoran=6.80;
	hRestoran=3.30;
	cRestoran=5.00;
	pTrovac=8.00;
	hTrovac=3.00;
	cTrovac=3.90;
	pBistro=5.30;
	hBistro=5.00;
	cBistro=6.00;
	PPPrestoran=3*pRestoran;
	PPPfastfood=3*pTrovac;
	PPPbistro=3*pBistro;
	popustPPP=3*(pRestoran*0.9);
	HHHrestoran=3*hRestoran;
	HHHfastfood=3*hTrovac;
	HHHbistro=3*hBistro;
	popustHHH=3*(hRestoran*0.9);
	CCCrestoran=3*cRestoran;
	CCCfastfood=3*cTrovac;
	CCCbistro=3*cBistro;
	popustCCC=3*(cRestoran*0.9);
	PPCrestoran=2*pRestoran+cRestoran;
	PPCfastfood=2*pTrovac+cTrovac;
	PPCbistro=2*pBistro+cBistro;
	if ((2*(pRestoran*0.9)+cRestoran)<(2*pRestoran+(cRestoran*0.9))) popustPPC=2*(pRestoran*0.9)+cRestoran;
	else popustPPC=2*pRestoran+(cRestoran*0.9);
	PPHrestoran=2*pRestoran+hRestoran;
	PPHfastfood=2*pTrovac+hTrovac;
	PPHbistro=2*pBistro+hBistro;
	if ((2*(pRestoran*0.9)+hRestoran)<(2*pRestoran+(hRestoran*0.9))) popustPPH=2*(pRestoran*0.9)+hRestoran;
	else popustPPH=2*pRestoran+(hRestoran*0.9);
	HHCrestoran=2*hRestoran+cRestoran;
	HHCfastfood=2*hTrovac+cTrovac;
	HHCbistro=2*hBistro+cBistro;
	if ((2*(hRestoran*0.9)+cRestoran)<(2*hRestoran+(cRestoran*0.9))) popustHHC=2*(hRestoran*0.9)+cRestoran;
	else popustHHC=2*hRestoran+(cRestoran*0.9);
	HHPrestoran=2*hRestoran+pRestoran;
	HHPfastfood=2*hTrovac+pTrovac;
	HHPbistro=2*hBistro+pBistro;
	if ((2*(hRestoran*0.9)+pRestoran)<(2*hRestoran+(pRestoran*0.9))) popustHHP=2*(hRestoran*0.9)+pRestoran;
	else popustHHP=2*hRestoran+(pRestoran*0.9);
	CCPrestoran=2*cRestoran+pRestoran;
	CCPfastfood=2*cTrovac+pTrovac;
	CCPbistro=2*cBistro+pBistro;
	if ((2*(cRestoran*0.9)+pRestoran)<(2*cRestoran+(pRestoran*0.9))) popustCCP=2*(cRestoran*0.9)+pRestoran;
	else popustCCP=2*cRestoran+(pRestoran*0.9);
	CCHrestoran=2*cRestoran+hRestoran;
	CCHfastfood=2*cTrovac+hTrovac;
	CCHbistro=2*cBistro+hBistro;
	if ((2*(cRestoran*0.9)+hRestoran)<(2*cRestoran+(hRestoran*0.9))) popustCCH=2*(cRestoran*0.9)+hRestoran;
	else popustCCH=2*cRestoran+(hRestoran*0.9);
	PHCrestoran=pRestoran+cRestoran+hRestoran;
	PHCfastfood=pTrovac+hTrovac+cTrovac;
	PHCbistro=pBistro+hBistro+cBistro;
	if (((0.9*pRestoran)+cRestoran+hRestoran)<((0.9*cRestoran)+pRestoran+hRestoran) && ((0.9*pRestoran)+cRestoran+hRestoran)<((0.9*hRestoran)+pRestoran+cRestoran)){
		popustPHC=((0.9*pRestoran)+cRestoran+hRestoran);
	} else if(((0.9*cRestoran)+pRestoran+hRestoran)<((0.9*pRestoran)+cRestoran+hRestoran) && ((0.9*cRestoran)+pRestoran+hRestoran)<((0.9*hRestoran)+pRestoran+cRestoran)){
		popustPHC=((0.9*cRestoran)+pRestoran+hRestoran);
	}	else popustPHC=((0.9*hRestoran)+pRestoran+cRestoran);
			printf("Unesite jelo za Tarika: ");
			scanf("%c",&t);
			scanf("%c",&nr);
			printf("Unesite jelo za Bojana: ");
			scanf("%c",&b);
			scanf("%c",&nr);
			printf("Unesite jelo za Mirzu: ");
			scanf("%c",&m);
			scanf("%c",&nr);
			if (t==b && m==t) {
				if(t=='P') {
						if(PPPfastfood<PPPrestoran && PPPfastfood<PPPbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",PPPfastfood);
						if(PPPbistro<PPPrestoran && PPPbistro<PPPfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",PPPbistro);
						if(PPPrestoran<PPPbistro && PPPrestoran<PPPfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",PPPrestoran);
						else if(popustPPP<PPPbistro && popustPPP<PPPfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustPPP);
					}
					if(t=='H') {
						if(HHHfastfood<HHHrestoran && HHHfastfood<HHHbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",HHHfastfood);
						if(HHHbistro<HHHrestoran && HHHbistro<HHHfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",HHHbistro);
						if(HHHrestoran<HHHbistro && HHHrestoran<HHHfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",HHHrestoran);
						else if(popustHHH<HHHbistro && popustHHH<HHHfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustHHH);
					}
					if(t=='C') {
						if(CCCfastfood<CCCrestoran && CCCfastfood<CCCbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",CCCfastfood);
						if(CCCbistro<CCCrestoran && CCCbistro<CCCfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",CCCbistro);
						if(CCCrestoran<CCCbistro && CCCrestoran<CCCfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",CCCrestoran);
						else if(popustCCC<CCCbistro && popustCCC<CCCfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustCCC);
					}
				}
	if (t==b && t!=m && b!=m) {
	if (t=='P') {
			if(m=='C') {
				if(PPCfastfood<PPCrestoran && PPCfastfood<PPCbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",PPCfastfood);
				if(PPCbistro<PPCrestoran && PPCbistro<PPCfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",PPCbistro);
				if(PPCrestoran<PPCbistro && PPCrestoran<PPCfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",PPCrestoran);
				else if(popustPPC<PPCbistro && popustPPC<PPCfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustPPC);
			}
			if(m=='H') {
				if(PPHfastfood<PPHrestoran && PPHfastfood<PPHbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",PPHfastfood);
				if(PPHbistro<PPHrestoran && PPHbistro<PPHfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",PPHbistro);
				if(PPHrestoran<PPHbistro && PPHrestoran<PPHfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",PPHrestoran);
				else if(popustPPH<PPHbistro && popustPPH<PPHfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustPPH);
			}
		}
		if (t=='H') {
			if(m=='C') {
				if(HHCfastfood<HHCrestoran && HHCfastfood<HHCbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",HHCfastfood);
				if(HHCbistro<HHCrestoran && HHCbistro<HHCfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",HHCbistro);
				if(HHCrestoran<HHCbistro && HHCrestoran<HHCfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",HHCrestoran);
				else if(popustHHC<HHCbistro && popustHHC<HHCfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustHHC);
			}
			if(m=='P') {
				if(HHPfastfood<HHPrestoran && HHPfastfood<HHPbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",HHPfastfood);
				if(HHPbistro<HHPrestoran && HHPbistro<HHPfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",HHPbistro);
				if(HHPrestoran<HHPbistro && HHPrestoran<HHPfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",HHPrestoran);
				else if(popustHHP<HHPbistro && popustHHP<HHPfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustHHP);
			}
		}
		if (t=='C') {
			if(m=='H') {
				if(CCHfastfood<CCHrestoran && CCHfastfood<CCHbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",CCHfastfood);
				if(CCHbistro<CCHrestoran && CCHbistro<CCHfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",CCHbistro);
				if(CCHrestoran<CCHbistro && CCHrestoran<CCHfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",CCHrestoran);
				else if(popustCCH<CCHbistro && popustCCH<CCHfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustCCH);
			}
			if(m=='P') {
				if(CCPfastfood<CCPrestoran && CCPfastfood<CCPbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",CCPfastfood);
				if(CCPbistro<CCPrestoran && CCPbistro<CCPfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",CCPbistro);
				if(CCPrestoran<CCPbistro && CCPrestoran<CCPfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",CCPrestoran);
				else if(popustCCP<CCPbistro && popustCCP<CCPfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustCCP);
			}
		}
	}
	if (t==m && t!=b && b!=m) {
	if (t=='P') {
			if(b=='C') {
				if(PPCfastfood<PPCrestoran && PPCfastfood<PPCbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",PPCfastfood);
				if(PPCbistro<PPCrestoran && PPCbistro<PPCfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",PPCbistro);
				if(PPCrestoran<PPCbistro && PPCrestoran<PPCfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",PPCrestoran);
				else if(popustPPC<PPCbistro && popustPPC<PPCfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustPPC);
			}
			if(b=='H') {
				if(PPHfastfood<PPHrestoran && PPHfastfood<PPHbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",PPHfastfood);
				if(PPHbistro<PPHrestoran && PPHbistro<PPHfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",PPHbistro);
				if(PPHrestoran<PPHbistro && PPHrestoran<PPHfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",PPHrestoran);
				else if(popustPPH<PPHbistro && popustPPH<PPHfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustPPH);
			}
		}
		if (t=='H') {
			if(b=='C') {
				if(HHCfastfood<HHCrestoran && HHCfastfood<HHCbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",HHCfastfood);
				if(HHCbistro<HHCrestoran && HHCbistro<HHCfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",HHCbistro);
				if(HHCrestoran<HHCbistro && HHCrestoran<HHCfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",HHCrestoran);
				else if(popustHHC<HHCbistro && popustHHC<HHCfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustHHC);
			}
			if(b=='P') {
				if(HHPfastfood<HHPrestoran && HHPfastfood<HHPbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",HHPfastfood);
				if(HHPbistro<HHPrestoran && HHPbistro<HHPfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",HHPbistro);
				if(HHPrestoran<HHPbistro && HHPrestoran<HHPfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",HHPrestoran);
				else if(popustHHP<HHPbistro && popustHHP<HHPfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustHHP);
			}
		}
		if (t=='C') {
			if(b=='H') {
				if(CCHfastfood<CCHrestoran && CCHfastfood<CCHbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",CCHfastfood);
				if(CCHbistro<CCHrestoran && CCHbistro<CCHfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",CCHbistro);
				if(CCHrestoran<CCHbistro && CCHrestoran<CCHfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",CCHrestoran);
				else if(popustCCH<CCHbistro && popustCCH<CCHfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustCCH);
			}
			if(b=='P') {
				if(CCPfastfood<CCPrestoran && CCPfastfood<CCPbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",CCPfastfood);
				if(CCPbistro<CCPrestoran && CCPbistro<CCPfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",CCPbistro);
				if(CCPrestoran<CCPbistro && CCPrestoran<CCPfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",CCPrestoran);
				else if(popustCCP<CCPbistro && popustCCP<CCPfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustCCP);
			}
		}
	}
	if (b==m && t!=b && t!=m) {
	if (b=='P') {
			if(t=='C') {
				if(PPCfastfood<PPCrestoran && PPCfastfood<PPCbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",PPCfastfood);
				if(PPCbistro<PPCrestoran && PPCbistro<PPCfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",PPCbistro);
				if(PPCrestoran<PPCbistro && PPCrestoran<PPCfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",PPCrestoran);
				else if(popustPPC<PPCbistro && popustPPC<PPCfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustPPC);
			}
			if(t=='H') {
				if(PPHfastfood<PPHrestoran && PPHfastfood<PPHbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",PPHfastfood);
				if(PPHbistro<PPHrestoran && PPHbistro<PPHfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",PPHbistro);
				if(PPHrestoran<PPHbistro && PPHrestoran<PPHfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",PPHrestoran);
				else if(popustPPH<PPHbistro && popustPPH<PPHfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustPPH);
			}
		}
		if (b=='H') {
			if(t=='C') {
				if(HHCfastfood<HHCrestoran && HHCfastfood<HHCbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",HHCfastfood);
				if(HHCbistro<HHCrestoran && HHCbistro<HHCfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",HHCbistro);
				if(HHCrestoran<HHCbistro && HHCrestoran<HHCfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",HHCrestoran);
				else if(popustHHC<HHCbistro && popustHHC<HHCfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustHHC);
			}
			if(t=='P') {
				if(HHPfastfood<HHPrestoran && HHPfastfood<HHPbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",HHPfastfood);
				if(HHPbistro<HHPrestoran && HHPbistro<HHPfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",HHPbistro);
				if(HHPrestoran<HHPbistro && HHPrestoran<HHPfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",HHPrestoran);
				else if(popustHHP<HHPbistro && popustHHP<HHPfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustHHP);
			}
		}
		if (b=='C') {
			if(t=='H') {
				if(CCHfastfood<CCHrestoran && CCHfastfood<CCHbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",CCHfastfood);
				if(CCHbistro<CCHrestoran && CCHbistro<CCHfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",CCHbistro);
				if(CCHrestoran<CCHbistro && CCHrestoran<CCHfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",CCHrestoran);
				else if(popustCCH<CCHbistro && popustCCH<CCHfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustCCH);
			}
			if(t=='P') {
				if(CCPfastfood<CCPrestoran && CCPfastfood<CCPbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",CCPfastfood);
				if(CCPbistro<CCPrestoran && CCPbistro<CCPfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",CCPbistro);
				if(CCPrestoran<CCPbistro && CCPrestoran<CCPfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",CCPrestoran);
				else if(popustCCP<CCPbistro && popustCCP<CCPfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustCCP);
			}
		}
	}
	if (b!=m && b!=t && t!=m) {
	if(PHCfastfood<PHCrestoran && PHCfastfood<PHCbistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",PHCfastfood);
		if(PHCbistro<PHCrestoran && PHCbistro<PHCfastfood) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",PHCbistro);
		if(PHCrestoran<PHCbistro && PHCrestoran<PHCfastfood) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",PHCrestoran);
		else if(popustPHC<PHCbistro && popustPHC<PHCfastfood) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popustPHC);
	}

	return 0;
}
