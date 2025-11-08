# K-way-QuickSort
O algoritmo implementado é o QuickSort em K-partições, em um vetor com qualquer tipo de dado a ser utilizado.
<br>O QuickSort tem como objetivo ordernar um vetor, selecionando um pivô de forma arbitrária (sendo ele o primeiro elemento/o último elemento/um elemento aleatório do vetor), dividindo a tarefa de ordenação a cada iteração, até chegar no caso mínimo (subvetor com tamanho 1).
<br><br><b>Integrantes do grupo:</b>
<br>Igor Soares da Silva
<br>Saimon Augusto da Silva Rocha
<br>Adriel Borges Zanetti
<br>Gabriel Anael Strotkamp
<br>Jhônattan Djovane Reolon da Silva.

"Saimon:"
🧠 Lógica da implementação

Escolher K−1 pivôs.
– Pode pegar os primeiros, últimos, aleatórios, ou mesmo medianas.
– Pra simplificar.
- Pegando pivôs aleatórios

Ordenar os pivôs.
– Isso garante que eles definem intervalos bem delimitados.

Criar K listas vazias (subarrays).

Distribuir os elementos de acordo com os pivôs:

se x < p1 → vai pro primeiro grupo

se p1 ≤ x < p2 → segundo grupo

...

se x ≥ pK-1 → último grupo

Chamar o K-way QuickSort recursivamente em cada grupo.

Concatenar os resultados

💬 Explicação rápida

kWayQuickSort é recursivo igual ao QuickSort normal.

Escolhe k−1 pivôs aleatórios e ordena eles.

Cria k partições (vector<vector<int>> parts(k)).

Cada elemento vai pra partição correspondente de acordo com os pivôs.

Ordena cada partição recursivamente e concatena os resultados.