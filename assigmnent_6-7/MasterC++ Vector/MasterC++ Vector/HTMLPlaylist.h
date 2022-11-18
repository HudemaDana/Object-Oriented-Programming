#pragma once
#include "FilePlaylist.h"
#include<Windows.h>

class HTMLPlaylist:public FilePlaylist
{
public:
	HTMLPlaylist() :FilePlaylist{} { setFilename("tutorial.html"); }
	void WriteToFile() override;
	void DisplayPlaylist() const override;
};

