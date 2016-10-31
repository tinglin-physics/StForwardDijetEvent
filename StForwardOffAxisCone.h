// OffAxisCone Class Used with StForwardJet

#ifndef StForwardOffAxisCone_def
#define StForwardOffAxisCone_def

#include "TObject.h"
#include "TRef.h"
#include "TVector3.h"
#include "TLorentzVector.h"
#include "TRefArray.h"

#include "StForwardTrack.h"
#include "StForwardTower.h"
#include "StForwardParticle.h"

class StForwardDijetEvent;
class StForwardDijet;
class StForwardJet;
class StForwardTrack;
class StForwardTower;
class StForwardParticle;

class StForwardOffAxisCone : public TObject {

 public:

  StForwardOffAxisCone();

  TVector3 momentum() const;
  TLorentzVector fourMomentum() const;

  // Declare Setters
  void setPt(Double_t pt);
  void setEta(Double_t eta);
  void setPhi(Double_t phi);
  void setRadius(Double_t radius);
  void setMult(Int_t mult);

  // Declare and Implement Getters
  Double_t pt() const { return mPt; }
  Double_t eta() const { return mEta; }
  Double_t phi() const { return mPhi; }
  Double_t radius() const { return mRadius; }
  Double_t mult() const { return mMult; }

  int numberOfTracks() const;
  int numberOfTowers() const;
  int numberOfParticles() const;

  StForwardTrack* track(int i) const;
  StForwardTower* tower(int i) const;
  StForwardParticle* particle(int i) const;

  // Add Track / Tower to Jet
  StForwardTrack* addTrack(StForwardTrack* track);
  StForwardTower* addTower(StForwardTower* tower);
  StForwardParticle* addParticle(StForwardParticle* particle);

  // Set Jet
  void setJet(const StForwardJet* jet) {mJet = (TObject*)jet; }

 private:

  TRef mJet;

  Double_t mPt;
  Double_t mEta;
  Double_t mPhi;
  Double_t mRadius;
  Int_t mMult;

  TRefArray mTracks;
  TRefArray mTowers;
  TRefArray mParticles;

  ClassDef(StForwardOffAxisCone,6);
};

inline TVector3 StForwardOffAxisCone::momentum() const
{
  TVector3 mom;
  mom.SetPtEtaPhi(mPt,mEta,mPhi);
  return mom;
}

inline TLorentzVector StForwardOffAxisCone::fourMomentum() const
{
  TLorentzVector mom;
  mom.SetPtEtaPhiM(mPt,mEta,mPhi,0.00); // OffAxisCones assume Zero mass
  return mom;
}

#endif
