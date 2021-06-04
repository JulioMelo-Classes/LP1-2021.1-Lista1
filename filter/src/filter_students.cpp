#include <iostream>
#include <iterator>

int * filter( int * first_, int *last_ )
{
    // Percorrer o intervalo do início ao fim, analisando cada elemento
    while( first_ != last_ )
    {
        // Avaliar se o elemento deve ser filtrado ou não
        if ( *first_ <= 0 ) // rejeitado
        {
            // Deslocar todos os elementos a partir do first, 1 posição para esquerda.
            auto i( first_ );
            while( i != last_-1 )
            {
                *i = *(i+1);
                ++i;
            }
            // Potencial 'bug'!!! Não esquecer de atualizar o last_.
            last_--;
        }
        else
        {
            // Avançar e aceitar o elemento.
            first_++;
        }
    }

    return first_; //
}

/*
 *   +--- fast
 *   |
 *   V
 * +---+---+---+---+---+---+---+---+---+---+
 * |   |   |   |   |   |   |   |   |   |   |
 * +---+---+---+---+---+---+---+---+---+---+
 *
 *
 *
 */
int * mega_filter( int * first_, int * last_ )
{
    auto slow( first_ );
    auto fast( first_ );
    // Processar cada elemento do vetor para classificar/filtrar.
    while( fast != last_ )
    {
        // Critério de seleção/filtragem.
        if( *fast > 0 )
        {
            //std::swap( *slow, *fast ); // mover o elemento para o intervalo dos aceitos.
            *slow = *fast;
            slow++;// Incrementar o intervalo dos selecionados/filtrados.
        }

        fast++; // O fast sempre avança pois o elemento atual foi classificado/filtrado
    }

    return slow; // marca o final da região (exclusive) dos selecionados/filtrados.
}

int main( )
{
    int A[] = { -2, -8, 6, 7, -3, 10, 1, 0, -3, 7 };
    size_t len = sizeof(A) / sizeof(int);

    // Printing the filtered array.
    std::cout << ">>> Original array  = [ ";
    //std::copy( std::begin(A), std::end(A),  std::ostream_iterator<int>( std::cout, " " ) );
    for( auto i(0u) ; i < len ; ++i )
        std::cout << A[i] << " ";
    std::cout << "], Size = " <<  std::distance( std::begin(A), std::end(A) ) << "\n";

    // Filtering
    auto new_end = mega_filter( std::begin(A), std::end(A) );

    // Printing the filtered array.
    std::cout << ">>> FILTERED array  = [ ";
    std::copy( std::begin(A), new_end,  std::ostream_iterator<int>( std::cout, " " ) );
    std::cout << "], Size = " <<  std::distance( std::begin(A), new_end ) << "\n";

    return EXIT_SUCCESS;
}



