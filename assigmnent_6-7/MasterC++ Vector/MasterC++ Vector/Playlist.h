#pragma once
#include "C:/Users/dllov/OneDrive/Desktop/sem2/OOP/assigmnent_4-5/Master C++/Master C++/Tutorial.h"
#include <vector>

class Playlist
{
protected:
	std::vector<tutorial> tutorials;
	int current;

public:
	Playlist();

	void add(const tutorial& t);
	void remove(const tutorial& elem);
	tutorial findByTitleAndPresenter(const std::string& title, const std::string& presenter);
	std::vector<tutorial>& getTutorials() { return tutorials; }
	virtual ~Playlist(){}
};

