# Intervalos

Escreva um programa em C++ que lê um número não conhecido de valores inteiros e conta quantos deles estão em cada um dos intervalos \[0; 25), \[25; 50), \[50; 75), \[75; 100) 
e fora desses intervalos. Para ler um número indeterminado de valores basta incluir o comando de extração associado ao `std::cin` como condição de parada em um laço (ver abaixo).
```c++
int x;
while( cin >> std::ws >> x) {
  // realização da contagem em relação aos intervalos
}
```
Após encerrada a entrada de dados, o programa deve imprimir a **porcentagem** de números para cada um dos quatro intervalos e de números fora deles, nessa ordem, um por linha 
e representados com quatro casas de precisão. Para definir a precisão use a função `std::setprecision(4)` antes do uso do `cout`.

## Exemplos de Entrada/Saída

<table>
  <tr>
    <th>Entrada</th> <th>Saída</th>
  </tr>
  <tr>
    <td>
<pre>
-9 -8
1 5 15 20
25 30 35 40 45 46 47
50 55 60
78 85 90 99
100 120
</pre>
    </td>
    <td>
<pre>
18.18
31.82
13.64
18.18
18.18
</pre>
    </td>
  </tr>
    <tr>
    <td>
<pre>
25 30 35 40 45 46 47
78 85 90 99
100 120
</pre>
    </td>
    <td>
<pre>
0
53.85
0
30.77
15.38
</pre>
    </td>
  </tr>
</table>

## Conhecimentos Necessários

Leitura de entrada padrão, escrita em saída padrão, laços, condicionais, _type casting_, saída formatada, uso de vetores.
