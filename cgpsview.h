#ifndef CGPSVIEW_H
#define CGPSVIEW_H

#include <QMainWindow>

namespace Ui {
class CGPSView;
}

class CGPSView : public QMainWindow
{
    Q_OBJECT

public:
    explicit CGPSView(QWidget *parent = 0);
    ~CGPSView();

private:
    Ui::CGPSView *ui;
};

#endif // CGPSVIEW_H
