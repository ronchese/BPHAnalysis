#ifndef BPHAnalysis_SpecificDecay_BPHPhiToKKBuilder_h
#define BPHAnalysis_SpecificDecay_BPHPhiToKKBuilder_h
/** \class BPHPhiToKKBuilder
 *
 *  Description: 
 *     Class to build Phi to K+ K- candidates
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "BPHAnalysis/SpecificDecay/interface/BPHDecayToChargedXXbarBuilder.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "BPHAnalysis/SpecificDecay/interface/BPHDecayGenericBuilderBase.h"
#include "BPHAnalysis/SpecificDecay/interface/BPHParticleMasses.h"
#include "BPHAnalysis/RecoDecay/interface/BPHRecoBuilder.h"
#include "BPHAnalysis/RecoDecay/interface/BPHRecoCandidate.h"
#include "BPHAnalysis/RecoDecay/interface/BPHPlusMinusCandidate.h"

#include "FWCore/Framework/interface/EventSetup.h"

//---------------
// C++ Headers --
//---------------
#include <string>
#include <vector>

//              ---------------------
//              -- Class Interface --
//              ---------------------

class BPHPhiToKKBuilder: public BPHDecayToChargedXXbarBuilder {

 public:

  /** Constructor
   */
  BPHPhiToKKBuilder( const edm::EventSetup& es,
       const BPHRecoBuilder::BPHGenericCollection* posCollection,
       const BPHRecoBuilder::BPHGenericCollection* negCollection ):
   BPHDecayGenericBuilderBase( es ),
   BPHDecayToChargedXXbarBuilder( es, "KPos", "KNeg",
                                  BPHParticleMasses::kaonMass,
                                  BPHParticleMasses::kaonMSigma,
                                  posCollection, negCollection ) {
    setPtMin (  0.7 );
    setEtaMax( 10.0 );
    setMassRange ( 1.00, 1.04 );
    setProbMin   ( 0.0 );
  }

  // deleted copy constructor and assignment operator
  BPHPhiToKKBuilder           ( const BPHPhiToKKBuilder& x ) = delete;
  BPHPhiToKKBuilder& operator=( const BPHPhiToKKBuilder& x ) = delete;

  /** Destructor
   */
  ~BPHPhiToKKBuilder() override {}

};


#endif

