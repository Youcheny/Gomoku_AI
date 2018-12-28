//
//  Player.hpp
//  Gomoku_AI
//
//  Created by Youcheng Ye on 12/28/18.
//  Copyright © 2018 Youcheng Ye. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>

class Player {
public:
    Player(class Judge* judge);
    virtual ~Player();
    virtual void MakeMove() = 0;
protected:
    class Judge* mJudge;
};

#endif /* Player_hpp */
