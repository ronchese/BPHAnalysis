#ifndef BPHAnalysis_SpecificDecay_BPHMuonPtSelect_h
#define BPHAnalysis_SpecificDecay_BPHMuonPtSelect_h
/** \class BPHMuonPtSelect
 *
 *  Description: 
 *     Class for muon selection by Pt
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "BPHAnalysis/SpecificDecay/interface/BPHParticlePtSelect.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "DataFormats/PatCandidates/interface/Muon.h"

//---------------
// C++ Headers --
//---------------


//              ---------------------
//              -- Class Interface --
//              ---------------------

class BPHMuonPtSelect: public BPHParticlePtSelect {

 public:

  /** Constructor
   */
  BPHMuonPtSelect( double pt ): BPHParticlePtSelect( pt ) {}

  // deleted copy constructor and assignment operator
  BPHMuonPtSelect           ( const BPHMuonPtSelect& x ) = delete;
  BPHMuonPtSelect& operator=( const BPHMuonPtSelect& x ) = delete;

  /** Destructor
   */
  ~BPHMuonPtSelect() override {}

  /** Operations
   */
  /// select muon
  bool accept( const reco::Candidate& cand ) const override {
    if ( dynamic_cast<const pat::Muon*>( &cand ) == nullptr ) return false;
    return BPHParticlePtSelect::accept( cand );
  }

 private:

};


#endif

