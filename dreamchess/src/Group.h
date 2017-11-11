/*  DreamChess
**
**  DreamChess is the legal property of its developers, whose names are too
**  numerous to list here. Please refer to the COPYRIGHT file distributed
**  with this source distribution.
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DREAMCHESS_GROUP_H
#define DREAMCHESS_GROUP_H

#include <vector>
#include "Object.h"

class Group: public Object {
public:
	Group(Game *g, Group *p): Object(g, p) {_is3D = false; _parent = nullptr;}
	void is3D(bool b) {_is3D = b;}

	Object *getObject(int i) {return _objects.at(i);}
	void addObject(Object *o);
	void removeObject(Object *o);
	int getObjectCount() {return _objects.size();}

	virtual void render();
	void updateMatrix();
protected:
	bool _is3D;
	std::vector<Object*> _objects;
};

#endif
