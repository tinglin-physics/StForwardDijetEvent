// Particle Container

#include "StForwardParticle.h"

ClassImp(StForwardParticle);

StForwardParticle::StForwardParticle()
{
}

Double_t StForwardParticle::rap() { return StForwardParticle::fourMomentum().Rapidity(); }

// Implement Setters
void StForwardParticle::setPt(Double_t pt) { mPt = pt; }
void StForwardParticle::setEta(Double_t eta) { mEta = eta; }
void StForwardParticle::setPhi(Double_t phi) { mPhi = phi; }
void StForwardParticle::setM(Double_t m) { mM = m; }
void StForwardParticle::setE(Double_t e) { mE = e; }
void StForwardParticle::setPDG(int pdg) { mPdg = pdg; }
void StForwardParticle::setStatus(int stat) { mStatus = stat; }
void StForwardParticle::setFirstMother(int mom) { mFirstMother = mom; }
void StForwardParticle::setLastMother(int mom) { mLastMother = mom; }
void StForwardParticle::setFirstDaughter(int dau) { mFirstDaughter = dau; }
void StForwardParticle::setLastDaughter(int dau) { mLastDaughter = dau; }

