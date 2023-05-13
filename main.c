#include <stdio.h>
#include <stdlib.h>

// Karşılaştırma fonksiyonu
int karsilastir(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Binary search algoritması
int binarySearch(int dizi[], int sol, int sag, int hedef) {
    while (sol <= sag) {
        int orta = sol + (sag - sol) / 2;

        // Hedef sayı ortada ise
        if (dizi[orta] == hedef)
            return orta;

        // Hedef sayı ortada değilse, sol veya sağ yarı diziyi kontrol et
        if (dizi[orta] < hedef)
            sol = orta + 1;
        else
            sag = orta - 1;
    }

    // Hedef sayı dizide yoksa -1 döndür
    return -1;
}

int main() {
    int dizi[] = {4, 8, 3, 84, 47, 76, 9, 24, 68};
    int boyut = sizeof(dizi) / sizeof(dizi[0]);

    // Diziyi sırala
    qsort(dizi, boyut, sizeof(int), karsilastir);

    // Binary search ile 24 sayısının index'ini bul
    int bul = 24;
    int sonuc = binarySearch(dizi, 0, boyut - 1, bul);
    if (sonuc == -1)
        printf("Hedef sayi dizide yok");
    else
        printf("Hedef sayinin indexi: %d", sonuc);
    return 0;
}
