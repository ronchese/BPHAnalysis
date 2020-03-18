#ifndef BPHAnalysis_RecoDecay_BPHMomentumSelect_h
#define BPHAnalysis_RecoDecay_BPHMomentumSelect_h
/** \class BPHMomentumSelect
 *
 *  Description: 
 *     Base class for candidate selection at momentum sum level
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------


//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
class BPHDecayMomentum;

//---------------
// C++ Headers --
//---------------


//              ---------------------
//              -- Class Interface --
//              ---------------------

class BPHMomentumSelect {

 public:

  /** Constructor
   */
  BPHMomentumSelect();

  // deleted copy constructor and assignment operator
  BPHMomentumSelect           ( const BPHMomentumSelect& x ) = delete;
  BPHMomentumSelect& operator=( const BPHMomentumSelect& x ) = delete;

  /** Destructor
   */
  virtual ~BPHMomentumSelect();

  /** Operations
   */
  /// accept function
  virtual bool accept( const BPHDecayMomentum& cand ) const = 0;

 private:

};


#endif

