#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

class animal
{
public:
	virtual string myType(){ return "Animal"; }
	virtual int feedAnimals() = 0;
	virtual int cleanAnimals() = 0;
	virtual int healthRecords() = 0;
};
class reptiles :public animal
{
	int totalR;
public:
	reptiles()
	{
		totalR = 3;
	}
	string myType(){ return "Reptiles"; }
	int feedAnimals(){ return 1; }
	int cleanAnimals(){ return 0; }
	int healthRecords(){ return 1; }


	//void setTotalR(int r){ totalR = r; }
	int getTotalR(){ return totalR; }
};

class mammals :public animal
{
	int totalM;
public:
	mammals()
	{
		totalM = 5;
	}
	string myType(){ return "Mammals"; }
	//void setTotalM(int m){ totalM = m; }
	int getTotalM(){ return totalM; }
	int feedAnimals(){ return 0; }
	int cleanAnimals(){ return 1; }
	int healthRecords(){ return 1; }

};

class birds : public animal
{
	int totalB;
public:
	birds()
	{
		totalB = 10;
	}
	string myType(){ return "Birds"; }
	int getTotaolB(){ return totalB; }
	int feedAnimals(){ return 1; }
	int cleanAnimals(){ return 1; }
	int healthRecords(){ return 1; }

};

class people
{
	string feedback;
	int ticket;
public:
	void setFeedback(string f){ feedback = f; }
	string getFeedback(){ return feedback; }

	void setTicket(int t){ ticket = t; }
	int getTicket(){ return ticket; }
};


class zoo
{

private:
	animal *a;
	birds b; mammals m; reptiles r;
	people p[5];
	int totalAnimals;
	int revenuegenerated;

public:
	zoo(){ revenuegenerated = 0; }
	int getTotalNumber()
	{ 
		totalAnimals = b.getTotaolB() + m.getTotalM() + r.getTotalR();
		return totalAnimals; 
	}

	int getRevenueGenerated()
	{
		for (int i = 0; i < 5; i++)
		{
			this->revenuegenerated = p[i].getTicket() + this->revenuegenerated;
		}
		return revenuegenerated;
	}

	void peopleVisit()
	{
		int i = 0;
		while (i<5)
		{
			cout << "Person " << i + 1 << " enteried the zoo." << endl << " payed 10 Rs for his ticket. " << endl;
			p[i].setTicket(10);
			cout << "Person " << i + 1 << " leaving the zoo." << endl << "Please give your preciuos feedback: ";
			string f;
			getline(cin, f);
			p[i].setFeedback(f);
			i++;
		}
	}

	void displayFeedback()
	{
		int i = 0;
		while (i<5)
		{
			cout << endl << "   Feedbacks    " << endl
				<< "Person " << i + 1 << " feedback is " << endl
				<< "\t" << p[i].getFeedback() << endl << endl;
			i++;
		}
	}
};

int main()
{
	cout << endl << "            Welcome to zoo" << endl;
	zoo z;
	z.peopleVisit();
	



	int revenue = z.getRevenueGenerated();
	cout << "Total revenue generated is " << revenue << endl;
	z.displayFeedback();
	_getche();
	return 0;
}