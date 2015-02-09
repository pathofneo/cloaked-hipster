#include "towerAOI.cpp"

int main()
{
	MapConfig a;
	TowerConfig b;
	
	a.Width=200;
	a.Height=200;
	
	b.Width=10;
	b.Height=10;
	TowerAOI t=TowerAOI(a,b);
	Object obj1,obj2,obj3;
	Position pos1,pos2,pos3,pos4,pos5,pos6,pos7,pos8;
	
	
	/* define 2 watchers : obj1,obj2   */
	obj1=Object(1,1);
	pos1=Position(22,25);
	t.AddObject(obj1, pos1);	
	t.AddWatcher(obj1, pos1, 2 );

	obj2=Object(2,1);
	pos2=Position(44,44);
	t.AddObject(obj2, pos2);	
	t.AddWatcher(obj2, pos2, 2 );

	/* obj3 moves from l -> r  */
	obj3=Object(3,1);
	pos3=Position(44,22);
	t.AddObject(obj3, pos3);
	
 
	pos4=Position(62,32);
	t.UpdateObject(obj3, pos3, pos4);
	cout<<endl;
	
	
	pos5=Position(42,62);
	t.UpdateObject(obj3, pos4, pos5);
	cout<<endl;
	
	pos6=Position(42,72);
	t.UpdateObject(obj3, pos5, pos6);
	cout<<endl; 
	
	/*  watcher 2 moves from l->r   */
	pos7=Position(62,72);
	t.UpdateObject(obj2, pos2, pos7);
	t.UpdateWatcher(obj2, pos2, pos7 ,  2,  2);
	cout<<endl;
	
	pos8=Position(12,72);
	t.UpdateObject(obj2, pos7, pos8);
	t.UpdateWatcher(obj2, pos7, pos8 ,  2,  3);	
	cout<<endl;
	
	

	
	return 1;
}