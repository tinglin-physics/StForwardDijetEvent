// Test of Dijet Used with StForwardDijetEvent

#ifndef StForwardDijet_def
#define StForwardDijet_def

#include "TObject.h"
#include "TRefArray.h"
#include "TVector3.h"

class StForwardDijetEvent;
class StForwardJet;

class StForwardDijet : public TObject {
 public:

  StForwardDijet();

  // Declare Setters
  void setTrigCombo(short trig);
  void setMass(Double_t mass);
  void setNoMass(Double_t noMass);
  void setVertex(TVector3 vertex);

  // Declare and Implement Getters
  int   trigCombo()  const { return mTrigCombo; }
  Double_t mass()    const { return mMass; }
  Double_t noMass()  const { return mNoMass; }

  Double_t cosPhiDiff() const;
  Double_t ptBalance() const;
  Double_t etaSum() const;
  Double_t etaDiff() const;
  Double_t x1Calc() const;
  Double_t x2Calc() const;
  Double_t cosTheta() const;
  Double_t vertX()    const { return mVertexX; }
  Double_t vertY()    const { return mVertexY; }
  Double_t vertZ()    const { return mVertexZ; }

  //int numberOfJets() const { return mJets.GetEntriesFast(); }
  // Get Number of Jets
  int numberOfJets() const;

  // Get Jet
  StForwardJet* jet(int i) const; //{ return (StForwardJet*)mJets.At(i); }
  StForwardJet* sameSide() const;
  StForwardJet* awaySide() const;

  // Add Jet to Dijet
  StForwardJet* addJet(StForwardJet* jet); //{ mJets.Add((TObject*)jet); return (StForwardJet*)mJets.Last(); }
  
 private:

  short mTrigCombo;
  Double_t mMass;
  Double_t mNoMass;
  Double_t mVertexX, mVertexY, mVertexZ;

  TRefArray mJets;
  
  ClassDef(StForwardDijet,6);
};

#endif
