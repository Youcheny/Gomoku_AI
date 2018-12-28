//
//  Game.cpp
//  Gomoku_AI
//
//  Created by Youcheng Ye on 12/28/18.
//  Copyright © 2018 Youcheng Ye. All rights reserved.
//

#include "Game.hpp"
#include "Board.hpp"
#include "Judge.hpp"
#include <string>
#include <sstream>

Game::Game() {
    mBoard = new Board();
    mJudge = new Judge(mBoard);
}

Game::~Game() {
    delete mBoard;
    delete mJudge;
}

void Game::HostMove() {
    std::cout << (*mJudge);
    std::cout << "Make Move: ";
    std::string line;
    int move;
    std::cin >> line;
    move = std::atoi(line.c_str());
    MoveResult result = mJudge->MakeMove(mJudge->GetTurn(), move);
    if (result == BlackWins)
        std::cout << "Black Wins" << std::endl;
    else if (result == WhiteWins)
        std::cout << "White Wins" << std::endl;
}

bool Game::isEnded() {
    return mJudge->GetTurn() == EndGame;
}

std::ostream& operator << (std::ostream& out, const Game& g) {
    out << (*(g.mJudge));
    return out;
}
