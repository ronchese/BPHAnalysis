#ifndef BPHAnalysis_SpecificDecay_BPHX3872ToJPsiPiPiBuilder_h
#define BPHAnalysis_SpecificDecay_BPHX3872ToJPsiPiPiBuilder_h
/** \class BPHX3872ToJPsiPiPiBuilder
 *
 *  Description: 
 *     Class to build X3872 to JPsi pi+ pi- candidates
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "BPHAnalysis/SpecificDecay/interface/BPHDecayToResTrkTrkSameMassBuilder.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "BPHAnalysis/SpecificDecay/interface/BPHDecayGenericBuilderBase.h"
#include "BPHAnalysis/SpecificDecay/interface/BPHDecayConstrainedBuilderBase.h"
#include "BPHAnalysis/SpecificDecay/interface/BPHParticleMasses.h"
#include "BPHAnalysis/RecoDecay/interface/BPHRecoBuilder.h"
#include "BPHAnalysis/RecoDecay/interface/BPHRecoCandidate.h"
#include "BPHAnalysis/RecoDecay/interface/BPHPlusMinusCandidate.h"

#include "FWCore/Framework/interface/EventSetup.h"

class BPHEventSetupWrapper;

//---------------
// C++ Headers --
//---------------
#include <string>
#include <vector>

//              ---------------------
//              -- Class Interface --
//              ---------------------

class BPHX3872ToJPsiPiPiBuilder:
      public BPHDecayToResTrkTrkSameMassBuilder<BPHRecoCandidate,
                                                BPHPlusMinusCandidate> {

 public:

  /** Constructor
   */
  BPHX3872ToJPsiPiPiBuilder( const BPHEventSetupWrapper& es,
      const std::vector<BPHPlusMinusConstCandPtr>& jpsiCollection,
      const BPHRecoBuilder::BPHGenericCollection*   posCollection,
      const BPHRecoBuilder::BPHGenericCollection*   negCollection ):
   BPHDecayGenericBuilderBase( es, nullptr ),
   BPHDecayConstrainedBuilderBase( "JPsi", BPHParticleMasses::jPsiMass,
                                           BPHParticleMasses::jPsiMWidth ),
   BPHDecayToResTrkTrkSameMassBuilder( jpsiCollection,
                                       "PionPos", "PionNeg",
                                       BPHParticleMasses::pionMass,
                                       BPHParticleMasses::pionMSigma,
                                       posCollection, negCollection ) {
    setResMassRange( 2.80, 3.40 );
    setTrkPtMin    (  1.0 );
    setTrkEtaMax   ( 10.0 );
    setMassRange   ( 3.00, 4.50 );
    setProbMin     ( 0.02 );
    setMassFitRange( 3.50, 4.20 );
  }

  // deleted copy constructor and assignment operator
  BPHX3872ToJPsiPiPiBuilder           ( const BPHX3872ToJPsiPiPiBuilder& x ) = delete;
  BPHX3872ToJPsiPiPiBuilder& operator=( const BPHX3872ToJPsiPiPiBuilder& x ) = delete;

  /** Destructor
   */
  ~BPHX3872ToJPsiPiPiBuilder() override {}

  /** Operations
   */

  /// set cuts
  void setPiPtMin    ( double pt  ) { setTrkPtMin  (  pt ); }
  void setPiEtaMax   ( double eta ) { setTrkEtaMax ( eta ); }
  void setJPsiMassMin( double m   ) { setResMassMin(   m ); }
  void setJPsiMassMax( double m   ) { setResMassMax(   m ); }

  /// get current cuts
  double getPiPtMin    () const { return getTrkPtMin  (); }
  double getPiEtaMax   () const { return getTrkEtaMax (); }
  double getJPsiMassMin() const { return getResMassMin(); }
  double getJPsiMassMax() const { return getResMassMax(); }

};


#endif

