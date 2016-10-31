// Test of Dijet

#include "StForwardDijet.h"
#include "StForwardJet.h"
#include "TVector3.h"

ClassImp(StForwardDijet);

StForwardDijet::StForwardDijet()
{
}

void StForwardDijet::setTrigCombo(short trig) { mTrigCombo = trig; }
void StForwardDijet::setMass(Double_t mass) { mMass = mass; }
void StForwardDijet::setNoMass(Double_t noMass) { mNoMass = noMass; }
void StForwardDijet::setVertex(TVector3 vertex)
{
  mVertexX = vertex.X();
  mVertexY = vertex.Y();
  mVertexZ = vertex.Z();
}

Double_t StForwardDijet::cosPhiDiff() const
{
  StForwardJet *jet1 = jet(0);
  StForwardJet *jet2 = jet(1);

  return TMath::Cos(jet1->phi()-jet2->phi());
}

Double_t StForwardDijet::ptBalance() const
{
  StForwardJet *same = sameSide();
  StForwardJet *away = awaySide();

  return away->pt()/same->pt();
}

Double_t StForwardDijet::etaSum() const
{
  StForwardJet *jet1 = jet(0);
  StForwardJet *jet2 = jet(1);

  return jet1->eta() + jet2->eta();
}

Double_t StForwardDijet::etaDiff() const
{
  StForwardJet *jet1 = jet(0);
  StForwardJet *jet2 = jet(1);

  return TMath::Abs(jet1->eta() - jet2->eta());
}

Double_t StForwardDijet::x1Calc() const
{
  Double_t x;
  x = (mass()/200.0)*TMath::Exp(0.5*etaSum());
  return x;
}

Double_t StForwardDijet::x2Calc() const
{
  Double_t x;
  x = (mass()/200.0)*TMath::Exp(-0.5*etaSum());
  return x;
}

Double_t StForwardDijet::cosTheta() const
{
  Double_t x;
  x = TMath::TanH(0.5*etaDiff());
  return x;
}


// Get Number of Dijets
int StForwardDijet::numberOfJets() const { return mJets.GetEntriesFast(); }

// Get Jet
StForwardJet* StForwardDijet::jet(int i) const { return (StForwardJet*)mJets.At(i); }

StForwardJet* StForwardDijet::sameSide() const
{
  StForwardJet *jet1 = jet(0);
  StForwardJet *jet2 = jet(1);

  if(jet1->isSameSide()) return jet1;
  if(jet2->isSameSide()) return jet2;
  return 0;
}

StForwardJet* StForwardDijet::awaySide() const
{
  StForwardJet *jet1 = jet(0);
  StForwardJet *jet2 = jet(1);
  
  if(!jet1->isSameSide()) return jet1;
  if(!jet2->isSameSide()) return jet2;
  return 0;
}

// Add Jet to Dijet
StForwardJet* StForwardDijet::addJet(StForwardJet* jet) { mJets.Add((TObject*)jet); return (StForwardJet*)mJets.Last(); }

