## Part 1

Številčnica ima vrednosti od 0 do 99, začnemo na položaju 50. Vhod (`input.txt`) vsebuje vrstice oblike `L68`, `R48`, kjer `L` pomeni vrtenje levo (proti manjšim številom), `R` pa desno (proti večjim številom). Število za črko je razdalja v klikih.

Za vsak ukaz:

1. Preberemo smer (`L` ali `R`) in razdaljo.
2. Novo pozicijo izračunamo z aritmetiko modulo 100.
3. Če se rotacija konča na 0, povečamo števec za Part 1.

Rezultat Part 1 je število rotacij, ki se končajo na 0.

## Part 2

Za drugi del moramo šteti **vsak klik**, ki pripelje kazalec na 0, ne samo končne položaje rotacij.

Namesto da bi simulirali vsak klik posebej, za posamezno rotacijo izračunamo:

- pri desni rotaciji `R` je prvi klik na 0 pri koraku `s0 = (100 - position) mod 100`, pri levi `L` pa pri `s0 = position` (ali 100, če smo na 0),
- če je razdalja `dist` vsaj `s0`, potem je število zadetkov 0 v tej rotaciji  
  `1 + (dist - s0) / 100`.

To število prištejemo v skupni `part2`. S tem dobimo skupno število vseh klikov, pri katerih je kazalec na 0.

Časovna zahtevnost ostane linearna v številu rotacij (`O(n)`), ker na vsaki vrstici naredimo konstantno količino računanja.
