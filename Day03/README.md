
## Part 1
Vsaka vrstica vhodne datoteke predstavlja eno banko baterij, kjer so števke zapisane zaporedno. Iz vsake banke moram izbrati točno dve bateriji, pri čemer vrstnega reda ne smem spreminjati, cilj pa je dobiti čim večje dvomestno število.

V kodi vsako vrstico obravnavam kot niz znakov. Če je števk manj ali enako kot jih potrebujem, enostavno vzamem vse. Sicer pa števke izbiram postopoma. Najprej poiščem največjo možno prvo števko tako, da pregledujem le tisti del niza, iz katerega je še možno sestaviti celotno število. Ko izberem prvo števko, postopek ponovim za naslednjo, vedno začenjam iskanje za izbrano pozicijo.

Iz izbranih števk sestavim število in ga prištejem k skupnemu rezultatu za Part 1.

## Part 2
V drugem delu je postopek zelo podoben, le da moram iz vsake vrstice izbrati dvanajst števk namesto dveh. Logika izbire ostane enaka kot v Part 1, le število potrebnih števk je večje.

V kodi za oba dela uporabim isto funkcijo, ki kot parameter dobi število števk, ki jih mora izbrati. Tako se algoritem za izbiro največjega možnega števila ponovno uporabi brez dodatnega zapletanja. Rezultate za Part 1 in Part 2 sproti seštevam in ju na koncu izpišem.
