#include "TFile.h"
#include "TTree.h"
#include "TROOT.h"

#include "MyHitPattern.h"
#include "MyTrack.h"

#include <iostream>
#include <vector>


void foo()
{
    std::string fileName = "storageV2.root";

    TFile *file = new TFile(fileName.c_str(), "RECREATE");
    TTree *tree = new TTree("tree", "tree");

    std::vector<MyTrack> tracks;
    // 10 tracks
    for (int i = 0; i < 10; i++) {
        tracks.push_back(MyTrack());
        // 5 hits per track
        for (int j = 0; j < 5; j++) {
            tracks.back().setHitPattern(j + 1, j);
        }
        std::cout << "Inserted track " << i << std::endl;
    }
    tree->Branch("collection_split_level_default", &tracks, 32000);
    tree->Branch("collection_split_level_2", &tracks, 32000, 2);
    tree->Branch("collection_split_level_1", &tracks, 32000, 1);
    tree->Branch("collection_split_level_0", &tracks, 32000, 0);

    tree->Fill();
    file->Write();
    file->Close();
    std::cout << "Saved to file: " <<  fileName << std::endl;

    //releasing tree produces sigsev
    //delete tree;

    delete file;
}
