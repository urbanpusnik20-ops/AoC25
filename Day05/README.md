## Part 1
Vhodna datoteka je razdeljena na dva dela. V prvem delu so podani razponi svežih ID-jev v obliki a-b, v drugem delu pa so posamezni ID-ji sestavin, ki jih je treba preveriti.

Program najprej prebere vse razpone in jih shrani v seznam parov. Nato začne brati drugi del vhodne datoteke, kjer je v vsaki vrstici en ID. Za vsak ID zaporedno preverim, ali pade v vsaj enega izmed podanih razponov. Če ID leži znotraj katerega koli razpona, ga obravnavam kot svežega in povečam števec za Part 1.

## Part 2
V drugem delu posamezni ID-ji niso več pomembni, zanima me samo, koliko različnih ID-jev je skupaj pokritih z razponi svežih sestavin.

Najprej razpone uredim po začetni vrednosti. Nato jih obdelujem zaporedno in sproti združujem razpone, ki se prekrivajo ali stikajo. Če naletim na razpon, ki se ne prekriva z trenutnim, prištejem dolžino trenutnega razpona k rezultatu in začnem novega.

Na koncu prištejem še zadnji združeni razpon. Tako dobim skupno število različnih ID-jev, ki jih razponi označujejo kot sveže. Program na koncu izpiše rezultat za oba dela.
