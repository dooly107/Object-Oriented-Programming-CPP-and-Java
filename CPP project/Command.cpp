#include "Command.h"
#include "Zork.h"

Command::Command(rapidxml::xml_node<> * commandnode) {
	this -> command = commandnode -> value();
}