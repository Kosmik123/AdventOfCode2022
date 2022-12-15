#include "RockPaperScissors.h"

using namespace std;

void RockPaperScissors::solve(const string& input)
{
	list<string> lines;
	splitString(input, lines, enter);

	int score1 = 0;
	int score2 = 0;
	for (auto line = lines.begin(); line != lines.end(); ++line)
	{
		MoveType opponent = convert(line->at(0));
		MoveType myMove1 = convert(line->at(2));
		MoveType myMove2 = getMoveByResult(opponent, line->at(2));

		score1 += duel(opponent, myMove1);
		score2 += duel(opponent, myMove2);
	}
	output1 = score1;
	output2 = score2;
}

const int RockPaperScissors::duel(const MoveType opponentMove, const MoveType myMove) const
{
	int score = 0;
	switch (myMove)
	{
	case Rock:
		score += 1;
		break;
	case Paper:
		score += 2;
		break;
	case Scissors:
		score += 3;
		break;
	}

	bool draw = opponentMove == myMove;
	bool win = (opponentMove == Rock && myMove == Paper)
		|| (opponentMove == Paper && myMove == Scissors)
		|| (opponentMove == Scissors && myMove == Rock);
	if (win)
		score += 6;
	else if (draw)
		score += 3;

	return score;
}

const RockPaperScissors::MoveType RockPaperScissors::convert(const char letter) const
{
	if (letter == 'A' || letter == 'X')
		return Rock;

	if (letter == 'B' || letter == 'Y')
		return Paper;

	if (letter == 'C' || letter == 'Z')
		return Scissors;

	return None;
}

const RockPaperScissors::MoveType RockPaperScissors::getMoveByResult(const MoveType opponent, const char result) const
{
	switch (result)
	{
	case 'X': // LOSE
		if (opponent == Rock)
			return Scissors;
		if (opponent == Paper)
			return Rock;
		if (opponent == Scissors)
			return Paper;
		
	case 'Y': // DRAW
		return opponent;
		
	case 'Z': // WIN
		if (opponent == Rock)
			return Paper;
		if (opponent == Paper)
			return Scissors;
		if (opponent == Scissors)
			return Rock;
	}

	return None;
}
