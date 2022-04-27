/*
 *  See header file for a description of this class.
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
#include "BPHAnalysis/SpecificDecay/interface/BPHDecayToResFlyingBuilderBase.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "BPHAnalysis/SpecificDecay/interface/BPHDecayGenericBuilderBase.h"
#include "BPHAnalysis/RecoDecay/interface/BPHRecoBuilder.h"
#include "BPHAnalysis/RecoDecay/interface/BPHPlusMinusCandidate.h"
#include "BPHAnalysis/RecoDecay/interface/BPHRecoCandidate.h"

//---------------
// C++ Headers --
//---------------
using namespace std;

//-------------------
// Initializations --
//-------------------


//----------------
// Constructors --
//----------------
BPHDecayToResFlyingBuilderBase::BPHDecayToResFlyingBuilderBase(
    const BPHEventSetupWrapper& es,
    const string& resName, double resMass, double resWidth,
    const string& flyName, double flyMass, double flyMSigma ):
 BPHDecayGenericBuilderBase( es, nullptr ),
 BPHDecayConstrainedBuilderBase( resName, resMass, resWidth ),
 BPHDecayToFlyingCascadeBuilderBase( flyName, flyMass, flyMSigma ) {
}


BPHDecayToResFlyingBuilderBase::BPHDecayToResFlyingBuilderBase() {
}

//--------------
// Operations --
//--------------
/// build candidates
void BPHDecayToResFlyingBuilderBase::fill( BPHRecoBuilder& brb,
                                           void* parameters ) {

  brb.setMinPDiffererence( minPDiff );
  addResCollection( brb );
  addFlyCollection( brb );

  if ( massSel->getMassMax() >= 0.0 )
  brb.filter( *massSel );

  setup( parameters );

  return;

}

