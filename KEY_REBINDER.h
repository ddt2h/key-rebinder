#pragma once
#include "Keys.h"
#include "Input_Mechanics.h"
class KEY_REBINDER
{
private:
	sf::Clock global_clock;
	
	double time_line; //in ms



	//key - key
	std::pair<int, sf::Keyboard::Key> bind_keys;

	bool inst_finished = false;
	void realize()
	{
		//organize down-up

		bool is_down = false;
		if (sf::Keyboard::isKeyPressed(bind_keys.second))
		{
			is_down = true;
		//	std::cout << "u pressed lol" << std::endl;

			advanced_mouse_down("left");
		}
		if (!sf::Keyboard::isKeyPressed(bind_keys.second) && is_down)
		{
			is_down = false;
		//	std::cout << "u released lol" << std::endl;

			advanced_mouse_up("left");
		}
	}
	void scan_input()
	{
		/*for (sf::Keyboard::Key i = sf::Keyboard::Key::Unknown; i < sf::Keyboard::Key::Return; i = sf::Keyboard::Key(i + 1))
		{
			if (sf::Keyboard::isKeyPressed(i))
				std::cout << i << std::endl;
		}*/

		std::cout << "Press a key/mouse button you need to imitate" << std::endl;

		
		while (!inst_finished)
		{
			if (bind_keys.first == -1)
			{
				for (sf::Mouse::Button i = sf::Mouse::Button::Left; i < sf::Mouse::Button::ButtonCount; i = sf::Mouse::Button(i + 1))
				{
					if (sf::Mouse::isButtonPressed(i))
					{
						std::cout << "You chose mouse: " << i << " for imitating" << std::endl;;
					
						std::cout << "Press a key/mouse button you need to imitate" << std::endl;
						bind_keys.first = i;
						break;
					}

				}
			}

			if (bind_keys.second == sf::Keyboard::Key::Unknown && bind_keys.first != -1)
			{
				
				for (sf::Keyboard::Key i = sf::Keyboard::Key::Unknown; i < sf::Keyboard::Key::Return; i = sf::Keyboard::Key(i + 1))
				{
					if (sf::Keyboard::isKeyPressed(i))
					{
						std::cout << "You chose keyboard: " << i << " for binding" << std::endl;
						bind_keys.second = i;
						
						break;
					}

				}
			}
			if (bind_keys.first != -1 && bind_keys.second != sf::Keyboard::Key::Unknown)
			{
				inst_finished = true;
			}
		}
		
	}
	void cycle()
	{
		global_clock.restart();
		scan_input();
		for (;;)
		{
			realize();
			//time_line = global_clock.getElapsedTime().asMilliseconds();
			
		}
	}
public:
	KEY_REBINDER()
	{
		bind_keys.first = -1;
		bind_keys.second = sf::Keyboard::Key::Unknown;
	}
	void rebind_key(int trigger_key, int substitute_key)
	{

	}
	void rebind_mouse(int trigger_key, int substitute_mouse)
	{

	}
	void start()
	{
		std::thread cycle_thread(&KEY_REBINDER::cycle, this);
		cycle_thread.detach();
	}
};