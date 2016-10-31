// Test of Dijet Tree

#include "TClonesArray.h"
#include "TVector3.h"
#include "StForwardDijetEvent.h"
#include "StForwardDijet.h"
#include "StForwardJet.h"
#include "StForwardTrack.h"
#include "StForwardTower.h"
#include "StForwardParticle.h"
#include "StForwardPYTHIA.h"
#include "StForwardOffAxisCone.h"

ClassImp(StForwardDijetEvent);

  StForwardDijetEvent::StForwardDijetEvent()
    : mDijets(new TClonesArray("StForwardDijet",50))
    , mJets(new TClonesArray("StForwardJet",50))
    , mTracks(new TClonesArray("StForwardTrack",50))
    , mTowers(new TClonesArray("StForwardTower",50))
    , mParticles(new TClonesArray("StForwardParticle",50))
    , mPythia(new TClonesArray("StForwardPYTHIA",50))
    , mOffAxisCones(new TClonesArray("StForwardOffAxisCone",50))
{
}

void StForwardDijetEvent::Clear()
{
  mDijets->Clear();
  mJets->Clear();
  mTracks->Clear();
  mTowers->Clear();
  mParticles->Clear();
  mPythia->Clear();
  mOffAxisCones->Clear();
}

// Implement Setters
void StForwardDijetEvent::setRunId(int id) { mRunId = id; }
void StForwardDijetEvent::setRunIndex(int index) { mIndex = index; }
void StForwardDijetEvent::setEventId(int id) { mEventId = id; }
void StForwardDijetEvent::setUnixTime(unsigned int time) { mUnixTime = time; }
void StForwardDijetEvent::setFill(float fill) { mFill = fill; }
void StForwardDijetEvent::setRFF(bool isRFF) { mIsRFF = isRFF; }
void StForwardDijetEvent::setZDCRate(Double_t west, Double_t east, Double_t coin)
{
  mZDCW = west;
  mZDCE = east;
  mZDCCoin = coin;
}
void StForwardDijetEvent::setBBCRate(Double_t west, Double_t east, Double_t coin)
{
  mBBCW = west;
  mBBCE = east;
  mBBCCoin = coin;
}
void StForwardDijetEvent::setBX(int bx7, int bx48)
{
  mbx7 = bx7;
  mbx48 = bx48;
}
void StForwardDijetEvent::setTimeBin(int timeBin) { mBBCTimeBin = timeBin; }
void StForwardDijetEvent::setSpin4(int spin4) { mSpin4 = spin4; }
void StForwardDijetEvent::setRelLumi(Double_t r1, Double_t r2, Double_t r3, Double_t r4, Double_t r5, Double_t r6)
{
  mR1 = r1;
  mR2 = r2;
  mR3 = r3;
  mR4 = r4;
  mR5 = r5;
  mR6 = r6;
}
void StForwardDijetEvent::setBeamPol(unsigned int t0, Double_t pb, Double_t pb0, Double_t dpdtb, Double_t py, Double_t py0, Double_t dpdty)
{
  mt0 = t0;
  mpb = pb;
  mpb0 = pb0;
  mdpdtb = dpdtb;
  mpy = py;
  mpy0 = py0;
  mdpdty = dpdty;
}
void StForwardDijetEvent::setWeight(Double_t weight) { mWeight = weight; }
void StForwardDijetEvent::setBranch(int branch) { mBranch = branch; }

// Get Number of Dijets
int StForwardDijetEvent::numberOfDijets() const { return mDijets->GetEntriesFast(); }

// Get Number of Pythia Objects
int StForwardDijetEvent::numberOfPythia() const { return mPythia->GetEntriesFast(); }

// Get Dijet
StForwardDijet* StForwardDijetEvent::dijet(int i) const { return (StForwardDijet*)mDijets->At(i); }

// Get Pythia Object
StForwardPYTHIA* StForwardDijetEvent::pythia(int i) const { return (StForwardPYTHIA*)mPythia->At(i); }

// Declare New Objects
StForwardDijet* StForwardDijetEvent::newDijet() 
{ 
  return new ((*mDijets)[mDijets->GetEntriesFast()]) StForwardDijet; 
}
StForwardJet* StForwardDijetEvent::newJet(const TLorentzVector& fourMomentum)
{
  return new ((*mJets)[mJets->GetEntriesFast()]) StForwardJet(fourMomentum);
}
StForwardTrack* StForwardDijetEvent::newTrack()
{
  return new ((*mTracks)[mTracks->GetEntriesFast()]) StForwardTrack;
}
StForwardTower* StForwardDijetEvent::newTower()
{
  return new ((*mTowers)[mTowers->GetEntriesFast()]) StForwardTower;
}
StForwardParticle* StForwardDijetEvent::newParticle()
{
  return new ((*mParticles)[mParticles->GetEntriesFast()]) StForwardParticle;
}
StForwardPYTHIA* StForwardDijetEvent::newPythia()
{
  return new ((*mPythia)[mPythia->GetEntriesFast()]) StForwardPYTHIA;
}
StForwardOffAxisCone* StForwardDijetEvent::newOffAxisCone()
{
  return new ((*mOffAxisCones)[mOffAxisCones->GetEntriesFast()]) StForwardOffAxisCone;
}
