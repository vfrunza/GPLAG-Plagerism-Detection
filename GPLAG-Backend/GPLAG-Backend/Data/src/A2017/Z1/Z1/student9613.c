#include <stdio.h>
#include <stdlib.h>

int main() 
{   
    float min, rest, fast, bist, pr=6.8, pf=8., pb=5.3, hr=3.3, hf=3., hb=5.0, cr=5.0, cf=3.9, cb=6.;
    char t, b, m, novi_red;
    
    printf("Unesite jelo za Tarika: ");
    scanf("%c", &t);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Bojana: ");
    scanf("%c", &b);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c", &m);
    scanf("%c", &novi_red);
    
    if(t=='H' && b=='H' && m=='H')
    {
     rest=3*hr;
     min=rest;
     fast=3*hf;
     if(fast<min)
     min=fast;
     bist=3*hb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", min, rest-0.1*rest);
    }
    
    if(t=='H' && b=='H' && m=='P')
    {
     rest=2*hr+pr;
     min=rest;
     fast=2*hf+pf;
     if(fast<min)
     min=fast;
     bist=2*hb+pb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", min);
    }
    
    if(t=='H' && b=='P' && m=='H')
    {
     rest=2*hr+pr;
     min=rest;
     fast=2*hf+pf;
     if(fast<min)
     min=fast;
     bist=2*hb+pb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", min);
    }
    
    if(t=='H' && b=='P' && m=='P')
    {
     rest=2*pr+hr;
     min=rest;
     fast=2*pf+hf;
     if(fast<min)
     min=fast;
     bist=2*pb+hb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", min, rest-0.2*pr);
    }
    
    if(t=='P' && b=='H' && m=='H')
    {
     rest=2*hr+pr;
     min=rest;
     fast=2*hf+pf;
     if(fast<min)
     min=fast;
     bist=2*hb+pb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", min);
    }
    
    if(t=='P' && b=='H' && m=='P')
    {
     rest=2*pr+hr;
     min=rest;
     fast=2*pf+hf;
     if(fast<min)
     min=fast;
     bist=2*pb+hb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", min, rest-0.2*pr);
    }
    
    if(t=='P' && b=='P' && m=='H')
    {
     rest=2*pr+hr;
     min=rest;
     fast=2*pf+hf;
     if(fast<min)
     min=fast;
     bist=2*pb+hb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", min, rest-0.2*pr);
    }
    
    if(t=='P' && b=='P' && m=='P')
    {
     rest=3*pr;
     min=rest;
     fast=3*pf;
     if(fast<min)
     min=fast;
     bist=3*pb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", min);
    }
    
    if(t=='P' && b=='P' && m=='C')
    {
     rest=2*pr+cr;
     min=rest;
     fast=2*pf+cf;
     if(fast<min)
     min=fast;
     bist=2*pb+cb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", min);
    }
    
    if(t=='P' && b=='C' && m=='P')
    {
     rest=2*pr+cr;
     min=rest;
     fast=2*pf+cf;
     if(fast<min)
     min=fast;
     bist=2*pb+cb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", min);
    }
    
    if(t=='C' && b=='P' && m=='P')
    {
     rest=2*pr+cr;
     min=rest;
     fast=2*pf+cf;
     if(fast<min)
     min=fast;
     bist=2*pb+cb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", min);
    }
    
    if(t=='P' && b=='C' && m=='C')
    {
     rest=2*cr+pr;
     min=rest;
     fast=2*cf+pf;
     if(fast<min)
     min=fast;
     bist=2*cb+pb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", min);
    }
    
    if(t=='C' && b=='P' && m=='C')
    {
     rest=2*cr+pr;
     min=rest;
     fast=2*cf+pf;
     if(fast<min)
     min=fast;
     bist=2*cb+pb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", min);
    }
    
    if(t=='C' && b=='C' && m=='P')
    {
     rest=2*cr+pr;
     min=rest;
     fast=2*cf+pf;
     if(fast<min)
     min=fast;
     bist=2*cb+pb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", min);
    }
    
    if(t=='C' && b=='C' && m=='C')
    {
     rest=3*cr;
     min=rest;
     fast=3*cf;
     if(fast<min)
     min=fast;
     bist=3*cb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", min);
    }
    
    if(t=='C' && b=='C' && m=='H')
    {
     rest=2*cr+hr;
     min=rest;
     fast=2*cf+hf;
     if(fast<min)
     min=fast;
     bist=2*cb+hb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", min);
    }
    
    if(t=='C' && b=='H' && m=='C')
    {
     rest=2*cr+hr;
     min=rest;
     fast=2*cf+hf;
     if(fast<min)
     min=fast;
     bist=2*cb+hb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", min);
    }
    
    if(t=='C' && b=='H' && m=='H')
    {
     rest=2*hr+cr;
     min=rest;
     fast=2*hf+cf;
     if(fast<min)
     min=fast;
     bist=2*hb+cb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", min);
    }
    
    if(t=='H' && b=='C' && m=='C')
    {
     rest=2*cr+hr;
     min=rest;
     fast=2*cf+hf;
     if(fast<min)
     min=fast;
     bist=2*cb+hb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", min);
    }
    
    if(t=='H' && b=='C' && m=='H')
    {
     rest=2*cr+hr;
     min=rest;
     fast=2*cf+hf;
     if(fast<min)
     min=fast;
     bist=2*cb+hb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", min);
    }
    
    if(t=='H' && b=='H' && m=='C')
    {
     rest=2*cr+hr;
     min=rest;
     fast=2*cf+hf;
     if(fast<min)
     min=fast;
     bist=2*cb+hb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", min);
    }
    
    if(t=='C' && b=='H' && m=='P')
    {
     rest=cr+hr+pr;
     min=rest;
     fast=cf+hf+pf;
     if(fast<min)
     min=fast;
     bist=cb+hb+pb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", min, (rest-0.1*pr));
    }
    
    if(t=='C' && b=='P' && m=='H')
    {
     rest=cr+hr+pr;
     min=rest;
     fast=cf+hf+pf;
     if(fast<min)
     min=fast;
     bist=cb+hb+pb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM). Sa popustom bi Restoran bio jeftiniji (%.2f KM).", min, (rest-0.1*pr));
    }
    
    if(t=='P' && b=='H' && m=='C')
    {
     rest=cr+hr+pr;
     min=rest;
     fast=cf+hf+pf;
     if(fast<min)
     min=fast;
     bist=cb+hb+pb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM). Sa popustom bi Restoran bio jeftiniji (%.2f KM).", min, (rest-0.1*pr));
    }
    
    if(t=='P' && b=='C' && m=='H')
    {
     rest=cr+hr+pr;
     min=rest;
     fast=cf+hf+pf;
     if(fast<min)
     min=fast;
     bist=cb+hb+pb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM). Sa popustom bi Restoran bio jeftiniji (%.2f KM).", min, (rest-0.1*pr));
    }
    
    if(t=='H' && b=='C' && m=='P')
    {
     rest=cr+hr+pr;
     min=rest;
     fast=cf+hf+pf;
     if(fast<min)
     min=fast;
     bist=cb+hb+pb;
     if(bist<min)
     min=bist;
     
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM). Sa popustom bi Restoran bio jeftiniji (%.2f KM).", min, (rest-0.1*pr));
    }
    
    if(t=='H' && b=='P' && m=='C')
    {
     rest=cr+hr+pr;
     min=rest;
     fast=cf+hf+pf;
     if(fast<min)
     min=fast;
     bist=cb+hb+pb;
     if(bist<min)
     min=bist;
    
     printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM). Sa popustom bi Restoran bio jeftiniji (%.2f KM).", min, (rest-0.1*pr));
    }
    return 0;
}