#pragma once



// Структура для представления карты Таро с прямыми и перевернутыми значениями
struct TarotCard;
struct DrawnCard;

// Функция для перемешивания колоды
void shuffleDeck ( std::vector<TarotCard>& deck );
