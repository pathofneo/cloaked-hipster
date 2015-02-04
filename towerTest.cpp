//towerTest.c
#include "tower.cpp"


int main()
{
	
	Tower tower = Tower();
	Object obj1,obj2,obj3,obj4;//(0,0);
	obj1=Object(100,1);
	tower.Add(&obj1);	
	obj2=Object(101,1);
	tower.Add(&obj2);
	obj3=Object(103,2);
	tower.Add(&obj3);
	obj4=Object(104,3);
	tower.Add(&obj4);
	
	
	int a[10];
	a[0]=1;
	a[1]=2;
	cout<<tower.GetIdsByTypes(a,2)[1][101]<<"  "<<tower.GetIdsByTypes(a,2)[2][103]<<endl;
	tower.Remove(&obj2);
	cout<<tower.GetIdsByTypes(a,2)[1][101]<<"  "<<tower.GetIdsByTypes(a,2)[2][103]<<endl;
	tower.Remove(&obj3);
	cout<<tower.GetIdsByTypes(a,2)[1][101]<<"  "<<tower.GetIdsByTypes(a,2)[2][103]<<endl;
	
	Object watcher1(201,21),watcher2(201,22);
	tower.AddWatcher(&watcher1);
	tower.AddWatcher(&watcher2);
	
	a[0]=21;
	a[1]=22;
	cout<<tower.GetWatchers(a,2)[21][201]<<"  "<<tower.GetWatchers(a,2)[22][201]<<endl;
	tower.RemoveWatcher(&watcher2);
	cout<<tower.GetWatchers(a,2)[21][201]<<"  "<<tower.GetWatchers(a,2)[22][201]<<endl;
	
}
