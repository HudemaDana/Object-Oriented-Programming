#pragma once
#include "FilePlaylist.h"


class CSVPlaylist:public FilePlaylist
{
public:
	CSVPlaylist() :FilePlaylist{} { setFilename("tutorial.csv"); }
	void WriteToFile() override;
	void DisplayPlaylist() const override;
};

