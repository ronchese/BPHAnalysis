#ifndef BPHAnalysis_SpecificDecay_BPHDecayGenericBuilder_h
#define BPHAnalysis_SpecificDecay_BPHDecayGenericBuilder_h
/** \class BPHDecayGenericBuilder
 *
 *  Description: 
 *     Class to build a generic decay applying selections to the
 *     reconstructed particle
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
#include "BPHAnalysis/SpecificDecay/interface/BPHMassSelect.h"
#include "BPHAnalysis/SpecificDecay/interface/BPHChi2Select.h"
#include "BPHAnalysis/SpecificDecay/interface/BPHMassFitSelect.h"

#include "FWCore/Framework/interface/EventSetup.h"

//---------------
// C++ Headers --
//---------------
#include <vector>
#include <iostream>

//              ---------------------
//              -- Class Interface --
//              ---------------------

template <class ProdType>
class BPHDecayGenericBuilder: public virtual BPHDecayGenericBuilderBase {

 public:

  typedef typename ProdType::const_pointer prod_ptr;

  /** Constructor
   */
  BPHDecayGenericBuilder( const edm::EventSetup& es,
                          BPHMassFitSelect* mfs ):
   BPHDecayGenericBuilderBase( es, mfs ) {
  }

  // deleted copy constructor and assignment operator
  BPHDecayGenericBuilder           ( const BPHDecayGenericBuilder& x ) = delete;
  BPHDecayGenericBuilder& operator=( const BPHDecayGenericBuilder& x ) = delete;

  /** Destructor
   */
  ~BPHDecayGenericBuilder() override {}

  /** Operations
   */
  /// build candidates
  virtual std::vector<prod_ptr> build() {
    if ( outdated ) {
      recList.clear();
      fillRecList();
      outdated = false;
    }
    return recList;
  }

 protected:

  BPHDecayGenericBuilder() {}

  std::vector<prod_ptr> recList;

};


#endif

