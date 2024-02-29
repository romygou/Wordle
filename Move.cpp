//
//  Move.cpp
// 

#include "Move.h"
#include <stdexcept>

namespace cs31
{

// a 5 letter word is a move. by default, each letter of the word is an invalid.
Move::Move()
{
    Piece p;  // invalid piece
    for( int i = 0; i < REQUIREDLENGTH; i++)
    {
        array[ i ] = p;
    }
}

// retrieves a letter in the ith place of the inputed word
Piece Move::getPiece( int i )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        return( array[ i ] );
    else
        throw std::logic_error( "invalid i value" );
}

// sets the ith place in a word to the desired letter
void  Move::setPiece( int i, char c )
{
    if (i >= 0 && i < REQUIREDLENGTH)
    {
        Piece p( c );
        array[ i ] = p;
    }
    else
        throw std::logic_error( "invalid i value" );
}

// construct a Piece for the Move from the Piece parameter but throw logic_error if the index is out of range
void  Move::setPiece( int i, Piece p )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        array[ i ] = p;
    else
        throw std::logic_error( "invalid i value" );
}

// construct a Piece for the Move from the first letter of the string parameter but throw logic_error if the index is out of range
void  Move::setPiece( int i, std::string s )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        setPiece( i, s.at( 0 ) );
    else
        throw std::logic_error( "invalid i value" );
}

void  Move::setPieces( std::string s )
{
    // for now...
    if (s.length() == 5)
    {
        setPiece(0, s.at(0));
        setPiece(1, s.at(1));
        setPiece(2, s.at(2));
        setPiece(3, s.at(3));
        setPiece(4, s.at(4));
    }else{
        throw std::logic_error("not a 5-character string");
    }
}

// stringify this Move
std::string Move::to_string() const
{
    std::string s;
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        s += array[ i ].getLetterAsString();
    }
    return( s );
}


}
