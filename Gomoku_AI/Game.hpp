//
//  Game.hpp
//  Gomoku_AI
//
//  Created by Youcheng Ye on 12/28/18.
//  Copyright © 2018 Youcheng Ye. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <iostream>

class Game {
public:
    Game();
    ~Game();
    void HostMove();
    bool isEnded();
    friend std::ostream& operator << (std::ostream& out, const Game& g);
private:
    class Board* mBoard;
    class Judge* mJudge;
    
};

std::ostream& operator << (std::ostream& out, const Game& g);
#endif /* Game_hpp */
