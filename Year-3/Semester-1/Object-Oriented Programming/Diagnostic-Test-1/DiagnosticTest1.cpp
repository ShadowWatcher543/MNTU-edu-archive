class coord {
	int x,y;
	
	public:
	coord() { 
		x = 0; 
		y = 0; 
	}
	coord(int i, int j) { 
		x = i; 
		y = j; 
	}
	void get_xy(int &i, int &j) { 
		i = x; 
		j = y; 
	}
	// ... оголошення оператора-функції
};
	//... визначення оператора-функції для int + coord
	void main() { //... оголошення об’єктів
	// ... додавання числа і об’єкта - виклик оператора-функції
};