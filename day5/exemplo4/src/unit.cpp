#include "unit.hpp"

Unit::Unit() : _quantity(1), _health(100) { }

int Unit::get_quantity() const
{
	return _quantity;
}

void Unit::set_quantity(int quantity)
{
	if (quantity < 64)
	{
		_quantity = quantity;
	} else {
		_quantity = 64;
	}
}

sf::String Unit::get_string() const
{
	std::stringstream strs;
	strs << "units:\n" << get_quantity() << "\n";
	sf::String str(strs.str());
	return str;
}