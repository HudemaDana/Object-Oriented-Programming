#include "CSVPlaylist.h"
#include <fstream>
#include <Windows.h>

void CSVPlaylist::WriteToFile()
{
	std::ofstream g{this->filename};
	for (auto& i : this->tutorials)
		g << i;
}

void CSVPlaylist::DisplayPlaylist() const
{
	std::string aux =this->filename; // if the path contains spaces, we must put it inside quotations
	ShellExecuteA(NULL, NULL, "c:\\Program Files\\LibreOffice\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
