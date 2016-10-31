// OffAxisCone Container

#include "StForwardOffAxisCone.h"

ClassImp(StForwardOffAxisCone);

StForwardOffAxisCone::StForwardOffAxisCone()
{
}

// Implement Setters
void StForwardOffAxisCone::setPt(Double_t pt) { mPt = pt; }
void StForwardOffAxisCone::setEta(Double_t eta) { mEta = eta; }
void StForwardOffAxisCone::setPhi(Double_t phi) { mPhi = phi; }
void StForwardOffAxisCone::setRadius(Double_t radius) { mRadius = radius; }
void StForwardOffAxisCone::setMult(Int_t mult) { mMult = mult; }

int StForwardOffAxisCone::numberOfTracks() const { return mTracks.GetEntriesFast(); }
int StForwardOffAxisCone::numberOfTowers() const { return mTowers.GetEntriesFast(); }
int StForwardOffAxisCone::numberOfParticles() const { return mParticles.GetEntriesFast(); }

StForwardTrack* StForwardOffAxisCone::track(int i) const { return (StForwardTrack*)mTracks.At(i); }
StForwardTower* StForwardOffAxisCone::tower(int i) const { return (StForwardTower*)mTowers.At(i); }
StForwardParticle* StForwardOffAxisCone::particle(int i) const { return (StForwardParticle*)mParticles.At(i); }

StForwardTrack* StForwardOffAxisCone::addTrack(StForwardTrack* track) { mTracks.Add((TObject*)track); return (StForwardTrack*)mTracks.Last(); }
StForwardTower* StForwardOffAxisCone::addTower(StForwardTower* tower) { mTowers.Add((TObject*)tower); return (StForwardTower*)mTowers.Last(); }
StForwardParticle* StForwardOffAxisCone::addParticle(StForwardParticle* particle) { mParticles.Add((TObject*)particle); return (StForwardParticle*)mParticles.Last(); }
