#include "towerAOI.h"

bool TowerAOI::isInRect(Position &pos,Position &start, Position &end)
{
	return ((pos.X >= start.X) && (pos.X <= end.X) && (pos.Y >= start.Y) && (pos.Y <= end.Y));
}

map_int_int_int TowerAOI::GetIdsByRange(Position pos, int r, int* types, int length)
{
	Position start;
	Position end;
	map_int_int_int result;
	if (checkPos(pos) || (r < 0) || (r > rangeLimit)) 
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
			result = addMapByTypes(result, towers[i][j].GetIdsByTypes(types,length), types)
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

map_int_int_l TowerAOI::GetIdsByPos(Position pos, int r )
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
			addMap(result, towers[i][j].GetIds(),&result.content,&result.length);
		}
	}
	return result;
}

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
	if (checkPos(pos)) {
		p = transPos(pos);
		towers[p.X][p.Y].Remove(obj);
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