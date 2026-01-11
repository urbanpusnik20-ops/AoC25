
## Part 1
ID je neveljaven, če je sestavljen iz neke zaporedne sekvence števk, ki je ponovljena natanko dvakrat (na primer 55, 6464 ali 123123).

Program najprej prebere celotno vrstico iz vhodne datoteke, ki vsebuje več razponov ID-jev, ločenih z vejicami. Vsak razpon oblike a-b obdelam posebej in zaporedno pregledam vse ID-je od a do b.

Vsak ID pretvorim v niz znakov. Če ima niz sodo dolžino, ga razdelim na dve enako dolgi polovici in preverim, ali sta polovici enaki. Če sta, pomeni, da je ID sestavljen iz ene sekvence, ponovljene dvakrat, zato njegovo vrednost prištejem k rezultatu za Part 1.

## Part 2
V drugem delu je definicija razširjena. ID je neveljaven, če je sestavljen iz neke zaporedne sekvence števk, ki je ponovljena vsaj dvakrat, torej se lahko ponovi tudi trikrat ali večkrat.

Branje vhodnih podatkov in iteriranje po razponih ostane enako kot v Part 1. Razlika je v preverjanju posameznega ID-ja. ID ponovno obravnavam kot niz znakov, nato pa preverjam vse možne dolžine začetnega bloka, ki bi se lahko ponavljal.

Za vsako možno dolžino preverim, ali se celoten niz lahko sestavi iz ponavljanja prvega bloka. To naredim tako, da primerjam znake na trenutnem mestu z ustreznimi znaki v prvem bloku. Če najdem blok, ki se ponovi vsaj dvakrat in pokrije celoten niz, ID obravnavam kot neveljaven in njegovo vrednost prištejem k rezultatu za Part 2.
