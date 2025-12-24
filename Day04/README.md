## Part 1

Roll (`@`) je dostopen z viličarjem, če ima v **8 sosednih poljih** (tudi diagonale) **manj kot 4** sosednje rolle (`@`).

Postopek:

1. Za vsak `@` na mreži preštejemo število sosednjih `@` v 8 smereh.
2. Če je to število `< 4`, ga štejemo kot dostopen.
3. Rezultat Part 1 je število dostopnih rollov v začetnem stanju.

---

## Part 2

Zdaj se rolli, ki so dostopni, lahko **odstranijo**. Ko jih odstranimo, se lahko zaradi spremenjene okolice dostopni rolli spremenijo, zato postopek ponavljamo:

1. Najdemo vse rolle, ki so trenutno dostopni (isti pogoj kot v Part 1: manj kot 4 sosednji `@`).
2. Vse te rolle odstranimo **hkrati** (spremenimo jih v `.`).
3. Število odstranjenih rollov prištejemo v skupni števec.
4. Ponavljamo, dokler v neki iteraciji ne najdemo nobenega več dostopnega rolla.

Rezultat Part 2 je skupno število odstranjenih rollov.

---

## Implementacija

Program:

- najprej izračuna Part 1 na originalni mreži,
- nato naredi kopijo mreže in v zanki:
  - poišče vse trenutne dostopne rolle (pogoj < 4 sosednjih `@`),
  - jih odstrani in prišteje njihov count v skupno vsoto,
  - ustavi se, ko v iteraciji ni nobenega rolla za odstraniti.

Časovna zahtevnost je `O(k * h * w)`, kjer je `k` število iteracij. Za tipične Advent of Code velikosti je to brez problema.
