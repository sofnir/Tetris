#include "FiguresFactory.h"

FiguresFactory::FiguresFactory()
{
	;
}

Figure * FiguresFactory::create(int number) const
{
	Figure * figure;

	switch (number)
	{
	case 1:
		figure = new Figure(figure_I, number,true);
		break;
	case 2:
		figure = new Figure(figure_Z, number, true);		
		break;
	case 3:
		figure = new Figure(figure_S, number, true);		
		break;
	case 4:
		figure = new Figure(figure_T, number, true);		
		break;
	case 5:
		figure = new Figure(figure_L, number, true);		
		break;
	case 6:
		figure = new Figure(figure_J, number, true);
		break;
	case 7:
		figure = new Figure(figure_O, number, false);
		break;
	default:
		return nullptr;
	}

	return figure;
}