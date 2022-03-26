#pragma once

class Truck {
	int ID;
	bool Available;
	static int TruckCount;
	int Type; //(1) VIP (2) Normal (3) Special
	int speed;
	int J; //Number of Journies Before Checkup
	int CheckUpDuration;
	
public:

	Truck(int T, int s, int J, int Duration);

	void SetType(int T);
	int GetType() const;
	
	void SetSpeed(int S);
	int GetSpeed() const;

	void SetJournies(int J);
	int GetJournies() const;

	void SetDuration(int Dur);
	int GetDuration() const;

};
