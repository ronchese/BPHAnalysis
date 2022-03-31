/*
 *  See header file for a description of this class.
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
#include "BPHAnalysis/SpecificDecay/interface/BPHDecayToFlyingCascadeBuilderBase.h"

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
BPHDecayToFlyingCascadeBuilderBase::BPHDecayToFlyingCascadeBuilderBase(
    const edm::EventSetup& es,
    const string& flyName, double flyMass, double flyMSigma ):
 BPHDecayToFlyingCascadeBuilderBase( flyName, flyMass, flyMSigma ) {
  evSetup = &es;
}


BPHDecayToFlyingCascadeBuilderBase::BPHDecayToFlyingCascadeBuilderBase(
    const string& flyName, double flyMass, double flyMSigma ):
 fName  ( flyName ),
 fMass  ( flyMass ),
 fMSigma( flyMSigma ),
 flySel   ( new BPHMassFitSelect( -2.0e+06, -1.0e+06 ) ),
 kfChi2Sel( new BPHKinFitChi2Select( -1.0 ) ) {
}


BPHDecayToFlyingCascadeBuilderBase::BPHDecayToFlyingCascadeBuilderBase():
 flySel   ( new BPHMassFitSelect( -2.0e+06, -1.0e+06 ) ),
 kfChi2Sel( new BPHKinFitChi2Select( -1.0 ) ) {
}

//--------------
// Destructor --
//--------------
BPHDecayToFlyingCascadeBuilderBase::~BPHDecayToFlyingCascadeBuilderBase() {
  delete    flySel;
  delete kfChi2Sel;
}

//--------------
// Operations --
//--------------

/// set cuts
void BPHDecayToFlyingCascadeBuilderBase::setFlyingMassMin( double m ) {
  outdated = true;
  flySel->setMassMin( m );
  return;
}


void BPHDecayToFlyingCascadeBuilderBase::setFlyingMassMax( double m ) {
  outdated = true;
  flySel->setMassMax( m );
  return;
}


void BPHDecayToFlyingCascadeBuilderBase::setFlyingMassRange( double mMin, double mMax ) {
  outdated = true;
  flySel->setMassMin( mMin );
  flySel->setMassMax( mMax );
  return;
}


void BPHDecayToFlyingCascadeBuilderBase::setKinFitProbMin( double p ) {
  outdated = true;
  kfChi2Sel->setProbMin ( p );
}

