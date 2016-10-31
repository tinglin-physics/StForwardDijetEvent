// Test of Jet Container

#include "StForwardJet.h"
//#include "StForwardTrack.h"
//#include "StForwardTower.h"

ClassImp(StForwardJet);

StForwardJet::StForwardJet(const TLorentzVector& fourMomentum)
  : mPt(fourMomentum.Pt())
  , mEta(fourMomentum.Eta())
  , mPhi(fourMomentum.Phi())
  , mE(fourMomentum.E())
{
}

// Implement Setters
void StForwardJet::setRt(Double_t rt) { mRt = rt; }
void StForwardJet::setDetEta(Double_t detEta) { mDetEta = detEta; }
void StForwardJet::setSameSide(bool sameSide) { mSameSide = sameSide; }
void StForwardJet::setTrig(short trig) { mTrig = trig; }
void StForwardJet::setArea(float area, float areaError) {mArea=area; mAreaError=areaError;}

// Implement Getter
Double_t StForwardJet::rap() const { return StForwardJet::fourMomentum().Rapidity(); }

// Implement Utility Functions
Double_t StForwardJet::sumTrackPt() const
{
  //Double_t s = 0.;
  TVector3 mom;
  for(int i=0; i<numberOfTracks(); ++i)
    {
      const StForwardTrack* t = track(i);
      //s += t->pt();
      mom += t->momentum();
    }
  //return s;
  return mom.Pt();
}

Double_t StForwardJet::sumTrackPt(Double_t radius) const
{
  //Double_t s = 0.;
  TVector3 mom;
  for(int i=0; i<numberOfTracks(); ++i)
    {
      const StForwardTrack* t = track(i);
      //if(deltaR(t) < radius) s += t->pt();
      if(deltaR(t) < radius) mom += t->momentum();
    }
  //return s;
  return mom.Pt();
}

Double_t StForwardJet::sumTowerPt() const
{
  //Double_t s = 0.;
  TVector3 mom;
  for(int i=0; i<numberOfTowers(); ++i)
    {
      const StForwardTower* t = tower(i);
      //s += t->pt();
      mom += t->momentum();
    }
  //return s;
  return mom.Pt();
}

Double_t StForwardJet::sumTowerPt(Double_t radius) const
{
  //Double_t s = 0.;
  TVector3 mom;
  for(int i=0; i<numberOfTowers(); ++i)
    {
      const StForwardTower* t = tower(i);
      //if(deltaR(t) < radius) s += t->pt();
      if(deltaR(t) < radius) mom += t->momentum();
    }
  //return s;
  return mom.Pt();
}

Double_t StForwardJet::sumTrackTowerPt() const
{
  //Double_t s = 0.;
  TVector3 mom;
  for(int i=0; i<numberOfTowers(); ++i)
    {
      const StForwardTower* t = tower(i);
      //s += t->pt();
      mom += t->momentum();
    }
  for(int i=0; i<numberOfTracks(); ++i)
    {
      const StForwardTrack* t = track(i);
      mom += t->momentum();
    }
  //return s;
  return mom.Pt();
}

Double_t StForwardJet::sumTrackTowerPt(Double_t radius) const
{
  //Double_t s = 0.;
  TVector3 mom;
  for(int i=0; i<numberOfTowers(); ++i)
    {
      const StForwardTower* t = tower(i);
      //if(deltaR(t) < radius) s += t->pt();
      if(deltaR(t) < radius) mom += t->momentum();
    }
  for(int i=0; i<numberOfTracks(); ++i)
    {
      const StForwardTrack* t = track(i);
      if(deltaR(t) < radius) mom += t->momentum();
    }
  //return s;
  return mom.Pt();
}

Double_t StForwardJet::sumParticlePt() const
{
  //Double_t s = 0.;
  TVector3 mom;
  for(int i=0; i<numberOfParticles(); ++i)
    {
      const StForwardParticle* t = particle(i);
      //s += t->pt();
      mom += t->momentum();
    }
  //return s;
  return mom.Pt();
}

Double_t StForwardJet::sumParticlePt(Double_t radius) const
{
  //Double_t s = 0.;
  TVector3 mom;
  for(int i=0; i<numberOfParticles(); ++i)
    {
      const StForwardParticle* t = particle(i);
      //if(deltaR(t) < radius) s += t->pt();
      if(deltaR(t) < radius) mom += t->momentum();
    }
  //return s;
  return mom.Pt();
}

Double_t StForwardJet::deltaR(const StForwardTrack* track) const
{
  Double_t jetRap = StForwardJet::fourMomentum().Rapidity();
  Double_t constituentRap = track->fourMomentum().Rapidity();

  Double_t jetPhi = StForwardJet::phi();
  Double_t constituentPhi = track->phi();

  Double_t dRap = jetRap - constituentRap;
  Double_t dPhi = TVector2::Phi_mpi_pi(jetPhi - constituentPhi);

  return TMath::Sqrt( dRap*dRap + dPhi*dPhi );
}

Double_t StForwardJet::deltaR(const StForwardTower* tower) const
{
  Double_t jetRap = StForwardJet::fourMomentum().Rapidity();
  Double_t constituentRap = tower->fourMomentum().Rapidity();

  Double_t jetPhi = StForwardJet::phi();
  Double_t constituentPhi = tower->phi();

  Double_t dRap = jetRap - constituentRap;
  Double_t dPhi = TVector2::Phi_mpi_pi(jetPhi - constituentPhi);

  return TMath::Sqrt( dRap*dRap + dPhi*dPhi );
}

Double_t StForwardJet::deltaR(const StForwardParticle* part) const
{
  Double_t jetRap = StForwardJet::fourMomentum().Rapidity();
  Double_t constituentRap = part->fourMomentum().Rapidity();

  Double_t jetPhi = StForwardJet::phi();
  Double_t constituentPhi = part->phi();

  Double_t dRap = jetRap - constituentRap;
  Double_t dPhi = TVector2::Phi_mpi_pi(jetPhi - constituentPhi);

  return TMath::Sqrt( dRap*dRap + dPhi*dPhi );
}

// Set Parent Dijet
void StForwardJet::setDijet(const StForwardDijet* dijet) { mDijet = (TObject*)dijet; }

// Get Number of Tracks / Towers / Particles
int StForwardJet::numberOfTracks() const { return mTracks.GetEntriesFast(); }
int StForwardJet::numberOfTowers() const { return mTowers.GetEntriesFast(); }
int StForwardJet::numberOfParticles() const { return mParticles.GetEntriesFast(); }
int StForwardJet::numberOfOffAxisCones() const { return mOffAxisCones.GetEntriesFast(); }

// Get Track / Tower / Particle
StForwardTrack* StForwardJet::track(int i) const { return (StForwardTrack*)mTracks.At(i); }
StForwardTower* StForwardJet::tower(int i) const { return (StForwardTower*)mTowers.At(i); }
StForwardParticle* StForwardJet::particle(int i) const { return (StForwardParticle*)mParticles.At(i); }
StForwardOffAxisCone* StForwardJet::offAxisCone(int i) const { return (StForwardOffAxisCone*)mOffAxisCones.At(i); }

// Add Track / Tower / Particle to Jet
StForwardTrack* StForwardJet::addTrack(StForwardTrack* track) { mTracks.Add((TObject*)track); return (StForwardTrack*)mTracks.Last(); }
StForwardTower* StForwardJet::addTower(StForwardTower* tower) { mTowers.Add((TObject*)tower); return (StForwardTower*)mTowers.Last(); }
StForwardParticle* StForwardJet::addParticle(StForwardParticle* particle) { mParticles.Add((TObject*)particle); return (StForwardParticle*)mParticles.Last(); }
StForwardOffAxisCone* StForwardJet::addOffAxisCone(StForwardOffAxisCone* offAxisCone) { mOffAxisCones.Add((TObject*)offAxisCone); return (StForwardOffAxisCone*)mOffAxisCones.Last(); }
