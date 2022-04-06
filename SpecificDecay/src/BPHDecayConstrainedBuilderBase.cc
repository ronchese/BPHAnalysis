/*
 *  See header file for a description of this class.
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
#include "BPHAnalysis/SpecificDecay/interface/BPHDecayConstrainedBuilderBase.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
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
BPHDecayConstrainedBuilderBase::BPHDecayConstrainedBuilderBase(
    const BPHEventSetupWrapper& es,
    const string& resName, double resMass, double resWidth ):
 BPHDecayConstrainedBuilderBase( resName, resMass, resWidth ) {
  evSetup = &es;
}


BPHDecayConstrainedBuilderBase::BPHDecayConstrainedBuilderBase(
    const string& resName, double resMass, double resWidth ):
 rName( resName ),
 rMass( resMass ),
 rWidth( resWidth ),
 resoSel( new BPHMassSelect( -2.0e+06, -1.0e+06 ) ),
 massConstr( true ) {
  mFitSel = new BPHMassFitSelect( resName, resMass, resWidth,
                                  -2.0e+06, -1.0e+06 );
}


BPHDecayConstrainedBuilderBase::BPHDecayConstrainedBuilderBase() {
}

//--------------
// Destructor --
//--------------
BPHDecayConstrainedBuilderBase::~BPHDecayConstrainedBuilderBase() {
  delete resoSel;
}

//--------------
// Operations --
//--------------
/// set cuts
void BPHDecayConstrainedBuilderBase::setResMassMin( double m ) {
  outdated = true;
  resoSel->setMassMin( m );
  return;
}


void BPHDecayConstrainedBuilderBase::setResMassMax( double m ) {
  outdated = true;
  resoSel->setMassMax( m );
  return;
}


void BPHDecayConstrainedBuilderBase::setResMassRange( double mMin, double mMax ) {
  outdated = true;
  resoSel->setMassMin( mMin );
  resoSel->setMassMax( mMax );
  return;
}


void BPHDecayConstrainedBuilderBase::setConstr( bool flag ) {
  outdated = true;
  if ( flag == massConstr ) return;
  double mMin = mFitSel->getMassMin();
  double mMax = mFitSel->getMassMax();
  delete mFitSel;
  massConstr = flag;
  if ( massConstr ) mFitSel = new BPHMassFitSelect    ( rName, rMass, rWidth,
                                                        mMin, mMax );
  else              mFitSel = new BPHMassFitSelect    ( mMin, mMax );
  return;
}

