#ifndef DRUM_DOWNLOADER_H
#define DRUM_DOWNLOADER_H

#include <string>
#include <vector>

namespace pt2
{

class api
{
public:
    api(const std::string&,const std::string&);
protected:
    const std::string base_dir;
    const std::string base_url;
    void parse_json();
};

}

#endif
