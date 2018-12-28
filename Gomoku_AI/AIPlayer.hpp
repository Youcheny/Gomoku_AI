//
//  AIPlayer.hpp
//  Gomoku_AI
//
//  Created by Youcheng Ye on 12/28/18.
//  Copyright © 2018 Youcheng Ye. All rights reserved.
//

#ifndef AIPlayer_hpp
#define AIPlayer_hpp

#include "Player.hpp"
#include <stdio.h>

class AIPlayer : public Player {
public:
    AIPlayer(class Judge* judge);
    void MakeMove() override;
};

#endif /* AIPlayer_hpp */
