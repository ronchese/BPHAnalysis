#ifndef BPHAnalysis_SpecificDecay_BPHDecaySpecificBuilder_h
#define BPHAnalysis_SpecificDecay_BPHDecaySpecificBuilder_h
/** \class BPHDecaySpecificBuilder
 *
 *  Description: 
 *     Class to plug the usage of BPHRecoBuilder inside BPHGenericBuilder
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "BPHAnalysis/SpecificDecay/interface/BPHDecayGenericBuilder.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "FWCore/Framework/interface/EventSetup.h"

class BPHRecoBuilder;

//---------------
// C++ Headers --
//---------------
#include <vector>
#include <iostream>

//              ---------------------
//              -- Class Interface --
//              ---------------------

class BPHDecaySpecificBuilderBase {
 public:
  virtual ~BPHDecaySpecificBuilderBase() {}
 protected:
  virtual void fill( BPHRecoBuilder& brb, void* parameters ) = 0;
  virtual void setup( void* parameters ) = 0;
};

template <class ProdType>
class BPHDecaySpecificBuilder:
      public virtual BPHDecaySpecificBuilderBase,
      public virtual BPHDecayGenericBuilder<ProdType> {

 public:

  /** Constructor
   */
  BPHDecaySpecificBuilder() {}

  // deleted copy constructor and assignment operator
  BPHDecaySpecificBuilder           ( const BPHDecaySpecificBuilder& x ) = delete;
  BPHDecaySpecificBuilder& operator=( const BPHDecaySpecificBuilder& x ) = delete;

  /** Destructor
   */
  ~BPHDecaySpecificBuilder() override {}

 protected:

  /** Operations
   */
  /// build candidates

  void fillRecList() override;

};


#endif

