README.md pentru Problemele de Algoritmica Rezolvate
1. drumuri.cpp - Algoritm Dijkstra pentru Cea Mai Scurtă Cale
Descriere:
Programul drumuri.cpp utilizează algoritmul lui Dijkstra pentru a calcula costul minim al drumurilor între noduri într-un graf orientat ponderat. Graficul este reprezentat printr-o listă de adiacență, iar costurile sunt stocate în perechi (cost, nod). Programul citește numărul de noduri (N), numărul de muchii (M) și conexiunile între ele, apoi calculează costul total minim pentru a ajunge de la nodul z la nodurile x și y.

Complexitate:
Complexitatea temporală este O((N + M) log N) din cauza utilizării cozii de priorități în implementarea lui Dijkstra, care necesită log N pentru fiecare inserare și extragere. Complexitatea spațială este O(N + M) pentru stocarea grafului și a vectorului de distanțe.

2. trenuri.cpp - Căutarea Celui Mai Lung Drum Între Două Orașe
Descriere:
trenuri.cpp implementează căutarea celui mai lung drum într-un graf aciclic orientat (DAG) folosind un sort topologic și o abordare de tip programare dinamică. Programul citește orașele de start și de sfârșit, numărul de conexiuni directe între orașe și apoi calculează cel mai lung drum între orașele specificate.

Complexitate:
Complexitatea temporală este O(N + M) datorită parcurgerii DFS pentru sortarea topologică și a evaluării ulterioare a celui mai lung drum. Complexitatea spațială este O(N + M) pentru stocarea grafului și a structurilor auxiliare.

Note suplimentare:
Algoritmul presupune un graf aciclic, deci nu gestionează cicluri.

3. numarare.cpp - Numărarea Drumurilor într-un Graf Comun
Descriere:
numarare.cpp calculează numărul de drumuri de la nodul 1 la N într-un graf care este intersecția a două grafuri direcționate. Se utilizează sortarea topologică pentru a procesa nodurile în ordine și programarea dinamică pentru a contoriza drumurile posibile.

Complexitate:
Complexitatea temporală este O(N + M) pentru sortarea topologică și calculul drumurilor, în timp ce complexitatea spațială este O(N + M) pentru stocarea structurilor de date necesare.

Note suplimentare:
Programul presupune că intersecția grafurilor este tot un DAG. Dacă rezultatul intersecției introduce cicluri, rezultatele nu vor fi valide.