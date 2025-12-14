
#ifndef TUTORINGSESSION_H_
#define TUTORINGSESSION_H_
#include "Resource.h"
class TutoringSession : public Resource{
private:
	string tutor;
	string subject;

public:
	TutoringSession(int id, string n, string l, pair<double,double>a, bool co,
					string t, string s):
					Resource(id, n, l, a, co),
					tutor(t), subject(s){}
	virtual ~TutoringSession();

	string getTutor(){return tutor;}
	string getSubject(){return subject;}

	void setTutor(string t){tutor = t;}
	void setSubject(string s){subject = s;}

	void getResourceSpecifics()const
		{
			cout << "Tutor: " << tutor << endl
				 << "Subject: " << subject << endl;
		}
};
#endif
