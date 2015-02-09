map_int_int_int TowerAOI::GetIdsByRange(Position pos, int r, int* types, int length)
{
	Position start;
	Position end;
	map_int_int_int result;
	if (!checkPos(pos) || (r < 0) || (r > rangeLimit)) 
	{
		return result;
	}

	Position p = transPos(pos);
/*	if (p == NULL) 
	{
		cout<<"p value is nil.\n"
	}*/
	//Position* pt = 
	getPosLimit(p, r, max,&start,&end);
	//Position start = *pt; 
	//Position end = *(pt+1);
	
	for (int i = start.X; i <= end.X; i++) 
	{
		for (int j = start.Y; j <= end.Y; j++) 
		{
			result = addMapByTypes(result, towers[i][j].GetIdsByTypes(types,length), types,length);
		}
	}
	return result;
}

map_int_int_int TowerAOI::addMapByTypes( map_int_int_int result, map_int_int_int m , int* types, int length)
{
	int objType;
	map_int_int::iterator it;
	for (int i = 0; i < length; i++) 
	{
		objType = types[i];
		
		
		for(it=m[objType].begin();it!=m[objType].end();++it)
        result[objType].insert(pair<int,int>(it->first ,it->second));
	}
	return result;
}

map_int_int_int TowerAOI::GetWatchers(Position pos, int* types,int length)
{
	map_int_int_int result;
	Position p;
	
	if (checkPos(pos)) {
		p = transPos(pos);
		return towers[p.X][p.Y].GetWatchers(types,length);
	}
	return result;
}


//func isInRect(pos *Position, start *Position, end *Position) bool 



/*

func (t *TowerAOI) Init(config *Config) 
//func (t *TowerAOI) GetIdsByRange(pos *Position, r int, types []int) map[int]map[int64]int64
//func (t *TowerAOI) GetIdsByPos(pos *Position, r int) []int64 { 
//func (t *TowerAOI) AddObject(obj *Object, pos *Position) bool {
//func (t *TowerAOI) RemoveObject(obj *Object, pos *Position) bool
//func (t *TowerAOI) UpdateObject(obj *Object, oldPos *Position, newPos *Position) bool
//func (t *TowerAOI) checkPos(pos *Position) bool
//func (t *TowerAOI) transPos(pos *Position) *Position
//func (t *TowerAOI) AddWatcher(watcher *Object, pos *Position, r int)
//func (t *TowerAOI) RemoveWatcher(watcher *Object, pos *Position, r int) 
//func (t *TowerAOI) UpdateWatcher(watcher *Object, oldPos *Position, newPos *Position, oldRange int, newRange int) bool 
//func (t *TowerAOI) getChangedTowers(p1 *Position, p2 *Position, oldRange int, newRange int, towers [][]*Tower, max *Position) (removeTowers []*Tower, addTowers []*Tower, unChangeTowers []*Tower) 
//func (t *TowerAOI) getPosLimit(pos *Position, r int, max *Position) (start *Position, end *Position)//返回一个数组指针

//func (t *TowerAOI) GetWatchers(pos *Position, types []int) map[int]map[int64]int64 

//func (t *TowerAOI) addMapByTypes(result map[int]map[int64]int64, m map[int]map[int64]int64, types []int) map[int]map[int64]int64
//
//func addMap(result []int64, m map[int64]int64) []int64
func CreateTowerAOI(config *Config) *TowerAOI)

*/


/*map_int_int_l TowerAOI::GetIdsByPos(Position pos, int r )
{
	map_int_int_l result;
	Position start,end,p;
	
	result.length=0;
	if (checkPos(pos) || (r < 0)) 
	{
		return result;
	}

	if (r > 5) 
	{
		r = 5;
	}

	p = transPos(pos);
	getPosLimit(p, r, max,&start,&end);
	for (int i = start.X; i <= end.X; i++) 
	{
		for (int j = start.Y; j <= end.Y; j++) 
		{
			addMap(result, towers[i][j].GetIds(),&result);
		}
	}
	return result;
}
*/


/* 
void TowerAOI::getChangedTowers(Position p1, Position p2, int oldRange , int newRange , map_int_int_Tower towers , Position max, 
vector_Tower_s * removeTowers,vector_Tower_s * addTowers,vector_Tower_s * unChangeTowers)
{
	Position start1, end1;
	getPosLimit(p1, oldRange, max,&start1, &end1 );
	Position start2, end2;
	getPosLimit(p2, newRange, max,&start2, &end2);
	Position p;

	
	
	for (int x = start1.X; x <= end1.X; x++) 
	{
		for (int y = start1.Y; y <= end1.Y; y++) 
		{
			p.X=x;
			p.Y=y;
			if (isInRect(p, start2, end2)) 
			{
				//if unChangeTowers == nil {
				//	unChangeTowers = make([]*Tower, 1)
				//}
				//cout<<"uc  "<<x<<" "<<y<<endl;
				unChangeTowers->push_back(&towers[x][y]);
			} 
			else 
			{
				//if removeTowers == nil {
				//	removeTowers = make([]*Tower, 1)
				//}
				//cout<<"rm  "<<x<<" "<<y<<endl;
				removeTowers->push_back(&towers[x][y]);
			}
		}
	}

	for (int x = start2.X; x <= end2.X; x++) {
		for (int y = start2.Y; y <= end2.Y; y++) {
			p.X=x;
			p.Y=y;
			if (!isInRect(p, start1, end1)) {
				//if addTowers == nil {
				//	addTowers = make([]*Tower, 1)
				//}
				//cout<<"add  "<<x<<" "<<y<<endl;
				addTowers->push_back(&towers[x][y]);
			}
		}
	}
	return;
}
 */
