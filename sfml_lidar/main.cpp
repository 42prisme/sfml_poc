
#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics.hpp>

#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <iostream>

/*
                                            _
                           ____ ___  ____ _(_)___
                          / __ `__ \/ __ `/ / __ \
                         / / / / / / /_/ / / / / /
                        /_/ /_/ /_/\__,_/_/_/ /_/
                        
*/

struct points{

	points(float p_x, float p_y)
	{
		this->x = p_x;
		this->y = p_y;
	}

	float x;
	float y;
};

void fill_point_list(){} //only if val sent are polar coordinates

sf::CircleShape DisplayPoint(points p_pts)
{
	sf::CircleShape shape(1.f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(p_pts.x, p_pts.y);
    return shape;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 800), "PellencForEver");

//window.create;
	window.setFramerateLimit(120);	

	ImGui::SFML::Init(window);

//
	bool newFrame = true;
	std::vector<points> pts ;
	//populate liste
	for (int j = 0; j < 10000; ++j)
	{
		std::cout << (std::rand()/((RAND_MAX + 1u)/1000)) << std::endl;
		pts.push_back(points(((std::rand()/((RAND_MAX + 1u)/2000))), (std::rand()/((RAND_MAX + 1u)/1000))));
	}

////////////////////////////////////////////////////////////////////////////////
//                                   Loop                                     //
////////////////////////////////////////////////////////////////////////////////

	while (window.isOpen()) {

		// sfml event -- mouse, keyboard ect.
		for (sf::Event sfevent; window.pollEvent(sfevent); ) {
			if (sfevent.type == sf::Event::Closed)
				window.close();	

			if(newFrame)
				window.clear(sf::Color::Black);

			//display points
			for (unsigned long i = 0; i < pts.size() ; i++)
			{
				window.draw(DisplayPoint(pts.at(i)));
				window.display();
			}
		}
	}
	return (0);
}
