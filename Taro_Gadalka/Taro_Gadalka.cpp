#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <string>
#include <algorithm>
#include <tuple>
#include <Windows.h>

#include "Beta_CreateTarotDeck.h"
#include "StepOutput.h"

int main() {
    std::setlocale ( LC_ALL , "RU" );
    std::vector<TarotCard> tarotDeck = createTarotDeck ( );
    shuffleDeck ( tarotDeck );

    try {
        std::vector<DrawnCard> selectedCards = drawCards ( tarotDeck );
        std::cout << "Гадание на прошлое, настоящее и будущее:" << std::endl;

        // Прошлое
        StringStepOutput ( "Прошлое:\n" );

        Sleep ( 500 );
        StringStepOutput ( selectedCards[0].card.name + " - " + "\n" );
        Sleep ( 500 );

        if ( selectedCards[0].isReversed ) {
            StringStepOutput ( std::get<0> ( selectedCards[0].card.meanings_reversed ) );
            Sleep ( 300 );
            StringStepOutput ( " (перевернутая)" );
            Sleep ( 300 );
            StringStepOutput ( "\n" );
            SeparationStepOutput ( );
            //std::cout << std::get<0> ( selectedCards[0].card.meanings_reversed ) << " (перевернутая)" << std::endl;
        }
        else {
            StringStepOutput ( std::get<0> ( selectedCards[0].card.meanings_upright ) );
            Sleep ( 300 );
            StringStepOutput ( "\n" );
            SeparationStepOutput ( );
            //std::cout << std::get<0> ( selectedCards[0].card.meanings_upright ) << std::endl;
        }

        Sleep ( 1000 );

        // Настоящее
        StringStepOutput ( "Настоящее:\n" );

        Sleep ( 500 );
        StringStepOutput ( selectedCards[1].card.name + " - " );
        Sleep ( 500 );

        if (selectedCards[1].isReversed) {
            StringStepOutput ( std::get<1> ( selectedCards[1].card.meanings_reversed ) );
            Sleep ( 300 );
            StringStepOutput ( " (перевернутая)" );
            Sleep ( 300 );
            StringStepOutput ( "\n" );
            SeparationStepOutput ( );
            //std::cout << std::get<1> ( selectedCards[1].card.meanings_reversed ) << " (перевернутая)" << std::endl;
        }
        else {
            StringStepOutput ( std::get<1> ( selectedCards[1].card.meanings_upright ) );
            Sleep ( 300 );
            StringStepOutput ( "\n" );
            SeparationStepOutput ( );
            //std::cout << std::get<1> ( selectedCards[1].card.meanings_upright ) << std::endl;
        }

        Sleep ( 1000 );

       // Будущее
        StringStepOutput ( "Будущее:\n" );

        Sleep ( 500 );
        StringStepOutput ( selectedCards[2].card.name + " - " );
        Sleep ( 500 );
        
        if (selectedCards[2].isReversed) {
            StringStepOutput ( std::get<2> ( selectedCards[2].card.meanings_reversed ) );
            Sleep ( 300 );
            StringStepOutput ( " (перевернутая)" );
            Sleep ( 300 );
            StringStepOutput ( "\n" );
            SeparationStepOutput ( );
            //std::cout << std::get<2> ( selectedCards[2].card.meanings_reversed ) << " (перевернутая)" << std::endl;
        }
        else {
            StringStepOutput ( std::get<2> ( selectedCards[2].card.meanings_upright ) );
            Sleep ( 300 );
            StringStepOutput ( "\n" );
            SeparationStepOutput ( );
            //std::cout << std::get<2> ( selectedCards[2].card.meanings_upright ) << std::endl;
        }

        
    }
    catch ( const std::runtime_error& error ) {
        std::cerr << "Ошибка: " << error.what ( ) << std::endl;
        return 1;
    }
    return 0;
}