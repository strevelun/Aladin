#include "CSprite.h"

void CSprite::Render(HDC _dest, int _sx, int _sy, HDC _memDC)
{
    GdiTransparentBlt(_dest, _sx, _sy+(1-(h*2)), w*2, h*2, _memDC,
        x, y, w, h, RGB(255, 0, 255));
}