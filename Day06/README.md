
## Part 1
Vhodni podatki predstavljajo matematične naloge, zapisane v obliki stolpcev. Najprej preberem vse vrstice iz datoteke in jih shranim v seznam nizov. Ker vrstice niso nujno enako dolge, jih v kodi razširim z znaki presledkov, da imajo vse enako širino.

Nato poiščem posamezne naloge tako, da pregledujem stolpce. Polna kolona presledkov pomeni ločnico med nalogami, zato iz zaporednih ne-praznih stolpcev sestavim posamezne bloke, kjer vsak blok predstavlja eno matematično nalogo.

Za vsak blok najprej poiščem operacijo, ki je zapisana v spodnji vrstici bloka (znak `+` ali `*`). Nato grem po vrsticah od zgoraj navzdol in iz vsake vrstice izluščim število, ki pripada temu bloku. Števila sproti seštevam ali množim glede na operacijo in dobljeni rezultat prištejem k skupnemu rezultatu za Part 1.

## Part 2
V drugem delu se spremeni način branja števil. Namesto branja po vrsticah zdaj berem po stolpcih, saj so števke zapisane navpično od zgoraj navzdol.

Za vsak stolpec znotraj bloka zberem vse števke, ki niso presledki, in iz njih sestavim število. Nato ta števila ponovno seštevam ali množim glede na operacijo, enako kot v Part 1. Dobljeni rezultat prištejem k skupnemu rezultatu za Part 2.

Na koncu program izpiše oba rezultata.
