#include "HTMLPlaylist.h"
#include <fstream>

void HTMLPlaylist::WriteToFile()
{
	std::ofstream g{ this->filename };
	g << "<!DOCTYPE html> \n";
	g << "<html>\n<head>\n    <title>Watchlist</title>\n</head>\n<body>\n<table border=\"1\">\n";
	g << "<tr>\n<td>Title</td>\n<td>Presenter</td>\n<td>Duration</td>\n<td>Likes</td>\n<td>Link</td>\n</tr>";
	for (auto& i : tutorials)
	{
		g << "<tr>\n";
		g << "<td>" << i.getTitle() << "</td>\n";
		g << "<td>" << i.getPresenter() << "</td>\n";
		g << "<td>" << i.getDuration().getMinute() << ":" << i.getDuration().getSeconds() << "</td>\n";
		g << "<td>" << i.getLikes() << "</td>\n";
		g << "<td>" << i.getLink() << "</td>\n";
		g << "</tr>\n";
	}
	g << "</table>\n</body>\n</html>";
}

void HTMLPlaylist::DisplayPlaylist() const
{
	std::string aux = "file:///C:/Users/dllov/OneDrive/Desktop/sem2/OOP/assigmnent_6-7/MasterC++%20Vector/MasterC++%20Vector/" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
	ShellExecuteA(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
