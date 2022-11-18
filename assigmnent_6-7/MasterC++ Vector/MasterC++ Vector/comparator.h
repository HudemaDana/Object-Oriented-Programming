#pragma once
#include "C:/Users/dllov/OneDrive/Desktop/sem2/OOP/assigmnent_4-5/Master C++/Master C++/Tutorial.h"

template <class TElem>
class comparator {
public:
	virtual bool compare(const TElem& t1,const TElem& t2) = 0;
};

class ComparatorAscendingByTitle :public comparator<tutorial>
{
public:
	bool compare(const tutorial& t1,const tutorial& t2) override;
};

class ComparatorDescendingByPresenter :public comparator<tutorial>
{
public:
	bool compare(const tutorial& t1,const tutorial& t2) override;
};

void testLab();