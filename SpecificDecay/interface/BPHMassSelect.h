#ifndef BPHAnalysis_SpecificDecay_BPHMassSelect_h
#define BPHAnalysis_SpecificDecay_BPHMassSelect_h
/** \class BPHMassSelect
 *
 *  Description: 
 *     Class for candidate selection by invariant mass (at momentum sum level)
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "BPHAnalysis/RecoDecay/interface/BPHMomentumSelect.h"
#include "BPHAnalysis/SpecificDecay/interface/BPHMassCuts.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "BPHAnalysis/RecoDecay/interface/BPHDecayMomentum.h"

//---------------
// C++ Headers --
//---------------


//              ---------------------
//              -- Class Interface --
//              ---------------------

class BPHMassSelect: public BPHMomentumSelect, public BPHMassCuts {

 public:

  /** Constructor
   */
  BPHMassSelect( double minMass, double maxMass ): BPHMassCuts( minMass,
                                                                maxMass ) {
  }

  // deleted copy constructor and assignment operator
  BPHMassSelect           ( const BPHMassSelect& x ) = delete;
  BPHMassSelect& operator=( const BPHMassSelect& x ) = delete;

  /** Destructor
   */
  ~BPHMassSelect() override = default;

  /** Operations
   */
  /// select particle
  bool accept( const BPHDecayMomentum& cand ) const override {
    double mass = cand.composite().mass();
    return ( ( mass >= mMin ) && ( mass <= mMax ) );
  }
};


#endif

