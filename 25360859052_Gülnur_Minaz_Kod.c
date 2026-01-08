#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Sabitler
#define PI 3.14159265359
#define GEZEGEN_SAYISI 8

void serbest_dusme_deneyi(float *g_dizisi, char *isimler[]);
void yukari_atis_deneyi(float *g_dizisi, char *isimler[]);
void agirlik_deneyi(float *g_dizisi, char *isimler[]);
void kutlecekimsel_potansiyel_enerji_deneyi(float *g_dizisi, char *isimler[]);
void hidrostatik_basinc_deneyi(float *g_dizisi, char *isimler[]);
void arsimet_kaldirma_kuvveti_deneyi(float *g_dizisi, char *isimler[]);
void basit_sarkac_periyodu_deneyi(float *g_dizisi, char *isimler[]);
void sabit_ip_gerilmesi_deneyi(float *g_dizisi, char *isimler[]);
void asansor_deneyi(float *g_dizisi, char *isimler[]);

int main() {
//Gezegen sırası: Merkür, Venüs, Dünya, Mars, Jüpiter, Satürn, Uranüs, Neptün
char *gezegen_isimleri[]={"Merkur","Venus","Dunya", "Mars", "Jupiter", "Saturn", "Uranus", "Neptun"};
float yercekimi[]={3.7, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69};

char bilim_insani[50];
int secim=0;
char temizle;
printf("-----Uzay Simülasyon Uygulaması-----\n");
printf("Bilim insaninin adini giriniz:");
scanf("%s", bilim_insani);
while (getchar()!='\n');

while(1) {
    printf("\n---Deneyler---\n");
    printf("1. Serbest Dusme Deneyi\n2. Yukari Atis Deneyi\n3. Agirlik Deneyi\n");
    printf("4. Kutlecekimsel Potansiyel Enerji Deneyi\n5. Hidrostatik Basinc Deneyi\n6. Arsimet Kaldırma Kuvveti Deneyi\n");
    printf("7. Basit Sarkac Deney\n8. Sabit İp Gerilmesi Deneyi\n9. Asansör Deneyi\n");
    printf("Cikis icin -1'e basiniz\n");
    printf("Bilim insani %s yapmak istediginiz deneyi seciniz. \n", bilim_insani);
    printf("\nSeciminiz:\n");
    if(scanf("%d",&secim)!=1){
        printf("Hata:Sadece tam sayi giriniz.\n");
        while((temizle=getchar())!= '\n'&& temizle!=EOF);
        continue;
    }
    if (secim == -1){
    printf("Cikis yapiliyor."); 
      break;
    }
    switch(secim){
        case 1: serbest_dusme_deneyi(yercekimi, gezegen_isimleri);
        break;
        case 2: yukari_atis_deneyi(yercekimi, gezegen_isimleri);
        break;
        case 3: agirlik_deneyi(yercekimi, gezegen_isimleri);
        break;
        case 4: kutlecekimsel_potansiyel_enerji_deneyi(yercekimi, gezegen_isimleri);
        break;
        case 5: hidrostatik_basinc_deneyi(yercekimi, gezegen_isimleri);
        break;
        case 6: arsimet_kaldirma_kuvveti_deneyi(yercekimi, gezegen_isimleri);
        break;
        case 7: basit_sarkac_periyodu_deneyi(yercekimi, gezegen_isimleri);
        break;
        case 8: sabit_ip_gerilmesi_deneyi(yercekimi, gezegen_isimleri);
        break;
        case 9: asansor_deneyi(yercekimi, gezegen_isimleri);
        break;
        default: printf("Gecersiz secim! Tekrar Deneyiniz.\n");

    }

}
printf("Uygulama sonlandirildi.\n");
return 0;
}
//Fonksiyonlar
void serbest_dusme_deneyi(float *g_ptr, char *isimler[]) {
    float h, t;
    printf("Sureyi (s) giriniz:");
    scanf("%f", &t);
    t= (t>0)? t: -t;
    //Negatif süre girildiyse ternary ile mutlak değerine dönüşür
    
    for(int i=0; i<GEZEGEN_SAYISI; i++){
        h=0.5* (*(g_ptr+i))*pow(t,2);
        printf("%s:Kat ettigi yol h= %.2f metre\n", isimler[i],h);
    }
}

void yukari_atis_deneyi(float *g_ptr, char *isimler[]) {
    float hmax,v0;
    printf("Ilk hizi (m/s) giriniz:");
    scanf("%f", &v0);
    v0 = (v0<0)? -v0: v0;

    for(int i=0; i<GEZEGEN_SAYISI; i++){
        hmax=pow(v0,2)/(2* (*(g_ptr+i)));
        printf("%s:Maksimum Yukseklik hmax=%.2f metre\n", isimler[i], hmax);
    }
}
void agirlik_deneyi(float *g_ptr, char*isimler[]){
    float m,G;
    printf("Kutleyi (kg) giriniz:");
    scanf("%f", &m);
    m=(m<0)? -m: m;

    for(int i=0; i<GEZEGEN_SAYISI;i++){
        G=m* (*(g_ptr+i));
        printf("%s: Agirlik G= %.2f Newton\n", isimler[i], G);
    }
}
void kutlecekimsel_potansiyel_enerji_deneyi(float *g_ptr, char*isimler[]){
    float Ep, m, h;
    printf("Kutleyi (kg) giriniz:");
    scanf("%f", &m);
    printf("Yuksekligi (m) giriniz:");
    scanf("%f", &h);
    m=(m<0)? -m : m;
    h=(h<0)? -h : h;

    for(int i=0; i<GEZEGEN_SAYISI; i++) {
        Ep=m* (*(g_ptr +i)) *h;
        printf("%s: Kutle Potansiyel Enerji Ep = %.2f joule\n", isimler[i], Ep);
    }
}
void hidrostatik_basinc_deneyi(float *g_ptr, char*isimler[]){
    float P, h, rho;
    printf("Sivi yogunlugunu (kg/m3) giriniz:");
    scanf("%f", &rho);
    printf("Derinligi giriniz(m):");
    scanf("%f",&h);
    rho=(rho<0) ? -rho : rho;
    h=(h<0) ? -h : h;

    for(int i=0; i<GEZEGEN_SAYISI; i++){
        P= rho* (*(g_ptr+i)) *h;
        printf("%s: Hidrostatik Basinc P= %.2f Pascal\n", isimler[i], P);
    }
}
void arsimet_kaldirma_kuvveti_deneyi(float *g_ptr, char *isimler[]){
    float rho, v, Fk;
    printf("Sivi yogunlugunu (kg/m3) giriniz:");
    scanf("%f", &rho);
    printf("Batan hacmi(m3) giriniz:");
    scanf("%f", &v);
    rho=(rho<0) ? -rho : rho;
    v=(v<0) ? -v : v;

    for(int i=0; i<GEZEGEN_SAYISI; i++){
        Fk=rho* (*(g_ptr +i)) *v;
        printf("%s: Arsimet Kaldirma Kuvveti Fk = %.2f Newton\n", isimler[i], Fk);
    }
}
void basit_sarkac_periyodu_deneyi(float *g_ptr, char*isimler[]) {
    float L,T;
    printf("Sarkac uzunlugunu giriniz:");
    scanf("%f", &L);
    L=(L<0) ? -L : L;

    for(int i=0; i<GEZEGEN_SAYISI; i++){
        T=2*PI*sqrt(L/ (*(g_ptr+i)));
        printf("%s: Periyot T =%.2f saniye\n", isimler[i], T);
    }
}
void sabit_ip_gerilmesi_deneyi(float *g_ptr, char*isimler[]){
    float m, T_ip;
    printf("Kutleyi (kg) giriniz:");
    scanf("%f", &m);
    m= (m<0) ? -m : m;

    for(int i=0; i<GEZEGEN_SAYISI; i++){
        T_ip= m* (*(g_ptr+i));
        printf("%s: Ip Gerilmesi T= %.2f Newton\n", isimler[i], T_ip);
        
    }
}
 void asansor_deneyi(float *g_ptr, char*isimler[]){
    float m, a, N;
    int yon;
    printf("Kutleyi (kg) giriniz:");
    scanf("%f", &m);
    printf("Asansor ivmesini (m/s2) giriniz:");
    scanf("%f", &a);
    m=(m<0) ? -m : m;
    a= (a<0) ? -a: a;

    printf("Yon seciniz: \n1.Yukari hizlanan ya da Asagi yavaslayan\n2.Asagi hizlanan ya da Yukari yavaslayan\n ");
    scanf("%d", &yon);

    for (int i=0; i<GEZEGEN_SAYISI;i++){
        if (yon==1)
           N=m * ((*(g_ptr +i))+a);
        else
        N=m* ((*(g_ptr+i)) -a);

        printf("%s:Gorunur Agirlik N=%.2f Newton\n", isimler[i], N);
    
        
    }
 }