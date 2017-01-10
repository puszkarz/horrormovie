#ifndef HORRORMOVIE_SMALLTOWN_H
#define HORRORMOVIE_SMALLTOWN_H

#include "helper.h"

//Klasa SmallTown tworzona za pomocą klasy Builder, dla której można ustawić co
//        najmniej:
//* potwora, który atakuje miasto,
//* czas startowy t0 typu Time,
//* czas maksymalny t1 typu Time,
//* obywateli miasteczka.
//
//Klasa SmallTown ma metody publiczne:
//        Status getStatus() – zwraca nazwę typu potwora, liczbę jego punktów życia oraz
//liczbę pozostałych przy życiu mieszkańców;
//void tick(Time timeStep) – na początku sprawdza aktualny czas; jeśli jest to czas
//ataku, to następuje atak na wszystkich mieszkańców; na koniec czas w miasteczku
//        przesuwa się o timeStep.
//
//SmallTown operuje zgodnie z wewnętrznym zegarem. Czas liczony jest w godzinach,
//od godziny 0 do godziny t1 i potem znów od godziny 0, i tak cyklicznie. Pierwsze
//        odliczanie zaczyna się od godziny t0. Potwór atakuje tylko o godzinach
//        podzielnych  przez 3 lub 13, a niepodzielnych przez 7.
//Śmierć mieszkańca bądź potwora następuje w momencie, gdy jego liczba punktów
//życia osiągnie zero. Wywołanie tick() na miasteczku z martwym potworem i co
//        najmniej jednym żywym mieszkańcem powoduje wypisanie na standardowe wyjście
//komunikatu "CITIZENS WON". Wywołanie tick() na miasteczku z martwymi
//mieszkańcami i żywym potworem powoduje wypisanie na standardowym wyjściu napisu
//"MONSTER WON". Jeśli zarówno mieszańcy, jak i potwór są martwi, to tick()
//wypisuje na standardowe wyjście "DRAW".

#endif //HORRORMOVIE_SMALLTOWN_H
