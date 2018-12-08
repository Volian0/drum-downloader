#include "drum_downloader.h"
#include "win.h"
#include "experimental/json.h"

namespace pt2
{

api::api(const std::string& d,const std::string& u)
    : base_dir(d), base_url(u)
{
    parse_json();
}

void api::parse_json()
{
	win::create_dir(base_dir);
    win::download_file(base_url,base_dir+"\\instruments.json");
    const json::JsonFile file(base_dir+"\\instruments.json");
    auto array = file.value->GetObject()->Find("data")->GetArray();
    for (unsigned i=0; i<array->GetSize(); ++i)
    {
        std::string name = array->GetValue(i)->GetObject()->Find("name")->GetString();
		win::create_dir(base_dir+"\\"+name);
        win::download_file(base_url+name,base_dir+"\\"+name+".json");
        const json::JsonFile file2(base_dir+"\\"+name+".json");
        auto data = file2.value->GetObject()->Find("data")->GetObject();
        std::string base_url2 = data->Find("base_url")->GetString();
        auto array2 = data->Find("pitches")->GetArray();
        for (unsigned i2=0; i2<array2->GetSize(); ++i2)
        {
            auto note = array2->GetValue(i2)->GetObject();
            std::string path = note->Find("path")->GetString();
            std::string name2 = note->Find("name")->GetString();
            win::download_file(base_url2+path,base_dir+"\\"+name+"\\"+name2+".mp3");
        }
    }
	win::show_dir(base_dir);
}

}
