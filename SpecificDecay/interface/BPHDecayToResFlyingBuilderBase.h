#ifndef BPHAnalysis_SpecificDecay_BPHDecayToResFlyingBuilderBase_h
#define BPHAnalysis_SpecificDecay_BPHDecayToResFlyingBuilderBase_h
/** \class BPHDecayToResFlyingBuilderBase
 *
 *  Description: 
 *     Base class to build a particle decaying to a particle, decaying itself
 *     in cascade, and an additional flying particle
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "BPHAnalysis/SpecificDecay/interface/BPHDecaySpecificBuilder.h"
#include "BPHAnalysis/SpecificDecay/interface/BPHDecayConstrainedBuilderBase.h"
#include "BPHAnalysis/SpecificDecay/interface/BPHDecayToFlyingCascadeBuilderBase.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "BPHAnalysis/SpecificDecay/interface/BPHKinFitChi2Select.h"
#include "FWCore/Framework/interface/EventSetup.h"

class BPHRecoBuilder;

//---------------
// C++ Headers --
//---------------
#include <string>
#include <vector>

//              ---------------------
//              -- Class Interface --
//              ---------------------

class BPHDecayToResFlyingBuilderBase:
      public virtual BPHDecaySpecificBuilderBase,
      public virtual BPHDecayConstrainedBuilderBase,
      public virtual BPHDecayToFlyingCascadeBuilderBase {

 public:

  /** Constructor
   */
  BPHDecayToResFlyingBuilderBase( const edm::EventSetup& es,
      const std::string& resName, double resMass, double resWidth,
      const std::string& flyName, double flyMass, double flyMSigma );

  // deleted copy constructor and assignment operator
  BPHDecayToResFlyingBuilderBase           ( const BPHDecayToResFlyingBuilderBase& x )
                                         = delete;
  BPHDecayToResFlyingBuilderBase& operator=( const BPHDecayToResFlyingBuilderBase& x )
                                         = delete;

  /** Destructor
   */
  ~BPHDecayToResFlyingBuilderBase() override;

 protected:

  BPHDecayToResFlyingBuilderBase();

  /// build candidates
  void fill( BPHRecoBuilder& brb, void* parameters ) override;

};


#endif

