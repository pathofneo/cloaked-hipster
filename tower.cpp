#include <iostream>
#include "tower.h"
using namespace std;

Object::Object()
{
	ID = 0;
	ObjType = 0;
}

Object::Object(int x,int y)
{
	ID = x;
	ObjType = y;
}

bool Tower::Add(Object* obj )
{
	int id = obj->ID;
	int objType = obj->ObjType;

	if (objType != 0) 
	{
		if (typeMap[objType][id] == id) 
		{
			return false;
		}

		ids[id] = id;
		typeMap[objType][id] = id;
		size++;
		return true;
	}
	return false;
}
void Tower::Remove(Object* obj )
{
	int id = obj->ID;
	int objType = obj->ObjType;

	ids.erase(id);
	if(typeMap.count(objType)>0)
		typeMap[objType].erase(id);
	size--;

}

map_int_int Tower::GetIds()
{
	return ids;
}


void Tower::AddWatcher(Object* watcher)
{
	int id = watcher->ID;
	int objType = watcher->ObjType;

	if (objType != 0) 
	{
		watchers[objType][id] = id;
	}
	
}

void Tower::RemoveWatcher(Object* watcher)
{
	int id = watcher->ID;
	int objType = watcher->ObjType;

	if(watchers.count(objType)>0)
		watchers[objType].erase(id);

}

map_int_int_int Tower::GetWatchers(int* types,int length)
{
	map_int_int_int result;
	int objType;
	


	if ((types != NULL) && (length > 0)) {
		for (int i = 0; i < length; i++ )
		{
			objType = types[i];
			result[objType] = watchers[objType];
			}
		}
	
	return result;
}

map_int_int_int Tower::GetIdsByTypes(int* types,int length)	
{
	map_int_int_int result;
	int objType;
	for (int i = 0; i < length; i++ )
	{
		objType = types[i];
		result[objType] = typeMap[objType];
	}

	return result;
  
}

//	CreateTower() (Tower* tower );		// CreateTower() (tower *Tower)

