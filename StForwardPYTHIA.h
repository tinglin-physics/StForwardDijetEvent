// Container for PYTHIA Level Info 

#ifndef StForwardPYTHIA_def
#define StForwardPYTHIA_def

#include "TObject.h"
#include "TRefArray.h"
#include "TVector3.h"
#include "TParticle.h"
#include "TClonesArray.h"

class StForwardDijetEvent;

class StForwardPYTHIA : public TObject {
 public:

  StForwardPYTHIA();

  enum { NPDF=34 };
  enum PDF { LO=0, NLO=1, STD=1, ZERO=2, MAX=3, MIN=4, M015=5, M030=6, M045=7, M060=8, M075=9, M090=10, M105=11, P030=12, P045=13, P060=14, P070=15, GS_NLOA=16, GS_NLOB=17, GS_NLOC=18, DSSV=19, LSS1=20, LSS2=21, LSS3=22, AAC1=23, AAC2=24, AAC3=25, BB1=26, BB2=27, DNS1=28, DNS2=29, DSSV2009a=30, LSS2010_delGpos=31, LSS2010_chsign_delG=32, BB2010=33 };

  // Declare Setters
  void setRunId(int id);
  void setEventId(int id);
  void setProcessId(int id);
  void setTune(int tune);
  void setVertex(TVector3 vertex);
  void setS(Double_t s);
  void setT(Double_t t);
  void setU(Double_t u);
  void setPt(Double_t pt);
  void setCosTheta(Double_t cosTheta);
  void setX1(Double_t x1);
  void setX2(Double_t x2);
  void setMstu72(int mstu72);
  void setMstu73(int mstu73);
  void setMstp111(int mstp111);
  void setQ2(Double_t q2);
  void setPartonALL(Double_t a);
  void setALL(int dist, Double_t a);

  const TClonesArray* particles() const;
  int numberOfParticles() const;
  const TParticle* particle(int i) const;

  void addParticle(const TParticle& particle);

  void Clear(Option_t* option = "");

  // Declare and Implement Getters
  int      runId() const { return mRunId; }
  int      eventId() const { return mEventId; }
  int      processId() const { return mProcessId; }
  int      tune() const { return mTune; }
  //const TVector3& vertex() const;
  Double_t vertX() const { return mVertexX; }
  Double_t vertY() const { return mVertexY; }
  Double_t vertZ() const { return mVertexZ; }
  Double_t s() const { return mS; }
  Double_t t() const { return mT; }
  Double_t u() const { return mU; }
  Double_t pt() const { return mPt; }
  Double_t cosTheta() const { return mCosTheta; }
  Double_t x1() const { return mX1; }
  Double_t x2() const { return mX2; }
  int      mstu72() const { return mMstu72; }
  int      mstu73() const { return mMstu73; }
  int      mstp111() const { return mMstp111; }
  Double_t Q2() const { return mQ2; }
  Double_t partonALL() const { return mPartonALL; }
  Double_t ALL(int dist) const { return mALL[dist]; }

 private:
  int      mRunId;
  int      mEventId;
  int      mProcessId;
  int      mTune;
  //TVector3 mVertex;
  Double_t mS;
  Double_t mT;
  Double_t mU;
  Double_t mPt;
  Double_t mCosTheta;
  Double_t mX1;
  Double_t mX2;
  int      mMstu72;
  int      mMstu73;
  int      mMstp111;
  Double_t mQ2;
  Double_t mPartonALL;
  Double_t mALL[NPDF];
  Double_t mVertexX;
  Double_t mVertexY;
  Double_t mVertexZ;

  TClonesArray* mParticles;

  ClassDef(StForwardPYTHIA,6);
};

#endif
