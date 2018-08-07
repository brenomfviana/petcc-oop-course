#ifndef _WORKER_HPP_
#define _WORKER_HPP_

#include "unit.hpp"
#include "entity.hpp"

class Worker : public Unit, public sf::Drawable
{
public:
	Worker();
	Worker(Color color);
	Worker(Color color, int x, int y);
	//virtual ~Worker(){}
private:
	int collected_wood; ///<
	int collected_rock; ///<
	int collected_iron; ///<
	int collected_food; ///<
	Color _color;
	virtual void draw(sf::RenderTarget& target, 
		sf::RenderStates states) const override;
	void _draw_avatar() const;
};

#endif /* _WORKER_HPP_ */
