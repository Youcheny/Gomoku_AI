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
    std::vector<std::vector<State>> initTo(15, std::vector<State>(15, Unoccupied));
    mState = initTo;
}

State Board::Get(int r, int c) const {
    return mState[r][c];
}

std::ostream& operator << (std::ostream& out, const Board& b) {
    out << "Board:" << std::endl;
    for (int i=0; i<15; ++i) {
        for (int j=0; j<15; ++j) {
            switch (b.mState[i][j]) {
                case BlackOccupied:
                    out << 'B' << '\t';
                    break;
                case WhiteOccupied:
                    out << 'W' << '\t';
                    break;
                case Unoccupied:
                    out << i * 15 + j + 1 << '\t';
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
