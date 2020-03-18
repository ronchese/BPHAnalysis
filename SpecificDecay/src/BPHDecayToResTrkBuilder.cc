/*
 *  See header file for a description of this class.
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//-----------------------
// This Class' Header --
//-----------------------
#include "BPHAnalysis/SpecificDecay/interface/BPHDecayToResTrkBuilder.h"

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "BPHAnalysis/RecoDecay/interface/BPHRecoBuilder.h"
#include "BPHAnalysis/RecoDecay/interface/BPHPlusMinusCandidate.h"
#include "BPHAnalysis/RecoDecay/interface/BPHRecoCandidate.h"
#include "BPHAnalysis/SpecificDecay/interface/BPHParticleNeutralVeto.h"

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
BPHDecayToResTrkBuilder::BPHDecayToResTrkBuilder( const edm::EventSetup& es,
    const std::string& resName, double resMass, double resWidth,
    const std::vector<BPHPlusMinusConstCandPtr>& resCollection,
    const std::string& trkName, double trkMass, double trkSigma,
    const BPHRecoBuilder::BPHGenericCollection*  trkCollection ):
 BPHDecayConstrainedBuilder( es, resName, resMass, resWidth, resCollection ),
 tName( trkName ),
 tMass( trkMass ),
 tSigma( trkSigma ),
 tCollection(  trkCollection ),
 tknVeto( new BPHParticleNeutralVeto ),
 ptSel  ( new BPHParticlePtSelect (   0.0 ) ),
 etaSel ( new BPHParticleEtaSelect( 100.0 ) ) {
}

//--------------
// Destructor --
//--------------
BPHDecayToResTrkBuilder::~BPHDecayToResTrkBuilder() {
  delete tknVeto;
  delete   ptSel;
  delete  etaSel;
}

//--------------
// Operations --
//--------------
vector<BPHRecoConstCandPtr> BPHDecayToResTrkBuilder::build() {

  if ( updated ) return recList;

  recList.clear();

  BPHRecoBuilder brb( *evSetup );
  brb.setMinPDiffererence( minPDiff );
  brb.add( rName, *rCollection );
  brb.add( tName,  tCollection, tMass, tSigma );
  if ( resoSel->getMassMax() > 0.0 )
  brb.filter( rName, *resoSel );
  brb.filter( tName, *tknVeto );
  if (  ptSel->getPtMin   () >= 0.0 )
  brb.filter( tName, *  ptSel );
  if (  etaSel->getEtaMax () >= 0.0 )
  brb.filter( tName, * etaSel );

  if ( massSel->getMassMax() >= 0.0 )
  brb.filter( *massSel );
  if ( chi2Sel->getProbMin() >= 0.0 )
  brb.filter( *chi2Sel );
  if ( mFitSel->getMassMax() >= 0.0 )
  brb.filter( *mFitSel );

  recList = BPHRecoCandidate::build( brb );
  updated = true;
  return recList;

}

/// set cuts
void BPHDecayToResTrkBuilder::setTrkPtMin( double pt ) {
  updated = false;
  ptSel->setPtMin( pt );
  return;
}


void BPHDecayToResTrkBuilder::setTrkEtaMax( double eta ) {
  updated = false;
  etaSel->setEtaMax( eta );
  return;
}

