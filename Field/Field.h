#ifndef FIELD
#define FIELD
#include "..\Cell\Cell.h"

class Field {
private:
	Cell** field;
	unsigned int width, height;
	Field(unsigned int width, unsigned int height) noexcept;
	Field(const Field& copy) noexcept;
	Field(Field&& copy) noexcept;
	Field operator=(const Field& copy) noexcept;
	Field operator=(Field&& copy) noexcept;
	
	void drawFrame();
	void drawGrid();
	void generateMaze();
	void display();
public:
	~Field();
	static Field& getInstance(unsigned int width, unsigned int height);
	Cell& getCell(unsigned int x, unsigned int y);
	unsigned int getWidth() const;
	unsigned int getHeight() const;
};

#endif