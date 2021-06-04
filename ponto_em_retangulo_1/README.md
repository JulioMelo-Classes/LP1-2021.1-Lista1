## Ponto em retângulo

Considerando a estrutura abaixo para representar as coordenadas Cartesianas de um ponto no plano bidimensional (2D), implemente
uma função em C++ que verifica se um ponto P = (x<sub>p</sub>,y<sub>p</sub>), determinado por suas coordenadas cartesianas, está localizado
**dentro, na borda ou fora** de um retângulo definido por dois pontos: o canto inferior esquerdo IE = (x<sub>ie</sub>,y<sub>ie</sub>) e o canto
superior direito SD = (x<sub>sd</sub>, y<sub>sd</sub>).

![Diagrama](https://gdurl.com/gtfp)

Struct que descreve um ponto:
```c++
struct Ponto {
  int x; // ! < coordenada X do ponto.
  int y; // ! < coordenada y do ponto.
  // Construtor padrão
  Ponto ( int xi =0, int yi =0 ) : x{xi}, y{yi} // copia args para os campos x e y
  { /* nada */ }
};
```

A função a ser criada deve receber 3 pontos como referências constante representando, respectivamente,
os dois pontos, IE e SD, que definem um retângulo, e o ponto a ser testado P. **Assuma** que os pontos IE e SD definem um retângulo válido, i.e IE&ne;SD 
(pelo menos uma coordenada de um ponto é diferente do outro). Dessa forma a função deve ter a seguinte assinatura:

```c++
int pt_in_rect ( const Ponto &R1, cons t Ponto &R2, const Ponto &P );
```

A seguir, a função deve realizar testes e indicar se o ponto P está dentro, na borda ou fora
do retângulo, retornando, respectivamente, os valores 0, 1 ou 2 para cada caso ora descrito.

Se desejar tornar seu código mais inteligível, você pode utilizar a enumeração abaixo:
```c++
enum location_t : int { INSIDE =0, BORDER =1, OUTSIDE =2 };
```
Neste caso, modifique na assinatura da função o tipo do retorno para que seja `location_t`.

## Conhecimentos necessários

Utilização de funções, tipos heterogêneos (struct), passagem de parâmetro por referência constante,
uso de enumerações, condicionais, expressões lógicas.

**Observações**: Veja que, diferente das definições em C, definimos uma função dentro da struct. Esta função, especialmente, permite inicializar a struct de uma
forma mais simples, ao invés de setar os valores de x e y ou usar o inicializador inline de C. Para _instanciar_ uma variável do tipo da struct Ponto e colocar
valores específicos de x e y apenas fazemos: `Ponto p1 = Ponto(12,32);`. Essa forma é relativamente simples, e talvez fosse melhor usar a inicialização em C (`Ponto p1 = {12,32}`),
mas usando os construtores, podemos fazer coisas mais complexas, como chamar funções ou realizar checagens durante a incialização dos campos.

