#ifndef _UNIT_HPP_
#define _UNIT_HPP_

#include "entity.hpp"
#include <sstream>

class Unit : public Entity
{
public:
	Unit();
	//virtual ~Unit() { };
	int get_quantity() const;
	sf::String get_string() const;
	void set_quantity(int quantity);
private:
	int _quantity; ///< Number of units
	int _health; ///< Unit health
};

#include "worker.hpp"
//#include "soldier.h"

#endif /* _UNIT_HPP_ */
