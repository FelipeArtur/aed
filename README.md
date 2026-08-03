# Algoritmos e Estruturas de Dados I e II

Trabalhos, provas e listas das duas disciplinas de Algoritmos e Estruturas de
Dados no SENAI CIMATEC. Tudo em C, com alguns arquivos em C++.

Vários trabalhos são em grupo, e os nomes dos integrantes estão no cabeçalho de
cada arquivo.

## `AED1/`

Estruturas encadeadas e os primeiros problemas de julgamento automático.

| Pasta | O que tem |
|---|---|
| `AV1/resolucao-corrigida/` | Problemas 1068, 1244 e 1523 do beecrowd (ex-URI), já com a correção |
| `AV2/` | Problemas 1766, 2633 e 2654 |
| `AV3/` | Cadastro de infratores: fila (`FilaiInfrator.h`) e lista encadeada (`conferelista.h`) com menu e login |
| `atividades/exercicios-av1/` | Lista de exercícios da primeira avaliação |
| `atividades/unidade-2/` | Fila e lista encadeada de inteiros, com os programas de teste |
| `atividades/unidade-3/` | Leitura e escrita em arquivo |

## `AED2/`

Estruturas de busca em disco e ordenação que não cabe na memória.

### `primeira-unidade/atividade-pontuada-1/` — ordenação externa

O trabalho mais longo do repositório. Ordena um volume de dados maior que a
memória disponível, usando **intercalação balanceada** entre seis arquivos: três
de entrada e três de saída, alternando a cada passada até tudo ficar ordenado.

`v0.c` a `v6.c` são as versões sucessivas, do esqueleto que só criava os arquivos
até a implementação completa. `ExternalOrder.c` é a versão final e é a que vale
ler — as outras ficam como registro de como o algoritmo foi crescendo.

### `segunda-unidade/` — árvore Trie

Árvore de prefixos com 26 filhos por nó, um por letra. Cada nó guarda a letra e
uma marca de fim de palavra.

### `terceira-unidade/` — árvore B

Árvore B de ordem 2 (até 4 chaves por página), que lê os registros de
`produtos.xml` e indexa por código de produto. É a estrutura que os bancos de
dados usam de verdade para índice, porque minimiza acesso a disco.

### `outros/`

Exercícios soltos de aula, agrupados pela data: busca binária, Fibonacci, maior
elemento de um vetor, bubblesort e árvore binária de busca.

## Compilando

Nenhum arquivo tem build system; cada um compila sozinho:

```sh
gcc -o programa AED2/primeira-unidade/atividade-pontuada-1/ExternalOrder.c
```

Boa parte usa `system("cls")` e `system("pause")`, que só funcionam no Windows —
foi onde a disciplina rodou. Em Linux compila e roda, mas essas chamadas falham
silenciosamente.
