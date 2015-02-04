#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Object
{

public:
	int ID;
	int ObjType;
	Object();
	Object(int x,int y);
	
};

/*
typedef struct _object
{
	int ID;
	int ObjType ;
}Object;
*/
typedef map<int,int> map_int_int ;
typedef map<int,map<int,int> > map_int_int_int; 

class Tower
{
private:
	map_int_int ids;
	map_int_int_int	watchers;
	map_int_int_int typeMap;	
	int		size;

public:
	//Init();
	bool Add(Object* obj );
	void Remove(Object* obj );
	map_int_int GetIds(); 
	void AddWatcher(Object* watcher);
	void RemoveWatcher(Object* watcher);
	//GetWatchers(types []int) map[int]map[int64]int64
	map_int_int_int GetWatchers(int* types,int length);
	map_int_int_int GetIdsByTypes(int* types,int length);		//GetIdsByTypes(types []int) map[int]map[int64]int64
//	CreateTower() (Tower* tower );		// CreateTower() (tower *Tower)
	
};



/*	
var Tower = function(){
  this.ids = {};
  this.watchers = {};
  this.typeMap = {};
  
  this.size = 0;
}
*/
