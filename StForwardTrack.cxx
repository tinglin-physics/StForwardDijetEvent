// Test of Track Container

#include "StForwardTrack.h"

ClassImp(StForwardTrack);

StForwardTrack::StForwardTrack()
{
}

Double_t StForwardTrack::rap() { return StForwardTrack::fourMomentum().Rapidity(); }

// Implement Setters
void StForwardTrack::setPt(Double_t pt) { mPt = pt; }
void StForwardTrack::setEta(Double_t eta) { mEta = eta; }
void StForwardTrack::setPhi(Double_t phi) { mPhi = phi; }

void StForwardTrack::setFlag(short flag) { mFlag = flag; }
void StForwardTrack::setCharge(short charge) { mCharge = charge; }
void StForwardTrack::setNHits(short hits) { mNHits = hits; }
void StForwardTrack::setNHitsFit(short hits) { mNHitsFit = hits; }
void StForwardTrack::setNHitsPoss(short hits) { mNHitsPoss = hits; }
void StForwardTrack::setNHitsDedx(short hits) { mNHitsDedx = hits; }
void StForwardTrack::setDedx(Double_t dedx) { mDedx = dedx; }
void StForwardTrack::setExitPoint(TVector3 exit) { mExitPoint.SetXYZ(exit.X(),exit.Y(),exit.Z()); }
void StForwardTrack::setExitTowerId(short id) { mExitTowerId = id; }
void StForwardTrack::setExitDetectorId(short id) { mExitDetectorId = id; }
void StForwardTrack::setDca(TVector3 dca) { mDca.SetXYZ(dca.X(),dca.Y(),dca.Z()); }
void StForwardTrack::setDcaD(Double_t dca) { mDcaD = dca; }
void StForwardTrack::setChi2(Double_t chi) { mChi2 = chi; }
void StForwardTrack::setChi2Prob(Double_t chi) { mChi2Prob = chi; }
void StForwardTrack::setBeta(Double_t beta) { mBeta = beta; }
void StForwardTrack::setFirstPoint(TVector3 point) { mFirstPoint.SetXYZ(point.X(),point.Y(),point.Z()); }
void StForwardTrack::setLastPoint(TVector3 point) { mLastPoint.SetXYZ(point.X(),point.Y(),point.Z()); }

void StForwardTrack::setnSigmaPion(float nSigmaPion){mnSigmaPion = nSigmaPion;}
void StForwardTrack::setnSigmaKaon(float nSigmaKaon){mnSigmaKaon = nSigmaKaon;}
void StForwardTrack::setnSigmaProton(float nSigmaProton){mnSigmaProton = nSigmaProton;}
void StForwardTrack::setnSigmaElectron(float nSigmaElectron){mnSigmaElectron = nSigmaElectron;}
