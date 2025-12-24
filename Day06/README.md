## Part 1

Števila so zapisana "klasično", v vrsticah:

- za vsak blok vzamemo stolpce bloka,
- v vsaki vrstici razen zadnje izrežemo substring bloka in ga obrežemo (trim),
- ne-prazen substring je eno število,
- spodnja vrstica v bloku vsebuje operator (`+` ali `*`),
- z izbranimi števili izračunamo rezultat problema,
- vse rezultate seštejemo.

---

## Part 2

Cephalopod zapis: števila so **po stolpcih**:

- še vedno veljajo isti bloki in isti operator na dnu bloka,
- zdaj v vsakem stolpcu bloka preberemo znake od vrha do vrstice tik nad operatorjem,
- izberemo samo števke (`0-9`) in jih zložimo skupaj v niz,
- ne-prazen niz predstavlja eno število v tem stolpcu,
- operator na dnu bloka (`+` ali `*`) velja za vsa stolpčna števila v bloku.

Za vsak blok:

- iz stolpcev zgradimo vsa števila po cephalopod pravilu,
- uporabimo isti operator kot prej,
- dobimo rezultat za ta problem,
- vse rezultate seštejemo v skupni cephalopod "grand total".

---

## Izhod

Program izpiše dve števili:

1. Prva vrstica: grand total za Part 1 (števila po vrsticah).
2. Druga vrstica: grand total za Part 2 (števila po stolpcih).
