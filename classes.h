#include "MyTrack.h"
#include <vector>

#ifdef __GCCXML__
template class std::vector<MyTrack>;

/*
namespace
{

struct GCCXML_DUMMY_INSTANTIATION {
    std::vector<MyTrack> vtrack;
};

}
*/
#endif

