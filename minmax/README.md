# Minmax

Escreva uma função em C++ chamada _min\_max_ que recebe como parâmetro um vetor _V_ com _n_ números inteiros, identifica e retorna um _par_ de valores correspondentes
aos índices da primeira ocorrência do menor elemento e da última ocorrência do maior elemento presente em _V_. Por exemplo, se a entrada fosse `V={5,4,1,3,1,10,7,10,6,8}`
a função deveria retornar o par `{2,7}`, correspondente às posições do primeiro _'1'_ em V\[2\] e do último _'10'_ na posição V\[7\].

Um par de valores pode ser retornado por uma função através de um struct, vetor ou utilizando a classe utilitária `std::pair`, nesta questão usaremos a `std::pair`. Assim
a função deve ter a seguinte assinatura:
```c++
std::pair <size_t ,size_t> min_max ( int V[], size_t n );
```

## Conhecimentos necessários

Utilização de função, passagem de vetor por parâmetro, utilização da classe `std::pair`, retorno de funçao com tipo composto, condicionais, laços.
