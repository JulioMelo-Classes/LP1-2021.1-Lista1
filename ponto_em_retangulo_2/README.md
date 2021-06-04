# Ponto em Retângulo 2

Implemente um programa em C++ que recebe da entrada padrão um número indeterminado de
linhas, cada uma correspondendo a um caso de teste. Cada caso de teste contém informções
correspondentes a um possível retângulo e um ponto, ambos definidos no plano Cartesiano
2D. Para cada caso de teste o programa deve (1) verificar se o retângulo é válido e, em caso
verdadeiro (2) classificar o ponto em relação ao retângulo em uma das três possibilidades:
fora, na fronteira, ou dentro do retângulo.

Um retângulo é considerado válido se e somente se pelo menos uma das quatro coordenadas
dos vértices que o define for diferente, ou seja R1&ne;R2. Portanto, o programa deve aceitar
os chamados retângulos "degenerados" que formam uma linha vertical ou horizontal, como
por exemplo: IE(2; 5) x SD(2; 7) ou IE(-53;-4) x SD(-5;-4).

A classifição do posicionamento do ponto em relação ao retângulo deve ser feita
através da invocação da função implementada na [Ponto em Retângulo](../ponto_em_retangulo_1). 
Lembre que para a função _pt\_in\_rect_ funcionar corretamente é necessário informar como argumentos as coordenadas
do canto inferior esquerdo e superior direito. Portanto, seu programa deve analisar os
vértices de entrada e fazer os ajustes necessários (por exemplo, criando novos pontos a partir
das coordenadas originais) para satisfazer o pré-requisito da função de classificação.

Cada linha lida da entrada padrão deve corresponder a um caso de teste, tendo o formato:
x<sub>1</sub> y<sub>1</sub> x<sub>2</sub> y<sub>2</sub> x<sub>3</sub> y<sub>3</sub>, onde -1000 &le; x<sub>i</sub>,y<sub>i</sub> &le; 1000. 
Os quatro primeiros valores representam as coordenadas de dois vértices quaisquer do retângulo: R1 = (x<sub>1</sub>, y<sub>1</sub>) e R2 = (x<sub>2</sub>, y<sub>2</sub>).
Note que esses dois vértices podem representar qualquer um dos quatro possíveis cantos de
um retângulo: inferior esquerdo, inferior direito, superior esquerdo, ou superior direito. Os
últimos dois valores representam as coordenadas do ponto, P = (x<sub>3</sub>, y<sub>3</sub>), a ser testado contra
o retângulo definido na mesma linha.

## Exemplo de entrada/saída

Entrada | Saída
--------|------
`-3 -1 3 1 0 0` </br> `2 2 9 7 4 2` </br> `7 9 2 2 2 7` </br> `4 5 4 5 -1 -2` </br> `-3 0 5 5 1 6` </br> `-3 0 5 5 6 4` </br> `1 2 -5 7 -1 6` </br> `3 7 -2 -2 2 2` | inside </br> border </br> border </br> invalid </br> outside </br> outside </br> inside </br> inside

## Conhecimentos necessários

Utilização de funções, reutilização de código, tipos heterogêneos (struct), passagem de parâmetro
por referência constante, enumerações, Geometria 2D, condicionais, expressões lógicas.





