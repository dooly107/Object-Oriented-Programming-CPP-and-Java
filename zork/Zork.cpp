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

	Item * tempitem;
	while (items.size() != 0) {
		tempitem = new Item(items.front());
		itemlist.push_back(tempitem);
		items.pop();
	}

	Container * tempcontainer;
	while (containers.size() != 0) {
		tempcontainer = new Container(containers.front());
		containerlist.push_back(tempcontainer);
		containers.pop();
	}

	Creature* tempcreature;
	while (creatures.size() != 0) {
		tempcreature = new Creature(creatures.front());
		creaturelist.push_back(tempcreature);
		creatures.pop();
	}

	Room* temproom;
	while (rooms.size() != 0) {
		temproom = new Room(rooms.front());
		roomlist.push_back(temproom);
		rooms.pop();
	}

	startgame = true;
	finishgame = false;
	return true;
}

void Zork::start() {
	currentroom = roomlist[0];
	cout << roomlist[0] -> description << endl;
	bool override = false;
	while(true) {
		override = checktrigger_wocommand();
		if (override) {
			continue;
		}
		if (finishgame) {
			break;
		}
		getline(cin,userinput);

		override = checktrigger_wcommand(userinput);
		if (override) {
			continue;
		}
		if (finishgame) {
			break;
		}
		inputcommand(userinput);
	}
}

void Zork::inputcommand(string userinput) {
	if ((userinput == "n") || (userinput == "s") || (userinput == "e") || (userinput == "w")) {
		changeroom(userinput);
		return;
	}
	else if (userinput == "i") {
		listinventory();
		return;
	}
	else if (userinput.find("take") != string::npos) {
		taketoinventory(userinput);
		return;
	}
	else if (userinput == "open exit") {
		openexit();
		return;
	}
	else if (userinput.find("open") != string::npos) {
		opencontainer(userinput);
		return;
	}
	else if (userinput.find("read") != string::npos) {
		readitem(userinput);
		return;
	}
	else if (userinput.find("drop") != string::npos) {
		dropitem(userinput);
		return;
	}
	else if (userinput.find("put") != string::npos) {
		putitemincontainer(userinput);
		return;
	}
	else if (userinput.find("turn on") != string::npos) {
		turnonitem(userinput);
		return;
	}
	else if (userinput.find("attack") != string::npos) {
		attackcreature(userinput);
		return;
	}
	else {
		cout << "Error" << endl;
		return;
	}
}

void Zork::attackcreature(string input) {
	string removeattack = input.erase(0,7);
	int find = removeattack.find(" with ");
	string creature = removeattack.substr(0,find);
	string item = removeattack.substr(find+6);
	int i;
	int j;
	int k;
	int l;

	bool exist = false;


	for (i = 0; i < inventory.size(); i++) {
		if (inventory[i] == item) {
			exist = true;
		}
	}
	if (exist == false) {
		cout << "Error" << endl;
		return;
	}
	for (i = 0; i < currentroom -> creature.size(); i++) {
		if (currentroom -> creature[i] == creature) {
			for (j = 0; j < creaturelist.size(); j++) {
				if (creaturelist[j] -> name == creature) {
					for (k = 0; k < creaturelist[j] -> vulnerability.size(); k++) {
						if (creaturelist[j] -> vulnerability[k] == item) {
							if (creaturelist[j] -> attackexist == true) {
								if (creaturelist[j] -> attack -> conditionexist) {
								bool compare = false;
								bool find = false;
								for (l = 0; l < itemlist.size(); l++) {
									if (itemlist[l] -> name == creaturelist[j] -> attack -> condition.object) {
										find = true;
										if (itemlist[l] -> status == creaturelist[j] -> attack -> condition.status) {
											compare = true;
										}
										break;
									}
								}
								if (find == false) {
									for (l = 0; l < roomlist.size(); l++) {
										if (roomlist[l] -> name == creaturelist[j] -> attack -> condition.object) {
											find = true;
											if (roomlist[l] -> status == creaturelist[j] -> attack -> condition.status) {
												compare = true;
											}
										}
										break;
									}
								}
								if (find == false) {
									for (l = 0; l < containerlist.size(); l++) {
										if (containerlist[l] -> name == creaturelist[j] -> attack -> condition.object) {
											find = true;
											if (containerlist[l] -> status == creaturelist[j] -> attack -> condition.status) {
												compare = true;
											}
										}
										break;
									}
								}
								if (find == false) {
									for (l = 0; l < creaturelist.size(); l++) {
										if (creaturelist[l] -> name == creaturelist[j] -> attack -> condition.object) {
											find = true;
											if (creaturelist[l] -> status == creaturelist[j] -> attack -> condition.status) {
												compare = true;
											}
										}
										break;
									}
								}
								if (compare == false) {
									cout << "Error" << endl;
									return;
								}
								}
								if (creaturelist[j] -> attack -> printexist) {
									cout << "You assult the " << creature << " with the " << item << "." << endl;
									cout << creaturelist[j] -> attack -> print << endl;
								}
								if (creaturelist[j] -> attack -> actionexist) {
									for (l = 0; l < creaturelist[j] -> attack -> action.size(); l++) {
										performaction(creaturelist[j] -> attack -> action[l]);
									}
								}
								return;
							}
							else {
								cout << "You assult the " << creature << " with the " << item << "." << endl;
								return;
							}
						}
					}
				}
			}
		}
	}
	cout << "Error" << endl;
}

void Zork::turnonitem(string input){
	string removeturnon = input.erase(0,8);
	int i;
	int j;
	for (i = 0; i < inventory.size(); i++) {
		if (inventory[i] == removeturnon) {
			for (j = 0; j < itemlist.size(); j++) {
				if (itemlist[j] -> name == removeturnon) {
					if (itemlist[j] -> turn == false) {
						cout << "Cannot turnon this item" << endl;
						return;
					}
					else {
						cout << "You activate the " << removeturnon << endl;
						cout << itemlist[j] -> turnon.print << endl;
						performaction(itemlist[j] -> turnon.action);
						return;
					}
				}
			}
		}
	}
	cout << "Error" << endl;
}

void Zork::putitemincontainer(string input) {
	string removeput = input.erase(0,4);
	int find = removeput.find(" in ");
	string item = removeput.substr(0,find);
	string container = removeput.substr(find+4);
	int i;
	int j;
	int k;
	int l;


	for (i = 0; i < inventory.size(); i++) {
		if (inventory[i] == item) {
			for (j = 0; j < currentroom -> container.size(); j++) {
				if (currentroom -> container[j] == container) {
					for (k = 0; k < containerlist.size(); k++) {
						if (containerlist[k] -> name == container) {
							if (containerlist[k] -> accept.size() == 0) {
								containerlist[k] -> item.push_back(item);
								currentroom -> item.push_back(item);
								inventory.erase(inventory.begin() + i);
								cout << "Item " << item << " added to " << container << endl;
								return;
							}
							for (l = 0; l < containerlist[k] -> accept.size(); l++) {
								if (containerlist[k] -> accept[l] == item) {
									containerlist[k] -> item.push_back(item);
									currentroom -> item.push_back(item);
									inventory.erase(inventory.begin() + i);
									cout << "Item " << item << " added to " << container << endl;
									return;
								}
							}
							cout << container << " does not accept " << item << endl;
							return;
						}
					}
				}
			}
		}
	}
	cout << "Error" << endl;
}

void Zork::dropitem(string input) {
	string removedrop = input.erase(0,5);
	int i;
	int j;
	for (i = 0; i < inventory.size(); i++) {
		if (inventory[i] == removedrop) {
			inventory.erase(inventory.begin()+i);
			cout << removedrop << " dropped" << endl;
			currentroom -> item.push_back(removedrop);
			return;
		}
	}
	cout << "There is nothing to drop" << endl;
}

void Zork::readitem(string input) {
	string removeread = input.erase(0,5);
	int i;
	int j;
	for (i = 0; i < inventory.size(); i++) {
		if (inventory[i] == removeread) {
			for (j = 0; j < itemlist.size(); j++) {
				if (itemlist[j] -> name == removeread) {
					if (itemlist[j] -> writing != "") {
						cout << itemlist[j] -> writing << endl;
						return;
					}
					else {
						cout << "Nothing Written" << endl;
						return;
					}
				}
			}
		}
	}
	cout << "Error" << endl;
}

void Zork::openexit() {
	if (currentroom -> type == "exit") {
		cout << "Game Over" << endl;
		finishgame = true;
		return;
	}
	else {
		cout << "Error" << endl;
	}
}

void Zork::opencontainer(string input) {
	string removeopen = input.erase(0,5);
	int i = 0;
	int j = 0;
	int k = 0;
	if (currentroom -> container.size() == 0) {
		cout << "There is no container in this room" << endl;
		return;
	}
	else {
		for (i = 0; i < containerlist.size(); i++) {
			if (containerlist[i] -> name == removeopen) {
				if (containerlist[i] -> item.size() == 0) {
					cout << "Error" << endl;
					return;
				}
				else {
					cout << removeopen << " contains ";
					for (j = 0; j < (containerlist[i] -> item.size()) - 1; j++) {
						cout << containerlist[i] -> item[j] << ", ";
					}
					cout << containerlist[i] -> item[j] << endl;
					for (j = 0; j < (containerlist[i] -> item.size()); j++) {
						for (k = 0; k < currentroom -> item.size(); k++) {
							if (currentroom -> item[k] == containerlist[i] -> item[j]) {
								return;
							}
						}
						currentroom -> item.push_back(containerlist[i] -> item[j]);
					}
					return;
				}
			}
		}
	}
}

void Zork::changeroom(string input) {
	int i = 0;
	int j = 0;
	for (i = 0; i < (currentroom -> border.size()); i++) {
		if (currentroom -> border[i] -> direction == input) {
			for (j = 0; j < roomlist.size(); j++) {
				if (roomlist[j] -> name == currentroom -> border[i] -> name) {
					currentroom = roomlist[j];
					cout << currentroom -> description << endl;
					return;
				}
			}
		}
	}
	cout << "Can't go that way." << endl;
}

void Zork::taketoinventory(string input) {
	string removetake = input.erase(0,5);
	int i;
	int j;
	int k;
	int l;

	for (i = 0; i < currentroom -> item.size(); i++) {
		if (currentroom -> item[i] == removetake) {
			for (j = 0; j < currentroom -> container.size(); j++) {
				string temp_container_name = currentroom -> container[j];
				for (k = 0; k < containerlist.size(); k++) {
					if (containerlist[k] -> name == temp_container_name) {
						for (l = 0; l < containerlist[k] -> item.size(); l++) {
							if (containerlist[k] -> item[l] == removetake) {
								inventory.push_back(removetake);
								currentroom -> item.erase(currentroom -> item.begin() + i);
								containerlist[k] -> item.erase(containerlist[k] -> item.begin() + l);
								cout << "Item " << removetake << " added to inventory." << endl;
								return;
							}
						}
					}
				}
			}
			inventory.push_back(removetake);
			currentroom -> item.erase(currentroom -> item.begin() + i);
			cout << "Item " << removetake << " added to inventory." << endl;
			return;
		}
	}
	cout << "Error" << endl;
}

void Zork::listinventory() {
	int size = inventory.size();
	if (size == 0) {
		cout << "Inventory: empty" << endl;
	}
	else {
		int i;
		cout << "Inventory: ";
		for (i = 0; i < size - 1; i++) {
			cout << inventory[i] << ", ";
		}
		cout << inventory[i] << endl;
	}
}

string Zork::findtype(string value) {
	int i;
	for (i = 0; i < roomlist.size(); i++) {
		if (roomlist[i] -> name == value) {
			return "room";
		}
	}

	for (i = 0; i < containerlist.size(); i++) {
		if (containerlist[i] -> name == value) {
			return "container";
		}
	}

	for (i = 0; i < itemlist.size(); i++) {
		if (itemlist[i] -> name == value) {
			return "item";
		}
	}

	for (i = 0; i < creaturelist.size(); i++) {
		if (creaturelist[i] -> name == value) {
			return "creature";
		}
	}

	for (i = 0; i < inventory.size(); i++) {
		if (roomlist[i] -> name == value) {
			return "inventory";
		}
	}
	return "";
}

bool Zork::statustrigger(Trigger* trigger) {
	string status = trigger -> status.status;
	string object = trigger -> status.object;
	string objecttype = findtype(object);

	int i;
	int j;
	int k;


	if (objecttype == "item") {
		for (i = 0; i < itemlist.size(); i++) {
			if (itemlist[i] -> name == object) {
				if (itemlist[i] -> status == status) {
					if (trigger -> printexist) {
						cout << trigger -> print << endl;
					}
					if (trigger -> actionexist) {
						for (j = 0; j < trigger -> action.size(); j++) {
							performaction(trigger -> action[j]);
						}
					}
					return true;
				}
				else {
					return false;
				}
			}
		}
	}

	else if(objecttype == "room") {
		for (i = 0; i < roomlist.size(); i++) {
			if (roomlist[i] -> name == object) {
				if (roomlist[i] -> status == status) {
					if (trigger -> printexist) {
						cout << trigger -> print << endl;
					}
					if (trigger -> actionexist) {
						for (j = 0; j < trigger -> action.size(); j++) {
							performaction(trigger -> action[j]);
						}
					}
					return true;
				}
				else {
					return false;
				}
			}
		}
	}

	else if(objecttype == "container") {
		for (i = 0; i < containerlist.size(); i++) {
			if (containerlist[i] -> name == object) {
				if (containerlist[i] -> status == status) {
					if (trigger -> printexist) {
						cout << trigger -> print << endl;
					}
					if (trigger -> actionexist) {
						for (j = 0; j < trigger -> action.size(); j++) {
							performaction(trigger -> action[j]);
						}
					}
					return true;
				}
				else {
					return false;
				}
			}
		}
	}

	else if(objecttype == "creature") {
		for (i = 0; i < creaturelist.size(); i++) {
			if (creaturelist[i] -> name == object) {
				if (creaturelist[i] -> status == status) {
					if (trigger -> printexist) {
						cout << trigger -> print << endl;
					}
					if (trigger -> actionexist) {
						for (j = 0; j < trigger -> action.size(); j++) {
							performaction(trigger -> action[j]);
						}
					}
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
	return false;
}

bool Zork::ownertrigger(Trigger* trigger) {
	string owner = trigger -> owner.owner;
	string has = trigger -> owner.has;
	string object = trigger -> owner.object;
	string ownertype = findtype(owner);
	string objecttype = findtype(object);

	int i;
	int j;
	int k;

	if (owner == "inventory") {
		for (i = 0; i < inventory.size(); i++) {
			if (inventory[i] == object) {
				if (has == "yes") {
					if (trigger -> printexist) {
						cout << trigger -> print << endl;
					}
					if (trigger -> actionexist) {
						for (j = 0; j < trigger -> action.size(); j++) {
							performaction(trigger -> action[j]);
						}
					}
					return true;
				}
				else {
					return false;
				}
			}
		}
		if (has == "no") {
			if (trigger -> printexist) {
				cout << trigger -> print << endl;
			}
			if (trigger -> actionexist) {
				for (j = 0; j < trigger -> action.size(); j++) {
					performaction(trigger -> action[j]);
				}
			}
			return true;
		}
		else {
			return false;
		}
	}

	else if (ownertype == "room") {
		for (i = 0; i < roomlist.size(); i++) {
			if (roomlist[i] -> name == owner) {
				if (objecttype == "item") {
					for (j = 0; j < roomlist[i] -> item.size(); j++) {
						if (roomlist[i] -> item[j] == object) {
							if (has == "yes") {
								if (trigger -> printexist) {
									cout << trigger -> print << endl;
								}
								if (trigger -> actionexist) {
									for (k = 0; k < trigger -> action.size(); k++) {
										performaction(trigger -> action[k]);
									}
								}
								return true;
							}
							else {
								return false;
							}
						}
					}
					if (has == "no") {
						if (trigger -> printexist) {
							cout << trigger -> print << endl;
						}
						if (trigger -> actionexist) {
							for (j = 0; j < trigger -> action.size(); j++) {
								performaction(trigger -> action[j]);
							}
						}
						return true;
					}
					else {
						return false;
					}
				}
				else if (objecttype == "container") {
					for (j = 0; j < roomlist[i] -> container.size(); j++) {
						if (roomlist[i] -> container[j] == object) {
							if (has == "yes") {
								if (trigger -> printexist) {
									cout << trigger -> print << endl;
								}
								if (trigger -> actionexist) {
									for (k = 0; k < trigger -> action.size(); k++) {
										performaction(trigger -> action[k]);
									}
								}
								return true;
							}
							else {
								return false;
							}
						}
					}
					if (has == "no") {
						if (trigger -> printexist) {
							cout << trigger -> print << endl;
						}
						if (trigger -> actionexist) {
							for (j = 0; j < trigger -> action.size(); j++) {
								performaction(trigger -> action[j]);
							}
						}
						return true;
					}
					else {
						return false;
					}
				}
				else if (objecttype == "creature") {
					for (j = 0; j < roomlist[i] -> creature.size(); j++) {
						if (roomlist[i] -> creature[j] == object) {
							if (has == "yes") {
								if (trigger -> printexist) {
									cout << trigger -> print << endl;
								}
								if (trigger -> actionexist) {
									for (k = 0; k < trigger -> action.size(); k++) {
										performaction(trigger -> action[k]);
									}
								}
								return true;
							}
							else {
								return false;
							}
						}
					}
					if (has == "no") {
						if (trigger -> printexist) {
							cout << trigger -> print << endl;
						}
						if (trigger -> actionexist) {
							for (j = 0; j < trigger -> action.size(); j++) {
								performaction(trigger -> action[j]);
							}
						}
						return true;
					}
					else {
						return false;
					}
				}
			}
		}
	}
	else if (ownertype == "container") {
		for (i = 0; i < containerlist.size(); i++) {
			if (containerlist[i] -> name == owner) {
				for (j = 0; j < containerlist[i] -> item.size(); j++) {
					if (containerlist[i] -> item[j] == object) {
						if (has == "yes") {
							if (trigger -> printexist) {
								cout << trigger -> print << endl;
							}
							if (trigger -> actionexist) {
								for (k = 0; k < trigger -> action.size(); k++) {
									performaction(trigger -> action[k]);
								}
							}
							return true;
						}
						else {
							return false;
						}
					}
				}
				if (has == "no") {
					if (trigger -> printexist) {
						cout << trigger -> print << endl;
					}
					if (trigger -> actionexist) {
						for (j = 0; j < trigger -> action.size(); j++) {
							performaction(trigger -> action[j]);
						}
					}
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
	return false;
}

void Zork::performaction(string trigger_action) {
	if ((trigger_action == "n") || (trigger_action == "s") || (trigger_action == "e") || (trigger_action == "w")) {
		changeroom(trigger_action);
		return;
	}
	else if (trigger_action.find("Add") != string::npos) {
		Add(trigger_action);
		return;
	}
	else if (trigger_action.find("Delete") != string::npos) {
		Delete(trigger_action);
		return;
	}
	else if (trigger_action.find("Update") != string::npos) {
		Update(trigger_action);
		return;
	}
	else if (trigger_action.find("Game Over") != string::npos) {
		GameOver();
		return;
	}
	else if (trigger_action.find("take") != string::npos) {
		taketoinventory(trigger_action);
		return;
	}
	else if (trigger_action == "open exit") {
		openexit();
		return;
	}
	else if (trigger_action.find("open") != string::npos) {
		opencontainer(trigger_action);
		return;
	}
	else if (trigger_action.find("read") != string::npos) {
		readitem(trigger_action);
		return;
	}
	else if (trigger_action.find("drop") != string::npos) {
		dropitem(trigger_action);
		return;
	}
	else if (trigger_action.find("put") != string::npos) {
		putitemincontainer(trigger_action);
		return;
	}
	else if (trigger_action.find("turn on") != string::npos) {
		turnonitem(trigger_action);
		return;
	}
	else if (trigger_action.find("attack") != string::npos) {
		attackcreature(trigger_action);
		return;
	}
	else {
		cout << "Error" << endl;
		return;
	}
}

void Zork::Add(string action) {
	string removeadd = action.erase(0,4);
	int find = removeadd.find(" to ");
	string object = removeadd.substr(0,find);
	string room_container = removeadd.substr(find+4);
	string objecttype = findtype(object);
	int i;

	if (objecttype == "item") {
		for (i = 0; i < roomlist.size(); i++) {
			if (roomlist[i] -> name == room_container) {
				roomlist[i] -> item.push_back(object);
				return;
			}
		}
		for (i = 0; i < containerlist.size(); i++) {
			if (containerlist[i] -> name == room_container) {
				containerlist[i] -> item.push_back(object);
				return;
			}
		}
	}
	else if (objecttype == "creature") {
		for (i = 0; i < roomlist.size(); i++) {
			if (roomlist[i] -> name == room_container) {
				roomlist[i] -> creature.push_back(object);
				return;
			}
		}
	}
	else if (objecttype == "container") {
		for (i = 0; i < roomlist.size(); i++) {
			if (roomlist[i] -> name == room_container) {
				roomlist[i] -> container.push_back(object);
				return;
			}
		}
	}	
}

void Zork::Delete(string action) {
	string removedelete = action.erase(0,7);
	int i;
	int j;
	int k;
	int l;
	for (i = 0; i < roomlist.size(); i++) {
		if (roomlist[i] -> name == removedelete) {
			for (j = 0; j < currentroom -> border.size(); j++) {
				if (currentroom -> border[j] -> name == removedelete) {
					currentroom -> border.erase(currentroom -> border.begin() + j);
				}
			}
		}
	}
	for (i = 0; i < itemlist.size(); i++) {
		if (itemlist[i] -> name == removedelete) {
			for (j = 0; j < roomlist.size(); j++) {
				for (k = 0; k < roomlist[j] -> item.size(); k++) {
					if (roomlist[j] -> item[k] == removedelete) {
						roomlist[j] -> item.erase(roomlist[j] -> item.begin() + k);
					}
				}
			}
		}
	}
	for (i = 0; i < containerlist.size(); i++) {
		if (containerlist[i] -> name == removedelete) {
			for (j = 0; j < roomlist.size(); j++) {
				for (k = 0; k < roomlist[j] -> container.size(); k++) {
					if (roomlist[j] -> container[k] == removedelete) {
						roomlist[j] -> container.erase(roomlist[j] -> container.begin() + k);
					}
				}
			}
		}
	}
	for (i = 0; i < containerlist.size(); i++) {
		for (j = 0; j < containerlist[i] -> item.size(); j++) {
			if (containerlist[i] -> item[j] == removedelete) {
				containerlist[i] -> item.erase(containerlist[i] -> item.begin() + j);
			}
		}
	}
	for (i = 0; i < creaturelist.size(); i++) {
		if (creaturelist[i] -> name == removedelete) {
			for (j = 0; j < roomlist.size(); j++) {
				for (k = 0; k < roomlist[j] -> creature.size(); k++) {
					if (roomlist[j] -> creature[k] == removedelete) {
						roomlist[j] -> creature.erase(roomlist[j] -> creature.begin() + k);
					}
				}
			}
		}
	}
}

void Zork::Update(string action) {
	string removeupdate = action.erase(0,7);
	int find = removeupdate.find(" to ");
	string object = removeupdate.substr(0,find);
	string status = removeupdate.substr(find+4);
	string objecttype = findtype(object);
	int i;

	for (i = 0; i < roomlist.size(); i++) {
		if (roomlist[i] -> name == object) {
			roomlist[i] -> status = status;
			return;
		}
	}
	for (i = 0; i < containerlist.size(); i++) {
		if (containerlist[i] -> name == object) {
			containerlist[i] -> status = status;
			return;
		}
	}
	for (i = 0; i < creaturelist.size(); i++) {
		if (creaturelist[i] -> name == object) {
			creaturelist[i] -> status = status;
			return;
		}
	}
	for (i = 0; i < itemlist.size(); i++) {
		if (itemlist[i] -> name == object) {
			itemlist[i] -> status = status;
			return;
		}
	}
}

void Zork::GameOver() {
	cout << "Victory!" << endl;
	finishgame = true;
	return;
}

bool Zork::checktrigger_wcommand(string userinput) {
	bool roomtrig = false;
	bool containertrig = false;
	bool itemtrig = false;
	bool creaturetrig = false;

	Trigger* temptrig;

	int i;
	int j;
	int k;

	//Current Room Trigger with input
	if (currentroom -> trigger.size() != 0) {
		for (i = 0; i < currentroom -> trigger.size(); i++) {
			temptrig = currentroom -> trigger[i];
			if ((temptrig -> commandexist) && (userinput == temptrig -> command)) {
				if((temptrig -> type == "permanent") || (temptrig -> type == "single" && temptrig -> singletimes == 0)) {
					if (temptrig -> numcondition == 3) {
						roomtrig = ownertrigger(temptrig);
					}
					else {
						roomtrig = statustrigger(temptrig);
					}
					if (roomtrig) {
						temptrig -> singletimes++;
					}
				}
			}
		}
	}
	//Current Room Container Trigger with input
	for (i = 0; i < currentroom -> container.size(); i++) {
		string tempcontainer = currentroom -> container[i];
		for (j = 0; j < containerlist.size(); j++) {
			if (containerlist[j] -> name == tempcontainer) {
				for (k = 0; k < containerlist[j] -> trigger.size(); k++) {
					temptrig = containerlist[j] -> trigger[k];
					if ((temptrig -> commandexist) && (userinput == temptrig -> command)) {
						if((temptrig -> type == "permanent") || (temptrig -> type == "single" && temptrig -> singletimes == 0)) {
							if (temptrig -> numcondition == 3) {
								containertrig = ownertrigger(temptrig);
							}
							else {
								containertrig = statustrigger(temptrig);
							}
							if (containertrig) {
								temptrig -> singletimes++;
							}
						}
					}
				}
			}
		}
	}
	//Current Room Item Trigger with input
	for (i = 0; i < currentroom -> item.size(); i++) {
		string tempitem = currentroom -> item[i];
		for (j = 0; j < itemlist.size(); j++) {
			if (itemlist[j] -> name == tempitem) {
				for (k = 0; k < itemlist[j] -> trigger.size(); k++) {
					temptrig = itemlist[j] -> trigger[k];
					if ((temptrig -> commandexist) && (userinput == temptrig -> command)) {
						if((temptrig -> type == "permanent") || (temptrig -> type == "single" && temptrig -> singletimes == 0)) {
							if (temptrig -> numcondition == 3) {
								itemtrig = ownertrigger(temptrig);
							}
							else {
								itemtrig = statustrigger(temptrig);
							}
							if (itemtrig) {
								temptrig -> singletimes++;
							}
						}
					}
				}
			}
		}
	}

	//Current Room Creature Trigger with input
	for (i = 0; i < currentroom -> creature.size(); i++) {
		string tempcreature = currentroom -> creature[i];
		for (j = 0; j < creaturelist.size(); j++) {
			if (creaturelist[j] -> name == tempcreature) {
				for (k = 0; k < creaturelist[j] -> trigger.size(); k++) {
					temptrig = creaturelist[j] -> trigger[k];
					if ((temptrig -> commandexist) && (userinput == temptrig -> command)) {
						if((temptrig -> type == "permanent") || (temptrig -> type == "single" && temptrig -> singletimes == 0)) {
							if (temptrig -> numcondition == 3) {
								creaturetrig = ownertrigger(temptrig);
							}
							else {
								creaturetrig = statustrigger(temptrig);
							}
							if (creaturetrig) {
								temptrig -> singletimes++;
							}
						}
					}
				}
			}
		}
	}
	return (itemtrig||creaturetrig||containertrig||roomtrig);
}



bool Zork::checktrigger_wocommand() {
	bool roomtrig = false;
	bool containertrig = false;
	bool itemtrig = false;
	bool creaturetrig = false;

	Trigger* temptrig;

	int i;
	int j;
	int k;

	//Current Room Trigger
	if (currentroom -> trigger.size() != 0) {
		for (i = 0; i < currentroom -> trigger.size(); i++) {
			temptrig = currentroom -> trigger[i];
			if (!temptrig -> commandexist) {
				if((temptrig -> type == "permanent") || (temptrig -> type == "single" && temptrig -> singletimes == 0)) {
					if (temptrig -> numcondition == 3) {
						roomtrig = ownertrigger(temptrig);
					}
					else {
						roomtrig = statustrigger(temptrig);
					}
					if (roomtrig) {
						temptrig -> singletimes++;
					}
				}
			}
		}
	}
	//Current Room Container Trigger
	for (i = 0; i < currentroom -> container.size(); i++) {
		string tempcontainer = currentroom -> container[i];
		for (j = 0; j < containerlist.size(); j++) {
			if (containerlist[j] -> name == tempcontainer) {
				for (k = 0; k < containerlist[j] -> trigger.size(); k++) {
					temptrig = containerlist[j] -> trigger[k];
					if (!temptrig -> commandexist) {
						if((temptrig -> type == "permanent") || (temptrig -> type == "single" && temptrig -> singletimes == 0)) {
							if (temptrig -> numcondition == 3) {
								containertrig = ownertrigger(temptrig);
							}
							else {
								containertrig = statustrigger(temptrig);
							}
							if (containertrig) {
								temptrig -> singletimes++;
							}
						}
					}
				}
			}
		}
	}
	//Current Room Item Trigger
	for (i = 0; i < currentroom -> item.size(); i++) {
		string tempitem = currentroom -> item[i];
		for (j = 0; j < itemlist.size(); j++) {
			if (itemlist[j] -> name == tempitem) {
				for (k = 0; k < itemlist[j] -> trigger.size(); k++) {
					temptrig = itemlist[j] -> trigger[k];
					if (!temptrig -> commandexist) {
						if((temptrig -> type == "permanent") || (temptrig -> type == "single" && temptrig -> singletimes == 0)) {
							if (temptrig -> numcondition == 3) {
								itemtrig = ownertrigger(temptrig);
							}
							else {
								itemtrig = statustrigger(temptrig);
							}
							if (itemtrig) {
								temptrig -> singletimes++;
							}
						}
					}
				}
			}
		}
	}

	//Current Room Creature Trigger
	for (i = 0; i < currentroom -> creature.size(); i++) {
		string tempcreature = currentroom -> creature[i];
		for (j = 0; j < creaturelist.size(); j++) {
			if (creaturelist[j] -> name == tempcreature) {
				for (k = 0; k < creaturelist[j] -> trigger.size(); k++) {
					temptrig = creaturelist[j] -> trigger[k];
					if (!temptrig -> commandexist) {
						if((temptrig -> type == "permanent") || (temptrig -> type == "single" && temptrig -> singletimes == 0)) {
							if (temptrig -> numcondition == 3) {
								creaturetrig = ownertrigger(temptrig);
							}
							else if (temptrig -> numcondition == 2) {
								creaturetrig = statustrigger(temptrig);
							}
							if (creaturetrig) {
								temptrig -> singletimes++;
							}
						}
					}
				}
			}
		}
	}
	return (itemtrig||creaturetrig||containertrig||roomtrig);
}

