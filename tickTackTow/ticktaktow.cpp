// PractiseUnique.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <iomanip>


int const total_moves = 9;


int win_combo[16][3] = { {1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7},{7,5,3},{9,5,1},{9,6,3},{8,5,2},{7,4,1},{9,8,7},{6,5,4},{3,2,1} };

class Game
{

	static std::string m_array[total_moves];

public:

	Game() { }

	void print_mash() const {

		std::cout << std::endl << std::endl;

		int j = 0;

		for (int i = 1; i <= 11; i++) {

			if ((i % 2 == 0) && (i % 4 != 0)) {

				std::cout << "    " << m_array[j++] << "    " << "|";
				std::cout << "    " << m_array[j++] << "    " << "|";
				std::cout << "    " << m_array[j++] << "    " << std::endl;

			}
			else if ((i % 4 == 0) && (i != 0)) {
				std::cout << "---------|---------|---------" << std::endl;
			}
			else {
				std::cout << "         |         |         " << std::endl;
			}
		}
	}

	void set_mash(const int& pos, const char& element) {
		m_array[pos - 1] = element;
	}

	bool check_move(const int& m) {
		if (m_array[m - 1] == "*") {
			return true;
		}
		else 
			return false;
	}

	const char* get_mash_data(const int& d) {
		return (m_array[d - 1].c_str());
	}

	
};


std::string Game::m_array[total_moves] = { "*","*","*","*","*","*","*","*","*" };



class Player : public Game
{
	
	char m_xo;

public:

	Player(const char& xo) : m_xo(xo) {}

	char get_PlayerXo() const { return m_xo; }

	bool make_move(const int& place) {
			if (place < 10 && place > 0) {
				if (check_move(place)) {
					set_mash(place, m_xo);
					print_mash();
					return true;
				}
			}
			return false;
	}

	bool iswinner() {
		int win_count = 0;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 3; j++) {
				if ( *get_mash_data(win_combo[i][j]) == m_xo ) {
					win_count++;
				}
			}
			if (win_count == 3) {
				std::cout << "Congrates you won" << std::endl;
				return true;
			}
			else {
				win_count = 0;
			}
		}
		return false;
	}

};


class Ai : public Game
{
	char	m_xo;
	bool	m_combo, m_winCombo, m_oppWinCombo;

public:

	Ai(const char& xo) : m_xo(xo), m_combo(false), m_winCombo(false), m_oppWinCombo(false){}

	

	void make_aimove() {
		//TODO - get it to move
		if (m_winCombo) {
			//Do what it takes for winning
		}
		else if (m_oppWinCombo) {
			//Do what it takes to stop him win
		}
		else if (m_combo) {
			//do what it takes to make winning combo
		}
		else {
			//pick randam
		}


	}
};




int main()
{
	
	std::cout << "Hello Tick Tow player! Choose your Symbol O or X" << std::endl;
	
	char pch, aich, ch;

	while (true) {
		std::cin >> ch;
		if (ch == 'X' || ch == 'x') {
			pch = 'X';
			aich = 'O';
			break;
		}
		else if (ch == 'O' || ch == 'o') {
			pch = 'O';
			aich = 'X';
			break;
		}
		else {
			std::cout << "Not the correct number try again!!" << std::endl;
		}
	}
	
	Player p1(pch);
	Player p2(aich);
	p1.print_mash();

	bool no_winner = true;

	int turn = 0;
	int count = 0;

	while (no_winner) {
		int move = 0;
		if (turn == 0) {
			while (true) {
				std::cout << "Enter the position to make your move" << std::endl;
				std::cin >> move;
				if (p1.make_move(move)){
						turn = 1;
						count++;
						no_winner = !p1.iswinner();
						break;
					}
					else {
						std::cout << "Not the right move, choose again!!" << std::endl;
						continue;
					}
				}			
		}
		else {
			while (true) {
				std::cout << "Enter the position to make your move" << std::endl;
				std::cin >> move;
				if (p2.make_move(move)) {
					turn = 0;
					count++;
					no_winner = !p2.iswinner();
					break;
				}
				else {
					std::cout << "Not the right move, choose again!!" << std::endl;
					continue;
				}
			}
		}

		if (count == 9) {
			no_winner = false;
			std::cout << "Match Draw!!" << std::endl;
		}
	}



	std::cin.get();
	std::cin.get();
	return 0;
}

