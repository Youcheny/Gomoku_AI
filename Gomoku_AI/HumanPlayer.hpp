//
//  HumanPlayer.hpp
//  Gomoku_AI
//
//  Created by Youcheng Ye on 12/28/18.
//  Copyright © 2018 Youcheng Ye. All rights reserved.
//

#ifndef HumanPlayer_hpp
#define HumanPlayer_hpp

#include "Player.hpp"
#include <stdio.h>

class HumanPlayer : public Player {
public:
    HumanPlayer(class Judge* judge, FactionType faction);
    void MakeMove() override;
};

#endif /* HumanPlayer_hpp */
