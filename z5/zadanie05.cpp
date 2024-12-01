/*
Meno a priezvisko: Boris Pekarčík

POKYNY:
(1)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(2)  Cela implementacia musi byt v tomto jednom subore.
(3)  Odovzdajte len tento zdrojovy subor (s vypracovanymi rieseniami).
(4)  Program musi byt kompilovatelny.
(5)  Globalne a staticke premenne su zakazane.
(6)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
     (nemente nazvy, navratove hodnoty, ani typ a pocet parametrov v zadanych funkciach).
     Nemente implementacie zadanych datovych typov, ani implementacie hotovych pomocnych funkcii
     (ak nie je v zadani ulohy uvedene inak).
(7)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo datove typy.
(8)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo datovych typov).
     Testovaci kod ale nebude hodnoteny.
(9)  Funkcia 'main' musi byt v zdrojovom kode posledna.
*/


#include <iostream>
#include <cstdint>

using namespace std;

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia prida novy prvok do heapu.
    Verzia heap-u je Min-heap (hodnota kazdeho uzla je mensia alebo rovna, ako hodnoty vsetkych jeho nasledovnikov).
    Pouzite algoritmus sift up.

    PARAMETRE:
        [in, out] data - pole, ktoreho prva cast tvori heap, do ktoreho funkcia prida novy prvok
        [in] addIndex - index prvku v 'data', ktory funkcia prida do heap-u (preusporiadanim prvkov)

    VSTUPNE PODMIENKY:
        'data' ukazuje na platne pole s dlzkou minimalne 'addIndex+1'
        'addIndex' moze mat lubovolnu hodnotu
        Prvky data[0]...data[addIndex-1] (vratane) tvoria heap

    VYSTUPNE PODMIENKY:
        Prvky data[0]...data[addIndex] (vratane) tvoria heap
        Funkcia preusporiadala prvky data[0]...data[addIndex] tak, aby tvorili heap

    PRIKLADY:
        vstup:  data = (2, 4, 10, 7, 1, 2, 5, 0, 3, -1, 11, 12, 1), addIndex = 4
        vystup: data = (1, 2, 10, 7, 4, 2, 5, 0, 3, -1, 11, 12, 1)

        vstup:  data = (3, 4, 10, 5, 5, 11, 15, 7, 8, 9, 10, 14,  8, 1, 2), addIndex = 12
        vystup: data = (3, 4,  8, 5, 5, 10, 15, 7, 8, 9, 10, 14, 11, 1, 2)

        vstup:  data = (3, 4, 10, 5), addIndex = 0
        vystup: data = (3, 4, 10, 5)
*/
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void siftDown1(int data[], const size_t topIndex, const size_t length){ //opravujeme strom <start,end)
    size_t ileft = 2*topIndex + 1;
    size_t iright = 2*topIndex + 2;
    size_t iswap = topIndex; //index kde na konci swapmnem

    //ak neni lavy strom konec
    if (ileft >= length){
        return;
    }
    //existuje lavy potomok a ma vacsiu hodnotu ako uzol top?
    if(data[ileft] > data[topIndex]){
        iswap = ileft;
    }
    //existuje pravy potomok v poli a ma vacsiu hodnotu ako uzol top?
    if(iright < length && data[iright] > data[iswap]){
        iswap = iright;
    }

    if (iswap != topIndex){
        swap(&data[topIndex], &data[iswap]);
        siftDown1(data, iswap, length);
    }

}

void buildMaxHeap1(int *data, const size_t len){ //zradime pole cez vlastnost maxheap
    for (size_t i = (len/2)-1; i!= SIZE_MAX; i--){
        siftDown1(data,i,len);
    }
}

void siftUp(int data[], const size_t addIndex)
{
    if (addIndex == 0) { //detsky index
        return; //uz nemozme ist nahor ta konec
    }
    size_t parentIndex = (addIndex - 1) / 2; //zistim index rodica


    if (data[addIndex] < data[parentIndex]) { //parent je vyssie, mussi byt mensi
        swap(data[addIndex], data[parentIndex]);
        siftUp(data, parentIndex); //nase nove dieta je terajsi rodic
    }
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori heap na poli 'data' preusporiadanim prvkov.
    Verzia heap-u je Min-heap.
    Pouzite algoritmus sift up.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia preusporiada, aby bolo heap-om
        [in] length - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'data' ukazuje na platne pole, ak 'length' > 0
        'length' moze mat lubovolnu hodnotu

    VYSTUPNE PODMIENKY:
        'data' je heap-om

    PRIKLAD:
        vstup:  data = (7, 2, 1, 2, 8, 5, 3, 4, 2, 2, 6), length = 11
        vystup: data = (1, 2, 2, 2, 2, 5, 3, 7, 4, 8, 6)
*/
void buildHeapSiftUp(int data[], const size_t length)
{
    for (size_t i = 1; i < length; i++){ //zrob pre cele pole
        siftUp(data, i);
    }
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia opravi cast heap-u (podstrom, ktoreho koren ma index 'topIndex').
    Verzia heap-u je Min-heap.
    Pouzite algoritmus sift down.

    PARAMETRE:
        [in, out] data - pole, v ktorom funkcia opravi cast heapu preusporiadanim prvkov
        [in] topIndex - index korena podstromu (casti heapu), ktory sa ma opravit
        [in] length - pocet prvkov pola

    VSTUPNE PODMIENKY:
        Podstromy prvku s indexom 'topIndex' splnaju podmienky heap (podstromy, ktorych korene su priamy nasledovnici uzla s indexom 'topIndex').
        'data' ukazuje na platne pole
        'topIndex' moze mat lubovolnu hodnotu
        'length' moze mat lubovolnu hodnotu

    VYSTUPNE PODMIENKY:
        Podstrom, ktoreho koren ma index 'topIndex', splna podmienku heap.

    PRIKLADY:
        vstup:  data = (55, 20, 10, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140), topIndex = 0, length = 15
        vystup: data = (10, 20, 50, 30, 40, 55, 60, 70, 80, 90, 100, 110, 120, 130, 140)

        vstup:  data = (100, 8, 2, 1, 0, 5, 6, 7, 4, 2, 3, 11, 12, 13, 14, 15, 16, 17), topIndex = 1, length = 18
        vystup: data = (100, 0, 2, 1, 2, 5, 6, 7, 4, 8, 3, 11, 12, 13, 14, 15, 16, 17)
*/
void siftDown(int data[], const size_t topIndex, const size_t length)
{
    size_t ileft = 2*topIndex + 1;
    size_t iright = 2*topIndex + 2;
    size_t iswap = topIndex; //index kde na konci swapmnem

    //ak neni lavy strom konec
    if (ileft >= length){
        return;
    }
    //existuje lavy potomok a ma vacsiu hodnotu ako uzol top?
    if(data[ileft] < data[topIndex]){
        iswap = ileft;
    }
    //existuje pravy potomok v poli a ma vacsiu hodnotu ako uzol top?
    if(iright < length && data[iright] < data[iswap]){
        iswap = iright;
    }

    if (iswap != topIndex){
        swap(&data[topIndex], &data[iswap]);
        siftDown(data, iswap, length);
    }

}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori heap na poli 'data' preusporiadanim prvkov.
    Verzia heap-u je Min-heap.
    Pouzite algoritmus sift down.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia preusporiada, aby bolo heap-om
        [in] length - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'data' ukazuje na platne pole, ak 'length' > 0
        'length' moze mat lubovolnu hodnotu

    VYSTUPNE PODMIENKY:
        'data' je heap-om

    PRIKLAD:
        vstup:  data = (7, 2, 1, 2, 8, 5, 3, 4, 2, 2, 6), length = 11
        vystup: data = (1, 2, 3, 2, 2, 5, 7, 4, 2, 8, 6)
*/
void buildHeapSiftDown(int data[], const size_t length)
{
    for (size_t i = (length/2)-1; i!= SIZE_MAX; i--){
        siftDown(data,i,length);
    }
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia preusporiada pole 'data' od najvacsieho prvku po najmensi.
    Pouzite algoritmus heap sort.

    PARAMETRE:
        [in,out] data - pole, ktore funkcia usporiada
        [in] length - dlzka pola

    VSTUPNE PODMIENKY:
        'data' ukazuje na platne pole, ak 'length' > 0
        'length' moze mat lubovolnu hodnotu

    VYSTUPNE PODMIENKY:
        Pole 'data' je usporiadane

    PRIKLAD:
        vstup:  data = (7, 2, 1, 2, 8, 5, 3, 4, 2, 2, 6), length = 11
        vystup: data = (8, 7, 6, 5, 4, 3, 2, 2, 2, 2, 1)
*/
void heapSort(int data[], const size_t length)
{
    if (length == 0) {
        return;
    }
    // Krok 1: Vytvoríme min-heap pre celé pole
    buildHeapSiftDown(data, length);

    // Krok 2: Postupne presunieme najmenší prvok na koniec a opravíme min-heap
    for (size_t i = length - 1; i > 0; i--) {
        // Vymeníme koreň (najmenší prvok) s posledným prvkom v aktuálnom rozsahu
        swap(&data[0], &data[i]);

        // Aplikujeme siftDown na zmenšený rozsah, aby sme opravili min-heap
        siftDown(data, 0, i);
    }
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne testovacie funkcie a struktury

int main() {

    // tu mozete doplnit testovaci kod

    return 0;
}