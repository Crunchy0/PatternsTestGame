#include <iostream>
#include <ctime>

#include "Field.h"

using namespace std;

	Field::Field(unsigned int width, unsigned int height) noexcept {
		this->width = width;
		this->height = height;
		this->field = new Cell * [this->height];
		for (unsigned int i = 0; i < this->height; i++) {
			this->field[i] = new Cell[this->width];
			for (unsigned int j = 0; j < this->width; j++) {
				this->field[i][j].addSub(new EmptySub());
			}
		}
		this->drawFrame();
		//this->generateMaze();
	}

	Field::Field(const Field& copy) noexcept {
		this->height = copy.height;
		this->width = copy.width;
		this->field = new Cell * [this->height];
		for (unsigned int i = 0; i < this->height; i++) {
			this->field[i] = new Cell[this->width];
			for (unsigned int j = 0; j < this->width; j++) {
				this->field[i][j] = copy.field[i][j];
			}
		}
	}

	Field::Field(Field&& copy) noexcept {
		for (unsigned int i = 0; i < this->height; i++) {
			delete[] this->field[i];
		}
		delete[] this->field;
		this->height = copy.height;
		this->width = copy.width;
		this->field = copy.field;
		copy.field = nullptr;
	}

	Field Field::operator=(const Field& copy) noexcept {
		if (this == &copy) {
			return *this;
		}

		for (unsigned int i = 0; i < this->height; i++) {
			delete[] this->field[i];
		}
		delete[] this->field;

		this->height = copy.height;
		this->width = copy.width;
		this->field = new Cell * [this->height];
		for (unsigned int i = 0; i < this->height; i++) {
			this->field[i] = new Cell[this->width];
			for (unsigned int j = 0; j < this->width; j++) {
				this->field[i][j] = copy.field[i][j];
			}
		}
		return *this;
	}

	Field Field::operator=(Field&& copy) noexcept {
		if (this == &copy) {
			return *this;
		}

		for (unsigned int i = 0; i < this->height; i++) {
			delete[] this->field[i];
		}
		delete[] this->field;

		this->height = copy.height;
		this->width = copy.width;
		this->field = copy.field;
		copy.field = nullptr;
		return *this;
	}

	Field::~Field() {
		for (unsigned int i = 0; i < this->height; i++) {
			delete[] this->field[i];
		}
		delete[] this->field;
	}

	void Field::drawFrame() {
		for (unsigned int i = 0; i < this->height; i++) {
			for (unsigned int j = 0; j < this->width; j++) {
				if (i == 0 || j == 0 || i == this->height - 1 || j == this->width - 1) {
					this->field[i][j].setType(1);
					this->field[i][j].setPassable(false);
				}
			}
		}
		this->field[0][1].setType(2);
		this->field[0][1].setPassable(true);
		this->field[this->height - 1][this->width - 2].setType(3);
		this->field[this->height - 1][this->width - 2].setPassable(true);
	}

	void Field::drawGrid() {
		if ((this->height > 2 && this->height < 5) || (this->width > 2 && this->width < 5)) {
			for (unsigned int i = 0; i < this->height; i++) {
				for (unsigned int j = 0; j < this->width; j++) {
					if (i == 0 || j == 0 || i == this->height - 1 || j == this->width - 1) {
						this->field[i][j].setType(1);
						this->field[i][j].setPassable(false);
					}
				}
			}
			this->field[0][1].setType(2);
			this->field[0][1].setPassable(true);
			this->field[this->height - 1][this->width - 2].setType(3);
			this->field[this->height - 1][this->width - 2].setPassable(true);
		}
		else {
			for (unsigned int i = 0; i < this->height; i++) {
				for (unsigned int j = 0; j < this->width; j++) {
					if (i % 2 != 0 && j % 2 != 0 && i < this->height - 1 && j < this->width - 1) {
						this->field[i][j].setType(0);
					}
					else {
						this->field[i][j].setType(1);
						this->field[i][j].setPassable(false);
					}
					this->field[0][1].setType(2);
					this->field[0][1].setPassable(true);
					unsigned int decX = this->width % 2 ? 0 : 1;
					unsigned int decY = this->height % 2 ? 0 : 1;
					this->field[this->height - 1 - decY][this->width - 2 - decX].setType(3);
					this->field[this->height - 1 - decY][this->width - 2 - decX].setPassable(true);
				}
			}
		}
	}

	void Field::generateMaze() {

		struct Point {
			unsigned int x;
			unsigned int y;
			bool visited;
		};

		struct PointStack {
			Point* array;
			unsigned int length;
			unsigned int top;
		};

		struct AdjPts {
			Point list[4];
			unsigned int length;
		};

		this->drawGrid();

		if (this->height >= 5 && this->width >= 5) {

			Point** map = new Point * [this->height];
			for (unsigned int i = 0; i < this->height; i++) {
				map[i] = new Point[this->width];
				for (unsigned int j = 0; j < this->width; j++) {
					map[i][j] = Point{ i, j, false };
					if (this->field[i][j].getType() == 1) {
						map[i][j].visited = true;
					}
				}
			}

			////////////////////////////////////

			PointStack stack = PointStack{ nullptr, 0, 0 };
			AdjPts neighbours{ {0,0,0,0}, 0 };
			Point cur = Point{ 1, 1, false };

			unsigned int unvisitedAmount = 0;
			do {
				unvisitedAmount = 0;
				for (unsigned int i = 1; i < this->height - 1; i += 2) {
					for (unsigned int j = 1; j < this->width - 1; j += 2) {
						if (!map[i][j].visited) {
							unvisitedAmount++;
						}
					}
				}

				if (!(map[cur.y][cur.x].visited)) {
					map[cur.y][cur.x].visited = true;
				}

				Point up = Point{ cur.x, cur.y - 2, false };
				Point down = Point{ cur.x, cur.y + 2, false };
				Point left = Point{ cur.x - 2, cur.y, false };
				Point right = Point{ cur.x + 2, cur.y, false };

				Point dir[4] = { up, down, left, right };

				for (unsigned int i = 0; i < 4; i++) {
					if ((dir[i].x > 0) && (dir[i].x < this->width - 1) && (dir[i].y > 0) && (dir[i].y < this->height - 1)) {
						if (!map[dir[i].y][dir[i].x].visited) {
							neighbours.list[neighbours.length] = dir[i];
							neighbours.length++;
						}
					}
				}

				if (neighbours.length) {
					unsigned int num = rand() % neighbours.length;
					Point newP = neighbours.list[num];



					int dx = (newP.x - cur.x) / 2;
					int dy = (newP.y - cur.y) / 2;

					unsigned int targX = cur.x + dx;
					unsigned int targY = cur.y + dy;

					this->field[targY][targX].setType(0);
					this->field[targY][targX].setPassable(true);

					if (stack.top < stack.length) {
						stack.top++;
					}
					else {
						PointStack nStack = PointStack{ nullptr, stack.length + 1, stack.top + 1 };
						nStack.array = new Point[nStack.length];
						for (unsigned int i = 0; i < stack.length; i++) {
							nStack.array[i] = stack.array[i];
						}
						delete[] stack.array;
						stack.array = nStack.array;
						stack.length = nStack.length;
						stack.top = nStack.top;
					}
					stack.array[stack.top - 1] = cur;

					cur = newP;
				}
				else {
					stack.top -= 1;
					if (stack.top > 0) {
						cur = stack.array[stack.top - 1];
					}
				}
				neighbours.length = 0;
			} while (unvisitedAmount > 0);

			delete[] stack.array;

			for (unsigned int i = 0; i < this->height; i++) {
				delete[] map[i];
			}
			delete[] map;
		}
	}

	void Field::display() {
		for (unsigned int i = 0; i < this->height; i++) {
			for (unsigned int j = 0; j < this->width; j++) {
				if (this->field[i][j].getType() == 1) {
					cout << "X ";
				}
				else if (this->field[i][j].getType() == 2) {
					cout << "I ";
				}
				else if (this->field[i][j].getType() == 3) {
					cout << "O ";
				}
				else {
					cout << "  ";
				}
			}
			cout << "\n";
		}
	}

	Field& Field::getInstance(unsigned int width, unsigned int height) {
		if (width <3) {
			width = 3;
		}
		if (height < 3) {
			height = 3;
		}
		static Field instance = Field(width, height);
		return instance;
	}

	Cell& Field::getCell(unsigned int x, unsigned int y) {
		return field[y][x];
	}

	unsigned int Field::getWidth() const {
		return width;
	}

	unsigned int Field::getHeight() const {
		return height;
	}