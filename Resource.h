#ifndef RESOURCE_H_
#define RESOURCE_H_
#include <bits/stdc++.h>
using namespace std;

class Resource {
private:
	int id;
	string name;
	string location;
	pair<double, double> availability;
	bool checkedOut;
public:
	Resource(int id, string n, string l, pair<double, double>a, bool co):
		id(id), name(n), location(l), availability(a), checkedOut(co){}
	virtual ~Resource();
	virtual void getResourceSpecifics() const = 0;
	int getId(){return id;}
	string getName(){return name;}
	bool isCheckedOut(){return checkedOut;}
	pair<double, double> getAvailability(){return availability;}

	void setId(int id){this->id = id;}
	void setName(string n){name = n;}
	void setLocation(string l){location = l;}
	void setAvailability(pair<double, double> a){availability = a;}
};
#endif
