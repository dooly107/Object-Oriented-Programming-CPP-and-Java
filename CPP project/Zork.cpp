#include "Zork.h"

Zork::Zork(string filename) {
	try {
		MakeNewWorld(filename);
	}
	catch (int error) {
		cout << "Error when parsing given xml file" <<endl;
	}
}

void Zork::listxmlintonodes(xml_node<> * child_node, queue<xml_node<> *>& items, queue<xml_node<> *>& rooms, queue<xml_node<> *>& containers, queue<xml_node<> *>& creatures) {
	while (child_node != NULL) {
		if (child_node -> name() == string("room")) {
			rooms.push(child_node);
		}
		else if (child_node -> name() == string("item")) {
			items.push(child_node);
		}
		else if (child_node -> name() == string("container")) {
			containers.push(child_node);
		}
		else if (child_node -> name() == string("creature")) {
			creatures.push(child_node);
		}
		child_node = child_node -> next_sibling();
	}
}

bool Zork::MakeNewWorld(string filename) {
	xml_document<> doc;
	xml_node<> * root_node;

	//Open XML file with given filename
	ifstream myFile(filename);
	if (!myFile.is_open()) {
		cout << "Error while opening XML file" << endl;
		return false;
	}

	//Read file into vector<char>
	vector<char> buffer((istreambuf_iterator<char>(myFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	doc.parse<0>(&buffer[0]);

	root_node = doc.first_node();
	xml_node<>* child_node = root_node->first_node();

	queue<xml_node<> *> items;
	queue<xml_node<> *> rooms;
	queue<xml_node<> *> containers;
	queue<xml_node<> *> creatures;

	listxmlintonodes(child_node,items,rooms,containers,creatures);

	Item * itemlists;
	while (items.size() != 0) {
		itemlists = new Item(items.front());
		items_map[itemlists->name] = itemlists;
		object_lookup_map[itemlists->name] = "item";
		items.pop();
	}


	Container * containerlists;
	while (containers.size() != 0) {
		containerlists = new Container(containers.front());
		containers_map[containerlists->name] = containerlists;
		object_lookup_map[containerlists->name] = "container";
		containers.pop();
	}

	Creature* creaturelists;
	while (creatures.size() != 0) {
		creaturelists = new Creature(creatures.front());
		creatures_map[creaturelists->name] = creaturelists;
		object_lookup_map[creaturelists->name] = "creature";
		creatures.pop();
	}

	Room* roomlist;
	while (rooms.size() != 0) {
		roomlist = new Room(rooms.front());
		rooms_map[roomlist->name] = roomlist;
		object_lookup_map[roomlist->name] = "room";
		rooms.pop();
	}

	startgame = true;
	return true;
}

void Zork::start() {
	currentroom = "Entrance";
	cout << rooms_map.find(currentroom)->second->description << endl;
	bool check = false;
	while(true) {
		getline(cin,userinput);
		cout << "You have entered: " << userinput << endl;

		userCommand(userinput);
		
	}
}

void Zork::userCommand(string input) {
	Room * curroom = rooms_map.find(currentroom) -> second;

	//Split input words
//	istringstream buf(input);
//	istream_iterator <std::string> beg(buf), end;
//	vector<string> commandstring(beg, end);

	if (input == "n" || input == "e" || input == "s" || input == "w") {
		changeroom(input);
	}
}

void Zork::changeroom(string input) {
	Room * curroom = rooms_map.find(currentroom) -> second;

	string direction;
	bool trig = false;

	if (input == "n") {
		direction = "north";
		trig = true;
	}
	else if (input == "e") {
		direction = "east";
		trig = true;
	}
	else if (input == "s") {
		direction = "south";
		trig = true;
	}
	else if (input == "w") {
		direction = "west";
		trig = true;
	}
	else {
		cout << "Error" << endl;
	}
	if (trig)
		bool check = checkroomtrigger(curroom -> triggers);

}

bool Zork::checkroomtrigger(vector<Trigger *> roomtrigger) {
	Trigger * trigger;
	for (std::vector<Trigger *>::iterator temp_trig = roomtrigger.begin(); temp_trig != roomtrigger.end(); temp_trig++) {
		trigger = *temp_trig;
		cout << trigger -> type << endl;
	}
	return true;
}

/*
bool Zork::checktriggers(){
	bool roomtriggertf = false;
	bool itemtriggertf = false;
	bool containertriggertf = false;
	bool creaturetriggertf = false;

	Room * temp_room_trig;
	Item * temp_item_trig;
	Container * temp_container_trig;
	Creature * temp_creature_trig;
	Trigger * temp_trigger;


	Room * curroom = rooms.find(currentroom) -> second;

	//Check Trigger in Current Room
	for (std::vector<Trigger *>::iterator trigger_room = curroom->triggers.begin(); trigger_room != curroom->triggers.end(); trigger_room++) {
		temp_trigger = *trigger_room;

	}
}
*/
