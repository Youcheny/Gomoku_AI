//
//  HumanPlayer.cpp
//  Gomoku_AI
//
//  Created by Youcheng Ye on 12/28/18.
//  Copyright © 2018 Youcheng Ye. All rights reserved.
//

#include "HumanPlayer.hpp"
#include "Judge.hpp"
#include <iostream>

HumanPlayer::HumanPlayer(Judge* judge): Player(judge) {
    
}

void HumanPlayer::MakeMove() {
    // Human Player prompts the user for move
    std::cout << (*mJudge);
    if (mJudge->GetTurn() == EndGame) {
        std::cout << "Game Has Ended." << std::endl;
        return;
    }
    switch (mJudge->GetTurn()) {
        case BlackTurn:
            std::cout << "Black ";
            break;
        case WhiteTurn:
            std::cout << "White ";
            break;
        default:
            break;
    }
    std::cout << "Make Move: ";
    std::string line;
    int move;
    std::cin >> line;
    move = std::atoi(line.c_str());
    MoveResult result = mJudge->JudgeMove(mJudge->GetTurn(), move);
    switch (result) {
        case BlackWins:
            std::cout << "Black Wins" << std::endl;
            break;
        case WhiteWins:
            std::cout << "White Wins" << std::endl;
            break;
        default:
            break;
    }
}
