
## Part 1
Vhodni podatki predstavljajo mrežo znakov, kjer znak `@` pomeni zvitek papirja, pika `.` pa prazno polje. Najprej preberem celotno mrežo v vektor nizov, da lahko do posameznih polj dostopam z indeksi vrstic in stolpcev.

Za vsak zvitek papirja preverim njegovih osem sosednjih polj (levo, desno, gor, dol in diagonale). V kodi imam pripravljena dva seznama premikov, s katerima enostavno preverjam vseh osem smeri. Preštejem, koliko sosednjih polj vsebuje znak `@`. Če ima zvitek manj kot štiri sosede, ga štejem kot dostopnega in ga prištejem k rezultatu za Part 1.

## Part 2
V drugem delu se zvitki papirja lahko postopoma odstranjujejo. Najprej naredim kopijo začetne mreže, saj Part 2 ne sme vplivati na rezultat Part 1. Nato postopek ponavljam v zanki.

V vsaki iteraciji ponovno pregledam celotno mrežo in poiščem vse zvitke, ki imajo manj kot štiri sosede. Te zvitke si najprej shranim v seznam, da jih ne odstranjujem sproti med pregledovanjem. Ko je pregled končan, vse najdene zvitke odstranim iz mreže in njihovo število prištejem k rezultatu za Part 2.

Postopek ponavljam, dokler v eni iteraciji ne najdem več nobenega zvitka, ki bi ga bilo možno odstraniti. Na koncu izpišem rezultat za oba dela.
