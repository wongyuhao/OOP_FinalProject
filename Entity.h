#pragma once
class Entity
{
private:
	int posX;
	int posY;
	char ID;



public:
	Entity(char id, int x, int y):
	ID(id),
	posX(x),
	posY(y)
	{
		
	}

	Entity() {};

	void setPosX(int x) {
		posX = x;
	}

	int getPosX() const {
		return posX;
	}

	void setPosY(int y) {
		posY = y;
	}

	int getPosY()const {
		return posY;
	}

	void setID(char id) {
		this->ID = id;
	}
	char getID()const {
		return ID;
	}

};
