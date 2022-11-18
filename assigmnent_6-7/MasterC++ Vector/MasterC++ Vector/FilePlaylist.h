#pragma once
#include "Playlist.h"

class FilePlaylist:public Playlist
{
protected:
	std::string filename;

public:
	FilePlaylist() : Playlist{}, filename{""}{}
	virtual ~FilePlaylist() {}

	void setFilename(const std::string& name) { this->filename = name; }
	virtual void WriteToFile() = 0;
	virtual void DisplayPlaylist() const= 0;
};

