//
//  Board.cpp
//

#include "Board.h"
#include <stdexcept>
#include <string>
#include <iostream>

namespace cs31
{
    Board::Board() : mRoundCount( 0 )
    {
        
    }
    
    // save this Move and Score into the set of Moves and Scores being managed by this Board
    void Board::endRound( Move m, Score s )
    {
        if (mRoundCount < TOTALROUNDSALLOWED)
        {
            moves[ mRoundCount ] = m;
            scores[ mRoundCount ] = s;
            // increment to the next round
            mRoundCount++;
        }
        else
        {
            // throw an error rather than walk off the edge of the array
            std::logic_error le( "invalid roundcount value" );
            throw( le );
        }
    }
    
    // print this Board
    // the Wordle object repetitively calls this operation as the game play proceeds
    std::string Board::display( ) const
    {
        using namespace std;
        
        std::string s = "\t\t  CS31Wordle Game\n";
        if (mRoundCount > 0)
        {
            int i = 0;
            while( i < mRoundCount )
            {
                s += std::to_string( i+1 );
                s += " : ";
                s += moves[ i ].to_string();
                s += " - ";
                s += scores[ i ].to_string();
                s += "\n";
                i++;
            }
        }
        
        return( s );
    }
    
int Board::getCurrentRound() const
    {
        if (mRoundCount >= 0 & mRoundCount <= 8)
        {
            return(mRoundCount);
        }else{
            throw std::logic_error("invalid round count");
        }
        return( -10 );
    }

Move Board::getMoveForRound( int round ) const
    {
        Move m;
        if (round >= 0 & round <= getCurrentRound() & round <= 8)
        {
            return(moves[round]);
        }else{
            throw std::logic_error("invalid getMove round value");
        }
        return(m);
    }

Score Board::getScoreForRound( int round ) const
    {
        Score s;
        if (round >= 0 & round <= getCurrentRound() & round <= 8)
        {
            return(scores[round]);
        }else{
            throw std::logic_error("invalid getScore round value");
        }
        return(s);
    }

    
}
