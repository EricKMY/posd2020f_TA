#ifndef UTILITY_H
#define UTILITY_H


class Utility 
{
    public:
        Shape* getShapeById(Shape* shape, string id) {
            Iterator *it = shape->createIterator();
            try {
                it->first();
            }catch(string e) {
                throw string("Only complex shape can get shape!");
            }

            for(;!it->isDone(); it->next()){
                if(it->currentItem()->id() == id) {
                    return it->currentItem();
                }
                try{
                    return getShapeById(it->currentItem(), id);
                }catch(string e) {}
            }
            throw string("expected get shape but shape not found");
        }
};


#endif
