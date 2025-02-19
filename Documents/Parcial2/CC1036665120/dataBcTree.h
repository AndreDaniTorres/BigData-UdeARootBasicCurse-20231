//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May 23 20:27:02 2023 by ROOT version 6.24/04
// from TTree treeBc/treeBc
// found on file: dataBc.root
//////////////////////////////////////////////////////////

#ifndef dataBcTree_h
#define dataBcTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class dataBcTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         Bcmass;
   Float_t         tau;
   Float_t         tauerror;

   // List of branches
   TBranch        *b_Bcmass;   //!
   TBranch        *b_tau;   //!
   TBranch        *b_tauerror;   //!

   dataBcTree(TTree *tree=0);
   virtual ~dataBcTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef dataBcTree_cxx
dataBcTree::dataBcTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("dataBc.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("dataBc.root");
      }
      f->GetObject("treeBc",tree);

   }
   Init(tree);
}

dataBcTree::~dataBcTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t dataBcTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t dataBcTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void dataBcTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Bcmass", &Bcmass, &b_Bcmass);
   fChain->SetBranchAddress("tau", &tau, &b_tau);
   fChain->SetBranchAddress("tauerror", &tauerror, &b_tauerror);
   Notify();
}

Bool_t dataBcTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void dataBcTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t dataBcTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef dataBcTree_cxx
