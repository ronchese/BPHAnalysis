#ifndef BPHAnalysis_SpecificDecay_BPHDecayConstrainedBuilderBase_h
#define BPHAnalysis_SpecificDecay_BPHDecayConstrainedBuilderBase_h
/** \class BPHDecayConstrainedBuilderBase
 *
 *  Description: 
 *     Class to build a particle decaying to a resonance, decaying itself
 *     to an opposite charged particles pair, applying a mass constraint
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "BPHAnalysis/SpecificDecay/interface/BPHDecayGenericBuilderBase.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
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

class BPHDecayConstrainedBuilderBase:
      public virtual BPHDecayGenericBuilderBase {

 public:

  /** Constructor
   */
  BPHDecayConstrainedBuilderBase( const edm::EventSetup& es,
      const std::string& resName, double resMass, double resWidth );

  // deleted copy constructor and assignment operator
  BPHDecayConstrainedBuilderBase           ( const BPHDecayConstrainedBuilderBase& x )
                                         = delete;
  BPHDecayConstrainedBuilderBase& operator=( const BPHDecayConstrainedBuilderBase& x )
                                         = delete;

  /** Destructor
   */
  ~BPHDecayConstrainedBuilderBase() override;

  /** Operations
   */
  /// set cuts
  void setResMassMin( double m  );
  void setResMassMax( double m  );
  void setResMassRange( double mMin, double mMax );
  void setConstr    ( bool flag );

  /// get current cuts
  double getResMassMin() const { return resoSel->getMassMin(); }
  double getResMassMax() const { return resoSel->getMassMax(); }
  bool   getConstr    () const { return massConstr; }

 protected:

  BPHDecayConstrainedBuilderBase( const std::string& resName,
                                  double resMass, double resWidth );
  BPHDecayConstrainedBuilderBase();

  std::string rName;
  double rMass;
  double rWidth;

  BPHMassSelect* resoSel;

  bool massConstr;

  virtual void addResCollection( BPHRecoBuilder& brb ) = 0;

};


#endif

