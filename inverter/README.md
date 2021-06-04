# Inverter

Escreva uma função em C++ chamada _reverse_ que recebe como parâmetro uma referência para um vetor estático de strings, implementado com `std::array` , 
e inverte a ordem dos seus elementos da forma mais eficiente possível. 

Por exemplo, considere o vetor A contém as seguintes strings: \["um", "dois", "três", "quatro"\], após a execução
da função o vetor A deverá ter seus elementos na seguinte ordem: \["quatro", "três", "dois", "um"\].

A classe `std::array` representa um vetor estático de memória contígua que faz parte da [biblioteca padrão](https://en.wikipedia.org/wiki/Standard_Template_Library). 
A função _reverse_ deve ter a seguinte assinatura:
```c++
template <size_t SIZE>
void reverse ( std::array <std::string, SIZE> &arr );
```
Note nesta assinatura a presenta da palavra chave **template**. Essa construção permite que a variável SIZE (inteiro longo sem sinal) seja definida em tempo de compilação
por quem invocar sua função. Uma das vantagens de usar uma classe para definir o vetor, ao invés de usar um vetor tradicional do C++, é que a classe `std::array` 
possui várias funcionalidades já implementadas e disponíveis para uso. Por exemplo, se você desejar recuperar a quantidade de elementos em _arr_ basta invocar o método 
_size()_ , como em: `size_t tamanho = arr . size ();`, com isso não precisamos passaro comprimento de _arr_ para a função.

Outro ponto a se observar é uso do operador de referncia **\&**, associado ao parâmetro _arr_. Essa construção faz com que a função receba uma _referencia_ para a variável que é
passada no parâmetro quando a função é usada, fazendo com que operações em _arr_ sejam refletidas fora do escopo da função quando ela acaba. De forma similar ao que ocorria com 
vetores quando passados para funções em C, por isso a função é void, não precisando retornar o vetor na ordem reversa. 

Da mesma forma que C, quando funções em c++ recebem vetores básicos (conhecidos como _raw arrays_, ou aqueles que usam os \[\]) a função sempre recebe uma referencia, implicando 
que mudanças nos vetore são refletidas fora do escopo da função. No entanto, nesta função usamos o objeto do tipo `std::array`, neste caso, assim como quando usamos `std::vector` 
ou qualquer outro objeto, por padrão a **passagem é por valor**, implicando que mudanças no vetor recebido não são refletidas quando a função acaba. Para mudar esse comportamento
usamos o **\&** na frente do parâmetro desejado, fazendo com que a **passagem seja por referência**, assim o objeto `std::array` nesta função se comporta de forma similar aos
vetores comuns de C.

## Conhecimentos Necessários

Utilização de funções, strings, passagem de parâmetro por referência, uso da classe `std::array`, laços, uso da função `std::swap`.

**Observação**: Não é necessário criar um outro vetor para inverter os valores presentes no vetor passado por referência. A inversão pode ser feita internamente, 
ou seja, dentro do próprio vetor, com a ajuda de variáveis auxiliares.
