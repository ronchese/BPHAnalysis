#ifndef BPHAnalysis_SpecificDecay_BPHLbToJPsiL0Builder_h
#define BPHAnalysis_SpecificDecay_BPHLbToJPsiL0Builder_h
/** \class BPHLbToJPsiL0Builder
 *
 *  Description: 
 *     Class to build Lambda_b to JPsi Lambda_0 candidates
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "BPHAnalysis/SpecificDecay/interface/BPHDecayToResFlyingBuilder.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "BPHAnalysis/SpecificDecay/interface/BPHDecayGenericBuilderBase.h"
#include "BPHAnalysis/SpecificDecay/interface/BPHDecayConstrainedBuilderBase.h"
#include "BPHAnalysis/SpecificDecay/interface/BPHDecayToFlyingCascadeBuilderBase.h"
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

class BPHLbToJPsiL0Builder:
      public BPHDecayToResFlyingBuilder<BPHRecoCandidate,
                                        BPHPlusMinusCandidate,
                                        BPHPlusMinusCandidate> {

 public:

  /** Constructor
   */
  BPHLbToJPsiL0Builder( const BPHEventSetupWrapper& es,
      const std::vector<BPHPlusMinusConstCandPtr>& jpsiCollection,
      const std::vector<BPHPlusMinusConstCandPtr>&   l0Collection ):
   BPHDecayGenericBuilderBase( es, nullptr ),
   BPHDecayConstrainedBuilderBase( "JPsi", BPHParticleMasses::jPsiMass,
                                           BPHParticleMasses::jPsiMWidth ),
   BPHDecayToFlyingCascadeBuilderBase( "Lambda0",
                                       BPHParticleMasses::lambda0Mass,
                                       BPHParticleMasses::lambda0MSigma ),
   BPHDecayToResFlyingBuilder( jpsiCollection, l0Collection ) {
    setResMassRange   ( 2.80, 3.40 );
    setFlyingMassRange( 0.00, 3.00 );
    setMassRange      ( 3.50, 8.00 );
    setKinFitProbMin  ( 0.02 );
    setMassFitRange   ( 5.00, 6.00 );
    setConstr( true );
  }

  // deleted copy constructor and assignment operator
  BPHLbToJPsiL0Builder           ( const BPHLbToJPsiL0Builder& x ) = delete;
  BPHLbToJPsiL0Builder& operator=( const BPHLbToJPsiL0Builder& x ) = delete;

  /** Destructor
   */
  ~BPHLbToJPsiL0Builder() override = default;

  /** Operations
   */
  /// set cuts
  void setJPsiMassMin   ( double m ) { setResMassMin   ( m ); }
  void setJPsiMassMax   ( double m ) { setResMassMax   ( m ); }
  void setLambda0MassMin( double m ) { setFlyingMassMin( m ); }
  void setLambda0MassMax( double m ) { setFlyingMassMax( m ); }

  /// get current cuts
  double getJPsiMassMin   () const { return getResMassMin   (); }
  double getJPsiMassMax   () const { return getResMassMax   (); }
  double getLambda0MassMin() const { return getFlyingMassMin(); }
  double getLambda0MassMax() const { return getFlyingMassMax(); }

  /// setup parameters for BPHRecoBuilder
  void setup( void* parameters ) override {}

};


#endif

