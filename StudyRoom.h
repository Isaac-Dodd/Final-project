
#ifndef STUDYROOM_H_
#define STUDYROOM_H_
#include "Resource.h"
class StudyRoom : public Resource{
private:
	int capacity;
	bool whiteBoard;
public:
	StudyRoom(int id,string n, string l, pair<double,double>a, bool co,
			  int c, bool wb):
			  Resource(id, n, l, a, co),
			  capacity(c), whiteBoard(wb) {}
	~StudyRoom();

	int getCapacity(){return capacity;}
	bool hasWhiteBoard(){return whiteBoard;}

	void setCapacity(int c){capacity = c;}
	void setWhiteBoard(bool wb){whiteBoard = wb;}

	void getResourceSpecifics()const
	{
		cout << "Capacity: " << capacity << " persons\n"
			 << "Has white board: ";
		if(whiteBoard) cout << "Yes\n";
		else cout << "No\n";
	}
};
#endif
