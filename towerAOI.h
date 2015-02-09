#include "tower.cpp"
#include <vector>
#include <math.h>
using namespace std;


typedef struct Rectangle_  {
	int Width;
	int Height;
}Rectangle; 

typedef vector<int> vector_int ;
typedef vector<Tower> vector_Tower ;
typedef vector<Tower* > vector_Tower_s ;

typedef map<int,map<int,Tower> > map_int_int_Tower; 



typedef  struct MapConfig_{
	int Width;
	int Height;
	int ID;
}MapConfig;


typedef  struct TowerConfig_{
	int Width;
	int Height;
	int ID;
}TowerConfig;


class Position
{
public:
	int X; 
	int Y;
	Position(int a,int b);

	Position();

};


class TowerAOI
{
private:
	//*Config
		MapConfig M;
	TowerConfig T;
	int rangeLimit; 
	

	int width;      
	int height;     
	map_int_int_Tower towers;     
	
	//*
	Position max;   

public:
	TowerAOI(MapConfig a,TowerConfig b);
	bool isInRect(Position &pos,Position &start, Position &end);
	void getPosLimit(Position pos, int r, Position max, Position* start , Position* end);// (start *Position, end *Position)//返回一个数组指针
	bool checkPos( Position pos);
	bool AddObject(Object obj, Position pos);
	bool RemoveObject(Object obj, Position pos);
	Position transPos(Position pos); 	
	void AddWatcher(Object watcher, Position pos, int r );
	void RemoveWatcher(Object watcher, Position pos,  int r) ;
	void addMap(vector<int> * result, map_int_int m);
	bool UpdateObject(Object obj, Position oldPos, Position newPos);
	bool UpdateWatcher(Object watcher, Position oldPos, Position newPos ,  int oldRange,  int newRange);
	
	
	// void getChangedTowers(Position p1, Position p2, int oldRange , int newRange , map_int_int_Tower towers , Position max, 
	//vector_Tower_s* removeTowers,vector_Tower_s* addTowers,vector_Tower_s* unChangeTowers);
	//map_int_int_int addMapByTypes( map_int_int_int result, map_int_int_int m , int* types, int length);
		//int[] addMap(int[] result, m map[int][]) 
	//map_int_int_int GetIdsByRange(Position pos, int r, int* types, int length);
		//map_int_int_l GetIdsByPos(Position pos, int r );
	//map_int_int_int GetWatchers(Position pos, int* types,int length);
};