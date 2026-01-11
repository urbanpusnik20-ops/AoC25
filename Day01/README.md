ChatGPT uporabljen z alepši izpis

## Part 1
Na začetku je številčnica nastavljena na 50. Iz vhodne datoteke po vrsticah berem rotacije v levo (L) in desno (R) skupaj z razdaljo. Vsako vrstico razbijem na smer vrtenja in število korakov.

Po vsaki rotaciji izračunam novo pozicijo na krožni številčnici z vrednostmi od 0 do 99. V kodi to naredim tako, da razdaljo najprej zmanjšam z ostankom pri deljenju z 100, nato pa trenutno pozicijo glede na smer vrtenja povečam ali zmanjšam. Na ta način poskrbim, da se pozicija vedno pravilno zavije okoli kroga.

Ko je nova pozicija izračunana, preverim, ali je enaka 0. Če je, povečam števec za Part 1. Tako sproti sledim trenutni poziciji in številu zadetkov ničle.

## Part 2
V drugem delu ni več dovolj, da preverjam samo končno pozicijo, ampak moram šteti vsak prehod čez 0, tudi če se ta zgodi med samo rotacijo. Ker so razdalje lahko zelo velike, v kodi ne simuliram vsakega posameznega klika.

Namesto tega glede na trenutno pozicijo in smer vrtenja izračunam, koliko korakov je potrebnih do prvega prehoda čez 0. Če je razdalja dovolj velika, lahko nato izračunam še dodatna prehajanja, ki se ponovijo vsakih 100 korakov. Število teh prehodov sproti prištevam k rezultatu za Part 2.

Na koncu vsake rotacije ponovno izračunam končno pozicijo na krožni številčnici na enak način kot v Part 1, da lahko pravilno nadaljujem z naslednjo rotacijo. Program na koncu izpiše rezultat za oba dela.
