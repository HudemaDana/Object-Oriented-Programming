#include "comparator.h"
#include<vector>
#include <cassert>
bool ComparatorAscendingByTitle::compare(const tutorial& t1,const tutorial& t2)
{
    return t1.getTitle() > t2.getTitle();
}

bool ComparatorDescendingByPresenter::compare(const tutorial& t1,const tutorial& t2)
{
    return t1.getPresenter() < t2.getPresenter();
}

template <typename TELem>
void sort_lab(std::vector<TELem>& l, comparator<TELem>* c) {
	bool sortat;
	do
	{
		sortat = true;
		for (int i = 0; i < l.size() - 1; i++)
			if (c->compare(l[i], l[i + 1]))
			{
				auto aux = l[i];
				l[i] = l[i + 1];
				l[i + 1] = aux;
				sortat = false;
			}
	} while (!sortat);

}

void testLab()
{
	std::vector<tutorial> list;
	
	list.push_back(tutorial{ "t1","p1",Duration{1,1},1,"ceva" });
	list.push_back(tutorial{ "t3","p3",Duration{2,2},2,"ceva" });
	list.push_back(tutorial{ "t2","p2",Duration{3,3},3,"ceva" });
	list.push_back(tutorial{ "t4","p4",Duration{4,4},4,"ceva" });
	list.push_back(tutorial{ "t5","p5",Duration{5,5},5,"ceva" });

	comparator<tutorial>* c1 = new ComparatorAscendingByTitle{};
	sort_lab(list, c1);
	assert(c1->compare(list[1], list[2]) == false);
	assert(list[1].getTitle() == "t2");

	comparator<tutorial>* c2 = new ComparatorDescendingByPresenter{};
	sort_lab(list, c2);
	assert(list[0].getPresenter() == "p5");
	
	delete c1;
	delete c2;
}

