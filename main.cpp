//
//  main.cpp
//  Wordle
//

#include <iostream>
#include "Wordle.h"
#include "Move.h"
#include "Score.h"

void clearScreen( );

// interactively play Wordle
int main()
{
    using namespace cs31;
    using namespace std;
    
    /*
    //testing individual parts of the program

    Move m1;
    m1.setPieces("candy");
    Move m2;
    m2.setPieces("CANDY");
    Score s1(m1, m2);
    assert(s1.isExactMatch());
    
    Board board;
    assert(board.getCurrentRound() == 0);
    m1.setPieces("apple");
    m2.setPieces("candy");
    Score s2(m1, m2);
    board.endRound(m1, s2);
    assert( board.getCurrentRound() == 1 );
    assert( board.getMoveForRound( 0 ).to_string() == "APPLE" );
    assert( board.getScoreForRound( 0 ).to_string() == "M____" );
    
    Board board3;
    assert(board3.getCurrentRound() == 0);
    m1.setPieces("adrrr");
    m2.setPieces("candy");
    Score s3(m1, m2);
    board3.endRound(m1, s3);
    assert( board3.getCurrentRound() == 1 );
    assert( board3.getMoveForRound( 0 ).to_string() == "ADRRR" );
    assert( board3.getScoreForRound( 0 ).to_string() == "MM___" );
    
    Board board4;
    assert(board4.getCurrentRound() == 0);
    m1.setPieces("caddy");
    m2.setPieces("asody");
    Score s4(m1, m2);
    board4.endRound(m1, s4);
    assert( board4.getCurrentRound() == 1 );
    assert( board4.getMoveForRound( 0 ).to_string() == "CADDY" );
    assert( board4.getScoreForRound( 0 ).to_string() == "_M_RR" );
    
    Wordle game( "happy" );
    Move m;
    Score s;
    m = game.play( "shark" );
    s = game.endRound( m );
    m = game.play( "rover" );
    s = game.endRound( m );
    m = game.play( "cabby" );
    s = game.endRound( m );
    m = game.play( "drive" );
    s = game.endRound( m );
    m = game.play( "fight" );
    s = game.endRound( m );
    m = game.play( "every" );
    s = game.endRound( m );
    m = game.play( "eight" );
    s = game.endRound( m );
    m = game.play( "happy" );
    s = game.endRound( m );
    assert(game.answer() == "HAPPY" );
    assert( game.gameIsOver( ) );
    assert( game.determineGameOutcome() == GAMEOUTCOME::GAMEWON );
    */
    
    clearScreen();
    
    // by default, no cheating - pick a random word
    Wordle game;
    
    bool forceEnd = false;
    std::string action, turn, message = "(p)lay (q)uit: ";
    cout << game.display( message ) << endl;
    
    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                forceEnd = true;
                break;
            case 'p':
            case 'P':
                if (game.determineGameOutcome() == GAMENOTOVER)
                {
                    // acquire the entered word
                    getline( cin, turn );
                    // if the word is valid, build a move
                    // for this round of play
                    if (game.isValid(turn))
                    {
                        Move m = game.play( turn );
                        game.endRound(m);
                    }
                    else
                    {
                        // turn was not a valid word and does not count
                        cout << turn << " was not a Dictionary word!" << endl;
                    }
                }
                break;
        }
        if (!game.gameIsOver())
        {
            // repetitively display the board
            cout << game.display( message ) << endl;
        }
        else
        {
            // once the game is over, finally display the board and
            // show the game outcome and the winning word
            cout << game.display( game.gameOutcomeAsString() ) << endl;
            cout << "The winning word was: " << game.answer() << endl;
        }
    } while( !game.gameIsOver() && !forceEnd );
    
    // destroy the in-memory database of five letter words managed by
    // the Dictionary object
    Singleton::destroySingleton();

    return( 0 );
}



void clearScreen();



///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif

