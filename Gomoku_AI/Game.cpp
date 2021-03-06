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
#include "Player.hpp"
#include "HumanPlayer.hpp"
#include "AIPlayer.hpp"
#include <string>
#include <sstream>

Game::Game() {
    mBoard = new Board();
    mJudge = new Judge(mBoard);
}

Game::Game(PlayerType pt1, PlayerType pt2): Game() {
    switch (pt1) {
        case Human:
            mPlayer1 = new HumanPlayer(mJudge, Black);
            break;
        case AI:
            mPlayer1 = new AIPlayer(mJudge, Black);
            break;
    }
    switch (pt2) {
        case Human:
            mPlayer2 = new HumanPlayer(mJudge, White);
            break;
        case AI:
            mPlayer2 = new AIPlayer(mJudge, White);
            break;
    }
}

Game::~Game() {
    delete mBoard;
    delete mJudge;
    delete mPlayer1;
    delete mPlayer2;
}

void Game::HostRound() {
    PrintStatus();
    mPlayer1->MakeMove();
    if (isEnded()) return;
    PrintStatus();
    mPlayer2->MakeMove();
}

bool Game::isEnded() {
    return mJudge->GetTurn() == EndGame;
}

void Game::PrintStatus() const {
    std::cout << (*mJudge);
}


std::ostream& operator << (std::ostream& out, const Game& g) {
    out << (*(g.mJudge));
    return out;
}
