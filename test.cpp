
void TMyWindow::Paint(TDC& PaintDC, bool erase, TRect& rect) {

HPEN PenHandle, OldPenHandle;

HBRUSH BrushHandle, OldBrushHandle;

PenHandle = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));

OldPenHandle = SelectObject(PaintDC, PenHandle);

BrushHandle = CreateSolidBrush(RGB(255, 255, 0));

OldBrushHandle = SelectObject(PaintDC, BrushHandle);

Ellipse(10, 10, 50, 50);

SelectObject(OldBrushHandle) ;

DeleteObject(BrushHandle) ;

SelectObject(OldPenHandle);

DeleteObject(PenHandle) ;

)
