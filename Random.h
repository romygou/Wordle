//
//  Random.h
//

#ifndef Random_h
#define Random_h

namespace cs31
{
    
// This class provides a random number which by default will be one of 26 different values between 0-25 inclusive.
class Random
{
public:
    Random( int maxValue = 25 ); // by default, 0-25
    // generate a random number
    void random();
    // retrieve the previously generated random number
    int  getValue( ) const;
private:
    int  mValue;
    // the maximum desired value
    // the minimum desired value will be zero 
    int  mMaxValue;
};

    
}
#endif /* Random_h */
