
## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Requirements: cmake, gnuplot, doxygen + dot (in graphviz library)

Example:

``` bash
> mkdir build && cd build
> cmake .. #### options: -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release], Debug is default
> make     #### compilation
> ./main   #### main() from app
> make test      #### Compile the tests
> ./unit_tests -s   #### Start the tests, -s flag - full description of each case
> make fulltest #### alternative for above, compile & run tests with full decription
> make coverage  #### Generate a coverage report
> make doc       #### Generate html documentation
```

Things to remember:
* changes to CMakeLists.txt in the main folder with new files added, i.e.:
```cpp
# --------------------------------------------------------------------------------
#                         Locate files (change as needed).
# --------------------------------------------------------------------------------
set(SOURCES          # All .cpp files in src/
    src/lacze_do_gnuplota
    src/Matrix2x2.cpp
    src/Rectangle .cpp
    src/Vector2D.cpp # etc.
)
set(TESTFILES        # All .cpp files in tests/
    Vector2D.cpp
    Matrix2x2.cpp
    Rectangle.cpp # etc.
)
set(LIBRARY_NAME zadX)  # Default name for the library built from src/*.cpp (change if you wish)
```
* changes to tests/CMakeLists.txt (in tests subfolder) with new files added, i.e.:
```cpp
# List all files containing tests. (Change as needed)
set(TESTFILES        # All .cpp files in tests/
    main.cpp
    test_Wektor2D.cpp
    test_Macierz2x2.cpp
    test_Prostokat.cpp # etc.
)
```
The `main.cpp` in the folder `tests` is needed. Only there we define `#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN`.

The main loop of the program is in the `app` folder.

Wazne informacje:
rotory drona nie kreca sie podczas lotu i wznoszenia
Można maksymalnie dodać 9 przeszkod, ale usuniete przeszkody nie zwalniaja limitu(nie wiedzialem jak zapisywac przeszkody do wczesniejszych plikow).
Poczatkowe przeszkody trzeba ustawic recznie(przerobienie konstruktorow zajeloby mi za duzo czasu )
drony i przeszkody sa na osobnych listach(wybralem uproszcenie)
Nowo tworzone preszkody moga powstac na istniejacych obiektach(w opisie zadania nie bylo o tym mowy(chyba), a ze wzgledu na skalowanie przeszkod i problem z ponownym wykorzystaniem plikow zapisu nie zdecydowalem sie na to )
Przy drugim przemieszczeniu sie drona laduje on polowa korpusu "w ziemi" blad ten sie nie poglebia(kazde kolejne ladowanie konczy sie tak samo) i nie udalo mi sie znalezc jego przyczyny.
