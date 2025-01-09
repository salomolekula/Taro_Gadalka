#pragma once

#include <random>
#include <tuple>
#include <vector>
#include <string>
#include <Windows.h>

#include "RandomCards.h"


struct TarotCard {
    int id;
    std::string name;
    std::tuple<std::string , std::string , std::string> meanings_upright;
    std::tuple<std::string , std::string , std::string> meanings_reversed;
};

struct DrawnCard {
    TarotCard card;
    bool isReversed;
};


// Функция для перемешивания колоды
void shuffleDeck ( std::vector<TarotCard>& deck ) {
    std::srand ( std::time ( 0 ) );
    std::shuffle ( deck.begin ( ) , deck.end ( ) , std::default_random_engine ( std::rand ( ) ) );
}


std::vector<DrawnCard> drawCards(std::vector<TarotCard>& deck) {
    if ( deck.size ( ) < 3 ) {
        throw std::runtime_error ( "Недостаточно карт в колоде." );
    }

    std::vector<DrawnCard> result;
    std::vector<int> drawnCards;

    std::srand ( std::time ( 0 ) );
    std::default_random_engine generator ( std::rand ( ) );
    std::uniform_int_distribution<int> distribution ( 0 , deck.size ( ) - 1 );
    std::uniform_int_distribution<int> orientationDistribution ( 0 , 1 );

    // Выбираем карту для прошлого
    int index = distribution ( generator );
    bool isReversed = orientationDistribution ( generator );
    result.push_back ( { deck[index], isReversed } );
    drawnCards.push_back ( index );

    // Выбираем карту для настоящего
    int index2;
    do {
        index2 = distribution ( generator );
    } while ( std::find ( drawnCards.begin ( ) , drawnCards.end ( ) , index2 ) != drawnCards.end ( ) );
    bool isReversed2 = orientationDistribution ( generator );
    result.push_back ( { deck[index2], isReversed2 } );
    drawnCards.push_back ( index2 );

    // Выбираем карту для будущего
    int index3;
    do {
        index3 = distribution ( generator );
    } while ( std::find ( drawnCards.begin ( ) , drawnCards.end ( ) , index3 ) != drawnCards.end ( ) );
    bool isReversed3 = orientationDistribution ( generator );
    result.push_back ( { deck[index3], isReversed3 } );
    drawnCards.push_back ( index3 );

    return result;
}