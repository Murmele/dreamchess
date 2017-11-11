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

#include "Group.h"
#include "DreamChess.h"
#include "System.h"
#include "Object.h"

void Group::addObject(Object *o) {
	o->setParent(this);
    _objects.push_back(o);
}

void Group::removeObject(Object *o) {
    // TODO
}

void Group::updateMatrix() {
    if (_parent == nullptr)
        _matrix == glm::mat4();
    else
	   _matrix = _parent->getMatrix();
    

	for (int i = 0; i < _objects.size(); i++) {
		_objects[i]->updateMatrix();
	}
}

void Group::render() {
    if (_is3D)
        _game->getSystem()->go3D();
    else
        _game->getSystem()->go2D(); 

    for (int i = 0; i < _objects.size(); i++) {
        _objects[i]->render();
    }
}