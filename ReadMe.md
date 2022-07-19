# Projekt pico-AD597

Celem projektu jest kod urządzenia testowego czujników temperatury.
Odczyty temperatury powinny być wyświetlane na konsoli.


# Konfiguracja

Zobacz [Using the Raspberry Pi Pico on Ubuntu](https://www.gibbard.me/using_the_raspberry_pi_pico_on_ubuntu/)

1. Zainstalowanie PICO-SDK i skompilowanie przykładów w folderze ~/Development/pico:
```
$ git clone -b master https://github.com/raspberrypi/pico-sdk.git
$ cd pico-sdk
$ git submodule update --init

# Add SDK path to your environment
$ echo 'export PICO_SDK_PATH=$HOME/Development/pico/pico-sdk' >> ~/.bashrc 

$ cd ..
$ git clone -b master https://github.com/raspberrypi/pico-examples.git
$ cd pico-examples
$ mkdir build
$ cd build
$ cmake ..
$ cd blink
$ make -j $(nproc)
```

# Utworzenie projektu CMAKE
Projekt na początku ma zawierać:
* plik z funkcją __main()_; dla porządku w folderze __src__)
* CMakeList.txt
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
Dwie ostatnie linie w pliku __CMakeLists.txt__ definiują działanie funkcji printf(). Ma ona skonfigurowany output na serial over USB zamiast na UART.
Po połączeniu komputera z pico kablem USB sprawdź nazwę urządzenia:
```
$ dmesg | egrep --color 'USB ACM device'
[13287.289925] cdc_acm 4-1:1.0: ttyACM0: USB ACM device
```
a nastepnie uruchom konsolę zestawiając połączenie szeregowe z raspberry pico:
```
$ sudo minicom -b 115200 -D /dev/ttyACM0
```

# Konfiguracja sprzętowa
![Raspberry-pico pins layout](./pictures/raspberry-pico-layout.png)


# Oprogramowanie czujników temperatury

## Wewnętrzny sensor temperatury


## Termopara typu k z przetwornikiem AD597
```C
/* File name: AD597.h */
float tc_read()
{
    const float conversion_factor = 3.3f / (1 << 12);
    uint16_t result = adc_read();

    return result * conversion_factor;
}
```


References:
* [Raspberry Pi pico examples](https://raspberrypi.github.io/pico-sdk-doxygen/examples_page.html)
* [GitHub examples](https://github.com/raspberrypi/pico-examples)
* [Raspberry Pi Pico (RP2040) I2C Example with MicroPython and C/C++](https://www.digikey.pl/en/maker/projects/raspberry-pi-pico-rp2040-i2c-example-with-micropython-and-cc/47d0c922b79342779cdbd4b37b7eb7e2)
* [Forbot](https://forbot.pl/forum/topic/19701-raspberry-pi-pico-podstawy-dla-zielonych/)
* [How to Program Raspberry Pi Pico using C/C++ SDK](https://circuitdigest.com/microcontroller-projects/how-to-program-raspberry-pi-pico-using-c)

* [Working with the Raspberry Pi Pico with Windows and C/C++](https://community.element14.com/products/raspberry-pi/b/blog/posts/working-with-the-raspberry-pi-pico-with-windows-and-c-c)

* [Raspberry Pi Pico and RP2040 - C/C++ Part 2: Debugging with VS Code](https://www.digikey.be/en/maker/projects/raspberry-pi-pico-and-rp2040-cc-part-2-debugging-with-vs-code/470abc7efb07432b82c95f6f67f184c0)

* [Building Code for the Raspberry Pi Pico](https://www.teachmemicro.com/building-code-raspberry-pi-pico/)

CMake related references:
* [CMAKE commands](https://cmake.org/cmake/help/latest/manual/cmake-commands.7.html)
* [Modern CMake is like inheritance](https://kubasejdak.com/modern-cmake-is-like-inheritance)