# C_STM32Task

Polska wersja

Projekt
Zaliczeniowy z przedmiotu Mikrokontrolery.

Cel
Sterowanie pilotem IR diodami led.

Urządzenie docelowe
Mikrokontroler STM32 z podłączonymi podzespołami:
* odbiornik podczerwienie
* diody led

Implementacja
Projekt implementuje obsługę protokołu komunikacyjnego IR (zgodnie ze specyfikacją firmy NEC),
po czym następuje obsługa pewnego podzbioru komend nadajnika Ir (przykładowo pilot IR do rzutnika NEC).


Użycie
1. Po podłączeniu podzespołów należy zmienić plik ustawień lokalnych Config.h
zgodnie z własą konfiguracją
2. Kompliacja 
make
3. Załadowanie programu na mikrokontroler
load.sh


