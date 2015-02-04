

typedef struct Rectangle_  {
	int Width;
	int Height;
}Rectangle; 

typedef struct Position_ {
	int X; 
	int Y;
}Position;

/*typedef  struct MapConfig_{
	*Rectangle
	int ID;
}MapConfig;

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
	int width;      
	int height;     
	Tower[][] towers;     
	int rangeLimit; 
	//*
	Position max;   

public:
	bool isInRect(&Position pos,&Position start, &Position end);
	//int[] addMap(int[] result, m map[int][]) 
	
}
//func isInRect(pos *Position, start *Position, end *Position) bool 



func (t *TowerAOI) Init(config *Config) 
func (t *TowerAOI) GetIdsByRange(pos *Position, r int, types []int) map[int]map[int64]int64
func (t *TowerAOI) GetIdsByPos(pos *Position, r int) []int64 {
func (t *TowerAOI) AddObject(obj *Object, pos *Position) bool {
func (t *TowerAOI) RemoveObject(obj *Object, pos *Position) bool
func (t *TowerAOI) UpdateObject(obj *Object, oldPos *Position, newPos *Position) bool
func (t *TowerAOI) checkPos(pos *Position) bool
func (t *TowerAOI) transPos(pos *Position) *Position
func (t *TowerAOI) AddWatcher(watcher *Object, pos *Position, r int)
func (t *TowerAOI) RemoveWatcher(watcher *Object, pos *Position, r int) 
func (t *TowerAOI) UpdateWatcher(watcher *Object, oldPos *Position, newPos *Position, oldRange int, newRange int) bool 
func (t *TowerAOI) getChangedTowers(p1 *Position, p2 *Position, oldRange int, newRange int, towers [][]*Tower, max *Position) (removeTowers []*Tower, addTowers []*Tower, unChangeTowers []*Tower) 
func (t *TowerAOI) getPosLimit(pos *Position, r int, max *Position) (start *Position, end *Position)

func (t *TowerAOI) GetWatchers(pos *Position, types []int) map[int]map[int64]int64 

func (t *TowerAOI) addMapByTypes(result map[int]map[int64]int64, m map[int]map[int64]int64, types []int) map[int]map[int64]int64
//
func addMap(result []int64, m map[int64]int64) []int64
func CreateTowerAOI(config *Config) *TowerAOI