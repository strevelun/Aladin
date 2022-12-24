#include "CSprite.h"

void CSprite::Render(HDC _dest, float _sx, float _sy, HDC _memDC)
{
    GdiTransparentBlt(_dest, _sx, _sy+(1-(h*4)), w*4, h*4, _memDC,
        x, y, w, h, RGB(255, 0, 255));
}