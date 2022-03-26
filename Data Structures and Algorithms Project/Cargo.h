#pragma once

class Cargo {

	static int CargoCount;
	int PT;
	int LT;
	int Type; //(1) VIP (2) Normal (3) Special
	int Distance;
	int Cost;

public:

	Cargo(int Type, int Prep, int Load, int Dist, int Cost);

	void SetType(int Cargo);
	int GetType() const;

	void SetPT(int P);
	int GetPT() const;

	void SetLT(int T);
	int GetLT() const;

	void SetDist(int D);
	int GetDist() const;

	void SetCost(int C);
	int GetCost() const;

};
