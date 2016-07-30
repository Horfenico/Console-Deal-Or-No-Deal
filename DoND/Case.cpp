#include "Case.h"
std::ostream& operator<<(std::ostream& ostr, const Case& cas)
{
	ostr << "Case Number: " << cas.getNum() <<
		"\n Case Value ($): " << cas.getValue() << std::endl;
	return ostr;
}