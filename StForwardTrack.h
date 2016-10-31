// Test of Track Used with StForwardJet

#ifndef StForwardTrack_def
#define StForwardTrack_def

#include "TObject.h"
#include "TRef.h"
#include "TVector3.h"
#include "TLorentzVector.h"

class StForwardDijetEvent;
class StForwardDijet;
class StForwardJet;

class StForwardTrack : public TObject { 

 public:

  StForwardTrack();

  TVector3 momentum() const;
  TLorentzVector fourMomentum() const;

  // Declare Setters
  void setPt(Double_t pt);
  void setEta(Double_t eta);
  void setPhi(Double_t phi);

  void setFlag(short flag);
  void setCharge(short charge);
  void setNHits(short hits);
  void setNHitsFit(short hits);
  void setNHitsPoss(short hits);
  void setNHitsDedx(short hits);
  void setDedx(Double_t dedx);
  void setExitPoint(TVector3 exit);
  void setExitTowerId(short id);
  void setExitDetectorId(short id);
  void setDca(TVector3 dca);
  void setDcaD(Double_t dca);
  void setChi2(Double_t chi2);
  void setChi2Prob(Double_t chi2);
  void setBeta(Double_t beta);
  void setFirstPoint(TVector3 point);
  void setLastPoint(TVector3 point);

  void setnSigmaPion(float nSigmaPion);
  void setnSigmaKaon(float nSigmaKaon);
  void setnSigmaProton(float nSigmaProton);
  void setnSigmaElectron(float nSigmaElectron);

  // Declare and Implement Getters
  Double_t pt()                   const { return mPt; }
  Double_t eta()                  const { return mEta; }
  Double_t phi()                  const { return mPhi; }

  Double_t rap();

  short    flag()                 const { return mFlag; }
  short    charge()               const { return mCharge; }
  short    nHits()                const { return mNHits; }
  short    nHitsFit()             const { return mNHitsFit; }
  short    nHitsPoss()            const { return mNHitsPoss; }
  short    nHitsDedx()            const { return mNHitsDedx; }
  Double_t dEdx()                 const { return mDedx; }
  const TVector3& exitPoint()  const { return mExitPoint; }
  short    exitTowerId()          const { return mExitTowerId; }
  short    exitDetectorId()       const { return mExitDetectorId; }
  const TVector3& dca()        const { return mDca; }
  Double_t dcaD()                 const { return mDcaD; }
  Double_t dcaXY()                const { return dcaD(); }
  Double_t dcaZ()                 const { return dca().z(); }
  Double_t chi2()                 const { return mChi2; }
  Double_t chi2prob()             const { return mChi2Prob; }
  Double_t beta()                 const { return mBeta; }
  const TVector3& firstPoint() const { return mFirstPoint; }
  const TVector3& lastPoint()  const { return mLastPoint;  }

  float nSigmaPion() const {return mnSigmaPion;}
  float nSigmaKaon() const {return mnSigmaKaon;}
  float nSigmaProton() const {return mnSigmaProton;}
  float nSigmaElectron() const {return mnSigmaElectron;}

  // Set Jet
  void setJet(const StForwardJet* jet) {mJet = (TObject*)jet; }

 private:

  TRef mJet;

  Double_t mPt;
  Double_t mEta;
  Double_t mPhi;

  short    mFlag;
  short    mCharge;
  short    mNHits;
  short    mNHitsFit;
  short    mNHitsPoss;
  short    mNHitsDedx;
  Double_t mDedx;
  TVector3 mExitPoint;
  short    mExitTowerId;
  short    mExitDetectorId;
  TVector3 mDca;
  Double_t mDcaD;
  Double_t mChi2;
  Double_t mChi2Prob;
  Double_t mBeta;
  TVector3 mFirstPoint;
  TVector3 mLastPoint;

  float mnSigmaPion;
  float mnSigmaKaon;
  float mnSigmaProton;
  float mnSigmaElectron;

  ClassDef(StForwardTrack,6);
};

inline TVector3 StForwardTrack::momentum() const
{
  TVector3 mom;
  mom.SetPtEtaPhi(mPt,mEta,mPhi);
  return mom;
}

inline TLorentzVector StForwardTrack::fourMomentum() const
{
  TLorentzVector mom;
  mom.SetPtEtaPhiM(mPt,mEta,mPhi,0.1395700); // Tracks assume Pion mass
  return mom;
}

#endif
