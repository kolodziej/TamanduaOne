#ifndef TAMANDUA_COMMAND_HPP
#define TAMANDUA_COMMAND_HPP

#include <vector>
#include <string>

namespace tamandua {

class Command
{
private:
	std::string name_;
	std::string format_;
	int params_min_;
	int params_max_;
	std::vector<std::string> params_;

public:
	Command(std::string, int = -1, int = 0);
	Command(std::string, std::string, int = -1, int = 0);

	std::string name();
	std::string format();
	int min();
	int max();
	virtual void run(std::vector<std::string>&) = 0;

protected:
	virtual bool validateParams_(std::vector<std::string>&) = 0;

};

}

#endif
