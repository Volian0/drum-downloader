#include "drum_downloader.h"

int main(int argc, char* argv[])
{
    std::string url{"http://op-pt2.cmcm.com/api/instruments/"};
    std::string dir{"music"};
    if (argc>1) url = argv[1];
    if (argc>2) dir = argv[2];
    pt2::api api(dir,url);
    return 0;
}
