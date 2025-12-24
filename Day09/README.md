Part 1

Vsi rdeči kvadrati so podani s koordinatami.
Za vsak par rdečih kvadratov izračunam pravokotnik, ki ga določata kot nasprotna kota:

area = (|x1 – x2| + 1) * (|y1 – y2| + 1)


Skozi vse pare poiščem največjo površino.

Part 2

Rdeči kvadrati tvorijo zaprto ortogonalno zanko, vmesni kvadrati med njimi pa so zeleni (tudi notranjost zanke je zelena).
Pravokotnik je veljaven, če:

ima rdeča kota,

so vsi kvadrati v pravokotniku rdeči ali zeleni.

Ker so koordinate zelo velike, uporabim koordinatno kompresijo, da zmanjšam grid na približno n × n.
Na kompresiranem gridu:

narišem rob poligona (rdeči kvadrati),

z BFS označim zunanjost,

vse kar ni zunaj je dovoljeno (rdeče + zeleno),

naredim 2D prefix sum za hitre O(1) preverbe pravokotnikov,

preverim vse pare rdečih kvadratov in vzamem največjo dovoljeno površino.

Program izpiše:

največja površina (part 1)
največja površina (part 2)