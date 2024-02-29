//
//  Score.cpp
//

#include "Score.h"
#include <stdexcept>

namespace cs31
{

// setup a default score - all WRONG ANSWER's
Score::Score()
{
    for( int i = 0; i < REQUIREDLENGTH; i++ )
    {
        array[ i ] = ANSWER::WRONG; //edited
    }
}

Score::Score( Move move, Move answer )
{
    int maybe = 0;
    
    //goes through and marks letters as either MAYBE or WRONG
    for (int i = 0; i < REQUIREDLENGTH; i++) //loops through each letter in move
    {
        for (int j = 0; j < REQUIREDLENGTH; j++) //loops through each letter in answer
        {
            if (move.getPiece(i).getLetter() == answer.getPiece(j).getLetter()) //if any letter in move is equal to any letter in answer
            {
                maybe = maybe + 1;
            }
        }
        
        //if the for-loop results in >1 maybes, mark the current letter as MAYBE
        if (maybe > 0)
        {
            array[i] = ANSWER::MAYBE;
        }
        
        //if the for-loop results in 0 maybes, mark the current letter as WRONG
        if (maybe == 0)
        {
            array[i] = ANSWER::WRONG;
        }
        maybe = 0; //resets maybe-count for next letter
    }
    
    //goes through and marks the second instance of duplicate letters in move as WRONG
    for (int i = 0; i < REQUIREDLENGTH; i++) //loops through each letter in move
    {
        for (int j = i + 1; j < REQUIREDLENGTH; j++) //loops through the letters in move that come after the ith letter
        {
            if (move.getPiece(i).getLetter() == move.getPiece(j).getLetter()) //if the ith letter in move has a duplicate
            {
                array[j] = ANSWER::WRONG; //marks the second instance of the letter as WRONG
            }
        }
    }
    
    //goes through and marks matching letters in move and answer as RIGHT
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        if (move.getPiece(i).getLetter() == answer.getPiece(i).getLetter())
        {
            array[i] = ANSWER::RIGHT;
        }
    }
    
    //goes through and marks the first instance of duplicate letters in move as WRONG if the second instance has already been marked RIGHT
    for (int i = 0; i < REQUIREDLENGTH; i++) //loops through each letter in move
    {
        for (int j = i + 1; j < REQUIREDLENGTH; j++) //loops through the letters in move that come after the ith letter
        {
            if ((move.getPiece(i).getLetter() == move.getPiece(j).getLetter()) & (array[j] == ANSWER::RIGHT) & (array[i] == ANSWER::MAYBE)) //if the letter has a duplicate AND the second instance is RIGHT AND the first instance is MAYBE
            {
                array[i] = ANSWER::WRONG; //marks the first instance as WRONG
            }
        }
    }
}

// trivial getter but throw logic_error if the index is out of range
ANSWER Score::getAnswer( int i )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        return( array[ i ] );
    else
        throw std::logic_error( "invalid i value" );
}

// stringify this Score
std::string Score::to_string() const
{
    std::string s = "";
    int mCount = 0;
    int rCount = 0;
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        switch( array[i] )
        {
            case ANSWER::WRONG: //edited
                // wrongs should not be printed at all
                s += "_";
                break;
            case ANSWER::RIGHT: //edited
                rCount++;
                s += "R";
                break;
            case ANSWER::MAYBE: //edite
                mCount++;
                s += "M";
                break;
        }
    }
    return( s );
}

bool Score::isExactMatch() const
{
    if (to_string() == "RRRRR")
    {
        return(true);
    } else {
        return(false);
    }
}

}
