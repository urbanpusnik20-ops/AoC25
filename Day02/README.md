## Part 1

ID je neveljaven, če je sestavljen iz neke zaporedne sekvence števk, ki je ponovljena **dvakrat**.
Primeri: `55` (`5` dvakrat), `6464` (`64` dvakrat), `123123` (`123` dvakrat).

Pogoj:
- število števk je sodo,
- prva polovica niza je enaka drugi polovici.

Program:

1. Preberemo celotno vrstico in jo razdelimo po vejicah v razpone `a-b`.
2. Za vsak razpon iteriramo po vseh ID-jih od `a` do `b`.
3. Vsak ID pretvorimo v niz:
   - če ima sodo dolžino in je prva polovica enaka drugi, ga prištejemo v `sumPart1`.

---

## Part 2

Nova definicija: ID je neveljaven, če je sestavljen iz neke zaporedne sekvence števk, ki je ponovljena **vsaj dvakrat**.

Primeri:
- `12341234` = `1234` × 2
- `123123123` = `123` × 3
- `1212121212` = `12` × 5
- `1111111` = `1` × 7

Pogoj:
- obstaja dolžina bloka `d`, da:
  - `n % d == 0`, kjer je `n` dolžina niza,
  - število ponovitev `k = n / d` je `k >= 2`,
  - celoten niz je enak prvemu bloku, ponovljenemu `k`-krat.

Program za Part 2:

1. Za vsak ID (enako kot pri Part 1) preverimo vse možne dolžine bloka `d` od 1 do `n/2`.
2. Če `n % d != 0`, ta `d` preskočimo.
3. Če `k = n / d` in `k >= 2`, preverimo, ali je celoten niz zgrajen iz ponavljanja prvih `d` znakov.
4. Če najdemo tak blok, ID prištejemo v `sumPart2`.

