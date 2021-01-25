#pragma once

class Position {
public:
	Position() = default;

	Position(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Position operator+(const Position& other) const {
		return Position(x + other.x, y + other.y);
	}
	bool operator<(const Position& other) const {
		if (x < other.x) {
			return true;
		}
		else if (x == other.x && y < other.y) {
			return true;
		}
		return false;
	}
	bool operator==(const Position& other) const {
		return x == other.x && y == other.y;
	}

	bool operator!=(const Position& other) const {
		return !(*this == other);
	}
	int x;
	int y;
};
