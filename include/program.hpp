#include <iostream>
#include <unistd.h>

// template<typename T = double>
#define precision 0.00001

class Program
{
	unsigned int position = 0;
	int address(int hex);

public:
	unsigned char program_memory[36] = {};
	void add(unsigned char code) { 
		program_memory[position] = code; 
		position++;
	} // запись кода в массив
	unsigned char operator[](int pos) { return program_memory[pos]; } // it = prog[13];
	void set_position(int pos) { position = pos; }
	void fin_subprogram() { position = 0; }
	void fin_program() {  }
	void next_cell() { position++; } // подвинуть на один вперед
	void previous_cell() { position--; } // подвинуть на один назад
	int condition(auto x_register_ptr); // условные переходы
	void clear() { for(int i = 0; i < 36; i++) program_memory[i] = 0; } // обнулить массив
	unsigned int get_position() { return position; }
	
	/*
	class Iterator
	{
		unsigned int position;
		public:
		Iterator();

		Iterator& operator=(unsigned char*); // it = prog.begin();
		Iterator& operator++(int); // подвинуть вправо
		Iterator& operator--(int); // подвинуть влево
		unsigned char operator*(); // позиция итератора
		int take(unsigned char*); // если итератор проходится по массиву в режиме RUN
	
		void place(unsigned char);
		unsigned char read();
		void move_right();
		void move_left();
	};
	*/	
};

//class Iterator: protected Program

int Program::address(int hex)
{
	// пересчитываем шестиричный адрес в десятичный
	// -1 возвращается, если адреса не существует
	if (hex % 10 > 6)
	{
		return -1;
	}
	return (hex / 10) + (hex % 10) - 1;
};

int Program::condition(auto x_register_ptr)
{
	std::cout << "Condition" << std::endl;
	int jump;
	jump = address(program_memory[position + 1]);
	switch ( program_memory[position] / 10)
	{
		case 4:
		{
			std::cout << "case 49: >= 0" << std::endl;
			if (*x_register_ptr >= 0)
			{
				std::cout << "condition 49 met" << std::endl;
				position += 2;
				break;
			}
			std::cout << "condition 49 is not met, jumping" << std::endl;
			if (jump != -1)
			{
				position = jump;
				return 0;
			}
			return -1;
		}
		case 5:
		{
			std::cout << "case 59: = 0" << std::endl;
			if (*x_register_ptr >= -precision && *x_register_ptr <= precision)
			{
				std::cout << "condition 59 met" << std::endl;
				position += 2;
				break;
			}
			std::cout << "condition 59 is not met, jumping" << std::endl;
			if (jump != -1)
			{
				position = jump;
				return 0;
			}
			return -1;
		}
		case 6:
		{
			std::cout << "case 69: < 0" << std::endl;
			if (*x_register_ptr < 0)
			{
				std::cout << "condition 69 met" << std::endl;
				position += 2;
				break;
			}
			std::cout << "condition 69 is not met, jumping" << std::endl;
			if (jump != -1)
			{
				position = jump;
				return 0;
			}
			return -1;
		}
		case 7:
		{
			std::cout << "case 79: != 0" << std::endl;
			if (*x_register_ptr >= precision || *x_register_ptr <= -precision)
			{
				std::cout << "condition 79 met" << std::endl;
				position += 2;
				break;
			}
			std::cout << "condition 79 is not met, jumping" << std::endl;
			if (jump != -1)
			{
				position = jump;
				return 0;
			}
			return -1;
		}
		default:
		{
			std::cout << "This is not a condition" << std::endl;
			return -2;
			break;
		}
	}
};
