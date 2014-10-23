#include "TFile.h"
#include "TTree.h"
#include "TROOT.h"

#include "MyHitPattern.h"
#include "MyTrack.h"

#include <iostream>
#include <vector>


int foo()
{
    std::string m_rootFileName = "storage.root";
    std::cout << m_rootFileName << std::endl;

    TFile *m_rootFile = new TFile(m_rootFileName.c_str(), "RECREATE");
    TTree *m_rootTree = new TTree("tree", "tree");
//    gROOT->ProcessLine("#include <vector>");
#define vector
#ifdef vector
    using namespace std;
    vector <MyTrack> tracks;
    for (int j = 0; j < 10; j++) {
        tracks.push_back(MyTrack());
        for (int i = 0; i < 25; i++) {
            tracks.back().setHitPattern(i, i);
        }
    }
    m_rootTree->Branch("collection", &tracks);

#else

    MyHitPattern hitp;
    for (int i = 0; i < 25; i++) {
        hitp.setHit(i, i);
    }
    m_rootTree->Branch("collection", &hitp);

#endif

    m_rootFile->Write();
    m_rootFile->Close();
//delete m_rootTree;
    delete m_rootFile;
    return 0;
}
