#ifndef POINT_HPP
#define POINT_HPP

class Point {

	private:
		int x;
		int y;

	public:
		Point(int, int);
		Point(const Point&);

		int getX() const;
		int getY() const;
		void setX(int);
		void setY(int);

		const Point& operator=(const Point&);

};

#endif
