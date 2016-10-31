// Test of Jet Used with StForwardDijetEvent

#ifndef StForwardJet_def
#define StForwardJet_def

#include "TObject.h"
#include "TLorentzVector.h"
#include "TRef.h"
#include "TRefArray.h"

#include <map>
#include <string>
using namespace std;

#include "StForwardTrack.h"
#include "StForwardTower.h"
#include "StForwardParticle.h"
#include "StForwardOffAxisCone.h"

class StForwardDijetEvent;
class StForwardDijet;
class StForwardTrack;
class StForwardTower;
class StForwardParticle;
class StForwardOffAxisCone;

class StForwardJet : public TObject {
 public:
  StForwardJet()
    : mPt(0)
    , mEta(0)
    , mPhi(0)
    , mE(0)
    {
    }

    StForwardJet(const TLorentzVector& fourMomentum);

    TVector3 momentum() const;
    TLorentzVector fourMomentum() const;

    // Declare Setters
    void setRt(Double_t rt);
    void setDetEta(Double_t detEta);
    void setSameSide(bool sameSide);
    void setTrig(short trig);
    void setArea(float area, float areaError);
    void setUeDensity(map<string, float> jueDensity){ mUeDensity=jueDensity; }

    // Declare and Implement Getters
    Double_t pt()         const { return mPt; }
    Double_t eta()        const { return mEta; }
    Double_t phi()        const { return mPhi; }
    Double_t E()          const { return mE; }
    Double_t rt()         const { return mRt; }
    Double_t detEta()     const { return mDetEta; }
    bool     isSameSide() const { return mSameSide; }
    short    trig()       const { return mTrig; }
    float area() const{ return mArea; }
    float areaError() const{ return mAreaError; }
    map<string, float> ueDensity() const { return mUeDensity; }

    Double_t rap() const;

    // Declare Utility Functions
    Double_t sumTrackPt() const;
    Double_t sumTrackPt(Double_t radius) const;
    Double_t sumTowerPt() const;
    Double_t sumTowerPt(Double_t radius) const;
    Double_t sumTrackTowerPt() const;
    Double_t sumTrackTowerPt(Double_t radius) const;
    Double_t sumParticlePt() const;
    Double_t sumParticlePt(Double_t radius) const;
    Double_t profileTrack(Double_t radius) const { return sumTrackPt(radius)/sumTrackPt(); }
    Double_t profileTower(Double_t radius) const { return sumTowerPt(radius)/sumTowerPt(); }
    Double_t profileTrackTower(Double_t radius) const { return sumTrackTowerPt(radius)/sumTrackTowerPt(); }
    Double_t profileParticle(Double_t radius) const { return sumParticlePt(radius)/sumParticlePt(); }
    Double_t deltaR(const StForwardTrack* track) const;
    Double_t deltaR(const StForwardTower* tower) const;
    Double_t deltaR(const StForwardParticle* particle) const;


    // Set Parent Dijet
    void setDijet(const StForwardDijet* dijet); //{ mDijet = (TObject*)dijet; }

    // Get Number of Tracks / Towers / Particles
    int numberOfTracks() const; // { return mTracks.GetEntriesFast(); }
    int numberOfTowers() const;
    int numberOfParticles() const;
    int numberOfOffAxisCones() const;

    // Get Track / Tower / Particle
    StForwardTrack* track(int i) const; // { return (StForwardTrack*)mTracks.At(i); }
    StForwardTower* tower(int i) const;
    StForwardParticle* particle(int i) const;
    StForwardOffAxisCone* offAxisCone(int i) const;

    // Add Track / Tower / Particle to Jet
    StForwardTrack* addTrack(StForwardTrack* track); // { mTracks.Add((TObject*)track); return (StForwardTrack*)mTracks.Last(); }
    StForwardTower* addTower(StForwardTower* tower);
    StForwardParticle* addParticle(StForwardParticle* particle);
    StForwardOffAxisCone* addOffAxisCone(StForwardOffAxisCone* offAxisCone);

 private:

    TRef mDijet;

    Double_t mPt;
    Double_t mEta;
    Double_t mPhi;
    Double_t mE;
    Double_t mRt;
    Double_t mDetEta;
    bool  mSameSide;
    short mTrig;
    Double_t mArea;
    Double_t mAreaError;

    map<string, float> mUeDensity;

    TRefArray mTracks;
    TRefArray mTowers;
    TRefArray mParticles;
    TRefArray mOffAxisCones;

    ClassDef(StForwardJet,6);
};


inline TVector3 StForwardJet::momentum() const
{
  TVector3 mom;
  mom.SetPtEtaPhi(mPt,mEta,mPhi);
  return mom;
}

inline TLorentzVector StForwardJet::fourMomentum() const
{
  TLorentzVector mom;
  mom.SetPtEtaPhiE(mPt,mEta,mPhi,mE);
  return mom;
}

#endif
