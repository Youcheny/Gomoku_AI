//
//  Board.cpp
//  Gomoku_AI
//
//  Created by Youcheng Ye on 12/27/18.
//  Copyright © 2018 Youcheng Ye. All rights reserved.
//

#include "Board.hpp"
#include <iostream>

Board::Board() {
    // Initialize board state
    std::vector<std::vector<State>> initTo(19, std::vector<State>(19, Unoccupied));
    mState = initTo;
}

State Board::Get(int r, int c) const {
    return mState[r][c];
}

std::ostream& operator << (std::ostream& out, const Board& b) {
    out << "Board:" << std::endl;
    for (int i=0; i<19; ++i) {
        for (int j=0; j<19; ++j) {
            switch (b.mState[i][j]) {
                case BlackOccupied:
                    out << 'B' << '\t';
                    break;
                case WhiteOccupied:
                    out << 'W' << '\t';
                    break;
                case Unoccupied:
                    out << i * 19 + j + 1 << '\t';
                    break;
                default:
                    out << "Err" << '\t';
                    break;
            }
        }
        out << std::endl;
    }
    return out;
}
