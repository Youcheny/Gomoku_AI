//
//  Board.hpp
//  Gomoku_AI
//
//  Created by Youcheng Ye on 12/27/18.
//  Copyright © 2018 Youcheng Ye. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <vector>
#include "Judge.hpp"

enum State {
    WhiteOccupied,
    BlackOccupied,
    Unoccupied
};

class Board {
public:
    Board();
    State Get(int r, int c) const;
    friend std::ostream& operator << (std::ostream& out, const Board& b);
    friend Judge;
protected:
    std::vector<std::vector<State>> mState;
    
    
};

std::ostream& operator << (std::ostream& out, const Board& b);

#endif /* Board_hpp */
