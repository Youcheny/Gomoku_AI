//
//  Judge.cpp
//  Gomoku_AI
//
//  Created by Youcheng Ye on 12/28/18.
//  Copyright © 2018 Youcheng Ye. All rights reserved.
//

#include "Judge.hpp"
#include "Board.hpp"

Judge::Judge(Board* board)
: mBoard(board)
, mTurn(BlackTurn) {
    
}

Judge::~Judge() {
    
}

MoveResult Judge::JudgeMove(Turn t, int r, int c) {
    if (r < 0 || r > 15 || c < 0 || c > 15 || t != mTurn || mTurn == EndGame)
        return InvalidMove;
    if (mBoard->mState[r][c] == Unoccupied) {
        // change the board accordingly
        if (mTurn == BlackTurn)
            mBoard->mState[r][c] = BlackOccupied;
        else mBoard->mState[r][c] = WhiteOccupied;
        // determine if there is a winnner
        MoveResult result = JudgeWinner(r, c);
        // change mTurn accordingly
        if (result == BlackWins || result == WhiteWins)
            mTurn = EndGame;
        else if (mTurn == BlackTurn)
            mTurn = WhiteTurn;
        else mTurn = BlackTurn;
        return result;
    }
    else return InvalidMove;
}

MoveResult Judge::JudgeMove(Turn t, int move) {
    --move;
    return JudgeMove(t, move / 15, move % 15);
}

MoveResult Judge::JudgeWinner(int r, int c) {
    std::vector<std::pair<int, int>> directions = {
        std::make_pair(-1, 0),
        std::make_pair(-1, 1),
        std::make_pair(0, 1),
        std::make_pair(1, 1)
    };
    for (std::pair<int, int>& dir : directions) {
        std::pair<int, int> negdir = std::make_pair(-dir.first, -dir.second);
        if (CountDepth(r, c, dir) + CountDepth(r, c, negdir) - 1 >= 5) {
            if (mTurn == BlackTurn)
                return BlackWins;
            return WhiteWins;
        }
    }
    return NeitherWins;
}

int Judge::CountDepth(int r, int c, const std::pair<int, int>& dir) {
    int depth = 0;
    while (r >= 0 && c >= 0 && r <= 15 && c <= 15) {
        if (mTurn == BlackTurn) {
            if (mBoard->mState[r][c] == BlackOccupied)
                ++depth;
            else break;
        }
        else {
            if (mBoard->mState[r][c] == WhiteOccupied)
                ++depth;
            else break;
        }
        r += dir.first;
        c += dir.second;
    }
    return depth;
}

std::ostream& operator << (std::ostream& out, const Judge& j) {
    if (j.mTurn == EndGame) {
        out << "End of Game" << std::endl;
        return out;
    }
    if (j.mTurn == BlackTurn) {
        out << "Black Turn" << std::endl;
    }
    else {
        out << "White Turn" << std::endl;
    }
    out << (*(j.mBoard));
    return out;
}
