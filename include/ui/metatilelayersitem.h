#ifndef METATILELAYERSITEM_H
#define METATILELAYERSITEM_H

#include "tileset.h"
#include "selectablepixmapitem.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class MetatileLayersItem: public SelectablePixmapItem {
    Q_OBJECT
public:
    MetatileLayersItem(Metatile *metatile, uint16_t metatileId, Tileset *primaryTileset, Tileset *secondaryTileset, bool tripleLayer): SelectablePixmapItem(16, 16, 6, 2) {
        this->metatile = metatile;
        this->metatileId = metatileId;
        this->primaryTileset = primaryTileset;
        this->secondaryTileset = secondaryTileset;
        this->tripleLayer = tripleLayer;
        this->clearLastModifiedCoords();
    }
    void draw();
    void setTilesets(Tileset*, Tileset*);
    void setMetatile(Metatile*, uint16_t);
    void clearLastModifiedCoords();
private:
    Metatile* metatile;
    uint16_t metatileId;
    Tileset *primaryTileset;
    Tileset *secondaryTileset;
    QPoint prevChangedTile;
    bool tripleLayer;
    void getBoundedCoords(QPointF, int*, int*);
signals:
    void tileChanged(int, int);
    void selectedTilesChanged(QPoint, int, int);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    void mouseMoveEvent(QGraphicsSceneMouseEvent*);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*);
};

#endif // METATILELAYERSITEM_H
