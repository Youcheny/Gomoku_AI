//
//  main.cpp
//  Gomoku_AI
//
//  Created by Youcheng Ye on 12/27/18.
//  Copyright © 2018 Youcheng Ye. All rights reserved.
//

#include <iostream>
#include "Game.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    Game game;
    while (!game.isEnded()) {
        game.HostMove();
    }
    std::cout << "Thanks for playing!" << std::endl;
    return 0;
}
