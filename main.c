#include <stdio.h>
#include <stdlib.h>

// Eklemeli sıralama algoritması
void insertionSort(int dizi[], int n) {
    int i, anahtar, j;

    for (i = 1; i < n; i++) {
        anahtar = dizi[i];
        j = i - 1;

        while (j >= 0 && dizi[j] > anahtar) {
            dizi[j + 1] = dizi[j];
            j = j - 1;
        }

        dizi[j + 1] = anahtar;
    }
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
    int n = sizeof(dizi) / sizeof(dizi[0]);
    insertionSort(dizi, n);

    // Binary search ile 24 sayısının index'ini bul ve yazdır
    int bul = 24;
    int sonuc = binarySearch(dizi, 0, boyut - 1, bul);
    if (sonuc == -1)
        printf("Hedef sayi dizide yok");
    else
        printf("Hedef sayinin indexi: %d", sonuc);
    return 0;
}
