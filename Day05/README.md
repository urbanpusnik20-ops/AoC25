
## Part 1

Za vsak razpoložljivi ID preverimo, ali je v vsaj enem razponu `a <= id <= b`.

Štejemo samo tiste, ki so sveži.

---

## Part 2

Razpoložljivi ID-ji se ignorirajo.

Moramo ugotoviti **koliko različnih ID-jev** pokriva unija vseh razponov:

1. Razpone sortiramo.
2. Združimo vse, ki se prekrivajo ali stikajo.
3. Za vsak združen razpon prištejemo `(b - a + 1)`.

Rezultat je skupno število svežih ID-jev.

---

## Izhod

Program izpiše dve številki:

1. Število svežih ID-jev iz Part 1.
2. Število vseh ID-jev, ki jih pokriva unija razponov (Part 2).
