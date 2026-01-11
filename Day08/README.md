## Part 1
Vhodni podatki so koordinate točk v 3D prostoru, kjer vsaka točka predstavlja eno razdelilno omarico. Na začetku je vsaka omarica v svojem krogu (ni povezana z nobeno drugo).

Najprej izračunam razdaljo med vsakim parom točk. Ker je dovolj, da primerjam razdalje, uporabim kar kvadrat razdalje (dx² + dy² + dz²), brez korenjenja. Vse pare shranim kot povezave in jih sortiram od najkrajše do najdaljše.

Nato povezave obdelujem po vrsti, od najkrajše naprej. Če dve omarici še nista v istem krogu, ju povežem. Za sledenje krogom uporabim strukturo parent + size (union–find).

Ko naredim prvih 1000 povezav, pogledam velikosti vseh trenutno obstoječih krogov, jih razvrstim po velikosti in zmnožim tri največje. To je rezultat za Part 1.

## Part 2
V drugem delu nadaljujem z enakim postopkom povezovanja, le da me zanima trenutek, ko so vse omarice povezane v en sam krog.

Sproti spremljam, koliko ločenih komponent še obstaja. Vsakič, ko se dve različni komponenti združita, se število komponent zmanjša za ena.

Ko število komponent prvič pade na 1, pomeni, da je celoten sistem povezan. Takrat vzamem zadnjo povezavo, ki je to povzročila, in zmnožim X-koordinati obeh točk iz te povezave. To je rezultat za Part 2.

Na koncu program izpiše rezultat za oba dela.
