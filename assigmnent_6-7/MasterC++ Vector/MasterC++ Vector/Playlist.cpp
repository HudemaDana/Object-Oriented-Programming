#include "Playlist.h"

Playlist::Playlist()
{
	this->current = 0;
}

void Playlist::add(const tutorial& t)
{
	tutorials.push_back(t);
}

void Playlist::remove(const tutorial& elem)
{
	int size = tutorials.size();
	auto it = std::remove_if(tutorials.begin(), tutorials.end(), [&elem](tutorial& i) {return i == elem; });
	if (it != tutorials.end())
		tutorials.resize(tutorials.size() - 1);
	return;
}

tutorial Playlist::findByTitleAndPresenter(const std::string& title, const std::string& presenter)
{

	auto it = std::find_if(tutorials.begin(), tutorials.end(), [&presenter, &title](const tutorial& i) {return i.getPresenter() == presenter && i.getTitle() == title; });
	if (it != tutorials.end())
		return *it;

	//throw MyException{ "Invalid input for your operation.The element was not found" };
}



//tutorial Playlist::getCurrentTutorial()
//{
//	if (this->current == this->tutorials.size())
//		this->current = 0;
//	return this->tutorials[this->current];
//	return tutorial{};
//}
//
//void Playlist::next()
//{
//	if (this->tutorials.size() == 0)
//		return;
//	this->current++;
//	this->getCurrentTutorial().play();
//}
//
//void Playlist::play()
//{
//	if (this->tutorials.size() == 0)
//		return;
//	this->current = 0;
//	this->getCurrentTutorial().play();
//}
//
//bool Playlist::isEmpty()
//{
//	return this->tutorials.size() == 0;
//}
