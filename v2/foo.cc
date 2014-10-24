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

    std::vector<MyTrack> tracks;
    for (int i = 0; i < 10; i++) {
        tracks.push_back(MyTrack());
         for (int j = 0; j < 5; j++) {
            tracks.back().setHitPattern(j, j);
        }
       std::cout << "Inserted track " << i << std::endl;
    }
    m_rootTree->Branch("collection_split2", &tracks, 32000, 2);
    m_rootTree->Branch("collection_split1", &tracks, 32000, 1);
    m_rootTree->Branch("collection_split0", &tracks, 32000, 0);

    m_rootTree->Fill();
    m_rootFile->Write();
    m_rootFile->Close();
    //delete m_rootTree;
    //delete m_rootFile;
    return 0;
}
