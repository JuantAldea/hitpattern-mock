#include "MyTrack.h"
#include <vector>

#ifdef __GCCXML__

template class std::vector<MyTrack>;
template class std::vector<int>;

/*
namespace
{

struct GCCXML_DUMMY_INSTANTIATION {
    std::vector<MyTrack> vtrack;
};

}
*/
#endif

