// PYTHIA Info

#include "StForwardPYTHIA.h"

ClassImp(StForwardPYTHIA);

StForwardPYTHIA::StForwardPYTHIA()
{
  mParticles = new TClonesArray("TParticle");
  
  Clear();
}

void StForwardPYTHIA::setRunId(int id) { mRunId = id; }
void StForwardPYTHIA::setEventId(int id) { mEventId = id; }
void StForwardPYTHIA::setProcessId(int id) { mProcessId = id; }
void StForwardPYTHIA::setTune(int tune) { mTune = tune; }
void StForwardPYTHIA::setVertex(TVector3 vertex)
{
  mVertexX = vertex.X();
  mVertexY = vertex.Y();
  mVertexZ = vertex.Z();
}
void StForwardPYTHIA::setS(Double_t s) { mS = s; }
void StForwardPYTHIA::setT(Double_t t) { mT = t; }
void StForwardPYTHIA::setU(Double_t u) { mU = u; }
void StForwardPYTHIA::setPt(Double_t pt) { mPt = pt; }
void StForwardPYTHIA::setCosTheta(Double_t theta) { mCosTheta = theta; }
void StForwardPYTHIA::setX1(Double_t x1) { mX1 = x1; }
void StForwardPYTHIA::setX2(Double_t x2) { mX2 = x2; }
void StForwardPYTHIA::setMstu72(int m) { mMstu72 = m; }
void StForwardPYTHIA::setMstu73(int m) { mMstu73 = m; }
void StForwardPYTHIA::setMstp111(int m) { mMstp111 = m; }
void StForwardPYTHIA::setQ2(Double_t q) { mQ2 = q; }
void StForwardPYTHIA::setPartonALL(Double_t a) { mPartonALL = a; }
void StForwardPYTHIA::setALL(int dist, Double_t a) { mALL[dist] = a; }

//float StForwardPYTHIA::ALL(int dist) { return

const TClonesArray* StForwardPYTHIA::particles() const { return mParticles; }

int StForwardPYTHIA::numberOfParticles() const { return mParticles->GetEntriesFast(); }

const TParticle* StForwardPYTHIA::particle(int i) const { return (TParticle*)mParticles->At(i); }

void StForwardPYTHIA::addParticle(const TParticle& particle)
{
  new ((*mParticles)[mParticles->GetEntriesFast()]) TParticle(particle);
}

void StForwardPYTHIA::Clear(Option_t* option)
{
    if (mParticles) mParticles->Clear(option);
}
