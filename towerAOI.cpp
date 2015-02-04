

bool TowerAOI::isInRect(&Position pos,&Position start, &Position end)
{
	return ((pos.X >= start.X) && (pos.X <= end.X) && (pos.Y >= start.Y) && (pos.Y <= end.Y));
}