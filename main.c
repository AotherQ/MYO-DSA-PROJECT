//Ahmet Umut Doğan
//2420161014
//https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=GoDfm1pGww


#include <stdio.h>


void listeyi_goster(int liste[], int uzunluk) {
    for (int i = 0; i < uzunluk; i++) {
        printf("%d ", liste[i]);
    }
    printf("\n");
}
void yer_degistir(int *sayi1, int *sayi2) {
    int depo = *sayi1;
    *sayi1 = *sayi2;
    *sayi2 = depo;
}

void listeyi_sirala(int liste[], int adet) {
    int i, j;
    int degisim_oldu_mu;

    for (i = 0; i < adet - 1; i++) {
        degisim_oldu_mu = 0; 

        for (j = 0; j < adet - i - 1; j++) {
            if (liste[j] > liste[j + 1]) {
                yer_degistir(&liste[j], &liste[j + 1]);
                degisim_oldu_mu = 1;
            }
        }

        if (degisim_oldu_mu == 0) break;

        printf("Adim %d: ", i + 1);
        listeyi_goster(liste, adet);
    }
}

int hizli_ara(int liste[], int bas, int son, int hedef) {
    while (bas <= son) {
        int orta = bas + (son - bas) / 2;

        if (liste[orta] == hedef)
            return orta;
        if (liste[orta] < hedef)
            bas = orta + 1;
        else
            son = orta - 1;
    }
    return -1;
}

int main() {
    int sayilar[] = {60, 61, 55, 53, 8, 5, 19, 57, 52, 67, 74, 1};
    int eleman_sayisi = sizeof(sayilar) / sizeof(sayilar[0]);
    int aranan, konum;

    printf("--- Karisik Liste ---\n");
    listeyi_goster(sayilar, eleman_sayisi);
    printf("---------------------\n\n");

    printf("Siralama islemi baslatiliyor...\n");
    listeyi_sirala(sayilar, eleman_sayisi);
    
    printf("\nSiralanmis Son Liste:\n");
    listeyi_goster(sayilar, eleman_sayisi);

    printf("\nBulmak istediginiz sayiyi yazin: ");
    if (scanf("%d", &aranan) == 1) {
        konum = hizli_ara(sayilar, 0, eleman_sayisi - 1, aranan);

        if (konum != -1)
            printf("Buldum! %d sayisi dizinin %d. sirasinda (indis) duruyor.\n", aranan, konum);
        else
            printf("Maalesef, %d sayisi bu listede mevcut degil.\n", aranan);
    }

    return 0;
}