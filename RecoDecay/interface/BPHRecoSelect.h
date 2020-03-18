#ifndef BPHAnalysis_RecoDecay_BPHRecoSelect_h
#define BPHAnalysis_RecoDecay_BPHRecoSelect_h
/** \class BPHRecoSelect
 *
 *  Description: 
 *     Base class for daughter particle selection
 *
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------


//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
class BPHRecoBuilder;

namespace reco {
  class Candidate;
}

//---------------
// C++ Headers --
//---------------
#include <string>

//              ---------------------
//              -- Class Interface --
//              ---------------------

class BPHRecoSelect {

 public:

  /** Constructor
   */
  BPHRecoSelect();

  // deleted copy constructor and assignment operator
  BPHRecoSelect           ( const BPHRecoSelect& x ) = delete;
  BPHRecoSelect& operator=( const BPHRecoSelect& x ) = delete;

  /** Destructor
   */
  virtual ~BPHRecoSelect();

  /** Operations
   */
  /// accept function
  /// pointers to other particles in the decays can be obtained 
  /// by the function "get" giving the particle name (passing the pointer 
  /// to the builder)
  virtual bool accept( const reco::Candidate& cand ) const;
  virtual bool accept( const reco::Candidate& cand,
                       const BPHRecoBuilder* build ) const;

 protected:

  // function to get other particles pointers
  const reco::Candidate* get( const std::string& name,
                              const BPHRecoBuilder* build ) const;

 private:

};


#endif

