
#include "entity.h"
#include "texture.h"

class box: public entity
{
    public:
        box( float xsize, float ysize, char *file );
        void render();
        void update();
    private:
        texture *tx;    
};
