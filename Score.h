//
//  Score.h

#ifndef SCORE_H
#define SCORE_H

#include "Settings.h"
#include "Move.h"
#include <string>

namespace cs31
{

// The Score object compares a Move to the winnning Move in the Wordle game
// It holds an array of ANSWER of the required length
class Score
{
public:
    // By default, a Score will hold all WRONG ANSWER's
    Score();
    // create the ANSWER array from the supplied Move and answer
    Score( Move move, Move answer );
    
    // called whenever a Score is displayed
    std::string to_string() const;
    
    // is the ANSWER array all RIGHT ANSWER's?
    bool isExactMatch() const;

    // trivial getter
    ANSWER getAnswer( int i );
private:
    // the ordered set of ANSWER that makes up this Score
    ANSWER array[ REQUIREDLENGTH ];
};

}

#endif
