# Projekt pico-AD597

Celem projektu jest kod urządzenia testowego czujników temperatury.
Odczyty temperatury powinny być wyświetlane na konsoli.

# Utworzenie projektu CMAKE
Projekt na początku ma zawierać:
* plik z funkcją __main()_; dla porządku w folderze __src__)
* CMakeList.txt (skopiowany z innego projektu)
* katalog build (pusty)

Nazwa pliku z funkcją main() jest podana CMakeList.txt jako __main.c__.

```
$ cd build
$ cmake ..
$ make -j2
```

Make powinien poprawnie zbudować następujące "targety":
* __blink.elf__ - którego używa debugger
* __blink.uf2__ - który można przeciągnąć na urządzenie pamięci masowej USB RP2040

Skopuj __build.uf2__ na dysk virtualny pico (ponowne podłączenie kabelka USB ze wciśniętym przyciskiem na pico).

# Podłączenie terminala do raspberry pico 
Funkcja printf() ma skonfigurowany output na serial over USB zamiast na UART.
Po połączeniu komputera z pico kablem USB sprawdź nazwę urządzenia.
```
$ dmesg | egrep --color 'USB ACM device'
```
Uruchom konsolę zestawiając połączenie szeregowe z raspberry pico:
```
$ sudo minicom -b 115200 -D /dev/ttyACM0
```

# Konfiguracja sprzętowa
![Raspberry-pico pins layout](./pictures/raspberry-pico-layout.png)


# Oprogramowanie czujników temperatury

## Termopara typu k z przetwornikiem AD597





Odnośniki:
