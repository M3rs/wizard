//
// main.cpp
// Wizard
//
// Created by Andy Moran on 4/9/13
// Copyright (c) 2014 Andy Moran. All rights reserved.
//

#include <iostream>

#include "game.h"

int main(int argc, const char * argv[])
{
    std::cout << "Beginning of main \n";

    Game game;

    game.play();

    std::cout << "Exiting main \n";

    return 0;
}
