//
//  Rank.h
//  Rankings
//
//  Created by Miles Everest on 11/13/15.
//  Copyright © 2015 Miles. All rights reserved.
//

#ifndef Rank_h
#define Rank_h

#include <string>
#include <fstream>
using namespace std;

class Teams
{
private:
	int wins; // wins
	int losses; // losses
	int oppWins; // opponent wins
	int oppLosses; // opponent losses
	int ppg; // points per game
	int papg; // points allowed per game

	int gamesPlayed;

	int points[15];
	int oppPoints[15];

	double rankValue;

public:
	string teamName;

	Teams()
	{
		teamName = "";
		wins = 0;
		losses = 0;
		oppWins = 0;
		oppLosses = 0;
		ppg = 0;
		papg = 0;
		rankValue = 0.0;
		gamesPlayed = 0;

		for (int i = 0; i < 15; i++)
		{
			points[i] = 0;
			oppPoints[i] = 0;
		}
	}

	// Get Variables

	string getTeamName()
	{
		return teamName;
	}

	int getWins()
	{
		return wins;
	}

	int getLosses()
	{
		return losses;
	}

	int getOppWins()
	{
		return oppWins;
	}

	int getOppLosses()
	{
		return oppLosses;
	}

	int getPPG()
	{
		return ppg;
	}

	int getPAPG()
	{
		return papg;
	}

	double getRankValue()
	{
		return rankValue;
	}

	int getGamesPlayed()
	{
		return gamesPlayed;
	}

	// Set Variables

	void setTeamName(string name)
	{
		teamName = name;
	}

	void addWin()
	{
		wins++;
	}

	void addLoss()
	{
		losses++;
	}

	void setOppWin(int data)
	{
		oppWins += data;
	}

	void setOppLoss(int data)
	{
		oppLosses += data;
	}

	void setPPG(int points)
	{
		ppg = points;
	}

	void setPAPG(int points)
	{
		papg = points;
	}

	void setRankValue(double value)
	{
		rankValue = value;
	}

	void addGamesPlayed()
	{
		gamesPlayed++;
	}

	void addPoint(int game, int data)
	{
		points[game] = data;
	}

	void addOppPoint(int game, int data)
	{
		oppPoints[game] = data;
	}
};

bool operator<(Teams const & a, Teams const & b)
{
	return a.teamName < b.teamName;
}

#endif /* Rank_h */