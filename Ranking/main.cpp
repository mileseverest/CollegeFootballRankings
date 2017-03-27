//
//  main.cpp
//  Rankings
//
//  Created by Miles Everest on 11/13/15.
//  Copyright © 2015 Miles. All rights reserved.
//

#include <iostream>
#include <string>
#include "Rank.h"
#include <sstream>
#include <algorithm>

using std::string;
using std::stoi;

void gatherTeams(Teams *team);
void getWinLoss(Teams *team);
void getOppWinLoss(Teams *team);
void createRanking(Teams *team);

int main(int argc, const char * argv[])
{
	
		int a;
		int *b;

		a = 1;
		b = 0;
		//c = add(a, b);
	
}

void gatherTeams(Teams *team)
{
	int i = 0, existFlag = 0, j = 0;

	ifstream data("teams.txt"); // open file for writing

	string line;
	while (getline(data, line)) // get the line
	{
		team[i].setTeamName(line);

		i++;

	}

	/*for (i = 0; i < 310; i++)
	{
		cout << team[i].getTeamName() << endl;
	}*/
}

void getWinLoss(Teams *team)
{
	cout << "Calculating Win Loss..." << endl;

	int i = 0;
	bool added = false;

	ifstream data("record.txt"); // open file for writing

	string line, copy;
	while (getline(data, line)) // get the line
	{
		stringstream  lineStream(line);
		string data, winner, loser, winPt, losPt;

		if (line.at(0) == '(')
		{
			string rank;
			getline(lineStream, rank, ' ');
			getline(lineStream, data, ',');
			winner = data;
		}

		else
		{
			getline(lineStream, data, ',');
			winner = data;
		}

		getline(lineStream, winPt, ',');

		getline(lineStream, data, ',');
		copy = data;
		stringstream  lineCopy(copy);

		if (copy.at(0) == '(')
		{
			string rank;
			getline(lineCopy, rank, ' ');
			getline(lineCopy, copy, ',');
			loser = copy;
		}

		else
		{
			getline(lineCopy, copy, ',');
			loser = data;
		}

		getline(lineStream, losPt, '\n');
		int winPoint = stoi(winPt);
		int losPoint = stoi(losPt);

		for (i = 0, added = false; (i < 310) && (added == false); i++)
		{
			if (winner == team[i].getTeamName())
			{
				team[i].addWin();
				team[i].addGamesPlayed();
				team[i].addPoint(team[i].getGamesPlayed() - 1, winPoint);
				team[i].addOppPoint(team[i].getGamesPlayed() - 1, losPoint);
				added = true;
			}
		}

		for (i = 0, added = false; (i < 310) && (added == false); i++)
		{
			if (loser == team[i].getTeamName())
			{
				team[i].addLoss();
				team[i].addGamesPlayed();
				team[i].addPoint(team[i].getGamesPlayed() - 1, losPoint);
				team[i].addOppPoint(team[i].getGamesPlayed() - 1, winPoint);
				added = true;
			}
		}
	}
}

void getOppWinLoss(Teams *team)
{
	cout << "Calculating Opponent Win Loss..." << endl;

	int i = 0, j = 0;
	bool added = false, oppAdded = false;

	ifstream data("record.txt"); // open file for writing

	string line;
	while (getline(data, line)) // get the line
	{
		stringstream  lineStream(line);
		string data, winner, loser;
		getline(lineStream, data, ',');
		winner = data;
		getline(lineStream, data, '\n');
		loser = data;

		for (i = 0, added = false; (i < 310) && (added == false); i++)
		{
			if (winner == team[i].getTeamName())
			{
				for (j = 0, oppAdded = false; (j < 310) && (oppAdded == false); j++)
				{
					if (loser == team[j].getTeamName())
					{
						team[i].setOppWin(team[j].getWins());
						team[i].setOppLoss(team[j].getLosses());
						oppAdded = true;
						added = true;
					}
				}
			}
		}

		for (i = 0, added = false; (i < 310) && (added == false); i++)
		{
			if (loser == team[i].getTeamName())
			{
				for (j = 0, oppAdded = false; (j < 310) && (oppAdded == false); j++)
				{
					if (winner == team[j].getTeamName())
					{
						team[i].setOppWin(team[j].getWins());
						team[i].setOppLoss(team[j].getLosses());
						oppAdded = true;
						added = true;
					}
				}
			}
		}
	}
}

void createRanking(Teams *team)
{
	cout << "Creating Rank Values..." << endl;

	int i = 0;

	while (i < 210)
	{
		double wins = team[i].getWins(), losses = team[i].getLosses(), oppWins = team[i].getOppWins(), oppLoss = team[i].getOppLosses();

		double record = (wins + 1) / (wins + losses + 2);
		double oppRecord = (oppWins + 1) / (oppWins + oppLoss + 2);

		double stat = ((record) / (1 - oppRecord)) / 2;

		team[i].setRankValue(stat);

		i++;
	}
}