#include "win.h"
#include <windows.h>
#include <urlmon.h>
#include <cstdio>
#include <stdexcept>
#include <iostream>

namespace win
{

void download_file(const std::string& url,const std::string& name)
{
	std::cout << url << std::endl;
    if (URLDownloadToFile(0,url.c_str(),name.c_str(),0,0)!=S_OK)
        throw std::runtime_error("Cannot download \""+url+"\" as \""+name+"\"");
}

void create_dir(const std::string& name)
{
    CreateDirectory(name.c_str(),0);
}

void show_dir(const std::string& name)
{
	ShellExecute(0,"open",name.c_str(),0,0,SW_SHOWDEFAULT);
}

}
