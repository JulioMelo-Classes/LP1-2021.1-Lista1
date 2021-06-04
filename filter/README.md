# Filter

Escreva uma função em C++ chamada _filter_ que "filtra" os elementos no intervalo `[first ;
last)` definido sobre um vetor de inteiros por meio de ponteiros, retirando todos os valores
nulos e negativos e preservando a ordem relativa dos elementos filtrados. A função deve
retornar um ponteiro para a posição após o último elemento que permaneceu no vetor depois
de realizada a operação de filtragem.

Considere o exemplo abaixo com apenas 10 elementos no intervalo:

```
       first                                last
          ↓                                   ↓
Indice |  0|  1| 2| 3|  4|  5| 6| 7|  8| 10| 11|
Valor  | -2| -8| 6| 7| -3| 10| 1| 0| -3|  7|  ?|
``` 
Depois da filtragem o vetor deverá ficar:

```
       first            ret             last
         ↓               ↓                ↓
Indice | 0| 1|  2| 3| 4| 5| 6| 7| 8| 10| 11|
Valor  | 6| 7| 10| 1| 7| ?| ?| ?| ?|  ?| ? |
``` 
A função deve ter a seguinte assinatura:
```c++
const int* filter ( const int *first , const int *last );
```

Note que a função apenas rearranja os valores dentro do vetor e retorna o endereço logo após o último
valor válido dentro do vetor filtrado, os valores de first e last não são alterados (e nem podem, devido a assinatura `const`). Essas operações
podem ser feitas fácilmente através de **incremento de ponteiros** e **acesso ao conteúdo de ponteiros**.

## Conhecimentos Necessários

Utilização de função, relação entre ponteiro e memória, ponteiros para memória constante,
aritmética de ponteiros, laços, troca interna de valores em vetor.

**Observação**: Não é necessário criar um outro vetor para armazenar o resultado da filtragem.
A filtragem pode ser feita internamente, ou seja, dentro do próprio vetor, com a ajuda de
variáveis auxiliares.
