// Tower Container

#include "StForwardTower.h"

ClassImp(StForwardTower);

StForwardTower::StForwardTower()
{
}

Double_t StForwardTower::rap() { return StForwardTower::fourMomentum().Rapidity(); }

// Implement Setters
void StForwardTower::setPt(Double_t pt) { mPt = pt; }
void StForwardTower::setEta(Double_t eta) { mEta = eta; }
void StForwardTower::setPhi(Double_t phi) { mPhi = phi; }
void StForwardTower::setE(Double_t e) { mE = e; }

void StForwardTower::setId(short id) { mId = id; }
void StForwardTower::setDetectorId(short id) { mDetectorId = id; }

void StForwardTower::setAdc(short adc) { mAdc = adc; }
void StForwardTower::setPedestal(Double_t ped) { mPedestal = ped; }
void StForwardTower::setRms(Double_t rms) { mRms = rms; }
void StForwardTower::setStatus(short stat) { mStatus = stat; }
