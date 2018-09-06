#pragma once

class Player {
private:
	int score{ 0 };
	int highScore{ 0 };

public:
	Player() {}
	~Player() {}

	void addScore(const int s) { score += s; }
	
	const int getScore() const { return score; }
	const int getHighScore() const { return highScore; }

	bool updateHighScore()
	{
		if (score > highScore)
		{
			highScore = score;
			return true;
		}

		return false;
	}

	void reset() { score = 0; }
};