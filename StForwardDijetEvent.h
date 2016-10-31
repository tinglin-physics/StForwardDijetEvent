// Test of Dijet Tree

#ifndef StForwardDijetEvent_def
#define StForwardDijetEvent_def

class TLorentzVector;
class TClonesArray;
class StForwardDijet;
class StForwardJet;
class StForwardTrack;
class StForwardTower;
class StForwardParticle;
class StForwardPYTHIA;
class StForwardOffAxisCone;

#include "TObject.h"
#include "TVector3.h"
#include "TDatime.h"

class StForwardDijetEvent : public TObject { // declare the class{

 public:

  StForwardDijetEvent();

  void Clear();

  // Declare Setters
  void setRunId(int id);
  void setRunIndex(int index);
  void setEventId(int id);
  void setUnixTime(unsigned int time);
  void setFill(float fill);
  void setRFF(bool isRFF);
  void setZDCRate(Double_t west, Double_t east, Double_t coin);
  void setBBCRate(Double_t west, Double_t east, Double_t coin);
  void setBX(int bx7, int bx48);
  void setTimeBin(int timeBin);
  void setSpin4(int spin4);
  void setRelLumi(Double_t r1, Double_t r2, Double_t r3, Double_t r4, Double_t r5, Double_t r6);
  //void setBeamPol(float bluePol, float yellPol);
  void setBeamPol(unsigned int t0, Double_t pb, Double_t pb0, Double_t dpdtb, Double_t py, Double_t py0, Double_t dpdty);
  void setWeight(Double_t weight);
  void setBranch(int branch);
  //void setVertex(TVector3 vertex);
  
  // Declare and Implement Getters
  int            runId()       const { return mRunId; }
  int            runIndex()    const { return mIndex; }
  int            eventId()     const { return mEventId; }
  unsigned int   getUnixTime() const { return mUnixTime; }
  float          fill()        const { return mFill; }
  bool           isRFF()       const { return mIsRFF; }
  Double_t       zdcW()        const { return mZDCW; }
  Double_t       zdcE()        const { return mZDCE; }
  Double_t       zdcCoin()     const { return mZDCCoin; }
  Double_t       bbcW()        const { return mBBCW; }
  Double_t       bbcE()        const { return mBBCE; }
  Double_t       bbcCoin()     const { return mBBCCoin; }
  int            bx7()         const { return mbx7; }
  int            bx48()        const { return mbx48; }
  int            timeBin()     const { return mBBCTimeBin; }
  int            spin4()       const { return mSpin4; }
  Double_t       r1()          const { return mR1; }
  Double_t       r2()          const { return mR2; }
  Double_t       r3()          const { return mR3; }
  Double_t       r4()          const { return mR4; }
  Double_t       r5()          const { return mR5; }
  Double_t       r6()          const { return mR6; }
  //float          bluePol()     const { return mBluePol; }
  //float          yellPol()     const { return mYellPol; }
  unsigned int   t0()          const { return mt0; }
  Double_t       pb()          const { return mpb; }
  Double_t       pb0()         const { return mpb0; }
  Double_t       dpdtb()       const { return mdpdtb; }
  Double_t       py()          const { return mpy; }
  Double_t       py0()         const { return mpy0; }
  Double_t       dpdty()       const { return mdpdty; }
  Double_t       weight()      const { return mWeight; }
  int            branch()      const { return mBranch; }
  //float vertX()    const { return mVertexX; }
  //float vertY()    const { return mVertexY; }
  //float vertZ()    const { return mVertexZ; }

  // Get Number of Dijets
  int numberOfDijets() const;

  // Get Number of Pythia Objects
  int numberOfPythia() const;

  // Get Dijet
  StForwardDijet* dijet(int i) const;

  // Get PYTHIA Info
  StForwardPYTHIA* pythia(int i) const;

  // Declare New Objects
  StForwardDijet* newDijet();
  StForwardJet* newJet(const TLorentzVector& fourMomentum);
  StForwardTrack* newTrack();
  StForwardTower* newTower();
  StForwardParticle* newParticle();
  StForwardPYTHIA* newPythia();
  StForwardOffAxisCone* newOffAxisCone();
  

 private:

  int          mRunId;
  int          mIndex;
  int          mEventId;
  unsigned int mUnixTime;
  float        mFill;
  bool         mIsRFF;
  Double_t     mZDCW, mZDCE, mZDCCoin;
  Double_t     mBBCW, mBBCE, mBBCCoin;
  int          mbx7, mbx48;
  int          mBBCTimeBin;
  int          mSpin4;
  Double_t     mR1, mR2, mR3, mR4, mR5, mR6;
  //float mBluePol, mYellPol;
  unsigned int mt0;
  Double_t     mpb, mpb0, mdpdtb, mpy, mpy0, mdpdty;
  Double_t     mWeight;
  int          mBranch;
  //float mVertexX, mVertexY, mVertexZ;

  TClonesArray* mDijets;
  TClonesArray* mJets;
  TClonesArray* mTracks;
  TClonesArray* mTowers;
  TClonesArray* mParticles;
  TClonesArray* mPythia;
  TClonesArray* mOffAxisCones;

  ClassDef(StForwardDijetEvent,6);
};

#endif

