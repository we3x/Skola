# Procesi
Procesi predstavljaju jedan od najvažnijih koncepata operativnih sistema. Program je niz instrukcija koji ostvaruje neki algoritam. Proces je program u statusu izvršavanja, zajedno sa svim resursima koji su potrebni za rad programa.

Osnovna stanja procesa su RUNNING (proces je pokrenut), READY (proces je spreman za izvrsavanje, ima sve sto mu je potrebno), BLOCKED (Proces je blokiran zato sto mu je trenutno nedostupno sve sto mu je potrebno).

Kod nekih operativnih sistema procesi mogu biti i suspendnovani. SUSPEND stanje se javlja na primer u trenutku kada je broj spremnih procesa mnogo veci od mogucnosti procesora. Ili kod zaglavljivanja dva procesa jedan proces (koristi i menja podatke potrebne drugom procesu).

Svakom procesu se dodeljuje jedinstveni PCB koji sadrži informacije koje su potrebne za nastavak izvršavanja tog procesa. Te informacije uključuju:
- jedinstveni identifikator procesa (pid – process ID)
- stanje procesa
- prioritet procesa (iz liste čekanja biramo najpre procese sa već im prioritetima)
- adresa memorije gde se nalazi proces
- adrese zauzetih resursa
- sadržaj registara procesora, itd.

Operacije koje bi operativni sistem trebao da omoguci: kreiranje i unistavanje procesa, menjanje stanja procesa, menjanje prioriteta procesa...

Proces moze da pokrene novi proces. Onda je on roditelj a proces koji je kreirao se naziva dete (grade oblik stabla).Između roditelja i deteta možemo imati dve vrste veze:
1. proces-roditelj kreira novog procesa i čeka dok proces-dete završi sa radom
2. proces-roditelj kreira novog procesa i nastavljaju sa radom oba procesa (rade paralelno)
