//
//  Judge.hpp
//  Gomoku_AI
//
//  Created by Youcheng Ye on 12/28/18.
//  Copyright © 2018 Youcheng Ye. All rights reserved.
//

#ifndef Judge_hpp
#define Judge_hpp

#include <stdio.h>
#include <utility>
#include <iostream>

enum MoveResult {
    BlackWins,
    WhiteWins,
    NeitherWins,
    InvalidMove
};

enum Turn {
    BlackTurn,
    WhiteTurn,
    EndGame
};

class Judge {
public:
    Judge(class Board* board);
    ~Judge();
    MoveResult JudgeMove(Turn t, int r, int c);
    MoveResult JudgeMove(Turn t, int move);
    Turn GetTurn() {return mTurn;};
    friend std::ostream& operator << (std::ostream& out, const Judge& j);
protected:
    MoveResult JudgeWinner(int r, int c);
    int CountDepth(int r, int c, const std::pair<int, int>& dir);
    class Board* mBoard;
    Turn mTurn;
};

std::ostream& operator << (std::ostream& out, const Judge& j);

#endif /* Judge_hpp */
