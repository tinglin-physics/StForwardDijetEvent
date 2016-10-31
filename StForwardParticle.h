// Particle Used with StForwardJet

#ifndef StForwardParticle_def
#define StForwardParticle_def

#include "TObject.h"
#include "TRef.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TParticlePDG.h"
#include "TDatabasePDG.h"

class StForwardDijetEvent;
class StForwardDijet;
class StForwardJet;

class StForwardParticle : public TObject {

public:

  StForwardParticle();

  TVector3 momentum() const;
  TLorentzVector fourMomentum() const;

  // Declare Setters
  void setPt(Double_t pt);
  void setEta(Double_t eta);
  void setPhi(Double_t phi);
  void setM(Double_t m);
  void setE(Double_t e);
  void setPDG(int pdg);
  void setStatus(int stat);
  void setFirstMother(int mom);
  void setLastMother(int mom);
  void setFirstDaughter(int dau);
  void setLastDaughter(int dau);

  // Declare and Implement Getters
  Double_t pt() const { return mPt; }
  Double_t eta() const { return mEta; }
  Double_t phi() const { return mPhi; }

  Double_t rap();

  Double_t m() const { return mM; }
  Double_t e() const { return mE; }
  int      pdg() const { return mPdg; }
  int      status() const { return mStatus; }
  int      firstMother() const { return mFirstMother; }
  int      lastMother() const { return mLastMother; }
  int      firstDaughter() const { return mFirstDaughter; }
  int      lastDaughter() const { return mLastDaughter; }

  const char* name() const
  {
    static const char* noname = "???";
    const TParticlePDG* ap = TDatabasePDG::Instance()->GetParticle(mPdg);
    return ap ? ap->GetName() : noname;
  }

  // Set Jet
  void setJet(const StForwardJet* jet) {mJet = (TObject*)jet; }

private:
  
  TRef mJet;

  Double_t mPt;
  Double_t mEta;
  Double_t mPhi;
  Double_t mM;
  Double_t mE;
  int      mPdg;
  int      mStatus;
  int      mFirstMother;
  int      mLastMother;
  int      mFirstDaughter;
  int      mLastDaughter;

  ClassDef(StForwardParticle,6);
};

inline TVector3 StForwardParticle::momentum() const
  {
    TVector3 p;
    p.SetPtEtaPhi(mPt,mEta,mPhi);
    return p;
  }

inline TLorentzVector StForwardParticle::fourMomentum() const
  {
    TLorentzVector p;
    p.SetPtEtaPhiE(mPt,mEta,mPhi,mE);
    return p;
  }

#endif 
