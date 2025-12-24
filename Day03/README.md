## Part 1

V vsakem banku moramo izbrati **točno dve bateriji** (dve poziciji v nizu, v pravilnem vrstnem redu). Jolt je dvomestno število, sestavljeno iz izbranih dveh števk. Cilj je dobiti največje možno dvomestno število za vsako vrstico. Skupni rezultat je vsota teh največjih dvomestnih števil.

Za Part 1 program za vsak niz uporabi funkcijo `bestKDigits(line, 2)`.

## Part 2

Zdaj moramo v vsakem banku izbrati **točno 12 baterij**. Nastalo število je 12-mestno (števke v istem vrstnem redu kot v vhodu). Cilj je dobiti največje možno 12-mestno število za vsako vrstico in nato vse sešteti.

Za vsak niz:

1. Želimo izbrati podzaporedje dolžine `k` (za Part 2 je `k = 12`), tako da je nastalo število največje.
2. Gremo po pozicijah od 1 do `k` in vsakič:
   - v preostalem delu niza poiščemo največjo možno števko,
   - pazimo, da za preostale pozicije ostane dovolj znakov,
   - izbrano števko dodamo v rezultat, indeks pa premaknemo naprej.

To je klasičen greedy za "največje leksikografsko podzaporedje" fiksne dolžine.

Program:

- za vsako vrstico izračuna `bestKDigits(line, 2)` in `bestKDigits(line, 12)`,
- rezultate sešteje v `totalPart1` in `totalPart2`,
- izpiše obe vsoti v dveh vrsticah (najprej Part 1, nato Part 2).

Časovna zahtevnost je `O(n * k)` na vrstico, kjer je `k` majhen (2 ali 12), zato je efektivno linearna v dolžini vrstice.
