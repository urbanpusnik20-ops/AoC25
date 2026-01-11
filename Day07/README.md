## Part 1
Vhodni podatki predstavljajo mrežo znakov, kjer znak `S` označuje začetno pozicijo žarka, znak `^` pa razdelilnik (splitter). Žarek se vedno premika navzdol po vrsticah mreže.

Najprej poiščem začetno pozicijo `S` v mreži. Nato za vsako naslednjo vrstico sledim, v katerih stolpcih je žarek trenutno prisoten. To v kodi hranim v vektorju, kjer vsak element pove, ali je žarek prisoten v določenem stolpcu.

Ko žarek naleti na razdelilnik `^`, se razdeli v levo in desno, kar v Part 1 štejem kot en split. Če ni razdelilnika, žarek nadaljuje naravnost navzdol. Postopek ponavljam po vrsticah do dna mreže in sproti seštevam število razdelitev.

## Part 2
V drugem delu obravnavam kvantni primer, kjer se ob vsakem razdelilniku čas razcepi in žarek hkrati nadaljuje po obeh poteh. Cilj je ugotoviti, koliko različnih časovnih linij nastane, ko žarek zapusti mrežo.

Namesto simulacije vseh poti uporabim dinamično programiranje. V kodi si predstavljam, da v vsako celico vstopam od zgoraj, in si za vsako celico shranim, koliko časovnih linij nastane, če žarek pride do te točke.

Računanje izvajam od spodaj navzgor. Če žarek pride izven spodnjega roba mreže, to štejem kot eno zaključno časovno linijo. Če v celici ni razdelilnika, se število linij preprosto prenese v celico nad njo. Če pa je v celici razdelilnik `^`, se število linij razdeli v levo in desno, skupno število pa je vsota obeh poti.

Na koncu pogledam vrednost neposredno pod začetno pozicijo `S`, kar predstavlja skupno število časovnih linij za Part 2. Program izpiše rezultat za oba dela.
