#ifndef BPHAnalysis_SpecificDecay_BPHParticlePtSelect_h
#define BPHAnalysis_SpecificDecay_BPHParticlePtSelect_h
/** \class BPHParticlePtSelect
 *
 *  Description: 
 *     Class for particle selection by Pt
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "BPHAnalysis/RecoDecay/interface/BPHRecoSelect.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "DataFormats/RecoCandidate/interface/RecoCandidate.h"

//---------------
// C++ Headers --
//---------------


//              ---------------------
//              -- Class Interface --
//              ---------------------

class BPHParticlePtSelect: public BPHRecoSelect {

 public:

  /** Constructor
   */
  BPHParticlePtSelect( double pt ): ptMin( pt ) {}

  /** Destructor
   */
  ~BPHParticlePtSelect() override {}

  /** Operations
   */
  /// select particle
  bool accept( const reco::Candidate& cand ) const override {
    return ( cand.p4().pt() >= ptMin );
  }

  /// set pt min
  void setPtMin( double pt ) { ptMin = pt; return; }

  /// get current pt min
  double getPtMin() const { return ptMin; }

 private:

  // private copy and assigment constructors
  BPHParticlePtSelect           ( const BPHParticlePtSelect& x );
  BPHParticlePtSelect& operator=( const BPHParticlePtSelect& x );

  double ptMin;

};


#endif

