#include "tower.cpp"
#include <math.h>

typedef struct Rectangle_  {
	int Width;
	int Height;
}Rectangle; 

typedef struct Position_ {
	int X; 
	int Y;
}Position;
typedef map<int,map<int,Tower> > map_int_int_Tower; 

typedef struct map_int_int_length_ {
	map_int_int content; 
	int length;
}map_int_int_l;

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

/*
type TowerConfig struct {
	*Rectangle
}

type Config struct {
	M     *MapConfig
	T     *TowerConfig
	Limit int
}
*/
class TowerAOI
{
private:
	//*Config
	MapConfig M;
	int width;      
	int height;     
	map_int_int_Tower towers;     
	int rangeLimit; 
	//*
	Position max;   

public:
	bool isInRect(Position &pos,Position &start, Position &end);
	//int[] addMap(int[] result, m map[int][]) 
	map_int_int_int GetIdsByRange(Position pos, int r, int* types, int length);
	void getPosLimit(Position pos, int r, Position max, Position* start , Position* end);// (start *Position, end *Position)//返回一个数组指针
	map_int_int_l GetIdsByPos(Position pos, int r );
	bool checkPos( Position pos);
	bool AddObject(Object obj, Position pos);
	bool RemoveObject(Object obj, Position pos);
	Position transPos(Position pos); 	
	map_int_int_int GetWatchers(Position pos, int* types,int length);
	void AddWatcher(Object watcher, Position pos, int r );
};
//func isInRect(pos *Position, start *Position, end *Position) bool 



func (t *TowerAOI) Init(config *Config) 
//func (t *TowerAOI) GetIdsByRange(pos *Position, r int, types []int) map[int]map[int64]int64
//func (t *TowerAOI) GetIdsByPos(pos *Position, r int) []int64 { 
//func (t *TowerAOI) AddObject(obj *Object, pos *Position) bool {
//func (t *TowerAOI) RemoveObject(obj *Object, pos *Position) bool
func (t *TowerAOI) UpdateObject(obj *Object, oldPos *Position, newPos *Position) bool
//func (t *TowerAOI) checkPos(pos *Position) bool
//func (t *TowerAOI) transPos(pos *Position) *Position
//func (t *TowerAOI) AddWatcher(watcher *Object, pos *Position, r int)
func (t *TowerAOI) RemoveWatcher(watcher *Object, pos *Position, r int) 
func (t *TowerAOI) UpdateWatcher(watcher *Object, oldPos *Position, newPos *Position, oldRange int, newRange int) bool 
func (t *TowerAOI) getChangedTowers(p1 *Position, p2 *Position, oldRange int, newRange int, towers [][]*Tower, max *Position) (removeTowers []*Tower, addTowers []*Tower, unChangeTowers []*Tower) 
//func (t *TowerAOI) getPosLimit(pos *Position, r int, max *Position) (start *Position, end *Position)//返回一个数组指针

//func (t *TowerAOI) GetWatchers(pos *Position, types []int) map[int]map[int64]int64 

func (t *TowerAOI) addMapByTypes(result map[int]map[int64]int64, m map[int]map[int64]int64, types []int) map[int]map[int64]int64
//
func addMap(result []int64, m map[int64]int64) []int64
func CreateTowerAOI(config *Config) *TowerAOI)

*/