tu je vecinoma naredil chatGPT moje znanje ne obstaja več žal (bom poskusil razumeti zaenkrat ne gre)

## Part 1
Vsaka vrstica opisuje en stroj. Na začetku je prikazan končni vzorec lučk, kjer `#` pomeni vklopljeno lučko, `.` pa izklopljeno. Vse lučke so na začetku izklopljene. Gumbi preklapljajo določene lučke in vsak gumb lahko pritisnem poljubnokrat.

Najprej končni vzorec lučk pretvorim v binarno masko, kjer vsaka lučka ustreza enemu bitu. Nato vsak gumb prav tako pretvorim v masko, ki pove, katere lučke ta gumb preklopi. Ker preklapljanje deluje kot XOR, je celoten problem v bistvu iskanje najmanjšega števila gumbov, s katerimi dobim ciljno masko.

Ker je gumbov več, problem rešim tako, da jih razdelim na dve polovici. Za prvo polovico izračunam vse možne kombinacije in si zapomnim, s koliko pritiski dobim posamezno masko. Nato grem čez kombinacije druge polovice in preverjam, ali skupaj s prvo polovico lahko sestavim ciljno stanje. Med vsemi možnostmi izberem najmanjše skupno število pritiskov. Ta vrednost je rezultat za Part 1 za posamezno vrstico, vse vrstice pa seštejem.

## Part 2
V drugem delu lučke niso več pomembne. Namesto tega ima vsak stroj več števcev napetosti, ki se začnejo pri 0. Cilj je doseči točno določene končne vrednosti. Gumbi zdaj ne preklapljajo več, ampak ob vsakem pritisku povečajo določene števce za 1.

Za ta del uporabim iskanje po stanjih. Začetno stanje je vektor ničel, ciljno stanje pa je vektor iz vhodnih podatkov. Vsako stanje predstavlja trenutne vrednosti vseh števcev. Z BFS postopoma dodajam pritiske gumbov, pri čemer nikoli ne dovolim, da bi kateri koli števec presegel ciljno vrednost.

Ko prvič dosežem ciljni vektor, vem, da sem do njega prišel z najmanjšim možnim številom pritiskov. To število prištejem k skupni vsoti za Part 2. Na koncu program izpiše vsoto najmanjših potrebnih pritiskov za oba dela.
