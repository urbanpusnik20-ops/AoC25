# Day 9 – Movie Theater

## Part 1
Vhodni podatki so koordinate rdečih ploščic v ravnini. Vsaki dve rdeči ploščici lahko vzamem kot nasprotna vogala pravokotnika, ki je poravnan z osmi.

V prvem delu me zanima samo največja možna površina takega pravokotnika. Zato preberem vse točke v seznam in nato preverim vse možne pare točk. Za vsak par izračunam širino in višino pravokotnika kot absolutno razliko koordinat, povečano za ena, in iz tega dobim površino. Sproti si zapomnim največjo vrednost, ki jo na koncu izpišem kot rezultat za Part 1.

## Part 2
V drugem delu pravokotnik ne sme segati izven območja, ki ga tvorijo rdeče in zelene ploščice. Zelene ploščice skupaj z rdečimi tvorijo zaprt obroč in zapolnijo tudi notranjost.

Najprej poenostavim koordinatni sistem tako, da vse različne X in Y koordinate preslikam v zaporedne indekse. Na tako zmanjšani mreži narišem rob območja med zaporednimi rdečimi ploščicami. Nato z iskanjem po širini označim vso zunanjost območja. Vse celice, ki niso zunaj, skupaj z robom, štejem kot dovoljene.

Da lahko hitro preverim, ali je celoten pravokotnik znotraj dovoljenega območja, si nad to mrežo izračunam tabelo delnih vsot. Nato ponovno pregledam vse pare rdečih ploščic. Če je pravokotnik med njima v celoti sestavljen samo iz dovoljenih celic, izračunam njegovo pravo površino v originalnih koordinatah in posodobim maksimum. Ta vrednost je rezultat za Part 2.
