#include "towerAOI.h"

Position::Position(int a,int b)
{
	X=a;
	Y=b;
}
Position::Position()
{
}


bool TowerAOI::isInRect(Position &pos,Position &start, Position &end)
{
	return ((pos.X >= start.X) && (pos.X <= end.X) && (pos.Y >= start.Y) && (pos.Y <= end.Y));
}

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

void TowerAOI::getPosLimit(Position pos, int r , Position max, Position* start , Position* end)// (start *Position, end *Position)//返回一个数组指针
{

	if (pos.X-r < 0) {
		start->X = 0;
		end->X = 2 * r;
	} else if (pos.X+r > max.X) {
		end->X = max.X;
		start->X = max.X - 2*r;
	} else {
		start->X = pos.X - r;
		end->X = pos.X + r;
	}

	if (pos.Y-r < 0) {
		start->Y = 0;
		end->Y = 2 * r;
	} else if (pos.Y+r > max.Y) {
		end->Y = max.Y;
		start->Y = max.Y - 2*r;
	} else {
		start->Y = pos.Y - r;
		end->Y = pos.Y + r;
	}

	if (start->X < 0) {
		start->X = 0;
	}
	if (end->X > max.X) {
		end->X = max.X;
	}

	if (start->Y < 0) {
		start->Y = 0;
	}
	if (end->Y > max.Y) {
		end->Y = max.Y;
	}
	
}

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
bool TowerAOI::checkPos(Position pos )
{
	

	if ((pos.X < 0) || (pos.Y < 0) || (pos.X >= M.Width) || (pos.Y >= M.Height)) {
		return false; 
	}
	return true;
}

bool TowerAOI::AddObject(Object obj, Position pos)
{
	Position p;
	if (checkPos(pos)) {
		p = transPos(pos);
		towers[p.X][p.Y].Add(&obj);
		// emit('add', {id: obj.id, type:obj.type, watchers:this.towers[p.x][p.y].watchers});
		return true;
	}
	return false;
}


bool TowerAOI::RemoveObject(Object obj, Position pos)
{
	Position p;
	if (checkPos(pos)) {
		p = transPos(pos);
		towers[p.X][p.Y].Remove(&obj);
		// this.emit('remove', {id: obj.id, type:obj.type, watchers:this.towers[p.x][p.y].watchers});
		return true;
	}
	return false;
}

Position TowerAOI::transPos(Position pos)
{
	Position p;
	p.X = int(floor(float(pos.X) / float(T.Width)));
	p.Y = int(floor(float(pos.Y) / float(T.Width)));
	return p;
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

void TowerAOI::AddWatcher(Object watcher, Position pos, int r )
{
	Position start,end,p;
	if (r < 0) {
		return;
	}

	if (r > 5) {
		r = 5;
	}

	p = transPos(pos);
	getPosLimit(p, r, max,&start,&end);

	for (int i = start.X; i <= end.X; i++) 
	{
		for (int j = start.Y; j <= end.Y; j++) 
		{
			towers[i][j].AddWatcher(&watcher);
		}
	}
}

void TowerAOI::RemoveWatcher(Object watcher, Position pos,  int r) 
{
	Position start,end,p;
	if (r < 0) {
		return;
	}

	if (r > 5) {
		r = 5;
	}

	p = transPos(pos);
	getPosLimit(p, r, max,&start,&end);
	for (int i = start.X; i <= end.X; i++) 
	{
		for (int j = start.Y; j <= end.Y; j++) 
		{
			towers[i][j].RemoveWatcher(&watcher);
		}
	}
}

void TowerAOI::addMap(vector<int> * result, map_int_int m)//,vector<int> * result2 )
{
	map_int_int::iterator it;
	for(it=m.begin();it!=m.end();++it)
        result->push_back(it->second);
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
bool TowerAOI::UpdateObject(Object obj, Position oldPos, Position newPos)
{
	Tower oldTower,newTower;
	
	if (!checkPos(oldPos) || !checkPos(newPos)) 
	{
		return false;
	}
	
	Position p1 = transPos(oldPos);
	Position p2 = transPos(newPos);

	if ((p1.X == p2.X) && (p1.Y == p2.Y)) {
		return true;
	} //else {
		//if t.towers[p1.X] == nil || t.towers[p2.X] == nil {
			//fmt.Printf("AOI pos error ! oldPos : %v, newPos : %v, p1 : %v, p2 : %v\n", oldPos, newPos, p1, p2)
		//	return false
		//}

	oldTower = towers[p1.X][p1.Y];
	newTower = towers[p2.X][p2.Y];

	oldTower.Remove(&obj);
	newTower.Add(&obj);
	
	
	
	
	printTower(oldTower,"oldTower");
	printTower(newTower,"newTower");
	
		// this.emit('update', {id: obj.id, type:obj.type, oldWatchers:oldTower.watchers, newWatchers:newTower.watchers})
	return true;
}

bool TowerAOI::UpdateWatcher(Object watcher, Position oldPos, Position newPos ,  int oldRange,  int newRange)
{
	vector_Tower_s removeTowers,addTowers,unChangeTowers;
	
	if (!checkPos(oldPos) || !checkPos(newPos))
	{
		return false;
	}
			
 		vector_int addObjs;// := make([]int64, 1)
		vector_int removeObjs;// := make([]int64, 1)

	Position p1 = transPos(oldPos);
	Position p2 = transPos(newPos);
	
/*		cout<<"OP "<<oldPos.X<<" "<<oldPos.Y<<endl;
	
	cout<<"NP "<<newPos.X<<" "<<newPos.Y<<endl;
		
	cout<<"p1 "<<p1.X<<" "<<p1.Y<<endl;
	
	cout<<"p2 "<<p2.X<<" "<<p2.Y<<endl;
	*/
	

	if ((p1.X == p2.X) && (p1.Y == p2.Y)) 
	{
		return true;
	} else 
	{
		if ((oldRange < 0) || (newRange < 0)) 
		{
			return false;
		}

		if (oldRange > 5) {
			oldRange = 5;
		}
		if (newRange > 5) {
			newRange = 5;
		}
		map_int_int ids;

//		getChangedTowers(p1, p2, oldRange, newRange, towers, max,&removeTowers, &addTowers, &unChangeTowers );
		
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
				unChangeTowers.push_back(&towers[x][y]);
			} 
			else 
			{
				//if removeTowers == nil {
				//	removeTowers = make([]*Tower, 1)
				//}
				//cout<<"rm  "<<x<<" "<<y<<endl;
				removeTowers.push_back(&towers[x][y]);
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
				//addTowers.push_back(&towers[x][y]);
				towers[x][y].AddWatcher(&watcher);
				ids = towers[x][y].GetIds();
				addMap(&addObjs, ids);
				
				
			}
		}
	}
		

		
		// for (int i = 0; i < addTowers.size(); i++) 
		// {
			// addTowers[i]->AddWatcher(&watcher);

		// }
		
		

		// for (int i = 0; i < addTowers.size(); i++) 
		// {
			// addTowers[i]->AddWatcher(&watcher);
			// ids = addTowers[i]->GetIds();
			// addMap(&addObjs, ids);
		// }
		
		//addTowers.clear();
		//addTowers[0]=towers[4][7];
		//for (int i = 0; i < addTowers.size(); i++) 
		//{
		//	addTowers[i].AddWatcher(&watcher);
		//	ids = addTowers[i].GetIds();
		//	addMap(&addObjs, ids);
		//}
		
		cout<<"addOBJ:";
		for (int i = 0; i < addObjs.size(); i++)
			cout<<" id=  "<<addObjs[i];
		cout<<endl;
		

		for (int i = 0; i < removeTowers.size(); i++) 
		{
			removeTowers[i]->RemoveWatcher(&watcher);
			ids = removeTowers[i]->GetIds();
			addMap(&removeObjs, ids);
			
		}
		cout<<"removeObj:";
		for (int i = 0; i < removeObjs.size(); i++)
			cout<<" id=  "<<removeObjs[i];
		cout<<endl;		
		
	/*	 */
		
		//printf...
		
		//Println("unChangeTowers: %v ?????", unChangeTowers)

		//this.emit('updateWatcher', {id: watcher.id, type:watcher.type, addObjs: addObjs, removeObjs:removeObjs});
		return true;
	}
	return false;
}

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


TowerAOI::TowerAOI(MapConfig a,TowerConfig b) 
{
	//t.Config = config
//
	// if t.Config.Limit != 0 {
		// t.rangeLimit = t.Config.Limit
	// } else {
		// t.
	// }
	rangeLimit = 5;
	
	M=a;
	T=b;
	
	width = T.Width;
	height = T.Height;

	int m = M.Width / T.Width;
	int n = M.Height / T.Height;

	max = Position(m - 1,n - 1);

//	t.towers = make([][]*Tower, m)
	for (int i = 0; i < m; i++) 
	{
	//	towers[i] = make([]*Tower, n)
		for (int j = 0; j < n; j++) 
		{
			towers[i][j] = Tower();
		}
	}
}