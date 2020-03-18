#ifndef BPHAnalysis_RecoDecay_BPHVertexSelect_h
#define BPHAnalysis_RecoDecay_BPHVertexSelect_h
/** \class BPHVertexSelect
 *
 *  Description: 
 *     Base class for candidate selection at vertex reconstruction level
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
class BPHDecayVertex;

//---------------
// C++ Headers --
//---------------


//              ---------------------
//              -- Class Interface --
//              ---------------------

class BPHVertexSelect {

 public:

  /** Constructor
   */
  BPHVertexSelect();

  // deleted copy constructor and assignment operator
  BPHVertexSelect           ( const BPHVertexSelect& x ) = delete;
  BPHVertexSelect& operator=( const BPHVertexSelect& x ) = delete;

  /** Destructor
   */
  virtual ~BPHVertexSelect();

  /** Operations
   */
  /// accept function
  virtual bool accept( const BPHDecayVertex& cand ) const = 0;

 private:

};


#endif

