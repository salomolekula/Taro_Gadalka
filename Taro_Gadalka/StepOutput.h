#pragma once

#include <string>
#include <iostream>
#include <Windows.h>

void StringStepOutput ( std::string out ) {
    for ( int i = 0; i < std::size ( out ); i++) {
        std::cout << out[i];
        Sleep ( 60 );
    }
}
void SeparationStepOutput () {
    for ( int i = 0; i < 60; i++) {
        std::cout << "- ";
        Sleep ( 25 );
    }
    std::cout << "\n";
}