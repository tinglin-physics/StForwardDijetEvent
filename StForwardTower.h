// Tower Class Used with StForwardJet

#ifndef StForwardTower_def
#define StForwardTower_def

#include "TObject.h"
#include "TRef.h"
#include "TVector3.h"
#include "TLorentzVector.h"

class StForwardDijetEvent;
class StForwardDijet;
class StForwardJet;

class StForwardTower : public TObject {

 public:

  StForwardTower();

  TVector3 momentum() const;
  TLorentzVector fourMomentum() const;

  // Declare Setters
  void setPt(Double_t pt);
  void setEta(Double_t eta);
  void setPhi(Double_t phi);
  void setE(Double_t e);

  void setId(short id);
  void setDetectorId(short id);

  void setAdc(short adc);
  void setPedestal(Double_t ped);
  void setRms(Double_t rms);
  void setStatus(short stat);

  // Declare and Implement Getters
  Double_t pt() const { return mPt; }
  Double_t eta() const { return mEta; }
  Double_t phi() const { return mPhi; }
  Double_t energy() const { return mE; }

  Double_t rap();

  short    id() const { return mId; }
  short    detectorId() const { return mDetectorId; }

  short    adc() const { return mAdc; }
  Double_t ped() const { return mPedestal; }
  Double_t rms() const { return mRms; }
  short    status() const { return mStatus; }


  // Set Jet
  void setJet(const StForwardJet* jet) {mJet = (TObject*)jet; }

 private:

  TRef mJet;

  Double_t mPt;
  Double_t mEta;
  Double_t mPhi;
  Double_t mE;

  short    mId;
  short    mDetectorId;

  short    mAdc;
  Double_t mPedestal;
  Double_t mRms;
  short    mStatus;


  ClassDef(StForwardTower,6);
};

inline TVector3 StForwardTower::momentum() const
{
  TVector3 mom;
  mom.SetPtEtaPhi(mPt,mEta,mPhi);
  return mom;
}

inline TLorentzVector StForwardTower::fourMomentum() const
{
  TLorentzVector mom;
  mom.SetPtEtaPhiM(mPt,mEta,mPhi,0.00); // Towers assume Zero mass
  return mom;
}

#endif
