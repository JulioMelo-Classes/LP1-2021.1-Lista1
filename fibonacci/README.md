# Fibonacci

Implemente uma função em C++ chamada _fib\_below\_n_ que recebe um valor inteiro positivo _n_ e armazena os termos da série de Fibonacci inferiores a _n_ em um vetor do tipo 
`std::vector`. A função deve então retornar esse objeto usando o comando return. A _classe_ `std::vector` representa um tipo de container que faz parte da 
[biblioteca padrão/STL](https://en.wikipedia.org/wiki/Standard_Template_Library)(c++ tem um conjunto de bibliotecas padrão que provêem várias estruturas úteis inexistentes em C) 
e representa a estrutura de dados lista dinâmica.

A função deve ter a seguinte assinatura:
```c++
std::vector<int> fib_below_n ( unsigned int n );
```
**Relemebrando**: A sequência de Fibonacci define-se como uma sequencia de números inteiros onde os dois primeiros termos são iguais a 1 e cada termo seguinte é a soma dos 
dois termos imediatamente anteriores. Desta forma se fosse fornecido ao programa uma entrada n = 15 o mesmo deveria produzir a seguinte sequência de termos da série: {1; 1; 2; 3; 5; 8; 13}.

## Conhecimentos Necessários

Utilização de funcões, retorno de função, utilização da classe `std::vector` da STL, laços
